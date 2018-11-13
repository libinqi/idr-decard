#include "DCRead.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <windows.h>

using namespace v8;

Persistent<Function> DCRead::constructor;
HANDLE icdev; //设备句柄

DCRead::DCRead()
{
	icdev = 0;
	doExecute = execute;
}

DCRead::~DCRead()
{
}

static std::string GBKToUTF8(const std::string &strGBK)
{
	static std::string strOutUTF8 = "";
	WCHAR *str1;
	int n = MultiByteToWideChar(CP_ACP, 0, strGBK.c_str(), -1, NULL, 0);
	str1 = new WCHAR[n];
	MultiByteToWideChar(CP_ACP, 0, strGBK.c_str(), -1, str1, n);
	n = WideCharToMultiByte(CP_UTF8, 0, str1, -1, NULL, 0, NULL, NULL);
	char *str2 = new char[n];
	WideCharToMultiByte(CP_UTF8, 0, str1, -1, str2, n, NULL, NULL);
	strOutUTF8 = str2;
	delete[] str1;
	str1 = NULL;
	delete[] str2;
	str2 = NULL;
	return strOutUTF8;
}

void DCRead::Init(Handle<Object> exports)
{
	Isolate *isolate = Isolate::GetCurrent();

	// Prepare constructor template
	Local<FunctionTemplate> tpl = FunctionTemplate::New(isolate, New);
	tpl->SetClassName(String::NewFromUtf8(isolate, "DCRead"));
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "OpenRealReadCard", DR_Open_RealReadCard);
	NODE_SET_PROTOTYPE_METHOD(tpl, "StartRealReadCard", DR_Start_RealReadCard);
	NODE_SET_PROTOTYPE_METHOD(tpl, "StopRealReadCard", DR_Stop_RealReadCard);
	NODE_SET_PROTOTYPE_METHOD(tpl, "CloseRealReadCard", DR_Close_RealReadCard);

	constructor.Reset(isolate, tpl->GetFunction());
	exports->Set(String::NewFromUtf8(isolate, "DCRead"),
				 tpl->GetFunction());
}

void DCRead::New(const FunctionCallbackInfo<Value> &args)
{
	Isolate *isolate = Isolate::GetCurrent();
	HandleScope scope(isolate);

	if (args.IsConstructCall())
	{
		// Invoked as constructor: `new MyObject(...)`

		DCRead *obj = new DCRead();
		obj->Wrap(args.This());
		args.GetReturnValue().Set(args.This());
	}
	else
	{
		// Invoked as plain function `MyObject(...)`, turn into construct call.
		const int argc = 1;
		Local<Value> argv[argc] = {args[0]};
		Local<Function> cons = Local<Function>::New(isolate, constructor);
		Local<Object> result =
			cons->NewInstance(context, argc, argv).ToLocalChecked();
		args.GetReturnValue().Set(result);
	}
}

void DCRead::DR_Open_RealReadCard(const FunctionCallbackInfo<Value> &args)
{
	Isolate *isolate = Isolate::GetCurrent();
	HandleScope scope(isolate);

	int iPort = args[0]->Int32Value();

	icdev = dc_init(iPort, 115200);

	if (icdev)
	{
		bind(isolate, Local<Function>::Cast(args[1]), Local<Function>::Cast(args[2]));
		args.GetReturnValue().Set(Number::New(isolate, 1));
	}
	else
	{
		args.GetReturnValue().Set(Number::New(isolate, 0));
	}
}

void DCRead::DR_Start_RealReadCard(const FunctionCallbackInfo<Value> &args)
{
	Isolate *isolate = Isolate::GetCurrent();
	HandleScope scope(isolate);

	resume();

	args.GetReturnValue().Set(Number::New(isolate, 1));
}

void DCRead::DR_Stop_RealReadCard(const FunctionCallbackInfo<Value> &args)
{
	Isolate *isolate = Isolate::GetCurrent();
	HandleScope scope(isolate);

	suspend();

	args.GetReturnValue().Set(Number::New(isolate, 1));
}

void DCRead::DR_Close_RealReadCard(const FunctionCallbackInfo<Value> &args)
{
	Isolate *isolate = Isolate::GetCurrent();
	HandleScope scope(isolate);

	suspend();

	int result = dc_exit(icdev);
	args.GetReturnValue().Set(Number::New(isolate, result == 0 ? 1 : 0));
}

void DCRead::execute()
{
	Receiver receiver;

	if (dc_find_i_d(icdev) == 0)
	{
		receiver.type = ReceiveType::IDCard;

		if (dc_start_i_d(icdev) < 0)
		{
			doError(0, GBKToUTF8("读取身份证信息错误!"));
		}
		else
		{
			strcpy(receiver.name, dc_i_d_query_name(icdev));
			strcpy(receiver.gender, dc_i_d_query_sex(icdev));
			strcpy(receiver.folk, dc_i_d_query_nation(icdev));
			strcpy(receiver.birthDay, dc_i_d_query_birth(icdev));
			strcpy(receiver.code, dc_i_d_query_id_number(icdev));
			strcpy(receiver.address, dc_i_d_query_address(icdev));
			strcpy(receiver.agency, dc_i_d_query_department(icdev));

			std::string expireDay = dc_i_d_query_expire_day(icdev);
			expireDay.substr(0, 8).copy(receiver.expireStart, 8, 0);
			expireDay.substr(8, 8).copy(receiver.expireEnd, 8, 0);

			dc_i_d_query_photo_file(icdev, "c:\\photo.jpg");
			dc_end_i_d(icdev);

			doReceive(receiver);
		}
	}
	else
	{
		unsigned int cardsnr;
		if (dc_card(icdev, 0, &cardsnr) == 0)
		{
			dc_halt(icdev);

			receiver.type = ReceiveType::ICCard;
			sprintf(receiver.code, "%2X", cardsnr);

			std::string cardIdStr = receiver.code;
			cardIdStr = cardIdStr.substr(6, 2) + cardIdStr.substr(4, 2) + cardIdStr.substr(2, 2) + cardIdStr.substr(0, 2);
			cardIdStr.copy(receiver.code, 8, 0);

			doReceive(receiver);
		}
	}

	Sleep(10);
}

void InitAll(Handle<Object> exports)
{
	DCRead::Init(exports);
}

NODE_MODULE(DCRead, InitAll)

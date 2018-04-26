// -*- mode:c++ -*-

/**
 * @file
 * @author Wei Yang <wstcreator@hotmail.com>
 * @date   Tue Dec 20 11:42:16 2016
 * @brief  ��д�����ܽӿ������ļ���
 */

#ifndef DCRF32_H_
#define DCRF32_H_

#ifdef WIN32
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")
#define USER_API __stdcall
#else
typedef int HANDLE;
#define USER_API
#endif

#ifdef __cplusplus
extern "C" {
#endif

  /**
   * @brief  ����ڡ�
   * @par    ˵����
   * ���Ի�ȡ������һЩ����ز������˽ӿڿɲ����ã�������ñ���������������ӿ�֮ǰ���á�
   * @param[in] flag ��ǣ����ھ��� @a context �����ͺͺ��塣
   * @n 0 - ��ʾ��ȡ��汾�� @a context ����Ϊchar *�������ٷ���8���ֽڡ�
   * @n 1 - ��ʾ���ÿ�Ĺ���Ŀ¼�� @a context ����Ϊconst char *��
   * @n 2 - ��ʾ���ÿ�����ߵĹ���Ŀ¼�� @a context ����Ϊconst char *��
   * @n 3 - �����ڲ�ʹ�ã���ʾ���ø����ӿ������ģ� @a context ����Ϊ�Զ���ṹָ�롣
   * @n 4 - �����ڲ�ʹ�ã���ʾ��ȡ�����ӿ������ģ� @a context ����Ϊ�Զ���ṹָ�롣
   * @param[in,out] context ����ʵ�����ͺͺ����� @a flag ��ֵ��������
   */
  void USER_API LibMain(int flag, void *context);

  /**
   * @brief  ���ö˿����ơ�
   * @par    ˵����
   * �������ö˿ڶ�Ӧ���������ƣ��ڵ��� ::dc_init ֮ǰ����ʹ�ô˽ӿ����ı�˿ں��ڲ���Ӧ��Ĭ���������ƣ���Windowsƽ̨��0�˿ںŶ�Ӧ��Ĭ������Ϊ"COM1"��Linuxƽ̨��0�˿ںŶ�Ӧ��Ĭ������Ϊ"/dev/ttyS0"��
   * @param[in] port �˿ںţ�ͬ ::dc_init �� @a port ������֧�ִ���ģʽ������ģʽ�Ķ˿ںţ�����0~99��300~399��
   * @param[in] name �������ơ�
   */
  void USER_API dc_config_port_name(short port, const char *name);

  /**
   * @brief  ���豸��
   * @par    ˵����
   * �����豸��ͨѶ���ҷ�����Ӧ����Դ���󲿷ֹ��ܽӿڶ���Ҫ�ڴ˹��̺���ܽ��У��ڲ���Ҫʹ���豸�󣬱���ʹ�� ::dc_exit ȥ�ر��豸��ͨѶ���ͷ���Դ��
   * @param[in] port �˿ںš�
   * @n 0~99 - ��ʾ����ģʽ����������Ӧ�������0��ʾ��һ�����ںϷ��豸�����1��ʾ�ڶ������ںϷ��豸���Դ����ơ�
   * @n 100~199 - ��ʾUSBģʽ������߼���Ӧ�������100��ʾ��һ��USB�Ϸ��豸�����1��ʾ�ڶ���USB�Ϸ��豸���Դ����ơ�
   * @n 200~299 - ��ʾPCSCģʽ������߼���Ӧ�������200��ʾ��һ��PCSC�Ϸ��豸�����201��ʾ�ڶ���PCSC�Ϸ��豸���Դ����ơ�
   * @n 300~399 - ��ʾ����ģʽ������߼���Ӧ�������300��ʾ��һ�������Ϸ��豸�����301��ʾ�ڶ��������Ϸ��豸���Դ����ơ�
   * @param[in] baud �����ʣ�ֻ��Դ���ģʽ��Ч��
   * @return <0��ʾʧ�ܣ�����Ϊ�豸��ʶ����
   */
  HANDLE USER_API dc_init(short port, int baud);

  /**
   * @brief  ���豸��
   * @par    ˵����
   * �����豸��ͨѶ���ҷ�����Ӧ����Դ���󲿷ֹ��ܽӿڶ���Ҫ�ڴ˹��̺���ܽ��У��ڲ���Ҫʹ���豸�󣬱���ʹ�� ::dc_exit ȥ�ر��豸��ͨѶ���ͷ���Դ��
   * @param[in] port �˿ںš�
   * @n 0~99 - ��ʾ����ģʽ����������Ӧ�������0��ʾ��һ�����ںϷ��豸�����1��ʾ�ڶ������ںϷ��豸���Դ����ơ�
   * @n 100~199 - ��ʾUSBģʽ������߼���Ӧ�������100��ʾ��һ��USB�Ϸ��豸�����1��ʾ�ڶ���USB�Ϸ��豸���Դ����ơ�
   * @n 200~299 - ��ʾPCSCģʽ������߼���Ӧ�������200��ʾ��һ��PCSC�Ϸ��豸�����201��ʾ�ڶ���PCSC�Ϸ��豸���Դ����ơ�
   * @n 300~399 - ��ʾ����ģʽ������߼���Ӧ�������300��ʾ��һ�������Ϸ��豸�����301��ʾ�ڶ��������Ϸ��豸���Դ����ơ�
   * @param[in] baud �����ʣ�ֻ��Դ���ģʽ��Ч��
   * @param[in] name �豸�߼����ơ�
   * @return <0��ʾʧ�ܣ�����Ϊ�豸��ʶ����
   */
  HANDLE USER_API dc_init_name(short port, int baud, const char *name);

  /**
   * @brief  �ر��豸��
   * @par    ˵����
   * �ر��豸��ͨѶ���ͷ���Դ��
   * @param[in] icdev �豸��ʶ����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_exit(HANDLE icdev);

  /**
   * @brief  ��ȡ���ơ�
   * @par    ˵����
   * �˽ӿڽ���ȡһ������ʶ��ǰ���豸��������Ӧ���߼����ƣ���ȡ���߼����ƽ����ڲ�ʹ�á�
   * @param[in] icdev �豸��ʶ����
   * @param[out] name ���ص������ַ����������ٷ���64���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_getname(HANDLE icdev, char *name);

  /**
   * @brief  ������
   */
  short USER_API dc_config(HANDLE icdev, unsigned char _Mode, unsigned char _Baud);

  /**
   * @brief  Ѱ������
   * @par    ˵����
   * ֧��ISO 14443 Type A���Ϳ�Ƭ��Ѱ������
   * @param[in] icdev �豸��ʶ����
   * @param[in] _Mode ģʽ��0x00��ʾ�Կ��п����в�����0x01��ʾ�����п�������
   * @param[out] TagType ���ص�ATQAֵ��
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���==1��ʾ�޿����޷�Ѱ����Ƭ��
   */
  short USER_API dc_request(HANDLE icdev, unsigned char _Mode, unsigned short *TagType);

  /**
   * @brief  ������ͻ��
   * @par    ˵����
   * ֧��ISO 14443 Type A���Ϳ�Ƭ�ķ�����ͻ��
   * @param[in] icdev �豸��ʶ����
   * @param[in] _Bcnt �������̶�Ϊ0x00��
   * @param[out] _Snr ���صĿ����кš�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_anticoll(HANDLE icdev, unsigned char _Bcnt, unsigned int *_Snr);

  /**
   * @brief  ѡ��������
   * @par    ˵����
   * ͨ��ָ�����кţ�ѡȡ��Ӧ�Ŀ�Ƭ��
   * @param[in] icdev �豸��ʶ����
   * @param[in] _Snr ��Ƭ���кš�
   * @param[out] _Size ���ص�SAKֵ��
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_select(HANDLE icdev, unsigned int _Snr, unsigned char *_Size);

  /**
   * @brief  ��֤M1�����롣
   * @par    ˵����
   * ʹ���豸�ڲ�װ�ص���������֤M1�����롣
   * @param[in] icdev �豸��ʶ����
   * @param[in] _Mode ģʽ��
   * @n 0x00 - ��ʾ���豸�ڲ�װ�صĵ�0��A��������֤��ǰѡȡ��Ƭ��A���롣
   * @n 0x01 - ��ʾ���豸�ڲ�װ�صĵ�1��A��������֤��ǰѡȡ��Ƭ��A���롣
   * @n 0x02 - ��ʾ���豸�ڲ�װ�صĵ�2��A��������֤��ǰѡȡ��Ƭ��A���롣
   * @n 0x04 - ��ʾ���豸�ڲ�װ�صĵ�0��B��������֤��ǰѡȡ��Ƭ��B���롣
   * @n 0x05 - ��ʾ���豸�ڲ�װ�صĵ�1��B��������֤��ǰѡȡ��Ƭ��B���롣
   * @n 0x06 - ��ʾ���豸�ڲ�װ�صĵ�2��B��������֤��ǰѡȡ��Ƭ��B���롣
   * @param[in] _SecNr Ҫ��֤����������š�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_authentication(HANDLE icdev, unsigned char _Mode, unsigned char _SecNr);

  /**
   * @brief  ��ֹ��������
   * @par    ˵����
   * ʹ��Ƭ������ֹ״̬����ʱ����ѿ��Ƴ���Ӧ�����ٴη����Ӧ������Ѱ�����ſ���
   * @param[in] icdev �豸��ʶ����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_halt(HANDLE icdev);

  /**
   * @brief  �������ݡ�
   * @par    ˵����
   * ��ȡ�������ݣ�����M1����һ�ζ�ȡһ��������ݣ�Ϊ16���ֽڣ�����ML����һ�ζ�ȡ��ͬ���Ե���ҳ��Ϊ8���ֽڡ�
   * @param[in] icdev �豸��ʶ����
   * @param[in] _Adr ��ַ��
   * @n M1�� - S50���ַ��0~63����S70���ַ��0~255����
   * @n ML�� - ҳ��ַ��0~11����
   * @param[out] _Data �̶�����16���ֽ����ݣ���ʵ���ݿ���С��16���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_read(HANDLE icdev, unsigned char _Adr, unsigned char *_Data);

  /**
   * @brief  �������ݡ�
   * @par    ˵����
   * ::dc_read ��HEX��ʽ�ӿڣ����� @a _Data ΪHEX��ʽ��
   */
  short USER_API dc_read_hex(HANDLE icdev, unsigned char _Adr, char *_Data);

  /**
   * @brief  д�����ݡ�
   * @par    ˵����
   * д�����ݵ���Ƭ�ڣ�����M1����һ�α���д��һ��������ݣ�Ϊ16���ֽڣ�����ML����һ�α���д��һ��ҳ�����ݣ�Ϊ4���ֽڡ�
   * @param[in] icdev �豸��ʶ����
   * @param[in] _Adr ��ַ��
   * @n M1�� - S50���ַ��1~63����S70���ַ��1~255����
   * @n ML�� - ҳ��ַ��2~11����
   * @param[out] _Data �̶�����16���ֽ����ݣ���ʵ���ݿ���С��16���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_write(HANDLE icdev, unsigned char _Adr, unsigned char *_Data);

  /**
   * @brief  д�����ݡ�
   * @par    ˵����
   * ::dc_write ��HEX��ʽ�ӿڣ����� @a _Data ΪHEX��ʽ��
   */
  short USER_API dc_write_hex(HANDLE icdev, unsigned char _Adr, char *_Data);

  /**
   * @brief  ������
   */
  short USER_API dc_write_TS(HANDLE icdev);

  /**
   * @brief  װ���豸���롣
   * @par    ˵����
   * װ��M1�����뵽�豸�ڲ���װ�غ�������ض�ʱ���� ::dc_authentication ����֤M1�����롣ע�⣺���ڶ��װ���豸������ܻ���Ӳ���洢�������ƣ��˽ӿ�ֻ����������Թ̶���װ�ش����ٵĳ��ϡ�
   * @param[in] icdev �豸��ʶ����
   * @param[in] _Mode ģʽ��ͬ ::dc_authentication �� @a _Mode ��
   * @param[in] _SecNr ��Ӧװ�ص������š�
   * @param[in] _NKey д���豸�еĿ����룬�̶�Ϊ6���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_load_key(HANDLE icdev, unsigned char _Mode, unsigned char _SecNr, unsigned char *_NKey);

  /**
   * @brief  װ���豸���롣
   * @par    ˵����
   * ::dc_load_key ��HEX��ʽ�ӿڣ����� @a _NKey ΪHEX��ʽ��
   */
  short USER_API dc_load_key_hex(HANDLE icdev, unsigned char _Mode, unsigned char _SecNr, char *_NKey);

  /**
   * @brief  Ѱ�����󡢷�����ͻ��ѡ��������
   * @par    ˵����
   * �ڲ������� ::dc_request ::dc_anticoll ::dc_select �Ĺ��ܡ�
   * @param[in] icdev �豸��ʶ����
   * @param[in] _Mode ģʽ��ͬ ::dc_request �� @a _Mode ��
   * @param[out] _Snr ���صĿ����кš�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���==1��ʾ�޿����޷�Ѱ����Ƭ��
   */
  short USER_API dc_card(HANDLE icdev, unsigned char _Mode, unsigned int *_Snr);

  /**
   * @brief  Ѱ�����󡢷�����ͻ��ѡ��������
   * @par    ˵����
   * ::dc_card ��HEX��ʽ�ӿڣ����� @a snrstr ΪHEX��ʽ��
   */
  short USER_API dc_card_hex(HANDLE icdev, unsigned char _Mode, unsigned char *snrstr);

  /**
   * @brief  M1���������ÿ������
   * @par    ˵����
   * �޸�M1���������ÿ����ݣ�M1���������ÿ�Ҳ����ÿ�����������һ�飬��������A�������ֽڡ�����B���ݡ�
   * @param[in] icdev �豸��ʶ����
   * @param[in] _SecNr �����š�
   * @param[in] _KeyA ����A���̶�Ϊ6���ֽڡ�
   * @param[in] _B0 ��0�����֣���һ������16��ʱ����ӦΪ��0~4�Ŀ����֣�����3λ��D2D1D0����ӦC10��C20��C30��
   * @param[in] _B1 ��1�����֣���һ������16��ʱ����ӦΪ��5~9�Ŀ����֣�����3λ��D2D1D0����ӦC11��C21��C31��
   * @param[in] _B2 ��2�����֣���һ������16��ʱ����ӦΪ��10~14�Ŀ����֣�����3λ��D2D1D0����ӦC12��C22��C32��
   * @param[in] _B3 ��3�����֣���һ������16��ʱ����ӦΪ��15�Ŀ����֣�����3λ��D2D1D0����ӦC13��C23��C33��
   * @param[in] _Bk �������̶�Ϊ0x00��
   * @param[in] _KeyB ����B���̶�Ϊ6���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_changeb3(HANDLE icdev, unsigned char _SecNr, unsigned char *_KeyA, unsigned char _B0, unsigned char _B1, unsigned char _B2, unsigned char _B3, unsigned char _Bk, unsigned char *_KeyB);

  /**
   * @brief  M1���������ÿ������
   * @par    ˵����
   * ::dc_changeb3 ��HEX��ʽ�ӿڣ����� @a _KeyA @a _KeyB ΪHEX��ʽ��
   */
  short USER_API dc_changeb3_hex(HANDLE icdev, unsigned char _SecNr, const char *_KeyA, unsigned char _B0, unsigned char _B1, unsigned char _B2, unsigned char _B3, unsigned char _Bk, const char *_KeyB);

  /**
   * @brief  M1��ֵ��ش���
   * @par    ˵����
   * ���ڰ�ָ����ֵ�������ݴ棬��������ʹ�� ::dc_transfer ���ݴ�ֵ�����ݴ��ݵ���һ���У�ʵ�ֿ����֮����ֵ���͡�
   * @param[in] icdev �豸��ʶ����
   * @param[in] _Adr Ҫ�ش��Ŀ��ַ��
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_restore(HANDLE icdev, unsigned char _Adr);

  /**
   * @brief  M1��ֵ�鴫�ݡ�
   * @par    ˵����
   * ���ڰ� ::dc_restore �ݴ��ֵ�����ݴ��ݵ�ָ�����У�ʵ�ֿ����֮����ֵ���͡�
   * @param[in] icdev �豸��ʶ����
   * @param[in] _Adr Ҫ���ݵĿ��ַ��
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_transfer(HANDLE icdev, unsigned char _Adr);

  /**
   * @brief  M1��ֵ���ֵ��
   * @par    ˵����
   * ���ڲ���M1��ֵ�飬ʹ��ֵ����ָ����ֵ��
   * @param[in] icdev �豸��ʶ����
   * @param[in] _Adr ���ַ��
   * @param[in] _Value Ҫ���ӵ���ֵ��
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_increment(HANDLE icdev, unsigned char _Adr, unsigned int _Value);

  /**
   * @brief  M1��ֵ���ֵ��
   * @par    ˵����
   * ���ڲ���M1��ֵ�飬ʹ��ֵ����ָ����ֵ��
   * @param[in] icdev �豸��ʶ����
   * @param[in] _Adr ���ַ��
   * @param[in] _Value Ҫ���ٵ���ֵ��
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_decrement(HANDLE icdev, unsigned char _Adr, unsigned int _Value);

  /**
   * @brief  M1��ֵ���ʼ����
   * @par    ˵����
   * ���ڲ���M1����ʹ��ָ����Ϊֵ�飬���ҳ�ʼ����ֵ��Ϊָ����ֵ��
   * @param[in] icdev �豸��ʶ����
   * @param[in] _Adr ���ַ��
   * @param[in] _Value ��ʼ����ֵ��
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_initval(HANDLE icdev, unsigned char _Adr, unsigned int _Value);

  /**
   * @brief  M1��ֵ���ֵ��
   * @par    ˵����
   * ���ڶ�ȡM1��ֵ����ֵ��
   * @param[in] icdev �豸��ʶ����
   * @param[in] _Adr Ҫ��ȡ�Ŀ��ַ��
   * @param[out] _Value ���ص���ֵ��
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_readval(HANDLE icdev, unsigned char _Adr, unsigned int *_Value);

  /**
   * @brief  ML��ֵ��ʼ����
   * @par    ˵����
   * ���ڲ���ML������ʼ��������Ϊָ����ֵ��
   * @param[in] icdev �豸��ʶ����
   * @param[in] _Value ��ʼ����ֵ��
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_initval_ml(HANDLE icdev, unsigned short _Value);

  /**
   * @brief  ML����ֵ��
   * @par    ˵����
   * ���ڶ�ȡML����ֵ��
   * @param[in] icdev �豸��ʶ����
   * @param[out] _Value ���ص���ֵ��
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_readval_ml(HANDLE icdev, unsigned short *_Value);

  /**
   * @brief  ML����ֵ��
   * @par    ˵����
   * ���ڲ���ML��ֵ��ʹֵ����ָ����ֵ��
   * @param[in] icdev �豸��ʶ����
   * @param[in] _Value Ҫ���ٵ���ֵ��
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_decrement_ml(HANDLE icdev, unsigned short _Value);

  /**
   * @brief  ��֤M1�����롣
   * @par    ˵����
   * ʹ���豸�ڲ�װ�ص���������֤M1�����롣
   * @param[in] icdev �豸��ʶ����
   * @param[in] _Mode ģʽ��ͬ ::dc_authentication �� @a _Mode ��
   * @param[in] KeyNr Ҫ��֤����������š�
   * @param[in] Adr Ҫ��֤���������еĿ�ţ��˿�ŷǿ�Ƭ���Կ�š�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_authentication_2(HANDLE icdev, unsigned char _Mode, unsigned char KeyNr, unsigned char Adr);

  /**
   * @brief  �ڶ���������ͻ��
   * @par    ˵����
   * ֧��ISO 14443 Type A���Ϳ�Ƭ�ĵڶ���������ͻ��
   * @param[in] icdev �豸��ʶ����
   * @param[in] _Bcnt �������̶�Ϊ0x00��
   * @param[out] _Snr ���صĿ����кš�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_anticoll2(HANDLE icdev, unsigned char _Bcnt, unsigned int *_Snr);

  /**
   * @brief  �ڶ���ѡ��������
   * @par    ˵����
   * ͨ��ָ�����кţ�ѡȡ��Ӧ�Ŀ�Ƭ��
   * @param[in] icdev �豸��ʶ����
   * @param[in] _Snr ��Ƭ���кš�
   * @param[out] _Size ���ص�SAKֵ��
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_select2(HANDLE icdev, unsigned int _Snr, unsigned char *_Size);

  /**
   * @brief  ������
   */
  short USER_API dc_HL_write(HANDLE icdev, unsigned char _Mode, unsigned char _Adr, unsigned int *_Snr, unsigned char *_Data);

  /**
   * @brief  ������
   */
  short USER_API dc_HL_writehex(HANDLE icdev, unsigned char _Mode, unsigned char _Adr, unsigned int *_Snr, unsigned char *_Data);

  /**
   * @brief  ������
   */
  short USER_API dc_HL_read(HANDLE icdev, unsigned char _Mode, unsigned char _Adr, unsigned int _Snr, unsigned char *_Data, unsigned int *_NSnr);

  /**
   * @brief  ������
   */
  short USER_API dc_HL_readhex(HANDLE icdev, unsigned char _Mode, unsigned char _Adr, unsigned int _Snr, unsigned char *_Data, unsigned int *_NSnr);

  /**
   * @brief  �߲���֤M1�����롣
   * @par    ˵����
   * �ڲ������� ::dc_card ::dc_authentication �Ĺ��ܡ�
   * @param[in] icdev �豸��ʶ����
   * @param[in] reqmode Ѱ������ģʽ��ͬ ::dc_request �� @a _Mode ��
   * @param[in] snr �������̶�Ϊ0��
   * @param[in] authmode ��֤ģʽ��ͬ ::dc_authentication �� @a _Mode ��
   * @param[in] secnr Ҫ��֤����������š�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���==1��ʾ�޿����޷�Ѱ����Ƭ��
   */
  short USER_API dc_HL_authentication(HANDLE icdev, unsigned char reqmode, unsigned int snr, unsigned char authmode, unsigned char secnr);

  /**
   * @brief  ���֮ǰд������ݡ�
   * @par    ˵����
   * �ڲ������� ::dc_card ::dc_authentication ::dc_read �Ĺ��ܣ�������֤����Ͷ�ȡ�������Ƿ�һ�¡�
   * @param[in] icdev �豸��ʶ����
   * @param[in] Snr �����кţ������ڲ��˶ԡ�
   * @param[in] authmode ��֤ģʽ��ͬ ::dc_authentication �� @a _Mode ��
   * @param[in] Adr ���ַ��
   * @param[in] _data �����ݣ��̶�Ϊ16���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���==1��ʾ�޿����޷�Ѱ����Ƭ��
   */
  short USER_API dc_check_write(HANDLE icdev, unsigned int Snr, unsigned char authmode, unsigned char Adr, unsigned char *_data);

  /**
   * @brief  ���֮ǰд������ݡ�
   * @par    ˵����
   * ::dc_check_write ��HEX��ʽ�ӿڣ����� @a _data ΪHEX��ʽ��
   */
  short USER_API dc_check_writehex(HANDLE icdev, unsigned int Snr, unsigned char authmode, unsigned char Adr, unsigned char *_data);

  /**
   * @brief  ��ȡ�豸�汾��
   * @par    ˵����
   * ��ȡ�豸�ڲ��̼�����İ汾��
   * @param[in] icdev �豸��ʶ����
   * @param[out] sver ���صİ汾�ַ����������ٷ���128���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_getver(HANDLE icdev, unsigned char *sver);

  /**
   * @brief  ������
   */
  short USER_API dc_update(HANDLE icdev);

  /**
   * @brief  ������
   */
  short USER_API dc_clr_control_bit(HANDLE icdev, unsigned char _b);

  /**
   * @brief  ������
   */
  short USER_API dc_set_control_bit(HANDLE icdev, unsigned char _b);

  /**
   * @brief  ��λ��Ƶ��
   * @par    ˵����
   * ��λ�豸����Ƶ�����Թرգ��رղ���������
   * @param[in] icdev �豸��ʶ����
   * @param[in] _Msec Ϊ0��ʾ�ر���Ƶ������Ϊ��λʱ�䣬��λΪ10���룬һ����ý���ֵΪ10��
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_reset(HANDLE icdev, unsigned short _Msec);

  /**
   * @brief  �豸������
   * @par    ˵����
   * �豸����������ָ��ʱ��ķ�������
   * @param[in] icdev �豸��ʶ����
   * @param[in] _Msec ����ʱ�䣬��λΪ10���롣
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_beep(HANDLE icdev, unsigned short _Msec);

  /**
   * @brief  Һ����ʾ��
   * @par    ˵����
   * ��ʾָ���ַ�����Һ����Ļ�ϡ�
   * @param[in] icdev �豸��ʶ����
   * @param[in] dispstr Ҫ��ʾ���ַ�����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_disp_str(HANDLE icdev, char *dispstr);

  /**
   * @brief  ��EEPROM��
   * @par    ˵����
   * ��ȡ�豸�ڲ�EEPROM�е����ݣ������������ݱ���ȡ�
   * @param[in] icdev �豸��ʶ����
   * @param[in] offset ƫ�Ƶ�ַ��
   * @param[in] length ��ȡ���ȡ�
   * @param[out] rec_buffer ���ص����ݡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_srd_eeprom(HANDLE icdev, short offset, short length, unsigned char *rec_buffer);

  /**
   * @brief  дEEPROM��
   * @par    ˵����
   * д�����ݵ��豸�ڲ�EEPROM�У������������ݱ���ȡ�
   * @param[in] icdev �豸��ʶ����
   * @param[in] offset ƫ�Ƶ�ַ��
   * @param[in] length д�볤�ȡ�
   * @param[in] send_buffer �������ݡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_swr_eeprom(HANDLE icdev, short offset, short length, unsigned char *send_buffer);

  /**
   * @brief  дEEPROM��
   * @par    ˵����
   * ͬ ::dc_swr_eeprom ��
   */
  short USER_API swr_alleeprom(HANDLE icdev, short offset, short length, unsigned char *snd_buffer);

  /**
   * @brief  ��EEPROM��
   * @par    ˵����
   * ͬ ::dc_srd_eeprom ��
   */
  short USER_API srd_alleeprom(HANDLE icdev, short offset, short length, unsigned char *receive_buffer);

  /**
   * @brief  ��EEPROM��
   * @par    ˵����
   * ::dc_srd_eeprom ��HEX��ʽ�ӿڣ����� @a rec_buffer ΪHEX��ʽ��
   */
  short USER_API dc_srd_eepromhex(HANDLE icdev, short offset, short length, unsigned char *rec_buffer);

  /**
   * @brief  дEEPROM��
   * @par    ˵����
   * ::dc_swr_eeprom ��HEX��ʽ�ӿڣ����� @a send_buffer ΪHEX��ʽ��
   */
  short USER_API dc_swr_eepromhex(HANDLE icdev, short offset, short length, unsigned char *send_buffer);

  /**
   * @brief  ��ȡ�豸ʱ�䡣
   * @par    ˵����
   * ��ȡ�豸��ǰ��ʱ�䡣
   * @param[in] icdev �豸��ʶ����
   * @param[out] time ���ص�ʱ�䣬����Ϊ7���ֽڣ���ʽΪ'��'��'����'��'��'��'��'��'ʱ'��'��'��'��'���磺0x16,0x01,0x12,0x08,0x16,0x20,0x10��ʾ2016������һ12��8��16ʱ20��10�롣
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_gettime(HANDLE icdev, unsigned char *time);

  /**
   * @brief  ��ȡ�豸ʱ�䡣
   * @par    ˵����
   * ::dc_gettime ��HEX��ʽ�ӿڣ����� @a time ΪHEX��ʽ��
   */
  short USER_API dc_gettimehex(HANDLE icdev, char *time);

  /**
   * @brief  �����豸ʱ�䡣
   * @par    ˵����
   * �����豸�ĵ�ǰʱ�䡣
   * @param[in] icdev �豸��ʶ����
   * @param[in] time ����ʱ�䣬����Ϊ7���ֽڣ���ʽΪ'��'��'����'��'��'��'��'��'ʱ'��'��'��'��'���磺0x16,0x01,0x12,0x08,0x16,0x20,0x10��ʾ2016������һ12��8��16ʱ20��10�롣
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_settime(HANDLE icdev, unsigned char *time);

  /**
   * @brief  �����豸ʱ�䡣
   * @par    ˵����
   * ::dc_settime ��HEX��ʽ�ӿڣ����� @a time ΪHEX��ʽ��
   */
  short USER_API dc_settimehex(HANDLE icdev, char *time);

  /**
   * @brief  ������
   */
  short USER_API dc_setbright(HANDLE icdev, unsigned char bright);

  /**
   * @brief  ������
   */
  short USER_API dc_ctl_mode(HANDLE icdev, unsigned char mode);

  /**
   * @brief  ������
   */
  short USER_API dc_disp_mode(HANDLE icdev, unsigned char mode);

  /**
   * @brief  ��DES�ӽ��ܡ�
   * @par    ˵����
   * ::dcdes ��HEX��ʽ�ӿڣ����� @a key @a sour @a dest ΪHEX��ʽ��
   */
  short USER_API dcdeshex(unsigned char *key, unsigned char *sour, unsigned char *dest, short m);

  /**
   * @brief  ��DES�ӽ��ܡ�
   * @par    ˵����
   * ʹ�õ�DES�㷨�����ݽ��м���/���ܡ�
   * @param[in] key 8���ֽ���Կ��
   * @param[in] sour 8���ֽ�Ҫ������/���ܵ����ݡ�
   * @param[out] dest ����8���ֽ����������ݡ�
   * @param[in] m ģʽ��0-���ܣ�1-���ܡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dcdes(unsigned char *key, unsigned char *sour, unsigned char *dest, short m);

  /**
   * @brief  ָʾ�Ƶ���/Ϩ��
   * @par    ˵����
   * ����/Ϩ���豸��ָʾ�ơ�
   * @param[in] icdev �豸��ʶ����
   * @param[in] _OnOff 0-������1-Ϩ��
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_light(HANDLE icdev, unsigned short _OnOff);

  /**
   * @brief  Һ����ʾ��
   * @par    ˵����
   * ��ʾָ�����ݵ�Һ����Ļ�ϡ�
   * @param[in] icdev �豸��ʶ����
   * @param[in] offset ��Ļƫ�ơ�
   * @param[in] displen ��ʾ���ݵĳ��ȡ�
   * @param[in] dispstr ��ʾ���ݡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_high_disp(HANDLE icdev, unsigned char offset, unsigned char displen, unsigned char *dispstr);

  /**
   * @brief  ���õ�ǰ�Ӵ�ʽ������
   * @par    ˵����
   * ���õ�ǰ�Ӵ�ʽ����Ϊָ�����������ڶ࿨���л���������
   * @param[in] icdev �豸��ʶ����
   * @param[in] _Byte ������š�
   * @n 0x0C - ������/�Ӵ�ʽCPU1������
   * @n 0x0B - �Ӵ�ʽCPU2������
   * @n 0x0D - SAM1������
   * @n 0x0E - SAM2������
   * @n 0x0F - SAM3������
   * @n 0x11 - SAM4������
   * @n 0x12 - SAM5������
   * @n 0x13 - SAM6����/ESAMоƬ��
   * @n 0x14 - SAM7������
   * @n 0x15 - SAM8������
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_setcpu(HANDLE icdev, unsigned char _Byte);

  /**
   * @brief  �Ӵ�ʽCPU����λ��
   * @par    ˵����
   * �Ե�ǰ����CPU�����и�λ�������˸�λΪ�临λ��
   * @param[in] icdev �豸��ʶ����
   * @param[out] rlen ���ظ�λ��Ϣ�ĳ��ȡ�
   * @param[out] databuffer ���صĸ�λ��Ϣ�������ٷ���128���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_cpureset(HANDLE icdev, unsigned char *rlen, unsigned char *databuffer);

  /**
   * @brief  �Ӵ�ʽCPU��ָ�����
   * @par    ˵����
   * �Ե�ǰ����CPU������ָ���������ע��˽ӿڲ���װ��Э�鲿�֡�
   * @param[in] icdev �豸��ʶ����
   * @param[in] slen �������ݵĳ��ȡ�
   * @param[in] sendbuffer �������ݡ�
   * @param[out] rlen �������ݵĳ��ȡ�
   * @param[out] databuffer ���ص����ݡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_cpuapdusource(HANDLE icdev, unsigned char slen, unsigned char *sendbuffer, unsigned char *rlen, unsigned char *databuffer);

  /**
   * @brief  �Ӵ�ʽCPU��ָ�����
   * @par    ˵����
   * �Ե�ǰ����CPU������ָ���������ע��˽ӿ��ѷ�װ��Э�鲿�֡�
   * @param[in] icdev �豸��ʶ����
   * @param[in] slen �������ݵĳ��ȡ�
   * @param[in] sendbuffer �������ݡ�
   * @param[out] rlen �������ݵĳ��ȡ�
   * @param[out] databuffer ���ص����ݡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_cpuapdu(HANDLE icdev, unsigned char slen, unsigned char *sendbuffer, unsigned char *rlen, unsigned char *databuffer);

  /**
   * @brief  �Ӵ�ʽCPU����λ��
   * @par    ˵����
   * ::dc_cpureset ��HEX��ʽ�ӿڣ����� @a databuffer ΪHEX��ʽ��
   */
  short USER_API dc_cpureset_hex(HANDLE icdev, unsigned char *rlen, char *databuffer);

  /**
   * @brief  �Ӵ�ʽCPU��ָ�����
   * @par    ˵����
   * ::dc_cpuapdusource ��HEX��ʽ�ӿڣ����� @a sendbuffer @a databuffer ΪHEX��ʽ��
   */
  short USER_API dc_cpuapdusource_hex(HANDLE icdev, unsigned char slen, char *sendbuffer, unsigned char *rlen, char *databuffer);

  /**
   * @brief  �Ӵ�ʽCPU��ָ�����
   * @par    ˵����
   * ::dc_cpuapdu ��HEX��ʽ�ӿڣ����� @a sendbuffer @a databuffer ΪHEX��ʽ��
   */
  short USER_API dc_cpuapdu_hex(HANDLE icdev, unsigned char slen, char *sendbuffer, unsigned char *rlen, char *databuffer);

  /**
   * @brief  �Ӵ�ʽCPU��ָ�����
   * @par    ˵����
   * �Ե�ǰ����CPU������ָ���������ע��˽ӿ��ѷ�װ��Э�鲿�֣��ڲ�������SW1Ϊ0x61��0x6C�������
   * @param[in] icdev �豸��ʶ����
   * @param[in] slen �������ݵĳ��ȡ�
   * @param[in] sendbuffer �������ݡ�
   * @param[out] rlen �������ݵĳ��ȡ�
   * @param[out] databuffer ���ص����ݡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_cpuapdurespon(HANDLE icdev, unsigned char slen, unsigned char *sendbuffer, unsigned char *rlen, unsigned char *databuffer);

  /**
   * @brief  �Ӵ�ʽCPU��ָ�����
   * @par    ˵����
   * ::dc_cpuapdurespon ��HEX��ʽ�ӿڣ����� @a sendbuffer @a databuffer ΪHEX��ʽ��
   */
  short USER_API dc_cpuapdurespon_hex(HANDLE icdev, unsigned char slen, char *sendbuffer, unsigned char *rlen, char *databuffer);

  /**
   * @brief  �Ӵ�ʽCPU���µ硣
   * @par    ˵����
   * �Ե�ǰ����CPU�������µ������
   * @param[in] icdev �豸��ʶ����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_cpudown(HANDLE icdev);

  /**
   * @brief  ������
   */
  short USER_API dc_set_addr(unsigned char saddr);

  /**
   * @brief  ������
   */
  HANDLE USER_API dc_init_485(short port, int baud);

  /**
   * @brief  ������
   */
  short USER_API dc_changebaud_485(HANDLE icdev, int baud);

  /**
   * @brief  ������
   */
  short USER_API dc_change_addr(HANDLE icdev, unsigned char saddr);

  /**
   * @brief  �ǽӴ�ʽCPU����λ��
   * @par    ˵����
   * �Ը�Ӧ��CPU�����и�λ������
   * @param[in] icdev �豸��ʶ����
   * @param[out] rlen ���ظ�λ��Ϣ�ĳ��ȡ�
   * @param[out] receive_data ���صĸ�λ��Ϣ�������ٷ���128���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_pro_reset(HANDLE icdev, unsigned char *rlen, unsigned char *receive_data);

  /**
   * @brief  �ǽӴ�ʽCPU��ָ�����
   * @par    ˵����
   * �Ը�Ӧ��CPU������ָ���������ע��˽ӿ��ѷ�װ��Э�鲿�֡�
   * @param[in] icdev �豸��ʶ����
   * @param[in] slen �������ݵĳ��ȡ�
   * @param[in] sendbuffer �������ݡ�
   * @param[out] rlen �������ݵĳ��ȡ�
   * @param[out] databuffer ���ص����ݡ�
   * @param[in] timeout ��ʱֵ����ֵֻ�ڲ����豸�ĵײ�ʹ�ã���λΪ250���룬һ����ý���ֵΪ7��
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_pro_command(HANDLE icdev, unsigned char slen, unsigned char *sendbuffer, unsigned char *rlen, unsigned char *databuffer, unsigned char timeout);

  /**
   * @brief  �ǽӴ�ʽCPU����λ��
   * @par    ˵����
   * ::dc_pro_reset ��HEX��ʽ�ӿڣ����� @a receive_data ΪHEX��ʽ��
   */
  short USER_API dc_pro_resethex(HANDLE icdev, unsigned char *rlen, char *receive_data);

  /**
   * @brief  �ǽӴ�ʽCPU����λ��
   * @par    ˵����
   * �Ը�Ӧ��CPU�����и�λ������
   * @param[in] icdev �豸��ʶ����
   * @param[out] rlen ���ظ�λ��Ϣ�ĳ��ȡ�
   * @param[out] receive_data ���صĸ�λ��Ϣ�������ٷ���128���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_pro_resetInt(HANDLE icdev, unsigned char *rlen, unsigned char *receive_data);

  /**
   * @brief  �ǽӴ�ʽCPU����λ��
   * @par    ˵����
   * ::dc_pro_resetInt ��HEX��ʽ�ӿڣ����� @a receive_data ΪHEX��ʽ��
   */
  short USER_API dc_pro_resetInt_hex(HANDLE icdev, unsigned char *rlen, char *receive_data);

  /**
   * @brief  �ǽӴ�ʽCPU��ָ�����
   * @par    ˵����
   * ::dc_pro_command ��HEX��ʽ�ӿڣ����� @a sendbuffer @a databuffer ΪHEX��ʽ��
   */
  short USER_API dc_pro_commandhex(HANDLE icdev, unsigned char slen, char *sendbuffer, unsigned char *rlen, char *databuffer, unsigned char timeout);

  /**
   * @brief  �ǽӴ�ʽCPU��ָ�����
   * @par    ˵����
   * �Ը�Ӧ��CPU������ָ���������ע��˽ӿڲ���װ��Э�鲿�֡�
   * @param[in] icdev �豸��ʶ����
   * @param[in] slen �������ݵĳ��ȡ�
   * @param[in] sendbuffer �������ݡ�
   * @param[out] rlen �������ݵĳ��ȡ�
   * @param[out] databuffer ���ص����ݡ�
   * @param[in] timeout ��ʱֵ����ֵֻ�ڲ����豸�ĵײ�ʹ�ã���λΪ250���룬һ����ý���ֵΪ7��
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_pro_commandsource(HANDLE icdev, unsigned char slen, unsigned char *sendbuffer, unsigned char *rlen, unsigned char *databuffer, unsigned char timeout);

  /**
   * @brief  �ǽӴ�ʽCPU��ָ�����
   * @par    ˵����
   * ::dc_pro_commandsource ��HEX��ʽ�ӿڣ����� @a sendbuffer @a databuffer ΪHEX��ʽ��
   */
  short USER_API dc_pro_commandsourcehex(HANDLE icdev, unsigned char slen, char *sendbuffer, unsigned char *rlen, char *databuffer, unsigned char timeout);

  /**
   * @brief  �ǽӴ�ʽCPU��ָ�����
   * @par    ˵����
   * �Ը�Ӧ��CPU������ָ���������ע��˽ӿڲ���װ��Э�鲿�֡�
   * @param[in] icdev �豸��ʶ����
   * @param[in] slen �������ݵĳ��ȡ�
   * @param[in] sendbuffer �������ݡ�
   * @param[out] rlen �������ݵĳ��ȡ�
   * @param[out] databuffer ���ص����ݡ�
   * @param[in] timeout ��ʱֵ����ֵֻ�ڲ����豸�ĵײ�ʹ�ã���λΪ250���룬һ����ý���ֵΪ7��
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_pro_commandsource_int(HANDLE icdev, unsigned int slen, unsigned char *sendbuffer, unsigned int *rlen, unsigned char *databuffer, unsigned char timeout);

  /**
   * @brief  ��ֹ�ǽӴ�ʽCPU��������
   * @par    ˵����
   * ʹ�ǽӴ�ʽCPU��������ֹ״̬����ʱ����ѿ��Ƴ���Ӧ�����ٴη����Ӧ������Ѱ�����ſ���
   * @param[in] icdev �豸��ʶ����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_pro_halt(HANDLE icdev);

  /**
   * @brief  SHC1102��Ѱ������
   * @par    ˵����
   * ֧��SHC1102����Ѱ������
   * @param[in] icdev �豸��ʶ����
   * @param[in] _Mode ģʽ��0x00��ʾ�Կ��п����в�����0x01��ʾ�����п�������
   * @param[out] TagType ���ص�ATQAֵ��
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���==1��ʾ�޿����޷�Ѱ����Ƭ��
   */
  short USER_API dc_request_shc1102(HANDLE icdev, unsigned char _Mode, unsigned short *TagType);

  /**
   * @brief  ��֤SHC1102�����롣
   * @par    ˵����
   * ʹ�ô������������֤SHC1102�����롣
   * @param[in] icdev �豸��ʶ����
   * @param[in] _Data ���룬�̶�Ϊ4���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_auth_shc1102(HANDLE icdev, unsigned char *_Data);

  /**
   * @brief  ��SHC1102����
   * @par    ˵����
   * ��ȡSHC1102�������ݡ�
   * @param[in] icdev �豸��ʶ����
   * @param[in] _Adr ���ַ��0~15����
   * @param[out] _Data ���ص����ݣ��̶�Ϊ4���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_read_shc1102(HANDLE icdev, unsigned char _Adr, unsigned char *_Data);

  /**
   * @brief  дSHC1102����
   * @par    ˵����
   * д�����ݵ�SHC1102���С�
   * @param[in] icdev �豸��ʶ����
   * @param[in] _Adr ���ַ��2~15����
   * @param[in] _Data �������ݣ��̶�Ϊ4���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_write_shc1102(HANDLE icdev, unsigned char _Adr, unsigned char *_Data);

  /**
   * @brief  ��ֹSHC1102��������
   * @par    ˵����
   * ʹSHC1102��������ֹ״̬����ʱ����ѿ��Ƴ���Ӧ�����ٴη����Ӧ������Ѱ�����ſ���
   * @param[in] icdev �豸��ʶ����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_halt_shc1102(HANDLE icdev);

  /**
   * @brief  ����ת����
   * @par    ˵����
   * ��ͨ���ݻ���ʮ�������ַ�������ת������
   * @param[in] hex Ҫת�������ݡ�
   * @param[out] a ת������ַ�����
   * @param[in] length Ҫת�����ݵĳ��ȡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API hex_a(unsigned char *hex, unsigned char *a, short length);

  /**
   * @brief  ����ת����
   * @par    ˵����
   * ʮ�������ַ�����ת��Ϊ��ͨ���ݣ���ת�̣���
   * @param[in] a Ҫת�������ݡ�
   * @param[out] hex ת��������ݡ�
   * @param[in] len Ҫת�����ݵĳ��ȡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API a_hex(unsigned char *a, unsigned char *hex, short len);

  /**
   * @brief  ���÷ǽӴ������͡�
   * @par    ˵����
   * ������Ҫ����ʲô���͵ķǽӴ�ʽ�����豸�ϵ��Ĭ�ϲ���Type A��������ʹ�ô˽ӿ����ı����ͣ�һ����Ѱ��ǰ���ô˽ӿڡ�
   * @param[in] icdev �豸��ʶ����
   * @param[in] cardtype ���ͣ�'A'��ʾType A����'B'��ʾType B����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_config_card(HANDLE icdev, unsigned char cardtype);

  /**
   * @brief  Ѱ������
   * @par    ˵����
   * ֧��ISO 14443 Type B���Ϳ�Ƭ��Ѱ������
   * @param[in] icdev �豸��ʶ����
   * @param[in] _Mode �������̶�Ϊ0x00��
   * @param[in] AFI Ӧ�����ʶ����
   * @param[in] N ʱ��۱�š�
   * @param[out] ATQB ���ص�ATQBֵ�������ٷ���32���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_request_b(HANDLE icdev, unsigned char _Mode, unsigned char AFI, unsigned char N, unsigned char *ATQB);

  /**
   * @brief  �ܵ���ǡ�
   * @par    ˵����
   * ֧��ISO 14443 Type B���Ϳ�Ƭ�Ĺܵ���ǡ�
   * @param[in] icdev �豸��ʶ����
   * @param[in] N ʱ��۱�š�
   * @param[out] ATQB ���ص�ATQBֵ�������ٷ���32���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_slotmarker(HANDLE icdev, unsigned char N, unsigned char *ATQB);

  /**
   * @brief  ���Ƭ��
   * @par    ˵����
   * ֧��ISO 14443 Type B���Ϳ�Ƭ�ļ��
   * @param[in] icdev �豸��ʶ����
   * @param[in] PUPI αΨһPICC��ʶ�����̶�Ϊ4���ֽڡ�
   * @param[in] CID �ŵ��š�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_attrib(HANDLE icdev, unsigned char *PUPI, unsigned char CID);

  /**
   * @brief  ������
   */
  short USER_API dc_open_door(HANDLE icdev, unsigned char cflag);

  /**
   * @brief  ������
   */
  short USER_API dc_open_timedoor(HANDLE icdev, unsigned short utime);

  /**
   * @brief  ������
   */
  short USER_API dc_read_random(HANDLE icdev, unsigned char *data);

  /**
   * @brief  ������
   */
  short USER_API dc_write_random(HANDLE icdev, short length, unsigned char *data);

  /**
   * @brief  ������
   */
  short USER_API dc_read_random_hex(HANDLE icdev, unsigned char *data);

  /**
   * @brief  ������
   */
  short USER_API dc_write_random_hex(HANDLE icdev, short length, unsigned char *data);

  /**
   * @brief  ������
   */
  short USER_API dc_erase_random(HANDLE icdev, short length);

  /**
   * @brief  Mifare Desfire����֤��
   * @par    ˵����
   * ��Mifare Desfire��������֤��
   * @param[in] icdev �豸��ʶ����
   * @param[in] keyno ��Կ�š�
   * @param[in] keylen ��Կ���ݵĳ��ȡ�
   * @param[in] authkey ��Կ���ݡ�
   * @param[in] randAdata ���������A��8���ֽڡ�
   * @param[out] randBdata ���ص������B��8���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_mfdes_auth(HANDLE icdev, unsigned char keyno, unsigned char keylen, unsigned char *authkey, unsigned char *randAdata, unsigned char *randBdata);

  /**
   * @brief  ��֤M1�����롣
   * @par    ˵����
   * ʹ�ô������������֤M1�����롣
   * @param[in] icdev �豸��ʶ����
   * @param[in] _Mode ģʽ��0x00��ʾ��֤A���룬0x04��ʾ��֤B���롣
   * @param[in] _Addr Ҫ��֤����������š�
   * @param[in] passbuff ���룬�̶�Ϊ6���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_authentication_pass(HANDLE icdev, unsigned char _Mode, unsigned char _Addr, unsigned char *passbuff);

  /**
   * @brief  �߲�Һ����ʾ��
   * @par    ˵����
   * ��ʾָ�����ݵ�Һ����Ļ�ϡ�
   * @param[in] icdev �豸��ʶ����
   * @param[in] dispstr ��ʾ�ַ�����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_disp_neg(HANDLE icdev, char *dispstr);

  /**
   * @brief  �ǽӴ�ʽCPU��ָ�����
   * @par    ˵����
   * �Ը�Ӧ��CPU������ָ���������ע��˽ӿ��ѷ�װ��Э�鲿�֡�
   * @param[in] icdev �豸��ʶ����
   * @param[in] slen �������ݵĳ��ȡ�
   * @param[in] sendbuffer �������ݡ�
   * @param[out] rlen �������ݵĳ��ȡ�
   * @param[out] databuffer ���ص����ݡ�
   * @param[in] timeout ��ʱֵ����ֵֻ�ڲ����豸�ĵײ�ʹ�ã���λΪ250���룬һ����ý���ֵΪ7��
   * @param[in] FG �ָ�ֵ����ֵֻ�ڲ����豸�ĵײ�ʹ�ã���λΪ�ֽڣ�һ����ý���ֵΪ64��
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_pro_commandlink(HANDLE icdev, unsigned char slen, unsigned char *sendbuffer, unsigned char *rlen, unsigned char *databuffer, unsigned char timeout, unsigned char FG);

  /**
   * @brief  �ǽӴ�ʽCPU��ָ�����
   * @par    ˵����
   * ::dc_pro_commandlink ��HEX��ʽ�ӿڣ����� @a sendbuffer @a databuffer ΪHEX��ʽ��
   */
  short USER_API dc_pro_commandlink_hex(HANDLE icdev, unsigned char slen, unsigned char *sendbuffer, unsigned char *rlen, unsigned char *databuffer, unsigned char timeout, unsigned char FG);

  /**
   * @brief  Ѱ�����󡢷�����ͻ��ѡ��������
   * @par    ˵����
   * �ڲ������� ::dc_request ::dc_anticoll ::dc_select ::dc_anticoll2 ::dc_select2 �Ĺ��ܣ��˽ӿ������ȱ�ݣ����ܷ��ؿ����к�ʵ�ʳ��ȣ�����ʹ�� ::dc_card_n �����
   * @param[in] icdev �豸��ʶ����
   * @param[in] _Mode ģʽ��ͬ ::dc_request �� @a _Mode ��
   * @param[out] _Snr ���صĿ����кţ������ٷ���8���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���==1��ʾ�޿����޷�Ѱ����Ƭ��
   */
  short USER_API dc_card_double(HANDLE icdev, unsigned char _Mode, unsigned char *_Snr);

  /**
   * @brief  Ѱ�����󡢷�����ͻ��ѡ��������
   * @par    ˵����
   * ::dc_card_double ��HEX��ʽ�ӿڣ����� @a _Snr ΪHEX��ʽ��
   */
  short USER_API dc_card_double_hex(HANDLE icdev, unsigned char _Mode, unsigned char *_Snr);

  /**
   * @brief  ��ID����
   * @par    ˵����
   * ��ȡID�����ݡ�
   * @param[in] icdev �豸��ʶ����
   * @param[in] times �豸��ʱֵ����λΪ�롣
   * @param[out] _Data ���ص����ݣ��̶�Ϊ5���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_read_idcard(HANDLE icdev, unsigned char times, unsigned char *_Data);

  /**
   * @brief  ��ȡid����
   * @par    ˵����
   * ::dc_read_idcard ��HEX��ʽ�ӿڣ����� @a _Data ΪHEX��ʽ��
   */
  short USER_API dc_read_idcard_hex(HANDLE icdev, unsigned char times, unsigned char *_Data);

  /**
   * @brief  ��֤M1�����롣
   * @par    ˵����
   * ::dc_authentication_pass ��HEX��ʽ�ӿڣ����� @a passbuff ΪHEX��ʽ��
   */
  short USER_API dc_authentication_pass_hex(HANDLE icdev, unsigned char _Mode, unsigned char _Addr, unsigned char *passbuff);

  /**
   * @brief  ���ýӴ�ʽCPU��������
   * @par    ˵����
   * �˽ӿڿɿ��ƽӴ�ʽCPU����������Ϊ����������ʱ���豸��ʹ��Ĭ�Ϸ�ʽ���нӴ�ʽCPU��������
   * @param[in] icdev �豸��ʶ����
   * @param[in] cputype ������ţ�ͬ ::dc_setcpu �� @a _Byte ��
   * @param[in] cpupro ��Э���ţ�0x00��ʾT0��0x01��ʾT1��Ĭ��Ϊ0x00��
   * @param[in] cpuetu ����λ�����ʱ�ţ�0x5C��ʾ9600��0x14��ʾ38400.
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_setcpupara(HANDLE icdev, unsigned char cputype, unsigned char cpupro, unsigned char cpuetu);

  /**
   * @brief  ������
   */
  short USER_API dc_command(HANDLE icdev, unsigned char cmd, unsigned char slen, unsigned char *sendbuffer, unsigned char *rlen, unsigned char *databuffer);

  /**
   * @brief  ������
   */
  short USER_API dc_command_hex(HANDLE icdev, unsigned char cmd, unsigned char slen, char *sendbuffer, unsigned char *rlen, char *databuffer);

  /**
   * @brief  ������
   */
  short USER_API dc_creat_mac(unsigned char KeyLen, unsigned char *Key, unsigned short DataLen, unsigned char *Data, unsigned char *InitData, unsigned char AutoFixFlag, unsigned char FixChar, unsigned char *MacData);

  /**
   * @brief  ������
   */
  short USER_API dc_creat_mac_hex(unsigned char KeyLen, unsigned char *Key, unsigned short DataLen, unsigned char *Data, unsigned char *InitData, unsigned char AutoFixFlag, unsigned char FixChar, unsigned char *MacData);

  /**
   * @brief  ������
   */
  short USER_API dc_creat_mac2(HANDLE icdev, unsigned short DataLen, unsigned char *Data, unsigned char *MacData, unsigned char flag);

  /**
   * @brief  ������
   */
  short USER_API dc_creat_mac2_hex(HANDLE icdev, unsigned short DataLen, unsigned char *Data, unsigned char *MacData, unsigned char flag);

  /**
   * @brief  ������
   */
  short USER_API dc_encrypt(char *key, char *ptrSource, unsigned short msgLen, char *ptrDest);

  /**
   * @brief  ������
   */
  short USER_API dc_decrypt(char *key, char *ptrSource, unsigned short msgLen, char *ptrDest);

  /**
   * @brief  ������
   */
  short USER_API dc_encrypt_hex(char *key, char *ptrSource, unsigned short msgLen, char *ptrDest);

  /**
   * @brief  ������
   */
  short USER_API dc_decrypt_hex(char *key, char *ptrSource, unsigned short msgLen, char *ptrDest);

  /**
   * @brief  ������
   */
  short USER_API dc_HL_write_hex(HANDLE icdev, unsigned char _Mode, unsigned char _Adr, unsigned int *_Snr, unsigned char *_Data);

  /**
   * @brief  ������
   */
  short USER_API dc_HL_read_hex(HANDLE icdev, unsigned char _Mode, unsigned char _Adr, unsigned int _Snr, unsigned char *_Data, unsigned int *_NSnr);

  /**
   * @brief  ���֮ǰд������ݡ�
   * @par    ˵����
   * ::dc_check_write ��HEX��ʽ�ӿڣ����� @a _data ΪHEX��ʽ��
   */
  short USER_API dc_check_write_hex(HANDLE icdev, unsigned int Snr, unsigned char authmode, unsigned char Adr, unsigned char *_data);

  /**
   * @brief  ��EEPROM��
   * @par    ˵����
   * ::dc_srd_eeprom ��HEX��ʽ�ӿڣ����� @a rec_buffer ΪHEX��ʽ��
   */
  short USER_API dc_srd_eeprom_hex(HANDLE icdev, short offset, short length, unsigned char *rec_buffer);

  /**
   * @brief  дEEPROM��
   * @par    ˵����
   * ::dc_swr_eeprom ��HEX��ʽ�ӿڣ����� @a send_buffer ΪHEX��ʽ��
   */
  short USER_API dc_swr_eeprom_hex(HANDLE icdev, short offset, short length, unsigned char *send_buffer);

  /**
   * @brief  ��ȡ�豸ʱ�䡣
   * @par    ˵����
   * ::dc_gettime ��HEX��ʽ�ӿڣ����� @a time ΪHEX��ʽ��
   */
  short USER_API dc_gettime_hex(HANDLE icdev, char *time);

  /**
   * @brief  �����豸ʱ�䡣
   * @par    ˵����
   * ::dc_settime ��HEX��ʽ�ӿڣ����� @a time ΪHEX��ʽ��
   */
  short USER_API dc_settime_hex(HANDLE icdev, char *time);

  /**
   * @brief  ��DES�ӽ��ܡ�
   * @par    ˵����
   * ::dc_des ��HEX��ʽ�ӿڣ����� @a key @a sour @a dest ΪHEX��ʽ��
   */
  short USER_API dc_des_hex(unsigned char *key, unsigned char *sour, unsigned char *dest, short m);

  /**
   * @brief  ��DES�ӽ��ܡ�
   * @par    ˵����
   * ʹ�õ�DES�㷨�����ݽ��м���/���ܡ�
   * @param[in] key 8���ֽ���Կ��
   * @param[in] sour 8���ֽ�Ҫ������/���ܵ����ݡ�
   * @param[out] dest ����8���ֽ����������ݡ�
   * @param[in] m ģʽ��0-���ܣ�1-���ܡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_des(unsigned char *key, unsigned char *sour, unsigned char *dest, short m);

  /**
   * @brief  �ǽӴ�ʽCPU����λ��
   * @par    ˵����
   * ::dc_pro_reset ��HEX��ʽ�ӿڣ����� @a receive_data ΪHEX��ʽ��
   */
  short USER_API dc_pro_reset_hex(HANDLE icdev, unsigned char *rlen, char *receive_data);

  /**
   * @brief  �ǽӴ�ʽCPU��ָ�����
   * @par    ˵����
   * ::dc_pro_command ��HEX��ʽ�ӿڣ����� @a sendbuffer @a databuffer ΪHEX��ʽ��
   */
  short USER_API dc_pro_command_hex(HANDLE icdev, unsigned char slen, char *sendbuffer, unsigned char *rlen, char *databuffer, unsigned char timeout);

  /**
   * @brief  �ǽӴ�ʽCPU��ָ�����
   * @par    ˵����
   * ::dc_pro_commandsource ��HEX��ʽ�ӿڣ����� @a sendbuffer @a databuffer ΪHEX��ʽ��
   */
  short USER_API dc_pro_commandsource_hex(HANDLE icdev, unsigned char slen, char *sendbuffer, unsigned char *rlen, char *databuffer, unsigned char timeout);

  /**
   * @brief  ������
   */
  short USER_API dc_switch_unix(HANDLE icdev, int baud);

  /**
   * @brief  ��֤M1�����롣
   * @par    ˵����
   * ʹ�ô������������֤M1�����롣
   * @param[in] icdev �豸��ʶ����
   * @param[in] _Mode ģʽ��0x00��ʾ��֤A���룬0x04��ʾ��֤B���롣
   * @param[in] _Addr Ҫ��֤����Ŀ�š�
   * @param[in] passbuff ���룬�̶�Ϊ6���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_authentication_passaddr(HANDLE icdev, unsigned char _Mode, unsigned char _Addr, unsigned char *passbuff);

  /**
   * @brief  ��֤M1�����롣
   * @par    ˵����
   * ::dc_authentication_passaddr ��HEX��ʽ�ӿڣ����� @a passbuff ΪHEX��ʽ��
   */
  short USER_API dc_authentication_passaddr_hex(HANDLE icdev, unsigned char _Mode, unsigned char _Addr, unsigned char *passbuff);

  /**
   * @brief  ѰFM11RF005����
   * @par    ˵����
   * ��FM11RF005������Ѱ��������
   * @param[in] icdev �豸��ʶ����
   * @param[in] _Mode ģʽ��ģʽ��ͬ ::dc_request �� @a _Mode ��
   * @param[out] _Snr ���صĿ����кš�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���==1��ʾ�޿����޷�Ѱ����Ƭ��
   */
  short USER_API dc_card_fm11rf005(HANDLE icdev, unsigned char _Mode, unsigned int *_Snr);

  /**
   * @brief  ������
   */
  short USER_API dc_setusbtimeout(unsigned char ntimes);

  /**
   * @brief  ������
   */
  short USER_API dc_mfdes_baud(HANDLE icdev, unsigned char _Mode, unsigned char para);

  /**
   * @brief  ��DES�ӽ��ܡ�
   * @par    ˵����
   * ʹ����DES�㷨�����ݽ��м���/���ܡ�
   * @param[in] key 16���ֽ���Կ��
   * @param[in] src 8���ֽ�Ҫ������/���ܵ����ݡ�
   * @param[out] dest ����8���ֽ����������ݡ�
   * @param[in] m ģʽ��0-���ܣ�1-���ܡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_tripledes(unsigned char *key, unsigned char *src, unsigned char *dest, short m);

  /**
   * @brief  ��DES�ӽ��ܡ�
   * @par    ˵����
   * ::dc_tripledes ��HEX��ʽ�ӿڣ����� @a key @a src @a dest ΪHEX��ʽ��
   */
  short USER_API dc_tripledes_hex(unsigned char *key, unsigned char *src, unsigned char *dest, short m);

  /**
   * @brief  Mifare Desfire����֤��
   * @par    ˵����
   * ::dc_mfdes_auth ��HEX��ʽ�ӿڣ����� @a authkey @a randAdata @a randBdata ΪHEX��ʽ��
   */
  short USER_API dc_mfdes_auth_hex(HANDLE icdev, unsigned char keyno, unsigned char keylen, unsigned char *authkey, unsigned char *randAdata, unsigned char *randBdata);

  /**
   * @brief  ������
   */
  short USER_API dc_pro_sendcommandsource(HANDLE icdev, unsigned char slen, unsigned char *sendbuffer, unsigned char timeout);

  /**
   * @brief  ������
   */
  short USER_API dc_pro_receivecommandsource(HANDLE icdev, unsigned char *rlen, unsigned char *databuffer);

  /**
   * @brief  ������
   */
  short USER_API dc_inventory(HANDLE icdev, unsigned char flags, unsigned char AFI, unsigned char masklen, unsigned char *rlen, unsigned char *rbuffer);

  /**
   * @brief  ������
   */
  short USER_API dc_inventory_hex(HANDLE icdev, unsigned char flags, unsigned char AFI, unsigned char masklen, unsigned char *rlen, unsigned char *rbuffer);

  /**
   * @brief  ������
   */
  short USER_API dc_stay_quiet(HANDLE icdev, unsigned char flags, unsigned char *UID);

  /**
   * @brief  ������
   */
  short USER_API dc_stay_quiet_hex(HANDLE icdev, unsigned char flags, unsigned char *UID);

  /**
   * @brief  ������
   */
  short USER_API dc_select_uid(HANDLE icdev, unsigned char flags, unsigned char *UID);

  /**
   * @brief  ������
   */
  short USER_API dc_select_uid_hex(HANDLE icdev, unsigned char flags, unsigned char *UID);

  /**
   * @brief  ������
   */
  short USER_API dc_reset_to_ready(HANDLE icdev, unsigned char flags, unsigned char *UID);

  /**
   * @brief  ������
   */
  short USER_API dc_reset_to_ready_hex(HANDLE icdev, unsigned char flags, unsigned char *UID);

  /**
   * @brief  ������
   */
  short USER_API dc_readblock(HANDLE icdev, unsigned char flags, unsigned char startblock, unsigned char blocknum, unsigned char *UID, unsigned char *rlen, unsigned char *rbuffer);

  /**
   * @brief  ������
   */
  short USER_API dc_readblock_hex(HANDLE icdev, unsigned char flags, unsigned char startblock, unsigned char blocknum, unsigned char *UID, unsigned char *rlen, unsigned char *rbuffer);

  /**
   * @brief  ������
   */
  short USER_API dc_writeblock(HANDLE icdev, unsigned char flags, unsigned char startblock, unsigned char blocknum, unsigned char *UID, unsigned char wlen, unsigned char *wbuffer);

  /**
   * @brief  ������
   */
  short USER_API dc_writeblock_hex(HANDLE icdev, unsigned char flags, unsigned char startblock, unsigned char blocknum, unsigned char *UID, unsigned char wlen, unsigned char *wbuffer);

  /**
   * @brief  ������
   */
  short USER_API dc_lock_block(HANDLE icdev, unsigned char flags, unsigned char block, unsigned char *UID);

  /**
   * @brief  ������
   */
  short USER_API dc_lock_block_hex(HANDLE icdev, unsigned char flags, unsigned char block, unsigned char *UID);

  /**
   * @brief  ������
   */
  short USER_API dc_write_afi(HANDLE icdev, unsigned char flags, unsigned char AFI, unsigned char *UID);

  /**
   * @brief  ������
   */
  short USER_API dc_write_afi_hex(HANDLE icdev, unsigned char flags, unsigned char AFI, unsigned char *UID);

  /**
   * @brief  ������
   */
  short USER_API dc_lock_afi(HANDLE icdev, unsigned char flags, unsigned char AFI, unsigned char *UID);

  /**
   * @brief  ������
   */
  short USER_API dc_lock_afi_hex(HANDLE icdev, unsigned char flags, unsigned char AFI, unsigned char *UID);

  /**
   * @brief  ������
   */
  short USER_API dc_write_dsfid(HANDLE icdev, unsigned char flags, unsigned char DSFID, unsigned char *UID);

  /**
   * @brief  ������
   */
  short USER_API dc_write_dsfid_hex(HANDLE icdev, unsigned char flags, unsigned char DSFID, unsigned char *UID);

  /**
   * @brief  ������
   */
  short USER_API dc_lock_dsfid(HANDLE icdev, unsigned char flags, unsigned char DSFID, unsigned char *UID);

  /**
   * @brief  ������
   */
  short USER_API dc_lock_dsfid_hex(HANDLE icdev, unsigned char flags, unsigned char DSFID, unsigned char *UID);

  /**
   * @brief  ������
   */
  short USER_API dc_get_systeminfo(HANDLE icdev, unsigned char flags, unsigned char *UID, unsigned char *rlen, unsigned char *rbuffer);

  /**
   * @brief  ������
   */
  short USER_API dc_get_systeminfo_hex(HANDLE icdev, unsigned char flags, unsigned char *UID, unsigned char *rlen, unsigned char *rbuffer);

  /**
   * @brief  ������
   */
  short USER_API dc_get_securityinfo(HANDLE icdev, unsigned char flags, unsigned char startblock, unsigned char blocknum, unsigned char *UID, unsigned char *rlen, unsigned char *rbuffer);

  /**
   * @brief  ������
   */
  short USER_API dc_get_securityinfo_hex(HANDLE icdev, unsigned char flags, unsigned char startblock, unsigned char blocknum, unsigned char *UID, unsigned char *rlen, unsigned char *rbuffer);

  /**
   * @brief  ��ȡFM11RF005�����кš�
   * @par    ˵����
   * ��ȡFM11RF005�����кš�
   * @param[in] icdev �豸��ʶ����
   * @param[out] _Snr ���صĿ����кš�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_getsnr_fm11rf005(HANDLE icdev, unsigned int *_Snr);

  /**
   * @brief  ��ȡFM11RF005�����кš�
   * @par    ˵����
   * ::dc_getsnr_fm11rf005 ��HEX��ʽ�ӿڣ����� @a snrstr ΪHEX��ʽ��
   */
  short USER_API dc_getsnr_fm11rf005_hex(HANDLE icdev, unsigned char *snrstr);

  /**
   * @brief  дFM11RF005����
   * @par    ˵����
   * д�����ݵ�FM11RF005���С�
   * @param[in] icdev �豸��ʶ����
   * @param[in] _Adr ���ַ��2~15����
   * @param[in] _Data �������ݣ��̶�Ϊ4���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_write_fm11rf005(HANDLE icdev, unsigned char _Adr, unsigned char *_Data);

  /**
   * @brief  ��FM11RF005����
   * @par    ˵����
   * ��ȡFM11RF005�������ݡ�
   * @param[in] icdev �豸��ʶ����
   * @param[in] _Adr ���ַ��0~15����
   * @param[out] _Data ���ص����ݣ��̶�Ϊ4���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_read_fm11rf005(HANDLE icdev, unsigned char _Adr, unsigned char *_Data);

  /**
   * @brief  ��FM11RF005����
   * @par    ˵����
   * ::dc_read_fm11rf005 ��HEX��ʽ�ӿڣ����� @a _Data ΪHEX��ʽ��
   */
  short USER_API dc_read_fm11rf005_hex(HANDLE icdev, unsigned char _Adr, char *_Data);

  /**
   * @brief  дFM11RF005����
   * @par    ˵����
   * ::dc_write_fm11rf005 ��HEX��ʽ�ӿڣ����� @a _Data ΪHEX��ʽ��
   */
  short USER_API dc_write_fm11rf005_hex(HANDLE icdev, unsigned char _Adr, char *_Data);

  /**
   * @brief  ������
   */
  short USER_API DCDEV_CommandMcu(HANDLE icdev, unsigned char ctimeout, unsigned char slen, unsigned char *sendbuffer, unsigned char *rlen, unsigned char *databuffer);

  /**
   * @brief  ������
   */
  short USER_API DCDEV_CommandMcu_Hex(HANDLE icdev, unsigned char ctimeout, unsigned char slen, unsigned char *sendbuffer, unsigned char *rlen, unsigned char *databuffer);

  /**
   * @brief  ������
   */
  short USER_API dc_displcd(HANDLE icdev, unsigned char flag);

  /**
   * @brief  �����������롣
   * @par    ˵����
   * ��ȡ���̰����������������룬��ͬ�ļ���װ�ÿ����в�ͬ��Ч�����粻ͬ����ʾ����ͬ����ʾ��
   * @param[in] icdev �豸��ʶ����
   * @param[in] ctime �豸��ʱֵ����λΪ�롣
   * @param[out] rlen ���ذ������ݵĳ��ȣ�����'\0'��
   * @param[out] cpass ���صİ������ݣ����ݸ�ʽΪ'\0'��β���ַ�����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���==0xA1��ʾȡ�����룬==0xA2��ʾ���볬ʱ��
   */
  short USER_API dc_getinputpass(HANDLE icdev, unsigned char ctime, unsigned char *rlen, unsigned char *cpass);

  /**
   * @brief  �����������롣
   * @par    ˵����
   * ��ȡ���̰����������������룬��ͬ�ļ���װ�ÿ����в�ͬ��Ч�����粻ͬ����ʾ����ͬ����ʾ��
   * @param[in] icdev �豸��ʶ����
   * @param[in] ctime �豸��ʱֵ����λΪ�롣
   * @param[out] rlen ���ذ������ݵĳ��ȣ�����'\0'��
   * @param[out] cpass ���صİ������ݣ����ݸ�ʽΪ'\0'��β���ַ�����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���==0xA1��ʾȡ�����룬==0xA2��ʾ���볬ʱ��
   */
  short USER_API dc_GetInputPass(HANDLE icdev, unsigned char ctime, unsigned char *rlen, unsigned char *cpass);

  /**
   * @brief  ����������
   * @par    ˵����
   * ��ȡ�����������ݣ�֧��2��3�����
   * @param[in] icdev �豸��ʶ����
   * @param[in] ctime �豸��ʱֵ����λΪ�롣
   * @param[out] pTrack2Data ���ص�2������ݣ����ݸ�ʽΪ'\0'��β���ַ�����
   * @param[out] pTrack2Len ����2������ݵĳ��ȣ�����'\0'��
   * @param[out] pTrack3Data ���ص�3������ݣ����ݸ�ʽΪ'\0'��β���ַ�����
   * @param[out] pTrack3Len ����3������ݵĳ��ȣ�����'\0'��
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_readmagcard(HANDLE icdev, unsigned char ctime, unsigned char *pTrack2Data, unsigned int *pTrack2Len, unsigned char *pTrack3Data, unsigned int *pTrack3Len);

  /**
   * @brief  д��������
   * @par    ˵����
   * д�����ݵ��������С�
   * @param[in] icdev �豸��ʶ����
   * @param[in] ctime �豸��ʱֵ����λΪ�롣
   * @param[in] pTrack1Data ����1������ݡ�
   * @param[in] pTrack1Len 1������ݵĳ��ȡ�
   * @param[in] pTrack2Data ����2������ݡ�
   * @param[in] pTrack2Len 2������ݵĳ��ȡ�
   * @param[in] pTrack3Data ����3������ݡ�
   * @param[in] pTrack3Len 3������ݵĳ��ȡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_writemagcard(HANDLE icdev, unsigned char ctime, unsigned char *pTrack1Data, unsigned char pTrack1Len, unsigned char *pTrack2Data, unsigned char pTrack2Len, unsigned char *pTrack3Data, unsigned char pTrack3Len);

  /**
   * @brief  �����豸ͨѶ��
   * @par    ˵����
   * ���Ժ��豸֮���Ƿ��������ͨѶ��
   * @param[in] icdev �豸��ʶ����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_testdevicecomm(HANDLE icdev);

  /**
   * @brief  ��ʾ�����档
   * @par    ˵����
   * ʹ�豸��Ļ����ʾԤ�õ������棬��ͬ�豸�������治����ͬ��
   * @param[in] icdev �豸��ʶ����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_dispmainmenu(HANDLE icdev);

  /**
   * @brief  �����豸ʱ�䡣
   * @par    ˵����
   * �����豸�ĵ�ǰʱ�䡣
   * @param[in] icdev �豸��ʶ����
   * @param[in] year �꣨0~99����
   * @param[in] month �£�1~12����
   * @param[in] date �գ�1~31����
   * @param[in] hour ʱ��0~23����
   * @param[in] minute �֣�0~59����
   * @param[in] second �루0~59����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_setdevicetime(HANDLE icdev, unsigned char year, unsigned char month, unsigned char date, unsigned char hour, unsigned char minute, unsigned char second);

  /**
   * @brief  ��ȡ�豸ʱ�䡣
   * @par    ˵����
   * ��ȡ�豸��ǰ��ʱ�䡣
   * @param[out] icdev �豸��ʶ����
   * @param[out] year �꣨0~99����
   * @param[out] month �£�1~12����
   * @param[out] date �գ�1~31����
   * @param[out] hour ʱ��0~23����
   * @param[out] minute �֣�0~59����
   * @param[out] second �루0~59����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_getdevicetime(HANDLE icdev, unsigned char *year, unsigned char *month, unsigned char *date, unsigned char *hour, unsigned char *minute, unsigned char *second);

  /**
   * @brief  Һ����ʾ��
   * @par    ˵����
   * ��ʾָ���ַ�����Һ����Ļ�ϡ�
   * @param[in] icdev �豸��ʶ����
   * @param[in] line �кš�
   * @param[in] offset ƫ�ơ�
   * @param[in] data Ҫ��ʾ���ַ�����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_dispinfo(HANDLE icdev, unsigned char line, unsigned char offset, char *data);

  /**
   * @brief  Һ����ʾ��
   * @par    ˵����
   * ��ʾָ���ַ�����Һ����Ļ�ϡ�
   * @param[in] icdev �豸��ʶ����
   * @param[in] offset ��Ļƫ�ơ�
   * @param[in] data Ҫ��ʾ���ַ�����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_dispmaininfo(HANDLE icdev, unsigned char offset, char *data);

  /**
   * @brief  �豸������
   * @par    ˵����
   * �豸����������ָ��ʱ��ķ�������
   * @param[in] icdev �豸��ʶ����
   * @param[in] beeptime ����ʱ�䣬��λΪ50���롣
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_posbeep(HANDLE icdev, unsigned char beeptime);

  /**
   * @brief  LCD������ơ�
   * @par    ˵����
   * �����豸��LCD���⡣
   * @param[in] icdev �豸��ʶ����
   * @param[in] cOpenFlag 0-�����⣬1-�ر��⡣
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_ctlbacklight(HANDLE icdev, unsigned char cOpenFlag);

  /**
   * @brief  ָʾ�ƿ��ơ�
   * @par    ˵����
   * �����豸��ָʾ�ơ�
   * @param[in] icdev �豸��ʶ����
   * @param[in] cLed ָʾ�Ʊ�ţ�0��ʾȫ��ָʾ�ƣ�1��ʾ��һ��ָʾ�ƣ�2��ʾ�ڶ���ָʾ�ƣ��Դ����ơ�
   * @param[in] cOpenFlag 0-������1-Ϩ��2-��˸��
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_ctlled(HANDLE icdev, unsigned char cLed, unsigned char cOpenFlag);

  /**
   * @brief  LCD������
   * @par    ˵����
   * ���LCD��Ļ����ʾ���ݡ�
   * @param[in] icdev �豸��ʶ����
   * @param[in] cLine ��Ҫ������кţ���Ŵ�1��ʼ��
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_lcdclrscrn(HANDLE icdev, unsigned char cLine);

  /**
   * @brief  ���������ģʽ��
   * @par    ˵����
   * ʹ�豸�����ȡ���̵�״̬���ӿڱ����ֱ�ӷ��أ�������ȴ�������ɻ��豸��ʱ��
   * @param[in] icdev �豸��ʶ����
   * @param[in] ctime �豸��ʱֵ����λΪ�롣
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_passin(HANDLE icdev, unsigned char ctime);

  /**
   * @brief  ���������ģʽ��
   * @par    ˵����
   * ʹ�豸�����ȡ���̵�״̬���ӿڱ����ֱ�ӷ��أ�������ȴ�������ɻ��豸��ʱ��
   * @param[in] icdev �豸��ʶ����
   * @param[in] ctime �豸��ʱֵ����λΪ�롣
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_PassIn(HANDLE icdev, unsigned char ctime);

  /**
   * @brief  ���������ģʽ��
   * @par    ˵����
   * ʹ�豸�����ȡ���̵�״̬���ӿڱ����ֱ�ӷ��أ�������ȴ�������ɻ��豸��ʱ��
   * @param[in] icdev �豸��ʶ����
   * @param[in] ctime �豸��ʱֵ����λΪ�롣
   * @param[in] ucmode ģʽ��0-�����ţ�1-�������š�
   * @param[in] cardno �����ַ�����ֻ���ڴ����ŵ�ģʽ��
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_passin2(HANDLE icdev, unsigned char ctime, unsigned char ucmode, unsigned char *cardno);

  /**
   * @brief  ���������ģʽ��
   * @par    ˵����
   * ʹ�豸�����ȡ���̵�״̬���ӿڱ����ֱ�ӷ��أ�������ȴ�������ɻ��豸��ʱ��
   * @param[in] icdev �豸��ʶ����
   * @param[in] ctime �豸��ʱֵ����λΪ�롣
   * @param[in] ucmode ģʽ��0-�����ţ�1-�������š�
   * @param[in] cardno �����ַ�����ֻ���ڴ����ŵ�ģʽ��
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_PassIn2(HANDLE icdev, unsigned char ctime, unsigned char ucmode, unsigned char *cardno);

  /**
   * @brief  ��ȡ�������ݡ�
   * @par    ˵����
   * ��ȡ�豸�Ѿ���ȡ���ļ������ݡ�
   * @param[in] icdev �豸��ʶ����
   * @param[out] rlen ���ذ������ݵĳ��ȣ�����'\0'��
   * @param[out] cpass ���صİ������ݣ����ݸ�ʽΪ'\0'��β���ַ�����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_passget(HANDLE icdev, unsigned char *rlen, unsigned char *cpass);

  /**
   * @brief  ��ȡ�������ݡ�
   * @par    ˵����
   * ��ȡ�豸�Ѿ���ȡ���ļ������ݡ�
   * @param[in] icdev �豸��ʶ����
   * @param[out] rlen ���ذ������ݵĳ��ȣ�����'\0'��
   * @param[out] cpass ���صİ������ݣ����ݸ�ʽΪ'\0'��β���ַ�����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_PassGet(HANDLE icdev, unsigned char *rlen, unsigned char *cpass);

  /**
   * @brief  �˳�������ģʽ��
   * @par    ˵����
   * ���豸���������ģʽ���豸��һֱ���ڽ��ռ��������״̬����ʱֻ�а�����ɡ��豸��ʱ����ô˽ӿڲ���ʹ���豸�˳�����״̬��
   * @param[in] icdev �豸��ʶ����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_passcancel(HANDLE icdev);

  /**
   * @brief  �˳�������ģʽ��
   * @par    ˵����
   * ���豸���������ģʽ���豸��һֱ���ڽ��ռ��������״̬����ʱ��ֻ�а�����ɡ��豸��ʱ����ô˽ӿڲ���ʹ���豸�˳�����״̬��
   * @param[in] icdev �豸��ʶ����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_PassCancel(HANDLE icdev);

  /**
   * @brief  ��ȡ�������롣
   * @par    ˵����
   * ��ȡ���̰�����ͬʱ��������ʱ��Ļ��ʾ����Ϣ��
   * @param[in] icdev �豸��ʶ����
   * @param[in] disptype ��ʾ���ͣ����������豸������ʾ��Ŀ��ء�
   * @param[in] line �кţ���Ϣ������ʾ�ڴ��к�ָ�������С�
   * @param[in] ctime �豸��ʱֵ����λΪ�롣
   * @param[out] rlen ���ذ������ݵĳ��ȣ�����'\0'��
   * @param[out] ckeydata ���صİ������ݣ����ݸ�ʽΪ'\0'��β���ַ�����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_getinputkey(HANDLE icdev, unsigned char disptype, unsigned char line, unsigned char ctime, unsigned char *rlen, unsigned char *ckeydata);

  /**
   * @brief  ������
   */
  short USER_API dc_displcd_ext(HANDLE icdev, unsigned char flag, unsigned char row, unsigned char offset);

  /**
   * @brief  ����������
   * @par    ˵����
   * ��ȡ�����������ݣ�֧��1��2��3�����
   * @param[in] icdev �豸��ʶ����
   * @param[in] ctime �豸��ʱֵ����λΪ�롣
   * @param[out] pTrack1Data ���ص�1������ݣ����ݸ�ʽΪ'\0'��β���ַ�����
   * @param[out] pTrack1Len ����1������ݵĳ��ȣ�����'\0'��
   * @param[out] pTrack2Data ���ص�2������ݣ����ݸ�ʽΪ'\0'��β���ַ�����
   * @param[out] pTrack2Len ����2������ݵĳ��ȣ�����'\0'��
   * @param[out] pTrack3Data ���ص�3������ݣ����ݸ�ʽΪ'\0'��β���ַ�����
   * @param[out] pTrack3Len ����3������ݵĳ��ȣ�����'\0'��
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_readmagcardall(HANDLE icdev, unsigned char ctime, unsigned char *pTrack1Data, unsigned int *pTrack1Len, unsigned char *pTrack2Data, unsigned int *pTrack2Len, unsigned char *pTrack3Data, unsigned int *pTrack3Len);

  /**
   * @brief  ��ȡ�豸���кš�
   * @par    ˵����
   * ��ȡ�豸�ڲ����Ƶ����кţ��豸Ĭ�����к�Ϊ�գ�ֻ��Ԥ�ȶ��Ƶ��豸�Ż���ڿ��õ����кš�
   * @param[in] icdev �豸��ʶ����
   * @param[out] snr ���ص����к��ַ����������ٷ���33���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_readdevsnr(HANDLE icdev, unsigned char *snr);

  /**
   * @brief  ��ȡ�豸���кš�
   * @par    ˵����
   * ��ȡ�豸�ڲ����Ƶ����кţ��豸Ĭ�����к�Ϊ�գ�ֻ��Ԥ�ȶ��Ƶ��豸�Ż���ڿ��õ����кš�
   * @param[in] icdev �豸��ʶ����
   * @param[out] snr ���ص����к��ַ����������ٷ���17���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_readreadersnr(HANDLE icdev, unsigned char *snr);

  /**
   * @brief  ��λ�豸��
   * @par    ˵����
   * ʹ�豸�����ϵ��ʼ״̬��
   * @param[in] icdev �豸��ʶ����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_resetdevice(HANDLE icdev);

  /**
   * @brief  ���ô����豸ͨѶ�����ʡ�
   * @par    ˵����
   * ���ô����豸ͨѶ�����ʡ�
   * @param[in] icdev �豸��ʶ����
   * @param[in] baud �����ʡ�
   * @n 0x00 - 115200��
   * @n 0x01 - 57600��
   * @n 0x02 - 38400��
   * @n 0x03 - 19200��
   * @n 0x04 - 9600��
   * @n 0x05 - 4800��
   * @n 0x06 - 2400��
   * @n 0x07 - 1200��
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_setdevicebaud(HANDLE icdev, unsigned char baud);

  /**
   * @brief  ��4442����
   * @par    ˵����
   * ��ȡ4442�������ݡ�
   * @param[in] icdev �豸��ʶ����
   * @param[in] offset ƫ�ơ�
   * @param[in] length ��ȡ���ȡ�
   * @param[out] data_buffer ���ص����ݡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_read_4442(HANDLE icdev, short offset, short length, unsigned char *data_buffer);

  /**
   * @brief  ��4442����
   * @par    ˵����
   * ::dc_read_4442 ��HEX��ʽ�ӿڣ����� @a data_buffer ΪHEX��ʽ��
   */
  short USER_API dc_read_4442_hex(HANDLE icdev, short offset, short length, unsigned char *data_buffer);

  /**
   * @brief  д4442����
   * @par    ˵����
   * д�����ݵ�4442���С�
   * @param[in] icdev �豸��ʶ����
   * @param[in] offset ƫ�ơ�
   * @param[in] length д�볤�ȡ�
   * @param[in] data_buffer �������ݡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_write_4442(HANDLE icdev, short offset, short length, unsigned char *data_buffer);

  /**
   * @brief  д4442����
   * @par    ˵����
   * ::dc_write_4442 ��HEX��ʽ�ӿڣ����� @a data_buffer ΪHEX��ʽ��
   */
  short USER_API dc_write_4442_hex(HANDLE icdev, short offset, short length, unsigned char *data_buffer);

  /**
   * @brief  ��֤4442�����롣
   * @par    ˵����
   * ʹ�ô������������֤4442�����롣
   * @param[in] icdev �豸��ʶ����
   * @param[in] passwd ���룬�̶�Ϊ3���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_verifypin_4442(HANDLE icdev, unsigned char *passwd);

  /**
   * @brief  ��֤4442�����롣
   * @par    ˵����
   * ::dc_verifypin_4442 ��HEX��ʽ�ӿڣ����� @a passwd ΪHEX��ʽ��
   */
  short USER_API dc_verifypin_4442_hex(HANDLE icdev, unsigned char *passwd);

  /**
   * @brief  ��4442�����롣
   * @par    ˵����
   * ��ȡ4442�������롣
   * @param[in] icdev �豸��ʶ����
   * @param[out] passwd ���룬�̶�Ϊ3���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_readpin_4442(HANDLE icdev, unsigned char *passwd);

  /**
   * @brief  ��4442�����롣
   * @par    ˵����
   * ::dc_readpin_4442 ��HEX��ʽ�ӿڣ����� @a passwd ΪHEX��ʽ��
   */
  short USER_API dc_readpin_4442_hex(HANDLE icdev, unsigned char *passwd);

  /**
   * @brief  ��4442�����������
   * @par    ˵����
   * ��ȡ4442��������������˼���ֵ��ʾ���Գ�����֤����Ĵ�����
   * @param[in] icdev �豸��ʶ����
   * @return <0��ʾʧ�ܣ�����Ϊ�������ֵ��
   */
  short USER_API dc_readpincount_4442(HANDLE icdev);

  /**
   * @brief  �޸�4442�����롣
   * @par    ˵����
   * �޸�4442�������롣
   * @param[in] icdev �豸��ʶ����
   * @param[in] passwd ���룬�̶�Ϊ3���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_changepin_4442(HANDLE icdev, unsigned char *passwd);

  /**
   * @brief  �޸�4442�����롣
   * @par    ˵����
   * ::dc_changepin_4442 ��HEX��ʽ�ӿڣ����� @a passwd ΪHEX��ʽ��
   */
  short USER_API dc_changepin_4442_hex(HANDLE icdev, unsigned char *passwd);

  /**
   * @brief  ��4442������λ��
   * @par    ˵����
   * ��ȡ4442���ı���������Щλ���Ѿ����ñ�����
   * @param[in] icdev �豸��ʶ����
   * @param[in] offset ƫ�ơ�
   * @param[in] length ��ȡ���ȡ�
   * @param[out] data_buffer ���ص����ݣ������к���0x00�ֽڵ�λ�ñ�ʾ�Ѿ����ñ�����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_readwrotect_4442(HANDLE icdev, short offset, short length, unsigned char *data_buffer);

  /**
   * @brief  ��4442������λ��
   * @par    ˵����
   * ::dc_readwrotect_4442 ��HEX��ʽ�ӿڣ����� @a data_buffer ΪHEX��ʽ��
   */
  short USER_API dc_readwrotect_4442_hex(HANDLE icdev, short offset, short length, unsigned char *data_buffer);

  /**
   * @brief  ��4442������λ��
   * @par    ˵����
   * ��ȡ4442���ı���������Щλ���Ѿ����ñ�����
   * @param[in] icdev �豸��ʶ����
   * @param[in] offset ƫ�ơ�
   * @param[in] length ��ȡ���ȡ�
   * @param[out] data_buffer ���ص����ݣ������к���0x00�ֽڵ�λ�ñ�ʾ�Ѿ����ñ�����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_readprotect_4442(HANDLE icdev, short offset, short length, unsigned char *data_buffer);

  /**
   * @brief  ��4442������λ��
   * @par    ˵����
   * ::dc_readprotect_4442 ��HEX��ʽ�ӿڣ����� @a data_buffer ΪHEX��ʽ��
   */
  short USER_API dc_readprotect_4442_hex(HANDLE icdev, short offset, short length, unsigned char *data_buffer);

  /**
   * @brief  д4442������λ��
   * @par    ˵����
   * ��4442���ı�������ָ��λ�ý����ñ�����
   * @param[in] icdev �豸��ʶ����
   * @param[in] offset ƫ�ơ�
   * @param[in] length д�볤�ȡ�
   * @param[in] data_buffer �������ݣ������кͿ���ԭ��������ͬ���ֽ�λ�ý����ñ�����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_writeprotect_4442(HANDLE icdev, short offset, short length, unsigned char *data_buffer);

  /**
   * @brief  д4442������λ��
   * @par    ˵����
   * ::dc_writeprotect_4442 ��HEX��ʽ�ӿڣ����� @a data_buffer ΪHEX��ʽ��
   */
  short USER_API dc_writeprotect_4442_hex(HANDLE icdev, short offset, short length, unsigned char *data_buffer);

  /**
   * @brief  д24Cϵ�п���
   * @par    ˵����
   * д�����ݵ�24Cϵ�п��У�֧��24C01��24C02��24C04��24C08��24C16����
   * @param[in] icdev �豸��ʶ����
   * @param[in] offset ƫ�ơ�
   * @param[in] length д�볤�ȡ�
   * @param[in] snd_buffer �������ݡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_write_24c(HANDLE icdev, short offset, short length, unsigned char *snd_buffer);

  /**
   * @brief  д24Cϵ�п���
   * @par    ˵����
   * ::dc_write_24c ��HEX��ʽ�ӿڣ����� @a snd_buffer ΪHEX��ʽ��
   */
  short USER_API dc_write_24c_hex(HANDLE icdev, short offset, short length, unsigned char *snd_buffer);

  /**
   * @brief  д24C64ϵ�п���
   * @par    ˵����
   * д�����ݵ�24C64ϵ�п��У�֧��24C64��24C512��24C1024����
   * @param[in] icdev �豸��ʶ����
   * @param[in] offset ƫ�ơ�
   * @param[in] length д�볤�ȡ�
   * @param[in] snd_buffer �������ݡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_write_24c64(HANDLE icdev, short offset, short length, unsigned char *snd_buffer);

  /**
   * @brief  д24C64ϵ�п���
   * @par    ˵����
   * ::dc_write_24c64 ��HEX��ʽ�ӿڣ����� @a snd_buffer ΪHEX��ʽ��
   */
  short USER_API dc_write_24c64_hex(HANDLE icdev, short offset, short length, unsigned char *snd_buffer);

  /**
   * @brief  ��24Cϵ�п���
   * @par    ˵����
   * ��ȡ24Cϵ�п������ݣ�֧��24C01��24C02��24C04��24C08��24C16����
   * @param[in] icdev �豸��ʶ����
   * @param[in] offset ƫ�ơ�
   * @param[in] length ��ȡ���ȡ�
   * @param[out] receive_buffer ���ص����ݡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_read_24c(HANDLE icdev, short offset, short length, unsigned char *receive_buffer);

  /**
   * @brief  ��24Cϵ�п���
   * @par    ˵����
   * ::dc_read_24c ��HEX��ʽ�ӿڣ����� @a receive_buffer ΪHEX��ʽ��
   */
  short USER_API dc_read_24c_hex(HANDLE icdev, short offset, short length, unsigned char *receive_buffer);

  /**
   * @brief  ��24C64ϵ�п���
   * @par    ˵����
   * ��ȡ24C64ϵ�п������ݣ�֧��24C64��24C512��24C1024����
   * @param[in] icdev �豸��ʶ����
   * @param[in] offset ƫ�ơ�
   * @param[in] length ��ȡ���ȡ�
   * @param[out] receive_buffer ���ص����ݡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_read_24c64(HANDLE icdev, short offset, short length, unsigned char *receive_buffer);

  /**
   * @brief  ��24C64ϵ�п���
   * @par    ˵����
   * ::dc_read_24c64 ��HEX��ʽ�ӿڣ����� @a receive_buffer ΪHEX��ʽ��
   */
  short USER_API dc_read_24c64_hex(HANDLE icdev, short offset, short length, unsigned char *receive_buffer);

  /**
   * @brief  ��4428����
   * @par    ˵����
   * ��ȡ4428�������ݡ�
   * @param[in] icdev �豸��ʶ����
   * @param[in] offset ƫ�ơ�
   * @param[in] length ��ȡ���ȡ�
   * @param[out] data_buffer ���ص����ݡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_read_4428(HANDLE icdev, short offset, short length, unsigned char *data_buffer);

  /**
   * @brief  ��4428����
   * @par    ˵����
   * ::dc_read_4428 ��HEX��ʽ�ӿڣ����� @a data_buffer ΪHEX��ʽ��
   */
  short USER_API dc_read_4428_hex(HANDLE icdev, short offset, short length, unsigned char *data_buffer);

  /**
   * @brief  д4428����
   * @par    ˵����
   * д�����ݵ�4428���С�
   * @param[in] icdev �豸��ʶ����
   * @param[in] offset ƫ�ơ�
   * @param[in] length д�볤�ȡ�
   * @param[in] data_buffer �������ݡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_write_4428(HANDLE icdev, short offset, short length, unsigned char *data_buffer);

  /**
   * @brief  д4428����
   * @par    ˵����
   * ::dc_write_4428 ��HEX��ʽ�ӿڣ����� @a data_buffer ΪHEX��ʽ��
   */
  short USER_API dc_write_4428_hex(HANDLE icdev, short offset, short length, unsigned char *data_buffer);

  /**
   * @brief  ��֤4428�����롣
   * @par    ˵����
   * ʹ�ô������������֤4428�����롣
   * @param[in] icdev �豸��ʶ����
   * @param[in] passwd ���룬�̶�Ϊ2���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_verifypin_4428(HANDLE icdev, unsigned char *passwd);

  /**
   * @brief  ��֤4428�����롣
   * @par    ˵����
   * ::dc_verifypin_4428 ��HEX��ʽ�ӿڣ����� @a passwd ΪHEX��ʽ��
   */
  short USER_API dc_verifypin_4428_hex(HANDLE icdev, unsigned char *passwd);

  /**
   * @brief  ��4428�����롣
   * @par    ˵����
   * ��ȡ4428�������롣
   * @param[in] icdev �豸��ʶ����
   * @param[out] passwd ���룬�̶�Ϊ2���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_readpin_4428(HANDLE icdev, unsigned char *passwd);

  /**
   * @brief  ��4428�����롣
   * @par    ˵����
   * ::dc_readpin_4428 ��HEX��ʽ�ӿڣ����� @a passwd ΪHEX��ʽ��
   */
  short USER_API dc_readpin_4428_hex(HANDLE icdev, unsigned char *passwd);

  /**
   * @brief  ��4428�����������
   * @par    ˵����
   * ��ȡ4428��������������˼���ֵ��ʾ���Գ�����֤����Ĵ�����
   * @param[in] icdev �豸��ʶ����
   * @return <0��ʾʧ�ܣ�����Ϊ�������ֵ��
   */
  short USER_API dc_readpincount_4428(HANDLE icdev);

  /**
   * @brief  �޸�4428�����롣
   * @par    ˵����
   * �޸�4428�������롣
   * @param[in] icdev �豸��ʶ����
   * @param[in] passwd ���룬�̶�Ϊ2���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_changepin_4428(HANDLE icdev, unsigned char *passwd);

  /**
   * @brief  �޸�4428�����롣
   * @par    ˵����
   * ::dc_changepin_4428 ��HEX��ʽ�ӿڣ����� @a passwd ΪHEX��ʽ��
   */
  short USER_API dc_changepin_4428_hex(HANDLE icdev, unsigned char *passwd);

  /**
   * @brief  ��4428������λ��
   * @par    ˵����
   * ��ȡ4428���ı���������Щλ���Ѿ����ñ�����
   * @param[in] icdev �豸��ʶ����
   * @param[in] offset ƫ�ơ�
   * @param[in] length ��ȡ���ȡ�
   * @param[out] data_buffer ���ص����ݣ������к���0x00�ֽڵ�λ�ñ�ʾ�Ѿ����ñ�����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_readprotect_4428(HANDLE icdev, short offset, short length, unsigned char *data_buffer);

  /**
   * @brief  ��4428������λ��
   * @par    ˵����
   * ::dc_readprotect_4428 ��HEX��ʽ�ӿڣ����� @a data_buffer ΪHEX��ʽ��
   */
  short USER_API dc_readprotect_4428_hex(HANDLE icdev, short offset, short length, unsigned char *data_buffer);

  /**
   * @brief  д4428������λ��
   * @par    ˵����
   * ��4428���ı�������ָ��λ�ý����ñ�����
   * @param[in] icdev �豸��ʶ����
   * @param[in] offset ƫ�ơ�
   * @param[in] length д�볤�ȡ�
   * @param[in] data_buffer �������ݣ������кͿ���ԭ��������ͬ���ֽ�λ�ý����ñ�����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_writeprotect_4428(HANDLE icdev, short offset, short length, unsigned char *data_buffer);

  /**
   * @brief  д4428������λ��
   * @par    ˵����
   * ::dc_writeprotect_4428 ��HEX��ʽ�ӿڣ����� @a data_buffer ΪHEX��ʽ��
   */
  short USER_API dc_writeprotect_4428_hex(HANDLE icdev, short offset, short length, unsigned char *data_buffer);

  /**
   * @brief  ���4442����
   * @par    ˵����
   * ��⵱ǰ�������Ƿ����4442����
   * @param[in] icdev �豸��ʶ����
   * @return <0��ʾʧ�ܻ򲻴��ڣ�==0��ʾ���ڡ�
   */
  short USER_API dc_Check_4442(HANDLE icdev);

  /**
   * @brief  ���4428����
   * @par    ˵����
   * ��⵱ǰ�������Ƿ����4428����
   * @param[in] icdev �豸��ʶ����
   * @return <0��ʾʧ�ܻ򲻴��ڣ�==0��ʾ���ڡ�
   */
  short USER_API dc_Check_4428(HANDLE icdev);

  /**
   * @brief  ���24C01����
   * @par    ˵����
   * ��⵱ǰ�������Ƿ����24C01����
   * @param[in] icdev �豸��ʶ����
   * @return <0��ʾʧ�ܻ򲻴��ڣ�==0��ʾ���ڡ�
   */
  short USER_API dc_Check_24C01(HANDLE icdev);

  /**
   * @brief  ���24C02����
   * @par    ˵����
   * ��⵱ǰ�������Ƿ����24C02����
   * @param[in] icdev �豸��ʶ����
   * @return <0��ʾʧ�ܻ򲻴��ڣ�==0��ʾ���ڡ�
   */
  short USER_API dc_Check_24C02(HANDLE icdev);

  /**
   * @brief  ���24C04����
   * @par    ˵����
   * ��⵱ǰ�������Ƿ����24C04����
   * @param[in] icdev �豸��ʶ����
   * @return <0��ʾʧ�ܻ򲻴��ڣ�==0��ʾ���ڡ�
   */
  short USER_API dc_Check_24C04(HANDLE icdev);

  /**
   * @brief  ���24C08����
   * @par    ˵����
   * ��⵱ǰ�������Ƿ����24C08����
   * @param[in] icdev �豸��ʶ����
   * @return <0��ʾʧ�ܻ򲻴��ڣ�==0��ʾ���ڡ�
   */
  short USER_API dc_Check_24C08(HANDLE icdev);

  /**
   * @brief  ���24C16����
   * @par    ˵����
   * ��⵱ǰ�������Ƿ����24C16����
   * @param[in] icdev �豸��ʶ����
   * @return <0��ʾʧ�ܻ򲻴��ڣ�==0��ʾ���ڡ�
   */
  short USER_API dc_Check_24C16(HANDLE icdev);

  /**
   * @brief  ���24C64����
   * @par    ˵����
   * ��⵱ǰ�������Ƿ����24C64����
   * @param[in] icdev �豸��ʶ����
   * @return <0��ʾʧ�ܻ򲻴��ڣ�==0��ʾ���ڡ�
   */
  short USER_API dc_Check_24C64(HANDLE icdev);

  /**
   * @brief  ���CPU����
   * @par    ˵����
   * ��⵱ǰ�������Ƿ����CPU����
   * @param[in] icdev �豸��ʶ����
   * @return <0��ʾʧ�ܻ򲻴��ڣ�==0��ʾ����T=0��CPU����==1��ʾ����T=1��CPU����
   */
  short USER_API dc_Check_CPU(HANDLE icdev);

  /**
   * @brief  ��⿨��
   * @par    ˵����
   * ��⵱ǰ�����д��ڵĿ����͡�
   * @param[in] icdev �豸��ʶ����
   * @return <0��ʾʧ�ܻ򲻴��ڡ�
   * @n 8 - ��ʾ����4442����
   * @n 9 - ��ʾ����4428����
   * @n 30 - ��ʾ����T=0��CPU����
   * @n 31 - ��ʾ����T=1��CPU����
   * @n 21 - ��ʾ����24C01����
   * @n 22 - ��ʾ����24C02����
   * @n 23 - ��ʾ����24C04����
   * @n 24 - ��ʾ����24C08����
   * @n 25 - ��ʾ����24C16����
   * @n 26 - ��ʾ����24C64����
   */
  short USER_API dc_CheckCard(HANDLE icdev);

  /**
   * @brief  ������
   */
  short USER_API dc_getrcinfo(HANDLE icdev, unsigned char *info);

  /**
   * @brief  ������
   */
  short USER_API dc_getrcinfo_hex(HANDLE icdev, unsigned char *info);

  /**
   * @brief  ��ȡ�豸���汾��
   * @par    ˵����
   * ��ȡ�豸�ڲ��̼�����ĳ��汾���˳��汾�����豸�ڲ��̼������ʵ�֣��п���ͬ�豸�汾һ�¡�
   * @param[in] icdev �豸��ʶ����
   * @param[out] sver ���صİ汾�ַ����������ٷ���128���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_getlongver(HANDLE icdev, unsigned char *sver);

  /**
   * @brief  Ѱ�����󡢷�����ͻ��ѡ��������
   * @par    ˵����
   * �ڲ������� ::dc_request ::dc_anticoll ::dc_select �Ĺ��ܡ�
   * @param[in] icdev �豸��ʶ����
   * @param[in] _Mode ģʽ��ͬ ::dc_request �� @a _Mode ��
   * @param[out] Strsnr ���صĿ����кţ���ʽΪ�����ַ�����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���==1��ʾ�޿����޷�Ѱ����Ƭ��
   */
  short USER_API dc_cardstr(HANDLE icdev, unsigned char _Mode, char *Strsnr);

  /**
   * @brief  ѰType A��Type B�������
   * @par    ˵����
   * ��Type A��Type B������Ѱ���ͼ��
   * @param[in] icdev �豸��ʶ����
   * @param[out] rlen ���ؼ�����Ϣ�ĳ��ȡ�
   * @param[out] rbuf ���صļ�����Ϣ�������ٷ���128���ֽڡ�
   * @param[out] type ���ͣ�'A'��ʾType A����'B'��ʾType B����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���==1��ʾ�޿����޷�Ѱ����Ƭ��
   */
  short USER_API dc_cardAB(HANDLE icdev, unsigned char *rlen, unsigned char *rbuf, unsigned char *type);

  /**
   * @brief  ѰType B�������
   * @par    ˵����
   * ��Type B������Ѱ���ͼ��
   * @param[in] icdev �豸��ʶ����
   * @param[out] rbuf ���صļ�����Ϣ�������ٷ���128���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���==1��ʾ�޿����޷�Ѱ����Ƭ��
   */
  short USER_API dc_card_b(HANDLE icdev, unsigned char *rbuf);

  /**
   * @brief  ѰType B�������
   * @par    ˵����
   * ::dc_card_b ��HEX��ʽ�ӿڣ����� @a rbuf ΪHEX��ʽ��
   */
  short USER_API dc_card_b_hex(HANDLE icdev, char *rbuf);

  /**
   * @brief  Һ����ʾ��
   * @par    ˵����
   * ��ʾָ���ַ�����Һ����Ļ�ϡ�
   * @param[in] icdev �豸��ʶ����
   * @param[in] line �кš�
   * @param[in] offset ƫ�ơ�
   * @param[in] data Ҫ��ʾ���ַ�����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_dispinfo_T8(HANDLE icdev, unsigned char line, unsigned char offset, char *data);

  /**
   * @brief  Һ����ʾ��
   * @par    ˵����
   * ��ʾָ���ַ�����Һ����Ļ�ϡ�
   * @param[in] icdev �豸��ʶ����
   * @param[in] offset ��Ļƫ�ơ�
   * @param[in] data Ҫ��ʾ���ַ�����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_dispinfo_pro_T8(HANDLE icdev, unsigned char offset, char *data);

  /**
   * @brief  LCD������
   * @par    ˵����
   * ���LCD��Ļ����ʾ���ݡ�
   * @param[in] icdev �豸��ʶ����
   * @param[in] line ��Ҫ������кţ���Ŵ�1��ʼ��
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_clearlcd_T8(HANDLE icdev, unsigned char line);

  /**
   * @brief  ָʾ�Ƶ���/Ϩ��
   * @par    ˵����
   * ����/Ϩ���豸��ָʾ�ơ�
   * @param[in] icdev �豸��ʶ����
   * @param[in] cled ָʾ�Ʊ�ţ�0��ʾȫ��ָʾ�ƣ�1��ʾ��һ��ָʾ�ƣ�2��ʾ�ڶ���ָʾ�ƣ��Դ����ơ�
   * @param[in] cflag 0-������1-Ϩ��
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_led_T8(HANDLE icdev, unsigned char cled, unsigned char cflag);

  /**
   * @brief  ������
   */
  short USER_API dc_dispmap_T8(HANDLE icdev, unsigned char *mapdata);

  /**
   * @brief  ������
   */
  short USER_API dc_displow_T8(HANDLE icdev, unsigned char rs, unsigned char cdata);

  /**
   * @brief  ��/д��Ƶ�Ĵ�����
   * @par    ˵����
   * ����Ƶ�Ĵ�����ȡֵ��д��ֵ����Ƶ�Ĵ����С�
   * @param[in] icdev �豸��ʶ����
   * @param[in] flag ��д��ǣ�0x00��ʾ����0x01��ʾд��
   * @param[in] _Adr �Ĵ�����ַ��
   * @param[in,out] _Data �Ĵ���ֵ���̶�Ϊ1���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_rw_rfreg(HANDLE icdev, unsigned char flag, unsigned char _Adr, unsigned char *_Data);

  /**
   * @brief  ��/д��Ƶ�Ĵ�����
   * @par    ˵����
   * ::dc_rw_rfreg ��HEX��ʽ�ӿڣ����� @a _Data ΪHEX��ʽ��
   */
  short USER_API dc_rw_rfreg_hex(HANDLE icdev, unsigned char flag, unsigned char _Adr, unsigned char *_Data);

  /**
   * @brief  ������
   */
  short USER_API dc_mulrequest_b(HANDLE icdev, unsigned char _Mode, unsigned char AFI, unsigned char *cardnum, unsigned char *mulATQB);

  /**
   * @brief  ������
   */
  short USER_API dc_hltb(HANDLE icdev, unsigned char *PUPI);

  /**
   * @brief  ������
   */
  short USER_API dc_set_poweroff(HANDLE icdev, unsigned int MsTimes, unsigned char TimerClock, unsigned char TimerReload);

  /**
   * @brief  �ǽӴ�ʽCPU��ָ�����
   * @par    ˵����
   * �Ը�Ӧ��CPU������ָ���������ע��˽ӿڲ���װ��Э�鲿�֣���CRC��
   * @param[in] icdev �豸��ʶ����
   * @param[in] slen �������ݵĳ��ȡ�
   * @param[in] sendbuffer �������ݡ�
   * @param[out] rlen �������ݵĳ��ȡ�
   * @param[out] databuffer ���ص����ݡ�
   * @param[in] timeout ��ʱֵ����ֵֻ�ڲ����豸�ĵײ�ʹ�ã���λΪ250���룬һ����ý���ֵΪ7��
   * @param[in] CRCSTU CRCֵ��
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_pro_commandsourceCRC(HANDLE icdev, unsigned char slen, unsigned char *sendbuffer, unsigned char *rlen, unsigned char *databuffer, unsigned char timeout, unsigned char CRCSTU);

  /**
   * @brief  �ǽӴ�ʽCPU��ָ�����
   * @par    ˵����
   * ::dc_pro_commandsourceCRC ��HEX��ʽ�ӿڣ����� @a sendbuffer @a databuffer ΪHEX��ʽ��
   */
  short USER_API dc_pro_commandsourceCRChex(HANDLE icdev, unsigned char slen, char *sendbuffer, unsigned char *rlen, char *databuffer, unsigned char timeout, unsigned char CRCSTU);

  /**
   * @brief  Mifare Plus�����ø��˻����ݣ�0������
   * @par    ˵����
   * ����Mifare Plus���ĸ��˻����ݡ�
   * @param[in] icdev �豸��ʶ����
   * @param[in] BNr Ҫд��ĸ��˻����ݿ�š�
   * @param[in] dataperso Ҫд������ݣ��̶�Ϊ16���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_MFPL0_writeperso(HANDLE icdev, unsigned int BNr, unsigned char *dataperso);

  /**
   * @brief  Mifare Plus�����ø��˻����ݣ�0������
   * @par    ˵����
   * ::dc_MFPL0_writeperso ��HEX��ʽ�ӿڣ����� @a dataperso ΪHEX��ʽ��
   */
  short USER_API dc_MFPL0_writeperso_hex(HANDLE icdev, unsigned int BNr, unsigned char *dataperso);

  /**
   * @brief  Mifare Plus���ύ���˻����ݣ�0������
   * @par    ˵����
   * �ύMifare Plus���ĸ��˻����ݣ��ύ�ɹ���Ƭ����1��״̬��
   * @param[in] icdev �豸��ʶ����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_MFPL0_commitperso(HANDLE icdev);

  /**
   * @brief  ��֤Mifare Plus��״̬���루1������
   * @par    ˵����
   * ��֤Mifare Plus��״̬���룬������1��״̬��ʵ���ϸ����֤��
   * @param[in] icdev �豸��ʶ����
   * @param[in] authkey ��֤���룬�̶�Ϊ16���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_MFPL1_authl1key(HANDLE icdev, unsigned char *authkey);

  /**
   * @brief  ��֤Mifare Plus��״̬���루1������
   * @par    ˵����
   * ::dc_MFPL1_authl1key ��HEX��ʽ�ӿڣ����� @a authkey ΪHEX��ʽ��
   */
  short USER_API dc_MFPL1_authl1key_hex(HANDLE icdev, unsigned char *authkey);

  /**
   * @brief  ����Mifare Plus��״̬��2����1������
   * @par    ˵����
   * ״̬�л�������ִ�иò�����1��״̬�Ŀ�Ƭת����2����
   * @param[in] icdev �豸��ʶ����
   * @param[in] authkey �������룬�̶�Ϊ16���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_MFPL1_switchtol2(HANDLE icdev, unsigned char *authkey);

  /**
   * @brief  ����Mifare Plus��״̬��3����1������
   * @par    ˵����
   * ״̬�л�������ִ�иò�����1��״̬�Ŀ�Ƭת����3����
   * @param[in] icdev �豸��ʶ����
   * @param[in] authkey �������룬�̶�Ϊ16���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_MFPL1_switchtol3(HANDLE icdev, unsigned char *authkey);

  /**
   * @brief  ����Mifare Plus��״̬��3����2������
   * @par    ˵����
   * ״̬�л�������ִ�иò�����2��״̬�Ŀ�Ƭת����3����
   * @param[in] icdev �豸��ʶ����
   * @param[in] authkey �������룬�̶�Ϊ16���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_MFPL2_switchtol3(HANDLE icdev, unsigned char *authkey);

  /**
   * @brief  ��֤Mifare Plus��״̬���루3������
   * @par    ˵����
   * ִ��3��״̬��Ƭ��֤�����������ŵĲ�ͬ����֤��ͬ�����롣
   * @param[in] icdev �豸��ʶ����
   * @param[in] keyBNr �����š�
   * @param[in] authkey ��֤���룬�̶�Ϊ16���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_MFPL3_authl3key(HANDLE icdev, unsigned int keyBNr, unsigned char *authkey);

  /**
   * @brief  ��֤Mifare Plus��״̬���루3������
   * @par    ˵����
   * ::dc_MFPL3_authl3key ��HEX��ʽ�ӿڣ����� @a authkey ΪHEX��ʽ��
   */
  short USER_API dc_MFPL3_authl3key_hex(HANDLE icdev, unsigned int keyBNr, unsigned char *authkey);

  /**
   * @brief  ��֤Mifare Plus��״̬���루3������
   * @par    ˵����
   * ִ��3��״̬��Ƭ��֤���������������ŵĲ�ͬ����֤��ͬ�����롣
   * @param[in] icdev �豸��ʶ����
   * @param[in] mode ģʽ��0x00��ʾ��֤A���룬�ڲ���0x4000+sectorBNr*2��������飬0x04��ʾ��֤B���룬�ڲ���0x4000+sectorBNr*2+1��������顣
   * @param[in] sectorBNr ���������š�
   * @param[in] authkey ��֤���룬�̶�Ϊ16���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_MFPL3_authl3sectorkey(HANDLE icdev, unsigned char mode, unsigned int sectorBNr, unsigned char *authkey);

  /**
   * @brief  ��֤Mifare Plus��״̬���루3������
   * @par    ˵����
   * ::dc_MFPL3_authl3key ��HEX��ʽ�ӿڣ����� @a authkey ΪHEX��ʽ��
   */
  short USER_API dc_MFPL3_authl3sectorkey_hex(HANDLE icdev, unsigned char mode, unsigned int sectorBNr, unsigned char *authkey);

  /**
   * @brief  ��Mifare Plus�����ݣ�3������
   * @par    ˵����
   * ��3��״̬�¶�ȡMifare Plus�����ݣ�������������飬ÿ��16�ֽڡ�
   * @param[in] icdev �豸��ʶ����
   * @param[in] BNr ��ʼ���ַ��
   * @param[in] Numblock ����Ŀ��һ�㲻����6�顣
   * @param[out] readdata ���ص����ݡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_MFPL3_readinplain(HANDLE icdev, unsigned int BNr, unsigned char Numblock, unsigned char *readdata);

  /**
   * @brief  ��Mifare Plus�����ݣ�3������
   * @par    ˵����
   * ::dc_MFPL3_readinplain ��HEX��ʽ�ӿڣ����� @a readdata ΪHEX��ʽ��
   */
  short USER_API dc_MFPL3_readinplain_hex(HANDLE icdev, unsigned int BNr, unsigned char Numblock, unsigned char *readdata);

  /**
   * @brief  ����ģʽ��Mifare Plus�����ݣ�3������
   * @par    ˵����
   * ��3��״̬���ü���ģʽ��ȡMifare Plus�����ݣ�������������飬ÿ��16�ֽڡ�
   * @param[in] icdev �豸��ʶ����
   * @param[in] BNr ��ʼ���ַ��
   * @param[in] Numblock ����Ŀ��һ�㲻����6�顣
   * @param[out] readdata ���ص����ݡ�
   * @param[in] flag ��ǣ�0x00��ʾ���������ڲ����ܺ��ٷ��أ�0x01��ʾ��������ֱ�ӷ��ء�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_MFPL3_readencrypted(HANDLE icdev, unsigned int BNr, unsigned char Numblock, unsigned char *readdata, unsigned char flag);

  /**
   * @brief  ����ģʽ��Mifare Plus�����ݣ�3������
   * @par    ˵����
   * ::dc_MFPL3_readencrypted ��HEX��ʽ�ӿڣ����� @a readdata ΪHEX��ʽ��
   */
  short USER_API dc_MFPL3_readencrypted_hex(HANDLE icdev, unsigned int BNr, unsigned char Numblock, unsigned char *readdata, unsigned char flag);

  /**
   * @brief  дMifare Plus�����ݣ�3������
   * @par    ˵����
   * ��3��״̬��д�����ݵ�Mifare Plus���У���������д��飬ÿ��16�ֽڡ�
   * @param[in] icdev �豸��ʶ����
   * @param[in] BNr ��ʼ���ַ��
   * @param[in] Numblock ����Ŀ��һ�㲻����6�顣
   * @param[in] writedata �������ݡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_MFPL3_writeinplain(HANDLE icdev, unsigned int BNr, unsigned char Numblock, unsigned char *writedata);

  /**
   * @brief  дMifare Plus�����ݣ�3������
   * @par    ˵����
   * ::dc_MFPL3_writeinplain ��HEX��ʽ�ӿڣ����� @a writedata ΪHEX��ʽ��
   */
  short USER_API dc_MFPL3_writeinplain_hex(HANDLE icdev, unsigned int BNr, unsigned char Numblock, unsigned char *writedata);

  /**
   * @brief  ����ģʽдMifare Plus�����ݣ�3������
   * @par    ˵����
   * ��3��״̬���ü���ģʽд�����ݵ�Mifare Plus���У���������д��飬ÿ��16�ֽڡ�ע�⣺д����ʱ������ʹ�ô˺������ҿ���Ŀֻ��Ϊ1��
   * @param[in] icdev �豸��ʶ����
   * @param[in] BNr ��ʼ���ַ��
   * @param[in] Numblock ����Ŀ��һ�㲻����6�顣
   * @param[in] writedata �������ݡ�
   * @param[in] flag ��ǣ�0x00��ʾ�����������ڲ����ܺ���ʹ�ã�0x01��ʾ��������ֱ��ʹ�á�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_MFPL3_writeencrypted(HANDLE icdev, unsigned int BNr, unsigned char Numblock, unsigned char *writedata, unsigned char flag);

  /**
   * @brief  ����ģʽдMifare Plus�����ݣ�3������
   * @par    ˵����
   * ::dc_MFPL3_writeencrypted ��HEX��ʽ�ӿڣ����� @a writedata ΪHEX��ʽ��
   */
  short USER_API dc_MFPL3_writeencrypted_hex(HANDLE icdev, unsigned int BNr, unsigned char Numblock, unsigned char *writedata, unsigned char flag);

  /**
   * @brief  ��֤Mifare Ultralight C�����롣
   * @par    ˵����
   * ʹ�ô������������֤Mifare Ultralight C�����롣
   * @param[in] icdev �豸��ʶ����
   * @param[in] key ���룬�̶�Ϊ16���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_auth_ulc(HANDLE icdev, unsigned char *key);

  /**
   * @brief  ��֤Mifare Ultralight C�����롣
   * @par    ˵����
   * ::dc_auth_ulc ��HEX��ʽ�ӿڣ����� @a key ΪHEX��ʽ��
   */
  short USER_API dc_auth_ulc_hex(HANDLE icdev, unsigned char *key);

  /**
   * @brief  �޸�Mifare Ultralight C�����롣
   * @par    ˵����
   * �޸�Mifare Ultralight C�������롣
   * @param[in] icdev �豸��ʶ����
   * @param[in] newkey ���룬�̶�Ϊ16���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_changekey_ulc(HANDLE icdev, unsigned char *newkey);

  /**
   * @brief  �޸�Mifare Ultralight C�����롣
   * @par    ˵����
   * ::dc_changekey_ulc ��HEX��ʽ�ӿڣ����� @a newkey ΪHEX��ʽ��
   */
  short USER_API dc_changekey_ulc_hex(HANDLE icdev, unsigned char *newkey);

  /**
   * @brief  ��ȡ�Ӵ�ʽCPU��������
   * @par    ˵����
   * �˽ӿڿɻ�ȡ�Ӵ�ʽCPU��������Ϊ�Ĳ�����
   * @param[in] icdev �豸��ʶ����
   * @param[in] cputype ������ţ�ͬ ::dc_setcpu �� @a _Byte ��
   * @param[out] cpupro ��Э���ţ�0x00��ʾT0��0x01��ʾT1��Ĭ��Ϊ0x00��
   * @param[out] cpuetu ����λ�����ʱ�ţ�0x5C��ʾ9600��0x14��ʾ38400.
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_getcpupara(HANDLE icdev, unsigned char cputype, unsigned char *cpupro, unsigned char *cpuetu);

  /**
   * @brief  �Ӵ�ʽCPU��ָ�����
   * @par    ˵����
   * �Ե�ǰ����CPU������ָ���������ע��˽ӿڲ���װ��Э�鲿�֡�
   * @param[in] icdev �豸��ʶ����
   * @param[in] slen �������ݵĳ��ȡ�
   * @param[in] sendbuffer �������ݡ�
   * @param[out] rlen �������ݵĳ��ȡ�
   * @param[out] databuffer ���ص����ݡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_cpuapdusourceEXT(HANDLE icdev, short slen, unsigned char *sendbuffer, short *rlen, unsigned char *databuffer);

  /**
   * @brief  �Ӵ�ʽCPU��ָ�����
   * @par    ˵����
   * ::dc_cpuapdusourceEXT ��HEX��ʽ�ӿڣ����� @a sendbuffer @a databuffer ΪHEX��ʽ��
   */
  short USER_API dc_cpuapdusourceEXT_hex(HANDLE icdev, short slen, char *sendbuffer, short *rlen, char *databuffer);

  /**
   * @brief  �Ӵ�ʽCPU��ָ�����
   * @par    ˵����
   * �Ե�ǰ����CPU������ָ���������ע��˽ӿ��ѷ�װ��Э�鲿�֡�
   * @param[in] icdev �豸��ʶ����
   * @param[in] slen �������ݵĳ��ȡ�
   * @param[in] sendbuffer �������ݡ�
   * @param[out] rlen �������ݵĳ��ȡ�
   * @param[out] databuffer ���ص����ݡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_cpuapduEXT(HANDLE icdev, short slen, unsigned char *sendbuffer, short *rlen, unsigned char *databuffer);

  /**
   * @brief  �Ӵ�ʽCPU��ָ�����
   * @par    ˵����
   * ::dc_cpuapduEXT ��HEX��ʽ�ӿڣ����� @a sendbuffer @a databuffer ΪHEX��ʽ��
   */
  short USER_API dc_cpuapduEXT_hex(HANDLE icdev, short slen, char *sendbuffer, short *rlen, char *databuffer);

  /**
   * @brief  �Ӵ�ʽCPU��ָ�����
   * @par    ˵����
   * �Ե�ǰ����CPU������ָ���������ע��˽ӿ��ѷ�װ��Э�鲿�֡�
   * @param[in] icdev �豸��ʶ����
   * @param[in] slen �������ݵĳ��ȡ�
   * @param[in] sendbuffer �������ݡ�
   * @param[out] rlen �������ݵĳ��ȡ�
   * @param[out] databuffer ���ص����ݡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_cpuapduInt(HANDLE icdev, unsigned int slen, unsigned char *sendbuffer, unsigned int *rlen, unsigned char *databuffer);

  /**
   * @brief  �Ӵ�ʽCPU��ָ�����
   * @par    ˵����
   * ::dc_cpuapduInt ��HEX��ʽ�ӿڣ����� @a sendbuffer @a databuffer ΪHEX��ʽ��
   */
  short USER_API dc_cpuapduInt_hex(HANDLE icdev, unsigned int slen, char *sendbuffer, unsigned int *rlen, char *databuffer);

  /**
   * @brief  �ǽӴ�ʽCPU��ָ�����
   * @par    ˵����
   * �Ը�Ӧ��CPU������ָ���������ע��˽ӿ��ѷ�װ��Э�鲿�֡�
   * @param[in] icdev �豸��ʶ����
   * @param[in] slen �������ݵĳ��ȡ�
   * @param[in] sendbuffer �������ݡ�
   * @param[out] rlen �������ݵĳ��ȡ�
   * @param[out] databuffer ���ص����ݡ�
   * @param[in] timeout ��ʱֵ����ֵֻ�ڲ����豸�ĵײ�ʹ�ã���λΪ250���룬һ����ý���ֵΪ7��
   * @param[in] FG �ָ�ֵ����ֵֻ�ڲ����豸�ĵײ�ʹ�ã���λΪ�ֽڣ�һ����ý���ֵΪ64��
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_pro_commandlinkEXT(HANDLE icdev, unsigned int slen, unsigned char *sendbuffer, unsigned int *rlen, unsigned char *databuffer, unsigned char timeout, unsigned char FG);

  /**
   * @brief  �ǽӴ�ʽCPU��ָ�����
   * @par    ˵����
   * ::dc_pro_commandlinkEXT ��HEX��ʽ�ӿڣ����� @a sendbuffer @a databuffer ΪHEX��ʽ��
   */
  short USER_API dc_pro_commandlinkEXT_hex(HANDLE icdev, unsigned int slen, unsigned char *sendbuffer, unsigned int *rlen, unsigned char *databuffer, unsigned char timeout, unsigned char FG);

  /**
   * @brief  �ǽӴ�ʽCPU��ָ�����
   * @par    ˵����
   * �Ը�Ӧ��CPU������ָ���������ע��˽ӿ��ѷ�װ��Э�鲿�֡�
   * @param[in] icdev �豸��ʶ����
   * @param[in] slen �������ݵĳ��ȡ�
   * @param[in] sendbuffer �������ݡ�
   * @param[out] rlen �������ݵĳ��ȡ�
   * @param[out] databuffer ���ص����ݡ�
   * @param[in] timeout ��ʱֵ����ֵֻ�ڲ����豸�ĵײ�ʹ�ã���λΪ250���룬һ����ý���ֵΪ7��
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_pro_commandlinkInt(HANDLE icdev, unsigned int slen, unsigned char *sendbuffer, unsigned int *rlen, unsigned char *databuffer, unsigned char timeout);

  /**
   * @brief  �ǽӴ�ʽCPU��ָ�����
   * @par    ˵����
   * ::dc_pro_commandlinkInt ��HEX��ʽ�ӿڣ����� @a sendbuffer @a databuffer ΪHEX��ʽ��
   */
  short USER_API dc_pro_commandlinkInt_hex(HANDLE icdev, unsigned int slen, char *sendbuffer, unsigned int *rlen, char *databuffer, unsigned char timeout);

  /**
   * @brief  ������
   */
  short USER_API dc_exchangeblock(HANDLE icdev, unsigned char slen, unsigned char *sendbuffer, unsigned char *rlen, unsigned char *databuffer, unsigned char timeout);

  /**
   * @brief  ������
   */
  short USER_API dc_exchangeblock_hex(HANDLE icdev, unsigned char slen, unsigned char *sendbuffer, unsigned char *rlen, unsigned char *databuffer, unsigned char timeout);

  /**
   * @brief  ������
   */
  short USER_API dc_write1024(HANDLE icdev, unsigned int offset, unsigned int length, unsigned char *writebuffer);

  /**
   * @brief  ������
   */
  short USER_API dc_write1024_hex(HANDLE icdev, unsigned int offset, unsigned int length, unsigned char *writebuffer);

  /**
   * @brief  ������
   */
  short USER_API dc_read1024(HANDLE icdev, unsigned int offset, unsigned int length, unsigned char *databuffer);

  /**
   * @brief  ������
   */
  short USER_API dc_read1024_hex(HANDLE icdev, unsigned int offset, unsigned int length, unsigned char *databuffer);

  /**
   * @brief  ������
   */
  short USER_API dc_switch_linux(HANDLE icdev);

  /**
   * @brief  �Ӵ�ʽCPU����λ��
   * @par    ˵����
   * �Ե�ǰ����CPU�����и�λ�������˸�λΪ�ȸ�λ��
   * @param[in] icdev �豸��ʶ����
   * @param[out] rlen ���ظ�λ��Ϣ�ĳ��ȡ�
   * @param[out] databuffer ���صĸ�λ��Ϣ�������ٷ���128���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_cpuhotreset(HANDLE icdev, unsigned char *rlen, unsigned char *databuffer);

  /**
   * @brief  �Ӵ�ʽCPU����λ��
   * @par    ˵����
   * ::dc_cpuhotreset ��HEX��ʽ�ӿڣ����� @a databuffer ΪHEX��ʽ��
   */
  short USER_API dc_cpuhotreset_hex(HANDLE icdev, unsigned char *rlen, char *databuffer);

  /**
   * @brief  ���࿨״̬��
   * @par    ˵����
   * ����豸�д���ʲô���͵Ŀ�Ƭ��֧�ִſ����ǽӡ��Ӵ������֤��
   * @param[in] icdev �豸��ʶ����
   * @param[out] flag ״̬��ǣ��̶�Ϊ2���ֽڣ����Խ���Ϊһ���޷���������Big-Endian����ֵΪ�����г���һ�ֻ����֮�͡�
   * @n 0x0001 - ��ʾ��ˢ�ſ���
   * @n 0x0002 - ��ʾ�������ڽӴ�ʽCPU����
   * @n 0x0004 - ��ʾ�������ڽӴ�ʽδ֪����
   * @n 0x0008 - ��ʾ��Ӧ���������֤��
   * @n 0x0010 - ��ʾ��Ӧ�����ڼ���ǰ��Type A CPU����Type B CPU����
   * @n 0x0020 - ��ʾ��Ӧ�����ڼ�����Type A CPU����Type B CPU����
   * @n 0x0040 - ��ʾ��Ӧ�����ڼ���ǰ��M1����
   * @n 0x0100 - ��ʾ��Ӧ�����ڼ���ǰ�Ķ���Type A CPU����
   * @n 0x0200 - ��ʾ��Ӧ�����ڼ���ǰ�Ķ���M1����
   * @n 0x0400 - ��ʾ��Ӧ��ͬʱ���ڼ���ǰ��Type A CPU����M1����
   * @n 0x0800 - ��ʾˢ�ſ�ʧ�ܡ�
   * @n 0x1000 - ��ʾ����ˢ�ſ�ģʽ���ڹر�״̬��
   * @n 0x2000 - ��ʾ����ˢ�ſ�ģʽ���ڿ���״̬��
   * @n 0x4000 - ��ʾ��Ӧ�����֤����ǰ��״̬һ�¡�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���==1��ʾ�޿����޷�Ѱ����Ƭ��
   */
  short USER_API dc_card_exist(HANDLE icdev, unsigned char *flag);

  /**
   * @brief  ���Ӵ�ʽ�����ڡ�
   * @par    ˵����
   * ���Ӵ�ʽ��Ƭ�Ƿ�����ڵ�ǰ�����С�
   * @param[in] icdev �豸��ʶ����
   * @return <0��ʾʧ�ܣ�==0��ʾ���ڣ�==1��ʾ�����ڡ�
   */
  short USER_API dc_card_status(HANDLE icdev);

  /**
   * @brief  ���֤��Type A CPU����Type B CPU����⡣
   * @par    ˵����
   * ����Ӧ���Ƿ�������֤��Type A CPU����Type B CPU����
   * @param[in] icdev �豸��ʶ����
   * @return <0��ʾʧ�ܣ�==0��ʾ�޿���==1��ʾ�������֤��==2��ʾ����Type A CPU����==3��ʾ����Type B CPU����
   */
  short USER_API dc_typeab_card_status(HANDLE icdev);

  /**
   * @brief  Ѱ�����󡢷�����ͻ��ѡ��������
   * @par    ˵����
   * �ڲ������� ::dc_request ::dc_anticoll ::dc_select ::dc_anticoll2 ::dc_select2 �Ĺ��ܡ�
   * @param[in] icdev �豸��ʶ����
   * @param[in] _Mode ģʽ��ͬ ::dc_request �� @a _Mode ��
   * @param[out] SnrLen ���ؿ����кŵĳ��ȡ�
   * @param[out] _Snr ���صĿ����кţ������ٷ���8���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���==1��ʾ�޿����޷�Ѱ����Ƭ��
   */
  short USER_API dc_card_n(HANDLE icdev, unsigned char _Mode, unsigned int *SnrLen, unsigned char *_Snr);

  /**
   * @brief  Ѱ�����󡢷�����ͻ��ѡ��������
   * @par    ˵����
   * ::dc_card_n ��HEX��ʽ�ӿڣ����� @a _Snr ΪHEX��ʽ��
   */
  short USER_API dc_card_n_hex(HANDLE icdev, unsigned char _Mode, unsigned int *SnrLen, unsigned char *_Snr);

  /**
   * @brief  ������
   */
  short USER_API dc_card_n_number(HANDLE icdev, unsigned char _Mode, char *_Snr);

  /**
   * @brief  ��ȡ��������ֵ��
   * @par    ˵����
   * ��ȡ�豸���̵İ���ֵ��ÿ�ε��ý��ܻ�ȡ��������ֵ��
   * @param[in] icdev �豸��ʶ����
   * @param[in] timeout �豸��ʱֵ����λΪ�롣
   * @param[out] value ���صİ���ֵ�������ٷ���8���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_pass_key_value(HANDLE icdev, unsigned char timeout, char *value);

  /**
   * @brief  ����������
   * @par    ˵����
   * �����豸����������
   * @param[in] icdev �豸��ʶ����
   * @param[in] mode �����κţ�1~12����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_play_voice(HANDLE icdev, unsigned char mode);

  /**
   * @brief  ����������
   * @par    ˵����
   * �����豸����������
   * @param[in] icdev �豸��ʶ����
   * @param[in] mode �����κţ�1~12����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_playvoice(HANDLE icdev, unsigned char mode);

  /**
   * @brief  װ��������
   * @par    ˵����
   * װ���������ݵ��豸�ڡ�
   * @param[in] icdev �豸��ʶ����
   * @param[in] flag ��ǣ�0��ʾ��һ����1��ʾ�ڶ������Դ����ƣ�0xFFFF��ʾ��������
   * @param[in] slen �������ݵĳ��ȣ�����С�ڻ����1024�������Ϊ��������ʱ��Ϊ0��
   * @param[in] sdata �������ݡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_load_voice(HANDLE icdev, int flag, int slen, const unsigned char *sdata);

  /**
   * @brief  �������������á�
   * @par    ˵����
   * ���ò����������Ĳ���������������Զ������ģʽ��Ч��
   * @param[in] icdev �豸��ʶ����
   * @param[in] mode ģʽ��0x00��ʾ���������0x01��ʾ�Զ������
   * @param[in] track1 1���������
   * @n bit0 - �������������ã�0��ʾ�������1��ʾ�����
   * @n bit1 - �������ͷ���ã�0��ʾ������ͷ��1��ʾ������ͷ��
   * @n bit2 - �������β���ã�0��ʾ������β��1��ʾ������β��
   * @n bit3 - ������ݻ��з����ã�0��ʾ�޻��з���1��ʾ�л��з���
   * @n bit4 - ������ݵȺ�������������ã�0��ʾ�������1��ʾ�����
   * @n bit5~bit7 - ������
   * @param[in] track2 2���������
   * @n bit0 - �������������ã�0��ʾ�������1��ʾ�����
   * @n bit1 - �������ͷ���ã�0��ʾ������ͷ��1��ʾ������ͷ��
   * @n bit2 - �������β���ã�0��ʾ������β��1��ʾ������β��
   * @n bit3 - ������ݻ��з����ã�0��ʾ�޻��з���1��ʾ�л��з���
   * @n bit4 - ������ݵȺ�������������ã�0��ʾ�������1��ʾ�����
   * @n bit5~bit7 - ������
   * @param[in] track3 3���������
   * @n bit0 - �������������ã�0��ʾ�������1��ʾ�����
   * @n bit1 - �������ͷ���ã�0��ʾ������ͷ��1��ʾ������ͷ��
   * @n bit2 - �������β���ã�0��ʾ������β��1��ʾ������β��
   * @n bit3 - ������ݻ��з����ã�0��ʾ�޻��з���1��ʾ�л��з���
   * @n bit4 - ������ݵȺ�������������ã�0��ʾ�������1��ʾ�����
   * @n bit5~bit7 - ������
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_setmag(HANDLE icdev, unsigned char mode, unsigned char track1, unsigned char track2, unsigned char track3);

  /**
   * @brief  ���ô�ӡ��������
   * @par    ˵����
   * ���ò�����ӡ���Ĳ�����
   * @param[in] icdev �豸��ʶ����
   * @param[in] FontSize �������ã�0x00��ʾ�ַ���СΪ8*16��0x01��ʾ�ַ���СΪ12*24��0x02��ʾ�ַ���СΪ16*32��
   * @param[in] Alignment �������ã�0x00��ʾ����룬0x01��ʾ���У�0x02��ʾ�Ҷ��롣
   * @param[in] LeftMargin ��߾����ã��ַ���СΪ8*16ʱ<48���ַ���СΪ12*24ʱ<32���ַ���СΪ16*32ʱ<24��
   * @param[in] RightMargin �ұ߾����ã��ַ���СΪ8*16ʱ<48���ַ���СΪ12*24ʱ<32���ַ���СΪ16*32ʱ<24��
   * @param[in] RowPitch �м�����ã���λΪ�㡣
   * @param[in] PrintOutRate ��ӡ�ٶ����ã�0x00~0x03����0x00��죬0x03������
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_setprint(HANDLE icdev, unsigned char FontSize, unsigned char Alignment, unsigned char LeftMargin, unsigned char RightMargin, unsigned char RowPitch, unsigned char PrintOutRate);

  /**
   * @brief  ��ѯ��ӡ��������
   * @par    ˵����
   * ��ѯ������ӡ���Ĳ�����
   * @param[in] icdev �豸��ʶ����
   * @param[out] FontSize �������ã�0x00��ʾ�ַ���СΪ8*16��0x01��ʾ�ַ���СΪ12*24��0x02��ʾ�ַ���СΪ16*32��
   * @param[out] Alignment �������ã�0x00��ʾ����룬0x01��ʾ���У�0x02��ʾ�Ҷ��롣
   * @param[out] LeftMargin ��߾����ã��ַ���СΪ8*16ʱ<48���ַ���СΪ12*24ʱ<32���ַ���СΪ16*32ʱ<24��
   * @param[out] RightMargin �ұ߾����ã��ַ���СΪ8*16ʱ<48���ַ���СΪ12*24ʱ<32���ַ���СΪ16*32ʱ<24��
   * @param[out] RowPitch �м�����ã���λΪ�㡣
   * @param[out] PrintOutRate ��ӡ�ٶ����ã�0x00~0x03����0x00��죬0x03������
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_checkprint(HANDLE icdev, unsigned char *FontSize, unsigned char *Alignment, unsigned char *LeftMargin, unsigned char *RightMargin, unsigned char *RowPitch, unsigned char *PrintOutRate);

  /**
   * @brief  ��ӡ�ַ���
   * @par    ˵����
   * ��ӡ�ı��ַ���Ϣ��
   * @param[in] icdev �豸��ʶ����
   * @param[in] length �ַ����ݵĳ��ȣ�����С�ڻ����480��
   * @param[in] character �ַ����ݡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_printcharacter(HANDLE icdev, unsigned short length, unsigned char *character);

  /**
   * @brief  ��ӡһά�롣
   * @par    ˵����
   * ��ӡһά����Ϣ��
   * @param[in] icdev �豸��ʶ����
   * @param[in] hight һά��ĸ߶ȡ�
   * @param[in] displayflag ��ʾ���ͣ�0x00��ʾͼ�������ı����ϣ�0x01��ʾͼ�������ı����£�0x02��ʾֻ��ʾͼ�β���ʾ�ı���
   * @param[in] FontSize �������ã�0x00��ʾ�ַ���СΪ8*16��0x01��ʾ�ַ���СΪ12*24��0x02��ʾ�ַ���СΪ16*32��
   * @param[in] length �ı����ݵĳ��ȣ�����С�ڻ����15��
   * @param[in] Onedimensional �ı����ݡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_printOnedimensional(HANDLE icdev, unsigned char hight, unsigned char displayflag, unsigned char FontSize, unsigned short length, unsigned char *Onedimensional);

  /**
   * @brief  ��ӡͼƬ��
   * @par    ˵����
   * ��ӡͼƬ��Ϣ��
   * @param[in] icdev �豸��ʶ����
   * @param[in] length ���ȣ���λΪ�ֽڣ�����С�ڻ����48������Ϊ0��
   * @param[in] height �߶ȣ���λΪ�㣬����С��100������Ϊ0��
   * @param[in] Alignment �������ã�0x00��ʾ����룬0x01��ʾ���У�0x02��ʾ�Ҷ��롣
   * @param[in] LeftMargin ��߾����ã�����С�ڻ����48��
   * @param[in] RightMargin �ұ߾����ã�����С�ڻ����48��
   * @param[in] size ͼƬ���ݵĴ�С��
   * @param[in] Picture ͼƬ���ݡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_printPicture(HANDLE icdev, unsigned char length, unsigned char height, unsigned char Alignment, unsigned char LeftMargin, unsigned char RightMargin, unsigned short size, unsigned char *Picture);

  /**
   * @brief  ��ֽ��
   * @par    ˵����
   * ��ֽ���豸�����ڴ�ӡ��
   * @param[in] icdev �豸��ʶ����
   * @param[in] RowPitch ��ֽ��������λΪ�㡣
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_printenter(HANDLE icdev, unsigned char RowPitch);

  /**
   * @brief  ��ȡ��ӡ��״̬��
   * @par    ˵����
   * ��ȡ��ӡ����״̬��
   * @param[in] icdev �豸��ʶ����
   * @param[out] paperstatus ֽ״̬��0x00��ʾ��ȱֽ��0x01��ʾȱֽ��
   * @param[out] tempturestatus �¶�״̬��0x00��ʾ�¶�������0x01��ʾ�¶ȹ��ߡ�
   * @param[out] zkstatus �ֿ�״̬��
   * @n 0x00 - �����ֿⶼ���ڡ�
   * @n 0x01 - �����ֿⶼ�����ڡ�
   * @n 0x02 - ����8*16�ֿ⡣
   * @n 0x03 - ����12*24�ֿ⡣
   * @n 0x04 - ����16*32�ֿ⡣
   * @n 0x05 - ����8*16�ֿ��12*24�ֿ⡣
   * @n 0x06 - ����8*16�ֿ��16*32�ֿ⡣
   * @n 0x07 - ����12*24�ֿ��16*32�ֿ⡣
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_printstatus(HANDLE icdev, unsigned char *paperstatus, unsigned char *tempturestatus, unsigned char *zkstatus);

  /**
   * @brief  ����2.4Gģ�鲨���ʡ�
   * @par    ˵����
   * ������2.4Gģ��֮��ͨѶ�Ĳ����ʡ�
   * @param[in] icdev �豸��ʶ����
   * @param[in] baund �����ʡ�
   * @n 0x00 - 2400��
   * @n 0x01 - 4800��
   * @n 0x02 - 9600��
   * @n 0x03 - 14400��
   * @n 0x04 - 38400��
   * @n 0x05 - 57600��
   * @n 0x06 - 115200��
   * @n 0x07 - 256000��
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_set2dot4Gbaund(HANDLE icdev, unsigned char baund);

  /**
   * @brief  ��ѯ2.4Gģ�鲨���ʡ�
   * @par    ˵����
   * ��ѯ��2.4Gģ��֮��ͨѶ�Ĳ����ʡ�
   * @param[in] icdev �豸��ʶ����
   * @param[out] baund �����ʡ�
   * @n 0x00 - 2400��
   * @n 0x01 - 4800��
   * @n 0x02 - 9600��
   * @n 0x03 - 14400��
   * @n 0x04 - 38400��
   * @n 0x05 - 57600��
   * @n 0x06 - 115200��
   * @n 0x07 - 256000��
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_check2dot4Gbaund(HANDLE icdev, unsigned char *baund);

  /**
   * @brief  2.4G��λ��
   * @par    ˵����
   * ��2.4G���и�λ������
   * @param[in] icdev �豸��ʶ����
   * @param[out] rlen ���ظ�λ��Ϣ�ĳ��ȡ�
   * @param[out] databuffer ���صĸ�λ��Ϣ�������ٷ���128���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_2dot4_reset(HANDLE icdev, unsigned char *rlen, unsigned char *databuffer);

  /**
   * @brief  2.4G��λ��
   * @par    ˵����
   * ::dc_2dot4_reset ��HEX��ʽ�ӿڣ����� @a databuffer ΪHEX��ʽ��
   */
  short USER_API dc_2dot4_resethex(HANDLE icdev, unsigned char *rlen, unsigned char *databuffer);

  /**
   * @brief  2.4Gָ�����
   * @par    ˵����
   * ��2.4G����ָ���������
   * @param[in] icdev �豸��ʶ����
   * @param[in] slen �������ݵĳ��ȡ�
   * @param[in] senddata �������ݡ�
   * @param[out] rlen �������ݵĳ��ȡ�
   * @param[out] recvbuffer ���ص����ݡ�
   * @param[in] timeout �豸��ʱֵ����λΪ�롣
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_2dot4_command(HANDLE icdev, unsigned int slen, unsigned char *senddata, unsigned int *rlen, unsigned char *recvbuffer, unsigned char timeout);

  /**
   * @brief  2.4Gָ�����
   * @par    ˵����
   * ::dc_2dot4_command ��HEX��ʽ�ӿڣ����� @a senddata @a recvbuffer ΪHEX��ʽ��
   */
  short USER_API dc_2dot4_command_hex(HANDLE icdev, unsigned int slen, unsigned char *senddata, unsigned int *rlen, unsigned char *recvbuffer, unsigned char timeout);

  /**
   * @brief  ���102����
   * @par    ˵����
   * ����Ƿ����102����
   * @param[in] icdev �豸��ʶ����
   * @return <0��ʾʧ�ܻ򲻴��ڣ�==0��ʾ���ڡ�
   */
  short USER_API dc_check_102(HANDLE icdev);

  /**
   * @brief  102���µ硣
   * @par    ˵����
   * ��102�������µ������
   * @param[in] icdev �豸��ʶ����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_down_102(HANDLE icdev);

  /**
   * @brief  ��102����
   * @par    ˵����
   * ��ȡ102�������ݡ�
   * @param[in] icdev �豸��ʶ����
   * @param[in] offset ƫ�ơ�
   * @param[in] length ��ȡ���ȡ�
   * @param[out] readdata ���ص����ݡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_read_102(HANDLE icdev, unsigned char offset, unsigned char length, unsigned char *readdata);

  /**
   * @brief  ��102����
   * @par    ˵����
   * ::dc_read_102 ��HEX��ʽ�ӿڣ����� @a readdata ΪHEX��ʽ��
   */
  short USER_API dc_read_102_hex(HANDLE icdev, unsigned char offset, unsigned char length, unsigned char *readdata);

  /**
   * @brief  д102����
   * @par    ˵����
   * д�����ݵ�102���С�
   * @param[in] icdev �豸��ʶ����
   * @param[in] offset ƫ�ơ�
   * @param[in] length д�볤�ȡ�
   * @param[in] writedata �������ݡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_write_102(HANDLE icdev, unsigned char offset, unsigned char length, unsigned char *writedata);

  /**
   * @brief  д102����
   * @par    ˵����
   * ::dc_write_102 ��HEX��ʽ�ӿڣ����� @a writedata ΪHEX��ʽ��
   */
  short USER_API dc_write_102_hex(HANDLE icdev, unsigned char offset, unsigned char length, unsigned char *writedata);

  /**
   * @brief  ��֤102�����롣
   * @par    ˵����
   * ʹ�ô������������֤102�����롣
   * @param[in] icdev �豸��ʶ����
   * @param[in] zone ��������
   * @n 0 - ��ʾ�����룬���볤��Ϊ2���ֽڡ�
   * @n 11 - ��ʾһ���������룬���볤��Ϊ6���ֽڡ�
   * @n 12 - ��ʾ�����������룬���볤��Ϊ4���ֽڡ�
   * @param[in] password ���롣
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_checkpass_102(HANDLE icdev, short zone, unsigned char *password);

  /**
   * @brief  ��֤102�����롣
   * @par    ˵����
   * ::dc_checkpass_102 ��HEX��ʽ�ӿڣ����� @a password ΪHEX��ʽ��
   */
  short USER_API dc_checkpass_102_hex(HANDLE icdev, short zone, unsigned char *password);

  /**
   * @brief  �޸�102�����롣
   * @par    ˵����
   * �޸�102�������롣
   * @param[in] icdev �豸��ʶ����
   * @param[in] zone ��������
   * @n 0 - ��ʾ�����룬���볤��Ϊ2���ֽڡ�
   * @n 11 - ��ʾһ���������룬���볤��Ϊ6���ֽڡ�
   * @n 12 - ��ʾ�����������룬���볤��Ϊ4���ֽڡ�
   * @param[in] password ���롣
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_changepass_102(HANDLE icdev, short zone, unsigned char *password);

  /**
   * @brief  �޸�102�����롣
   * @par    ˵����
   * ::dc_changepass_102 ��HEX��ʽ�ӿڣ����� @a password ΪHEX��ʽ��
   */
  short USER_API dc_changepass_102_hex(HANDLE icdev, short zone, unsigned char *password);

  /**
   * @brief  ��102�����������
   * @par    ˵����
   * ��ȡ102��������������˼���ֵ��ʾ���Գ�����֤����Ĵ�����
   * @param[in] icdev �豸��ʶ����
   * @param[in] zone ��������
   * @n 0 - ��ʾ�����롣
   * @return <0��ʾʧ�ܣ�����Ϊ�������ֵ��
   */
  short USER_API dc_readcount_102(HANDLE icdev, short zone);

  /**
   * @brief  102����˿��
   * @par    ˵����
   * ��102��������˿������
   * @param[in] icdev �豸��ʶ����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_fuse_102(HANDLE icdev);

  /**
   * @brief  ���1604����
   * @par    ˵����
   * ����Ƿ����1604����
   * @param[in] icdev �豸��ʶ����
   * @return <0��ʾʧ�ܻ򲻴��ڣ�==0��ʾ���ڡ�
   */
  short USER_API dc_check_1604(HANDLE icdev);

  /**
   * @brief  1604���µ硣
   * @par    ˵����
   * ��1604�������µ������
   * @param[in] icdev �豸��ʶ����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_down_1604(HANDLE icdev);

  /**
   * @brief  ��1604����
   * @par    ˵����
   * ��ȡ1604�������ݡ�
   * @param[in] icdev �豸��ʶ����
   * @param[in] offset ƫ�ơ�
   * @param[in] length ��ȡ���ȡ�
   * @param[out] readdata ���ص����ݡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_read_1604(HANDLE icdev, unsigned int offset, unsigned int length, unsigned char *readdata);

  /**
   * @brief  ��1604����
   * @par    ˵����
   * ::dc_read_1604 ��HEX��ʽ�ӿڣ����� @a readdata ΪHEX��ʽ��
   */
  short USER_API dc_read_1604_hex(HANDLE icdev, unsigned int offset, unsigned int length, unsigned char *readdata);

  /**
   * @brief  д1604����
   * @par    ˵����
   * д�����ݵ�1604���С�
   * @param[in] icdev �豸��ʶ����
   * @param[in] offset ƫ�ơ�
   * @param[in] length д�볤�ȡ�
   * @param[in] writedata �������ݡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_write_1604(HANDLE icdev, unsigned int offset, unsigned int length, unsigned char *writedata);

  /**
   * @brief  д1604����
   * @par    ˵����
   * ::dc_write_1604 ��HEX��ʽ�ӿڣ����� @a writedata ΪHEX��ʽ��
   */
  short USER_API dc_write_1604_hex(HANDLE icdev, unsigned int offset, unsigned int length, unsigned char *writedata);

  /**
   * @brief  ��֤1604�����롣
   * @par    ˵����
   * ʹ�ô������������֤1604�����롣
   * @param[in] icdev �豸��ʶ����
   * @param[in] zone ��������
   * @n 0 - ��ʾ�����롣
   * @n 1 - ��ʾһ�����롣
   * @n 2 - ��ʾ�������롣
   * @n 3 - ��ʾ�������롣
   * @n 4 - ��ʾ�������롣
   * @n 11 - ��ʾһ���������롣
   * @n 12 - ��ʾ�����������롣
   * @n 13 - ��ʾ�����������롣
   * @n 14 - ��ʾ�����������롣
   * @param[in] password ���룬�̶�Ϊ2���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_checkpass_1604(HANDLE icdev, short zone, unsigned char *password);

  /**
   * @brief  ��֤1604�����롣
   * @par    ˵����
   * ::dc_checkpass_1604 ��HEX��ʽ�ӿڣ����� @a password ΪHEX��ʽ��
   */
  short USER_API dc_checkpass_1604_hex(HANDLE icdev, short zone, unsigned char *password);

  /**
   * @brief  �޸�1604�����롣
   * @par    ˵����
   * �޸�1604�������롣
   * @param[in] icdev �豸��ʶ����
   * @param[in] zone ��������
   * @n 0 - ��ʾ�����롣
   * @n 1 - ��ʾһ�����롣
   * @n 2 - ��ʾ�������롣
   * @n 3 - ��ʾ�������롣
   * @n 4 - ��ʾ�������롣
   * @n 11 - ��ʾһ���������롣
   * @n 12 - ��ʾ�����������롣
   * @n 13 - ��ʾ�����������롣
   * @n 14 - ��ʾ�����������롣
   * @param[in] password ���룬�̶�Ϊ2���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_changepass_1604(HANDLE icdev, short zone, unsigned char *password);

  /**
   * @brief  �޸�1604�����롣
   * @par    ˵����
   * ::dc_changepass_1604 ��HEX��ʽ�ӿڣ����� @a password ΪHEX��ʽ��
   */
  short USER_API dc_changepass_1604_hex(HANDLE icdev, short zone, unsigned char *password);

  /**
   * @brief  ��1604�����������
   * @par    ˵����
   * ��ȡ1604��������������˼���ֵ��ʾ���Գ�����֤����Ĵ�����
   * @param[in] icdev �豸��ʶ����
   * @param[in] zone ��������
   * @n 0 - ��ʾ�����롣
   * @n 1 - ��ʾһ�����롣
   * @n 2 - ��ʾ�������롣
   * @n 3 - ��ʾ�������롣
   * @n 4 - ��ʾ�������롣
   * @n 11 - ��ʾһ���������롣
   * @n 12 - ��ʾ�����������롣
   * @n 13 - ��ʾ�����������롣
   * @n 14 - ��ʾ�����������롣
   * @return <0��ʾʧ�ܣ�����Ϊ�������ֵ��
   */
  short USER_API dc_readcount_1604(HANDLE icdev, short zone);

  /**
   * @brief  1604����˿��
   * @par    ˵����
   * ��1604��������˿������
   * @param[in] icdev �豸��ʶ����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_fuse_1604(HANDLE icdev);

  /**
   * @brief  4428���µ硣
   * @par    ˵����
   * ��4428�������µ������
   * @param[in] icdev �豸��ʶ����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_down_4428(HANDLE icdev);

  /**
   * @brief  4442���µ硣
   * @par    ˵����
   * ��4442�������µ������
   * @param[in] icdev �豸��ʶ����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_down_4442(HANDLE icdev);

  /**
   * @brief  ������
   */
  short USER_API dc_flash_card(HANDLE icdev);

  /**
   * @brief  ������
   */
  short USER_API dc_read_walletbalance(HANDLE icdev, unsigned char *walletvalue);

  /**
   * @brief  ������
   */
  short USER_API dc_consume_wallet(HANDLE icdev, unsigned char *walletvalue, unsigned char *secret);

  /**
   * @brief  ������
   */
  short USER_API dc_transfer_wallet(HANDLE icdev, unsigned char *walletvalue);

  /**
   * @brief  ������
   */
  short USER_API dc_authentication_key(HANDLE icdev, unsigned char *data, unsigned char *desdata);

  /**
   * @brief  ������
   */
  short USER_API dc_set_terminalnumber(HANDLE icdev, unsigned char length, unsigned char *serieldata);

  /**
   * @brief  ������
   */
  short USER_API dc_get_terminalnumber(HANDLE icdev, unsigned char length, unsigned char *serieldata);

  /**
   * @brief  ������
   */
  short USER_API dc_set_trademerchantcode(HANDLE icdev, unsigned char length, unsigned char *merchantcode);

  /**
   * @brief  ������
   */
  short USER_API dc_get_trademerchantcode(HANDLE icdev, unsigned char length, unsigned char *merchantcode);

  /**
   * @brief  ������
   */
  short USER_API dc_set_transactiontype(HANDLE icdev, unsigned char typecode);

  /**
   * @brief  ������
   */
  short USER_API dc_get_transactiontype(HANDLE icdev, unsigned char *typecode);

  /**
   * @brief  ������
   */
  short USER_API dc_set_tradesecretkey(HANDLE icdev, unsigned char *secretkey);

  /**
   * @brief  ������
   */
  short USER_API dc_get_tradesecretkey(HANDLE icdev, unsigned char *secretkey);

  /**
   * @brief  ������
   */
  short USER_API dc_set_hardwareserialnumber(HANDLE icdev, unsigned char length, unsigned char *hardwareserial);

  /**
   * @brief  ������
   */
  short USER_API dc_get_hardwareserialnumber(HANDLE icdev, unsigned char length, unsigned char *hardwareserial);

  /**
   * @brief  ������
   */
  short USER_API dc_reset_factory(HANDLE icdev);

  /**
   * @brief  ������
   */
  short USER_API dc_get_signmessageparameters(HANDLE icdev, unsigned char length, unsigned char *parameters);

  /**
   * @brief  ������
   */
  short USER_API dc_get_record(HANDLE icdev, unsigned char tablenumber, unsigned char recordnumber, unsigned char *recordquantity, unsigned char *recorddata);

  /**
   * @brief  ��������������
   * @par    ˵����
   * ʹ�豸������ˢ������״̬���ӿڱ����ֱ�ӷ��أ�������ȴ�ˢ���������
   * @param[in] icdev �豸��ʶ����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_startreadmag(HANDLE icdev);

  /**
   * @brief  ֹͣ����������
   * @par    ˵����
   * ���豸������ˢ������״̬��ֻ��ˢ�����������ô˽ӿڲ���ʹ���豸�˳�����״̬��
   * @param[in] icdev �豸��ʶ����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_stopreadmag(HANDLE icdev);

  /**
   * @brief  ��ȡ���������ݡ�
   * @par    ˵����
   * ��ȡ�豸�Ѿ���ȡ���Ĵ��������ݡ�
   * @param[in] icdev �豸��ʶ����
   * @param[out] pTrack1Data ���ص�1������ݣ����ݸ�ʽΪ'\0'��β���ַ�����
   * @param[out] pTrack1Len ����1������ݵĳ��ȣ�����'\0'��
   * @param[out] pTrack2Data ���ص�2������ݣ����ݸ�ʽΪ'\0'��β���ַ�����
   * @param[out] pTrack2Len ����2������ݵĳ��ȣ�����'\0'��
   * @param[out] pTrack3Data ���ص�3������ݣ����ݸ�ʽΪ'\0'��β���ַ�����
   * @param[out] pTrack3Len ����3������ݵĳ��ȣ�����'\0'��
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���==1��ʾ�ȴ�ˢ����==2��ʾ����ֹͣˢ��״̬��
   */
  short USER_API dc_readmag(HANDLE icdev, unsigned char *pTrack1Data, unsigned int *pTrack1Len, unsigned char *pTrack2Data, unsigned int *pTrack2Len, unsigned char *pTrack3Data, unsigned int *pTrack3Len);

  /**
   * @brief  �Զ���ȡ���������ݡ�
   * @par    ˵����
   * �ڲ������� ::dc_startreadmag ::dc_readmag ::dc_stopreadmag �Ĺ��ܡ�
   * @param[in] icdev �豸��ʶ����
   * @param[in] ctime �ӿڳ�ʱֵ����λΪ�롣
   * @param[out] pTrack1Data ���ص�1������ݣ����ݸ�ʽΪ'\0'��β���ַ�����
   * @param[out] pTrack1Len ����1������ݵĳ��ȣ�����'\0'��
   * @param[out] pTrack2Data ���ص�2������ݣ����ݸ�ʽΪ'\0'��β���ַ�����
   * @param[out] pTrack2Len ����2������ݵĳ��ȣ�����'\0'��
   * @param[out] pTrack3Data ���ص�3������ݣ����ݸ�ʽΪ'\0'��β���ַ�����
   * @param[out] pTrack3Len ����3������ݵĳ��ȣ�����'\0'��
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���==1��ʾ�ȴ�ˢ����==2��ʾ����ֹͣˢ��״̬��
   */
  short USER_API dc_readmagcardallA(HANDLE icdev, unsigned char ctime, unsigned char *pTrack1Data, unsigned int *pTrack1Len, unsigned char *pTrack2Data, unsigned int *pTrack2Len, unsigned char *pTrack3Data, unsigned int *pTrack3Len);

  /**
   * @brief  �������������Կ��
   * @par    ˵����
   * ����������ڵ���Կ�������ò�����
   * @param[in] icdev �豸��ʶ����
   * @param[in] flag ��ǡ�
   * @n 0x00 - ��ʾװ������Կ������װ�ء�
   * @n 0x01 - ��ʾװ��PIN��Կ������װ�أ�������Կ���ܣ���
   * @n 0x02 - ��ʾװ��MAC��Կ������װ�أ�������Կ���ܣ���
   * @n 0x03 - ��ʾװ��TDK��Կ������װ�أ�������Կ���ܣ���
   * @n 0xF0 - ��ʾ�������Կ��PIN��Կ��MAC��Կ��TDK��Կ��
   * @n 0xF1 - ��ʾ���PIN��Կ��
   * @n 0xF2 - ��ʾ���MAC��Կ��
   * @n 0xF3 - ��ʾ���TDK��Կ��
   * @param[in] keylen ��Կ���ݵĳ��ȡ�
   * @param[in] keydata ��Կ���ݡ�
   * @param[in] mode ģʽ��0x00��ʾ��DES��Կ��0x01��ʾ��DES��Կ��0x02��ʾSM4��Կ��0x03��ʾ24�ֽ���DES��Կ��
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_InstallKbKey(HANDLE icdev, unsigned char flag, unsigned char keylen, unsigned char *keydata, unsigned char mode);

  /**
   * @brief  ���õ�ǰ��Կ�顣
   * @par    ˵����
   * ����������̵�ǰʹ�õ���Կ�顣
   * @param[in] icdev �豸��ʶ����
   * @param[in] keyID ��Կ��ţ���0x00��ʼ��š�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_SetKbKeyID(HANDLE icdev, unsigned char keyID);

  /**
   * @brief  ��ȡ���ܰ������ݡ�
   * @par    ˵����
   * ��������̻�ȡANSI X9.8 PIN BLOCK���ܵİ������ݡ�
   * @param[in] icdev �豸��ʶ����
   * @param[in] ctime �豸��ʱֵ����λΪ�롣
   * @param[in] panlen ���ŵĳ��ȡ�
   * @param[in] pandata ���š�
   * @param[out] rlen ���ؼ������ݵĳ��ȡ�
   * @param[out] cpass ���صļ������ݡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���==0xA1��ʾȡ�����룬==0xA2��ʾ���볬ʱ��
   */
  short USER_API dc_GetEnPass(HANDLE icdev, unsigned char ctime, unsigned char panlen, unsigned char *pandata, unsigned char *rlen, unsigned char *cpass);

  /**
   * @brief  ������
   */
  short USER_API dc_get55data(HANDLE icdev, unsigned int slen, unsigned char *sdata, unsigned char *PacketType, unsigned int *rlen, unsigned char *rdata);

  /**
   * @brief  ������
   */
  short USER_API dc_CardIssuingScript(HANDLE icdev, unsigned int slen, unsigned char *sdata, unsigned char *TransactionIsInterrupted, unsigned char *TradingResult);

  /**
   * @brief  ������
   */
  short USER_API dc_SetEMVPara(HANDLE icdev, unsigned int slen, unsigned char *sdata);

  /**
   * @brief  ������
   */
  short USER_API dc_CalculateMACCheck(HANDLE icdev, unsigned char keyindex, unsigned char macmode, unsigned int datalen, unsigned char *srcdata, unsigned char *macdata);

  /**
   * @brief  ������
   */
  short USER_API dc_CalculateDes(HANDLE icdev, unsigned char keyindex, unsigned char enmode, unsigned short datalen, unsigned char *srcdata, unsigned char *desdata);

  /**
   * @brief  ������
   */
  short USER_API dc_CalculateSm4(HANDLE icdev, unsigned char keyindex, unsigned char enmode, unsigned short datalen, unsigned char *srcdata, unsigned char *sm4data);

  /**
   * @brief  �ù�����Կ�ӽ��ܡ�
   * @par    ˵����
   * ʹ��������̵Ĺ�����Կ�������ݼӽ��ܲ�������֧�ֵ�DES����DES��24�ֽ���DES�㷨���㷨��������Կʱȷ������ο� ::dc_InstallKbKey ��
   * @param[in] icdev �豸��ʶ����
   * @param[in] keytype ��Կ���ͣ�0x01��ʾPIN��Կ��0x02��ʾMAC��Կ��0x03��ʾTDK��Կ��
   * @param[in] enmode ����ģʽ��0x00��ʾ���ܣ�0x01��ʾ���ܡ�
   * @param[in] sourcedata �������ݣ��̶�Ϊ8���ֽڡ�
   * @param[out] retdata ���ص����ݣ��̶�Ϊ8���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_CreatDesData(HANDLE icdev, unsigned char keytype, unsigned char enmode, unsigned char *sourcedata, unsigned char *retdata);

  /**
   * @brief  �ù�����Կ�ӽ��ܡ�
   * @par    ˵����
   * ʹ��������̵Ĺ�����Կ�������ݼӽ��ܲ�������֧��SM4�㷨���㷨��������Կʱȷ������ο� ::dc_InstallKbKey ��
   * @param[in] icdev �豸��ʶ����
   * @param[in] keytype ��Կ���ͣ�0x01��ʾPIN��Կ��0x02��ʾMAC��Կ��0x03��ʾTDK��Կ��
   * @param[in] enmode ����ģʽ��0x00��ʾ���ܣ�0x01��ʾ���ܡ�
   * @param[in] sourcedata �������ݣ��̶�Ϊ16���ֽڡ�
   * @param[out] retdata ���ص����ݣ��̶�Ϊ16���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_CreatSm4Data(HANDLE icdev, unsigned char keytype, unsigned char enmode, unsigned char *sourcedata, unsigned char *retdata);

  /**
   * @brief  �ù�����Կ�ӽ��ܡ�
   * @par    ˵����
   * ʹ��������̵Ĺ�����Կ�������ݼӽ��ܲ�������֧�ֵ�DES ECB����DES ECB�㷨���ڲ������ ::dc_CreatDesData ��
   * @param[in] icdev �豸��ʶ����
   * @param[in] keytype ��Կ���ͣ�0x01��ʾPIN��Կ��0x02��ʾMAC��Կ��0x03��ʾTDK��Կ��
   * @param[in] enmode ����ģʽ��0x00��ʾ���ܣ�0x01��ʾ���ܡ�
   * @param[in] slen �������ݵĳ��ȡ�
   * @param[in] sourcedata �������ݡ�
   * @param[out] rlen �������ݵĳ��ȡ�
   * @param[out] retdata ���ص����ݡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_CreatDesDataECB(HANDLE icdev, unsigned char keytype, unsigned char enmode, int slen, unsigned char *sourcedata, int *rlen, unsigned char *retdata);

  /**
   * @brief  �ù�����Կ�ӽ��ܡ�
   * @par    ˵����
   * ʹ��������̵Ĺ�����Կ�������ݼӽ��ܲ�������֧��SM4 ECB�㷨���ڲ������ ::dc_CreatSm4Data ��
   * @param[in] icdev �豸��ʶ����
   * @param[in] keytype ��Կ���ͣ�0x01��ʾPIN��Կ��0x02��ʾMAC��Կ��0x03��ʾTDK��Կ��
   * @param[in] enmode ����ģʽ��0x00��ʾ���ܣ�0x01��ʾ���ܡ�
   * @param[in] slen �������ݵĳ��ȡ�
   * @param[in] sourcedata �������ݡ�
   * @param[out] rlen �������ݵĳ��ȡ�
   * @param[out] retdata ���ص����ݡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_CreatSm4DataECB(HANDLE icdev, unsigned char keytype, unsigned char enmode, int slen, unsigned char *sourcedata, int *rlen, unsigned char *retdata);

  /**
   * @brief  �ù�����Կ��MAC��
   * @par    ˵����
   * ʹ��������̵Ĺ�����Կ����������MAC�������ڲ������ ::dc_CreatDesData ::dc_CreatSm4Data ��
   * @param[in] icdev �豸��ʶ����
   * @param[in] keytype ��Կ���ͣ�0x01��ʾPIN��Կ��0x02��ʾMAC��Կ��0x03��ʾTDK��Կ��
   * @param[in] enmode ����ģʽ��0x00��0x01��ʾ��DES POS ECB��MAC��0x02��ʾ��SM4��MAC��0x03��ʾ��DES X9.9��MAC��0x04��ʾ����DES X9.19��MAC��0x05��ʾ����DES POS ECB��MAC��0x06��ʾ��24�ֽ���DES X9.19��MAC��0x07��ʾ��24�ֽ���DES POS ECB��MAC��
   * @param[in] slen �������ݵĳ��ȡ�
   * @param[in] sourcedata �������ݡ�
   * @param[out] rlen �������ݵĳ��ȡ�
   * @param[out] retdata ���ص����ݡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_CreatMacDataECB(HANDLE icdev, unsigned char keytype, unsigned char enmode, int slen, unsigned char *sourcedata, int *rlen, unsigned char *retdata);

  /**
   * @brief  дSD�洢��
   * @par    ˵����
   * д�����ݵ�SD�洢�У������������ݱ���ȡ�
   * @param[in] icdev �豸��ʶ����
   * @param[in] offset ƫ�Ƶ�ַ��
   * @param[in] length д�볤�ȡ�
   * @param[in] writebuffer �������ݡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_writeSD(HANDLE icdev, int offset, int length, unsigned char *writebuffer);

  /**
   * @brief  ��SD�洢��
   * @par    ˵����
   * ��ȡSD�洢�е����ݣ������������ݱ���ȡ�
   * @param[in] icdev �豸��ʶ����
   * @param[in] offset ƫ�Ƶ�ַ��
   * @param[in] length ��ȡ���ȡ�
   * @param[out] readbuffer ���ص����ݡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_readSD(HANDLE icdev, int offset, int length, unsigned char *readbuffer);

  /**
   * @brief  ����USBģʽ��
   * @par    ˵����
   * ����USBͨѶģʽ���������¶��豸�����ϵ������Ч��
   * @param[in] icdev �豸��ʶ����
   * @param[in] ucmode ģʽ��
   * @n 0x00 - ��ʾ�жϷ��ͺ��жϽ��գ���ʱVID=257B��PID=3010��
   * @n 0x01 - ��ʾ���Ʒ��ͺͿ��ƽ��գ���ʱVID=257B��PID=3011��
   * @n 0x02 - ��ʾ���Ʒ��ͺ��жϽ��գ���ʱVID=0471��PID=7002��
   * @n 0x03 - ��ʾ���Ʒ��ͺ��жϽ��գ���ʱVID=0471��PID=7003��
   * @n 0x04 - ��ʾ���Ʒ��ͺ��жϽ��գ���ʱVID=0471��PID=7003��֧�ִ������Զ��ϴ����ܡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_SetUsbMode(HANDLE icdev, unsigned char ucmode);

  /**
   * @brief  ����������ͨѶ��
   * @par    ˵����
   * ������������̽���ͨѶ������
   * @param[in] icdev �豸��ʶ����
   * @param[in] ctime �豸��ʱֵ����λΪ�롣
   * @param[in] senlen �������ݵĳ��ȡ�
   * @param[in] source �������ݡ�
   * @param[out] reclen �������ݵĳ��ȡ�
   * @param[out] rdata ���ص����ݡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API SD_InstallKey(HANDLE icdev, unsigned char ctime, unsigned char senlen, unsigned char *source, unsigned char *reclen, unsigned char *rdata);

  /**
   * @brief  ��ȡ���������̵İ汾��
   * @par    ˵����
   * ��ȡ���������̵İ汾��
   * @param[in] icdev �豸��ʶ����
   * @param[out] version ���صİ汾�ַ����������ٷ���128���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API SD_IFD_GetVersion(HANDLE icdev, char *version);

  /**
   * @brief  ���������̲���������
   * @par    ˵����
   * ������������������������
   * @param[in] icdev �豸��ʶ����
   * @param[in] _playmode �����κţ�0x01~0x08����
   * @n 0x01 - "����������"��
   * @n 0x02 - "������ԭ����"��
   * @n 0x03 - "��������һ��"��
   * @n 0x04 - "������������"��
   * @n 0x05 - "��ȷ��������"��
   * @n 0x06 - "�����޸ĳɹ�"��
   * @n 0x07 - "��忨"��
   * @n 0x08 - "��ˢ��"��
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API SD_IFD_PlayVoice(HANDLE icdev, unsigned char _playmode);

  /**
   * @brief  ���������̳�ʼ����
   * @par    ˵����
   * �����������̽��г�ʼ��������ʹ�临λΪ����״̬������״̬�����е�����Կ�ڴ�ռ䶼Ϊ�ֽ�0x88��
   * @param[in] icdev �豸��ʶ����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API SD_IFD_Init(HANDLE icdev);

  /**
   * @brief  ������������������Կ��
   * @par    ˵����
   * �������������ڵ�����Կ�������ò�����
   * @param[in] icdev �豸��ʶ����
   * @param[in] keyset ��Կ��ţ���0x00��ʼ��š�
   * @param[in] oldkey ������Կ���ݣ����ģ��̶�Ϊ16���ֽڡ�
   * @param[in] newkey ������Կ���ݣ����ģ��̶�Ϊ16���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API SD_IFD_SetMainKey(HANDLE icdev, unsigned char keyset, unsigned char *oldkey, unsigned char *newkey);

  /**
   * @brief  �������������̹�����Կ��
   * @par    ˵����
   * �������������ڵĹ�����Կ�������ò�����
   * @param[in] icdev �豸��ʶ����
   * @param[in] keysetmain ����Կ��ţ���0x00��ʼ��š�
   * @param[in] keysetwork ������Կ��ţ���0x00��ʼ��š�
   * @param[in] enkeywork ������Կ���ݣ����ģ�������Կ���ܣ����̶�Ϊ16���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API SD_IFD_SetWorkKey(HANDLE icdev, unsigned char keysetmain, unsigned char keysetwork, unsigned char *enkeywork);

  /**
   * @brief  �������������̹�����Կ��
   * @par    ˵����
   * �������������̵�ǰʹ�õĹ�����Կ��
   * @param[in] icdev �豸��ʶ����
   * @param[in] keysetmain ����Կ��ţ���0x00��ʼ��š�
   * @param[in] keysetwork ������Կ��ţ���0x00��ʼ��š�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API SD_IFD_ActWorkKey(HANDLE icdev, unsigned char keysetmain, unsigned char keysetwork);

  /**
   * @brief  ��������������������볤�ȡ�
   * @par    ˵����
   * �������������������û������������󳤶ȡ�
   * @param[in] icdev �豸��ʶ����
   * @param[in] keylength ������󳤶ȣ�1~16����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API SD_IFD_SetKeyLength(HANDLE icdev, unsigned char keylength);

  /**
   * @brief  ��ȡ�����������������ݡ�
   * @par    ˵����
   * �����������̻�ȡ���İ������ݡ�
   * @param[in] icdev �豸��ʶ����
   * @param[out] szPasswd ���صİ������ݣ����ݸ�ʽΪ'\0'��β���ַ�����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���==0xA1��ʾȡ�����룬==0xA2��ʾ���볬ʱ��
   */
  short USER_API SD_IFD_GetPIN(HANDLE icdev, char *szPasswd);

  /**
   * @brief  ��ȡ�����������������ݡ�
   * @par    ˵����
   * �����������̻�ȡ���İ������ݡ�
   * @param[in] icdev �豸��ʶ����
   * @param[out] szPasswd ���صİ������ݣ�����Ϊ���ĵ�HEX��ʽ�ַ�����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���==0xA1��ʾȡ�����룬==0xA2��ʾ���볬ʱ��
   */
  short USER_API SD_IFD_GetEnPIN(HANDLE icdev, char *szPasswd);

  /**
   * @brief  ��ȡ�����������������ݡ�
   * @par    ˵����
   * �����������̻�ȡ���İ������ݡ�
   * @param[in] icdev �豸��ʶ����
   * @param[out] szPasswd ���صİ������ݣ����ݸ�ʽΪ'\0'��β���ַ�����
   * @param[in] yyflag ��ǡ�
   * @n 0x80 - �̵�����Һ����ʾ"��ӭʹ��"����������ʾ��
   * @n 0x81 - �̵�����Һ����ʾ"��������һ��"����������ʾ��
   * @n 0x82 - �̵�����Һ����ʾ"����������"����������ʾ��
   * @n 0x83 - �̵�����Һ������������������ʾ��
   * @n 0x84 - �̵�����Һ����ʾ"������ԭ����"����������ʾ��
   * @n 0x85 - �̵�����Һ����ʾ"������������"����������ʾ��
   * @n 0x86 - �̵�����Һ����ʾ"������������"����������ʾ��
   * @param[in] timeout �豸��ʱֵ����λΪ�롣
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���==0xA1��ʾȡ�����룬==0xA2��ʾ���볬ʱ��
   */
  short USER_API SD_IFD_GetPINPro(HANDLE icdev, char *szPasswd, unsigned char yyflag, unsigned char timeout);

  /**
   * @brief  ��ȡ�����������������ݡ�
   * @par    ˵����
   * �����������̻�ȡ���İ������ݡ�
   * @param[in] icdev �豸��ʶ����
   * @param[out] szPasswd ���صİ������ݣ����ݸ�ʽΪ'\0'��β���ַ�����
   * @param[in] yyflag ��ǡ�
   * @n 0x30 - ���������ʾ"����������"��������ʾ������������ʾ'*'��
   * @n 0x31 - ���������ʾ"��������һ��"��������ʾ������������ʾ'*'��
   * @n 0x32 - ���������ʾ"����������"����������ʾ������������ʾ'*'��
   * @n 0x33 - ���������ʾ"��������һ��"����������ʾ������������ʾ'*'��
   * @n 0x34 - ���������ʾ"����������"��������ʾ����������������ʾ��
   * @n 0x35 - ���������ʾ"��������һ��"��������ʾ����������������ʾ��
   * @n 0x36 - ���������ʾ"����������"����������ʾ����������������ʾ��
   * @n 0x37 - ���������ʾ"��������һ��"����������ʾ����������������ʾ��
   * @param[in] modeflag ģʽ��
   * @n 0x30 - ��"ȷ��"���򵽴�ָ����PIN���ȡ�
   * @n 0x31 - ��"ȷ��"����
   * @n 0x32 - ����ָ����PIN���ȡ�
   * @n 0x33 - ����ָ����PIN���Ȳ���"ȷ��"����
   * @param[in] timeout �豸��ʱֵ����λΪ�롣
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���==0xA1��ʾȡ�����룬==0xA2��ʾ���볬ʱ��
   */
  short USER_API SD_IFD_GetEnPINPro(HANDLE icdev, char *szPasswd, unsigned char yyflag, unsigned char modeflag, unsigned char timeout);

  /**
   * @brief  ��ȡ�����������������ݡ�
   * @par    ˵����
   * �����������̻�ȡANSI X9.8 PIN BLOCK���ܵİ������ݡ�
   * @param[in] icdev �豸��ʶ����
   * @param[out] szPasswd ���صİ������ݣ����ݸ�ʽΪ'\0'��β���ַ�����
   * @param[in] yyflag ��ǡ�
   * @n 0x30 - ���������ʾ"����������"��������ʾ������������ʾ'*'��
   * @n 0x31 - ���������ʾ"��������һ��"��������ʾ������������ʾ'*'��
   * @n 0x32 - ���������ʾ"����������"����������ʾ������������ʾ'*'��
   * @n 0x33 - ���������ʾ"��������һ��"����������ʾ������������ʾ'*'��
   * @n 0x34 - ���������ʾ"����������"��������ʾ����������������ʾ��
   * @n 0x35 - ���������ʾ"��������һ��"��������ʾ����������������ʾ��
   * @n 0x36 - ���������ʾ"����������"����������ʾ����������������ʾ��
   * @n 0x37 - ���������ʾ"��������һ��"����������ʾ����������������ʾ��
   * @param[in] modeflag ģʽ��
   * @n 0x30 - ��"ȷ��"���򵽴�ָ����PIN���ȡ�
   * @n 0x31 - ��"ȷ��"����
   * @n 0x32 - ����ָ����PIN���ȡ�
   * @n 0x33 - ����ָ����PIN���Ȳ���"ȷ��"����
   * @param[in] cardno ��ȡ��Ŀ��ţ��̶�Ϊ12���ֽڡ�
   * @param[in] timeout �豸��ʱֵ����λΪ�롣
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���==0xA1��ʾȡ�����룬==0xA2��ʾ���볬ʱ��
   */
  short USER_API SD_IFD_GetEnPINBlock(HANDLE icdev, char *szPasswd, unsigned char yyflag, unsigned char modeflag, unsigned char *cardno, unsigned char timeout);

  /**
   * @brief  ���������������㷨��
   * @par    ˵����
   * ��������������ʹ�õ��㷨��
   * @param[in] icdev �豸��ʶ����
   * @param[in] desmode ģʽ��0x01��ʾ��DES��0x02��ʾ��DES��
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API SD_IFD_SelecetDes(HANDLE icdev, unsigned char desmode);

  /**
   * @brief  ����������Һ����ʾ��
   * @par    ˵����
   * ��ʾָ���ַ��������������̵�Һ����Ļ�ϡ�
   * @param[in] icdev �豸��ʶ����
   * @param[in] line �кš�
   * @param[in] row ƫ�ơ�
   * @param[in] leddata Ҫ��ʾ���ַ�����
   * @param[in] timeout �豸��ʱֵ����λΪ�롣
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API SD_IFD_LEDDisplay(HANDLE icdev, unsigned char line, unsigned char row, unsigned char *leddata, unsigned char timeout);

  /**
   * @brief  �����������̹�����Կ�ӽ��ܡ�
   * @par    ˵����
   * ʹ�����������̵Ĺ�����Կ�������ݼӽ��ܲ�����
   * @param[in] icdev �豸��ʶ����
   * @param[in] mode ����ģʽ��0x00��ʾ���ܣ�0x01��ʾ���ܡ�
   * @param[in] srcdata �������ݣ�HEX��ʽ�ַ�����
   * @param[out] desdata ���ص����ݣ�HEX��ʽ�ַ�����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API SD_IFD_DES(HANDLE icdev, unsigned char mode, unsigned char *srcdata, unsigned char *desdata);

  /**
   * @brief  �����������̹�����Կ�ӽ��ܡ�
   * @par    ˵����
   * ʹ�����������̵Ĺ�����Կ�������ݼӽ��ܲ�����
   * @param[in] icdev �豸��ʶ����
   * @param[in] srclen �������ݵĳ��ȡ�
   * @param[in] srcdata �������ݡ�
   * @param[out] desdata ���ص����ݣ�HEX��ʽ�ַ�����
   * @param[in] flag ����ģʽ��0x00��ʾ���ܣ�0x01��ʾ���ܡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API SD_IFD_DesCaculate(HANDLE icdev, unsigned char srclen, unsigned char *srcdata, unsigned char *desdata, unsigned char flag);

  /**
   * @brief  �����������̹�����Կ��MAC��
   * @par    ˵����
   * ʹ�����������̵Ĺ�����Կ����������MAC������
   * @param[in] icdev �豸��ʶ����
   * @param[in] srclen �������ݵĳ��ȡ�
   * @param[in] srcdata �������ݡ�
   * @param[out] macdata ���ص�MAC�ַ����������ٷ���64���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API SD_IFD_CreateMac(HANDLE icdev, unsigned char srclen, unsigned char *srcdata, unsigned char *macdata);

  /**
   * @brief  �������֤��
   * @par    ˵����
   * �Զ�ȡ���ݷ�ʽ�����Ƿ������֤�����ڸ�Ӧ����
   * @param[in] icdev �豸��ʶ����
   * @return <0��ʾʧ�ܻ򲻴��ڣ�==0��ʾ���ڡ�
   */
  short USER_API dc_find_i_d(HANDLE icdev);

  /**
   * @brief  �������֤��
   * @par    ˵����
   * �Զ�ȡ״̬��ʽ�����Ƿ������֤�����ڸ�Ӧ����
   * @param[in] icdev �豸��ʶ����
   * @return <0��ʾʧ�ܻ򲻴��ڣ�==0��ʾ���ڡ�
   */
  short USER_API dc_find_i_d_2(HANDLE icdev);

  /**
   * @brief  �������֤��
   * @par    ˵����
   * ��Ѱ����ʽ�����Ƿ������֤�����ڸ�Ӧ����
   * @param[in] icdev �豸��ʶ����
   * @return <0��ʾʧ�ܻ򲻴��ڣ�==0��ʾ���ڡ�
   */
  short USER_API dc_find_i_d_speed(HANDLE icdev);

  /**
   * @brief  �����֤ԭʼ���ݡ�
   * @par    ˵����
   * ��ȡ���֤ģ�鷵�ص�ԭʼ���ݣ������������ֺ���Ƭ���ݡ�
   * @param[in] icdev �豸��ʶ����
   * @param[out] rdata ���ص����ݣ������ٷ���4096���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_get_i_d_raw_buffer(HANDLE icdev, unsigned char *rdata);

  /**
   * @brief  �����֤��
   * @par    ˵����
   * ��ȡ���֤ģ�鷵�ص�ԭʼ���ݣ������������ֺ���Ƭ���ݣ��ڲ������������ҷ�����Դ�����棬�ͷ���Դ��ʹ�� ::dc_end_i_d ��
   * @param[in] icdev �豸��ʶ����
   * @return <0��ʾʧ�ܣ�����Ϊ���֤��ʶ����
   */
  HANDLE USER_API dc_start_i_d(HANDLE icdev);

  /**
   * @brief  �����֤��
   * @par    ˵����
   * ��ȡ���֤ģ�鷵�ص�ԭʼ���ݣ������������֡���Ƭ��ָ�����ݣ��ڲ������������ҷ�����Դ�����棬�ͷ���Դ��ʹ�� ::dc_end_i_d ��
   * @param[in] icdev �豸��ʶ����
   * @return <0��ʾʧ�ܣ�����Ϊ���֤��ʶ����
   */
  HANDLE USER_API dc_start_i_d_2(HANDLE icdev);

  /**
   * @brief  ��ȡ������
   * @par    ˵����
   * ��ȡ�ڲ������������
   * @param[in] idhandle ���֤��ʶ����
   * @return ���ص������ַ�����
   */
  char *USER_API dc_i_d_query_name(HANDLE idhandle);

  /**
   * @brief  ��ȡ������
   * @par    ˵����
   * ��ȡ�ڲ������������
   * @param[in] idhandle ���֤��ʶ����
   * @param[out] name �����������ٷ���32���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_i_d_query_name_2(HANDLE idhandle, char *name);

  /**
   * @brief  ��ȡ�Ա�
   * @par    ˵����
   * ��ȡ�ڲ�������Ա�
   * @param[in] idhandle ���֤��ʶ����
   * @return ���ص��Ա��ַ�����
   */
  char *USER_API dc_i_d_query_sex(HANDLE idhandle);

  /**
   * @brief  ��ȡ�Ա�
   * @par    ˵����
   * ��ȡ�ڲ�������Ա�
   * @param[in] idhandle ���֤��ʶ����
   * @param[out] sex �Ա������ٷ���8���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_i_d_query_sex_2(HANDLE idhandle, char *sex);

  /**
   * @brief  ��ȡ���塣
   * @par    ˵����
   * ��ȡ�ڲ���������塣
   * @param[in] idhandle ���֤��ʶ����
   * @return ���ص������ַ�����
   */
  char *USER_API dc_i_d_query_nation(HANDLE idhandle);

  /**
   * @brief  ��ȡ���塣
   * @par    ˵����
   * ��ȡ�ڲ���������塣
   * @param[in] idhandle ���֤��ʶ����
   * @param[out] nation ���壬�����ٷ���32���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_i_d_query_nation_2(HANDLE idhandle, char *nation);

  /**
   * @brief  ��ȡ���ա�
   * @par    ˵����
   * ��ȡ�ڲ���������ա�
   * @param[in] idhandle ���֤��ʶ����
   * @return ���ص������ַ�����
   */
  char *USER_API dc_i_d_query_birth(HANDLE idhandle);

  /**
   * @brief  ��ȡ���ա�
   * @par    ˵����
   * ��ȡ�ڲ���������ա�
   * @param[in] idhandle ���֤��ʶ����
   * @param[out] birth ���գ������ٷ���16���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_i_d_query_birth_2(HANDLE idhandle, char *birth);

  /**
   * @brief  ��ȡסַ��
   * @par    ˵����
   * ��ȡ�ڲ������סַ��
   * @param[in] idhandle ���֤��ʶ����
   * @return ���ص�סַ�ַ�����
   */
  char *USER_API dc_i_d_query_address(HANDLE idhandle);

  /**
   * @brief  ��ȡסַ��
   * @par    ˵����
   * ��ȡ�ڲ������סַ��
   * @param[in] idhandle ���֤��ʶ����
   * @param[out] address סַ�������ٷ���128���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_i_d_query_address_2(HANDLE idhandle, char *address);

  /**
   * @brief  ��ȡ������ݺ��롣
   * @par    ˵����
   * ��ȡ�ڲ�����Ĺ�����ݺ��롣
   * @param[in] idhandle ���֤��ʶ����
   * @return ���صĹ�����ݺ����ַ�����
   */
  char *USER_API dc_i_d_query_id_number(HANDLE idhandle);

  /**
   * @brief  ��ȡ������ݺ��롣
   * @par    ˵����
   * ��ȡ�ڲ�����Ĺ�����ݺ��롣
   * @param[in] idhandle ���֤��ʶ����
   * @param[out] id_number ������ݺ��룬�����ٷ���32���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_i_d_query_id_number_2(HANDLE idhandle, char *id_number);

  /**
   * @brief  ��ȡǩ�����ء�
   * @par    ˵����
   * ��ȡ�ڲ������ǩ�����ء�
   * @param[in] idhandle ���֤��ʶ����
   * @return ���ص�ǩ�������ַ�����
   */
  char *USER_API dc_i_d_query_department(HANDLE idhandle);

  /**
   * @brief  ��ȡǩ�����ء�
   * @par    ˵����
   * ��ȡ�ڲ������ǩ�����ء�
   * @param[in] idhandle ���֤��ʶ����
   * @param[out] department ǩ�����أ������ٷ���32���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_i_d_query_department_2(HANDLE idhandle, char *department);

  /**
   * @brief  ��ȡ��Ч���ޡ�
   * @par    ˵����
   * ��ȡ�ڲ��������Ч���ޡ�
   * @param[in] idhandle ���֤��ʶ����
   * @return ���ص���Ч�����ַ�����
   */
  char *USER_API dc_i_d_query_expire_day(HANDLE idhandle);

  /**
   * @brief  ��ȡ��Ч���ޡ�
   * @par    ˵����
   * ��ȡ�ڲ��������Ч���ޡ�
   * @param[in] idhandle ���֤��ʶ����
   * @param[out] expire_day ��Ч���ޣ������ٷ���32���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_i_d_query_expire_day_2(HANDLE idhandle, char *expire_day);

  /**
   * @brief  ��ȡ��Ƭԭʼ���ݡ�
   * @par    ˵����
   * ��ȡ�ڲ��������Ƭԭʼ���ݣ���������Ҫͨ����������Ƭ�����������������Ƭͼ��
   * @param[in] idhandle ���֤��ʶ����
   * @return ���ص���Ƭԭʼ���ݣ�����ʵ�ʳ���ͨ������ ::dc_i_d_query_photo_len ����ȡ��
   */
  unsigned char *USER_API dc_i_d_query_photo(HANDLE idhandle);

  /**
   * @brief  ��ȡ��Ƭԭʼ���ݡ�
   * @par    ˵����
   * ��ȡ�ڲ��������Ƭԭʼ���ݣ���������Ҫͨ����������Ƭ�����������������Ƭͼ��
   * @param[in] idhandle ���֤��ʶ����
   * @param[out] photo ��Ƭԭʼ���ݣ������ٷ���4096���ֽڣ�����ʵ�ʳ���ͨ������ ::dc_i_d_query_photo_len ����ȡ��
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_i_d_query_photo_2(HANDLE idhandle, unsigned char *photo);

  /**
   * @brief  ��ȡ��Ƭԭʼ���ݳ��ȡ�
   * @par    ˵����
   * ��ȡ�ڲ��������Ƭԭʼ���ݵĳ��ȡ�
   * @param[in] idhandle ���֤��ʶ����
   * @return ���ص���Ƭԭʼ���ݳ��ȡ�
   */
  unsigned int USER_API dc_i_d_query_photo_len(HANDLE idhandle);

  /**
   * @brief  ������Ƭͼ���ļ���
   * @par    ˵����
   * ʹ���ڲ��������Ƭԭʼ���ݣ�ͨ�����ù�������Ƭ��������������Ƭͼ���ļ���
   * @param[in] idhandle ���֤��ʶ����
   * @param[in] FileName �ļ�������ȷ����д���Ȩ�ޡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_i_d_query_photo_file(HANDLE idhandle, const char *FileName);

  /**
   * @brief  ������Ƭͼ�����ݡ�
   * @par    ˵����
   * ʹ���ڲ��������Ƭԭʼ���ݣ�ͨ�����ù�������Ƭ��������������Ƭͼ�����ݡ�
   * @param[in] idhandle ���֤��ʶ����
   * @param[out] BmpBuffer ���ص���Ƭͼ�����ݣ������ٷ���65536���ֽڡ�
   * @param[in,out] BmpLength ���� @a BmpBuffer ������ֽ�����������Ƭͼ�����ݵĳ��ȡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_i_d_query_photo_bmp_buffer(HANDLE idhandle, unsigned char *BmpBuffer, unsigned int *BmpLength);

  /**
   * @brief  ��ȡָ��ԭʼ���ݡ�
   * @par    ˵����
   * ��ȡ�ڲ������ָ��ԭʼ���ݡ�
   * @param[in] idhandle ���֤��ʶ����
   * @return ���ص�ָ��ԭʼ���ݣ�����ʵ�ʳ���ͨ������ ::dc_i_d_query_finger_len ����ȡ��
   */
  unsigned char *USER_API dc_i_d_query_finger(HANDLE idhandle);

  /**
   * @brief  ��ȡָ��ԭʼ���ݡ�
   * @par    ˵����
   * ��ȡ�ڲ������ָ��ԭʼ���ݡ�
   * @param[in] idhandle ���֤��ʶ����
   * @param[out] finger ָ��ԭʼ���ݣ������ٷ���4096���ֽڣ�����ʵ�ʳ���ͨ������ ::dc_i_d_query_finger_len ����ȡ��
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_i_d_query_finger_2(HANDLE idhandle, unsigned char *finger);

  /**
   * @brief  ��ȡָ��ԭʼ���ݳ��ȡ�
   * @par    ˵����
   * ��ȡ�ڲ������ָ��ԭʼ���ݵĳ��ȡ�
   * @param[in] idhandle ���֤��ʶ����
   * @return ���ص�ָ��ԭʼ���ݳ��ȡ�
   */
  unsigned int USER_API dc_i_d_query_finger_len(HANDLE idhandle);

  /**
   * @brief  ������
   */
  short USER_API dc_i_d_query_finger_file(HANDLE idhandle, const char *FileName);

  /**
   * @brief  ������
   */
  short USER_API dc_i_d_query_finger_bmp_buffer(HANDLE idhandle, unsigned char *BmpBuffer, unsigned int *BmpLength);

  /**
   * @brief  �ͷŶ����֤��Դ��
   * @par    ˵����
   * �ͷ� ::dc_start_i_d ::dc_start_i_d_2 �������Դ��
   * @param[in] idhandle ���֤��ʶ����
   */
  void USER_API dc_end_i_d(HANDLE idhandle);

  /**
   * @brief  ��ȡ���֤UID��
   * @par    ˵����
   * ��ȡ���֤��Ψһ��ʶ������Ϊ8���ֽڡ�
   * @param[in] icdev �豸��ʶ����
   * @param[out] uid ���ص�UID���̶�Ϊ8���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_getuid_i_d(HANDLE icdev, unsigned char *uid);

  /**
   * @brief  LCD��ʾ��ά�롣
   * @par    ˵����
   * ���豸LCD��ʾ������ʾ��ά�롣
   * @param[in] icdev �豸��ʶ����
   * @param[in] point_x X��ƫ�Ƶ�����0~60����
   * @param[in] point_y Y��ƫ�Ƶ�����0~5����
   * @param[in] info �ı��ַ�����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_display_2dbarcode(HANDLE icdev, int point_x, int point_y, const char *info);

  /**
   * @brief  �����ָ֤�ơ�
   * @par    ˵����
   * ��ȡ���֤�е�ָ�����ݡ�
   * @param[in] icdev �豸��ʶ����
   * @param[out] length ����ָ�����ݵĳ��ȣ�����'\0'��
   * @param[out] data ���ص�ָ�����ݣ�HEX��ʽ�ַ�����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_getfingerdata(HANDLE icdev, int *length, unsigned char *data);

  /**
   * @brief  ��⿨Ƭλ�á�
   * @par    ˵����
   * ��⿨Ƭ���豸�е�λ�á�
   * @param[in] icdev �豸��ʶ����
   * @param[out] pos λ�á�
   * @n 0x01 - ������ʼλ��
   * @n 0x02 - ����ĩλ��
   * @n 0x03 - ������ס��
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���==1��ʾ�޿���
   */
  short USER_API dc_card_status2(HANDLE icdev, unsigned char *pos);

  /**
   * @brief  ������������
   * @par    ˵����
   * ������������
   * @param[in] icdev �豸��ʶ����
   * @param[in] flag ��ǣ�0x00��ʾ������0x01��ʾ������
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���==1��ʾ�޿���
   */
  short USER_API dc_card_make_and_lock(HANDLE icdev, unsigned char flag);

  /**
   * @brief  ���Ͷ��š�
   * @par    ˵����
   * ���Ͷ��Ÿ�ָ�����롣
   * @param[in] icdev �豸��ʶ����
   * @param[in] phone_no ���롣
   * @param[in] sms_content �������ݡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_send_sms(HANDLE icdev, const char *phone_no, const char *sms_content);

  /**
   * @brief  ָ��ģ��ͨѶ��
   * @par    ˵����
   * ��ָ��ģ�����ͨѶ������
   * @param[in] icdev �豸��ʶ����
   * @param[in] ctime �豸��ʱֵ����λΪ�롣
   * @param[in] request �������ݡ�
   * @param[in] request_len �������ݵĳ��ȡ�
   * @param[out] response ���ص����ݡ�
   * @param[out] response_len �������ݵĳ��ȡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_fingerprint_io_control(HANDLE icdev, unsigned char ctime, const unsigned char *request, int request_len, unsigned char *response, int *response_len);

  /**
   * @brief  ������
   */
  short USER_API dc_keypad_io_control(HANDLE icdev, unsigned char ctime, const unsigned char *request, int request_len, unsigned char *response, int *response_len);

  /**
   * @brief  ������
   */
  short USER_API dc_keypad_ImportKey(HANDLE icdev, unsigned char *check_value, unsigned char check_mode, int key_index, int use_key_index, unsigned char enable, const unsigned char *key, int key_len);

  /**
   * @brief  ������
   */
  short USER_API dc_keypad_DeleteKey(HANDLE icdev, int key_index);

  /**
   * @brief  ������
   */
  short USER_API dc_keypad_SetButtonMark(HANDLE icdev, unsigned int mark_value, unsigned char use);

  /**
   * @brief  ������
   */
  short USER_API dc_keypad_Start(HANDLE icdev, unsigned char mode, int max_len, unsigned char auto_end, unsigned char enable_sound);

  /**
   * @brief  ������
   */
  short USER_API dc_keypad_End(HANDLE icdev);

  /**
   * @brief  ������
   */
  short USER_API dc_keypad_GetPressed(HANDLE icdev, int time_ms, unsigned char *value);

  /**
   * @brief  ������
   */
  short USER_API dc_keypad_GetPinBlock(HANDLE icdev, unsigned char mode, int key_index, const unsigned char *customer_data, int customer_data_len, unsigned char *out_data, int *out_data_len);

  /**
   * @brief  ������
   */
  short USER_API dc_keypad_GetRandomValue(HANDLE icdev, int length, unsigned char *value);

  /**
   * @brief  ������
   */
  short USER_API dc_keypad_GetEncryptDataOfCBC(HANDLE icdev, unsigned char mode, int key_index, const unsigned char *in_data, int in_data_len, unsigned char *out_data, int *out_data_len);

  /**
   * @brief  ������
   */
  short USER_API dc_keypad_GetDecryptDataOfCBC(HANDLE icdev, unsigned char mode, int key_index, const unsigned char *in_data, int in_data_len, unsigned char *out_data, int *out_data_len);

  /**
   * @brief  ������
   */
  short USER_API dc_keypad_GetEncryptDataOfECB(HANDLE icdev, unsigned char mode, int key_index, const unsigned char *in_data, int in_data_len, unsigned char *out_data, int *out_data_len);

  /**
   * @brief  ������
   */
  short USER_API dc_keypad_GetDecryptDataOfECB(HANDLE icdev, unsigned char mode, int key_index, const unsigned char *in_data, int in_data_len, unsigned char *out_data, int *out_data_len);

  /**
   * @brief  ������
   */
  short USER_API dc_keypad_GetMACDataOfCBC(HANDLE icdev, unsigned char mode, int key_index, const unsigned char *in_data, int in_data_len, unsigned char *out_data, int *out_data_len);

  /**
   * @brief  ��ȡ�ǽӴ������͡�
   * @par    ˵����
   * ��ȡ��Ӧ���д��ڵķǽӴ������͡�
   * @param[in] icdev �豸��ʶ����
   * @return <0��ʾʧ�ܡ�
   * @n 0x00 - �޿���
   * @n 0x11 - Type A CPU Card��
   * @n 0x13 - Type A Mifare S50��
   * @n 0x14 - Type A Mifare S70��
   * @n 0x15 - Type A Mifare Ultralight��
   * @n 0x21 - Type B CPU Card��
   * @n 0x22 - Type B �洢����
   */
  short USER_API dc_RfGetCardType(HANDLE icdev);

  /**
   * @brief  ������
   */
  short USER_API dc_RfWaveControl(HANDLE icdev, unsigned char mode);

  /**
   * @brief  ������
   */
  short USER_API dc_RfReadChipRegister(HANDLE icdev, unsigned char *register_data);

  /**
   * @brief  ������
   */
  short USER_API dc_RfSetChipRegister(HANDLE icdev, unsigned char register_type, unsigned char register_value);

  /**
   * @brief  ��ȡ���֤UID��
   * @par    ˵����
   * ��ȡ���֤��Ψһ��ʶ������Ϊ8���ֽڡ�
   * @param[in] icdev �豸��ʶ����
   * @param[out] _Data ���ص�UID���̶�Ϊ8���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_get_idsnr(HANDLE icdev, unsigned char *_Data);

  /**
   * @brief  ��ȡ���֤UID��
   * @par    ˵����
   * ::dc_get_idsnr ��HEX��ʽ�ӿڣ����� @a _Data ΪHEX��ʽ��
   */
  short USER_API dc_get_idsnr_hex(HANDLE icdev, char *_Data);

  /**
   * @brief  �������ģ��ͨѶ��
   * @par    ˵����
   * ���������ģ�����ͨѶ������
   * @param[in] icdev �豸��ʶ����
   * @param[in] time_100ms �豸��ʱֵ����λΪ100���롣
   * @param[in] slen �������ݵĳ��ȡ�
   * @param[in] sdata �������ݡ�
   * @param[out] rlen �������ݵĳ��ȡ�
   * @param[out] rdata ���ص����ݡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_PinpadCommunication(HANDLE icdev, int time_100ms, int slen, const unsigned char *sdata, int *rlen, unsigned char *rdata);

  /**
   * @brief  ��Flash��
   * @par    ˵����
   * ��ȡ�豸�ڲ�Flash�е����ݣ������������ݱ���ȡ�
   * @param[in] icdev �豸��ʶ����
   * @param[in] offset ƫ�Ƶ�ַ��
   * @param[in] length ��ȡ���ȡ�
   * @param[out] data_buffer ���ص����ݡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_ReadFlash(HANDLE icdev, int offset, int length, unsigned char *data_buffer);

  /**
   * @brief  дFlash��
   * @par    ˵����
   * д�����ݵ��豸�ڲ�Flash�У������������ݱ���ȡ�
   * @param[in] icdev �豸��ʶ����
   * @param[in] offset ƫ�Ƶ�ַ��
   * @param[in] length д�볤�ȡ�
   * @param[in] data_buffer �������ݡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_WriteFlash(HANDLE icdev, int offset, int length, const unsigned char *data_buffer);

  /**
   * @brief  ��⿨λ��״̬��
   * @par    ˵����
   * ��⿨Ƭ��ǰ��λ��״̬��
   * @param[in] icdev �豸��ʶ����
   * @param[out] pos λ��״̬����Ϊ�������ֵ��λ����һ��
   * @n 0x00 - �޿���
   * @n 0x01 - �޿�������ǰ�ſڣ����п�λ�á�
   * @n 0x02 - �޿�������ǰ�ſڣ������п�λ�á�
   * @n 0x10 - �п������ɲ����κο���
   * @n 0x11 - �п����ɲ���������
   * @n 0x12 - �п����ɲ����Ӵ���
   * @n 0x14 - �п����ɲ����ǽӴ���
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_SelfServiceDeviceCardStatus(HANDLE icdev, unsigned char *pos);

  /**
   * @brief  ���뿨Ƭ��
   * @par    ˵����
   * ���뿨Ƭ������ǰ�豸���п������
   * @param[in] icdev �豸��ʶ����
   * @param[in] time_s �豸��ʱֵ����λΪ�롣
   * @param[in] mode ģʽ��
   * @n 0x00 - ǰ�˽���������������
   * @n 0x01 - ǰ�˽�������������
   * @n 0x02 - ��˽���������������
   * @n 0x03 - ��˽�������������
   * @return <0��ʾʧ�ܡ�
   * @n 0 - �����ɹ���
   * @n 1 - �豸�����п���
   * @n 2 - ���ճ�ʱ��
   * @n 3 - ���ſ�����
   * @n 4 - �������ó���
   * @n 5 - �쳣������������
   * @n 6 - �쳣�������豸�ڡ�
   */
  short USER_API dc_SelfServiceDeviceCardInject(HANDLE icdev, unsigned char time_s, unsigned char mode);

  /**
   * @brief  ������Ƭ��
   * @par    ˵����
   * ������Ƭ������ǰ�豸���޿������
   * @param[in] icdev �豸��ʶ����
   * @param[in] time_s �豸��ʱֵ����λΪ�롣
   * @param[in] mode ģʽ��
   * @n 0x00 - ����ǰ�˲��п���
   * @n 0x01 - ������ˡ�
   * @n 0x02 - ����ǰ�˲��п���
   * @return <0��ʾʧ�ܡ�
   * @n 0 - �����ɹ���
   * @n 1 - �豸��û�п���
   * @n 2 - ���ճ�ʱ��
   * @n 3 - �������ó���
   * @n 4 - ��Ƭ�ѵ�ǰ�żп�λ�ã��ɲ�����Ƭ��
   * @n 5 - ��Ƭ�ѵ�ǰ�Ų��п�λ�ã����ɲ�����Ƭ��
   */
  short USER_API dc_SelfServiceDeviceCardEject(HANDLE icdev, unsigned char time_s, unsigned char mode);

  /**
   * @brief  �ƶ���Ƭ��
   * @par    ˵����
   * �ƶ���Ƭ������ǰ�豸���޿������
   * @param[in] icdev �豸��ʶ����
   * @param[in] time_s �豸��ʱֵ����λΪ�롣
   * @param[in] mode ģʽ��
   * @n 0x00 - �ƶ�������������λ�á�
   * @n 0x01 - �ƶ����Ӵ�������λ�á�
   * @n 0x02 - �ƶ����ǽӴ�������λ�á�
   * @return <0��ʾʧ�ܡ�
   * @n 0 - �����ɹ���
   * @n 1 - �豸��û�п���
   * @n 2 - ���ճ�ʱ��
   * @n 3 - �������ó���
   * @n 4 - ��Ƭ�ѵ�ǰ�Ų��п�λ�ã����ɲ�����Ƭ��
   */
  short USER_API dc_SelfServiceDeviceCardMove(HANDLE icdev, unsigned char time_s, unsigned char mode);

  /**
   * @brief  ��ȡ������״̬��
   * @par    ˵����
   * ��ȡ�豸��������״̬��
   * @param[in] icdev �豸��ʶ����
   * @param[out] value ״ֵ̬��
   * @n bit0 - ��բ�ſ��ش�������0��ʾ�򿪣�1��ʾ�رա�
   * @n bit1 - ѹ����������0��ʾ���ѱ���ѹ��1��ʾ�޿���
   * @n bit2~bit7 - �ֱ��ʾ��ǰ�˵���˵Ĵ�������ÿ��������ֵ0��ʾ�п���ֵ1��ʾ�޿���
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���==1��ʾ�����޷�ʹ�á�
   */
  short USER_API dc_SelfServiceDeviceSensorStatus(HANDLE icdev, unsigned char *value);

  /**
   * @brief  ���õ���ģʽ��
   * @par    ˵����
   * ���õ���ģʽ��
   * @param[in] icdev �豸��ʶ����
   * @param[in] mode ģʽ��
   * @n 0x00 - ����ǰ�˲��п���
   * @n 0x01 - ������ˡ�
   * @n 0x02 - ����ǰ�˲��п���
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_SelfServiceDeviceConfig(HANDLE icdev, unsigned char mode);

  /**
   * @brief  ����ǰ�˽���ģʽ��
   * @par    ˵����
   * ����ǰ�˽���ģʽ��
   * @param[in] icdev �豸��ʶ����
   * @param[in] mode ģʽ��
   * @n 0x00 - ǰ�˽�ֹ������
   * @n 0x01 - ǰ�˴ſ���ʽ������
   * @n 0x02 - ǰ�˿��ط�ʽ������
   * @n 0x03 - ǰ�˴��źŷ�ʽ������
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_SelfServiceDeviceConfigFront(HANDLE icdev, unsigned char mode);

  /**
   * @brief  ���ú�˽���ģʽ��
   * @par    ˵����
   * ���ú�˽���ģʽ��
   * @param[in] icdev �豸��ʶ����
   * @param[in] mode ģʽ��
   * @n 0x00 - ��˽�ֹ������
   * @n 0x01 - ��˴ſ���ʽ������
   * @n 0x02 - ��˷Ǵſ���ʽ������
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_SelfServiceDeviceConfigBack(HANDLE icdev, unsigned char mode);

  /**
   * @brief  ����ͣ��λ�á�
   * @par    ˵����
   * ����ͣ��λ�á�
   * @param[in] icdev �豸��ʶ����
   * @param[in] mode ģʽ��
   * @n 0x00 - ǰ�˲��п���
   * @n 0x01 - ǰ�˼п���
   * @n 0x02 - �Ӵ�ʽIC��λ�á�
   * @n 0x03 - ��Ƶ��λ�á�
   * @n 0x04 - �ſ�λ�á�
   * @n 0x05 - ��������ˡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_SelfServiceDeviceConfigPlace(HANDLE icdev, unsigned char mode);

  /**
   * @brief  ��⿨���͡�
   * @par    ˵����
   * �豸���Զ��ƶ���Ƭ���Ҽ�⿨Ƭ���͡�
   * @param[in] icdev �豸��ʶ����
   * @return <0��ʾʧ�ܡ�
   * @n 0x00 - ��ʾ�޷���⵽��Ӧ��Ƭ��
   * @n 0x01 - ��ʾ�豸���޿���
   * @n 0x11 - ��ʾType A CPU Card��
   * @n 0x13 - ��ʾType A Mifare S50��
   * @n 0x14 - ��ʾType A Mifare S70��
   * @n 0x15 - ��ʾType A Mifare Ultralight��
   * @n 0x21 - ��ʾType B CPU Card��
   * @n 0x22 - ��ʾType B �洢����
   * @n 0x31 - ��ʾ�Ӵ�T=0 CPU Card��
   * @n 0x32 - ��ʾ�Ӵ�T=1 CPU Card��
   * @n 0x41 - ��ʾ4442 Card��
   * @n 0x42 - ��ʾ4428 Card��
   */
  short USER_API dc_SelfServiceDeviceCheckCardType(HANDLE icdev);

  /**
   * @brief  ��λ�����豸��
   * @par    ˵����
   * ʹ�����豸�����ϵ��ʼ״̬���������ò���Ϊȱʡ������
   * @param[in] icdev �豸��ʶ����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_SelfServiceDeviceReset(HANDLE icdev);

  /**
   * @brief  ���࿨״̬��
   * @par    ˵����
   * �ж��Ƿ�Ϊ���ſ����Ƿ�ΪType A��Type B����
   * @param[in] icdev �豸��ʶ����
   * @param[out] type �����ͣ�0x0A��ʾType A����0x0B��ʾType B����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���==1��ʾ�޿���==2��ʾ���ڶ��ſ���
   */
  short USER_API dc_MulticardStatus(HANDLE icdev, unsigned char *type);

  /**
   * @brief  ��ȡ�������ֵ��
   * @par    ˵����
   * ��ȡ�豸���̵İ���ֵ��ÿ�ε��ÿ��Ի�ȡ�������ֵ��
   * @param[in] icdev �豸��ʶ����
   * @param[in] ctime �豸��ʱֵ����λΪ�롣
   * @param[out] rlen ���ذ������ݵĳ��ȣ�����'\0'��
   * @param[out] cpass ���صİ������ݣ����ݸ�ʽΪ'\0'��β���ַ�����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���==0xA1��ʾȡ�����룬==0xA2��ʾ���볬ʱ��
   */
  short USER_API dc_pass_key_value2(HANDLE icdev, unsigned char ctime, unsigned char *rlen, unsigned char *cpass);

  /**
   * @brief  ���ⲿEEPROM��
   * @par    ˵����
   * ��ȡ�豸�ⲿEEPROM�е����ݣ������������ݱ���ȡ�
   * @param[in] icdev �豸��ʶ����
   * @param[in] offset ƫ�Ƶ�ַ��
   * @param[in] length ��ȡ���ȡ�
   * @param[out] data_buffer ���ص����ݡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_ReadOutEeprom(HANDLE icdev, int offset, int length, unsigned char *data_buffer);

  /**
   * @brief  д�ⲿEEPROM��
   * @par    ˵����
   * д�����ݵ��豸�ⲿEEPROM�У������������ݱ���ȡ�
   * @param[in] icdev �豸��ʶ����
   * @param[in] offset ƫ�Ƶ�ַ��
   * @param[in] length д�볤�ȡ�
   * @param[in] data_buffer �������ݡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_WriteOutEeprom(HANDLE icdev, int offset, int length, const unsigned char *data_buffer);

  /**
   * @brief  ��ID����
   * @par    ˵����
   * ��ȡID�����ݡ�
   * @param[in] icdev �豸��ʶ����
   * @param[in] time_ms �豸��ʱֵ����λΪ���롣
   * @param[out] rlen �������ݵĳ��ȡ�
   * @param[out] rdata ���ص����ݡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_ReadIdCardInfo(HANDLE icdev, int time_ms, int *rlen, unsigned char *rdata);

  /**
   * @brief  ������
   */
  short USER_API dc_cpy_getkey(HANDLE icdev, unsigned char *respkey, int *resplen);

  /**
   * @brief  ������
   */
  short USER_API dc_cpy_setkey(HANDLE icdev, unsigned char *genkey, int keylen);

  /**
   * @brief  ������
   */
  short USER_API dc_cpy_cpuapdu(HANDLE icdev, unsigned char slen, unsigned char *sendbuffer, unsigned char *rlen, unsigned char *databuffer);

  /**
   * @brief  ������
   */
  short USER_API dc_cpy_cpuapdu_hex(HANDLE icdev, unsigned char slen, char *sendbuffer, unsigned char *rlen, char *databuffer);

  /**
   * @brief  ������
   */
  short USER_API dc_cpy_cpuapduInt(HANDLE icdev, unsigned int slen, unsigned char *sendbuffer, unsigned int *rlen, unsigned char *databuffer);

  /**
   * @brief  ������
   */
  short USER_API dc_cpy_cpuapduInt_hex(HANDLE icdev, unsigned int slen, char *sendbuffer, unsigned int *rlen, char *databuffer);

  /**
   * @brief  ������
   */
  short USER_API dc_cpy_procommand(HANDLE icdev, unsigned char slen, unsigned char *sendbuffer, unsigned char *rlen, unsigned char *databuffer, unsigned char timeout);

  /**
   * @brief  ������
   */
  short USER_API dc_cpy_procommand_hex(HANDLE icdev, unsigned char slen, char *sendbuffer, unsigned char *rlen, char *databuffer, unsigned char timeout);

  /**
   * @brief  ������
   */
  short USER_API dc_cpy_procommandInt(HANDLE icdev, unsigned int slen, unsigned char *sendbuffer, unsigned int *rlen, unsigned char *databuffer, unsigned char timeout);

  /**
   * @brief  ������
   */
  short USER_API dc_cpy_procommandInt_hex(HANDLE icdev, unsigned int slen, char *sendbuffer, unsigned int *rlen, char *databuffer, unsigned char timeout);

  /**
   * @brief  �ǽӴ�ʽCPU��ָ�����
   * @par    ˵����
   * �Ը�Ӧ��CPU������ָ���������ע��˽ӿ��ѷ�װ��Э�鲿�֡�
   * @param[in] icdev �豸��ʶ����
   * @param[in] slen �������ݵĳ��ȡ�
   * @param[in] sendbuffer �������ݡ�
   * @param[out] rlen �������ݵĳ��ȡ�
   * @param[out] databuffer ���ص����ݡ�
   * @param[in] timeout ��ʱֵ����ֵֻ�ڲ����豸�ĵײ�ʹ�ã���λΪ250���룬һ����ý���ֵΪ7��
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_procommandInt(HANDLE icdev, unsigned int slen, unsigned char *sendbuffer, unsigned int *rlen, unsigned char *databuffer, unsigned char timeout);

  /**
   * @brief  �ǽӴ�ʽCPU��ָ�����
   * @par    ˵����
   * ::dc_procommandInt ��HEX��ʽ�ӿڣ����� @a sendbuffer @a databuffer ΪHEX��ʽ��
   */
  short USER_API dc_procommandInt_hex(HANDLE icdev, unsigned int slen, char *sendbuffer, unsigned int *rlen, char *databuffer, unsigned char timeout);

  /**
   * @brief  ������
   */
  short USER_API dc_ReadRfCfgReg(HANDLE icdev, int type, int number, int *value);

  /**
   * @brief  ������
   */
  short USER_API dc_WriteRfCfgReg(HANDLE icdev, int type, int number, int value);

  /**
   * @brief  ��ʼ��NFC��
   * @par    ˵����
   * �л���Ƶ��NFC��Ե�ģʽ������NFC��Ե�ģʽ֮ǰ����ʹ�ô˽ӿڽ��г�ʼ����
   * @param[in] icdev �豸��ʶ����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_NfcInit(HANDLE icdev);

  /**
   * @brief  ����NFC��
   * @par    ˵����
   * ѰNFC��������NFC���Զ����ӣ�������ATR���ݡ�
   * @param[in] icdev �豸��ʶ����
   * @param[out] atr ���ص����ݡ�
   * @param[out] atr_len �������ݵĳ��ȡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_NfcActivate(HANDLE icdev, unsigned char *atr, int *atr_len);

  /**
   * @brief  �Ͽ�NFC��
   * @par    ˵����
   * �Ͽ����Ӳ��ر����ߣ����ô˽ӿڱ����ȼ���NFC��
   * @param[in] icdev �豸��ʶ����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_NfcDeactivate(HANDLE icdev);

  /**
   * @brief  NFC��Ե�����͸�������ͷ���ˣ���
   * @par    ˵����
   * �������ݵ�NFC�ֻ������ô˽ӿڱ����ȼ���NFC��
   * @param[in] icdev �豸��ʶ����
   * @param[in] request �������ݡ�
   * @param[in] request_len �������ݵĳ��ȡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_NfcPush(HANDLE icdev, const unsigned char *request, int request_len);

  /**
   * @brief  NFC��Ե�����͸�����ӷ���˽��գ���
   * @par    ˵����
   * ���ý���ģʽ�������󽫽���׼������NFC�ֻ����ݵ�ģʽ�����ô˽ӿ����뼤��NFC��
   * @param[in] icdev �豸��ʶ����
   * @param[in] flag ��ǣ�0��ʾ�رգ�1��ʾ������
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_NfcService(HANDLE icdev, int flag);

  /**
   * @brief  ����NFC�ֻ����ݡ�
   * @par    ˵����
   * �豸�������ģʽ�󣬿���ʹ�ô˽ӿ�������NFC�ֻ������ݡ�
   * @param[in] icdev �豸��ʶ����
   * @param[out] response ���ص����ݡ�
   * @param[out] response_len �������ݵĳ��ȡ�
   * @param[in] time_ms �ӿڳ�ʱֵ����λΪ�롣
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���==1��ʾ�ֻ����ڸ�Ӧ����==2��ʾ������Ҫ���´��ݡ�
   */
  short USER_API dc_NfcFetch(HANDLE icdev, unsigned char *response, int *response_len, int time_ms);

  /**
   * @brief  NFC��Ե�����͸�����ӷ���˽��գ���
   * @par    ˵����
   * ���ý���ģʽ�������󽫽���׼������NFC�ֻ����ݵ�ģʽ�����ô˽ӿ����뼤��NFC��
   * @param[in] icdev �豸��ʶ����
   * @param[in] mode ģʽ��0��ʾ�رգ�1��ʾ������
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_NfcSimulateCardConfig(HANDLE icdev, int mode);

  /**
   * @brief  �����������Զ��ϴ�����ģʽ���á�
   * @par    ˵����
   * �����������Զ��ϴ�����ģʽ���á�
   * @param[in] icdev �豸��ʶ����
   * @param[in] mode ģʽ��
   * @n 0 - ����������������ĸ����ĸת��Ϊ��д��ĸ��
   * @n 1 - ���������ԭʼ���ݣ�Ĭ�ϣ���
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_MagFormatConfig(HANDLE icdev, int mode);

  /**
   * @brief  ��ȡͨѶģ��MAC��ַ��
   * @par    ˵����
   * ��ȡͨѶģ��MAC��ַ��
   * @param[in] icdev �豸��ʶ����
   * @param[in] type ģ�����ͣ�1��ʾ����ģ�飬2��ʾWIFIģ�飬3��ʾGPRS/CDMA/ȫ��ͨ��ģ�顣
   * @param[out] value ���ص�MAC��ַ�����ݸ�ʽΪ'\0'��β���ַ�����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_ReadModuleMacAddress(HANDLE icdev, int type, char *value);

  /**
   * @brief  ����ͨѶģ��MAC��ַ��
   * @par    ˵����
   * ����ͨѶģ��MAC��ַ��
   * @param[in] icdev �豸��ʶ����
   * @param[in] type ģ�����ͣ�1��ʾ����ģ�飬2��ʾWIFIģ�飬3��ʾGPRS/CDMA/ȫ��ͨ��ģ�顣
   * @param[in] value ����MAC��ַ�����ݸ�ʽΪ'\0'��β���ַ�����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_WriteModuleMacAddress(HANDLE icdev, int type, const char *value);

  /**
   * @brief  ��ȡATS���ݡ�
   * @par    ˵����
   * ��ȡType A��Type B����ATS���˽ӿڱ����ڿ�Ƭ�����ſ�ʹ�á�
   * @param[in] icdev �豸��ʶ����
   * @param[out] ats_len ����ATS���ݵĳ��ȡ�
   * @param[out] ats ���ص�ATS���ݡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_ReadRfTypeABATS(HANDLE icdev, int *ats_len, unsigned char *ats);

  /**
   * @brief  ��ȡATS���ݡ�
   * @par    ˵����
   * ::dc_ReadRfTypeABATS ��HEX��ʽ�ӿڣ����� @a ats ΪHEX��ʽ��
   */
  short USER_API dc_ReadRfTypeABATS_hex(HANDLE icdev, int *ats_len, char *ats);

  /**
   * @brief  ������
   */
  short USER_API dc_RfFormatConfig(HANDLE icdev, int mode, int block_number, int offset, int length);

  /**
   * @brief  Flash����������
   * @par    ˵����
   * ����Flash�����е����ݡ�
   * @param[in] icdev �豸��ʶ����
   * @param[in] sector ������ַ��0xFFFF��ʾ����ȫ����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_FlashErase(HANDLE icdev, int sector);

  /**
   * @brief  �豸������
   * @par    ˵����
   * �豸����������ָ���������з������ӿڱ����ֱ�ӷ��أ�������ȴ�������������ɡ�
   * @param[in] icdev �豸��ʶ����
   * @param[in] beep_time_ms ���η���ʱ�䣬��λΪ���롣
   * @param[in] interval_time_ms ���ʱ�䣬��λΪ���롣
   * @param[in] count ��������������0x0000��ʾֹͣ��0xFFFF��ʾ���޴Ρ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_BuzzerBeep(HANDLE icdev, unsigned short beep_time_ms, unsigned short interval_time_ms, unsigned short count);

  /**
   * @brief  ����ģʽ���á�
   * @par    ˵����
   * ��������ģ���ͨѶģʽ��
   * @param[in] icdev �豸��ʶ����
   * @param[in] mode ģʽ��0x00��ʾ����ģʽ��ATָ���EEPROM��д����0x01��ʾ����ģʽ��
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_BtModeControl(HANDLE icdev, unsigned char mode);

  /**
   * @brief  ���������ʲ�ѯ/���á�
   * @par    ˵����
   * ��ѯ/��������ģ���ͨѶ�����ʣ��޸ĵ�������ģ��ˡ�
   * @param[in] icdev �豸��ʶ����
   * @param[in] flag ��ǣ�0x00��ʾ��ѯ��0x01��ʾ���á�
   * @param[in,out] value �����ʡ�
   * @n 0x00 - 9600��
   * @n 0x01 - 19200��
   * @n 0x02 - 38400��
   * @n 0x03 - 57600��
   * @n 0x04 - 115200��
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_BtBaudrateControl(HANDLE icdev, unsigned char flag, unsigned char *value);

  /**
   * @brief  �������������ѯ/���á�
   * @par    ˵����
   * ��ѯ/��������ģ����������롣
   * @param[in] icdev �豸��ʶ����
   * @param[in] flag ��ǣ�0x00��ʾ��ѯ��0x01��ʾ���á�
   * @param[in,out] value �����ַ�������ѯʱ�����ٷ���64���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_BtPasswordControl(HANDLE icdev, unsigned char flag, char *value);

  /**
   * @brief  ����ģ���ַ��ѯ/���á�
   * @par    ˵����
   * ��ѯ/��������ģ��ĵ�ַ��
   * @param[in] icdev �豸��ʶ����
   * @param[in] flag ��ǣ�0x00��ʾ��ѯ��0x01��ʾ���á�
   * @param[in,out] length ��ַ�ĳ��ȡ�
   * @param[in,out] value ��ַ����ѯʱ�����ٷ���64���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_BtAddressControl(HANDLE icdev, unsigned char flag, unsigned char *length, unsigned char *value);

  /**
   * @brief  ����ģ�����Ʋ�ѯ/���á�
   * @par    ˵����
   * ��ѯ/��������ģ������ơ�
   * @param[in] icdev �豸��ʶ����
   * @param[in] flag ��ǣ�0x00��ʾ��ѯ��0x01��ʾ���á�
   * @param[in,out] value �����ַ�������ѯʱ�����ٷ���64���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_BtNameControl(HANDLE icdev, unsigned char flag, char *value);

  /**
   * @brief  �����û��Զ�����������
   * @par    ˵����
   * ���ö�дEEPROM��ʽ��������ģ����Զ������á�
   * @param[in] icdev �豸��ʶ����
   * @param[in] flag ��ǣ�0x00��ʾ��EEPROM��0x01��ʾдEEPROM��ATָ�ģʽ��
   * @param[in] offset ƫ�Ƶ�ַ��
   * @param[in] length ���ݵĳ��ȡ�
   * @param[in,out] value ���ݡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_BtUserControl(HANDLE icdev, unsigned char flag, int offset, int length, unsigned char *value);

  /**
   * @brief  ���������λ��
   * @par    ˵����
   * ������ģ����������λ��
   * @param[in] icdev �豸��ʶ����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_BtReset(HANDLE icdev);

  /**
   * @brief  ����ģ��ͨѶ���ԡ�
   * @par    ˵����
   * ����ģ��������ͨѶģʽ�£��ô˽ӿڿ��Բ�������ͨѶ�Ƿ�ͨ�������ݷ��ͳɹ��󣬼����ش����Ƿ��н��յ����������ж�ͨѶ�Ƿ�ɹ���
   * @param[in] icdev �豸��ʶ����
   * @param[in] length �������ݵĳ��ȡ�
   * @param[in] value �������ݡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_BtCommunicationTest(HANDLE icdev, int length, const unsigned char *value);

  /**
   * @brief  ���������ʲ�ѯ/���á�
   * @par    ˵����
   * ��ѯ/����������ģ��֮���ͨѶ�����ʣ��޸ĵ����豸�ˡ�
   * @param[in] icdev �豸��ʶ����
   * @param[in] flag ��ǣ�0x00��ʾ��ѯ��0x01��ʾ���á�
   * @param[in,out] value �����ʡ�
   * @n 0x00 - 2400��
   * @n 0x01 - 4800��
   * @n 0x02 - 9600��
   * @n 0x03 - 14400��
   * @n 0x04 - 38400��
   * @n 0x05 - 57600��
   * @n 0x06 - 115200��
   * @n 0x07 - 256000��
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_BtWithReaderBaudrateControl(HANDLE icdev, unsigned char flag, unsigned char *value);

  /**
   * @brief  ����ģ��ͨѶ��
   * @par    ˵����
   * ������ģ�����ͨѶ������
   * @param[in] icdev �豸��ʶ����
   * @param[in] slen �������ݵĳ��ȡ�
   * @param[in] sdata �������ݡ�
   * @param[out] rlen �������ݵĳ��ȡ�
   * @param[out] rdata ���ص����ݡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_BtCommand(HANDLE icdev, int slen, const unsigned char *sdata, int *rlen, unsigned char *rdata);

  /**
   * @brief  ��ȡ�����ź�ǿ�ȡ�
   * @par    ˵����
   * ��ȡ�����ź�ǿ�ȡ�
   * @param[in] icdev �豸��ʶ����
   * @param[out] state ״̬��0x00��ʾ����δ���ӣ�0x01��ʾ���������ӡ�
   * @param[out] value �ź�ֵ��
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_BtSignalStrength(HANDLE icdev, unsigned char *state, short *value);

  /**
   * @brief  ��ȡ������Ӧ��
   * @par    ˵����
   * ��ȡ����ģ�鵱ǰִ���������Ӧ�����ݡ�
   * @param[in] icdev �豸��ʶ����
   * @param[out] length �������ݵĳ��ȡ�
   * @param[out] value ���ص����ݡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_BtDataResponse(HANDLE icdev, int *length, unsigned char *value);

  /**
   * @brief  ��������͸����
   * @par    ˵����
   * �˽ӿ����ڽ����������յ�������͸���������У������ش�������յ����ݡ�
   * @param[in] icdev �豸��ʶ����
   * @param[in] slen �������ݵĳ��ȡ�
   * @param[in] sdata �������ݡ�
   * @param[out] rlen �������ݵĳ��ȡ�
   * @param[out] rdata ���ص����ݡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_BtDataTransmit(HANDLE icdev, int slen, const unsigned char *sdata, int *rlen, unsigned char *rdata);

  /**
   * @brief  SAM_Aģ��ָ�����
   * @par    ˵����
   * �˽ӿ����ڲ����������֤��֤��ȫ����ģ�顣
   * @param[in] icdev �豸��ʶ����
   * @param[in] code ָ����롣
   * @n 0x10FF - ��λSAM_A���޷������ݣ��޷������ݡ�
   * @n 0x11FF - SAM_A״̬��⣬�޷������ݣ��޷������ݡ�
   * @n 0x12FF - ��SAM_A������Ϣ���޷������ݣ���������Ϊ16���ֽڵ�SAM_A��š�
   * @n 0x2001 - Ѱ�Ҿ������֤���޷������ݣ���������Ϊ4���ֽڵ�0x00��
   * @n 0x2002 - ѡȡ�������֤���޷������ݣ���������Ϊ8���ֽڵ�0x00��
   * @n 0x3001 - ������������Ϣ����Ƭ��Ϣ���޷������ݣ��������ݸ�ʽΪ����2���ֽ�������Ϣ���ȣ�Big-Endian������2���ֽ���Ƭ��Ϣ���ȣ�Big-Endian������������Ϣ��������256���ֽڣ�������Ƭ��Ϣ��������1024���ֽڣ�����
   * @n 0x3010 - ������������Ϣ����Ƭ��Ϣ��ָ����Ϣ���޷������ݣ��������ݸ�ʽΪ����2���ֽ�������Ϣ���ȣ�Big-Endian������2���ֽ���Ƭ��Ϣ���ȣ�Big-Endian������2���ֽ�ָ����Ϣ���ȣ�Big-Endian������������Ϣ��������256���ֽڣ�������Ƭ��Ϣ��������1024���ֽڣ�����ָ����Ϣ��������1024���ֽڣ�����
   * @n 0x3003 - ��׷��סַ��Ϣ���޷������ݣ���������Ϊ70���ֽڵ�׷��סַ��Ϣ��
   * @n 0x6000 - ����UART�ӿ����ʣ�����Ϊ115200bps���޷������ݣ��޷������ݡ�
   * @n 0x6001 - ����UART�ӿ����ʣ�����Ϊ57600bps���޷������ݣ��޷������ݡ�
   * @n 0x6002 - ����UART�ӿ����ʣ�����Ϊ38400bps���޷������ݣ��޷������ݡ�
   * @n 0x6003 - ����UART�ӿ����ʣ�����Ϊ19200bps���޷������ݣ��޷������ݡ�
   * @n 0x6004 - ����UART�ӿ����ʣ�����Ϊ9600bps���޷������ݣ��޷������ݡ�
   * @n 0x61FF - ����SAM_A����Ƶģ��һ֡ͨ�����ݵ�����ֽ�������������Ϊ1���ֽڵ�����ֽ�����ȡֵ����Ϊ0x18~0xFF��Ĭ��ֵΪ0x58���޷������ݡ�
   * @param[in] slen �������ݵĳ��ȡ�
   * @param[in] sdata �������ݡ�
   * @param[out] rlen �������ݵĳ��ȡ�
   * @param[out] rdata ���ص����ݣ������ٷ���4096���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_SamAControl(HANDLE icdev, int code, int slen, const unsigned char *sdata, int *rlen, unsigned char *rdata);

  /**
   * @brief  �����֤��
   * @par    ˵����
   * ��ȡ���֤��ԭʼ��Ϣ���ݡ�
   * @param[in] icdev �豸��ʶ����
   * @param[in] type ���͡�
   * @n 1 - ��ȡ������Ϣ����Ƭ��Ϣ��ָ����Ϣ��
   * @n 2 - ��ȡ׷��סַ��Ϣ��
   * @n 3 - ��ȡ������Ϣ����Ƭ��Ϣ��ָ����Ϣ��׷��סַ��Ϣ��
   * @param[out] text_len ����������Ϣ�ĳ��ȡ�
   * @param[out] text ���ص�������Ϣ�������ٷ���256���ֽڡ�
   * @param[out] photo_len ������Ƭ��Ϣ�ĳ��ȡ�
   * @param[out] photo ���ص���Ƭ��Ϣ�������ٷ���1024���ֽڡ�
   * @param[out] fingerprint_len ����ָ����Ϣ�ĳ��ȡ�
   * @param[out] fingerprint ���ص�ָ����Ϣ�������ٷ���1024���ֽڡ�
   * @param[out] extra_len ����׷��סַ��Ϣ�ĳ��ȡ�
   * @param[out] extra ���ص�׷��סַ��Ϣ�������ٷ���70���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_SamAReadCardInfo(HANDLE icdev, int type, int *text_len, unsigned char *text, int *photo_len, unsigned char *photo, int *fingerprint_len, unsigned char *fingerprint, int *extra_len, unsigned char *extra);

  /**
   * @brief  ����������Ϣ��
   * @par    ˵����
   * �����й��˾������֤������Ϣ����ȡ��Ӧ����Ŀ��
   * @param[in] icdev �豸��ʶ����
   * @param[in] charset ��ȡ��Ŀ�����õ��ַ�����0��ʾGBK��1��ʾUCS-2��
   * @param[in] info_len ������Ϣ�ĳ��ȡ�
   * @param[in] info ������Ϣ��
   * @param[out] name �����������ٷ���64���ֽڡ�
   * @param[out] sex �Ա������ٷ���8���ֽڡ�
   * @param[out] nation ���壬�����ٷ���12���ֽڡ�
   * @param[out] birth_day �������ڣ������ٷ���36���ֽڡ�
   * @param[out] address סַ�������ٷ���144���ֽڡ�
   * @param[out] id_number ������ݺ��룬�����ٷ���76���ֽڡ�
   * @param[out] department ǩ�����أ������ٷ���64���ֽڡ�
   * @param[out] expire_start_day ֤��ǩ�����ڣ������ٷ���36���ֽڡ�
   * @param[out] expire_end_day ֤����ֹ���ڣ������ٷ���36���ֽڡ�
   * @param[out] reserved Ԥ��������ٷ���76���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_ParseTextInfo(HANDLE icdev, int charset, int info_len, const unsigned char *info, unsigned char *name, unsigned char *sex, unsigned char *nation, unsigned char *birth_day, unsigned char *address, unsigned char *id_number, unsigned char *department, unsigned char *expire_start_day, unsigned char *expire_end_day, unsigned char *reserved);

  /**
   * @brief  ����������Ϣ��
   * @par    ˵����
   * ������������þ���֤������Ϣ����ȡ��Ӧ����Ŀ��
   * @param[in] icdev �豸��ʶ����
   * @param[in] charset ��ȡ��Ŀ�����õ��ַ�����0��ʾGBK��1��ʾUCS-2��
   * @param[in] info_len ������Ϣ�ĳ��ȡ�
   * @param[in] info ������Ϣ��
   * @param[out] english_name Ӣ�������������ٷ���244���ֽڡ�
   * @param[out] sex �Ա������ٷ���8���ֽڡ�
   * @param[out] id_number ���þ���֤���룬�����ٷ���64���ֽڡ�
   * @param[out] citizenship ���������ڵ������룬�����ٷ���16���ֽڡ�
   * @param[out] chinese_name ���������������ٷ���64���ֽڡ�
   * @param[out] expire_start_day ֤��ǩ�����ڣ������ٷ���36���ֽڡ�
   * @param[out] expire_end_day ֤����ֹ���ڣ������ٷ���36���ֽڡ�
   * @param[out] birth_day �������ڣ������ٷ���36���ֽڡ�
   * @param[out] version_number ֤���汾�ţ������ٷ���12���ֽڡ�
   * @param[out] department_code ��������������ش��룬�����ٷ���20���ֽڡ�
   * @param[out] type_sign ֤�����ͱ�ʶ�������ٷ���8���ֽڡ�
   * @param[out] reserved Ԥ��������ٷ���16���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_ParseTextInfoForForeigner(HANDLE icdev, int charset, int info_len, const unsigned char *info, unsigned char *english_name, unsigned char *sex, unsigned char *id_number, unsigned char *citizenship, unsigned char *chinese_name, unsigned char *expire_start_day, unsigned char *expire_end_day, unsigned char *birth_day, unsigned char *version_number, unsigned char *department_code, unsigned char *type_sign, unsigned char *reserved);

  /**
   * @brief  ������Ƭ��Ϣ��
   * @par    ˵����
   * ������Ƭ��Ϣ��ͨ����������Ƭ����⻹ԭ��Ƭͼ�����ݡ�
   * @param[in] icdev �豸��ʶ����
   * @param[in] type ��Ƭͼ�����ݵĸ�ʽ��0��ʾBMP�ļ���1��ʾBMP���棬2��ʾBMP Base64�ַ�����
   * @param[in] info_len ��Ƭ��Ϣ�ĳ��ȡ�
   * @param[in] info ��Ƭ��Ϣ��
   * @param[in,out] photo_len ���ݵĳ��ȡ�
   * @n BMP�ļ� - ��Ч��
   * @n BMP���� - ���� @a photo ������ֽ�����������Ƭͼ�����ݵĳ��ȡ�
   * @n BMP Base64�ַ��� - ���� @a photo ������ֽ�����������Ƭͼ������Base64�ַ����ĳ��ȣ�����'\0'��
   * @param[in,out] photo ���ݡ�
   * @n BMP�ļ� - �����ļ�������ȷ����д���Ȩ�ޡ�
   * @n BMP���� - ���ص���Ƭͼ�����ݣ������ٷ���65536���ֽڡ�
   * @n BMP Base64�ַ��� - ���ص���Ƭͼ������Base64�ַ����������ٷ���65536���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_ParsePhotoInfo(HANDLE icdev, int type, int info_len, const unsigned char *info, int *photo_len, unsigned char *photo);

  /**
   * @brief  ����������Ϣ��
   * @par    ˵����
   * ����������Ϣ��
   * @param[in] icdev �豸��ʶ����
   * @param[in] flag ��־��0��ʾ�Ա�1��ʾ���壬2��ʾ������
   * @param[in] in_info ������Ϣ��
   * @param[out] out_info ���ص���Ϣ��
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_ParseOtherInfo(HANDLE icdev, int flag, const unsigned char *in_info, unsigned char *out_info);

  /**
   * @brief  ���Ӵ�ʽCPU����
   * @par    ˵����
   * ��⵱ǰ������CPU����״̬��
   * @param[in] icdev �豸��ʶ����
   * @return <0��ʾʧ�ܡ�
   * @n 0 - ״̬δ֪��
   * @n 1 - �޿���
   * @n 2 - �п�����������δ֪��
   * @n 3 - �п�����δ�ϵ硣
   * @n 4 - �п��������ϵ硣
   */
  short USER_API dc_CpuCardStatus(HANDLE icdev);

  /**
   * @brief  �����豸��
   * @par    ˵����
   * �����豸���˽ӿ��������豸�����������󣬳ɹ����ʾ�豸�Ѿ����ѡ�
   * @param[in] icdev �豸��ʶ����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_WakeDevice(HANDLE icdev);

  /**
   * @brief  �����豸��
   * @par    ˵����
   * �����豸���˽ӿ��������豸������������ִ�гɹ�������ʾ�ɹ������������󣬲�����ʾ�豸�Ѿ���������״̬��
   * @param[in] icdev �豸��ʶ����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_RestDevice(HANDLE icdev);

  /**
   * @brief  ��ȡ��ص�����
   * @par    ˵����
   * ��ȡ��ص�����
   * @param[in] icdev �豸��ʶ����
   * @param[out] value ��ذٷֱȣ�0x00~0x64����0x00��ʾ0%��0x64��ʾ100%��
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_GetBatteryValue(HANDLE icdev, unsigned char *value);

  /**
   * @brief  ������ͻ��
   * @par    ˵����
   * ֧��ISO 14443 Type A���Ϳ�Ƭ�ķ�����ͻ��
   * @param[in] icdev �豸��ʶ����
   * @param[in] mode ģʽ��0x93��ʾһ����0x95��ʾ������0x97��ʾ������
   * @param[in] _Bcnt �������̶�Ϊ0x00��
   * @param[out] _Snr ���صĿ����кš�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_anticoll_mode(HANDLE icdev, unsigned char mode, unsigned char _Bcnt, unsigned int *_Snr);

  /**
   * @brief  ѡ��������
   * @par    ˵����
   * ͨ��ָ�����кţ�ѡȡ��Ӧ�Ŀ�Ƭ��
   * @param[in] icdev �豸��ʶ����
   * @param[in] mode ģʽ��0x93��ʾһ����0x95��ʾ������0x97��ʾ������
   * @param[in] _Snr ��Ƭ���кš�
   * @param[out] _Size ���ص�SAKֵ��
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_select_mode(HANDLE icdev, unsigned char mode, unsigned int _Snr, unsigned char *_Size);

  /**
   * @brief  ���Ƭ��
   * @par    ˵����
   * ֧��ISO 14443 Type B���Ϳ�Ƭ�ļ��
   * @param[in] icdev �豸��ʶ����
   * @param[in] PUPI αΨһPICC��ʶ����
   * @param[in] CID �ŵ��š�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_attribInt(HANDLE icdev, unsigned char *PUPI, unsigned char CID);

  /**
   * @brief  ���ϵ硣
   * @par    ˵����
   * ��ָ�������Ŀ�Ƭ�����ϵ������
   * @param[in] icdev �豸��ʶ����
   * @param[in] icc_slot_no ������ţ��û���Ϊ0x0n��SAM��Ϊ0x1n�����С�n����ȡֵ��ΧΪ1~F��
   * @param[out] response ���صĸ�λ��Ϣ�������ٷ���128���ֽڡ�
   * @return <0��ʾʧ�ܣ�����Ϊ���ظ�λ��Ϣ�ĳ��ȡ�
   * @n -1 - ��Ƭ���Ͳ��ԡ�
   * @n -2 - �޿���
   * @n -3 - �п�δ�ϵ硣
   * @n -4 - ��Ƭ��Ӧ��
   */
  short USER_API dc_rf_poweron(HANDLE icdev, unsigned char icc_slot_no, unsigned char *response);

  /**
   * @brief  ���µ硣
   * @par    ˵����
   * ��ָ�������Ŀ�Ƭ�����µ������
   * @param[in] icdev �豸��ʶ����
   * @param[in] icc_slot_no ������ţ��û���Ϊ0x0n��SAM��Ϊ0x1n�����С�n����ȡֵ��ΧΪ1~F��
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   * @n -1 - ��Ƭ���Ͳ��ԡ�
   * @n -2 - �޿���
   * @n -3 - �п�δ�ϵ硣
   * @n -4 - ��Ƭ��Ӧ��
   */
  short USER_API dc_rf_poweroff(HANDLE icdev, unsigned char icc_slot_no);

  /**
   * @brief  ��ȡ��״̬��
   * @par    ˵����
   * ��ȡָ�������Ŀ�Ƭ״̬��
   * @param[in] icdev �豸��ʶ����
   * @param[in] icc_slot_no ������ţ��û���Ϊ0x0n��SAM��Ϊ0x1n�����С�n����ȡֵ��ΧΪ1~F��
   * @return <0��ʾʧ�ܣ�==0��ʾ�п������ϵ硣
   * @n -1 - ��Ƭ���Ͳ��ԡ�
   * @n -2 - �޿���
   * @n -3 - �п�δ�ϵ硣
   * @n -4 - ��Ƭ��Ӧ��
   */
  short USER_API dc_rf_getstatus(HANDLE icdev, unsigned char icc_slot_no);

  /**
   * @brief  ��ָ�����
   * @par    ˵����
   * ��ָ�������Ŀ�Ƭ����ָ���������
   * @param[in] icdev �豸��ʶ����
   * @param[in] icc_slot_no ������ţ��û���Ϊ0x0n��SAM��Ϊ0x1n�����С�n����ȡֵ��ΧΪ1~F��
   * @param[in] length_of_command_apdu �������ݵĳ��ȡ�
   * @param[in] command_apdu �������ݵĳ��ȡ�
   * @param[in] length_of_command_apdu �������ݡ�
   * @param[out] response_apdu ���ص����ݡ�
   * @return <0��ʾʧ�ܣ�����Ϊ�������ݵĳ��ȡ�
   * @n -1 - ��Ƭ���Ͳ��ԡ�
   * @n -2 - �޿���
   * @n -3 - �п�δ�ϵ硣
   * @n -4 - ��Ƭ��Ӧ��
   */
  short USER_API dc_rf_application(HANDLE icdev, unsigned char icc_slot_no, int length_of_command_apdu, unsigned char *command_apdu, unsigned char *response_apdu);

  /**
   * @brief  ��ȡ����Type A��UID��
   * @par    ˵����
   * ��ȡ����Type A��UID��
   * @param[in] icdev �豸��ʶ����
   * @param[out] uid_data ���ص����ݣ������ٷ���256���ֽڡ���ʽΪ����1�ֽ�UID��Ŀ��������1�ֽ�UID���ȡ���UID����1�ֽ�UID2���ȡ���UID2��...��
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_RequestMultiCard(HANDLE icdev, unsigned char *uid_data);

  /**
   * @brief  ѡ��һ��Type A�������
   * @par    ˵����
   * ѡ��һ��Type A�������
   * @param[in] icdev �豸��ʶ����
   * @param[in] uid_len ����UID�ĳ��ȡ�
   * @param[in] uid ����UID��
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_ActivateCard(HANDLE icdev, unsigned char uid_len, const unsigned char *uid);

  /**
   * @brief  ��ȡ�����Ӧ�롣
   * @par    ˵����
   * ��ȡ���һ�κ��豸����ʱ�豸���ص���Ӧ״̬���룬�˽ӿڻ�ȡ����Ӧ�������豸�ڲ��̼������ʵ�֣���ͬ���豸�����в�һ�µ���Ӧ�롣
   * @param[in] icdev �豸��ʶ����
   * @param[out] code ���ص���Ӧ�롣
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_GetLastResponseCode(HANDLE icdev, unsigned int *code);

  /**
   * @brief  ���Flash����������
   * @par    ˵����
   * ����ָ��Flash�����е����ݡ�
   * @param[in] icdev �豸��ʶ����
   * @param[in] type ���ͣ�0x00��ʾ���İ��ϵ�Flash��0x01��ʾ��Spi��Flash��0x02��ʾ����Spi��Flash��0x03��ʾ�����洢��Flash��0x04��ʾ�ֿ�洢��Flash��
   * @param[in] sector ������ַ��0xFFFFFFFF��ʾ����ȫ����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_MultiFlashErase(HANDLE icdev, unsigned char type, unsigned int sector);

  /**
   * @brief  ���Flash�����ݡ�
   * @par    ˵����
   * ��ȡָ��Flash�е����ݡ�
   * @param[in] icdev �豸��ʶ����
   * @param[in] type ���ͣ�0x00��ʾ���İ��ϵ�Flash��0x01��ʾ��Spi��Flash��0x02��ʾ����Spi��Flash��0x03��ʾ�����洢��Flash��0x04��ʾ�ֿ�洢��Flash��
   * @param[in] offset_h ƫ�Ƶ�ַ����λ����
   * @param[in] offset_l ƫ�Ƶ�ַ����λ����
   * @param[in] length_h ��ȡ���ȣ���λ����
   * @param[in] length_l ��ȡ���ȣ���λ����
   * @param[out] data_buffer ���ص����ݡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_MultiFlashRead(HANDLE icdev, unsigned char type, unsigned int offset_h, unsigned int offset_l, unsigned int length_h, unsigned int length_l, unsigned char *data_buffer);

  /**
   * @brief  ���Flashд���ݡ�
   * @par    ˵����
   * д�����ݵ�ָ��Flash�С�
   * @param[in] icdev �豸��ʶ����
   * @param[in] type ���ͣ�0x00��ʾ���İ��ϵ�Flash��0x01��ʾ��Spi��Flash��0x02��ʾ����Spi��Flash��0x03��ʾ�����洢��Flash��0x04��ʾ�ֿ�洢��Flash��
   * @param[in] offset_h ƫ�Ƶ�ַ����λ����
   * @param[in] offset_l ƫ�Ƶ�ַ����λ����
   * @param[in] length_h ��ȡ���ȣ���λ����
   * @param[in] length_l ��ȡ���ȣ���λ����
   * @param[in] data_buffer �������ݡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_MultiFlashWrite(HANDLE icdev, unsigned char type, unsigned int offset_h, unsigned int offset_l, unsigned int length_h, unsigned int length_l, const unsigned char *data_buffer);

  /**
   * @brief  ���FLASH������С��ȡ��
   * @par    ˵����
   * ��ȡָ��Flash��������С��
   * @param[in] icdev �豸��ʶ����
   * @param[in] type ���ͣ�0x00��ʾ���İ��ϵ�Flash��0x01��ʾ��Spi��Flash��0x02��ʾ����Spi��Flash��0x03��ʾ�����洢��Flash��0x04��ʾ�ֿ�洢��Flash��
   * @param[out] length_h ���صĳ��ȣ���λ����
   * @param[out] length_l ���صĳ��ȣ���λ����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_MultiFlashGetSize(HANDLE icdev, unsigned char type, unsigned int *length_h, unsigned int *length_l);

  /**
   * @brief  ����Ѱ����
   * @par    ˵����
   * �п�Ѱ�����޿�Ѱ�����࿨����ͻ��
   * @param[in] icdev �豸��ʶ����
   * @return <0��ʾʧ�ܡ�
   * @n 0 - �����ɹ���
   * @n 1 - δ��⵽��Ƶ����
   * @n 2 - ��⵽���֤��
   * @n 3 - �࿨����
   * @n 4 - ������Ƶ����
   * @n 5 - ��⵽Type A / Type B CPU����
   * @n 6 - ��⵽�п���Ŀ�Ƭ���ڸ�Ӧ����
   */
  short USER_API dc_RfMultiRequest(HANDLE icdev);

  /**
   * @brief  TTS�������š�
   * @par    ˵����
   * TTS�������š�
   * @param[in] icdev �豸��ʶ����
   * @param[in] type ���ͣ�0x00��ʾֹͣ���ţ�0x01��ʾ��������ΪUCS2���룬0x02��ʾ��������ΪGBK���롣
   * @param[in] content �������ݡ�
   * @param[in] content_len �������ݵĳ��ȡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_TtsVoicePlay(HANDLE icdev, unsigned char type, const unsigned char *content, int content_len);

  /**
   * @brief  TTS�������á�
   * @par    ˵����
   * TTS�������á�
   * @param[in] icdev �豸��ʶ����
   * @param[in] type ���ͣ�0x01��ʾ�������٣�0x02��ʾ����������0x03��ʾ������ɫ��
   * @param[in] value ����ֵ��0x00~0xFF��������Ϊ0x80��
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_TtsVoiceConfig(HANDLE icdev, unsigned char type, unsigned char value);

  /**
   * @brief  ���ö�ά�빤��ģʽ��
   * @par    ˵����
   * ���ö�ά�빤��ģʽ��
   * @param[in] icdev �豸��ʶ����
   * @param[in] content �������ݡ�
   * @param[in] content_len �������ݵĳ��ȡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_Config2DBarcode(HANDLE icdev, const unsigned char *content, int content_len);

  /**
   * @brief  ɨ���ά�롣
   * @par    ˵����
   * ɨ���ά�롣
   * @param[in] icdev �豸��ʶ����
   * @param[in] time_ms �豸��ʱֵ����λΪ���롣
   * @param[out] message_data ��ά�룬���ݸ�ʽΪ'\0'��β���ַ�����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_Scan2DBarcode(HANDLE icdev, unsigned short time_ms, char *message_data);

  /**
   * @brief  ��������̡�
   * @par    ˵����
   * ��������̲��ҷ��������Դ��
   * @param[in] icdev �豸��ʶ����
   * @param[in] number ��ţ�0��ʾ����������̣�1��ʾ����������̡�
   * @param[out] version ���صİ汾�ַ����������ٷ���128���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_KeypadOpen(HANDLE icdev, int number, char *version);

  /**
   * @brief  �ر�������̡�
   * @par    ˵����
   * �ر�������̲����ͷ������Դ��
   * @param[in] icdev �豸��ʶ����
   * @param[in] number ��ţ�0��ʾ����������̣�1��ʾ����������̡�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_KeypadClose(HANDLE icdev, int number);

  /**
   * @brief  װ����Կ��
   * @par    ˵����
   * װ����Կ��������������ñ��档
   * @param[in] icdev �豸��ʶ����
   * @param[in] number ��ţ�0��ʾ����������̣�1��ʾ����������̡�
   * @param[in] set_index ��Կ��������0~15����
   * @param[in] sub_index ��Կ������0~15��������0��ʾ����Կ��
   * @param[in] type ��Կ���ͣ�0��ʾ��DES��1��ʾ��DES��2��ʾ24�ֽ���DES��16��ʾSM4��
   * @param[in] mode װ��ģʽ��0��ʾ����װ�أ�1��ʾ����װ�ء�
   * @param[in] key_data ��Կ���ݡ�
   * @param[in] key_len ��Կ���ݵĳ��ȡ�
   * @param[in] flag ��־��0��ʾ����֤��1��ʾ��֤���1��2��ʾ��֤���2��
   * @param[in,out] ex_data �������ݣ������� @a flag ��ֵ��������
   * @n flagΪ1 - ex_dataΪout��ʽ�Ĳ��������ؼ���ȫ0x00������ݡ�
   * @n flagΪ2 - ex_dataΪIn��ʽ�Ĳ������������ȫ0x00������ݡ�
   * @param[in,out] ex_len �������ݵĳ��ȣ������� @a flag ��ֵ��������
   * @n flagΪ1 - ex_lenΪOut��ʽ�Ĳ��������� @a ex_data �ĳ��ȡ�
   * @n flagΪ2 - ex_lenΪIn��ʽ�Ĳ��������� @a ex_data �ĳ��ȡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_KeypadLoadKey(HANDLE icdev, int number, int set_index, int sub_index, int type, int mode, const unsigned char *key_data, int key_len, int flag, unsigned char *ex_data, int *ex_len);

  /**
   * @brief  �����Կ��
   * @par    ˵����
   * ������������ָ������Կ��
   * @param[in] icdev �豸��ʶ����
   * @param[in] number ��ţ�0��ʾ����������̣�1��ʾ����������̡�
   * @param[in] set_index ��Կ��������0~15����-1��ʾȫ����Կ�ס�
   * @param[in] sub_index ��Կ������0~15��������0��ʾ����Կ��-1��ʾȫ����Կ��
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_KeypadClearKey(HANDLE icdev, int number, int set_index, int sub_index);

  /**
   * @brief  ��ȡ��Կ���͡�
   * @par    ˵����
   * ��ȡ���������ָ����Կ�����͡�
   * @param[in] icdev �豸��ʶ����
   * @param[in] number ��ţ�0��ʾ����������̣�1��ʾ����������̡�
   * @param[in] set_index ��Կ��������0~15����
   * @param[in] sub_index ��Կ������0~15��������0��ʾ����Կ��
   * @param[out] type ��Կ���ͣ�0��ʾ��DES��1��ʾ��DES��2��ʾ24�ֽ���DES��16��ʾSM4��
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_KeypadGetKeyType(HANDLE icdev, int number, int set_index, int sub_index, int *type);

  /**
   * @brief  ���ݼӽ��ܡ�
   * @par    ˵����
   * ʹ�����������װ�ص���Կ�������ݼӽ��ܲ�����
   * @param[in] icdev �豸��ʶ����
   * @param[in] number ��ţ�0��ʾ����������̣�1��ʾ����������̡�
   * @param[in] set_index ��Կ��������0~15����
   * @param[in] sub_index ��Կ������0~15��������0��ʾ����Կ��
   * @param[in] flag ��־��0��ʾʹ����ԿĬ���㷨��1��ʾʹ����Կ0~7�ֽ��㵥DES��2��ʾʹ����Կ8~15�ֽ��㵥DES��3��ʾʹ����Կ16~23�ֽ��㵥DES��
   * @param[in] mode ģʽ��0��ʾ���ܣ�1��ʾ���ܡ�
   * @param[in] in_data �������ݡ�
   * @param[in] in_len �������ݵĳ��ȡ�
   * @param[out] out_data ������ݡ�
   * @param[out] out_len ������ݵĳ��ȡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_KeypadAlgorithm(HANDLE icdev, int number, int set_index, int sub_index, int flag, int mode, const unsigned char *in_data, int in_len, unsigned char *out_data, int *out_len);

  /**
   * @brief  �����������롣
   * @par    ˵����
   * ����������̵İ������룬��ʱ�豸����ʼ�����û��İ������������
   * @param[in] icdev �豸��ʶ����
   * @param[in] number ��ţ�0��ʾ����������̣�1��ʾ����������̡�
   * @param[in] mode ģʽ��0��ʾ��ȡ���ģ�1��ʾ��ȡANSI X9.8 PIN BLOCK���ܵİ������ݣ�2��ʾ��ȡIBM3624���ܵİ������ݣ�3��ʾ��ȡANSII���ܵİ������ݡ�
   * @param[in] set_index ��Կ��������0~15��������ģʽ�ڲ����������Ĵ��롣
   * @param[in] sub_index ��Կ������0~15��������0��ʾ����Կ������ģʽ�ڲ����������Ĵ��롣
   * @param[in] in_data �������ݣ�������ģʽ������ģʽ�ڲ����������Ĵ��룬����ģʽΪ���ţ��̶�Ϊ12���ֽڡ�
   * @param[in] in_len �������ݵĳ��ȡ�
   * @param[in] min_len ��С���ȡ�
   * @param[in] max_len ��󳤶ȡ�
   * @param[in] auto_end ����ʱ�������ƣ��˴��Ľ�����ʾ�Ľ������豸�Ƿ���Զ����롾ȷ�ϡ���ֵ����0��ʾ���Զ�������1��ʾ�Զ�������
   * @param[in] enable_beep ����ʱ���������ƣ�0��ʾ��ʹ�÷�����1��ʾʹ�÷�����
   * @param[in] time_s �ӿ�ʼ���������ΰ���֮���ʱ������ʱֵ����λΪ�룬����-1��ʾ��ʹ��ʱ������ʱֵ��0��ʾȱʡֵ�����豸ʵ�־�������
   * @param[out] out_data ������ݡ�
   * @param[out] out_len ������ݵĳ��ȡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_KeypadStartInput(HANDLE icdev, int number, int mode, int set_index, int sub_index, const unsigned char *in_data, int in_len, int min_len, int max_len, int auto_end, int enable_beep, int time_s, unsigned char *out_data, int *out_len);

  /**
   * @brief  ��ȡ��ֵ��
   * @par    ˵����
   * ��ȡһ�����µİ���ֵ��ÿ��ֻ�ܻ�ȡһ����
   * @param[in] icdev �豸��ʶ����
   * @param[in] number ��ţ�0��ʾ����������̣�1��ʾ����������̡�
   * @param[out] value ��������ģʽ����ֵ��Ϊ��ֵ��ASCIIֵ�������1Ϊ0x31����������ģʽ����ֵ��Ϊ0x2A���κ�����ģʽ�¿��Ƽ��ļ�ֵһ�£����˸�Ϊ0x08����ȷ�ϡ�Ϊ0x0D����ȡ����Ϊ0x1B���������Ϊ0x7F������û�а�������Ϊ0xFF�����볬ʱΪ0x80��
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_KeypadGetKeyValue(HANDLE icdev, int number, unsigned char *value);

  /**
   * @brief  �˳����һ�ȡ�������ݡ�
   * @par    ˵����
   * �˳����һ�ȡ������̵��������ݣ���ʱ�豸��ֹͣ�����û��İ������������
   * @param[in] icdev �豸��ʶ����
   * @param[in] number ��ţ�0��ʾ����������̣�1��ʾ����������̡�
   * @param[in] mode ģʽ��0��ʾ���˳���1��ʾ�˳����һ�ȡ���ݡ�
   * @param[out] out_data ������ݡ�
   * @param[out] out_len ������ݵĳ��ȡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_KeypadExitAndGetInput(HANDLE icdev, int number, int mode, unsigned char *out_data, int *out_len);

  /**
   * @brief  ���ü�ֵ��
   * @par    ˵����
   * ����һ�����µİ���ֵ��ÿ��ֻ������һ����
   * @param[in] icdev �豸��ʶ����
   * @param[in] number ��ţ�0��ʾ����������̣�1��ʾ����������̡�
   * @param[in] value ��ֵ��Ϊ��ֵ��ASCIIֵ�������1Ϊ0x31�����Ƽ����˸�Ϊ0x08����ȷ�ϡ�Ϊ0x0D����ȡ����Ϊ0x1B���������Ϊ0x7F��
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_KeypadSetKeyValue(HANDLE icdev, int number, unsigned char value);

  /**
   * @brief  ��ȡ�豸Ψһʶ���롣
   * @par    ˵����
   * ��ȡ�豸�ڲ�д���Ψһʶ���롣
   * @param[in] icdev �豸��ʶ����
   * @param[out] uid ���ص�Ψһʶ�����ַ����������ٷ���33���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_GetDeviceUid(HANDLE icdev, char *uid);

  /**
   * @brief  ��ȡ�豸�̻��š�
   * @par    ˵����
   * ��ȡ�豸�ڲ�д����̻��š�
   * @param[in] icdev �豸��ʶ����
   * @param[out] number ���ص��̻����ַ����������ٷ���33���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_GetDeviceTradeNumber(HANDLE icdev, char *number);

  /**
   * @brief  ��ȡ�豸�ն˺š�
   * @par    ˵����
   * ��ȡ�豸�ڲ�д����ն˺š�
   * @param[in] icdev �豸��ʶ����
   * @param[out] number ���ص��ն˺��ַ����������ٷ���33���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_GetDeviceTerminalNumber(HANDLE icdev, char *number);

  /**
   * @brief  ��ȡ�豸�Զ�����Ϣ��
   * @par    ˵����
   * ��ȡ�豸�Զ�����Ϣ��
   * @param[in] icdev �豸��ʶ����
   * @param[out] info ���ص���Ϣ���̶�Ϊ8���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_ReadDeviceCustomInfo(HANDLE icdev, unsigned char *info);

  /**
   * @brief  д���豸�Զ�����Ϣ��
   * @par    ˵����
   * д���豸�Զ�����Ϣ��
   * @param[in] icdev �豸��ʶ����
   * @param[in] info ������Ϣ���̶�Ϊ8���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_WriteDeviceCustomInfo(HANDLE icdev, const unsigned char *info);

  /**
   * @brief  ��ȡ�豸�ͺ����ơ�
   * @par    ˵����
   * ��ȡ�豸�ͺ����ơ�
   * @param[in] icdev �豸��ʶ����
   * @param[out] name ���ص��ͺ������ַ����������ٷ���33���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_ReadDeviceTypeName(HANDLE icdev, char *name);

  /**
   * @brief  д���豸�ͺ����ơ�
   * @par    ˵����
   * д���豸�ͺ����ơ�
   * @param[in] icdev �豸��ʶ����
   * @param[in] name �����ͺ����ƣ����ݸ�ʽΪ'\0'��β���ַ�����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_WriteDeviceTypeName(HANDLE icdev, const char *name);

  /**
   * @brief  ����ģ���Դ���ơ�
   * @par    ˵����
   * ����ģ���Դ���ơ�
   * @param[in] icdev �豸��ʶ����
   * @param[in] value ���أ�0x00��ʾ�رգ�0x01��ʾ������
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_WirelessPowerControl(HANDLE icdev, unsigned char value);

  /**
   * @brief  ��TCP���ӡ�
   * @par    ˵����
   * ��TCP���ӡ�
   * @param[in] icdev �豸��ʶ����
   * @param[in] type ����ģ�����ͣ�0x00��ʾCDMA��0x01��ʾGPRS��0x02��ʾWIFI��
   * @param[in] network_address IP��ַ�����������ݸ�ʽΪ'\0'��β���ַ�����
   * @param[in] network_port IP�˿ںţ����ݸ�ʽΪ'\0'��β���ַ�����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_WirelessTcpOpen(HANDLE icdev, unsigned char type, const char *network_address, const char *network_port);

  /**
   * @brief  �ر�TCP���ӡ�
   * @par    ˵����
   * �ر�TCP���ӡ�
   * @param[in] icdev �豸��ʶ����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_WirelessTcpClose(HANDLE icdev);

  /**
   * @brief  ��ѯ����״̬��
   * @par    ˵����
   * ��ѯ����״̬��
   * @param[in] icdev �豸��ʶ����
   * @param[out] value ״ֵ̬���̶�Ϊ1���ֽڡ�
   * @n 0x00 - ��ʾTCP��ʼ״̬��
   * @n 0x01 - ��ʾ����ģ���޷�ͨѶ��
   * @n 0x02 - ��ʾ����ģ���Դ�رա�
   * @n 0x03 - ��ʾ����ģ���Դ������
   * @n 0x04 - ��ʾSIM���쳣�����޿���
   * @n 0x05 - ��ʾ�����ź��쳣��
   * @n 0x06 - ��ʾ����ģ���Լ�ɹ���
   * @n 0x07 - ��ʾTCP����״̬��
   * @n 0x08 - ��ʾTCP�Ѿ����ӳɹ���
   * @n 0x09 - ��ʾTCP�Ѿ��Ͽ����ӡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_WirelessGetStatus(HANDLE icdev, unsigned char *value);

  /**
   * @brief  �������ݵ�����ˡ�
   * @par    ˵����
   * �������ݵ�����ˡ�
   * @param[in] icdev �豸��ʶ����
   * @param[in] type ����ģ�����ͣ�0x00��ʾCDMA��0x01��ʾGPRS��0x02��ʾWIFI��
   * @param[in] data_buffer �������ݡ�
   * @param[in] data_len �������ݵĳ��ȡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_WirelessSend(HANDLE icdev, unsigned char type, const unsigned char *data_buffer, int data_len);

  /**
   * @brief  ������˽������ݡ�
   * @par    ˵����
   * ������˽������ݡ�
   * @param[in] icdev �豸��ʶ����
   * @param[in] type ����ģ�����ͣ�0x00��ʾCDMA��0x01��ʾGPRS��0x02��ʾWIFI��
   * @param[in] mode ģʽ��0x00��ʾ���յ����ݸ�ʽ������ʽͷ���ţ�0x01��ʾ���յ����ݸ�ʽ����ʽͷ���ţ�WIFIģ��˲�����Ч��
   * @param[in] time_100ms �豸��ʱֵ����λΪ100���롣
   * @param[out] data_buffer ���ص����ݡ�
   * @param[out] data_len �������ݵĳ��ȡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_WirelessRecv(HANDLE icdev, unsigned char type, unsigned char mode, unsigned char time_100ms, unsigned char *data_buffer, int *data_len);

  /**
   * @brief  ����WIFI������
   * @par    ˵����
   * ����WIFI������
   * @param[in] icdev �豸��ʶ����
   * @param[in] type ����ģ�����ͣ�0x00��ʾCDMA��0x01��ʾGPRS��0x02��ʾWIFI��
   * @param[in] ssid WIFI SSID�����ݸ�ʽΪ'\0'��β���ַ�����
   * @param[in] password WIFI���룬���ݸ�ʽΪ'\0'��β���ַ�����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_WirelessWifiConfig(HANDLE icdev, unsigned char type, const char *ssid, const char *password);

  /**
   * @brief  ��ȡGPS��Ϣ��
   * @par    ˵����
   * ��ȡGPS��Ϣ��
   * @param[in] icdev �豸��ʶ����
   * @param[in] time_ms �豸��ʱֵ����λΪ���롣
   * @param[out] data_buffer ���ص����ݡ�
   * @param[out] data_len �������ݵĳ��ȡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_GpsGetInfo(HANDLE icdev, int time_ms, unsigned char *data_buffer, int *data_len);

  /**
   * @brief  ���ýӴ�ʽCPU��616C���á�
   * @par    ˵����
   * ���ýӴ�ʽCPU��616C���á�
   * @param[in] icdev �豸��ʶ����
   * @param[in] value ����ֵ��0x00��ʾ�豸������616C��0x01��ʾ�豸����616C��
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_SetCpuCard616C(HANDLE icdev, unsigned char value);

  /**
   * @brief  ��ȡ�Ӵ�ʽCPU��616C���á�
   * @par    ˵����
   * ��ȡ�Ӵ�ʽCPU��616C���á�
   * @param[in] icdev �豸��ʶ����
   * @param[out] value ����ֵ��0x00��ʾ�豸������616C��0x01��ʾ�豸����616C��
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_GetCpuCard616C(HANDLE icdev, unsigned char *value);

  /**
   * @brief  ��ȡоƬΨһID�š�
   * @par    ˵����
   * ��ȡоƬΨһID�š�
   * @param[in] icdev �豸��ʶ����
   * @param[out] number ���ص�ID���ַ����������ٷ���128���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_GetChipIdNumber(HANDLE icdev, char *number);

  /**
   * @brief  �������ʾ��
   * @par    ˵����
   * �������ʾ��
   * @param[in] icdev �豸��ʶ����
   * @param[in] number ����ܱ�ţ�1~12����
   * @param[in] mode ģʽ��0x00��ʾ����������ʾ��0x01��ʾ������˸��ʾ��0x02��ʾ���ݲ���˸��ʾ��0x03��ʾ���ݴ�С������ʾ��
   * @param[in] value ��ʾ����ֵ��
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_LedDisplay(HANDLE icdev, unsigned char number, unsigned char mode, unsigned char value);

  /**
   * @brief  �������ʾ���á�
   * @par    ˵����
   * �������ʾ���á�
   * @param[in] icdev �豸��ʶ����
   * @param[in] mode ģʽ��
   * @n 0x00 - ���ơ�
   * @n 0x01 - ���ơ�
   * @n 0x02 - ��ѭ����
   * @n 0x03 - ��ѭ����
   * @n 0x04 - ��ʾ�����
   * @n 0x05 - ��ʾ��λ��
   * @n 0x06 - ��ʾ�������ӡ�
   * @n 0x07 - ��ʾ���Ƚ��͡�
   * @n 0x08 - ����ʾ��
   * @n 0x09 - ����ʾ��
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_LedControl(HANDLE icdev, unsigned char mode);

  /**
   * @brief  ͸��CRCģʽ���á�
   * @par    ˵����
   * ͸��CRCģʽ���á�
   * @param[in] icdev �豸��ʶ����
   * @param[in] tx_crc TXCRCģʽ��0x00��ʾ�ڲ�������TXCRC��0x01��ʾ�ڲ�����TXCRC��ֻ֧��ISO14443��׼������
   * @param[in] rx_crc RXCRCģʽ��0x00��ʾ�ڲ�������RXCRC��0x01��ʾ�ڲ�����RXCRC��ֻ֧��ISO14443��׼������
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_RfCrcModeConfig(HANDLE icdev, unsigned char tx_crc, unsigned char rx_crc);

  /**
   * @brief  ��ȡTCP��Ϣ��
   * @par    ˵����
   * ��ȡTCP��Ϣ��
   * @param[in] icdev �豸��ʶ����
   * @param[in] type ���ͣ�0x01��ʾ������ģ���ͺţ�0x02��ʾ�����õ�ǰ�ź�ǿ�ȡ�
   * @param[out] data_buffer ���ص����ݡ�
   * @param[out] data_len �������ݵĳ��ȡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_TcpGetInfo(HANDLE icdev, unsigned char type, unsigned char *data_buffer, int *data_len);

  /**
   * @brief  ��Ƶ���ߴ򿪡�
   * @par    ˵����
   * ��Ƶ���ߴ򿪡�
   * @param[in] icdev �豸��ʶ����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_RfMarch(HANDLE icdev);

  /**
   * @brief  ѡ�����ߡ�
   * @par    ˵����
   * ѡ�����ߡ�
   * @param[in] icdev �豸��ʶ����
   * @param[in] number ���߱�ţ���1��ʼ��š�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_SelectAntenna(HANDLE icdev, unsigned char number);

  /**
   * @brief  ������MAC��ַ��
   * @par    ˵����
   * ������MAC��ַ��
   * @param[in] icdev �豸��ʶ����
   * @param[out] data_buffer ���ص�������ַ��
   * @param[out] data_len ����������ַ�ĳ��ȡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_ReadNicMacAddress(HANDLE icdev, unsigned char *data_buffer, int *data_len);

  /**
   * @brief  д����MAC��ַ��
   * @par    ˵����
   * д����MAC��ַ��
   * @param[in] icdev �豸��ʶ����
   * @param[in] data_buffer ����������ַ��
   * @param[in] data_len ����������ַ�ĳ��ȡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_WriteNicMacAddress(HANDLE icdev, const unsigned char *data_buffer, int data_len);

  /**
   * @brief  ����������
   * @par    ˵����
   * ����������
   * @param[in] icdev �豸��ʶ����
   * @param[in] data_buffer ����IP��ַ��
   * @param[in] data_len ����IP��ַ�ĳ��ȡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_TestNic(HANDLE icdev, const unsigned char *data_buffer, int data_len);

  /**
   * @brief  ����USB��
   * @par    ˵����
   * ����USB��
   * @param[in] icdev �豸��ʶ����
   * @param[in] data_buffer ������
   * @param[in] data_len �������̶�Ϊ0��
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_TestUsb(HANDLE icdev, const unsigned char *data_buffer, int data_len);

  /**
   * @brief  ���Դ��ڡ�
   * @par    ˵����
   * ���Դ��ڡ�
   * @param[in] icdev �豸��ʶ����
   * @param[in] number ���ڱ�ţ�1~3����
   * @param[in] name �����������ƣ��磺"COM1:115200"��
   * @param[in,out] data_buffer ͨѶ���ݡ�
   * @param[in,out] data_len ͨѶ���ݵĳ��ȡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_TestCom(HANDLE icdev, unsigned char number, const char *name, unsigned char *data_buffer, int *data_len);

  /**
   * @brief  �趨��ʱIP��ַ��
   * @par    ˵����
   * �趨��ʱIP��ַ��
   * @param[in] icdev �豸��ʶ����
   * @param[in] data_buffer ����IP��ַ��
   * @param[in] data_len ����IP��ַ�ĳ��ȡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_ConfigTempIpAddress(HANDLE icdev, const unsigned char *data_buffer, int data_len);

  /**
   * @brief  �����������Զ��ϴ�����ģʽ��ȡ��
   * @par    ˵����
   * ��ȡ�����������Զ��ϴ�����ģʽ��
   * @param[in] icdev �豸��ʶ����
   * @param[out] mode ģʽ��
   * @n 0 - ����������������ĸ����ĸת��Ϊ��д��ĸ��
   * @n 1 - ���������ԭʼ���ݣ�Ĭ�ϣ���
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_GetMagFormat(HANDLE icdev, int *mode);

  /**
   * @brief  ������������ȡ��
   * @par    ˵����
   * ��ȡ�����������Ĳ���������������Զ������ģʽ��Ч��
   * @param[in] icdev �豸��ʶ����
   * @param[out] mode ģʽ��0x00��ʾ���������0x01��ʾ�Զ������
   * @param[out] track1 1���������
   * @n bit0 - �������������ã�0��ʾ�������1��ʾ�����
   * @n bit1 - �������ͷ���ã�0��ʾ������ͷ��1��ʾ������ͷ��
   * @n bit2 - �������β���ã�0��ʾ������β��1��ʾ������β��
   * @n bit3 - ������ݻ��з����ã�0��ʾ�޻��з���1��ʾ�л��з���
   * @n bit4 - ������ݵȺ�������������ã�0��ʾ�������1��ʾ�����
   * @n bit5~bit7 - ������
   * @param[out] track2 2���������
   * @n bit0 - �������������ã�0��ʾ�������1��ʾ�����
   * @n bit1 - �������ͷ���ã�0��ʾ������ͷ��1��ʾ������ͷ��
   * @n bit2 - �������β���ã�0��ʾ������β��1��ʾ������β��
   * @n bit3 - ������ݻ��з����ã�0��ʾ�޻��з���1��ʾ�л��з���
   * @n bit4 - ������ݵȺ�������������ã�0��ʾ�������1��ʾ�����
   * @n bit5~bit7 - ������
   * @param[out] track3 3���������
   * @n bit0 - �������������ã�0��ʾ�������1��ʾ�����
   * @n bit1 - �������ͷ���ã�0��ʾ������ͷ��1��ʾ������ͷ��
   * @n bit2 - �������β���ã�0��ʾ������β��1��ʾ������β��
   * @n bit3 - ������ݻ��з����ã�0��ʾ�޻��з���1��ʾ�л��з���
   * @n bit4 - ������ݵȺ�������������ã�0��ʾ�������1��ʾ�����
   * @n bit5~bit7 - ������
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_GetMag(HANDLE icdev, unsigned char *mode, unsigned char *track1, unsigned char *track2, unsigned char *track3);

  /**
   * @brief  ��ȡ�����豸ͨѶ�����ʡ�
   * @par    ˵����
   * ��ȡ�����豸ͨѶ�����ʡ�
   * @param[in] icdev �豸��ʶ����
   * @param[out] baud �����ʡ�
   * @n 0x00 - 115200��
   * @n 0x01 - 57600��
   * @n 0x02 - 38400��
   * @n 0x03 - 19200��
   * @n 0x04 - 9600��
   * @n 0x05 - 4800��
   * @n 0x06 - 2400��
   * @n 0x07 - 1200��
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_GetDeviceBaud(HANDLE icdev, unsigned char *baud);

  /**
   * @brief  ��ȡUSBģʽ��
   * @par    ˵����
   * ��ȡUSBͨѶģʽ��
   * @param[in] icdev �豸��ʶ����
   * @param[out] ucmode ģʽ��
   * @n 0x00 - ��ʾ�жϷ��ͺ��жϽ��գ���ʱVID=257B��PID=3010��
   * @n 0x01 - ��ʾ���Ʒ��ͺͿ��ƽ��գ���ʱVID=257B��PID=3011��
   * @n 0x02 - ��ʾ���Ʒ��ͺ��жϽ��գ���ʱVID=0471��PID=7002��
   * @n 0x03 - ��ʾ���Ʒ��ͺ��жϽ��գ���ʱVID=0471��PID=7003��
   * @n 0x04 - ��ʾ���Ʒ��ͺ��жϽ��գ���ʱVID=0471��PID=7003��֧�ִ������Զ��ϴ����ܡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_GetUsbMode(HANDLE icdev, unsigned char *ucmode);

  /**
   * @brief  �Ӵ�ʽCPU��ָ�����
   * @par    ˵����
   * �Ե�ǰ����CPU������ָ���������ע��˽ӿ��ѷ�װ��Э�鲿�֣��ڲ�������SW1Ϊ0x61��0x6C�������
   * @param[in] icdev �豸��ʶ����
   * @param[in] slen �������ݵĳ��ȡ�
   * @param[in] sendbuffer �������ݡ�
   * @param[out] rlen �������ݵĳ��ȡ�
   * @param[out] databuffer ���ص����ݡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_cpuapduresponInt(HANDLE icdev, unsigned int slen, unsigned char *sendbuffer, unsigned int *rlen, unsigned char *databuffer);

  /**
   * @brief  �Ӵ�ʽCPU��ָ�����
   * @par    ˵����
   * ::dc_cpuapduresponInt ��HEX��ʽ�ӿڣ����� @a sendbuffer @a databuffer ΪHEX��ʽ��
   */
  short USER_API dc_cpuapduresponInt_hex(HANDLE icdev, unsigned int slen, char *sendbuffer, unsigned int *rlen, char *databuffer);

  /**
   * @brief  ��ʼɨ���ά�롣
   * @par    ˵����
   * ��ʼɨ���ά�롣
   * @param[in] icdev �豸��ʶ����
   * @param[in] mode �������̶�Ϊ0x00��
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_Scan2DBarcodeStart(HANDLE icdev, unsigned char mode);

  /**
   * @brief  ��ȡ��ά�����ݡ�
   * @par    ˵����
   * ��ȡ��ά�����ݡ�
   * @param[in] icdev �豸��ʶ����
   * @param[out] rlen �������ݵĳ��ȡ�
   * @param[out] rdata ���ص����ݡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_Scan2DBarcodeGetData(HANDLE icdev, int *rlen, unsigned char *rdata);

  /**
   * @brief  �˳�ɨ���ά�롣
   * @par    ˵����
   * �˳�ɨ���ά�롣
   * @param[in] icdev �豸��ʶ����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_Scan2DBarcodeExit(HANDLE icdev);

  /**
   * @brief  д�������������á�
   * @par    ˵����
   * д�������������á�
   * @param[in] icdev �豸��ʶ����
   * @param[in] mode ģʽ��0��ʾд���칲�ƶ����Σ�1��ʾд���칲�ƶ�һ�Ρ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_SelfServiceDeviceWriteMagConfig(HANDLE icdev, unsigned char mode);

  /**
   * @brief  ����ģʽ���á�
   * @par    ˵����
   * ����ģʽ���á�
   * @param[in] icdev �豸��ʶ����
   * @param[in] mode ģʽ��0��ʾ����ģʽ��1��ʾ�Ƕ���ģʽ��
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_SelfServiceDeviceShakeConfig(HANDLE icdev, unsigned char mode);

  /**
   * @brief  �������ż���ʾ��
   * @par    ˵����
   * �����豸���������Լ��Ƿ���Ҫ��ʾ��
   * @param[in] icdev �豸��ʶ����
   * @param[in] mode �����κţ�0~8����
   * @n 0 - ���������롣
   * @n 1 - ������ԭ���롣
   * @n 2 - ��������һ�Ρ�
   * @n 3 - �����������롣
   * @n 4 - ��ȷ�������롣
   * @n 5 - �����޸ĳɹ���
   * @n 6 - ��忨��
   * @n 7 - ��ˢ����
   * @n 8 - �������
   * @param[in] type ��ʾ���ͣ�0��ʾ��ʾ�����������ݣ�1��ʾ����ʾ�����������ݡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_VoicePlayAndDisplay(HANDLE icdev, unsigned char mode, unsigned char type);

  /**
   * @brief  ǰ�ŵ�բ�����á�
   * @par    ˵����
   * ǰ�ŵ�բ�����á�
   * @param[in] icdev �豸��ʶ����
   * @param[in] mode ģʽ��0��ʾ����ǰ�ŵ�բ�ţ�1��ʾ������ǰ�ŵ�բ�š�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_SelfServiceDeviceSetFrontSwitch(HANDLE icdev, unsigned char mode);

  /**
   * @brief  ǰ�ŵ�բ�Ż�ȡ��
   * @par    ˵����
   * ǰ�ŵ�բ�Ż�ȡ��
   * @param[in] icdev �豸��ʶ����
   * @param[out] mode ģʽ��0��ʾ����ǰ�ŵ�բ�ţ�1��ʾ������ǰ�ŵ�բ�š�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_SelfServiceDeviceGetFrontSwitch(HANDLE icdev, unsigned char *mode);

  /**
   * @brief  ����豸���á�
   * @par    ˵����
   * ����豸���á�
   * @param[in] icdev �豸��ʶ����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_ClearDeviceConfig(HANDLE icdev);

  /**
   * @brief  �Ӵ�ʽCPU��PPS�������á�
   * @par    ˵����
   * �Ӵ�ʽCPU��PPS�������á�
   * @param[in] icdev �豸��ʶ����
   * @param[in] mode ģʽ��0��ʾ�ײ㲻֧��PPS��1��ʾ�ײ�֧��PPS��
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_SetCpuCardPps(HANDLE icdev, unsigned char mode);

  /**
   * @brief  �Ӵ�ʽCPU��PPS���û�ȡ��
   * @par    ˵����
   * �Ӵ�ʽCPU��PPS���û�ȡ��
   * @param[in] icdev �豸��ʶ����
   * @param[out] mode ģʽ��0��ʾ�ײ㲻֧��PPS��1��ʾ�ײ�֧��PPS��
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_GetCpuCardPps(HANDLE icdev, unsigned char *mode);

  /**
   * @brief  ������
   */
  short USER_API dc_checkcopy_m1(HANDLE icdev, unsigned char mode);

  /**
   * @brief  ˢ�·��������档
   * @par    ˵����
   * ˢ�·��������档
   * @param[in] icdev �豸��ʶ����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_RefreshAndDisplayMainUI(HANDLE icdev);

  /**
   * @brief  ������
   */
  short USER_API dc_GlyProCommand(HANDLE icdev, unsigned int slen, unsigned char *sendbuffer, unsigned int *rlen, unsigned char *databuffer, unsigned char timeout);

  /**
   * @brief  ������
   */
  short USER_API dc_GlyProCommand_hex(HANDLE icdev, unsigned int slen, char *sendbuffer, unsigned int *rlen, char *databuffer, unsigned char timeout);

  /**
   * @brief  ��ȡSAM_Aģ�����кš�
   * @par    ˵����
   * ��ȡSAM_Aģ�����кš�
   * @param[in] icdev �豸��ʶ����
   * @param[out] number ���ص����к��ַ����������ٷ���64���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_SamAReadSerialNumber(HANDLE icdev, char *number);

  /**
   * @brief  2.4G APDUָ�����
   * @par    ˵����
   * 2.4G APDUָ�����
   * @param[in] icdev �豸��ʶ����
   * @param[in] slen �������ݵĳ��ȡ�
   * @param[in] sendbuffer �������ݡ�
   * @param[out] rlen �������ݵĳ��ȡ�
   * @param[out] databuffer ���ص����ݡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_2dot4Apdu(HANDLE icdev, unsigned int slen, unsigned char *sendbuffer, unsigned int *rlen, unsigned char *databuffer);

  /**
   * @brief  2.4G APDUָ�����
   * @par    ˵����
   * ::dc_2dot4Apdu ��HEX��ʽ�ӿڣ����� @a sendbuffer @a databuffer ΪHEX��ʽ��
   */
  short USER_API dc_2dot4Apdu_hex(HANDLE icdev, unsigned int slen, char *sendbuffer, unsigned int *rlen, char *databuffer);

  /**
   * @brief  ��ʾͼ��
   * @par    ˵����
   * ����Ļ����ʾͼ�������ͼ��ָ����ǰ��ͼ��
   * @param[in] icdev �豸��ʶ����
   * @param[in] x ͼ����ʾ����ʼX���ꡣ
   * @param[in] y ͼ����ʾ����ʼY���ꡣ
   * @param[in] w ͼ����ʾ�Ŀ�ȡ�
   * @param[in] h ͼ����ʾ�ĸ߶ȡ�
   * @param[in] time_s ��ʾʱ�䣬��λΪ�룬0��ʾһֱ��ʾ��
   * @param[in] image_data ͼ�����ݡ���ʽΪ����4���ֽ�ͼ����Ϣ���ȣ�Big-Endian������ͼ����Ϣ����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_ScreenDisplayImage(HANDLE icdev, int x, int y, int w, int h, int time_s, const unsigned char *image_data);

  /**
   * @brief  �����ʾ��
   * @par    ˵����
   * �����Ļ�ϵ���ʾ�������������ʾΪǰ����
   * @param[in] icdev �豸��ʶ����
   * @param[in] x �����ʾ����ʼX���ꡣ
   * @param[in] y �����ʾ����ʼY���ꡣ
   * @param[in] w �����ʾ�Ŀ�ȡ�
   * @param[in] h �����ʾ�ĸ߶ȡ�
   * @param[in] time_s ��ʱ���ʱ�䣬��λΪ�룬0��ʾ���������
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_ScreenClearDisplay(HANDLE icdev, int x, int y, int w, int h, int time_s);

  /**
   * @brief  װ�ر���ͼ��
   * @par    ˵����
   * װ�ر���ͼ���豸�ڲ���
   * @param[in] icdev �豸��ʶ����
   * @param[in] number ͼ����ţ���1��ʼ��š�
   * @param[in] image_data ͼ�����ݡ���ʽΪ����4���ֽ�ͼ����Ϣ���ȣ�Big-Endian������ͼ����Ϣ����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_ScreenLoadBgImage(HANDLE icdev, int number, const unsigned char *image_data);

  /**
   * @brief  ��ʾ����ͼ��
   * @par    ˵����
   * ��ʾ�豸�ڲ�װ�صı���ͼ��
   * @param[in] icdev �豸��ʶ����
   * @param[in] number ͼ����ţ���1��ʼ��š�
   * @param[in] x ͼ����ʾ����ʼX���ꡣ
   * @param[in] y ͼ����ʾ����ʼY���ꡣ
   * @param[in] w ͼ����ʾ�Ŀ�ȡ�
   * @param[in] h ͼ����ʾ�ĸ߶ȡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_ScreenDisplayBgImage(HANDLE icdev, int number, int x, int y, int w, int h);

  /**
   * @brief  ��ȡ��ʾ���á�
   * @par    ˵����
   * ��ȡ��ʾ���á�
   * @param[in] icdev �豸��ʶ����
   * @param[in] tag ��ǩ��
   * @n 0x01 - Ϩ��ʱ�䣬������Ϣ���ȹ̶�Ϊ4���ֽڣ���λΪ�루Big-Endian�����磺config_data = {0x04,0x00,0x00,0x00,0x10}��ʾϨ��ʱ��Ϊ16�롣
   * @n 0x02 - ��ʾ�ֱ��ʣ�������Ϣ���ȹ̶�Ϊ4���ֽڣ�ǰ2���ֽ�Ϊˮƽ�ֱ��ʣ�Big-Endian������2���ֽ�Ϊ��ֱ�ֱ��ʣ�Big-Endian�����磺config_data = {0x04,0x02,0x80,0x01,0xE0}��ʾ�ֱ���Ϊ640x480��
   * @param[out] config_data �������ݡ���ʽΪ����1�ֽ�������Ϣ���ȡ���������Ϣ����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_ScreenDisplayGetConfig(HANDLE icdev, unsigned char tag, unsigned char *config_data);

  /**
   * @brief  ������ʾ���á�
   * @par    ˵����
   * ������ʾ���á�
   * @param[in] icdev �豸��ʶ����
   * @param[in] tag ��ǩ��
   * @n 0x01 - Ϩ��ʱ�䣬������Ϣ���ȹ̶�Ϊ4���ֽڣ���λΪ�루Big-Endian�����磺config_data = {0x04,0x00,0x00,0x00,0x10}��ʾϨ��ʱ��Ϊ16�롣
   * @n 0x02 - ��ʾ�ֱ��ʣ�������Ϣ���ȹ̶�Ϊ4���ֽڣ�ǰ2���ֽ�Ϊˮƽ�ֱ��ʣ�Big-Endian������2���ֽ�Ϊ��ֱ�ֱ��ʣ�Big-Endian�����磺config_data = {0x04,0x02,0x80,0x01,0xE0}��ʾ�ֱ���Ϊ640x480��
   * @param[in] config_data �������ݡ���ʽΪ����1�ֽ�������Ϣ���ȡ���������Ϣ����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_ScreenDisplaySetConfig(HANDLE icdev, unsigned char tag, const unsigned char *config_data);

  /**
   * @brief  ��ʾ���֡�
   * @par    ˵����
   * ����Ļ����ʾ���֣�ע������Ҳ����ǰ����
   * @param[in] icdev �豸��ʶ����
   * @param[in] font_size �����С��
   * @param[in] fg_rgb ����ǰ��ɫ��3���ֽ�RGBֵ����һ���ֽ�ΪR���ڶ����ֽ�ΪG���������ֽ�ΪB��
   * @param[in] bg_rgb ���ֱ���ɫ��3���ֽ�RGBֵ����һ���ֽ�ΪR���ڶ����ֽ�ΪG���������ֽ�ΪB��
   * @param[in] x ������ʾ����ʼX���ꡣ
   * @param[in] y ������ʾ����ʼY���ꡣ
   * @param[in] time_s ��ʾʱ�䣬��λΪ�룬0��ʾһֱ��ʾ��
   * @param[in] line_flag ���б�־��0��ʾ���Զ����У�1��ʾ�Զ����С�
   * @param[in] voice_flag ������־��0��ʾ������������1��ʾ����������
   * @param[in] text �ı��ַ�����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_ScreenDisplayText(HANDLE icdev, unsigned char font_size, const unsigned char *fg_rgb, const unsigned char *bg_rgb, int x, int y, int time_s, unsigned char line_flag, unsigned char voice_flag, const char *text);

  /**
   * @brief  ��䱳����
   * @par    ˵����
   * ʹ��ָ����ɫ��䱳����
   * @param[in] icdev �豸��ʶ����
   * @param[in] rgb ��ɫ��3���ֽ�RGBֵ����һ���ֽ�ΪR���ڶ����ֽ�ΪG���������ֽ�ΪB��
   * @param[in] x ��ʼX���ꡣ
   * @param[in] y ��ʼY���ꡣ
   * @param[in] w ��ȡ�
   * @param[in] h �߶ȡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_ScreenDisplayBgImageByColor(HANDLE icdev, const unsigned char *rgb, int x, int y, int w, int h);

  /**
   * @brief  NTAG��ǩ������
   * @par    ˵����
   * NTAG��ǩ������
   * @param[in] icdev �豸��ʶ����
   * @param[in] type �������̶�Ϊ0x00��
   * @param[in] mode ģʽ��
   * @param[in] slen �������ݵĳ��ȡ�
   * @param[in] sdata �������ݡ�
   * @param[out] rlen �������ݵĳ��ȡ�
   * @param[out] rdata ���ص����ݡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_NtagCommand(HANDLE icdev, unsigned char type, unsigned char mode, unsigned int slen, const unsigned char *sdata, unsigned int *rlen, unsigned char *rdata);

  /**
   * @brief  ���ýӴ�ʽCPU����ѹ��
   * @par    ˵����
   * ���ýӴ�ʽCPU����ѹ��
   * @param[in] icdev �豸��ʶ����
   * @param[in] voltage ��ѹֵ��0x00��ʾ5V��0x01��ʾ3.3V��0x02��ʾ1.8V��
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_SetCpuVoltage(HANDLE icdev, unsigned char voltage);

  /**
   * @brief  LCD��ʾ���֡�
   * @par    ˵����
   * ���豸LCD��ʾ������ʾ���֡�
   * @param[in] icdev �豸��ʶ����
   * @param[in] line �кš�
   * @param[in] offset ƫ�ơ�
   * @param[in] mode ģʽ��0��ʾ��ɫ��1��ʾ��ɫ��
   * @param[in] charset �ַ�����
   * @n 0 - ASCII��
   * @n 1 - GB2312��
   * @n 2 - GBK��
   * @n 3 - GB18030��
   * @n 4 - ANSI��
   * @n 5 - UNICODE��Little-Endian����
   * @n 6 - UNICODE��Big-Endian����
   * @param[in] text �ı��ַ�����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_LcdDisplayText(HANDLE icdev, unsigned char line, unsigned char offset, unsigned char mode, unsigned char charset, const unsigned char *text);

  /**
   * @brief  װ���ļ����ݡ�
   * @par    ˵����
   * װ���ļ����ݵ��豸�С�
   * @param[in] icdev �豸��ʶ����
   * @param[in] file_type �ļ����͡�
   * @param[in] file_size �ļ���С��
   * @param[in] flag �����־��
   * @n 0 - ׼�����䡣
   * @n 1~0xFFFFFFFE - �ǽ�β���䡣
   * @n 0xFFFFFFFF - ��β���䡣
   * @param[in] data ���ݣ��� @a flag ��Ϊ0ʱ��Ч��
   * @param[in,out] data_size ���ݴ�С��
   * @n flagΪ0 - data_sizeΪOut��ʽ�Ĳ����������豸֧�ֵ����ְ����ȡ�
   * @n flag��Ϊ0 - data_sizeΪIn��ʽ�Ĳ��������� @a data �ĳ��ȡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_DownloadFileData(HANDLE icdev, unsigned int file_type, unsigned int file_size, unsigned int flag, const unsigned char *data, unsigned int *data_size);

  /**
   * @brief  ���1608����
   * @par    ˵����
   * ����Ƿ����1608����
   * @param[in] icdev �豸��ʶ����
   * @return <0��ʾʧ�ܻ򲻴��ڣ�==0��ʾ���ڡ�
   */
  short USER_API dc_check_1608(HANDLE icdev);

  /**
   * @brief  1608���µ硣
   * @par    ˵����
   * ��1608�������µ������
   * @param[in] icdev �豸��ʶ����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_down_1608(HANDLE icdev);

  /**
   * @brief  ��1608����
   * @par    ˵����
   * ��ȡ1608�������ݡ�
   * @param[in] icdev �豸��ʶ����
   * @param[in] zone ��������
   * @n 0~7 - ��ʾ�û�����
   * @n 8 - ��ʾ��������
   * @param[in] offset ƫ�ơ�
   * @param[in] length ��ȡ���ȡ�
   * @param[out] readdata ���ص����ݡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_read_1608(HANDLE icdev, unsigned char zone, unsigned int offset, unsigned int length, unsigned char *readdata);

  /**
   * @brief  ��1608����
   * @par    ˵����
   * ::dc_read_1608 ��HEX��ʽ�ӿڣ����� @a readdata ΪHEX��ʽ��
   */
  short USER_API dc_read_1608_hex(HANDLE icdev, unsigned char zone, unsigned int offset, unsigned int length, unsigned char *readdata);

  /**
   * @brief  д1608����
   * @par    ˵����
   * д�����ݵ�1608���С�
   * @param[in] icdev �豸��ʶ����
   * @param[in] zone ��������
   * @n 0~7 - ��ʾ�û�����
   * @n 8 - ��ʾ��������
   * @param[in] offset ƫ�ơ�
   * @param[in] length д�볤�ȡ�
   * @param[in] writedata �������ݡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_write_1608(HANDLE icdev, unsigned char zone, unsigned int offset, unsigned int length, unsigned char *writedata);

  /**
   * @brief  д1608����
   * @par    ˵����
   * ::dc_write_1608 ��HEX��ʽ�ӿڣ����� @a writedata ΪHEX��ʽ��
   */
  short USER_API dc_write_1608_hex(HANDLE icdev, unsigned char zone, unsigned int offset, unsigned int length, unsigned char *writedata);

  /**
   * @brief  ��֤1608�����롣
   * @par    ˵����
   * ʹ�ô������������֤1608�����롣
   * @param[in] icdev �豸��ʶ����
   * @param[in] zone ��������
   * @n 0~7 - ��ʾ�û�����
   * @n 8 - ��ʾ��������
   * @param[in] type ���ͣ�0��ʾ��֤д��Կ��1��ʾ��֤����Կ��
   * @param[in] password ���룬�̶�Ϊ3���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_checkpass_1608(HANDLE icdev, unsigned char zone, unsigned char type, unsigned char *password);

  /**
   * @brief  ��֤1608�����롣
   * @par    ˵����
   * ::dc_checkpass_1608 ��HEX��ʽ�ӿڣ����� @a password ΪHEX��ʽ��
   */
  short USER_API dc_checkpass_1608_hex(HANDLE icdev, unsigned char zone, unsigned char type, unsigned char *password);

  /**
   * @brief  ��ʼ��1608����֤��
   * @par    ˵����
   * ʹ�ô������������ʼ��1608����֤��
   * @param[in] icdev �豸��ʶ����
   * @param[in] databuffer ���ݣ��̶�Ϊ8���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_init_auth_1608(HANDLE icdev, unsigned char *databuffer);

  /**
   * @brief  ��ʼ��1608����֤��
   * @par    ˵����
   * ::dc_init_auth_1608 ��HEX��ʽ�ӿڣ����� @a databuffer ΪHEX��ʽ��
   */
  short USER_API dc_init_auth_1608_hex(HANDLE icdev, unsigned char *databuffer);

  /**
   * @brief  �˶�1608����֤��
   * @par    ˵����
   * ʹ�ô�����������˶�1608����֤��
   * @param[in] icdev �豸��ʶ����
   * @param[in] databuffer ���ݣ��̶�Ϊ8���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_check_auth_1608(HANDLE icdev, unsigned char *databuffer);

  /**
   * @brief  �˶�1608����֤��
   * @par    ˵����
   * ::dc_check_auth_1608 ��HEX��ʽ�ӿڣ����� @a databuffer ΪHEX��ʽ��
   */
  short USER_API dc_check_auth_1608_hex(HANDLE icdev, unsigned char *databuffer);

  /**
   * @brief  д1608����˿��
   * @par    ˵����
   * д1608����˿��
   * @param[in] icdev �豸��ʶ����
   * @param[in] value �������̶�Ϊ0x00��
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_write_fuse_1608(HANDLE icdev, unsigned char value);

  /**
   * @brief  ��1608����˿��
   * @par    ˵����
   * ��1608����˿��
   * @param[in] icdev �豸��ʶ����
   * @param[out] value ״ֵ̬��
   * @n bit0 - FAB��Atmel��˾������˿��0��ʾ����˿��1��ʾδ��˿��
   * @n bit1 - CMA���������̷�����˿��0��ʾ����˿��1��ʾδ��˿��
   * @n bit2 - PER�����˻�������˿��0��ʾ����˿��1��ʾδ��˿��
   * @n bit3~bit7 - ������
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_read_fuse_1608(HANDLE icdev, unsigned char *value);

  /**
   * @brief  ���153����
   * @par    ˵����
   * ����Ƿ����153����
   * @param[in] icdev �豸��ʶ����
   * @return <0��ʾʧ�ܻ򲻴��ڣ�==0��ʾ���ڡ�
   */
  short USER_API dc_check_153(HANDLE icdev);

  /**
   * @brief  153���µ硣
   * @par    ˵����
   * ��153�������µ������
   * @param[in] icdev �豸��ʶ����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_down_153(HANDLE icdev);

  /**
   * @brief  ��153����
   * @par    ˵����
   * ��ȡ153�������ݡ�
   * @param[in] icdev �豸��ʶ����
   * @param[in] zone ��������
   * @n 0~2 - ��ʾ�û�����
   * @n 3 - ��ʾ��������
   * @param[in] offset ƫ�ơ�
   * @param[in] length ��ȡ���ȡ�
   * @param[out] readdata ���ص����ݡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_read_153(HANDLE icdev, unsigned char zone, unsigned int offset, unsigned int length, unsigned char *readdata);

  /**
   * @brief  ��153����
   * @par    ˵����
   * ::dc_read_153 ��HEX��ʽ�ӿڣ����� @a readdata ΪHEX��ʽ��
   */
  short USER_API dc_read_153_hex(HANDLE icdev, unsigned char zone, unsigned int offset, unsigned int length, unsigned char *readdata);

  /**
   * @brief  д153����
   * @par    ˵����
   * д�����ݵ�153���С�
   * @param[in] icdev �豸��ʶ����
   * @param[in] zone ��������
   * @n 0~2 - ��ʾ�û�����
   * @n 3 - ��ʾ��������
   * @param[in] offset ƫ�ơ�
   * @param[in] length д�볤�ȡ�
   * @param[in] writedata �������ݡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_write_153(HANDLE icdev, unsigned char zone, unsigned int offset, unsigned int length, unsigned char *writedata);

  /**
   * @brief  д153����
   * @par    ˵����
   * ::dc_write_153 ��HEX��ʽ�ӿڣ����� @a writedata ΪHEX��ʽ��
   */
  short USER_API dc_write_153_hex(HANDLE icdev, unsigned char zone, unsigned int offset, unsigned int length, unsigned char *writedata);

  /**
   * @brief  ��֤153�����롣
   * @par    ˵����
   * ʹ�ô������������֤153�����롣
   * @param[in] icdev �豸��ʶ����
   * @param[in] zone ��������
   * @n 0~2 - ��ʾ�û�����
   * @n 3 - ��ʾ��������
   * @param[in] type ���ͣ�0��ʾ��֤д��Կ��1��ʾ��֤����Կ��
   * @param[in] password ���룬�̶�Ϊ3���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_checkpass_153(HANDLE icdev, unsigned char zone, unsigned char type, unsigned char *password);

  /**
   * @brief  ��֤153�����롣
   * @par    ˵����
   * ::dc_checkpass_153 ��HEX��ʽ�ӿڣ����� @a password ΪHEX��ʽ��
   */
  short USER_API dc_checkpass_153_hex(HANDLE icdev, unsigned char zone, unsigned char type, unsigned char *password);

  /**
   * @brief  ��ʼ��153����֤��
   * @par    ˵����
   * ʹ�ô������������ʼ��153����֤��
   * @param[in] icdev �豸��ʶ����
   * @param[in] databuffer ���ݣ��̶�Ϊ8���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_init_auth_153(HANDLE icdev, unsigned char *databuffer);

  /**
   * @brief  ��ʼ��153����֤��
   * @par    ˵����
   * ::dc_init_auth_153 ��HEX��ʽ�ӿڣ����� @a databuffer ΪHEX��ʽ��
   */
  short USER_API dc_init_auth_153_hex(HANDLE icdev, unsigned char *databuffer);

  /**
   * @brief  �˶�153����֤��
   * @par    ˵����
   * ʹ�ô�����������˶�153����֤��
   * @param[in] icdev �豸��ʶ����
   * @param[in] databuffer ���ݣ��̶�Ϊ8���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_check_auth_153(HANDLE icdev, unsigned char *databuffer);

  /**
   * @brief  �˶�153����֤��
   * @par    ˵����
   * ::dc_check_auth_153 ��HEX��ʽ�ӿڣ����� @a databuffer ΪHEX��ʽ��
   */
  short USER_API dc_check_auth_153_hex(HANDLE icdev, unsigned char *databuffer);

  /**
   * @brief  д153����˿��
   * @par    ˵����
   * д153����˿��
   * @param[in] icdev �豸��ʶ����
   * @param[in] value �������̶�Ϊ0x00��
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_write_fuse_153(HANDLE icdev, unsigned char value);

  /**
   * @brief  ��153����˿��
   * @par    ˵����
   * ��153����˿��
   * @param[in] icdev �豸��ʶ����
   * @param[out] value ״ֵ̬��
   * @n bit0 - FAB��Atmel��˾������˿��0��ʾ����˿��1��ʾδ��˿��
   * @n bit1 - CMA���������̷�����˿��0��ʾ����˿��1��ʾδ��˿��
   * @n bit2 - PER�����˻�������˿��0��ʾ����˿��1��ʾδ��˿��
   * @n bit3~bit7 - ������
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_read_fuse_153(HANDLE icdev, unsigned char *value);

  /**
   * @brief  ������������ֹͣ��
   * @par    ˵����
   * ������������ֹͣ��
   * @param[in] icdev �豸��ʶ����
   * @param[in] flag ��ǣ�0��ʾֹͣ��1��ʾ������
   * @param[in,out] mask ����ֵ��32bit�ֱ��ʾ32·���ߣ���ӦbitλΪ1��ʾ������Ч������Ϊ�ڴ�ֵ������Ϊʵ��ֵ��
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_MultiAntennaStartOrStop(HANDLE icdev, unsigned char flag, unsigned int *mask);

  /**
   * @brief  �����߻�ȡ��״̬��
   * @par    ˵����
   * �����߻�ȡ��״̬��
   * @param[in] icdev �豸��ʶ����
   * @param[out] rlen �������ݵĳ��ȡ�
   * @param[out] rdata ���ص����ݡ�
   * @n 0x00 - �޿���
   * @n 0x8A - �п���Type A CPU����
   * @n 0x8B - �п���Type B CPU����
   * @n 0x80 - �п���δ֪���͡�
   * @n 0x81 - �п���M1����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_MultiAntennaGetCardStatus(HANDLE icdev, int *rlen, unsigned char *rdata);

  /**
   * @brief  ��ȡ���п��ʻ����롣
   * @par    ˵����
   * ��ȡ���п��ʻ����롣
   * @param[in] icdev �豸��ʶ����
   * @param[in] type ���ͣ�0��ʾ�ǽӴ�ʽ��1��ʾ�Ӵ�ʽ��
   * @param[out] number ���ص����п��ʻ������ַ����������ٷ���64���ֽڡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_GetBankAccountNumber(HANDLE icdev, int type, char *number);

  /**
   * @brief  �������֤����ͱ���ͼ��
   * @par    ˵����
   * �������֤����ͱ���ͼ��
   * @param[in] icdev �豸��ʶ����
   * @param[in] type ���ͣ�0��ʾ�й��˾������֤��1��ʾ��������þ���֤��
   * @param[in] text_len ������Ϣ�ĳ��ȡ�
   * @param[in] text ������Ϣ��
   * @param[in] photo_len ��Ƭ��Ϣ�ĳ��ȡ�
   * @param[in] photo ��Ƭ��Ϣ��
   * @param[in] front_file ��������ͼ���ļ�������ȷ����д���Ȩ�ޡ�
   * @param[in] back_file ���뱳��ͼ���ļ�������ȷ����д���Ȩ�ޡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_IdCardImageBuild(HANDLE icdev, int type, int text_len, const unsigned char *text, int photo_len, const unsigned char *photo, const char *front_file, const char *back_file);

  /**
   * @brief  �����Ӿ�����ء�
   * @par    ˵����
   * �����Ӿ�����ء�
   * @param[in] icdev �豸��ʶ����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_CvLibLoad(HANDLE icdev);

  /**
   * @brief  �����Ӿ���ж�ء�
   * @par    ˵����
   * �����Ӿ���ж�ء�
   * @param[in] icdev �豸��ʶ����
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_CvLibUnload(HANDLE icdev);

  /**
   * @brief  ��������ͷ��
   * @par    ˵����
   * ����ָ��������ͷ��
   * @param[in] icdev �豸��ʶ����
   * @param[in] number ����ͷ��š�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_CvOpen(HANDLE icdev, int number);

  /**
   * @brief  �ر�����ͷ��
   * @par    ˵����
   * �ر�ָ��������ͷ��
   * @param[in] icdev �豸��ʶ����
   * @param[in] number ����ͷ��š�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_CvClose(HANDLE icdev, int number);

  /**
   * @brief  ���ա�
   * @par    ˵����
   * ʹ��ָ��������ͷ�������ա�
   * @param[in] icdev �豸��ʶ����
   * @param[in] number ����ͷ��š�
   * @param[in] mode ģʽ��
   * @param[in] file_name �ļ�������ȷ����д���Ȩ�ޡ�
   * @return <0��ʾʧ�ܣ�==0��ʾ�ɹ���
   */
  short USER_API dc_CvCapture(HANDLE icdev, int number, int mode, const char *file_name);

#ifdef __cplusplus
}
#endif

#endif // DCRF32_H_

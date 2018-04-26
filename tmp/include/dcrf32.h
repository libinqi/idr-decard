// -*- mode:c++ -*-

/**
 * @file
 * @author Wei Yang <wstcreator@hotmail.com>
 * @date   Tue Dec 20 11:42:16 2016
 * @brief  读写器功能接口声明文件。
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
   * @brief  库入口。
   * @par    说明：
   * 可以获取或设置一些库相关参数，此接口可不掉用，如需调用必须放在所有其它接口之前调用。
   * @param[in] flag 标记，用于决定 @a context 的类型和含义。
   * @n 0 - 表示获取库版本， @a context 类型为char *，请至少分配8个字节。
   * @n 1 - 表示设置库的工作目录， @a context 类型为const char *。
   * @n 2 - 表示设置库调用者的工作目录， @a context 类型为const char *。
   * @n 3 - 保留内部使用，表示设置辅助接口上下文， @a context 类型为自定义结构指针。
   * @n 4 - 保留内部使用，表示获取辅助接口上下文， @a context 类型为自定义结构指针。
   * @param[in,out] context 参数实际类型和含义由 @a flag 的值来决定。
   */
  void USER_API LibMain(int flag, void *context);

  /**
   * @brief  配置端口名称。
   * @par    说明：
   * 用于配置端口对应的物理名称，在调用 ::dc_init 之前可以使用此接口来改变端口号内部对应的默认物理名称，如Windows平台下0端口号对应的默认名称为"COM1"，Linux平台下0端口号对应的默认名称为"/dev/ttyS0"。
   * @param[in] port 端口号，同 ::dc_init 的 @a port ，但仅支持串口模式和蓝牙模式的端口号，即：0~99、300~399。
   * @param[in] name 物理名称。
   */
  void USER_API dc_config_port_name(short port, const char *name);

  /**
   * @brief  打开设备。
   * @par    说明：
   * 建立设备的通讯并且分配相应的资源，大部分功能接口都需要在此过程后才能进行，在不需要使用设备后，必须使用 ::dc_exit 去关闭设备的通讯和释放资源。
   * @param[in] port 端口号。
   * @n 0~99 - 表示串口模式（编号物理对应），编号0表示第一个串口合法设备，编号1表示第二个串口合法设备，以此类推。
   * @n 100~199 - 表示USB模式（编号逻辑对应），编号100表示第一个USB合法设备，编号1表示第二个USB合法设备，以此类推。
   * @n 200~299 - 表示PCSC模式（编号逻辑对应），编号200表示第一个PCSC合法设备，编号201表示第二个PCSC合法设备，以此类推。
   * @n 300~399 - 表示蓝牙模式（编号逻辑对应），编号300表示第一个蓝牙合法设备，编号301表示第二个蓝牙合法设备，以此类推。
   * @param[in] baud 波特率，只针对串口模式有效。
   * @return <0表示失败，否则为设备标识符。
   */
  HANDLE USER_API dc_init(short port, int baud);

  /**
   * @brief  打开设备。
   * @par    说明：
   * 建立设备的通讯并且分配相应的资源，大部分功能接口都需要在此过程后才能进行，在不需要使用设备后，必须使用 ::dc_exit 去关闭设备的通讯和释放资源。
   * @param[in] port 端口号。
   * @n 0~99 - 表示串口模式（编号物理对应），编号0表示第一个串口合法设备，编号1表示第二个串口合法设备，以此类推。
   * @n 100~199 - 表示USB模式（编号逻辑对应），编号100表示第一个USB合法设备，编号1表示第二个USB合法设备，以此类推。
   * @n 200~299 - 表示PCSC模式（编号逻辑对应），编号200表示第一个PCSC合法设备，编号201表示第二个PCSC合法设备，以此类推。
   * @n 300~399 - 表示蓝牙模式（编号逻辑对应），编号300表示第一个蓝牙合法设备，编号301表示第二个蓝牙合法设备，以此类推。
   * @param[in] baud 波特率，只针对串口模式有效。
   * @param[in] name 设备逻辑名称。
   * @return <0表示失败，否则为设备标识符。
   */
  HANDLE USER_API dc_init_name(short port, int baud, const char *name);

  /**
   * @brief  关闭设备。
   * @par    说明：
   * 关闭设备的通讯和释放资源。
   * @param[in] icdev 设备标识符。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_exit(HANDLE icdev);

  /**
   * @brief  获取名称。
   * @par    说明：
   * 此接口将获取一个用于识别当前打开设备与软件层对应的逻辑名称，获取的逻辑名称仅供内部使用。
   * @param[in] icdev 设备标识符。
   * @param[out] name 返回的名称字符串，请至少分配64个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_getname(HANDLE icdev, char *name);

  /**
   * @brief  保留。
   */
  short USER_API dc_config(HANDLE icdev, unsigned char _Mode, unsigned char _Baud);

  /**
   * @brief  寻卡请求。
   * @par    说明：
   * 支持ISO 14443 Type A类型卡片的寻卡请求。
   * @param[in] icdev 设备标识符。
   * @param[in] _Mode 模式，0x00表示对空闲卡进行操作，0x01表示对所有卡操作。
   * @param[out] TagType 返回的ATQA值。
   * @return <0表示失败，==0表示成功，==1表示无卡或无法寻到卡片。
   */
  short USER_API dc_request(HANDLE icdev, unsigned char _Mode, unsigned short *TagType);

  /**
   * @brief  防卡冲突。
   * @par    说明：
   * 支持ISO 14443 Type A类型卡片的防卡冲突。
   * @param[in] icdev 设备标识符。
   * @param[in] _Bcnt 保留，固定为0x00。
   * @param[out] _Snr 返回的卡序列号。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_anticoll(HANDLE icdev, unsigned char _Bcnt, unsigned int *_Snr);

  /**
   * @brief  选卡操作。
   * @par    说明：
   * 通过指定序列号，选取相应的卡片。
   * @param[in] icdev 设备标识符。
   * @param[in] _Snr 卡片序列号。
   * @param[out] _Size 返回的SAK值。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_select(HANDLE icdev, unsigned int _Snr, unsigned char *_Size);

  /**
   * @brief  验证M1卡密码。
   * @par    说明：
   * 使用设备内部装载的密码来验证M1卡密码。
   * @param[in] icdev 设备标识符。
   * @param[in] _Mode 模式。
   * @n 0x00 - 表示用设备内部装载的第0套A密码来验证当前选取卡片的A密码。
   * @n 0x01 - 表示用设备内部装载的第1套A密码来验证当前选取卡片的A密码。
   * @n 0x02 - 表示用设备内部装载的第2套A密码来验证当前选取卡片的A密码。
   * @n 0x04 - 表示用设备内部装载的第0套B密码来验证当前选取卡片的B密码。
   * @n 0x05 - 表示用设备内部装载的第1套B密码来验证当前选取卡片的B密码。
   * @n 0x06 - 表示用设备内部装载的第2套B密码来验证当前选取卡片的B密码。
   * @param[in] _SecNr 要验证密码的扇区号。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_authentication(HANDLE icdev, unsigned char _Mode, unsigned char _SecNr);

  /**
   * @brief  终止卡操作。
   * @par    说明：
   * 使卡片进入终止状态，此时必须把卡移出感应区后再次放入感应区才能寻到这张卡。
   * @param[in] icdev 设备标识符。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_halt(HANDLE icdev);

  /**
   * @brief  读卡数据。
   * @par    说明：
   * 读取卡内数据，对于M1卡，一次读取一个块的数据，为16个字节；对于ML卡，一次读取相同属性的两页，为8个字节。
   * @param[in] icdev 设备标识符。
   * @param[in] _Adr 地址。
   * @n M1卡 - S50块地址（0~63），S70块地址（0~255）。
   * @n ML卡 - 页地址（0~11）。
   * @param[out] _Data 固定返回16个字节数据，真实数据可能小于16个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_read(HANDLE icdev, unsigned char _Adr, unsigned char *_Data);

  /**
   * @brief  读卡数据。
   * @par    说明：
   * ::dc_read 的HEX形式接口，参数 @a _Data 为HEX格式。
   */
  short USER_API dc_read_hex(HANDLE icdev, unsigned char _Adr, char *_Data);

  /**
   * @brief  写卡数据。
   * @par    说明：
   * 写入数据到卡片内，对于M1卡，一次必须写入一个块的数据，为16个字节；对于ML卡，一次必须写入一个页的数据，为4个字节。
   * @param[in] icdev 设备标识符。
   * @param[in] _Adr 地址。
   * @n M1卡 - S50块地址（1~63），S70块地址（1~255）。
   * @n ML卡 - 页地址（2~11）。
   * @param[out] _Data 固定传入16个字节数据，真实数据可能小于16个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_write(HANDLE icdev, unsigned char _Adr, unsigned char *_Data);

  /**
   * @brief  写卡数据。
   * @par    说明：
   * ::dc_write 的HEX形式接口，参数 @a _Data 为HEX格式。
   */
  short USER_API dc_write_hex(HANDLE icdev, unsigned char _Adr, char *_Data);

  /**
   * @brief  保留。
   */
  short USER_API dc_write_TS(HANDLE icdev);

  /**
   * @brief  装载设备密码。
   * @par    说明：
   * 装载M1卡密码到设备内部，装载后可以在特定时候用 ::dc_authentication 来验证M1卡密码。注意：由于多次装载设备密码可能会受硬件存储寿命限制，此接口只用于密码相对固定，装载次数少的场合。
   * @param[in] icdev 设备标识符。
   * @param[in] _Mode 模式，同 ::dc_authentication 的 @a _Mode 。
   * @param[in] _SecNr 对应装载的扇区号。
   * @param[in] _NKey 写入设备中的卡密码，固定为6个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_load_key(HANDLE icdev, unsigned char _Mode, unsigned char _SecNr, unsigned char *_NKey);

  /**
   * @brief  装载设备密码。
   * @par    说明：
   * ::dc_load_key 的HEX形式接口，参数 @a _NKey 为HEX格式。
   */
  short USER_API dc_load_key_hex(HANDLE icdev, unsigned char _Mode, unsigned char _SecNr, char *_NKey);

  /**
   * @brief  寻卡请求、防卡冲突、选卡操作。
   * @par    说明：
   * 内部包含了 ::dc_request ::dc_anticoll ::dc_select 的功能。
   * @param[in] icdev 设备标识符。
   * @param[in] _Mode 模式，同 ::dc_request 的 @a _Mode 。
   * @param[out] _Snr 返回的卡序列号。
   * @return <0表示失败，==0表示成功，==1表示无卡或无法寻到卡片。
   */
  short USER_API dc_card(HANDLE icdev, unsigned char _Mode, unsigned int *_Snr);

  /**
   * @brief  寻卡请求、防卡冲突、选卡操作。
   * @par    说明：
   * ::dc_card 的HEX形式接口，参数 @a snrstr 为HEX格式。
   */
  short USER_API dc_card_hex(HANDLE icdev, unsigned char _Mode, unsigned char *snrstr);

  /**
   * @brief  M1卡密码配置块操作。
   * @par    说明：
   * 修改M1卡密码配置块数据，M1卡密码配置块也就是每个扇区的最后一块，包含密码A、控制字节、密码B数据。
   * @param[in] icdev 设备标识符。
   * @param[in] _SecNr 扇区号。
   * @param[in] _KeyA 密码A，固定为6个字节。
   * @param[in] _B0 块0控制字（当一扇区有16块时，对应为块0~4的控制字），低3位（D2D1D0）对应C10、C20、C30。
   * @param[in] _B1 块1控制字（当一扇区有16块时，对应为块5~9的控制字），低3位（D2D1D0）对应C11、C21、C31。
   * @param[in] _B2 块2控制字（当一扇区有16块时，对应为块10~14的控制字），低3位（D2D1D0）对应C12、C22、C32。
   * @param[in] _B3 块3控制字（当一扇区有16块时，对应为块15的控制字），低3位（D2D1D0）对应C13、C23、C33。
   * @param[in] _Bk 保留，固定为0x00。
   * @param[in] _KeyB 密码B，固定为6个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_changeb3(HANDLE icdev, unsigned char _SecNr, unsigned char *_KeyA, unsigned char _B0, unsigned char _B1, unsigned char _B2, unsigned char _B3, unsigned char _Bk, unsigned char *_KeyB);

  /**
   * @brief  M1卡密码配置块操作。
   * @par    说明：
   * ::dc_changeb3 的HEX形式接口，参数 @a _KeyA @a _KeyB 为HEX格式。
   */
  short USER_API dc_changeb3_hex(HANDLE icdev, unsigned char _SecNr, const char *_KeyA, unsigned char _B0, unsigned char _B1, unsigned char _B2, unsigned char _B3, unsigned char _Bk, const char *_KeyB);

  /**
   * @brief  M1卡值块回传。
   * @par    说明：
   * 用于把指定的值块内容暂存，后续可以使用 ::dc_transfer 将暂存值块内容传递到另一块中，实现块与块之间数值传送。
   * @param[in] icdev 设备标识符。
   * @param[in] _Adr 要回传的块地址。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_restore(HANDLE icdev, unsigned char _Adr);

  /**
   * @brief  M1卡值块传递。
   * @par    说明：
   * 用于把 ::dc_restore 暂存的值块内容传递到指定块中，实现块与块之间数值传送。
   * @param[in] icdev 设备标识符。
   * @param[in] _Adr 要传递的块地址。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_transfer(HANDLE icdev, unsigned char _Adr);

  /**
   * @brief  M1卡值块加值。
   * @par    说明：
   * 用于操作M1卡值块，使块值增加指定数值。
   * @param[in] icdev 设备标识符。
   * @param[in] _Adr 块地址。
   * @param[in] _Value 要增加的数值。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_increment(HANDLE icdev, unsigned char _Adr, unsigned int _Value);

  /**
   * @brief  M1卡值块减值。
   * @par    说明：
   * 用于操作M1卡值块，使块值减少指定数值。
   * @param[in] icdev 设备标识符。
   * @param[in] _Adr 块地址。
   * @param[in] _Value 要减少的数值。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_decrement(HANDLE icdev, unsigned char _Adr, unsigned int _Value);

  /**
   * @brief  M1卡值块初始化。
   * @par    说明：
   * 用于操作M1卡，使得指定块为值块，并且初始化此值块为指定数值。
   * @param[in] icdev 设备标识符。
   * @param[in] _Adr 块地址。
   * @param[in] _Value 初始化数值。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_initval(HANDLE icdev, unsigned char _Adr, unsigned int _Value);

  /**
   * @brief  M1卡值块读值。
   * @par    说明：
   * 用于读取M1卡值块数值。
   * @param[in] icdev 设备标识符。
   * @param[in] _Adr 要读取的块地址。
   * @param[out] _Value 返回的数值。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_readval(HANDLE icdev, unsigned char _Adr, unsigned int *_Value);

  /**
   * @brief  ML卡值初始化。
   * @par    说明：
   * 用于操作ML卡，初始化卡内容为指定数值。
   * @param[in] icdev 设备标识符。
   * @param[in] _Value 初始化数值。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_initval_ml(HANDLE icdev, unsigned short _Value);

  /**
   * @brief  ML卡读值。
   * @par    说明：
   * 用于读取ML卡数值。
   * @param[in] icdev 设备标识符。
   * @param[out] _Value 返回的数值。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_readval_ml(HANDLE icdev, unsigned short *_Value);

  /**
   * @brief  ML卡减值。
   * @par    说明：
   * 用于操作ML卡值，使值减少指定数值。
   * @param[in] icdev 设备标识符。
   * @param[in] _Value 要减少的数值。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_decrement_ml(HANDLE icdev, unsigned short _Value);

  /**
   * @brief  验证M1卡密码。
   * @par    说明：
   * 使用设备内部装载的密码来验证M1卡密码。
   * @param[in] icdev 设备标识符。
   * @param[in] _Mode 模式，同 ::dc_authentication 的 @a _Mode 。
   * @param[in] KeyNr 要验证密码的扇区号。
   * @param[in] Adr 要验证密码扇区中的块号，此块号非卡片绝对块号。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_authentication_2(HANDLE icdev, unsigned char _Mode, unsigned char KeyNr, unsigned char Adr);

  /**
   * @brief  第二级防卡冲突。
   * @par    说明：
   * 支持ISO 14443 Type A类型卡片的第二级防卡冲突。
   * @param[in] icdev 设备标识符。
   * @param[in] _Bcnt 保留，固定为0x00。
   * @param[out] _Snr 返回的卡序列号。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_anticoll2(HANDLE icdev, unsigned char _Bcnt, unsigned int *_Snr);

  /**
   * @brief  第二级选卡操作。
   * @par    说明：
   * 通过指定序列号，选取相应的卡片。
   * @param[in] icdev 设备标识符。
   * @param[in] _Snr 卡片序列号。
   * @param[out] _Size 返回的SAK值。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_select2(HANDLE icdev, unsigned int _Snr, unsigned char *_Size);

  /**
   * @brief  保留。
   */
  short USER_API dc_HL_write(HANDLE icdev, unsigned char _Mode, unsigned char _Adr, unsigned int *_Snr, unsigned char *_Data);

  /**
   * @brief  保留。
   */
  short USER_API dc_HL_writehex(HANDLE icdev, unsigned char _Mode, unsigned char _Adr, unsigned int *_Snr, unsigned char *_Data);

  /**
   * @brief  保留。
   */
  short USER_API dc_HL_read(HANDLE icdev, unsigned char _Mode, unsigned char _Adr, unsigned int _Snr, unsigned char *_Data, unsigned int *_NSnr);

  /**
   * @brief  保留。
   */
  short USER_API dc_HL_readhex(HANDLE icdev, unsigned char _Mode, unsigned char _Adr, unsigned int _Snr, unsigned char *_Data, unsigned int *_NSnr);

  /**
   * @brief  高层验证M1卡密码。
   * @par    说明：
   * 内部包含了 ::dc_card ::dc_authentication 的功能。
   * @param[in] icdev 设备标识符。
   * @param[in] reqmode 寻卡请求模式，同 ::dc_request 的 @a _Mode 。
   * @param[in] snr 保留，固定为0。
   * @param[in] authmode 验证模式，同 ::dc_authentication 的 @a _Mode 。
   * @param[in] secnr 要验证密码的扇区号。
   * @return <0表示失败，==0表示成功，==1表示无卡或无法寻到卡片。
   */
  short USER_API dc_HL_authentication(HANDLE icdev, unsigned char reqmode, unsigned int snr, unsigned char authmode, unsigned char secnr);

  /**
   * @brief  检查之前写入的数据。
   * @par    说明：
   * 内部包含了 ::dc_card ::dc_authentication ::dc_read 的功能，并且验证传入和读取的数据是否一致。
   * @param[in] icdev 设备标识符。
   * @param[in] Snr 卡序列号，用于内部核对。
   * @param[in] authmode 验证模式，同 ::dc_authentication 的 @a _Mode 。
   * @param[in] Adr 块地址。
   * @param[in] _data 块数据，固定为16个字节。
   * @return <0表示失败，==0表示成功，==1表示无卡或无法寻到卡片。
   */
  short USER_API dc_check_write(HANDLE icdev, unsigned int Snr, unsigned char authmode, unsigned char Adr, unsigned char *_data);

  /**
   * @brief  检查之前写入的数据。
   * @par    说明：
   * ::dc_check_write 的HEX形式接口，参数 @a _data 为HEX格式。
   */
  short USER_API dc_check_writehex(HANDLE icdev, unsigned int Snr, unsigned char authmode, unsigned char Adr, unsigned char *_data);

  /**
   * @brief  获取设备版本。
   * @par    说明：
   * 获取设备内部固件代码的版本。
   * @param[in] icdev 设备标识符。
   * @param[out] sver 返回的版本字符串，请至少分配128个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_getver(HANDLE icdev, unsigned char *sver);

  /**
   * @brief  保留。
   */
  short USER_API dc_update(HANDLE icdev);

  /**
   * @brief  保留。
   */
  short USER_API dc_clr_control_bit(HANDLE icdev, unsigned char _b);

  /**
   * @brief  保留。
   */
  short USER_API dc_set_control_bit(HANDLE icdev, unsigned char _b);

  /**
   * @brief  复位射频。
   * @par    说明：
   * 复位设备的射频，可以关闭，关闭并且启动。
   * @param[in] icdev 设备标识符。
   * @param[in] _Msec 为0表示关闭射频，否则为复位时间，单位为10毫秒，一般调用建议值为10。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_reset(HANDLE icdev, unsigned short _Msec);

  /**
   * @brief  设备蜂鸣。
   * @par    说明：
   * 设备蜂鸣器发出指定时间的蜂鸣声。
   * @param[in] icdev 设备标识符。
   * @param[in] _Msec 蜂鸣时间，单位为10毫秒。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_beep(HANDLE icdev, unsigned short _Msec);

  /**
   * @brief  液晶显示。
   * @par    说明：
   * 显示指定字符串到液晶屏幕上。
   * @param[in] icdev 设备标识符。
   * @param[in] dispstr 要显示的字符串。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_disp_str(HANDLE icdev, char *dispstr);

  /**
   * @brief  读EEPROM。
   * @par    说明：
   * 读取设备内部EEPROM中的数据，可以用作数据保存等。
   * @param[in] icdev 设备标识符。
   * @param[in] offset 偏移地址。
   * @param[in] length 读取长度。
   * @param[out] rec_buffer 返回的数据。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_srd_eeprom(HANDLE icdev, short offset, short length, unsigned char *rec_buffer);

  /**
   * @brief  写EEPROM。
   * @par    说明：
   * 写入数据到设备内部EEPROM中，可以用作数据保存等。
   * @param[in] icdev 设备标识符。
   * @param[in] offset 偏移地址。
   * @param[in] length 写入长度。
   * @param[in] send_buffer 传入数据。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_swr_eeprom(HANDLE icdev, short offset, short length, unsigned char *send_buffer);

  /**
   * @brief  写EEPROM。
   * @par    说明：
   * 同 ::dc_swr_eeprom 。
   */
  short USER_API swr_alleeprom(HANDLE icdev, short offset, short length, unsigned char *snd_buffer);

  /**
   * @brief  读EEPROM。
   * @par    说明：
   * 同 ::dc_srd_eeprom 。
   */
  short USER_API srd_alleeprom(HANDLE icdev, short offset, short length, unsigned char *receive_buffer);

  /**
   * @brief  读EEPROM。
   * @par    说明：
   * ::dc_srd_eeprom 的HEX形式接口，参数 @a rec_buffer 为HEX格式。
   */
  short USER_API dc_srd_eepromhex(HANDLE icdev, short offset, short length, unsigned char *rec_buffer);

  /**
   * @brief  写EEPROM。
   * @par    说明：
   * ::dc_swr_eeprom 的HEX形式接口，参数 @a send_buffer 为HEX格式。
   */
  short USER_API dc_swr_eepromhex(HANDLE icdev, short offset, short length, unsigned char *send_buffer);

  /**
   * @brief  获取设备时间。
   * @par    说明：
   * 获取设备当前的时间。
   * @param[in] icdev 设备标识符。
   * @param[out] time 返回的时间，长度为7个字节，格式为'年'、'星期'、'月'、'日'、'时'、'分'、'秒'。如：0x16,0x01,0x12,0x08,0x16,0x20,0x10表示2016年星期一12月8日16时20分10秒。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_gettime(HANDLE icdev, unsigned char *time);

  /**
   * @brief  获取设备时间。
   * @par    说明：
   * ::dc_gettime 的HEX形式接口，参数 @a time 为HEX格式。
   */
  short USER_API dc_gettimehex(HANDLE icdev, char *time);

  /**
   * @brief  设置设备时间。
   * @par    说明：
   * 设置设备的当前时间。
   * @param[in] icdev 设备标识符。
   * @param[in] time 传入时间，长度为7个字节，格式为'年'、'星期'、'月'、'日'、'时'、'分'、'秒'。如：0x16,0x01,0x12,0x08,0x16,0x20,0x10表示2016年星期一12月8日16时20分10秒。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_settime(HANDLE icdev, unsigned char *time);

  /**
   * @brief  设置设备时间。
   * @par    说明：
   * ::dc_settime 的HEX形式接口，参数 @a time 为HEX格式。
   */
  short USER_API dc_settimehex(HANDLE icdev, char *time);

  /**
   * @brief  保留。
   */
  short USER_API dc_setbright(HANDLE icdev, unsigned char bright);

  /**
   * @brief  保留。
   */
  short USER_API dc_ctl_mode(HANDLE icdev, unsigned char mode);

  /**
   * @brief  保留。
   */
  short USER_API dc_disp_mode(HANDLE icdev, unsigned char mode);

  /**
   * @brief  单DES加解密。
   * @par    说明：
   * ::dcdes 的HEX形式接口，参数 @a key @a sour @a dest 为HEX格式。
   */
  short USER_API dcdeshex(unsigned char *key, unsigned char *sour, unsigned char *dest, short m);

  /**
   * @brief  单DES加解密。
   * @par    说明：
   * 使用单DES算法对数据进行加密/解密。
   * @param[in] key 8个字节密钥。
   * @param[in] sour 8个字节要做加密/解密的数据。
   * @param[out] dest 返回8个字节运算后的数据。
   * @param[in] m 模式，0-解密，1-加密。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dcdes(unsigned char *key, unsigned char *sour, unsigned char *dest, short m);

  /**
   * @brief  指示灯点亮/熄灭。
   * @par    说明：
   * 点亮/熄灭设备的指示灯。
   * @param[in] icdev 设备标识符。
   * @param[in] _OnOff 0-点亮，1-熄灭。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_light(HANDLE icdev, unsigned short _OnOff);

  /**
   * @brief  液晶显示。
   * @par    说明：
   * 显示指定数据到液晶屏幕上。
   * @param[in] icdev 设备标识符。
   * @param[in] offset 屏幕偏移。
   * @param[in] displen 显示数据的长度。
   * @param[in] dispstr 显示数据。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_high_disp(HANDLE icdev, unsigned char offset, unsigned char displen, unsigned char *dispstr);

  /**
   * @brief  设置当前接触式卡座。
   * @par    说明：
   * 设置当前接触式卡座为指定卡座，用于多卡座切换卡操作。
   * @param[in] icdev 设备标识符。
   * @param[in] _Byte 卡座编号。
   * @n 0x0C - 附卡座/接触式CPU1卡座。
   * @n 0x0B - 接触式CPU2卡座。
   * @n 0x0D - SAM1卡座。
   * @n 0x0E - SAM2卡座。
   * @n 0x0F - SAM3卡座。
   * @n 0x11 - SAM4卡座。
   * @n 0x12 - SAM5卡座。
   * @n 0x13 - SAM6卡座/ESAM芯片。
   * @n 0x14 - SAM7卡座。
   * @n 0x15 - SAM8卡座。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_setcpu(HANDLE icdev, unsigned char _Byte);

  /**
   * @brief  接触式CPU卡复位。
   * @par    说明：
   * 对当前卡座CPU卡进行复位操作，此复位为冷复位。
   * @param[in] icdev 设备标识符。
   * @param[out] rlen 返回复位信息的长度。
   * @param[out] databuffer 返回的复位信息，请至少分配128个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_cpureset(HANDLE icdev, unsigned char *rlen, unsigned char *databuffer);

  /**
   * @brief  接触式CPU卡指令交互。
   * @par    说明：
   * 对当前卡座CPU卡进行指令交互操作，注意此接口不封装卡协议部分。
   * @param[in] icdev 设备标识符。
   * @param[in] slen 发送数据的长度。
   * @param[in] sendbuffer 发送数据。
   * @param[out] rlen 返回数据的长度。
   * @param[out] databuffer 返回的数据。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_cpuapdusource(HANDLE icdev, unsigned char slen, unsigned char *sendbuffer, unsigned char *rlen, unsigned char *databuffer);

  /**
   * @brief  接触式CPU卡指令交互。
   * @par    说明：
   * 对当前卡座CPU卡进行指令交互操作，注意此接口已封装卡协议部分。
   * @param[in] icdev 设备标识符。
   * @param[in] slen 发送数据的长度。
   * @param[in] sendbuffer 发送数据。
   * @param[out] rlen 返回数据的长度。
   * @param[out] databuffer 返回的数据。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_cpuapdu(HANDLE icdev, unsigned char slen, unsigned char *sendbuffer, unsigned char *rlen, unsigned char *databuffer);

  /**
   * @brief  接触式CPU卡复位。
   * @par    说明：
   * ::dc_cpureset 的HEX形式接口，参数 @a databuffer 为HEX格式。
   */
  short USER_API dc_cpureset_hex(HANDLE icdev, unsigned char *rlen, char *databuffer);

  /**
   * @brief  接触式CPU卡指令交互。
   * @par    说明：
   * ::dc_cpuapdusource 的HEX形式接口，参数 @a sendbuffer @a databuffer 为HEX格式。
   */
  short USER_API dc_cpuapdusource_hex(HANDLE icdev, unsigned char slen, char *sendbuffer, unsigned char *rlen, char *databuffer);

  /**
   * @brief  接触式CPU卡指令交互。
   * @par    说明：
   * ::dc_cpuapdu 的HEX形式接口，参数 @a sendbuffer @a databuffer 为HEX格式。
   */
  short USER_API dc_cpuapdu_hex(HANDLE icdev, unsigned char slen, char *sendbuffer, unsigned char *rlen, char *databuffer);

  /**
   * @brief  接触式CPU卡指令交互。
   * @par    说明：
   * 对当前卡座CPU卡进行指令交互操作，注意此接口已封装卡协议部分，内部处理了SW1为0x61和0x6C的情况。
   * @param[in] icdev 设备标识符。
   * @param[in] slen 发送数据的长度。
   * @param[in] sendbuffer 发送数据。
   * @param[out] rlen 返回数据的长度。
   * @param[out] databuffer 返回的数据。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_cpuapdurespon(HANDLE icdev, unsigned char slen, unsigned char *sendbuffer, unsigned char *rlen, unsigned char *databuffer);

  /**
   * @brief  接触式CPU卡指令交互。
   * @par    说明：
   * ::dc_cpuapdurespon 的HEX形式接口，参数 @a sendbuffer @a databuffer 为HEX格式。
   */
  short USER_API dc_cpuapdurespon_hex(HANDLE icdev, unsigned char slen, char *sendbuffer, unsigned char *rlen, char *databuffer);

  /**
   * @brief  接触式CPU卡下电。
   * @par    说明：
   * 对当前卡座CPU卡进行下电操作。
   * @param[in] icdev 设备标识符。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_cpudown(HANDLE icdev);

  /**
   * @brief  保留。
   */
  short USER_API dc_set_addr(unsigned char saddr);

  /**
   * @brief  保留。
   */
  HANDLE USER_API dc_init_485(short port, int baud);

  /**
   * @brief  保留。
   */
  short USER_API dc_changebaud_485(HANDLE icdev, int baud);

  /**
   * @brief  保留。
   */
  short USER_API dc_change_addr(HANDLE icdev, unsigned char saddr);

  /**
   * @brief  非接触式CPU卡复位。
   * @par    说明：
   * 对感应区CPU卡进行复位操作。
   * @param[in] icdev 设备标识符。
   * @param[out] rlen 返回复位信息的长度。
   * @param[out] receive_data 返回的复位信息，请至少分配128个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_pro_reset(HANDLE icdev, unsigned char *rlen, unsigned char *receive_data);

  /**
   * @brief  非接触式CPU卡指令交互。
   * @par    说明：
   * 对感应区CPU卡进行指令交互操作，注意此接口已封装卡协议部分。
   * @param[in] icdev 设备标识符。
   * @param[in] slen 发送数据的长度。
   * @param[in] sendbuffer 发送数据。
   * @param[out] rlen 返回数据的长度。
   * @param[out] databuffer 返回的数据。
   * @param[in] timeout 超时值，此值只在部分设备的底层使用，单位为250毫秒，一般调用建议值为7。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_pro_command(HANDLE icdev, unsigned char slen, unsigned char *sendbuffer, unsigned char *rlen, unsigned char *databuffer, unsigned char timeout);

  /**
   * @brief  非接触式CPU卡复位。
   * @par    说明：
   * ::dc_pro_reset 的HEX形式接口，参数 @a receive_data 为HEX格式。
   */
  short USER_API dc_pro_resethex(HANDLE icdev, unsigned char *rlen, char *receive_data);

  /**
   * @brief  非接触式CPU卡复位。
   * @par    说明：
   * 对感应区CPU卡进行复位操作。
   * @param[in] icdev 设备标识符。
   * @param[out] rlen 返回复位信息的长度。
   * @param[out] receive_data 返回的复位信息，请至少分配128个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_pro_resetInt(HANDLE icdev, unsigned char *rlen, unsigned char *receive_data);

  /**
   * @brief  非接触式CPU卡复位。
   * @par    说明：
   * ::dc_pro_resetInt 的HEX形式接口，参数 @a receive_data 为HEX格式。
   */
  short USER_API dc_pro_resetInt_hex(HANDLE icdev, unsigned char *rlen, char *receive_data);

  /**
   * @brief  非接触式CPU卡指令交互。
   * @par    说明：
   * ::dc_pro_command 的HEX形式接口，参数 @a sendbuffer @a databuffer 为HEX格式。
   */
  short USER_API dc_pro_commandhex(HANDLE icdev, unsigned char slen, char *sendbuffer, unsigned char *rlen, char *databuffer, unsigned char timeout);

  /**
   * @brief  非接触式CPU卡指令交互。
   * @par    说明：
   * 对感应区CPU卡进行指令交互操作，注意此接口不封装卡协议部分。
   * @param[in] icdev 设备标识符。
   * @param[in] slen 发送数据的长度。
   * @param[in] sendbuffer 发送数据。
   * @param[out] rlen 返回数据的长度。
   * @param[out] databuffer 返回的数据。
   * @param[in] timeout 超时值，此值只在部分设备的底层使用，单位为250毫秒，一般调用建议值为7。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_pro_commandsource(HANDLE icdev, unsigned char slen, unsigned char *sendbuffer, unsigned char *rlen, unsigned char *databuffer, unsigned char timeout);

  /**
   * @brief  非接触式CPU卡指令交互。
   * @par    说明：
   * ::dc_pro_commandsource 的HEX形式接口，参数 @a sendbuffer @a databuffer 为HEX格式。
   */
  short USER_API dc_pro_commandsourcehex(HANDLE icdev, unsigned char slen, char *sendbuffer, unsigned char *rlen, char *databuffer, unsigned char timeout);

  /**
   * @brief  非接触式CPU卡指令交互。
   * @par    说明：
   * 对感应区CPU卡进行指令交互操作，注意此接口不封装卡协议部分。
   * @param[in] icdev 设备标识符。
   * @param[in] slen 发送数据的长度。
   * @param[in] sendbuffer 发送数据。
   * @param[out] rlen 返回数据的长度。
   * @param[out] databuffer 返回的数据。
   * @param[in] timeout 超时值，此值只在部分设备的底层使用，单位为250毫秒，一般调用建议值为7。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_pro_commandsource_int(HANDLE icdev, unsigned int slen, unsigned char *sendbuffer, unsigned int *rlen, unsigned char *databuffer, unsigned char timeout);

  /**
   * @brief  终止非接触式CPU卡操作。
   * @par    说明：
   * 使非接触式CPU卡进入终止状态，此时必须把卡移出感应区后再次放入感应区才能寻到这张卡。
   * @param[in] icdev 设备标识符。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_pro_halt(HANDLE icdev);

  /**
   * @brief  SHC1102卡寻卡请求。
   * @par    说明：
   * 支持SHC1102卡的寻卡请求。
   * @param[in] icdev 设备标识符。
   * @param[in] _Mode 模式，0x00表示对空闲卡进行操作，0x01表示对所有卡操作。
   * @param[out] TagType 返回的ATQA值。
   * @return <0表示失败，==0表示成功，==1表示无卡或无法寻到卡片。
   */
  short USER_API dc_request_shc1102(HANDLE icdev, unsigned char _Mode, unsigned short *TagType);

  /**
   * @brief  验证SHC1102卡密码。
   * @par    说明：
   * 使用传入的密码来验证SHC1102卡密码。
   * @param[in] icdev 设备标识符。
   * @param[in] _Data 密码，固定为4个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_auth_shc1102(HANDLE icdev, unsigned char *_Data);

  /**
   * @brief  读SHC1102卡。
   * @par    说明：
   * 读取SHC1102卡的数据。
   * @param[in] icdev 设备标识符。
   * @param[in] _Adr 块地址（0~15）。
   * @param[out] _Data 返回的数据，固定为4个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_read_shc1102(HANDLE icdev, unsigned char _Adr, unsigned char *_Data);

  /**
   * @brief  写SHC1102卡。
   * @par    说明：
   * 写入数据到SHC1102卡中。
   * @param[in] icdev 设备标识符。
   * @param[in] _Adr 块地址（2~15）。
   * @param[in] _Data 传入数据，固定为4个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_write_shc1102(HANDLE icdev, unsigned char _Adr, unsigned char *_Data);

  /**
   * @brief  终止SHC1102卡操作。
   * @par    说明：
   * 使SHC1102卡进入终止状态，此时必须把卡移出感应区后再次放入感应区才能寻到这张卡。
   * @param[in] icdev 设备标识符。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_halt_shc1102(HANDLE icdev);

  /**
   * @brief  数据转换。
   * @par    说明：
   * 普通数据换成十六进制字符串（短转长）。
   * @param[in] hex 要转换的数据。
   * @param[out] a 转换后的字符串。
   * @param[in] length 要转换数据的长度。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API hex_a(unsigned char *hex, unsigned char *a, short length);

  /**
   * @brief  数据转换。
   * @par    说明：
   * 十六进制字符数据转换为普通数据（长转短）。
   * @param[in] a 要转换的数据。
   * @param[out] hex 转换后的数据。
   * @param[in] len 要转换数据的长度。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API a_hex(unsigned char *a, unsigned char *hex, short len);

  /**
   * @brief  配置非接触卡类型。
   * @par    说明：
   * 配置需要操作什么类型的非接触式卡，设备上电后默认操作Type A卡，可以使用此接口来改变类型，一般在寻卡前调用此接口。
   * @param[in] icdev 设备标识符。
   * @param[in] cardtype 类型，'A'表示Type A卡，'B'表示Type B卡。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_config_card(HANDLE icdev, unsigned char cardtype);

  /**
   * @brief  寻卡请求。
   * @par    说明：
   * 支持ISO 14443 Type B类型卡片的寻卡请求。
   * @param[in] icdev 设备标识符。
   * @param[in] _Mode 保留，固定为0x00。
   * @param[in] AFI 应用族标识符。
   * @param[in] N 时间槽编号。
   * @param[out] ATQB 返回的ATQB值，请至少分配32个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_request_b(HANDLE icdev, unsigned char _Mode, unsigned char AFI, unsigned char N, unsigned char *ATQB);

  /**
   * @brief  管道标记。
   * @par    说明：
   * 支持ISO 14443 Type B类型卡片的管道标记。
   * @param[in] icdev 设备标识符。
   * @param[in] N 时间槽编号。
   * @param[out] ATQB 返回的ATQB值，请至少分配32个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_slotmarker(HANDLE icdev, unsigned char N, unsigned char *ATQB);

  /**
   * @brief  激活卡片。
   * @par    说明：
   * 支持ISO 14443 Type B类型卡片的激活。
   * @param[in] icdev 设备标识符。
   * @param[in] PUPI 伪唯一PICC标识符，固定为4个字节。
   * @param[in] CID 信道号。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_attrib(HANDLE icdev, unsigned char *PUPI, unsigned char CID);

  /**
   * @brief  保留。
   */
  short USER_API dc_open_door(HANDLE icdev, unsigned char cflag);

  /**
   * @brief  保留。
   */
  short USER_API dc_open_timedoor(HANDLE icdev, unsigned short utime);

  /**
   * @brief  保留。
   */
  short USER_API dc_read_random(HANDLE icdev, unsigned char *data);

  /**
   * @brief  保留。
   */
  short USER_API dc_write_random(HANDLE icdev, short length, unsigned char *data);

  /**
   * @brief  保留。
   */
  short USER_API dc_read_random_hex(HANDLE icdev, unsigned char *data);

  /**
   * @brief  保留。
   */
  short USER_API dc_write_random_hex(HANDLE icdev, short length, unsigned char *data);

  /**
   * @brief  保留。
   */
  short USER_API dc_erase_random(HANDLE icdev, short length);

  /**
   * @brief  Mifare Desfire卡认证。
   * @par    说明：
   * 对Mifare Desfire卡进行认证。
   * @param[in] icdev 设备标识符。
   * @param[in] keyno 密钥号。
   * @param[in] keylen 密钥数据的长度。
   * @param[in] authkey 密钥数据。
   * @param[in] randAdata 传入随机数A，8个字节。
   * @param[out] randBdata 返回的随机数B，8个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_mfdes_auth(HANDLE icdev, unsigned char keyno, unsigned char keylen, unsigned char *authkey, unsigned char *randAdata, unsigned char *randBdata);

  /**
   * @brief  验证M1卡密码。
   * @par    说明：
   * 使用传入的密码来验证M1卡密码。
   * @param[in] icdev 设备标识符。
   * @param[in] _Mode 模式，0x00表示验证A密码，0x04表示验证B密码。
   * @param[in] _Addr 要验证密码的扇区号。
   * @param[in] passbuff 密码，固定为6个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_authentication_pass(HANDLE icdev, unsigned char _Mode, unsigned char _Addr, unsigned char *passbuff);

  /**
   * @brief  高层液晶显示。
   * @par    说明：
   * 显示指定数据到液晶屏幕上。
   * @param[in] icdev 设备标识符。
   * @param[in] dispstr 显示字符串。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_disp_neg(HANDLE icdev, char *dispstr);

  /**
   * @brief  非接触式CPU卡指令交互。
   * @par    说明：
   * 对感应区CPU卡进行指令交互操作，注意此接口已封装卡协议部分。
   * @param[in] icdev 设备标识符。
   * @param[in] slen 发送数据的长度。
   * @param[in] sendbuffer 发送数据。
   * @param[out] rlen 返回数据的长度。
   * @param[out] databuffer 返回的数据。
   * @param[in] timeout 超时值，此值只在部分设备的底层使用，单位为250毫秒，一般调用建议值为7。
   * @param[in] FG 分割值，此值只在部分设备的底层使用，单位为字节，一般调用建议值为64。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_pro_commandlink(HANDLE icdev, unsigned char slen, unsigned char *sendbuffer, unsigned char *rlen, unsigned char *databuffer, unsigned char timeout, unsigned char FG);

  /**
   * @brief  非接触式CPU卡指令交互。
   * @par    说明：
   * ::dc_pro_commandlink 的HEX形式接口，参数 @a sendbuffer @a databuffer 为HEX格式。
   */
  short USER_API dc_pro_commandlink_hex(HANDLE icdev, unsigned char slen, unsigned char *sendbuffer, unsigned char *rlen, unsigned char *databuffer, unsigned char timeout, unsigned char FG);

  /**
   * @brief  寻卡请求、防卡冲突、选卡操作。
   * @par    说明：
   * 内部包含了 ::dc_request ::dc_anticoll ::dc_select ::dc_anticoll2 ::dc_select2 的功能，此接口有设计缺陷，不能返回卡序列号实际长度，建议使用 ::dc_card_n 替代。
   * @param[in] icdev 设备标识符。
   * @param[in] _Mode 模式，同 ::dc_request 的 @a _Mode 。
   * @param[out] _Snr 返回的卡序列号，请至少分配8个字节。
   * @return <0表示失败，==0表示成功，==1表示无卡或无法寻到卡片。
   */
  short USER_API dc_card_double(HANDLE icdev, unsigned char _Mode, unsigned char *_Snr);

  /**
   * @brief  寻卡请求、防卡冲突、选卡操作。
   * @par    说明：
   * ::dc_card_double 的HEX形式接口，参数 @a _Snr 为HEX格式。
   */
  short USER_API dc_card_double_hex(HANDLE icdev, unsigned char _Mode, unsigned char *_Snr);

  /**
   * @brief  读ID卡。
   * @par    说明：
   * 读取ID卡数据。
   * @param[in] icdev 设备标识符。
   * @param[in] times 设备超时值，单位为秒。
   * @param[out] _Data 返回的数据，固定为5个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_read_idcard(HANDLE icdev, unsigned char times, unsigned char *_Data);

  /**
   * @brief  读取id卡。
   * @par    说明：
   * ::dc_read_idcard 的HEX形式接口，参数 @a _Data 为HEX格式。
   */
  short USER_API dc_read_idcard_hex(HANDLE icdev, unsigned char times, unsigned char *_Data);

  /**
   * @brief  验证M1卡密码。
   * @par    说明：
   * ::dc_authentication_pass 的HEX形式接口，参数 @a passbuff 为HEX格式。
   */
  short USER_API dc_authentication_pass_hex(HANDLE icdev, unsigned char _Mode, unsigned char _Addr, unsigned char *passbuff);

  /**
   * @brief  设置接触式CPU卡参数。
   * @par    说明：
   * 此接口可控制接触式CPU卡操作的行为，当不掉用时，设备将使用默认方式进行接触式CPU卡操作。
   * @param[in] icdev 设备标识符。
   * @param[in] cputype 卡座编号，同 ::dc_setcpu 的 @a _Byte 。
   * @param[in] cpupro 卡协议编号，0x00表示T0，0x01表示T1，默认为0x00。
   * @param[in] cpuetu 卡复位波特率编号，0x5C表示9600，0x14表示38400.
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_setcpupara(HANDLE icdev, unsigned char cputype, unsigned char cpupro, unsigned char cpuetu);

  /**
   * @brief  保留。
   */
  short USER_API dc_command(HANDLE icdev, unsigned char cmd, unsigned char slen, unsigned char *sendbuffer, unsigned char *rlen, unsigned char *databuffer);

  /**
   * @brief  保留。
   */
  short USER_API dc_command_hex(HANDLE icdev, unsigned char cmd, unsigned char slen, char *sendbuffer, unsigned char *rlen, char *databuffer);

  /**
   * @brief  保留。
   */
  short USER_API dc_creat_mac(unsigned char KeyLen, unsigned char *Key, unsigned short DataLen, unsigned char *Data, unsigned char *InitData, unsigned char AutoFixFlag, unsigned char FixChar, unsigned char *MacData);

  /**
   * @brief  保留。
   */
  short USER_API dc_creat_mac_hex(unsigned char KeyLen, unsigned char *Key, unsigned short DataLen, unsigned char *Data, unsigned char *InitData, unsigned char AutoFixFlag, unsigned char FixChar, unsigned char *MacData);

  /**
   * @brief  保留。
   */
  short USER_API dc_creat_mac2(HANDLE icdev, unsigned short DataLen, unsigned char *Data, unsigned char *MacData, unsigned char flag);

  /**
   * @brief  保留。
   */
  short USER_API dc_creat_mac2_hex(HANDLE icdev, unsigned short DataLen, unsigned char *Data, unsigned char *MacData, unsigned char flag);

  /**
   * @brief  保留。
   */
  short USER_API dc_encrypt(char *key, char *ptrSource, unsigned short msgLen, char *ptrDest);

  /**
   * @brief  保留。
   */
  short USER_API dc_decrypt(char *key, char *ptrSource, unsigned short msgLen, char *ptrDest);

  /**
   * @brief  保留。
   */
  short USER_API dc_encrypt_hex(char *key, char *ptrSource, unsigned short msgLen, char *ptrDest);

  /**
   * @brief  保留。
   */
  short USER_API dc_decrypt_hex(char *key, char *ptrSource, unsigned short msgLen, char *ptrDest);

  /**
   * @brief  保留。
   */
  short USER_API dc_HL_write_hex(HANDLE icdev, unsigned char _Mode, unsigned char _Adr, unsigned int *_Snr, unsigned char *_Data);

  /**
   * @brief  保留。
   */
  short USER_API dc_HL_read_hex(HANDLE icdev, unsigned char _Mode, unsigned char _Adr, unsigned int _Snr, unsigned char *_Data, unsigned int *_NSnr);

  /**
   * @brief  检查之前写入的数据。
   * @par    说明：
   * ::dc_check_write 的HEX形式接口，参数 @a _data 为HEX格式。
   */
  short USER_API dc_check_write_hex(HANDLE icdev, unsigned int Snr, unsigned char authmode, unsigned char Adr, unsigned char *_data);

  /**
   * @brief  读EEPROM。
   * @par    说明：
   * ::dc_srd_eeprom 的HEX形式接口，参数 @a rec_buffer 为HEX格式。
   */
  short USER_API dc_srd_eeprom_hex(HANDLE icdev, short offset, short length, unsigned char *rec_buffer);

  /**
   * @brief  写EEPROM。
   * @par    说明：
   * ::dc_swr_eeprom 的HEX形式接口，参数 @a send_buffer 为HEX格式。
   */
  short USER_API dc_swr_eeprom_hex(HANDLE icdev, short offset, short length, unsigned char *send_buffer);

  /**
   * @brief  获取设备时间。
   * @par    说明：
   * ::dc_gettime 的HEX形式接口，参数 @a time 为HEX格式。
   */
  short USER_API dc_gettime_hex(HANDLE icdev, char *time);

  /**
   * @brief  设置设备时间。
   * @par    说明：
   * ::dc_settime 的HEX形式接口，参数 @a time 为HEX格式。
   */
  short USER_API dc_settime_hex(HANDLE icdev, char *time);

  /**
   * @brief  单DES加解密。
   * @par    说明：
   * ::dc_des 的HEX形式接口，参数 @a key @a sour @a dest 为HEX格式。
   */
  short USER_API dc_des_hex(unsigned char *key, unsigned char *sour, unsigned char *dest, short m);

  /**
   * @brief  单DES加解密。
   * @par    说明：
   * 使用单DES算法对数据进行加密/解密。
   * @param[in] key 8个字节密钥。
   * @param[in] sour 8个字节要做加密/解密的数据。
   * @param[out] dest 返回8个字节运算后的数据。
   * @param[in] m 模式，0-解密，1-加密。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_des(unsigned char *key, unsigned char *sour, unsigned char *dest, short m);

  /**
   * @brief  非接触式CPU卡复位。
   * @par    说明：
   * ::dc_pro_reset 的HEX形式接口，参数 @a receive_data 为HEX格式。
   */
  short USER_API dc_pro_reset_hex(HANDLE icdev, unsigned char *rlen, char *receive_data);

  /**
   * @brief  非接触式CPU卡指令交互。
   * @par    说明：
   * ::dc_pro_command 的HEX形式接口，参数 @a sendbuffer @a databuffer 为HEX格式。
   */
  short USER_API dc_pro_command_hex(HANDLE icdev, unsigned char slen, char *sendbuffer, unsigned char *rlen, char *databuffer, unsigned char timeout);

  /**
   * @brief  非接触式CPU卡指令交互。
   * @par    说明：
   * ::dc_pro_commandsource 的HEX形式接口，参数 @a sendbuffer @a databuffer 为HEX格式。
   */
  short USER_API dc_pro_commandsource_hex(HANDLE icdev, unsigned char slen, char *sendbuffer, unsigned char *rlen, char *databuffer, unsigned char timeout);

  /**
   * @brief  保留。
   */
  short USER_API dc_switch_unix(HANDLE icdev, int baud);

  /**
   * @brief  验证M1卡密码。
   * @par    说明：
   * 使用传入的密码来验证M1卡密码。
   * @param[in] icdev 设备标识符。
   * @param[in] _Mode 模式，0x00表示验证A密码，0x04表示验证B密码。
   * @param[in] _Addr 要验证密码的块号。
   * @param[in] passbuff 密码，固定为6个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_authentication_passaddr(HANDLE icdev, unsigned char _Mode, unsigned char _Addr, unsigned char *passbuff);

  /**
   * @brief  验证M1卡密码。
   * @par    说明：
   * ::dc_authentication_passaddr 的HEX形式接口，参数 @a passbuff 为HEX格式。
   */
  short USER_API dc_authentication_passaddr_hex(HANDLE icdev, unsigned char _Mode, unsigned char _Addr, unsigned char *passbuff);

  /**
   * @brief  寻FM11RF005卡。
   * @par    说明：
   * 对FM11RF005卡进行寻卡操作。
   * @param[in] icdev 设备标识符。
   * @param[in] _Mode 模式，模式，同 ::dc_request 的 @a _Mode 。
   * @param[out] _Snr 返回的卡序列号。
   * @return <0表示失败，==0表示成功，==1表示无卡或无法寻到卡片。
   */
  short USER_API dc_card_fm11rf005(HANDLE icdev, unsigned char _Mode, unsigned int *_Snr);

  /**
   * @brief  保留。
   */
  short USER_API dc_setusbtimeout(unsigned char ntimes);

  /**
   * @brief  保留。
   */
  short USER_API dc_mfdes_baud(HANDLE icdev, unsigned char _Mode, unsigned char para);

  /**
   * @brief  三DES加解密。
   * @par    说明：
   * 使用三DES算法对数据进行加密/解密。
   * @param[in] key 16个字节密钥。
   * @param[in] src 8个字节要做加密/解密的数据。
   * @param[out] dest 返回8个字节运算后的数据。
   * @param[in] m 模式，0-解密，1-加密。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_tripledes(unsigned char *key, unsigned char *src, unsigned char *dest, short m);

  /**
   * @brief  三DES加解密。
   * @par    说明：
   * ::dc_tripledes 的HEX形式接口，参数 @a key @a src @a dest 为HEX格式。
   */
  short USER_API dc_tripledes_hex(unsigned char *key, unsigned char *src, unsigned char *dest, short m);

  /**
   * @brief  Mifare Desfire卡认证。
   * @par    说明：
   * ::dc_mfdes_auth 的HEX形式接口，参数 @a authkey @a randAdata @a randBdata 为HEX格式。
   */
  short USER_API dc_mfdes_auth_hex(HANDLE icdev, unsigned char keyno, unsigned char keylen, unsigned char *authkey, unsigned char *randAdata, unsigned char *randBdata);

  /**
   * @brief  保留。
   */
  short USER_API dc_pro_sendcommandsource(HANDLE icdev, unsigned char slen, unsigned char *sendbuffer, unsigned char timeout);

  /**
   * @brief  保留。
   */
  short USER_API dc_pro_receivecommandsource(HANDLE icdev, unsigned char *rlen, unsigned char *databuffer);

  /**
   * @brief  保留。
   */
  short USER_API dc_inventory(HANDLE icdev, unsigned char flags, unsigned char AFI, unsigned char masklen, unsigned char *rlen, unsigned char *rbuffer);

  /**
   * @brief  保留。
   */
  short USER_API dc_inventory_hex(HANDLE icdev, unsigned char flags, unsigned char AFI, unsigned char masklen, unsigned char *rlen, unsigned char *rbuffer);

  /**
   * @brief  保留。
   */
  short USER_API dc_stay_quiet(HANDLE icdev, unsigned char flags, unsigned char *UID);

  /**
   * @brief  保留。
   */
  short USER_API dc_stay_quiet_hex(HANDLE icdev, unsigned char flags, unsigned char *UID);

  /**
   * @brief  保留。
   */
  short USER_API dc_select_uid(HANDLE icdev, unsigned char flags, unsigned char *UID);

  /**
   * @brief  保留。
   */
  short USER_API dc_select_uid_hex(HANDLE icdev, unsigned char flags, unsigned char *UID);

  /**
   * @brief  保留。
   */
  short USER_API dc_reset_to_ready(HANDLE icdev, unsigned char flags, unsigned char *UID);

  /**
   * @brief  保留。
   */
  short USER_API dc_reset_to_ready_hex(HANDLE icdev, unsigned char flags, unsigned char *UID);

  /**
   * @brief  保留。
   */
  short USER_API dc_readblock(HANDLE icdev, unsigned char flags, unsigned char startblock, unsigned char blocknum, unsigned char *UID, unsigned char *rlen, unsigned char *rbuffer);

  /**
   * @brief  保留。
   */
  short USER_API dc_readblock_hex(HANDLE icdev, unsigned char flags, unsigned char startblock, unsigned char blocknum, unsigned char *UID, unsigned char *rlen, unsigned char *rbuffer);

  /**
   * @brief  保留。
   */
  short USER_API dc_writeblock(HANDLE icdev, unsigned char flags, unsigned char startblock, unsigned char blocknum, unsigned char *UID, unsigned char wlen, unsigned char *wbuffer);

  /**
   * @brief  保留。
   */
  short USER_API dc_writeblock_hex(HANDLE icdev, unsigned char flags, unsigned char startblock, unsigned char blocknum, unsigned char *UID, unsigned char wlen, unsigned char *wbuffer);

  /**
   * @brief  保留。
   */
  short USER_API dc_lock_block(HANDLE icdev, unsigned char flags, unsigned char block, unsigned char *UID);

  /**
   * @brief  保留。
   */
  short USER_API dc_lock_block_hex(HANDLE icdev, unsigned char flags, unsigned char block, unsigned char *UID);

  /**
   * @brief  保留。
   */
  short USER_API dc_write_afi(HANDLE icdev, unsigned char flags, unsigned char AFI, unsigned char *UID);

  /**
   * @brief  保留。
   */
  short USER_API dc_write_afi_hex(HANDLE icdev, unsigned char flags, unsigned char AFI, unsigned char *UID);

  /**
   * @brief  保留。
   */
  short USER_API dc_lock_afi(HANDLE icdev, unsigned char flags, unsigned char AFI, unsigned char *UID);

  /**
   * @brief  保留。
   */
  short USER_API dc_lock_afi_hex(HANDLE icdev, unsigned char flags, unsigned char AFI, unsigned char *UID);

  /**
   * @brief  保留。
   */
  short USER_API dc_write_dsfid(HANDLE icdev, unsigned char flags, unsigned char DSFID, unsigned char *UID);

  /**
   * @brief  保留。
   */
  short USER_API dc_write_dsfid_hex(HANDLE icdev, unsigned char flags, unsigned char DSFID, unsigned char *UID);

  /**
   * @brief  保留。
   */
  short USER_API dc_lock_dsfid(HANDLE icdev, unsigned char flags, unsigned char DSFID, unsigned char *UID);

  /**
   * @brief  保留。
   */
  short USER_API dc_lock_dsfid_hex(HANDLE icdev, unsigned char flags, unsigned char DSFID, unsigned char *UID);

  /**
   * @brief  保留。
   */
  short USER_API dc_get_systeminfo(HANDLE icdev, unsigned char flags, unsigned char *UID, unsigned char *rlen, unsigned char *rbuffer);

  /**
   * @brief  保留。
   */
  short USER_API dc_get_systeminfo_hex(HANDLE icdev, unsigned char flags, unsigned char *UID, unsigned char *rlen, unsigned char *rbuffer);

  /**
   * @brief  保留。
   */
  short USER_API dc_get_securityinfo(HANDLE icdev, unsigned char flags, unsigned char startblock, unsigned char blocknum, unsigned char *UID, unsigned char *rlen, unsigned char *rbuffer);

  /**
   * @brief  保留。
   */
  short USER_API dc_get_securityinfo_hex(HANDLE icdev, unsigned char flags, unsigned char startblock, unsigned char blocknum, unsigned char *UID, unsigned char *rlen, unsigned char *rbuffer);

  /**
   * @brief  获取FM11RF005卡序列号。
   * @par    说明：
   * 获取FM11RF005卡序列号。
   * @param[in] icdev 设备标识符。
   * @param[out] _Snr 返回的卡序列号。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_getsnr_fm11rf005(HANDLE icdev, unsigned int *_Snr);

  /**
   * @brief  获取FM11RF005卡序列号。
   * @par    说明：
   * ::dc_getsnr_fm11rf005 的HEX形式接口，参数 @a snrstr 为HEX格式。
   */
  short USER_API dc_getsnr_fm11rf005_hex(HANDLE icdev, unsigned char *snrstr);

  /**
   * @brief  写FM11RF005卡。
   * @par    说明：
   * 写入数据到FM11RF005卡中。
   * @param[in] icdev 设备标识符。
   * @param[in] _Adr 块地址（2~15）。
   * @param[in] _Data 传入数据，固定为4个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_write_fm11rf005(HANDLE icdev, unsigned char _Adr, unsigned char *_Data);

  /**
   * @brief  读FM11RF005卡。
   * @par    说明：
   * 读取FM11RF005卡的数据。
   * @param[in] icdev 设备标识符。
   * @param[in] _Adr 块地址（0~15）。
   * @param[out] _Data 返回的数据，固定为4个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_read_fm11rf005(HANDLE icdev, unsigned char _Adr, unsigned char *_Data);

  /**
   * @brief  读FM11RF005卡。
   * @par    说明：
   * ::dc_read_fm11rf005 的HEX形式接口，参数 @a _Data 为HEX格式。
   */
  short USER_API dc_read_fm11rf005_hex(HANDLE icdev, unsigned char _Adr, char *_Data);

  /**
   * @brief  写FM11RF005卡。
   * @par    说明：
   * ::dc_write_fm11rf005 的HEX形式接口，参数 @a _Data 为HEX格式。
   */
  short USER_API dc_write_fm11rf005_hex(HANDLE icdev, unsigned char _Adr, char *_Data);

  /**
   * @brief  保留。
   */
  short USER_API DCDEV_CommandMcu(HANDLE icdev, unsigned char ctimeout, unsigned char slen, unsigned char *sendbuffer, unsigned char *rlen, unsigned char *databuffer);

  /**
   * @brief  保留。
   */
  short USER_API DCDEV_CommandMcu_Hex(HANDLE icdev, unsigned char ctimeout, unsigned char slen, unsigned char *sendbuffer, unsigned char *rlen, unsigned char *databuffer);

  /**
   * @brief  保留。
   */
  short USER_API dc_displcd(HANDLE icdev, unsigned char flag);

  /**
   * @brief  键盘密码输入。
   * @par    说明：
   * 获取键盘按键，用于密码输入，不同的键盘装置可能有不同的效果，如不同的提示音或不同的显示。
   * @param[in] icdev 设备标识符。
   * @param[in] ctime 设备超时值，单位为秒。
   * @param[out] rlen 返回按键数据的长度，不含'\0'。
   * @param[out] cpass 返回的按键数据，数据格式为'\0'结尾的字符串。
   * @return <0表示失败，==0表示成功，==0xA1表示取消输入，==0xA2表示输入超时。
   */
  short USER_API dc_getinputpass(HANDLE icdev, unsigned char ctime, unsigned char *rlen, unsigned char *cpass);

  /**
   * @brief  键盘密码输入。
   * @par    说明：
   * 获取键盘按键，用于密码输入，不同的键盘装置可能有不同的效果，如不同的提示音或不同的显示。
   * @param[in] icdev 设备标识符。
   * @param[in] ctime 设备超时值，单位为秒。
   * @param[out] rlen 返回按键数据的长度，不含'\0'。
   * @param[out] cpass 返回的按键数据，数据格式为'\0'结尾的字符串。
   * @return <0表示失败，==0表示成功，==0xA1表示取消输入，==0xA2表示输入超时。
   */
  short USER_API dc_GetInputPass(HANDLE icdev, unsigned char ctime, unsigned char *rlen, unsigned char *cpass);

  /**
   * @brief  读磁条卡。
   * @par    说明：
   * 读取磁条卡的数据，支持2、3轨道。
   * @param[in] icdev 设备标识符。
   * @param[in] ctime 设备超时值，单位为秒。
   * @param[out] pTrack2Data 返回的2轨道数据，数据格式为'\0'结尾的字符串。
   * @param[out] pTrack2Len 返回2轨道数据的长度，不含'\0'。
   * @param[out] pTrack3Data 返回的3轨道数据，数据格式为'\0'结尾的字符串。
   * @param[out] pTrack3Len 返回3轨道数据的长度，不含'\0'。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_readmagcard(HANDLE icdev, unsigned char ctime, unsigned char *pTrack2Data, unsigned int *pTrack2Len, unsigned char *pTrack3Data, unsigned int *pTrack3Len);

  /**
   * @brief  写磁条卡。
   * @par    说明：
   * 写入数据到磁条卡中。
   * @param[in] icdev 设备标识符。
   * @param[in] ctime 设备超时值，单位为秒。
   * @param[in] pTrack1Data 传入1轨道数据。
   * @param[in] pTrack1Len 1轨道数据的长度。
   * @param[in] pTrack2Data 传入2轨道数据。
   * @param[in] pTrack2Len 2轨道数据的长度。
   * @param[in] pTrack3Data 传入3轨道数据。
   * @param[in] pTrack3Len 3轨道数据的长度。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_writemagcard(HANDLE icdev, unsigned char ctime, unsigned char *pTrack1Data, unsigned char pTrack1Len, unsigned char *pTrack2Data, unsigned char pTrack2Len, unsigned char *pTrack3Data, unsigned char pTrack3Len);

  /**
   * @brief  测试设备通讯。
   * @par    说明：
   * 测试和设备之间是否可以正常通讯。
   * @param[in] icdev 设备标识符。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_testdevicecomm(HANDLE icdev);

  /**
   * @brief  显示主界面。
   * @par    说明：
   * 使设备屏幕上显示预置的主界面，不同设备的主界面不尽相同。
   * @param[in] icdev 设备标识符。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_dispmainmenu(HANDLE icdev);

  /**
   * @brief  设置设备时间。
   * @par    说明：
   * 设置设备的当前时间。
   * @param[in] icdev 设备标识符。
   * @param[in] year 年（0~99）。
   * @param[in] month 月（1~12）。
   * @param[in] date 日（1~31）。
   * @param[in] hour 时（0~23）。
   * @param[in] minute 分（0~59）。
   * @param[in] second 秒（0~59）。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_setdevicetime(HANDLE icdev, unsigned char year, unsigned char month, unsigned char date, unsigned char hour, unsigned char minute, unsigned char second);

  /**
   * @brief  获取设备时间。
   * @par    说明：
   * 获取设备当前的时间。
   * @param[out] icdev 设备标识符。
   * @param[out] year 年（0~99）。
   * @param[out] month 月（1~12）。
   * @param[out] date 日（1~31）。
   * @param[out] hour 时（0~23）。
   * @param[out] minute 分（0~59）。
   * @param[out] second 秒（0~59）。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_getdevicetime(HANDLE icdev, unsigned char *year, unsigned char *month, unsigned char *date, unsigned char *hour, unsigned char *minute, unsigned char *second);

  /**
   * @brief  液晶显示。
   * @par    说明：
   * 显示指定字符串到液晶屏幕上。
   * @param[in] icdev 设备标识符。
   * @param[in] line 行号。
   * @param[in] offset 偏移。
   * @param[in] data 要显示的字符串。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_dispinfo(HANDLE icdev, unsigned char line, unsigned char offset, char *data);

  /**
   * @brief  液晶显示。
   * @par    说明：
   * 显示指定字符串到液晶屏幕上。
   * @param[in] icdev 设备标识符。
   * @param[in] offset 屏幕偏移。
   * @param[in] data 要显示的字符串。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_dispmaininfo(HANDLE icdev, unsigned char offset, char *data);

  /**
   * @brief  设备蜂鸣。
   * @par    说明：
   * 设备蜂鸣器发出指定时间的蜂鸣声。
   * @param[in] icdev 设备标识符。
   * @param[in] beeptime 蜂鸣时间，单位为50毫秒。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_posbeep(HANDLE icdev, unsigned char beeptime);

  /**
   * @brief  LCD背光控制。
   * @par    说明：
   * 控制设备的LCD背光。
   * @param[in] icdev 设备标识符。
   * @param[in] cOpenFlag 0-开背光，1-关背光。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_ctlbacklight(HANDLE icdev, unsigned char cOpenFlag);

  /**
   * @brief  指示灯控制。
   * @par    说明：
   * 控制设备的指示灯。
   * @param[in] icdev 设备标识符。
   * @param[in] cLed 指示灯编号，0表示全部指示灯，1表示第一个指示灯，2表示第二个指示灯，以此类推。
   * @param[in] cOpenFlag 0-点亮，1-熄灭，2-闪烁。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_ctlled(HANDLE icdev, unsigned char cLed, unsigned char cOpenFlag);

  /**
   * @brief  LCD清屏。
   * @par    说明：
   * 清除LCD屏幕的显示内容。
   * @param[in] icdev 设备标识符。
   * @param[in] cLine 需要清除的行号，编号从1开始。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_lcdclrscrn(HANDLE icdev, unsigned char cLine);

  /**
   * @brief  进入读键盘模式。
   * @par    说明：
   * 使设备进入读取键盘的状态，接口本身会直接返回，而不会等待按键完成或设备超时。
   * @param[in] icdev 设备标识符。
   * @param[in] ctime 设备超时值，单位为秒。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_passin(HANDLE icdev, unsigned char ctime);

  /**
   * @brief  进入读键盘模式。
   * @par    说明：
   * 使设备进入读取键盘的状态，接口本身会直接返回，而不会等待按键完成或设备超时。
   * @param[in] icdev 设备标识符。
   * @param[in] ctime 设备超时值，单位为秒。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_PassIn(HANDLE icdev, unsigned char ctime);

  /**
   * @brief  进入读键盘模式。
   * @par    说明：
   * 使设备进入读取键盘的状态，接口本身会直接返回，而不会等待按键完成或设备超时。
   * @param[in] icdev 设备标识符。
   * @param[in] ctime 设备超时值，单位为秒。
   * @param[in] ucmode 模式，0-带卡号，1-不带卡号。
   * @param[in] cardno 卡号字符串，只用于带卡号的模式。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_passin2(HANDLE icdev, unsigned char ctime, unsigned char ucmode, unsigned char *cardno);

  /**
   * @brief  进入读键盘模式。
   * @par    说明：
   * 使设备进入读取键盘的状态，接口本身会直接返回，而不会等待按键完成或设备超时。
   * @param[in] icdev 设备标识符。
   * @param[in] ctime 设备超时值，单位为秒。
   * @param[in] ucmode 模式，0-带卡号，1-不带卡号。
   * @param[in] cardno 卡号字符串，只用于带卡号的模式。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_PassIn2(HANDLE icdev, unsigned char ctime, unsigned char ucmode, unsigned char *cardno);

  /**
   * @brief  获取键盘数据。
   * @par    说明：
   * 获取设备已经读取到的键盘数据。
   * @param[in] icdev 设备标识符。
   * @param[out] rlen 返回按键数据的长度，不含'\0'。
   * @param[out] cpass 返回的按键数据，数据格式为'\0'结尾的字符串。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_passget(HANDLE icdev, unsigned char *rlen, unsigned char *cpass);

  /**
   * @brief  获取键盘数据。
   * @par    说明：
   * 获取设备已经读取到的键盘数据。
   * @param[in] icdev 设备标识符。
   * @param[out] rlen 返回按键数据的长度，不含'\0'。
   * @param[out] cpass 返回的按键数据，数据格式为'\0'结尾的字符串。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_PassGet(HANDLE icdev, unsigned char *rlen, unsigned char *cpass);

  /**
   * @brief  退出读键盘模式。
   * @par    说明：
   * 在设备进入读键盘模式后，设备会一直处于接收键盘输入的状态，这时只有按键完成、设备超时或调用此接口才能使得设备退出这种状态。
   * @param[in] icdev 设备标识符。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_passcancel(HANDLE icdev);

  /**
   * @brief  退出读键盘模式。
   * @par    说明：
   * 在设备进入读键盘模式后，设备会一直处于接收键盘输入的状态，这时是只有按键完成、设备超时或调用此接口才能使得设备退出这种状态。
   * @param[in] icdev 设备标识符。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_PassCancel(HANDLE icdev);

  /**
   * @brief  获取键盘输入。
   * @par    说明：
   * 获取键盘按键，同时设置输入时屏幕显示的信息。
   * @param[in] icdev 设备标识符。
   * @param[in] disptype 显示类型，此类型与设备内置显示条目相关。
   * @param[in] line 行号，信息将会显示在此行号指定的行中。
   * @param[in] ctime 设备超时值，单位为秒。
   * @param[out] rlen 返回按键数据的长度，不含'\0'。
   * @param[out] ckeydata 返回的按键数据，数据格式为'\0'结尾的字符串。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_getinputkey(HANDLE icdev, unsigned char disptype, unsigned char line, unsigned char ctime, unsigned char *rlen, unsigned char *ckeydata);

  /**
   * @brief  保留。
   */
  short USER_API dc_displcd_ext(HANDLE icdev, unsigned char flag, unsigned char row, unsigned char offset);

  /**
   * @brief  读磁条卡。
   * @par    说明：
   * 读取磁条卡的数据，支持1、2、3轨道。
   * @param[in] icdev 设备标识符。
   * @param[in] ctime 设备超时值，单位为秒。
   * @param[out] pTrack1Data 返回的1轨道数据，数据格式为'\0'结尾的字符串。
   * @param[out] pTrack1Len 返回1轨道数据的长度，不含'\0'。
   * @param[out] pTrack2Data 返回的2轨道数据，数据格式为'\0'结尾的字符串。
   * @param[out] pTrack2Len 返回2轨道数据的长度，不含'\0'。
   * @param[out] pTrack3Data 返回的3轨道数据，数据格式为'\0'结尾的字符串。
   * @param[out] pTrack3Len 返回3轨道数据的长度，不含'\0'。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_readmagcardall(HANDLE icdev, unsigned char ctime, unsigned char *pTrack1Data, unsigned int *pTrack1Len, unsigned char *pTrack2Data, unsigned int *pTrack2Len, unsigned char *pTrack3Data, unsigned int *pTrack3Len);

  /**
   * @brief  获取设备序列号。
   * @par    说明：
   * 获取设备内部定制的序列号，设备默认序列号为空，只有预先定制的设备才会存在可用的序列号。
   * @param[in] icdev 设备标识符。
   * @param[out] snr 返回的序列号字符串，请至少分配33个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_readdevsnr(HANDLE icdev, unsigned char *snr);

  /**
   * @brief  获取设备序列号。
   * @par    说明：
   * 获取设备内部定制的序列号，设备默认序列号为空，只有预先定制的设备才会存在可用的序列号。
   * @param[in] icdev 设备标识符。
   * @param[out] snr 返回的序列号字符串，请至少分配17个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_readreadersnr(HANDLE icdev, unsigned char *snr);

  /**
   * @brief  复位设备。
   * @par    说明：
   * 使设备进入上电初始状态。
   * @param[in] icdev 设备标识符。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_resetdevice(HANDLE icdev);

  /**
   * @brief  设置串口设备通讯波特率。
   * @par    说明：
   * 设置串口设备通讯波特率。
   * @param[in] icdev 设备标识符。
   * @param[in] baud 波特率。
   * @n 0x00 - 115200。
   * @n 0x01 - 57600。
   * @n 0x02 - 38400。
   * @n 0x03 - 19200。
   * @n 0x04 - 9600。
   * @n 0x05 - 4800。
   * @n 0x06 - 2400。
   * @n 0x07 - 1200。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_setdevicebaud(HANDLE icdev, unsigned char baud);

  /**
   * @brief  读4442卡。
   * @par    说明：
   * 读取4442卡的数据。
   * @param[in] icdev 设备标识符。
   * @param[in] offset 偏移。
   * @param[in] length 读取长度。
   * @param[out] data_buffer 返回的数据。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_read_4442(HANDLE icdev, short offset, short length, unsigned char *data_buffer);

  /**
   * @brief  读4442卡。
   * @par    说明：
   * ::dc_read_4442 的HEX形式接口，参数 @a data_buffer 为HEX格式。
   */
  short USER_API dc_read_4442_hex(HANDLE icdev, short offset, short length, unsigned char *data_buffer);

  /**
   * @brief  写4442卡。
   * @par    说明：
   * 写入数据到4442卡中。
   * @param[in] icdev 设备标识符。
   * @param[in] offset 偏移。
   * @param[in] length 写入长度。
   * @param[in] data_buffer 传入数据。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_write_4442(HANDLE icdev, short offset, short length, unsigned char *data_buffer);

  /**
   * @brief  写4442卡。
   * @par    说明：
   * ::dc_write_4442 的HEX形式接口，参数 @a data_buffer 为HEX格式。
   */
  short USER_API dc_write_4442_hex(HANDLE icdev, short offset, short length, unsigned char *data_buffer);

  /**
   * @brief  验证4442卡密码。
   * @par    说明：
   * 使用传入的密码来验证4442卡密码。
   * @param[in] icdev 设备标识符。
   * @param[in] passwd 密码，固定为3个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_verifypin_4442(HANDLE icdev, unsigned char *passwd);

  /**
   * @brief  验证4442卡密码。
   * @par    说明：
   * ::dc_verifypin_4442 的HEX形式接口，参数 @a passwd 为HEX格式。
   */
  short USER_API dc_verifypin_4442_hex(HANDLE icdev, unsigned char *passwd);

  /**
   * @brief  读4442卡密码。
   * @par    说明：
   * 读取4442卡的密码。
   * @param[in] icdev 设备标识符。
   * @param[out] passwd 密码，固定为3个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_readpin_4442(HANDLE icdev, unsigned char *passwd);

  /**
   * @brief  读4442卡密码。
   * @par    说明：
   * ::dc_readpin_4442 的HEX形式接口，参数 @a passwd 为HEX格式。
   */
  short USER_API dc_readpin_4442_hex(HANDLE icdev, unsigned char *passwd);

  /**
   * @brief  读4442卡密码计数。
   * @par    说明：
   * 读取4442卡的密码计数，此计数值表示可以尝试验证密码的次数。
   * @param[in] icdev 设备标识符。
   * @return <0表示失败，否则为密码计数值。
   */
  short USER_API dc_readpincount_4442(HANDLE icdev);

  /**
   * @brief  修改4442卡密码。
   * @par    说明：
   * 修改4442卡的密码。
   * @param[in] icdev 设备标识符。
   * @param[in] passwd 密码，固定为3个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_changepin_4442(HANDLE icdev, unsigned char *passwd);

  /**
   * @brief  修改4442卡密码。
   * @par    说明：
   * ::dc_changepin_4442 的HEX形式接口，参数 @a passwd 为HEX格式。
   */
  short USER_API dc_changepin_4442_hex(HANDLE icdev, unsigned char *passwd);

  /**
   * @brief  读4442卡保护位。
   * @par    说明：
   * 读取4442卡的保护区中哪些位置已经被置保护。
   * @param[in] icdev 设备标识符。
   * @param[in] offset 偏移。
   * @param[in] length 读取长度。
   * @param[out] data_buffer 返回的数据，数据中含有0x00字节的位置表示已经被置保护。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_readwrotect_4442(HANDLE icdev, short offset, short length, unsigned char *data_buffer);

  /**
   * @brief  读4442卡保护位。
   * @par    说明：
   * ::dc_readwrotect_4442 的HEX形式接口，参数 @a data_buffer 为HEX格式。
   */
  short USER_API dc_readwrotect_4442_hex(HANDLE icdev, short offset, short length, unsigned char *data_buffer);

  /**
   * @brief  读4442卡保护位。
   * @par    说明：
   * 读取4442卡的保护区中哪些位置已经被置保护。
   * @param[in] icdev 设备标识符。
   * @param[in] offset 偏移。
   * @param[in] length 读取长度。
   * @param[out] data_buffer 返回的数据，数据中含有0x00字节的位置表示已经被置保护。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_readprotect_4442(HANDLE icdev, short offset, short length, unsigned char *data_buffer);

  /**
   * @brief  读4442卡保护位。
   * @par    说明：
   * ::dc_readprotect_4442 的HEX形式接口，参数 @a data_buffer 为HEX格式。
   */
  short USER_API dc_readprotect_4442_hex(HANDLE icdev, short offset, short length, unsigned char *data_buffer);

  /**
   * @brief  写4442卡保护位。
   * @par    说明：
   * 对4442卡的保护区中指定位置进行置保护。
   * @param[in] icdev 设备标识符。
   * @param[in] offset 偏移。
   * @param[in] length 写入长度。
   * @param[in] data_buffer 传入数据，数据中和卡内原有数据相同的字节位置将被置保护。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_writeprotect_4442(HANDLE icdev, short offset, short length, unsigned char *data_buffer);

  /**
   * @brief  写4442卡保护位。
   * @par    说明：
   * ::dc_writeprotect_4442 的HEX形式接口，参数 @a data_buffer 为HEX格式。
   */
  short USER_API dc_writeprotect_4442_hex(HANDLE icdev, short offset, short length, unsigned char *data_buffer);

  /**
   * @brief  写24C系列卡。
   * @par    说明：
   * 写入数据到24C系列卡中，支持24C01、24C02、24C04、24C08、24C16卡。
   * @param[in] icdev 设备标识符。
   * @param[in] offset 偏移。
   * @param[in] length 写入长度。
   * @param[in] snd_buffer 传入数据。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_write_24c(HANDLE icdev, short offset, short length, unsigned char *snd_buffer);

  /**
   * @brief  写24C系列卡。
   * @par    说明：
   * ::dc_write_24c 的HEX形式接口，参数 @a snd_buffer 为HEX格式。
   */
  short USER_API dc_write_24c_hex(HANDLE icdev, short offset, short length, unsigned char *snd_buffer);

  /**
   * @brief  写24C64系列卡。
   * @par    说明：
   * 写入数据到24C64系列卡中，支持24C64、24C512、24C1024卡。
   * @param[in] icdev 设备标识符。
   * @param[in] offset 偏移。
   * @param[in] length 写入长度。
   * @param[in] snd_buffer 传入数据。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_write_24c64(HANDLE icdev, short offset, short length, unsigned char *snd_buffer);

  /**
   * @brief  写24C64系列卡。
   * @par    说明：
   * ::dc_write_24c64 的HEX形式接口，参数 @a snd_buffer 为HEX格式。
   */
  short USER_API dc_write_24c64_hex(HANDLE icdev, short offset, short length, unsigned char *snd_buffer);

  /**
   * @brief  读24C系列卡。
   * @par    说明：
   * 读取24C系列卡的数据，支持24C01、24C02、24C04、24C08、24C16卡。
   * @param[in] icdev 设备标识符。
   * @param[in] offset 偏移。
   * @param[in] length 读取长度。
   * @param[out] receive_buffer 返回的数据。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_read_24c(HANDLE icdev, short offset, short length, unsigned char *receive_buffer);

  /**
   * @brief  读24C系列卡。
   * @par    说明：
   * ::dc_read_24c 的HEX形式接口，参数 @a receive_buffer 为HEX格式。
   */
  short USER_API dc_read_24c_hex(HANDLE icdev, short offset, short length, unsigned char *receive_buffer);

  /**
   * @brief  读24C64系列卡。
   * @par    说明：
   * 读取24C64系列卡的数据，支持24C64、24C512、24C1024卡。
   * @param[in] icdev 设备标识符。
   * @param[in] offset 偏移。
   * @param[in] length 读取长度。
   * @param[out] receive_buffer 返回的数据。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_read_24c64(HANDLE icdev, short offset, short length, unsigned char *receive_buffer);

  /**
   * @brief  读24C64系列卡。
   * @par    说明：
   * ::dc_read_24c64 的HEX形式接口，参数 @a receive_buffer 为HEX格式。
   */
  short USER_API dc_read_24c64_hex(HANDLE icdev, short offset, short length, unsigned char *receive_buffer);

  /**
   * @brief  读4428卡。
   * @par    说明：
   * 读取4428卡的数据。
   * @param[in] icdev 设备标识符。
   * @param[in] offset 偏移。
   * @param[in] length 读取长度。
   * @param[out] data_buffer 返回的数据。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_read_4428(HANDLE icdev, short offset, short length, unsigned char *data_buffer);

  /**
   * @brief  读4428卡。
   * @par    说明：
   * ::dc_read_4428 的HEX形式接口，参数 @a data_buffer 为HEX格式。
   */
  short USER_API dc_read_4428_hex(HANDLE icdev, short offset, short length, unsigned char *data_buffer);

  /**
   * @brief  写4428卡。
   * @par    说明：
   * 写入数据到4428卡中。
   * @param[in] icdev 设备标识符。
   * @param[in] offset 偏移。
   * @param[in] length 写入长度。
   * @param[in] data_buffer 传入数据。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_write_4428(HANDLE icdev, short offset, short length, unsigned char *data_buffer);

  /**
   * @brief  写4428卡。
   * @par    说明：
   * ::dc_write_4428 的HEX形式接口，参数 @a data_buffer 为HEX格式。
   */
  short USER_API dc_write_4428_hex(HANDLE icdev, short offset, short length, unsigned char *data_buffer);

  /**
   * @brief  验证4428卡密码。
   * @par    说明：
   * 使用传入的密码来验证4428卡密码。
   * @param[in] icdev 设备标识符。
   * @param[in] passwd 密码，固定为2个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_verifypin_4428(HANDLE icdev, unsigned char *passwd);

  /**
   * @brief  验证4428卡密码。
   * @par    说明：
   * ::dc_verifypin_4428 的HEX形式接口，参数 @a passwd 为HEX格式。
   */
  short USER_API dc_verifypin_4428_hex(HANDLE icdev, unsigned char *passwd);

  /**
   * @brief  读4428卡密码。
   * @par    说明：
   * 读取4428卡的密码。
   * @param[in] icdev 设备标识符。
   * @param[out] passwd 密码，固定为2个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_readpin_4428(HANDLE icdev, unsigned char *passwd);

  /**
   * @brief  读4428卡密码。
   * @par    说明：
   * ::dc_readpin_4428 的HEX形式接口，参数 @a passwd 为HEX格式。
   */
  short USER_API dc_readpin_4428_hex(HANDLE icdev, unsigned char *passwd);

  /**
   * @brief  读4428卡密码计数。
   * @par    说明：
   * 读取4428卡的密码计数，此计数值表示可以尝试验证密码的次数。
   * @param[in] icdev 设备标识符。
   * @return <0表示失败，否则为密码计数值。
   */
  short USER_API dc_readpincount_4428(HANDLE icdev);

  /**
   * @brief  修改4428卡密码。
   * @par    说明：
   * 修改4428卡的密码。
   * @param[in] icdev 设备标识符。
   * @param[in] passwd 密码，固定为2个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_changepin_4428(HANDLE icdev, unsigned char *passwd);

  /**
   * @brief  修改4428卡密码。
   * @par    说明：
   * ::dc_changepin_4428 的HEX形式接口，参数 @a passwd 为HEX格式。
   */
  short USER_API dc_changepin_4428_hex(HANDLE icdev, unsigned char *passwd);

  /**
   * @brief  读4428卡保护位。
   * @par    说明：
   * 读取4428卡的保护区中哪些位置已经被置保护。
   * @param[in] icdev 设备标识符。
   * @param[in] offset 偏移。
   * @param[in] length 读取长度。
   * @param[out] data_buffer 返回的数据，数据中含有0x00字节的位置表示已经被置保护。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_readprotect_4428(HANDLE icdev, short offset, short length, unsigned char *data_buffer);

  /**
   * @brief  读4428卡保护位。
   * @par    说明：
   * ::dc_readprotect_4428 的HEX形式接口，参数 @a data_buffer 为HEX格式。
   */
  short USER_API dc_readprotect_4428_hex(HANDLE icdev, short offset, short length, unsigned char *data_buffer);

  /**
   * @brief  写4428卡保护位。
   * @par    说明：
   * 对4428卡的保护区中指定位置进行置保护。
   * @param[in] icdev 设备标识符。
   * @param[in] offset 偏移。
   * @param[in] length 写入长度。
   * @param[in] data_buffer 传入数据，数据中和卡内原有数据相同的字节位置将被置保护。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_writeprotect_4428(HANDLE icdev, short offset, short length, unsigned char *data_buffer);

  /**
   * @brief  写4428卡保护位。
   * @par    说明：
   * ::dc_writeprotect_4428 的HEX形式接口，参数 @a data_buffer 为HEX格式。
   */
  short USER_API dc_writeprotect_4428_hex(HANDLE icdev, short offset, short length, unsigned char *data_buffer);

  /**
   * @brief  检测4442卡。
   * @par    说明：
   * 检测当前卡座中是否存在4442卡。
   * @param[in] icdev 设备标识符。
   * @return <0表示失败或不存在，==0表示存在。
   */
  short USER_API dc_Check_4442(HANDLE icdev);

  /**
   * @brief  检测4428卡。
   * @par    说明：
   * 检测当前卡座中是否存在4428卡。
   * @param[in] icdev 设备标识符。
   * @return <0表示失败或不存在，==0表示存在。
   */
  short USER_API dc_Check_4428(HANDLE icdev);

  /**
   * @brief  检测24C01卡。
   * @par    说明：
   * 检测当前卡座中是否存在24C01卡。
   * @param[in] icdev 设备标识符。
   * @return <0表示失败或不存在，==0表示存在。
   */
  short USER_API dc_Check_24C01(HANDLE icdev);

  /**
   * @brief  检测24C02卡。
   * @par    说明：
   * 检测当前卡座中是否存在24C02卡。
   * @param[in] icdev 设备标识符。
   * @return <0表示失败或不存在，==0表示存在。
   */
  short USER_API dc_Check_24C02(HANDLE icdev);

  /**
   * @brief  检测24C04卡。
   * @par    说明：
   * 检测当前卡座中是否存在24C04卡。
   * @param[in] icdev 设备标识符。
   * @return <0表示失败或不存在，==0表示存在。
   */
  short USER_API dc_Check_24C04(HANDLE icdev);

  /**
   * @brief  检测24C08卡。
   * @par    说明：
   * 检测当前卡座中是否存在24C08卡。
   * @param[in] icdev 设备标识符。
   * @return <0表示失败或不存在，==0表示存在。
   */
  short USER_API dc_Check_24C08(HANDLE icdev);

  /**
   * @brief  检测24C16卡。
   * @par    说明：
   * 检测当前卡座中是否存在24C16卡。
   * @param[in] icdev 设备标识符。
   * @return <0表示失败或不存在，==0表示存在。
   */
  short USER_API dc_Check_24C16(HANDLE icdev);

  /**
   * @brief  检测24C64卡。
   * @par    说明：
   * 检测当前卡座中是否存在24C64卡。
   * @param[in] icdev 设备标识符。
   * @return <0表示失败或不存在，==0表示存在。
   */
  short USER_API dc_Check_24C64(HANDLE icdev);

  /**
   * @brief  检测CPU卡。
   * @par    说明：
   * 检测当前卡座中是否存在CPU卡。
   * @param[in] icdev 设备标识符。
   * @return <0表示失败或不存在，==0表示存在T=0的CPU卡，==1表示存在T=1的CPU卡。
   */
  short USER_API dc_Check_CPU(HANDLE icdev);

  /**
   * @brief  检测卡。
   * @par    说明：
   * 检测当前卡座中存在的卡类型。
   * @param[in] icdev 设备标识符。
   * @return <0表示失败或不存在。
   * @n 8 - 表示存在4442卡。
   * @n 9 - 表示存在4428卡。
   * @n 30 - 表示存在T=0的CPU卡。
   * @n 31 - 表示存在T=1的CPU卡。
   * @n 21 - 表示存在24C01卡。
   * @n 22 - 表示存在24C02卡。
   * @n 23 - 表示存在24C04卡。
   * @n 24 - 表示存在24C08卡。
   * @n 25 - 表示存在24C16卡。
   * @n 26 - 表示存在24C64卡。
   */
  short USER_API dc_CheckCard(HANDLE icdev);

  /**
   * @brief  保留。
   */
  short USER_API dc_getrcinfo(HANDLE icdev, unsigned char *info);

  /**
   * @brief  保留。
   */
  short USER_API dc_getrcinfo_hex(HANDLE icdev, unsigned char *info);

  /**
   * @brief  获取设备长版本。
   * @par    说明：
   * 获取设备内部固件代码的长版本，此长版本依赖设备内部固件代码的实现，有可能同设备版本一致。
   * @param[in] icdev 设备标识符。
   * @param[out] sver 返回的版本字符串，请至少分配128个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_getlongver(HANDLE icdev, unsigned char *sver);

  /**
   * @brief  寻卡请求、防卡冲突、选卡操作。
   * @par    说明：
   * 内部包含了 ::dc_request ::dc_anticoll ::dc_select 的功能。
   * @param[in] icdev 设备标识符。
   * @param[in] _Mode 模式，同 ::dc_request 的 @a _Mode 。
   * @param[out] Strsnr 返回的卡序列号，格式为数字字符串。
   * @return <0表示失败，==0表示成功，==1表示无卡或无法寻到卡片。
   */
  short USER_API dc_cardstr(HANDLE icdev, unsigned char _Mode, char *Strsnr);

  /**
   * @brief  寻Type A或Type B卡并激活。
   * @par    说明：
   * 对Type A或Type B卡进行寻卡和激活。
   * @param[in] icdev 设备标识符。
   * @param[out] rlen 返回激活信息的长度。
   * @param[out] rbuf 返回的激活信息，请至少分配128个字节。
   * @param[out] type 类型，'A'表示Type A卡，'B'表示Type B卡。
   * @return <0表示失败，==0表示成功，==1表示无卡或无法寻到卡片。
   */
  short USER_API dc_cardAB(HANDLE icdev, unsigned char *rlen, unsigned char *rbuf, unsigned char *type);

  /**
   * @brief  寻Type B卡并激活。
   * @par    说明：
   * 对Type B卡进行寻卡和激活。
   * @param[in] icdev 设备标识符。
   * @param[out] rbuf 返回的激活信息，请至少分配128个字节。
   * @return <0表示失败，==0表示成功，==1表示无卡或无法寻到卡片。
   */
  short USER_API dc_card_b(HANDLE icdev, unsigned char *rbuf);

  /**
   * @brief  寻Type B卡并激活。
   * @par    说明：
   * ::dc_card_b 的HEX形式接口，参数 @a rbuf 为HEX格式。
   */
  short USER_API dc_card_b_hex(HANDLE icdev, char *rbuf);

  /**
   * @brief  液晶显示。
   * @par    说明：
   * 显示指定字符串到液晶屏幕上。
   * @param[in] icdev 设备标识符。
   * @param[in] line 行号。
   * @param[in] offset 偏移。
   * @param[in] data 要显示的字符串。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_dispinfo_T8(HANDLE icdev, unsigned char line, unsigned char offset, char *data);

  /**
   * @brief  液晶显示。
   * @par    说明：
   * 显示指定字符串到液晶屏幕上。
   * @param[in] icdev 设备标识符。
   * @param[in] offset 屏幕偏移。
   * @param[in] data 要显示的字符串。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_dispinfo_pro_T8(HANDLE icdev, unsigned char offset, char *data);

  /**
   * @brief  LCD清屏。
   * @par    说明：
   * 清除LCD屏幕的显示内容。
   * @param[in] icdev 设备标识符。
   * @param[in] line 需要清除的行号，编号从1开始。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_clearlcd_T8(HANDLE icdev, unsigned char line);

  /**
   * @brief  指示灯点亮/熄灭。
   * @par    说明：
   * 点亮/熄灭设备的指示灯。
   * @param[in] icdev 设备标识符。
   * @param[in] cled 指示灯编号，0表示全部指示灯，1表示第一个指示灯，2表示第二个指示灯，以此类推。
   * @param[in] cflag 0-点亮，1-熄灭。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_led_T8(HANDLE icdev, unsigned char cled, unsigned char cflag);

  /**
   * @brief  保留。
   */
  short USER_API dc_dispmap_T8(HANDLE icdev, unsigned char *mapdata);

  /**
   * @brief  保留。
   */
  short USER_API dc_displow_T8(HANDLE icdev, unsigned char rs, unsigned char cdata);

  /**
   * @brief  读/写射频寄存器。
   * @par    说明：
   * 从射频寄存器读取值或写入值到射频寄存器中。
   * @param[in] icdev 设备标识符。
   * @param[in] flag 读写标记，0x00表示读，0x01表示写。
   * @param[in] _Adr 寄存器地址。
   * @param[in,out] _Data 寄存器值，固定为1个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_rw_rfreg(HANDLE icdev, unsigned char flag, unsigned char _Adr, unsigned char *_Data);

  /**
   * @brief  读/写射频寄存器。
   * @par    说明：
   * ::dc_rw_rfreg 的HEX形式接口，参数 @a _Data 为HEX格式。
   */
  short USER_API dc_rw_rfreg_hex(HANDLE icdev, unsigned char flag, unsigned char _Adr, unsigned char *_Data);

  /**
   * @brief  保留。
   */
  short USER_API dc_mulrequest_b(HANDLE icdev, unsigned char _Mode, unsigned char AFI, unsigned char *cardnum, unsigned char *mulATQB);

  /**
   * @brief  保留。
   */
  short USER_API dc_hltb(HANDLE icdev, unsigned char *PUPI);

  /**
   * @brief  保留。
   */
  short USER_API dc_set_poweroff(HANDLE icdev, unsigned int MsTimes, unsigned char TimerClock, unsigned char TimerReload);

  /**
   * @brief  非接触式CPU卡指令交互。
   * @par    说明：
   * 对感应区CPU卡进行指令交互操作，注意此接口不封装卡协议部分，带CRC。
   * @param[in] icdev 设备标识符。
   * @param[in] slen 发送数据的长度。
   * @param[in] sendbuffer 发送数据。
   * @param[out] rlen 返回数据的长度。
   * @param[out] databuffer 返回的数据。
   * @param[in] timeout 超时值，此值只在部分设备的底层使用，单位为250毫秒，一般调用建议值为7。
   * @param[in] CRCSTU CRC值。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_pro_commandsourceCRC(HANDLE icdev, unsigned char slen, unsigned char *sendbuffer, unsigned char *rlen, unsigned char *databuffer, unsigned char timeout, unsigned char CRCSTU);

  /**
   * @brief  非接触式CPU卡指令交互。
   * @par    说明：
   * ::dc_pro_commandsourceCRC 的HEX形式接口，参数 @a sendbuffer @a databuffer 为HEX格式。
   */
  short USER_API dc_pro_commandsourceCRChex(HANDLE icdev, unsigned char slen, char *sendbuffer, unsigned char *rlen, char *databuffer, unsigned char timeout, unsigned char CRCSTU);

  /**
   * @brief  Mifare Plus卡设置个人化数据（0级）。
   * @par    说明：
   * 设置Mifare Plus卡的个人化数据。
   * @param[in] icdev 设备标识符。
   * @param[in] BNr 要写入的个人化数据块号。
   * @param[in] dataperso 要写入的数据，固定为16个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_MFPL0_writeperso(HANDLE icdev, unsigned int BNr, unsigned char *dataperso);

  /**
   * @brief  Mifare Plus卡设置个人化数据（0级）。
   * @par    说明：
   * ::dc_MFPL0_writeperso 的HEX形式接口，参数 @a dataperso 为HEX格式。
   */
  short USER_API dc_MFPL0_writeperso_hex(HANDLE icdev, unsigned int BNr, unsigned char *dataperso);

  /**
   * @brief  Mifare Plus卡提交个人化数据（0级）。
   * @par    说明：
   * 提交Mifare Plus卡的个人化数据，提交成功后卡片进入1级状态。
   * @param[in] icdev 设备标识符。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_MFPL0_commitperso(HANDLE icdev);

  /**
   * @brief  验证Mifare Plus卡状态密码（1级）。
   * @par    说明：
   * 验证Mifare Plus卡状态密码，用于在1级状态下实现严格的认证。
   * @param[in] icdev 设备标识符。
   * @param[in] authkey 认证密码，固定为16个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_MFPL1_authl1key(HANDLE icdev, unsigned char *authkey);

  /**
   * @brief  验证Mifare Plus卡状态密码（1级）。
   * @par    说明：
   * ::dc_MFPL1_authl1key 的HEX形式接口，参数 @a authkey 为HEX格式。
   */
  short USER_API dc_MFPL1_authl1key_hex(HANDLE icdev, unsigned char *authkey);

  /**
   * @brief  升级Mifare Plus卡状态到2级（1级）。
   * @par    说明：
   * 状态切换函数，执行该操作后，1级状态的卡片转换到2级。
   * @param[in] icdev 设备标识符。
   * @param[in] authkey 升级密码，固定为16个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_MFPL1_switchtol2(HANDLE icdev, unsigned char *authkey);

  /**
   * @brief  升级Mifare Plus卡状态到3级（1级）。
   * @par    说明：
   * 状态切换函数，执行该操作后，1级状态的卡片转换到3级。
   * @param[in] icdev 设备标识符。
   * @param[in] authkey 升级密码，固定为16个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_MFPL1_switchtol3(HANDLE icdev, unsigned char *authkey);

  /**
   * @brief  升级Mifare Plus卡状态到3级（2级）。
   * @par    说明：
   * 状态切换函数，执行该操作后，2级状态的卡片转换到3级。
   * @param[in] icdev 设备标识符。
   * @param[in] authkey 升级密码，固定为16个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_MFPL2_switchtol3(HANDLE icdev, unsigned char *authkey);

  /**
   * @brief  验证Mifare Plus卡状态密码（3级）。
   * @par    说明：
   * 执行3级状态卡片认证，根据密码块号的不同，验证不同的密码。
   * @param[in] icdev 设备标识符。
   * @param[in] keyBNr 密码块号。
   * @param[in] authkey 认证密码，固定为16个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_MFPL3_authl3key(HANDLE icdev, unsigned int keyBNr, unsigned char *authkey);

  /**
   * @brief  验证Mifare Plus卡状态密码（3级）。
   * @par    说明：
   * ::dc_MFPL3_authl3key 的HEX形式接口，参数 @a authkey 为HEX格式。
   */
  short USER_API dc_MFPL3_authl3key_hex(HANDLE icdev, unsigned int keyBNr, unsigned char *authkey);

  /**
   * @brief  验证Mifare Plus卡状态密码（3级）。
   * @par    说明：
   * 执行3级状态卡片认证，根据密码扇区号的不同，验证不同的密码。
   * @param[in] icdev 设备标识符。
   * @param[in] mode 模式，0x00表示验证A密码，内部用0x4000+sectorBNr*2计算密码块，0x04表示验证B密码，内部用0x4000+sectorBNr*2+1计算密码块。
   * @param[in] sectorBNr 密码扇区号。
   * @param[in] authkey 认证密码，固定为16个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_MFPL3_authl3sectorkey(HANDLE icdev, unsigned char mode, unsigned int sectorBNr, unsigned char *authkey);

  /**
   * @brief  验证Mifare Plus卡状态密码（3级）。
   * @par    说明：
   * ::dc_MFPL3_authl3key 的HEX形式接口，参数 @a authkey 为HEX格式。
   */
  short USER_API dc_MFPL3_authl3sectorkey_hex(HANDLE icdev, unsigned char mode, unsigned int sectorBNr, unsigned char *authkey);

  /**
   * @brief  读Mifare Plus卡数据（3级）。
   * @par    说明：
   * 在3级状态下读取Mifare Plus卡数据，可以连续读多块，每块16字节。
   * @param[in] icdev 设备标识符。
   * @param[in] BNr 起始块地址。
   * @param[in] Numblock 块数目，一般不大于6块。
   * @param[out] readdata 返回的数据。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_MFPL3_readinplain(HANDLE icdev, unsigned int BNr, unsigned char Numblock, unsigned char *readdata);

  /**
   * @brief  读Mifare Plus卡数据（3级）。
   * @par    说明：
   * ::dc_MFPL3_readinplain 的HEX形式接口，参数 @a readdata 为HEX格式。
   */
  short USER_API dc_MFPL3_readinplain_hex(HANDLE icdev, unsigned int BNr, unsigned char Numblock, unsigned char *readdata);

  /**
   * @brief  加密模式读Mifare Plus卡数据（3级）。
   * @par    说明：
   * 在3级状态下用加密模式读取Mifare Plus卡数据，可以连续读多块，每块16字节。
   * @param[in] icdev 设备标识符。
   * @param[in] BNr 起始块地址。
   * @param[in] Numblock 块数目，一般不大于6块。
   * @param[out] readdata 返回的数据。
   * @param[in] flag 标记，0x00表示加密数据内部解密后再返回，0x01表示加密数据直接返回。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_MFPL3_readencrypted(HANDLE icdev, unsigned int BNr, unsigned char Numblock, unsigned char *readdata, unsigned char flag);

  /**
   * @brief  加密模式读Mifare Plus卡数据（3级）。
   * @par    说明：
   * ::dc_MFPL3_readencrypted 的HEX形式接口，参数 @a readdata 为HEX格式。
   */
  short USER_API dc_MFPL3_readencrypted_hex(HANDLE icdev, unsigned int BNr, unsigned char Numblock, unsigned char *readdata, unsigned char flag);

  /**
   * @brief  写Mifare Plus卡数据（3级）。
   * @par    说明：
   * 在3级状态下写入数据到Mifare Plus卡中，可以连续写多块，每块16字节。
   * @param[in] icdev 设备标识符。
   * @param[in] BNr 起始块地址。
   * @param[in] Numblock 块数目，一般不大于6块。
   * @param[in] writedata 传入数据。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_MFPL3_writeinplain(HANDLE icdev, unsigned int BNr, unsigned char Numblock, unsigned char *writedata);

  /**
   * @brief  写Mifare Plus卡数据（3级）。
   * @par    说明：
   * ::dc_MFPL3_writeinplain 的HEX形式接口，参数 @a writedata 为HEX格式。
   */
  short USER_API dc_MFPL3_writeinplain_hex(HANDLE icdev, unsigned int BNr, unsigned char Numblock, unsigned char *writedata);

  /**
   * @brief  加密模式写Mifare Plus卡数据（3级）。
   * @par    说明：
   * 在3级状态下用加密模式写入数据到Mifare Plus卡中，可以连续写多块，每块16字节。注意：写密码时，必须使用此函数并且块数目只能为1。
   * @param[in] icdev 设备标识符。
   * @param[in] BNr 起始块地址。
   * @param[in] Numblock 块数目，一般不大于6块。
   * @param[in] writedata 传入数据。
   * @param[in] flag 标记，0x00表示传入数据需内部加密后再使用，0x01表示传入数据直接使用。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_MFPL3_writeencrypted(HANDLE icdev, unsigned int BNr, unsigned char Numblock, unsigned char *writedata, unsigned char flag);

  /**
   * @brief  加密模式写Mifare Plus卡数据（3级）。
   * @par    说明：
   * ::dc_MFPL3_writeencrypted 的HEX形式接口，参数 @a writedata 为HEX格式。
   */
  short USER_API dc_MFPL3_writeencrypted_hex(HANDLE icdev, unsigned int BNr, unsigned char Numblock, unsigned char *writedata, unsigned char flag);

  /**
   * @brief  验证Mifare Ultralight C卡密码。
   * @par    说明：
   * 使用传入的密码来验证Mifare Ultralight C卡密码。
   * @param[in] icdev 设备标识符。
   * @param[in] key 密码，固定为16个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_auth_ulc(HANDLE icdev, unsigned char *key);

  /**
   * @brief  验证Mifare Ultralight C卡密码。
   * @par    说明：
   * ::dc_auth_ulc 的HEX形式接口，参数 @a key 为HEX格式。
   */
  short USER_API dc_auth_ulc_hex(HANDLE icdev, unsigned char *key);

  /**
   * @brief  修改Mifare Ultralight C卡密码。
   * @par    说明：
   * 修改Mifare Ultralight C卡的密码。
   * @param[in] icdev 设备标识符。
   * @param[in] newkey 密码，固定为16个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_changekey_ulc(HANDLE icdev, unsigned char *newkey);

  /**
   * @brief  修改Mifare Ultralight C卡密码。
   * @par    说明：
   * ::dc_changekey_ulc 的HEX形式接口，参数 @a newkey 为HEX格式。
   */
  short USER_API dc_changekey_ulc_hex(HANDLE icdev, unsigned char *newkey);

  /**
   * @brief  获取接触式CPU卡参数。
   * @par    说明：
   * 此接口可获取接触式CPU卡操作行为的参数。
   * @param[in] icdev 设备标识符。
   * @param[in] cputype 卡座编号，同 ::dc_setcpu 的 @a _Byte 。
   * @param[out] cpupro 卡协议编号，0x00表示T0，0x01表示T1，默认为0x00。
   * @param[out] cpuetu 卡复位波特率编号，0x5C表示9600，0x14表示38400.
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_getcpupara(HANDLE icdev, unsigned char cputype, unsigned char *cpupro, unsigned char *cpuetu);

  /**
   * @brief  接触式CPU卡指令交互。
   * @par    说明：
   * 对当前卡座CPU卡进行指令交互操作，注意此接口不封装卡协议部分。
   * @param[in] icdev 设备标识符。
   * @param[in] slen 发送数据的长度。
   * @param[in] sendbuffer 发送数据。
   * @param[out] rlen 返回数据的长度。
   * @param[out] databuffer 返回的数据。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_cpuapdusourceEXT(HANDLE icdev, short slen, unsigned char *sendbuffer, short *rlen, unsigned char *databuffer);

  /**
   * @brief  接触式CPU卡指令交互。
   * @par    说明：
   * ::dc_cpuapdusourceEXT 的HEX形式接口，参数 @a sendbuffer @a databuffer 为HEX格式。
   */
  short USER_API dc_cpuapdusourceEXT_hex(HANDLE icdev, short slen, char *sendbuffer, short *rlen, char *databuffer);

  /**
   * @brief  接触式CPU卡指令交互。
   * @par    说明：
   * 对当前卡座CPU卡进行指令交互操作，注意此接口已封装卡协议部分。
   * @param[in] icdev 设备标识符。
   * @param[in] slen 发送数据的长度。
   * @param[in] sendbuffer 发送数据。
   * @param[out] rlen 返回数据的长度。
   * @param[out] databuffer 返回的数据。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_cpuapduEXT(HANDLE icdev, short slen, unsigned char *sendbuffer, short *rlen, unsigned char *databuffer);

  /**
   * @brief  接触式CPU卡指令交互。
   * @par    说明：
   * ::dc_cpuapduEXT 的HEX形式接口，参数 @a sendbuffer @a databuffer 为HEX格式。
   */
  short USER_API dc_cpuapduEXT_hex(HANDLE icdev, short slen, char *sendbuffer, short *rlen, char *databuffer);

  /**
   * @brief  接触式CPU卡指令交互。
   * @par    说明：
   * 对当前卡座CPU卡进行指令交互操作，注意此接口已封装卡协议部分。
   * @param[in] icdev 设备标识符。
   * @param[in] slen 发送数据的长度。
   * @param[in] sendbuffer 发送数据。
   * @param[out] rlen 返回数据的长度。
   * @param[out] databuffer 返回的数据。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_cpuapduInt(HANDLE icdev, unsigned int slen, unsigned char *sendbuffer, unsigned int *rlen, unsigned char *databuffer);

  /**
   * @brief  接触式CPU卡指令交互。
   * @par    说明：
   * ::dc_cpuapduInt 的HEX形式接口，参数 @a sendbuffer @a databuffer 为HEX格式。
   */
  short USER_API dc_cpuapduInt_hex(HANDLE icdev, unsigned int slen, char *sendbuffer, unsigned int *rlen, char *databuffer);

  /**
   * @brief  非接触式CPU卡指令交互。
   * @par    说明：
   * 对感应区CPU卡进行指令交互操作，注意此接口已封装卡协议部分。
   * @param[in] icdev 设备标识符。
   * @param[in] slen 发送数据的长度。
   * @param[in] sendbuffer 发送数据。
   * @param[out] rlen 返回数据的长度。
   * @param[out] databuffer 返回的数据。
   * @param[in] timeout 超时值，此值只在部分设备的底层使用，单位为250毫秒，一般调用建议值为7。
   * @param[in] FG 分割值，此值只在部分设备的底层使用，单位为字节，一般调用建议值为64。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_pro_commandlinkEXT(HANDLE icdev, unsigned int slen, unsigned char *sendbuffer, unsigned int *rlen, unsigned char *databuffer, unsigned char timeout, unsigned char FG);

  /**
   * @brief  非接触式CPU卡指令交互。
   * @par    说明：
   * ::dc_pro_commandlinkEXT 的HEX形式接口，参数 @a sendbuffer @a databuffer 为HEX格式。
   */
  short USER_API dc_pro_commandlinkEXT_hex(HANDLE icdev, unsigned int slen, unsigned char *sendbuffer, unsigned int *rlen, unsigned char *databuffer, unsigned char timeout, unsigned char FG);

  /**
   * @brief  非接触式CPU卡指令交互。
   * @par    说明：
   * 对感应区CPU卡进行指令交互操作，注意此接口已封装卡协议部分。
   * @param[in] icdev 设备标识符。
   * @param[in] slen 发送数据的长度。
   * @param[in] sendbuffer 发送数据。
   * @param[out] rlen 返回数据的长度。
   * @param[out] databuffer 返回的数据。
   * @param[in] timeout 超时值，此值只在部分设备的底层使用，单位为250毫秒，一般调用建议值为7。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_pro_commandlinkInt(HANDLE icdev, unsigned int slen, unsigned char *sendbuffer, unsigned int *rlen, unsigned char *databuffer, unsigned char timeout);

  /**
   * @brief  非接触式CPU卡指令交互。
   * @par    说明：
   * ::dc_pro_commandlinkInt 的HEX形式接口，参数 @a sendbuffer @a databuffer 为HEX格式。
   */
  short USER_API dc_pro_commandlinkInt_hex(HANDLE icdev, unsigned int slen, char *sendbuffer, unsigned int *rlen, char *databuffer, unsigned char timeout);

  /**
   * @brief  保留。
   */
  short USER_API dc_exchangeblock(HANDLE icdev, unsigned char slen, unsigned char *sendbuffer, unsigned char *rlen, unsigned char *databuffer, unsigned char timeout);

  /**
   * @brief  保留。
   */
  short USER_API dc_exchangeblock_hex(HANDLE icdev, unsigned char slen, unsigned char *sendbuffer, unsigned char *rlen, unsigned char *databuffer, unsigned char timeout);

  /**
   * @brief  保留。
   */
  short USER_API dc_write1024(HANDLE icdev, unsigned int offset, unsigned int length, unsigned char *writebuffer);

  /**
   * @brief  保留。
   */
  short USER_API dc_write1024_hex(HANDLE icdev, unsigned int offset, unsigned int length, unsigned char *writebuffer);

  /**
   * @brief  保留。
   */
  short USER_API dc_read1024(HANDLE icdev, unsigned int offset, unsigned int length, unsigned char *databuffer);

  /**
   * @brief  保留。
   */
  short USER_API dc_read1024_hex(HANDLE icdev, unsigned int offset, unsigned int length, unsigned char *databuffer);

  /**
   * @brief  保留。
   */
  short USER_API dc_switch_linux(HANDLE icdev);

  /**
   * @brief  接触式CPU卡复位。
   * @par    说明：
   * 对当前卡座CPU卡进行复位操作，此复位为热复位。
   * @param[in] icdev 设备标识符。
   * @param[out] rlen 返回复位信息的长度。
   * @param[out] databuffer 返回的复位信息，请至少分配128个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_cpuhotreset(HANDLE icdev, unsigned char *rlen, unsigned char *databuffer);

  /**
   * @brief  接触式CPU卡复位。
   * @par    说明：
   * ::dc_cpuhotreset 的HEX形式接口，参数 @a databuffer 为HEX格式。
   */
  short USER_API dc_cpuhotreset_hex(HANDLE icdev, unsigned char *rlen, char *databuffer);

  /**
   * @brief  检测多卡状态。
   * @par    说明：
   * 检测设备中存在什么类型的卡片，支持磁卡、非接、接触、身份证。
   * @param[in] icdev 设备标识符。
   * @param[out] flag 状态标记，固定为2个字节，可以解析为一个无符号整数（Big-Endian），值为下面列出的一种或多种之和。
   * @n 0x0001 - 表示已刷磁卡。
   * @n 0x0002 - 表示卡座存在接触式CPU卡。
   * @n 0x0004 - 表示卡座存在接触式未知卡。
   * @n 0x0008 - 表示感应区存在身份证。
   * @n 0x0010 - 表示感应区存在激活前的Type A CPU卡或Type B CPU卡。
   * @n 0x0020 - 表示感应区存在激活后的Type A CPU卡或Type B CPU卡。
   * @n 0x0040 - 表示感应区存在激活前的M1卡。
   * @n 0x0100 - 表示感应区存在激活前的多张Type A CPU卡。
   * @n 0x0200 - 表示感应区存在激活前的多张M1卡。
   * @n 0x0400 - 表示感应区同时存在激活前的Type A CPU卡和M1卡。
   * @n 0x0800 - 表示刷磁卡失败。
   * @n 0x1000 - 表示启动刷磁卡模式处于关闭状态。
   * @n 0x2000 - 表示启动刷磁卡模式处于开启状态。
   * @n 0x4000 - 表示感应区身份证激活前后状态一致。
   * @return <0表示失败，==0表示成功，==1表示无卡或无法寻到卡片。
   */
  short USER_API dc_card_exist(HANDLE icdev, unsigned char *flag);

  /**
   * @brief  检测接触式卡存在。
   * @par    说明：
   * 检测接触式卡片是否存在于当前卡座中。
   * @param[in] icdev 设备标识符。
   * @return <0表示失败，==0表示存在，==1表示不存在。
   */
  short USER_API dc_card_status(HANDLE icdev);

  /**
   * @brief  身份证、Type A CPU卡、Type B CPU卡检测。
   * @par    说明：
   * 检测感应区是否存在身份证、Type A CPU卡、Type B CPU卡。
   * @param[in] icdev 设备标识符。
   * @return <0表示失败，==0表示无卡，==1表示存在身份证，==2表示存在Type A CPU卡，==3表示存在Type B CPU卡。
   */
  short USER_API dc_typeab_card_status(HANDLE icdev);

  /**
   * @brief  寻卡请求、防卡冲突、选卡操作。
   * @par    说明：
   * 内部包含了 ::dc_request ::dc_anticoll ::dc_select ::dc_anticoll2 ::dc_select2 的功能。
   * @param[in] icdev 设备标识符。
   * @param[in] _Mode 模式，同 ::dc_request 的 @a _Mode 。
   * @param[out] SnrLen 返回卡序列号的长度。
   * @param[out] _Snr 返回的卡序列号，请至少分配8个字节。
   * @return <0表示失败，==0表示成功，==1表示无卡或无法寻到卡片。
   */
  short USER_API dc_card_n(HANDLE icdev, unsigned char _Mode, unsigned int *SnrLen, unsigned char *_Snr);

  /**
   * @brief  寻卡请求、防卡冲突、选卡操作。
   * @par    说明：
   * ::dc_card_n 的HEX形式接口，参数 @a _Snr 为HEX格式。
   */
  short USER_API dc_card_n_hex(HANDLE icdev, unsigned char _Mode, unsigned int *SnrLen, unsigned char *_Snr);

  /**
   * @brief  保留。
   */
  short USER_API dc_card_n_number(HANDLE icdev, unsigned char _Mode, char *_Snr);

  /**
   * @brief  获取单个按键值。
   * @par    说明：
   * 获取设备键盘的按键值，每次调用仅能获取单个按键值。
   * @param[in] icdev 设备标识符。
   * @param[in] timeout 设备超时值，单位为秒。
   * @param[out] value 返回的按键值，请至少分配8个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_pass_key_value(HANDLE icdev, unsigned char timeout, char *value);

  /**
   * @brief  播放语音。
   * @par    说明：
   * 播放设备内置语音。
   * @param[in] icdev 设备标识符。
   * @param[in] mode 语音段号（1~12）。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_play_voice(HANDLE icdev, unsigned char mode);

  /**
   * @brief  播放语音。
   * @par    说明：
   * 播放设备内置语音。
   * @param[in] icdev 设备标识符。
   * @param[in] mode 语音段号（1~12）。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_playvoice(HANDLE icdev, unsigned char mode);

  /**
   * @brief  装载语音。
   * @par    说明：
   * 装载语音数据到设备内。
   * @param[in] icdev 设备标识符。
   * @param[in] flag 标记，0表示第一包，1表示第二包，以此类推，0xFFFF表示结束包。
   * @param[in] slen 传入数据的长度，必须小于或等于1024，当标记为结束包的时候为0。
   * @param[in] sdata 传入数据。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_load_voice(HANDLE icdev, int flag, int slen, const unsigned char *sdata);

  /**
   * @brief  磁条卡参数配置。
   * @par    说明：
   * 配置操作磁条卡的参数，参数仅针对自动输出的模式有效。
   * @param[in] icdev 设备标识符。
   * @param[in] mode 模式，0x00表示不用输出，0x01表示自动输出。
   * @param[in] track1 1轨道参数。
   * @n bit0 - 轨道数据输出设置，0表示不输出，1表示输出。
   * @n bit1 - 轨道数据头设置，0表示无数据头，1表示有数据头。
   * @n bit2 - 轨道数据尾设置，0表示无数据尾，1表示有数据尾。
   * @n bit3 - 轨道数据换行符设置，0表示无换行符，1表示有换行符。
   * @n bit4 - 轨道数据等号与其后数据设置，0表示不输出，1表示输出。
   * @n bit5~bit7 - 保留。
   * @param[in] track2 2轨道参数。
   * @n bit0 - 轨道数据输出设置，0表示不输出，1表示输出。
   * @n bit1 - 轨道数据头设置，0表示无数据头，1表示有数据头。
   * @n bit2 - 轨道数据尾设置，0表示无数据尾，1表示有数据尾。
   * @n bit3 - 轨道数据换行符设置，0表示无换行符，1表示有换行符。
   * @n bit4 - 轨道数据等号与其后数据设置，0表示不输出，1表示输出。
   * @n bit5~bit7 - 保留。
   * @param[in] track3 3轨道参数。
   * @n bit0 - 轨道数据输出设置，0表示不输出，1表示输出。
   * @n bit1 - 轨道数据头设置，0表示无数据头，1表示有数据头。
   * @n bit2 - 轨道数据尾设置，0表示无数据尾，1表示有数据尾。
   * @n bit3 - 轨道数据换行符设置，0表示无换行符，1表示有换行符。
   * @n bit4 - 轨道数据等号与其后数据设置，0表示不输出，1表示输出。
   * @n bit5~bit7 - 保留。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_setmag(HANDLE icdev, unsigned char mode, unsigned char track1, unsigned char track2, unsigned char track3);

  /**
   * @brief  设置打印机参数。
   * @par    说明：
   * 设置操作打印机的参数。
   * @param[in] icdev 设备标识符。
   * @param[in] FontSize 字体设置，0x00表示字符大小为8*16，0x01表示字符大小为12*24，0x02表示字符大小为16*32。
   * @param[in] Alignment 对齐设置，0x00表示左对齐，0x01表示居中，0x02表示右对齐。
   * @param[in] LeftMargin 左边距设置，字符大小为8*16时<48，字符大小为12*24时<32，字符大小为16*32时<24。
   * @param[in] RightMargin 右边距设置，字符大小为8*16时<48，字符大小为12*24时<32，字符大小为16*32时<24。
   * @param[in] RowPitch 行间隔设置，单位为点。
   * @param[in] PrintOutRate 打印速度设置（0x00~0x03），0x00最快，0x03最慢。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_setprint(HANDLE icdev, unsigned char FontSize, unsigned char Alignment, unsigned char LeftMargin, unsigned char RightMargin, unsigned char RowPitch, unsigned char PrintOutRate);

  /**
   * @brief  查询打印机参数。
   * @par    说明：
   * 查询操作打印机的参数。
   * @param[in] icdev 设备标识符。
   * @param[out] FontSize 字体设置，0x00表示字符大小为8*16，0x01表示字符大小为12*24，0x02表示字符大小为16*32。
   * @param[out] Alignment 对齐设置，0x00表示左对齐，0x01表示居中，0x02表示右对齐。
   * @param[out] LeftMargin 左边距设置，字符大小为8*16时<48，字符大小为12*24时<32，字符大小为16*32时<24。
   * @param[out] RightMargin 右边距设置，字符大小为8*16时<48，字符大小为12*24时<32，字符大小为16*32时<24。
   * @param[out] RowPitch 行间隔设置，单位为点。
   * @param[out] PrintOutRate 打印速度设置（0x00~0x03），0x00最快，0x03最慢。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_checkprint(HANDLE icdev, unsigned char *FontSize, unsigned char *Alignment, unsigned char *LeftMargin, unsigned char *RightMargin, unsigned char *RowPitch, unsigned char *PrintOutRate);

  /**
   * @brief  打印字符。
   * @par    说明：
   * 打印文本字符信息。
   * @param[in] icdev 设备标识符。
   * @param[in] length 字符数据的长度，必须小于或等于480。
   * @param[in] character 字符数据。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_printcharacter(HANDLE icdev, unsigned short length, unsigned char *character);

  /**
   * @brief  打印一维码。
   * @par    说明：
   * 打印一维码信息。
   * @param[in] icdev 设备标识符。
   * @param[in] hight 一维码的高度。
   * @param[in] displayflag 显示类型，0x00表示图形在下文本在上，0x01表示图形在上文本在下，0x02表示只显示图形不显示文本。
   * @param[in] FontSize 字体设置，0x00表示字符大小为8*16，0x01表示字符大小为12*24，0x02表示字符大小为16*32。
   * @param[in] length 文本数据的长度，必须小于或等于15。
   * @param[in] Onedimensional 文本数据。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_printOnedimensional(HANDLE icdev, unsigned char hight, unsigned char displayflag, unsigned char FontSize, unsigned short length, unsigned char *Onedimensional);

  /**
   * @brief  打印图片。
   * @par    说明：
   * 打印图片信息。
   * @param[in] icdev 设备标识符。
   * @param[in] length 长度，单位为字节，必须小于或等于48，不能为0。
   * @param[in] height 高度，单位为点，必须小于100，不能为0。
   * @param[in] Alignment 对齐设置，0x00表示左对齐，0x01表示居中，0x02表示右对齐。
   * @param[in] LeftMargin 左边距设置，必须小于或等于48。
   * @param[in] RightMargin 右边距设置，必须小于或等于48。
   * @param[in] size 图片数据的大小。
   * @param[in] Picture 图片数据。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_printPicture(HANDLE icdev, unsigned char length, unsigned char height, unsigned char Alignment, unsigned char LeftMargin, unsigned char RightMargin, unsigned short size, unsigned char *Picture);

  /**
   * @brief  进纸。
   * @par    说明：
   * 进纸到设备内用于打印。
   * @param[in] icdev 设备标识符。
   * @param[in] RowPitch 进纸行数，单位为点。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_printenter(HANDLE icdev, unsigned char RowPitch);

  /**
   * @brief  获取打印机状态。
   * @par    说明：
   * 获取打印机的状态。
   * @param[in] icdev 设备标识符。
   * @param[out] paperstatus 纸状态，0x00表示不缺纸，0x01表示缺纸。
   * @param[out] tempturestatus 温度状态，0x00表示温度正常，0x01表示温度过高。
   * @param[out] zkstatus 字库状态。
   * @n 0x00 - 三种字库都存在。
   * @n 0x01 - 三种字库都不存在。
   * @n 0x02 - 存在8*16字库。
   * @n 0x03 - 存在12*24字库。
   * @n 0x04 - 存在16*32字库。
   * @n 0x05 - 存在8*16字库和12*24字库。
   * @n 0x06 - 存在8*16字库和16*32字库。
   * @n 0x07 - 存在12*24字库和16*32字库。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_printstatus(HANDLE icdev, unsigned char *paperstatus, unsigned char *tempturestatus, unsigned char *zkstatus);

  /**
   * @brief  设置2.4G模块波特率。
   * @par    说明：
   * 设置与2.4G模块之间通讯的波特率。
   * @param[in] icdev 设备标识符。
   * @param[in] baund 波特率。
   * @n 0x00 - 2400。
   * @n 0x01 - 4800。
   * @n 0x02 - 9600。
   * @n 0x03 - 14400。
   * @n 0x04 - 38400。
   * @n 0x05 - 57600。
   * @n 0x06 - 115200。
   * @n 0x07 - 256000。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_set2dot4Gbaund(HANDLE icdev, unsigned char baund);

  /**
   * @brief  查询2.4G模块波特率。
   * @par    说明：
   * 查询与2.4G模块之间通讯的波特率。
   * @param[in] icdev 设备标识符。
   * @param[out] baund 波特率。
   * @n 0x00 - 2400。
   * @n 0x01 - 4800。
   * @n 0x02 - 9600。
   * @n 0x03 - 14400。
   * @n 0x04 - 38400。
   * @n 0x05 - 57600。
   * @n 0x06 - 115200。
   * @n 0x07 - 256000。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_check2dot4Gbaund(HANDLE icdev, unsigned char *baund);

  /**
   * @brief  2.4G复位。
   * @par    说明：
   * 用2.4G进行复位操作，
   * @param[in] icdev 设备标识符。
   * @param[out] rlen 返回复位信息的长度。
   * @param[out] databuffer 返回的复位信息，请至少分配128个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_2dot4_reset(HANDLE icdev, unsigned char *rlen, unsigned char *databuffer);

  /**
   * @brief  2.4G复位。
   * @par    说明：
   * ::dc_2dot4_reset 的HEX形式接口，参数 @a databuffer 为HEX格式。
   */
  short USER_API dc_2dot4_resethex(HANDLE icdev, unsigned char *rlen, unsigned char *databuffer);

  /**
   * @brief  2.4G指令交互。
   * @par    说明：
   * 用2.4G进行指令交互操作。
   * @param[in] icdev 设备标识符。
   * @param[in] slen 发送数据的长度。
   * @param[in] senddata 发送数据。
   * @param[out] rlen 返回数据的长度。
   * @param[out] recvbuffer 返回的数据。
   * @param[in] timeout 设备超时值，单位为秒。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_2dot4_command(HANDLE icdev, unsigned int slen, unsigned char *senddata, unsigned int *rlen, unsigned char *recvbuffer, unsigned char timeout);

  /**
   * @brief  2.4G指令交互。
   * @par    说明：
   * ::dc_2dot4_command 的HEX形式接口，参数 @a senddata @a recvbuffer 为HEX格式。
   */
  short USER_API dc_2dot4_command_hex(HANDLE icdev, unsigned int slen, unsigned char *senddata, unsigned int *rlen, unsigned char *recvbuffer, unsigned char timeout);

  /**
   * @brief  检测102卡。
   * @par    说明：
   * 检测是否存在102卡。
   * @param[in] icdev 设备标识符。
   * @return <0表示失败或不存在，==0表示存在。
   */
  short USER_API dc_check_102(HANDLE icdev);

  /**
   * @brief  102卡下电。
   * @par    说明：
   * 对102卡进行下电操作。
   * @param[in] icdev 设备标识符。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_down_102(HANDLE icdev);

  /**
   * @brief  读102卡。
   * @par    说明：
   * 读取102卡的数据。
   * @param[in] icdev 设备标识符。
   * @param[in] offset 偏移。
   * @param[in] length 读取长度。
   * @param[out] readdata 返回的数据。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_read_102(HANDLE icdev, unsigned char offset, unsigned char length, unsigned char *readdata);

  /**
   * @brief  读102卡。
   * @par    说明：
   * ::dc_read_102 的HEX形式接口，参数 @a readdata 为HEX格式。
   */
  short USER_API dc_read_102_hex(HANDLE icdev, unsigned char offset, unsigned char length, unsigned char *readdata);

  /**
   * @brief  写102卡。
   * @par    说明：
   * 写入数据到102卡中。
   * @param[in] icdev 设备标识符。
   * @param[in] offset 偏移。
   * @param[in] length 写入长度。
   * @param[in] writedata 传入数据。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_write_102(HANDLE icdev, unsigned char offset, unsigned char length, unsigned char *writedata);

  /**
   * @brief  写102卡。
   * @par    说明：
   * ::dc_write_102 的HEX形式接口，参数 @a writedata 为HEX格式。
   */
  short USER_API dc_write_102_hex(HANDLE icdev, unsigned char offset, unsigned char length, unsigned char *writedata);

  /**
   * @brief  验证102卡密码。
   * @par    说明：
   * 使用传入的密码来验证102卡密码。
   * @param[in] icdev 设备标识符。
   * @param[in] zone 密码区。
   * @n 0 - 表示总密码，密码长度为2个字节。
   * @n 11 - 表示一区擦除密码，密码长度为6个字节。
   * @n 12 - 表示二区擦除密码，密码长度为4个字节。
   * @param[in] password 密码。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_checkpass_102(HANDLE icdev, short zone, unsigned char *password);

  /**
   * @brief  验证102卡密码。
   * @par    说明：
   * ::dc_checkpass_102 的HEX形式接口，参数 @a password 为HEX格式。
   */
  short USER_API dc_checkpass_102_hex(HANDLE icdev, short zone, unsigned char *password);

  /**
   * @brief  修改102卡密码。
   * @par    说明：
   * 修改102卡的密码。
   * @param[in] icdev 设备标识符。
   * @param[in] zone 密码区。
   * @n 0 - 表示总密码，密码长度为2个字节。
   * @n 11 - 表示一区擦除密码，密码长度为6个字节。
   * @n 12 - 表示二区擦除密码，密码长度为4个字节。
   * @param[in] password 密码。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_changepass_102(HANDLE icdev, short zone, unsigned char *password);

  /**
   * @brief  修改102卡密码。
   * @par    说明：
   * ::dc_changepass_102 的HEX形式接口，参数 @a password 为HEX格式。
   */
  short USER_API dc_changepass_102_hex(HANDLE icdev, short zone, unsigned char *password);

  /**
   * @brief  读102卡密码计数。
   * @par    说明：
   * 读取102卡的密码计数，此计数值表示可以尝试验证密码的次数。
   * @param[in] icdev 设备标识符。
   * @param[in] zone 密码区。
   * @n 0 - 表示总密码。
   * @return <0表示失败，否则为密码计数值。
   */
  short USER_API dc_readcount_102(HANDLE icdev, short zone);

  /**
   * @brief  102卡熔丝。
   * @par    说明：
   * 对102卡进行熔丝操作。
   * @param[in] icdev 设备标识符。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_fuse_102(HANDLE icdev);

  /**
   * @brief  检测1604卡。
   * @par    说明：
   * 检测是否存在1604卡。
   * @param[in] icdev 设备标识符。
   * @return <0表示失败或不存在，==0表示存在。
   */
  short USER_API dc_check_1604(HANDLE icdev);

  /**
   * @brief  1604卡下电。
   * @par    说明：
   * 对1604卡进行下电操作。
   * @param[in] icdev 设备标识符。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_down_1604(HANDLE icdev);

  /**
   * @brief  读1604卡。
   * @par    说明：
   * 读取1604卡的数据。
   * @param[in] icdev 设备标识符。
   * @param[in] offset 偏移。
   * @param[in] length 读取长度。
   * @param[out] readdata 返回的数据。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_read_1604(HANDLE icdev, unsigned int offset, unsigned int length, unsigned char *readdata);

  /**
   * @brief  读1604卡。
   * @par    说明：
   * ::dc_read_1604 的HEX形式接口，参数 @a readdata 为HEX格式。
   */
  short USER_API dc_read_1604_hex(HANDLE icdev, unsigned int offset, unsigned int length, unsigned char *readdata);

  /**
   * @brief  写1604卡。
   * @par    说明：
   * 写入数据到1604卡中。
   * @param[in] icdev 设备标识符。
   * @param[in] offset 偏移。
   * @param[in] length 写入长度。
   * @param[in] writedata 传入数据。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_write_1604(HANDLE icdev, unsigned int offset, unsigned int length, unsigned char *writedata);

  /**
   * @brief  写1604卡。
   * @par    说明：
   * ::dc_write_1604 的HEX形式接口，参数 @a writedata 为HEX格式。
   */
  short USER_API dc_write_1604_hex(HANDLE icdev, unsigned int offset, unsigned int length, unsigned char *writedata);

  /**
   * @brief  验证1604卡密码。
   * @par    说明：
   * 使用传入的密码来验证1604卡密码。
   * @param[in] icdev 设备标识符。
   * @param[in] zone 密码区。
   * @n 0 - 表示总密码。
   * @n 1 - 表示一区密码。
   * @n 2 - 表示二区密码。
   * @n 3 - 表示三区密码。
   * @n 4 - 表示四区密码。
   * @n 11 - 表示一区擦除密码。
   * @n 12 - 表示二区擦除密码。
   * @n 13 - 表示三区擦除密码。
   * @n 14 - 表示四区擦除密码。
   * @param[in] password 密码，固定为2个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_checkpass_1604(HANDLE icdev, short zone, unsigned char *password);

  /**
   * @brief  验证1604卡密码。
   * @par    说明：
   * ::dc_checkpass_1604 的HEX形式接口，参数 @a password 为HEX格式。
   */
  short USER_API dc_checkpass_1604_hex(HANDLE icdev, short zone, unsigned char *password);

  /**
   * @brief  修改1604卡密码。
   * @par    说明：
   * 修改1604卡的密码。
   * @param[in] icdev 设备标识符。
   * @param[in] zone 密码区。
   * @n 0 - 表示总密码。
   * @n 1 - 表示一区密码。
   * @n 2 - 表示二区密码。
   * @n 3 - 表示三区密码。
   * @n 4 - 表示四区密码。
   * @n 11 - 表示一区擦除密码。
   * @n 12 - 表示二区擦除密码。
   * @n 13 - 表示三区擦除密码。
   * @n 14 - 表示四区擦除密码。
   * @param[in] password 密码，固定为2个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_changepass_1604(HANDLE icdev, short zone, unsigned char *password);

  /**
   * @brief  修改1604卡密码。
   * @par    说明：
   * ::dc_changepass_1604 的HEX形式接口，参数 @a password 为HEX格式。
   */
  short USER_API dc_changepass_1604_hex(HANDLE icdev, short zone, unsigned char *password);

  /**
   * @brief  读1604卡密码计数。
   * @par    说明：
   * 读取1604卡的密码计数，此计数值表示可以尝试验证密码的次数。
   * @param[in] icdev 设备标识符。
   * @param[in] zone 密码区。
   * @n 0 - 表示总密码。
   * @n 1 - 表示一区密码。
   * @n 2 - 表示二区密码。
   * @n 3 - 表示三区密码。
   * @n 4 - 表示四区密码。
   * @n 11 - 表示一区擦除密码。
   * @n 12 - 表示二区擦除密码。
   * @n 13 - 表示三区擦除密码。
   * @n 14 - 表示四区擦除密码。
   * @return <0表示失败，否则为密码计数值。
   */
  short USER_API dc_readcount_1604(HANDLE icdev, short zone);

  /**
   * @brief  1604卡熔丝。
   * @par    说明：
   * 对1604卡进行熔丝操作。
   * @param[in] icdev 设备标识符。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_fuse_1604(HANDLE icdev);

  /**
   * @brief  4428卡下电。
   * @par    说明：
   * 对4428卡进行下电操作。
   * @param[in] icdev 设备标识符。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_down_4428(HANDLE icdev);

  /**
   * @brief  4442卡下电。
   * @par    说明：
   * 对4442卡进行下电操作。
   * @param[in] icdev 设备标识符。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_down_4442(HANDLE icdev);

  /**
   * @brief  保留。
   */
  short USER_API dc_flash_card(HANDLE icdev);

  /**
   * @brief  保留。
   */
  short USER_API dc_read_walletbalance(HANDLE icdev, unsigned char *walletvalue);

  /**
   * @brief  保留。
   */
  short USER_API dc_consume_wallet(HANDLE icdev, unsigned char *walletvalue, unsigned char *secret);

  /**
   * @brief  保留。
   */
  short USER_API dc_transfer_wallet(HANDLE icdev, unsigned char *walletvalue);

  /**
   * @brief  保留。
   */
  short USER_API dc_authentication_key(HANDLE icdev, unsigned char *data, unsigned char *desdata);

  /**
   * @brief  保留。
   */
  short USER_API dc_set_terminalnumber(HANDLE icdev, unsigned char length, unsigned char *serieldata);

  /**
   * @brief  保留。
   */
  short USER_API dc_get_terminalnumber(HANDLE icdev, unsigned char length, unsigned char *serieldata);

  /**
   * @brief  保留。
   */
  short USER_API dc_set_trademerchantcode(HANDLE icdev, unsigned char length, unsigned char *merchantcode);

  /**
   * @brief  保留。
   */
  short USER_API dc_get_trademerchantcode(HANDLE icdev, unsigned char length, unsigned char *merchantcode);

  /**
   * @brief  保留。
   */
  short USER_API dc_set_transactiontype(HANDLE icdev, unsigned char typecode);

  /**
   * @brief  保留。
   */
  short USER_API dc_get_transactiontype(HANDLE icdev, unsigned char *typecode);

  /**
   * @brief  保留。
   */
  short USER_API dc_set_tradesecretkey(HANDLE icdev, unsigned char *secretkey);

  /**
   * @brief  保留。
   */
  short USER_API dc_get_tradesecretkey(HANDLE icdev, unsigned char *secretkey);

  /**
   * @brief  保留。
   */
  short USER_API dc_set_hardwareserialnumber(HANDLE icdev, unsigned char length, unsigned char *hardwareserial);

  /**
   * @brief  保留。
   */
  short USER_API dc_get_hardwareserialnumber(HANDLE icdev, unsigned char length, unsigned char *hardwareserial);

  /**
   * @brief  保留。
   */
  short USER_API dc_reset_factory(HANDLE icdev);

  /**
   * @brief  保留。
   */
  short USER_API dc_get_signmessageparameters(HANDLE icdev, unsigned char length, unsigned char *parameters);

  /**
   * @brief  保留。
   */
  short USER_API dc_get_record(HANDLE icdev, unsigned char tablenumber, unsigned char recordnumber, unsigned char *recordquantity, unsigned char *recorddata);

  /**
   * @brief  启动读磁条卡。
   * @par    说明：
   * 使设备进入监测刷磁条的状态，接口本身会直接返回，而不会等待刷完磁条卡。
   * @param[in] icdev 设备标识符。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_startreadmag(HANDLE icdev);

  /**
   * @brief  停止读磁条卡。
   * @par    说明：
   * 在设备进入监测刷磁条的状态后，只有刷完磁条卡或调用此接口才能使得设备退出这种状态。
   * @param[in] icdev 设备标识符。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_stopreadmag(HANDLE icdev);

  /**
   * @brief  获取磁条卡数据。
   * @par    说明：
   * 获取设备已经读取到的磁条卡数据。
   * @param[in] icdev 设备标识符。
   * @param[out] pTrack1Data 返回的1轨道数据，数据格式为'\0'结尾的字符串。
   * @param[out] pTrack1Len 返回1轨道数据的长度，不含'\0'。
   * @param[out] pTrack2Data 返回的2轨道数据，数据格式为'\0'结尾的字符串。
   * @param[out] pTrack2Len 返回2轨道数据的长度，不含'\0'。
   * @param[out] pTrack3Data 返回的3轨道数据，数据格式为'\0'结尾的字符串。
   * @param[out] pTrack3Len 返回3轨道数据的长度，不含'\0'。
   * @return <0表示失败，==0表示成功，==1表示等待刷卡，==2表示处于停止刷卡状态。
   */
  short USER_API dc_readmag(HANDLE icdev, unsigned char *pTrack1Data, unsigned int *pTrack1Len, unsigned char *pTrack2Data, unsigned int *pTrack2Len, unsigned char *pTrack3Data, unsigned int *pTrack3Len);

  /**
   * @brief  自动获取磁条卡数据。
   * @par    说明：
   * 内部包含了 ::dc_startreadmag ::dc_readmag ::dc_stopreadmag 的功能。
   * @param[in] icdev 设备标识符。
   * @param[in] ctime 接口超时值，单位为秒。
   * @param[out] pTrack1Data 返回的1轨道数据，数据格式为'\0'结尾的字符串。
   * @param[out] pTrack1Len 返回1轨道数据的长度，不含'\0'。
   * @param[out] pTrack2Data 返回的2轨道数据，数据格式为'\0'结尾的字符串。
   * @param[out] pTrack2Len 返回2轨道数据的长度，不含'\0'。
   * @param[out] pTrack3Data 返回的3轨道数据，数据格式为'\0'结尾的字符串。
   * @param[out] pTrack3Len 返回3轨道数据的长度，不含'\0'。
   * @return <0表示失败，==0表示成功，==1表示等待刷卡，==2表示处于停止刷卡状态。
   */
  short USER_API dc_readmagcardallA(HANDLE icdev, unsigned char ctime, unsigned char *pTrack1Data, unsigned int *pTrack1Len, unsigned char *pTrack2Data, unsigned int *pTrack2Len, unsigned char *pTrack3Data, unsigned int *pTrack3Len);

  /**
   * @brief  设置密码键盘密钥。
   * @par    说明：
   * 对密码键盘内的密钥进行设置操作。
   * @param[in] icdev 设备标识符。
   * @param[in] flag 标记。
   * @n 0x00 - 表示装载主密钥，明文装载。
   * @n 0x01 - 表示装载PIN密钥，密文装载（用主密钥加密）。
   * @n 0x02 - 表示装载MAC密钥，密文装载（用主密钥加密）。
   * @n 0x03 - 表示装载TDK密钥，密文装载（用主密钥加密）。
   * @n 0xF0 - 表示清空主密钥、PIN密钥、MAC密钥、TDK密钥。
   * @n 0xF1 - 表示清空PIN密钥。
   * @n 0xF2 - 表示清空MAC密钥。
   * @n 0xF3 - 表示清空TDK密钥。
   * @param[in] keylen 密钥数据的长度。
   * @param[in] keydata 密钥数据。
   * @param[in] mode 模式，0x00表示单DES密钥，0x01表示三DES密钥，0x02表示SM4密钥，0x03表示24字节三DES密钥。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_InstallKbKey(HANDLE icdev, unsigned char flag, unsigned char keylen, unsigned char *keydata, unsigned char mode);

  /**
   * @brief  设置当前密钥组。
   * @par    说明：
   * 设置密码键盘当前使用的密钥组。
   * @param[in] icdev 设备标识符。
   * @param[in] keyID 密钥组号，从0x00开始编号。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_SetKbKeyID(HANDLE icdev, unsigned char keyID);

  /**
   * @brief  获取加密按键数据。
   * @par    说明：
   * 从密码键盘获取ANSI X9.8 PIN BLOCK加密的按键数据。
   * @param[in] icdev 设备标识符。
   * @param[in] ctime 设备超时值，单位为秒。
   * @param[in] panlen 卡号的长度。
   * @param[in] pandata 卡号。
   * @param[out] rlen 返回加密数据的长度。
   * @param[out] cpass 返回的加密数据。
   * @return <0表示失败，==0表示成功，==0xA1表示取消输入，==0xA2表示输入超时。
   */
  short USER_API dc_GetEnPass(HANDLE icdev, unsigned char ctime, unsigned char panlen, unsigned char *pandata, unsigned char *rlen, unsigned char *cpass);

  /**
   * @brief  保留。
   */
  short USER_API dc_get55data(HANDLE icdev, unsigned int slen, unsigned char *sdata, unsigned char *PacketType, unsigned int *rlen, unsigned char *rdata);

  /**
   * @brief  保留。
   */
  short USER_API dc_CardIssuingScript(HANDLE icdev, unsigned int slen, unsigned char *sdata, unsigned char *TransactionIsInterrupted, unsigned char *TradingResult);

  /**
   * @brief  保留。
   */
  short USER_API dc_SetEMVPara(HANDLE icdev, unsigned int slen, unsigned char *sdata);

  /**
   * @brief  保留。
   */
  short USER_API dc_CalculateMACCheck(HANDLE icdev, unsigned char keyindex, unsigned char macmode, unsigned int datalen, unsigned char *srcdata, unsigned char *macdata);

  /**
   * @brief  保留。
   */
  short USER_API dc_CalculateDes(HANDLE icdev, unsigned char keyindex, unsigned char enmode, unsigned short datalen, unsigned char *srcdata, unsigned char *desdata);

  /**
   * @brief  保留。
   */
  short USER_API dc_CalculateSm4(HANDLE icdev, unsigned char keyindex, unsigned char enmode, unsigned short datalen, unsigned char *srcdata, unsigned char *sm4data);

  /**
   * @brief  用工作密钥加解密。
   * @par    说明：
   * 使用密码键盘的工作密钥进行数据加解密操作，仅支持单DES、三DES和24字节三DES算法，算法由设置密钥时确定，请参考 ::dc_InstallKbKey 。
   * @param[in] icdev 设备标识符。
   * @param[in] keytype 密钥类型，0x01表示PIN密钥，0x02表示MAC密钥，0x03表示TDK密钥。
   * @param[in] enmode 运算模式，0x00表示加密，0x01表示解密。
   * @param[in] sourcedata 传入数据，固定为8个字节。
   * @param[out] retdata 返回的数据，固定为8个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_CreatDesData(HANDLE icdev, unsigned char keytype, unsigned char enmode, unsigned char *sourcedata, unsigned char *retdata);

  /**
   * @brief  用工作密钥加解密。
   * @par    说明：
   * 使用密码键盘的工作密钥进行数据加解密操作，仅支持SM4算法，算法由设置密钥时确定，请参考 ::dc_InstallKbKey 。
   * @param[in] icdev 设备标识符。
   * @param[in] keytype 密钥类型，0x01表示PIN密钥，0x02表示MAC密钥，0x03表示TDK密钥。
   * @param[in] enmode 运算模式，0x00表示加密，0x01表示解密。
   * @param[in] sourcedata 传入数据，固定为16个字节。
   * @param[out] retdata 返回的数据，固定为16个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_CreatSm4Data(HANDLE icdev, unsigned char keytype, unsigned char enmode, unsigned char *sourcedata, unsigned char *retdata);

  /**
   * @brief  用工作密钥加解密。
   * @par    说明：
   * 使用密码键盘的工作密钥进行数据加解密操作，仅支持单DES ECB和三DES ECB算法，内部会调用 ::dc_CreatDesData 。
   * @param[in] icdev 设备标识符。
   * @param[in] keytype 密钥类型，0x01表示PIN密钥，0x02表示MAC密钥，0x03表示TDK密钥。
   * @param[in] enmode 运算模式，0x00表示加密，0x01表示解密。
   * @param[in] slen 传入数据的长度。
   * @param[in] sourcedata 传入数据。
   * @param[out] rlen 返回数据的长度。
   * @param[out] retdata 返回的数据。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_CreatDesDataECB(HANDLE icdev, unsigned char keytype, unsigned char enmode, int slen, unsigned char *sourcedata, int *rlen, unsigned char *retdata);

  /**
   * @brief  用工作密钥加解密。
   * @par    说明：
   * 使用密码键盘的工作密钥进行数据加解密操作，仅支持SM4 ECB算法，内部会调用 ::dc_CreatSm4Data 。
   * @param[in] icdev 设备标识符。
   * @param[in] keytype 密钥类型，0x01表示PIN密钥，0x02表示MAC密钥，0x03表示TDK密钥。
   * @param[in] enmode 运算模式，0x00表示加密，0x01表示解密。
   * @param[in] slen 传入数据的长度。
   * @param[in] sourcedata 传入数据。
   * @param[out] rlen 返回数据的长度。
   * @param[out] retdata 返回的数据。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_CreatSm4DataECB(HANDLE icdev, unsigned char keytype, unsigned char enmode, int slen, unsigned char *sourcedata, int *rlen, unsigned char *retdata);

  /**
   * @brief  用工作密钥算MAC。
   * @par    说明：
   * 使用密码键盘的工作密钥进行数据算MAC操作，内部会调用 ::dc_CreatDesData ::dc_CreatSm4Data 。
   * @param[in] icdev 设备标识符。
   * @param[in] keytype 密钥类型，0x01表示PIN密钥，0x02表示MAC密钥，0x03表示TDK密钥。
   * @param[in] enmode 运算模式，0x00或0x01表示用DES POS ECB算MAC，0x02表示用SM4算MAC，0x03表示用DES X9.9算MAC，0x04表示用三DES X9.19算MAC，0x05表示用三DES POS ECB算MAC，0x06表示用24字节三DES X9.19算MAC，0x07表示用24字节三DES POS ECB算MAC。
   * @param[in] slen 传入数据的长度。
   * @param[in] sourcedata 传入数据。
   * @param[out] rlen 返回数据的长度。
   * @param[out] retdata 返回的数据。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_CreatMacDataECB(HANDLE icdev, unsigned char keytype, unsigned char enmode, int slen, unsigned char *sourcedata, int *rlen, unsigned char *retdata);

  /**
   * @brief  写SD存储。
   * @par    说明：
   * 写入数据到SD存储中，可以用作数据保存等。
   * @param[in] icdev 设备标识符。
   * @param[in] offset 偏移地址。
   * @param[in] length 写入长度。
   * @param[in] writebuffer 传入数据。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_writeSD(HANDLE icdev, int offset, int length, unsigned char *writebuffer);

  /**
   * @brief  读SD存储。
   * @par    说明：
   * 读取SD存储中的数据，可以用作数据保存等。
   * @param[in] icdev 设备标识符。
   * @param[in] offset 偏移地址。
   * @param[in] length 读取长度。
   * @param[out] readbuffer 返回的数据。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_readSD(HANDLE icdev, int offset, int length, unsigned char *readbuffer);

  /**
   * @brief  设置USB模式。
   * @par    说明：
   * 设置USB通讯模式，必须重新对设备进行上电才能生效。
   * @param[in] icdev 设备标识符。
   * @param[in] ucmode 模式。
   * @n 0x00 - 表示中断发送和中断接收，此时VID=257B，PID=3010。
   * @n 0x01 - 表示控制发送和控制接收，此时VID=257B，PID=3011。
   * @n 0x02 - 表示控制发送和中断接收，此时VID=0471，PID=7002。
   * @n 0x03 - 表示控制发送和中断接收，此时VID=0471，PID=7003。
   * @n 0x04 - 表示控制发送和中断接收，此时VID=0471，PID=7003，支持磁条卡自动上传功能。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_SetUsbMode(HANDLE icdev, unsigned char ucmode);

  /**
   * @brief  外接密码键盘通讯。
   * @par    说明：
   * 与外置密码键盘进行通讯交互。
   * @param[in] icdev 设备标识符。
   * @param[in] ctime 设备超时值，单位为秒。
   * @param[in] senlen 发送数据的长度。
   * @param[in] source 发送数据。
   * @param[out] reclen 返回数据的长度。
   * @param[out] rdata 返回的数据。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API SD_InstallKey(HANDLE icdev, unsigned char ctime, unsigned char senlen, unsigned char *source, unsigned char *reclen, unsigned char *rdata);

  /**
   * @brief  获取外接密码键盘的版本。
   * @par    说明：
   * 获取外接密码键盘的版本。
   * @param[in] icdev 设备标识符。
   * @param[out] version 返回的版本字符串，请至少分配128个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API SD_IFD_GetVersion(HANDLE icdev, char *version);

  /**
   * @brief  外接密码键盘播放语音。
   * @par    说明：
   * 播放外接密码键盘内置语音。
   * @param[in] icdev 设备标识符。
   * @param[in] _playmode 语音段号（0x01~0x08）。
   * @n 0x01 - "请输入密码"。
   * @n 0x02 - "请输入原密码"。
   * @n 0x03 - "请再输入一次"。
   * @n 0x04 - "请输入新密码"。
   * @n 0x05 - "请确认新密码"。
   * @n 0x06 - "密码修改成功"。
   * @n 0x07 - "请插卡"。
   * @n 0x08 - "请刷卡"。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API SD_IFD_PlayVoice(HANDLE icdev, unsigned char _playmode);

  /**
   * @brief  外接密码键盘初始化。
   * @par    说明：
   * 对外接密码键盘进行初始化操作，使其复位为出厂状态，出厂状态下所有的主密钥内存空间都为字节0x88。
   * @param[in] icdev 设备标识符。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API SD_IFD_Init(HANDLE icdev);

  /**
   * @brief  设置外接密码键盘主密钥。
   * @par    说明：
   * 对外接密码键盘内的主密钥进行设置操作。
   * @param[in] icdev 设备标识符。
   * @param[in] keyset 密钥组号，从0x00开始编号。
   * @param[in] oldkey 旧主密钥数据，明文，固定为16个字节。
   * @param[in] newkey 新主密钥数据，明文，固定为16个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API SD_IFD_SetMainKey(HANDLE icdev, unsigned char keyset, unsigned char *oldkey, unsigned char *newkey);

  /**
   * @brief  设置外接密码键盘工作密钥。
   * @par    说明：
   * 对外接密码键盘内的工作密钥进行设置操作。
   * @param[in] icdev 设备标识符。
   * @param[in] keysetmain 主密钥组号，从0x00开始编号。
   * @param[in] keysetwork 工作密钥组号，从0x00开始编号。
   * @param[in] enkeywork 工作密钥数据，密文（用主密钥加密），固定为16个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API SD_IFD_SetWorkKey(HANDLE icdev, unsigned char keysetmain, unsigned char keysetwork, unsigned char *enkeywork);

  /**
   * @brief  激活外接密码键盘工作密钥。
   * @par    说明：
   * 激活外接密码键盘当前使用的工作密钥。
   * @param[in] icdev 设备标识符。
   * @param[in] keysetmain 主密钥组号，从0x00开始编号。
   * @param[in] keysetwork 工作密钥组号，从0x00开始编号。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API SD_IFD_ActWorkKey(HANDLE icdev, unsigned char keysetmain, unsigned char keysetwork);

  /**
   * @brief  设置外接密码键盘最大输入长度。
   * @par    说明：
   * 设置外接密码键盘允许用户输入密码的最大长度。
   * @param[in] icdev 设备标识符。
   * @param[in] keylength 密码最大长度（1~16）。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API SD_IFD_SetKeyLength(HANDLE icdev, unsigned char keylength);

  /**
   * @brief  获取外接密码键盘明文数据。
   * @par    说明：
   * 从外接密码键盘获取明文按键数据。
   * @param[in] icdev 设备标识符。
   * @param[out] szPasswd 返回的按键数据，数据格式为'\0'结尾的字符串。
   * @return <0表示失败，==0表示成功，==0xA1表示取消输入，==0xA2表示输入超时。
   */
  short USER_API SD_IFD_GetPIN(HANDLE icdev, char *szPasswd);

  /**
   * @brief  获取外接密码键盘密文数据。
   * @par    说明：
   * 从外接密码键盘获取密文按键数据。
   * @param[in] icdev 设备标识符。
   * @param[out] szPasswd 返回的按键数据，数据为密文的HEX格式字符串。
   * @return <0表示失败，==0表示成功，==0xA1表示取消输入，==0xA2表示输入超时。
   */
  short USER_API SD_IFD_GetEnPIN(HANDLE icdev, char *szPasswd);

  /**
   * @brief  获取外接密码键盘明文数据。
   * @par    说明：
   * 从外接密码键盘获取明文按键数据。
   * @param[in] icdev 设备标识符。
   * @param[out] szPasswd 返回的按键数据，数据格式为'\0'结尾的字符串。
   * @param[in] yyflag 标记。
   * @n 0x80 - 绿灯亮，液晶显示"欢迎使用"，无语音提示。
   * @n 0x81 - 绿灯亮，液晶显示"请再输入一次"，有语音提示。
   * @n 0x82 - 绿灯亮，液晶显示"请输入密码"，有语音提示。
   * @n 0x83 - 绿灯亮，液晶不操作，无语音提示。
   * @n 0x84 - 绿灯亮，液晶显示"请输入原密码"，有语音提示。
   * @n 0x85 - 绿灯亮，液晶显示"请输入新密码"，有语音提示。
   * @n 0x86 - 绿灯亮，液晶显示"请输入新密码"，无语音提示。
   * @param[in] timeout 设备超时值，单位为秒。
   * @return <0表示失败，==0表示成功，==0xA1表示取消输入，==0xA2表示输入超时。
   */
  short USER_API SD_IFD_GetPINPro(HANDLE icdev, char *szPasswd, unsigned char yyflag, unsigned char timeout);

  /**
   * @brief  获取外接密码键盘密文数据。
   * @par    说明：
   * 从外接密码键盘获取密文按键数据。
   * @param[in] icdev 设备标识符。
   * @param[out] szPasswd 返回的按键数据，数据格式为'\0'结尾的字符串。
   * @param[in] yyflag 标记。
   * @n 0x30 - 密码键盘提示"请输入密码"，语音提示，输入密码显示'*'。
   * @n 0x31 - 密码键盘提示"请再输入一次"，语音提示，输入密码显示'*'。
   * @n 0x32 - 密码键盘提示"请输入密码"，无语音提示，输入密码显示'*'。
   * @n 0x33 - 密码键盘提示"请再输入一次"，无语音提示，输入密码显示'*'。
   * @n 0x34 - 密码键盘提示"请输入密码"，语音提示，输入密码明文显示。
   * @n 0x35 - 密码键盘提示"请再输入一次"，语音提示，输入密码明文显示。
   * @n 0x36 - 密码键盘提示"请输入密码"，无语音提示，输入密码明文显示。
   * @n 0x37 - 密码键盘提示"请再输入一次"，无语音提示，输入密码明文显示。
   * @param[in] modeflag 模式。
   * @n 0x30 - 按"确认"键或到达指定的PIN长度。
   * @n 0x31 - 按"确认"键。
   * @n 0x32 - 到达指定的PIN长度。
   * @n 0x33 - 到达指定的PIN长度并按"确认"键。
   * @param[in] timeout 设备超时值，单位为秒。
   * @return <0表示失败，==0表示成功，==0xA1表示取消输入，==0xA2表示输入超时。
   */
  short USER_API SD_IFD_GetEnPINPro(HANDLE icdev, char *szPasswd, unsigned char yyflag, unsigned char modeflag, unsigned char timeout);

  /**
   * @brief  获取外接密码键盘密文数据。
   * @par    说明：
   * 从外接密码键盘获取ANSI X9.8 PIN BLOCK加密的按键数据。
   * @param[in] icdev 设备标识符。
   * @param[out] szPasswd 返回的按键数据，数据格式为'\0'结尾的字符串。
   * @param[in] yyflag 标记。
   * @n 0x30 - 密码键盘提示"请输入密码"，语音提示，输入密码显示'*'。
   * @n 0x31 - 密码键盘提示"请再输入一次"，语音提示，输入密码显示'*'。
   * @n 0x32 - 密码键盘提示"请输入密码"，无语音提示，输入密码显示'*'。
   * @n 0x33 - 密码键盘提示"请再输入一次"，无语音提示，输入密码显示'*'。
   * @n 0x34 - 密码键盘提示"请输入密码"，语音提示，输入密码明文显示。
   * @n 0x35 - 密码键盘提示"请再输入一次"，语音提示，输入密码明文显示。
   * @n 0x36 - 密码键盘提示"请输入密码"，无语音提示，输入密码明文显示。
   * @n 0x37 - 密码键盘提示"请再输入一次"，无语音提示，输入密码明文显示。
   * @param[in] modeflag 模式。
   * @n 0x30 - 按"确认"键或到达指定的PIN长度。
   * @n 0x31 - 按"确认"键。
   * @n 0x32 - 到达指定的PIN长度。
   * @n 0x33 - 到达指定的PIN长度并按"确认"键。
   * @param[in] cardno 截取后的卡号，固定为12个字节。
   * @param[in] timeout 设备超时值，单位为秒。
   * @return <0表示失败，==0表示成功，==0xA1表示取消输入，==0xA2表示输入超时。
   */
  short USER_API SD_IFD_GetEnPINBlock(HANDLE icdev, char *szPasswd, unsigned char yyflag, unsigned char modeflag, unsigned char *cardno, unsigned char timeout);

  /**
   * @brief  设置外接密码键盘算法。
   * @par    说明：
   * 设置外接密码键盘使用的算法。
   * @param[in] icdev 设备标识符。
   * @param[in] desmode 模式，0x01表示单DES，0x02表示三DES。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API SD_IFD_SelecetDes(HANDLE icdev, unsigned char desmode);

  /**
   * @brief  外接密码键盘液晶显示。
   * @par    说明：
   * 显示指定字符串到外接密码键盘的液晶屏幕上。
   * @param[in] icdev 设备标识符。
   * @param[in] line 行号。
   * @param[in] row 偏移。
   * @param[in] leddata 要显示的字符串。
   * @param[in] timeout 设备超时值，单位为秒。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API SD_IFD_LEDDisplay(HANDLE icdev, unsigned char line, unsigned char row, unsigned char *leddata, unsigned char timeout);

  /**
   * @brief  用外接密码键盘工作密钥加解密。
   * @par    说明：
   * 使用外接密码键盘的工作密钥进行数据加解密操作。
   * @param[in] icdev 设备标识符。
   * @param[in] mode 运算模式，0x00表示加密，0x01表示解密。
   * @param[in] srcdata 传入数据，HEX格式字符串。
   * @param[out] desdata 返回的数据，HEX格式字符串。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API SD_IFD_DES(HANDLE icdev, unsigned char mode, unsigned char *srcdata, unsigned char *desdata);

  /**
   * @brief  用外接密码键盘工作密钥加解密。
   * @par    说明：
   * 使用外接密码键盘的工作密钥进行数据加解密操作。
   * @param[in] icdev 设备标识符。
   * @param[in] srclen 传入数据的长度。
   * @param[in] srcdata 传入数据。
   * @param[out] desdata 返回的数据，HEX格式字符串。
   * @param[in] flag 运算模式，0x00表示加密，0x01表示解密。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API SD_IFD_DesCaculate(HANDLE icdev, unsigned char srclen, unsigned char *srcdata, unsigned char *desdata, unsigned char flag);

  /**
   * @brief  用外接密码键盘工作密钥算MAC。
   * @par    说明：
   * 使用外接密码键盘的工作密钥进行数据算MAC操作。
   * @param[in] icdev 设备标识符。
   * @param[in] srclen 传入数据的长度。
   * @param[in] srcdata 传入数据。
   * @param[out] macdata 返回的MAC字符串，请至少分配64个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API SD_IFD_CreateMac(HANDLE icdev, unsigned char srclen, unsigned char *srcdata, unsigned char *macdata);

  /**
   * @brief  查找身份证。
   * @par    说明：
   * 以读取数据方式查找是否有身份证存在于感应区。
   * @param[in] icdev 设备标识符。
   * @return <0表示失败或不存在，==0表示存在。
   */
  short USER_API dc_find_i_d(HANDLE icdev);

  /**
   * @brief  查找身份证。
   * @par    说明：
   * 以读取状态方式查找是否有身份证存在于感应区。
   * @param[in] icdev 设备标识符。
   * @return <0表示失败或不存在，==0表示存在。
   */
  short USER_API dc_find_i_d_2(HANDLE icdev);

  /**
   * @brief  查找身份证。
   * @par    说明：
   * 以寻卡方式查找是否有身份证存在于感应区。
   * @param[in] icdev 设备标识符。
   * @return <0表示失败或不存在，==0表示存在。
   */
  short USER_API dc_find_i_d_speed(HANDLE icdev);

  /**
   * @brief  读身份证原始数据。
   * @par    说明：
   * 读取身份证模块返回的原始数据，包含基础文字和相片内容。
   * @param[in] icdev 设备标识符。
   * @param[out] rdata 返回的数据，请至少分配4096个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_get_i_d_raw_buffer(HANDLE icdev, unsigned char *rdata);

  /**
   * @brief  读身份证。
   * @par    说明：
   * 读取身份证模块返回的原始数据，包含基础文字和相片内容，内部会做解析并且分配资源来保存，释放资源请使用 ::dc_end_i_d 。
   * @param[in] icdev 设备标识符。
   * @return <0表示失败，否则为身份证标识符。
   */
  HANDLE USER_API dc_start_i_d(HANDLE icdev);

  /**
   * @brief  读身份证。
   * @par    说明：
   * 读取身份证模块返回的原始数据，包含基础文字、相片、指纹内容，内部会做解析并且分配资源来保存，释放资源请使用 ::dc_end_i_d 。
   * @param[in] icdev 设备标识符。
   * @return <0表示失败，否则为身份证标识符。
   */
  HANDLE USER_API dc_start_i_d_2(HANDLE icdev);

  /**
   * @brief  获取姓名。
   * @par    说明：
   * 获取内部保存的姓名。
   * @param[in] idhandle 身份证标识符。
   * @return 返回的姓名字符串。
   */
  char *USER_API dc_i_d_query_name(HANDLE idhandle);

  /**
   * @brief  获取姓名。
   * @par    说明：
   * 获取内部保存的姓名。
   * @param[in] idhandle 身份证标识符。
   * @param[out] name 姓名，请至少分配32个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_i_d_query_name_2(HANDLE idhandle, char *name);

  /**
   * @brief  获取性别。
   * @par    说明：
   * 获取内部保存的性别。
   * @param[in] idhandle 身份证标识符。
   * @return 返回的性别字符串。
   */
  char *USER_API dc_i_d_query_sex(HANDLE idhandle);

  /**
   * @brief  获取性别。
   * @par    说明：
   * 获取内部保存的性别。
   * @param[in] idhandle 身份证标识符。
   * @param[out] sex 性别，请至少分配8个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_i_d_query_sex_2(HANDLE idhandle, char *sex);

  /**
   * @brief  获取民族。
   * @par    说明：
   * 获取内部保存的民族。
   * @param[in] idhandle 身份证标识符。
   * @return 返回的民族字符串。
   */
  char *USER_API dc_i_d_query_nation(HANDLE idhandle);

  /**
   * @brief  获取民族。
   * @par    说明：
   * 获取内部保存的民族。
   * @param[in] idhandle 身份证标识符。
   * @param[out] nation 民族，请至少分配32个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_i_d_query_nation_2(HANDLE idhandle, char *nation);

  /**
   * @brief  获取生日。
   * @par    说明：
   * 获取内部保存的生日。
   * @param[in] idhandle 身份证标识符。
   * @return 返回的生日字符串。
   */
  char *USER_API dc_i_d_query_birth(HANDLE idhandle);

  /**
   * @brief  获取生日。
   * @par    说明：
   * 获取内部保存的生日。
   * @param[in] idhandle 身份证标识符。
   * @param[out] birth 生日，请至少分配16个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_i_d_query_birth_2(HANDLE idhandle, char *birth);

  /**
   * @brief  获取住址。
   * @par    说明：
   * 获取内部保存的住址。
   * @param[in] idhandle 身份证标识符。
   * @return 返回的住址字符串。
   */
  char *USER_API dc_i_d_query_address(HANDLE idhandle);

  /**
   * @brief  获取住址。
   * @par    说明：
   * 获取内部保存的住址。
   * @param[in] idhandle 身份证标识符。
   * @param[out] address 住址，请至少分配128个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_i_d_query_address_2(HANDLE idhandle, char *address);

  /**
   * @brief  获取公民身份号码。
   * @par    说明：
   * 获取内部保存的公民身份号码。
   * @param[in] idhandle 身份证标识符。
   * @return 返回的公民身份号码字符串。
   */
  char *USER_API dc_i_d_query_id_number(HANDLE idhandle);

  /**
   * @brief  获取公民身份号码。
   * @par    说明：
   * 获取内部保存的公民身份号码。
   * @param[in] idhandle 身份证标识符。
   * @param[out] id_number 公民身份号码，请至少分配32个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_i_d_query_id_number_2(HANDLE idhandle, char *id_number);

  /**
   * @brief  获取签发机关。
   * @par    说明：
   * 获取内部保存的签发机关。
   * @param[in] idhandle 身份证标识符。
   * @return 返回的签发机关字符串。
   */
  char *USER_API dc_i_d_query_department(HANDLE idhandle);

  /**
   * @brief  获取签发机关。
   * @par    说明：
   * 获取内部保存的签发机关。
   * @param[in] idhandle 身份证标识符。
   * @param[out] department 签发机关，请至少分配32个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_i_d_query_department_2(HANDLE idhandle, char *department);

  /**
   * @brief  获取有效期限。
   * @par    说明：
   * 获取内部保存的有效期限。
   * @param[in] idhandle 身份证标识符。
   * @return 返回的有效期限字符串。
   */
  char *USER_API dc_i_d_query_expire_day(HANDLE idhandle);

  /**
   * @brief  获取有效期限。
   * @par    说明：
   * 获取内部保存的有效期限。
   * @param[in] idhandle 身份证标识符。
   * @param[out] expire_day 有效期限，请至少分配32个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_i_d_query_expire_day_2(HANDLE idhandle, char *expire_day);

  /**
   * @brief  获取相片原始数据。
   * @par    说明：
   * 获取内部保存的相片原始数据，此数据需要通过公安部相片解码库解码才能生成相片图像。
   * @param[in] idhandle 身份证标识符。
   * @return 返回的相片原始数据，数据实际长度通过调用 ::dc_i_d_query_photo_len 来获取。
   */
  unsigned char *USER_API dc_i_d_query_photo(HANDLE idhandle);

  /**
   * @brief  获取相片原始数据。
   * @par    说明：
   * 获取内部保存的相片原始数据，此数据需要通过公安部相片解码库解码才能生成相片图像。
   * @param[in] idhandle 身份证标识符。
   * @param[out] photo 相片原始数据，请至少分配4096个字节，数据实际长度通过调用 ::dc_i_d_query_photo_len 来获取。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_i_d_query_photo_2(HANDLE idhandle, unsigned char *photo);

  /**
   * @brief  获取相片原始数据长度。
   * @par    说明：
   * 获取内部保存的相片原始数据的长度。
   * @param[in] idhandle 身份证标识符。
   * @return 返回的相片原始数据长度。
   */
  unsigned int USER_API dc_i_d_query_photo_len(HANDLE idhandle);

  /**
   * @brief  生成相片图像文件。
   * @par    说明：
   * 使用内部保存的相片原始数据，通过调用公安部相片解码库解码生成相片图像文件。
   * @param[in] idhandle 身份证标识符。
   * @param[in] FileName 文件名，请确保有写入的权限。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_i_d_query_photo_file(HANDLE idhandle, const char *FileName);

  /**
   * @brief  生成相片图像数据。
   * @par    说明：
   * 使用内部保存的相片原始数据，通过调用公安部相片解码库解码生成相片图像数据。
   * @param[in] idhandle 身份证标识符。
   * @param[out] BmpBuffer 返回的相片图像数据，请至少分配65536个字节。
   * @param[in,out] BmpLength 传入 @a BmpBuffer 分配的字节数，返回相片图像数据的长度。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_i_d_query_photo_bmp_buffer(HANDLE idhandle, unsigned char *BmpBuffer, unsigned int *BmpLength);

  /**
   * @brief  获取指纹原始数据。
   * @par    说明：
   * 获取内部保存的指纹原始数据。
   * @param[in] idhandle 身份证标识符。
   * @return 返回的指纹原始数据，数据实际长度通过调用 ::dc_i_d_query_finger_len 来获取。
   */
  unsigned char *USER_API dc_i_d_query_finger(HANDLE idhandle);

  /**
   * @brief  获取指纹原始数据。
   * @par    说明：
   * 获取内部保存的指纹原始数据。
   * @param[in] idhandle 身份证标识符。
   * @param[out] finger 指纹原始数据，请至少分配4096个字节，数据实际长度通过调用 ::dc_i_d_query_finger_len 来获取。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_i_d_query_finger_2(HANDLE idhandle, unsigned char *finger);

  /**
   * @brief  获取指纹原始数据长度。
   * @par    说明：
   * 获取内部保存的指纹原始数据的长度。
   * @param[in] idhandle 身份证标识符。
   * @return 返回的指纹原始数据长度。
   */
  unsigned int USER_API dc_i_d_query_finger_len(HANDLE idhandle);

  /**
   * @brief  保留。
   */
  short USER_API dc_i_d_query_finger_file(HANDLE idhandle, const char *FileName);

  /**
   * @brief  保留。
   */
  short USER_API dc_i_d_query_finger_bmp_buffer(HANDLE idhandle, unsigned char *BmpBuffer, unsigned int *BmpLength);

  /**
   * @brief  释放读身份证资源。
   * @par    说明：
   * 释放 ::dc_start_i_d ::dc_start_i_d_2 分配的资源。
   * @param[in] idhandle 身份证标识符。
   */
  void USER_API dc_end_i_d(HANDLE idhandle);

  /**
   * @brief  获取身份证UID。
   * @par    说明：
   * 获取身份证的唯一标识，长度为8个字节。
   * @param[in] icdev 设备标识符。
   * @param[out] uid 返回的UID，固定为8个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_getuid_i_d(HANDLE icdev, unsigned char *uid);

  /**
   * @brief  LCD显示二维码。
   * @par    说明：
   * 在设备LCD显示屏上显示二维码。
   * @param[in] icdev 设备标识符。
   * @param[in] point_x X轴偏移点数（0~60）。
   * @param[in] point_y Y轴偏移点数（0~5）。
   * @param[in] info 文本字符串。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_display_2dbarcode(HANDLE icdev, int point_x, int point_y, const char *info);

  /**
   * @brief  读身份证指纹。
   * @par    说明：
   * 读取身份证中的指纹数据。
   * @param[in] icdev 设备标识符。
   * @param[out] length 返回指纹数据的长度，不含'\0'。
   * @param[out] data 返回的指纹数据，HEX格式字符串。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_getfingerdata(HANDLE icdev, int *length, unsigned char *data);

  /**
   * @brief  检测卡片位置。
   * @par    说明：
   * 检测卡片在设备中的位置。
   * @param[in] icdev 设备标识符。
   * @param[out] pos 位置。
   * @n 0x01 - 卡到开始位。
   * @n 0x02 - 卡到末位。
   * @n 0x03 - 卡已锁住。
   * @return <0表示失败，==0表示成功，==1表示无卡。
   */
  short USER_API dc_card_status2(HANDLE icdev, unsigned char *pos);

  /**
   * @brief  开卡与锁卡。
   * @par    说明：
   * 开卡与锁卡。
   * @param[in] icdev 设备标识符。
   * @param[in] flag 标记，0x00表示锁卡，0x01表示开卡。
   * @return <0表示失败，==0表示成功，==1表示无卡。
   */
  short USER_API dc_card_make_and_lock(HANDLE icdev, unsigned char flag);

  /**
   * @brief  发送短信。
   * @par    说明：
   * 发送短信给指定号码。
   * @param[in] icdev 设备标识符。
   * @param[in] phone_no 号码。
   * @param[in] sms_content 短信内容。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_send_sms(HANDLE icdev, const char *phone_no, const char *sms_content);

  /**
   * @brief  指纹模块通讯。
   * @par    说明：
   * 与指纹模块进行通讯交互。
   * @param[in] icdev 设备标识符。
   * @param[in] ctime 设备超时值，单位为秒。
   * @param[in] request 发送数据。
   * @param[in] request_len 发送数据的长度。
   * @param[out] response 返回的数据。
   * @param[out] response_len 返回数据的长度。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_fingerprint_io_control(HANDLE icdev, unsigned char ctime, const unsigned char *request, int request_len, unsigned char *response, int *response_len);

  /**
   * @brief  保留。
   */
  short USER_API dc_keypad_io_control(HANDLE icdev, unsigned char ctime, const unsigned char *request, int request_len, unsigned char *response, int *response_len);

  /**
   * @brief  保留。
   */
  short USER_API dc_keypad_ImportKey(HANDLE icdev, unsigned char *check_value, unsigned char check_mode, int key_index, int use_key_index, unsigned char enable, const unsigned char *key, int key_len);

  /**
   * @brief  保留。
   */
  short USER_API dc_keypad_DeleteKey(HANDLE icdev, int key_index);

  /**
   * @brief  保留。
   */
  short USER_API dc_keypad_SetButtonMark(HANDLE icdev, unsigned int mark_value, unsigned char use);

  /**
   * @brief  保留。
   */
  short USER_API dc_keypad_Start(HANDLE icdev, unsigned char mode, int max_len, unsigned char auto_end, unsigned char enable_sound);

  /**
   * @brief  保留。
   */
  short USER_API dc_keypad_End(HANDLE icdev);

  /**
   * @brief  保留。
   */
  short USER_API dc_keypad_GetPressed(HANDLE icdev, int time_ms, unsigned char *value);

  /**
   * @brief  保留。
   */
  short USER_API dc_keypad_GetPinBlock(HANDLE icdev, unsigned char mode, int key_index, const unsigned char *customer_data, int customer_data_len, unsigned char *out_data, int *out_data_len);

  /**
   * @brief  保留。
   */
  short USER_API dc_keypad_GetRandomValue(HANDLE icdev, int length, unsigned char *value);

  /**
   * @brief  保留。
   */
  short USER_API dc_keypad_GetEncryptDataOfCBC(HANDLE icdev, unsigned char mode, int key_index, const unsigned char *in_data, int in_data_len, unsigned char *out_data, int *out_data_len);

  /**
   * @brief  保留。
   */
  short USER_API dc_keypad_GetDecryptDataOfCBC(HANDLE icdev, unsigned char mode, int key_index, const unsigned char *in_data, int in_data_len, unsigned char *out_data, int *out_data_len);

  /**
   * @brief  保留。
   */
  short USER_API dc_keypad_GetEncryptDataOfECB(HANDLE icdev, unsigned char mode, int key_index, const unsigned char *in_data, int in_data_len, unsigned char *out_data, int *out_data_len);

  /**
   * @brief  保留。
   */
  short USER_API dc_keypad_GetDecryptDataOfECB(HANDLE icdev, unsigned char mode, int key_index, const unsigned char *in_data, int in_data_len, unsigned char *out_data, int *out_data_len);

  /**
   * @brief  保留。
   */
  short USER_API dc_keypad_GetMACDataOfCBC(HANDLE icdev, unsigned char mode, int key_index, const unsigned char *in_data, int in_data_len, unsigned char *out_data, int *out_data_len);

  /**
   * @brief  获取非接触卡类型。
   * @par    说明：
   * 获取感应区中存在的非接触卡类型。
   * @param[in] icdev 设备标识符。
   * @return <0表示失败。
   * @n 0x00 - 无卡。
   * @n 0x11 - Type A CPU Card。
   * @n 0x13 - Type A Mifare S50。
   * @n 0x14 - Type A Mifare S70。
   * @n 0x15 - Type A Mifare Ultralight。
   * @n 0x21 - Type B CPU Card。
   * @n 0x22 - Type B 存储卡。
   */
  short USER_API dc_RfGetCardType(HANDLE icdev);

  /**
   * @brief  保留。
   */
  short USER_API dc_RfWaveControl(HANDLE icdev, unsigned char mode);

  /**
   * @brief  保留。
   */
  short USER_API dc_RfReadChipRegister(HANDLE icdev, unsigned char *register_data);

  /**
   * @brief  保留。
   */
  short USER_API dc_RfSetChipRegister(HANDLE icdev, unsigned char register_type, unsigned char register_value);

  /**
   * @brief  获取身份证UID。
   * @par    说明：
   * 获取身份证的唯一标识，长度为8个字节。
   * @param[in] icdev 设备标识符。
   * @param[out] _Data 返回的UID，固定为8个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_get_idsnr(HANDLE icdev, unsigned char *_Data);

  /**
   * @brief  获取身份证UID。
   * @par    说明：
   * ::dc_get_idsnr 的HEX形式接口，参数 @a _Data 为HEX格式。
   */
  short USER_API dc_get_idsnr_hex(HANDLE icdev, char *_Data);

  /**
   * @brief  密码键盘模块通讯。
   * @par    说明：
   * 与密码键盘模块进行通讯交互。
   * @param[in] icdev 设备标识符。
   * @param[in] time_100ms 设备超时值，单位为100毫秒。
   * @param[in] slen 发送数据的长度。
   * @param[in] sdata 发送数据。
   * @param[out] rlen 返回数据的长度。
   * @param[out] rdata 返回的数据。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_PinpadCommunication(HANDLE icdev, int time_100ms, int slen, const unsigned char *sdata, int *rlen, unsigned char *rdata);

  /**
   * @brief  读Flash。
   * @par    说明：
   * 读取设备内部Flash中的数据，可以用作数据保存等。
   * @param[in] icdev 设备标识符。
   * @param[in] offset 偏移地址。
   * @param[in] length 读取长度。
   * @param[out] data_buffer 返回的数据。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_ReadFlash(HANDLE icdev, int offset, int length, unsigned char *data_buffer);

  /**
   * @brief  写Flash。
   * @par    说明：
   * 写入数据到设备内部Flash中，可以用作数据保存等。
   * @param[in] icdev 设备标识符。
   * @param[in] offset 偏移地址。
   * @param[in] length 写入长度。
   * @param[in] data_buffer 传入数据。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_WriteFlash(HANDLE icdev, int offset, int length, const unsigned char *data_buffer);

  /**
   * @brief  检测卡位置状态。
   * @par    说明：
   * 检测卡片当前的位置状态。
   * @param[in] icdev 设备标识符。
   * @param[out] pos 位置状态，可为多个以下值按位或在一起。
   * @n 0x00 - 无卡。
   * @n 0x01 - 无卡，卡在前门口，处夹卡位置。
   * @n 0x02 - 无卡，卡在前门口，处不夹卡位置。
   * @n 0x10 - 有卡，不可操作任何卡。
   * @n 0x11 - 有卡，可操作磁条。
   * @n 0x12 - 有卡，可操作接触。
   * @n 0x14 - 有卡，可操作非接触。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_SelfServiceDeviceCardStatus(HANDLE icdev, unsigned char *pos);

  /**
   * @brief  进入卡片。
   * @par    说明：
   * 进入卡片，操作前设备内有卡则错误。
   * @param[in] icdev 设备标识符。
   * @param[in] time_s 设备超时值，单位为秒。
   * @param[in] mode 模式。
   * @n 0x00 - 前端进卡，不带磁条。
   * @n 0x01 - 前端进卡，带磁条。
   * @n 0x02 - 后端进卡，不带磁条。
   * @n 0x03 - 后端进卡，带磁条。
   * @return <0表示失败。
   * @n 0 - 操作成功。
   * @n 1 - 设备内已有卡。
   * @n 2 - 接收超时。
   * @n 3 - 读磁卡错误。
   * @n 4 - 参数设置出错。
   * @n 5 - 异常卡正常弹出。
   * @n 6 - 异常卡卡在设备内。
   */
  short USER_API dc_SelfServiceDeviceCardInject(HANDLE icdev, unsigned char time_s, unsigned char mode);

  /**
   * @brief  弹出卡片。
   * @par    说明：
   * 弹出卡片，操作前设备内无卡则错误。
   * @param[in] icdev 设备标识符。
   * @param[in] time_s 设备超时值，单位为秒。
   * @param[in] mode 模式。
   * @n 0x00 - 弹到前端并夹卡。
   * @n 0x01 - 弹道后端。
   * @n 0x02 - 弹到前端不夹卡。
   * @return <0表示失败。
   * @n 0 - 操作成功。
   * @n 1 - 设备内没有卡。
   * @n 2 - 接收超时。
   * @n 3 - 参数设置出错。
   * @n 4 - 卡片已到前门夹卡位置，可操作卡片。
   * @n 5 - 卡片已到前门不夹卡位置，不可操作卡片。
   */
  short USER_API dc_SelfServiceDeviceCardEject(HANDLE icdev, unsigned char time_s, unsigned char mode);

  /**
   * @brief  移动卡片。
   * @par    说明：
   * 移动卡片，操作前设备内无卡则错误。
   * @param[in] icdev 设备标识符。
   * @param[in] time_s 设备超时值，单位为秒。
   * @param[in] mode 模式。
   * @n 0x00 - 移动到磁条卡操作位置。
   * @n 0x01 - 移动到接触卡操作位置。
   * @n 0x02 - 移动到非接触卡操作位置。
   * @return <0表示失败。
   * @n 0 - 操作成功。
   * @n 1 - 设备内没有卡。
   * @n 2 - 接收超时。
   * @n 3 - 参数设置出错。
   * @n 4 - 卡片已到前门不夹卡位置，不可操作卡片。
   */
  short USER_API dc_SelfServiceDeviceCardMove(HANDLE icdev, unsigned char time_s, unsigned char mode);

  /**
   * @brief  获取传感器状态。
   * @par    说明：
   * 获取设备传感器的状态。
   * @param[in] icdev 设备标识符。
   * @param[out] value 状态值。
   * @n bit0 - 电闸门开关传感器，0表示打开，1表示关闭。
   * @n bit1 - 压卡传感器，0表示卡已被下压，1表示无卡。
   * @n bit2~bit7 - 分别表示从前端到后端的传感器，每个传感器值0表示有卡，值1表示无卡。
   * @return <0表示失败，==0表示成功，==1表示掉电无法使用。
   */
  short USER_API dc_SelfServiceDeviceSensorStatus(HANDLE icdev, unsigned char *value);

  /**
   * @brief  设置弹卡模式。
   * @par    说明：
   * 设置弹卡模式。
   * @param[in] icdev 设备标识符。
   * @param[in] mode 模式。
   * @n 0x00 - 弹到前端并夹卡。
   * @n 0x01 - 弹道后端。
   * @n 0x02 - 弹到前端不夹卡。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_SelfServiceDeviceConfig(HANDLE icdev, unsigned char mode);

  /**
   * @brief  设置前端进卡模式。
   * @par    说明：
   * 设置前端进卡模式。
   * @param[in] icdev 设备标识符。
   * @param[in] mode 模式。
   * @n 0x00 - 前端禁止进卡。
   * @n 0x01 - 前端磁卡方式进卡。
   * @n 0x02 - 前端开关方式进卡。
   * @n 0x03 - 前端磁信号方式进卡。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_SelfServiceDeviceConfigFront(HANDLE icdev, unsigned char mode);

  /**
   * @brief  设置后端进卡模式。
   * @par    说明：
   * 设置后端进卡模式。
   * @param[in] icdev 设备标识符。
   * @param[in] mode 模式。
   * @n 0x00 - 后端禁止进卡。
   * @n 0x01 - 后端磁卡方式进卡。
   * @n 0x02 - 后端非磁卡方式进卡。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_SelfServiceDeviceConfigBack(HANDLE icdev, unsigned char mode);

  /**
   * @brief  设置停卡位置。
   * @par    说明：
   * 设置停卡位置。
   * @param[in] icdev 设备标识符。
   * @param[in] mode 模式。
   * @n 0x00 - 前端不夹卡。
   * @n 0x01 - 前端夹卡。
   * @n 0x02 - 接触式IC卡位置。
   * @n 0x03 - 射频卡位置。
   * @n 0x04 - 磁卡位置。
   * @n 0x05 - 弹卡到后端。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_SelfServiceDeviceConfigPlace(HANDLE icdev, unsigned char mode);

  /**
   * @brief  检测卡类型。
   * @par    说明：
   * 设备将自动移动卡片并且检测卡片类型。
   * @param[in] icdev 设备标识符。
   * @return <0表示失败。
   * @n 0x00 - 表示无法检测到相应卡片。
   * @n 0x01 - 表示设备内无卡。
   * @n 0x11 - 表示Type A CPU Card。
   * @n 0x13 - 表示Type A Mifare S50。
   * @n 0x14 - 表示Type A Mifare S70。
   * @n 0x15 - 表示Type A Mifare Ultralight。
   * @n 0x21 - 表示Type B CPU Card。
   * @n 0x22 - 表示Type B 存储卡。
   * @n 0x31 - 表示接触T=0 CPU Card。
   * @n 0x32 - 表示接触T=1 CPU Card。
   * @n 0x41 - 表示4442 Card。
   * @n 0x42 - 表示4428 Card。
   */
  short USER_API dc_SelfServiceDeviceCheckCardType(HANDLE icdev);

  /**
   * @brief  复位自助设备。
   * @par    说明：
   * 使自助设备进入上电初始状态，并且设置参数为缺省参数。
   * @param[in] icdev 设备标识符。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_SelfServiceDeviceReset(HANDLE icdev);

  /**
   * @brief  检测多卡状态。
   * @par    说明：
   * 判断是否为多张卡，是否为Type A或Type B卡。
   * @param[in] icdev 设备标识符。
   * @param[out] type 卡类型，0x0A表示Type A卡，0x0B表示Type B卡。
   * @return <0表示失败，==0表示成功，==1表示无卡，==2表示存在多张卡。
   */
  short USER_API dc_MulticardStatus(HANDLE icdev, unsigned char *type);

  /**
   * @brief  获取多个按键值。
   * @par    说明：
   * 获取设备键盘的按键值，每次调用可以获取多个按键值。
   * @param[in] icdev 设备标识符。
   * @param[in] ctime 设备超时值，单位为秒。
   * @param[out] rlen 返回按键数据的长度，不含'\0'。
   * @param[out] cpass 返回的按键数据，数据格式为'\0'结尾的字符串。
   * @return <0表示失败，==0表示成功，==0xA1表示取消输入，==0xA2表示输入超时。
   */
  short USER_API dc_pass_key_value2(HANDLE icdev, unsigned char ctime, unsigned char *rlen, unsigned char *cpass);

  /**
   * @brief  读外部EEPROM。
   * @par    说明：
   * 读取设备外部EEPROM中的数据，可以用作数据保存等。
   * @param[in] icdev 设备标识符。
   * @param[in] offset 偏移地址。
   * @param[in] length 读取长度。
   * @param[out] data_buffer 返回的数据。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_ReadOutEeprom(HANDLE icdev, int offset, int length, unsigned char *data_buffer);

  /**
   * @brief  写外部EEPROM。
   * @par    说明：
   * 写入数据到设备外部EEPROM中，可以用作数据保存等。
   * @param[in] icdev 设备标识符。
   * @param[in] offset 偏移地址。
   * @param[in] length 写入长度。
   * @param[in] data_buffer 传入数据。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_WriteOutEeprom(HANDLE icdev, int offset, int length, const unsigned char *data_buffer);

  /**
   * @brief  读ID卡。
   * @par    说明：
   * 读取ID卡数据。
   * @param[in] icdev 设备标识符。
   * @param[in] time_ms 设备超时值，单位为毫秒。
   * @param[out] rlen 返回数据的长度。
   * @param[out] rdata 返回的数据。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_ReadIdCardInfo(HANDLE icdev, int time_ms, int *rlen, unsigned char *rdata);

  /**
   * @brief  保留。
   */
  short USER_API dc_cpy_getkey(HANDLE icdev, unsigned char *respkey, int *resplen);

  /**
   * @brief  保留。
   */
  short USER_API dc_cpy_setkey(HANDLE icdev, unsigned char *genkey, int keylen);

  /**
   * @brief  保留。
   */
  short USER_API dc_cpy_cpuapdu(HANDLE icdev, unsigned char slen, unsigned char *sendbuffer, unsigned char *rlen, unsigned char *databuffer);

  /**
   * @brief  保留。
   */
  short USER_API dc_cpy_cpuapdu_hex(HANDLE icdev, unsigned char slen, char *sendbuffer, unsigned char *rlen, char *databuffer);

  /**
   * @brief  保留。
   */
  short USER_API dc_cpy_cpuapduInt(HANDLE icdev, unsigned int slen, unsigned char *sendbuffer, unsigned int *rlen, unsigned char *databuffer);

  /**
   * @brief  保留。
   */
  short USER_API dc_cpy_cpuapduInt_hex(HANDLE icdev, unsigned int slen, char *sendbuffer, unsigned int *rlen, char *databuffer);

  /**
   * @brief  保留。
   */
  short USER_API dc_cpy_procommand(HANDLE icdev, unsigned char slen, unsigned char *sendbuffer, unsigned char *rlen, unsigned char *databuffer, unsigned char timeout);

  /**
   * @brief  保留。
   */
  short USER_API dc_cpy_procommand_hex(HANDLE icdev, unsigned char slen, char *sendbuffer, unsigned char *rlen, char *databuffer, unsigned char timeout);

  /**
   * @brief  保留。
   */
  short USER_API dc_cpy_procommandInt(HANDLE icdev, unsigned int slen, unsigned char *sendbuffer, unsigned int *rlen, unsigned char *databuffer, unsigned char timeout);

  /**
   * @brief  保留。
   */
  short USER_API dc_cpy_procommandInt_hex(HANDLE icdev, unsigned int slen, char *sendbuffer, unsigned int *rlen, char *databuffer, unsigned char timeout);

  /**
   * @brief  非接触式CPU卡指令交互。
   * @par    说明：
   * 对感应区CPU卡进行指令交互操作，注意此接口已封装卡协议部分。
   * @param[in] icdev 设备标识符。
   * @param[in] slen 发送数据的长度。
   * @param[in] sendbuffer 发送数据。
   * @param[out] rlen 返回数据的长度。
   * @param[out] databuffer 返回的数据。
   * @param[in] timeout 超时值，此值只在部分设备的底层使用，单位为250毫秒，一般调用建议值为7。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_procommandInt(HANDLE icdev, unsigned int slen, unsigned char *sendbuffer, unsigned int *rlen, unsigned char *databuffer, unsigned char timeout);

  /**
   * @brief  非接触式CPU卡指令交互。
   * @par    说明：
   * ::dc_procommandInt 的HEX形式接口，参数 @a sendbuffer @a databuffer 为HEX格式。
   */
  short USER_API dc_procommandInt_hex(HANDLE icdev, unsigned int slen, char *sendbuffer, unsigned int *rlen, char *databuffer, unsigned char timeout);

  /**
   * @brief  保留。
   */
  short USER_API dc_ReadRfCfgReg(HANDLE icdev, int type, int number, int *value);

  /**
   * @brief  保留。
   */
  short USER_API dc_WriteRfCfgReg(HANDLE icdev, int type, int number, int value);

  /**
   * @brief  初始化NFC。
   * @par    说明：
   * 切换射频到NFC点对点模式，操作NFC点对点模式之前必须使用此接口进行初始化。
   * @param[in] icdev 设备标识符。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_NfcInit(HANDLE icdev);

  /**
   * @brief  激活NFC。
   * @par    说明：
   * 寻NFC（即激活NFC后自动链接）并返回ATR数据。
   * @param[in] icdev 设备标识符。
   * @param[out] atr 返回的数据。
   * @param[out] atr_len 返回数据的长度。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_NfcActivate(HANDLE icdev, unsigned char *atr, int *atr_len);

  /**
   * @brief  断开NFC。
   * @par    说明：
   * 断开链接并关闭天线，调用此接口必须先激活NFC。
   * @param[in] icdev 设备标识符。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_NfcDeactivate(HANDLE icdev);

  /**
   * @brief  NFC点对点数据透传（推送服务端）。
   * @par    说明：
   * 推送数据到NFC手机，调用此接口必须先激活NFC。
   * @param[in] icdev 设备标识符。
   * @param[in] request 发送数据。
   * @param[in] request_len 发送数据的长度。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_NfcPush(HANDLE icdev, const unsigned char *request, int request_len);

  /**
   * @brief  NFC点对点数据透传（从服务端接收）。
   * @par    说明：
   * 设置接收模式，开启后将进入准备接收NFC手机数据的模式，调用此接口无须激活NFC。
   * @param[in] icdev 设备标识符。
   * @param[in] flag 标记，0表示关闭，1表示开启。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_NfcService(HANDLE icdev, int flag);

  /**
   * @brief  接收NFC手机数据。
   * @par    说明：
   * 设备进入接收模式后，可以使用此接口来接收NFC手机的数据。
   * @param[in] icdev 设备标识符。
   * @param[out] response 返回的数据。
   * @param[out] response_len 返回数据的长度。
   * @param[in] time_ms 接口超时值，单位为秒。
   * @return <0表示失败，==0表示成功，==1表示手机不在感应区，==2表示数据需要重新传递。
   */
  short USER_API dc_NfcFetch(HANDLE icdev, unsigned char *response, int *response_len, int time_ms);

  /**
   * @brief  NFC点对点数据透传（从服务端接收）。
   * @par    说明：
   * 设置接收模式，开启后将进入准备接收NFC手机数据的模式，调用此接口无须激活NFC。
   * @param[in] icdev 设备标识符。
   * @param[in] mode 模式，0表示关闭，1表示开启。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_NfcSimulateCardConfig(HANDLE icdev, int mode);

  /**
   * @brief  磁条卡数据自动上传数据模式设置。
   * @par    说明：
   * 磁条卡数据自动上传数据模式设置。
   * @param[in] icdev 设备标识符。
   * @param[in] mode 模式。
   * @n 0 - 输出数据中如果带字母，字母转化为大写字母。
   * @n 1 - 输出数据是原始数据（默认）。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_MagFormatConfig(HANDLE icdev, int mode);

  /**
   * @brief  获取通讯模块MAC地址。
   * @par    说明：
   * 获取通讯模块MAC地址。
   * @param[in] icdev 设备标识符。
   * @param[in] type 模块类型，1表示蓝牙模块，2表示WIFI模块，3表示GPRS/CDMA/全网通等模块。
   * @param[out] value 返回的MAC地址，数据格式为'\0'结尾的字符串。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_ReadModuleMacAddress(HANDLE icdev, int type, char *value);

  /**
   * @brief  设置通讯模块MAC地址。
   * @par    说明：
   * 设置通讯模块MAC地址。
   * @param[in] icdev 设备标识符。
   * @param[in] type 模块类型，1表示蓝牙模块，2表示WIFI模块，3表示GPRS/CDMA/全网通等模块。
   * @param[in] value 传入MAC地址，数据格式为'\0'结尾的字符串。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_WriteModuleMacAddress(HANDLE icdev, int type, const char *value);

  /**
   * @brief  读取ATS数据。
   * @par    说明：
   * 读取Type A、Type B卡的ATS，此接口必须在卡片激活后才可使用。
   * @param[in] icdev 设备标识符。
   * @param[out] ats_len 返回ATS数据的长度。
   * @param[out] ats 返回的ATS数据。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_ReadRfTypeABATS(HANDLE icdev, int *ats_len, unsigned char *ats);

  /**
   * @brief  读取ATS数据。
   * @par    说明：
   * ::dc_ReadRfTypeABATS 的HEX形式接口，参数 @a ats 为HEX格式。
   */
  short USER_API dc_ReadRfTypeABATS_hex(HANDLE icdev, int *ats_len, char *ats);

  /**
   * @brief  保留。
   */
  short USER_API dc_RfFormatConfig(HANDLE icdev, int mode, int block_number, int offset, int length);

  /**
   * @brief  Flash扇区擦除。
   * @par    说明：
   * 擦除Flash扇区中的数据。
   * @param[in] icdev 设备标识符。
   * @param[in] sector 扇区地址，0xFFFF表示擦除全部。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_FlashErase(HANDLE icdev, int sector);

  /**
   * @brief  设备蜂鸣。
   * @par    说明：
   * 设备蜂鸣器按照指定参数进行蜂鸣，接口本身会直接返回，而不会等待蜂鸣器工作完成。
   * @param[in] icdev 设备标识符。
   * @param[in] beep_time_ms 单次蜂鸣时间，单位为毫秒。
   * @param[in] interval_time_ms 间隔时间，单位为毫秒。
   * @param[in] count 蜂鸣次数，其中0x0000表示停止，0xFFFF表示无限次。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_BuzzerBeep(HANDLE icdev, unsigned short beep_time_ms, unsigned short interval_time_ms, unsigned short count);

  /**
   * @brief  蓝牙模式设置。
   * @par    说明：
   * 设置蓝牙模块的通讯模式。
   * @param[in] icdev 设备标识符。
   * @param[in] mode 模式，0x00表示串口模式（AT指令集或EEPROM读写），0x01表示蓝牙模式。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_BtModeControl(HANDLE icdev, unsigned char mode);

  /**
   * @brief  蓝牙波特率查询/设置。
   * @par    说明：
   * 查询/设置蓝牙模块的通讯波特率，修改的是蓝牙模块端。
   * @param[in] icdev 设备标识符。
   * @param[in] flag 标记，0x00表示查询，0x01表示设置。
   * @param[in,out] value 波特率。
   * @n 0x00 - 9600。
   * @n 0x01 - 19200。
   * @n 0x02 - 38400。
   * @n 0x03 - 57600。
   * @n 0x04 - 115200。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_BtBaudrateControl(HANDLE icdev, unsigned char flag, unsigned char *value);

  /**
   * @brief  蓝牙连接密码查询/设置。
   * @par    说明：
   * 查询/设置蓝牙模块的连接密码。
   * @param[in] icdev 设备标识符。
   * @param[in] flag 标记，0x00表示查询，0x01表示设置。
   * @param[in,out] value 密码字符串，查询时请至少分配64个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_BtPasswordControl(HANDLE icdev, unsigned char flag, char *value);

  /**
   * @brief  蓝牙模块地址查询/设置。
   * @par    说明：
   * 查询/设置蓝牙模块的地址。
   * @param[in] icdev 设备标识符。
   * @param[in] flag 标记，0x00表示查询，0x01表示设置。
   * @param[in,out] length 地址的长度。
   * @param[in,out] value 地址，查询时请至少分配64个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_BtAddressControl(HANDLE icdev, unsigned char flag, unsigned char *length, unsigned char *value);

  /**
   * @brief  蓝牙模块名称查询/设置。
   * @par    说明：
   * 查询/设置蓝牙模块的名称。
   * @param[in] icdev 设备标识符。
   * @param[in] flag 标记，0x00表示查询，0x01表示设置。
   * @param[in,out] value 名称字符串，查询时请至少分配64个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_BtNameControl(HANDLE icdev, unsigned char flag, char *value);

  /**
   * @brief  蓝牙用户自定义的配置命令。
   * @par    说明：
   * 采用读写EEPROM方式进行蓝牙模块的自定义配置。
   * @param[in] icdev 设备标识符。
   * @param[in] flag 标记，0x00表示读EEPROM，0x01表示写EEPROM或AT指令集模式。
   * @param[in] offset 偏移地址。
   * @param[in] length 数据的长度。
   * @param[in,out] value 数据。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_BtUserControl(HANDLE icdev, unsigned char flag, int offset, int length, unsigned char *value);

  /**
   * @brief  蓝牙软件复位。
   * @par    说明：
   * 对蓝牙模块进行软件复位。
   * @param[in] icdev 设备标识符。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_BtReset(HANDLE icdev);

  /**
   * @brief  蓝牙模块通讯测试。
   * @par    说明：
   * 蓝牙模块在蓝牙通讯模式下，用此接口可以测试蓝牙通讯是否通畅，数据发送成功后，监测相关串口是否有接收到该数据来判断通讯是否成功。
   * @param[in] icdev 设备标识符。
   * @param[in] length 发送数据的长度。
   * @param[in] value 发送数据。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_BtCommunicationTest(HANDLE icdev, int length, const unsigned char *value);

  /**
   * @brief  蓝牙波特率查询/设置。
   * @par    说明：
   * 查询/设置与蓝牙模块之间的通讯波特率，修改的是设备端。
   * @param[in] icdev 设备标识符。
   * @param[in] flag 标记，0x00表示查询，0x01表示设置。
   * @param[in,out] value 波特率。
   * @n 0x00 - 2400。
   * @n 0x01 - 4800。
   * @n 0x02 - 9600。
   * @n 0x03 - 14400。
   * @n 0x04 - 38400。
   * @n 0x05 - 57600。
   * @n 0x06 - 115200。
   * @n 0x07 - 256000。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_BtWithReaderBaudrateControl(HANDLE icdev, unsigned char flag, unsigned char *value);

  /**
   * @brief  蓝牙模块通讯。
   * @par    说明：
   * 与蓝牙模块进行通讯交互。
   * @param[in] icdev 设备标识符。
   * @param[in] slen 发送数据的长度。
   * @param[in] sdata 发送数据。
   * @param[out] rlen 返回数据的长度。
   * @param[out] rdata 返回的数据。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_BtCommand(HANDLE icdev, int slen, const unsigned char *sdata, int *rlen, unsigned char *rdata);

  /**
   * @brief  获取蓝牙信号强度。
   * @par    说明：
   * 获取蓝牙信号强度。
   * @param[in] icdev 设备标识符。
   * @param[out] state 状态，0x00表示蓝牙未连接，0x01表示蓝牙已连接。
   * @param[out] value 信号值。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_BtSignalStrength(HANDLE icdev, unsigned char *state, short *value);

  /**
   * @brief  获取蓝牙响应。
   * @par    说明：
   * 获取蓝牙模块当前执行命令的响应或数据。
   * @param[in] icdev 设备标识符。
   * @param[out] length 返回数据的长度。
   * @param[out] value 返回的数据。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_BtDataResponse(HANDLE icdev, int *length, unsigned char *value);

  /**
   * @brief  蓝牙数据透传。
   * @par    说明：
   * 此接口用于将从蓝牙接收到的数据透传到外设中，并返回从外设接收的数据。
   * @param[in] icdev 设备标识符。
   * @param[in] slen 发送数据的长度。
   * @param[in] sdata 发送数据。
   * @param[out] rlen 返回数据的长度。
   * @param[out] rdata 返回的数据。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_BtDataTransmit(HANDLE icdev, int slen, const unsigned char *sdata, int *rlen, unsigned char *rdata);

  /**
   * @brief  SAM_A模块指令交互。
   * @par    说明：
   * 此接口用于操作居民身份证验证安全控制模块。
   * @param[in] icdev 设备标识符。
   * @param[in] code 指令代码。
   * @n 0x10FF - 复位SAM_A，无发送数据，无返回数据。
   * @n 0x11FF - SAM_A状态检测，无发送数据，无返回数据。
   * @n 0x12FF - 读SAM_A管理信息，无发送数据，返回数据为16个字节的SAM_A编号。
   * @n 0x2001 - 寻找居民身份证，无发送数据，返回数据为4个字节的0x00。
   * @n 0x2002 - 选取居民身份证，无发送数据，返回数据为8个字节的0x00。
   * @n 0x3001 - 读机读文字信息和相片信息，无发送数据，返回数据格式为：【2个字节文字信息长度（Big-Endian）】【2个字节相片信息长度（Big-Endian）】【文字信息（不大于256个字节）】【相片信息（不大于1024个字节）】。
   * @n 0x3010 - 读机读文字信息、相片信息和指纹信息，无发送数据，返回数据格式为：【2个字节文字信息长度（Big-Endian）】【2个字节相片信息长度（Big-Endian）】【2个字节指纹信息长度（Big-Endian）】【文字信息（不大于256个字节）】【相片信息（不大于1024个字节）】【指纹信息（不大于1024个字节）】。
   * @n 0x3003 - 读追加住址信息，无发送数据，返回数据为70个字节的追加住址信息。
   * @n 0x6000 - 设置UART接口速率，速率为115200bps，无发送数据，无返回数据。
   * @n 0x6001 - 设置UART接口速率，速率为57600bps，无发送数据，无返回数据。
   * @n 0x6002 - 设置UART接口速率，速率为38400bps，无发送数据，无返回数据。
   * @n 0x6003 - 设置UART接口速率，速率为19200bps，无发送数据，无返回数据。
   * @n 0x6004 - 设置UART接口速率，速率为9600bps，无发送数据，无返回数据。
   * @n 0x61FF - 设置SAM_A与射频模块一帧通信数据的最大字节数，发送数据为1个字节的最大字节数，取值返回为0x18~0xFF，默认值为0x58，无返回数据。
   * @param[in] slen 发送数据的长度。
   * @param[in] sdata 发送数据。
   * @param[out] rlen 返回数据的长度。
   * @param[out] rdata 返回的数据，请至少分配4096个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_SamAControl(HANDLE icdev, int code, int slen, const unsigned char *sdata, int *rlen, unsigned char *rdata);

  /**
   * @brief  读身份证。
   * @par    说明：
   * 读取身份证的原始信息数据。
   * @param[in] icdev 设备标识符。
   * @param[in] type 类型。
   * @n 1 - 读取文字信息、相片信息和指纹信息。
   * @n 2 - 读取追加住址信息。
   * @n 3 - 读取文字信息、相片信息、指纹信息和追加住址信息。
   * @param[out] text_len 返回文字信息的长度。
   * @param[out] text 返回的文字信息，请至少分配256个字节。
   * @param[out] photo_len 返回相片信息的长度。
   * @param[out] photo 返回的相片信息，请至少分配1024个字节。
   * @param[out] fingerprint_len 返回指纹信息的长度。
   * @param[out] fingerprint 返回的指纹信息，请至少分配1024个字节。
   * @param[out] extra_len 返回追加住址信息的长度。
   * @param[out] extra 返回的追加住址信息，请至少分配70个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_SamAReadCardInfo(HANDLE icdev, int type, int *text_len, unsigned char *text, int *photo_len, unsigned char *photo, int *fingerprint_len, unsigned char *fingerprint, int *extra_len, unsigned char *extra);

  /**
   * @brief  解析文字信息。
   * @par    说明：
   * 解析中国人居民身份证文字信息，获取相应的条目。
   * @param[in] icdev 设备标识符。
   * @param[in] charset 获取条目将采用的字符集，0表示GBK，1表示UCS-2。
   * @param[in] info_len 文字信息的长度。
   * @param[in] info 文字信息。
   * @param[out] name 姓名，请至少分配64个字节。
   * @param[out] sex 性别，请至少分配8个字节。
   * @param[out] nation 民族，请至少分配12个字节。
   * @param[out] birth_day 出生日期，请至少分配36个字节。
   * @param[out] address 住址，请至少分配144个字节。
   * @param[out] id_number 公民身份号码，请至少分配76个字节。
   * @param[out] department 签发机关，请至少分配64个字节。
   * @param[out] expire_start_day 证件签发日期，请至少分配36个字节。
   * @param[out] expire_end_day 证件终止日期，请至少分配36个字节。
   * @param[out] reserved 预留项，请至少分配76个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_ParseTextInfo(HANDLE icdev, int charset, int info_len, const unsigned char *info, unsigned char *name, unsigned char *sex, unsigned char *nation, unsigned char *birth_day, unsigned char *address, unsigned char *id_number, unsigned char *department, unsigned char *expire_start_day, unsigned char *expire_end_day, unsigned char *reserved);

  /**
   * @brief  解析文字信息。
   * @par    说明：
   * 解析外国人永久居留证文字信息，获取相应的条目。
   * @param[in] icdev 设备标识符。
   * @param[in] charset 获取条目将采用的字符集，0表示GBK，1表示UCS-2。
   * @param[in] info_len 文字信息的长度。
   * @param[in] info 文字信息。
   * @param[out] english_name 英文姓名，请至少分配244个字节。
   * @param[out] sex 性别，请至少分配8个字节。
   * @param[out] id_number 永久居留证号码，请至少分配64个字节。
   * @param[out] citizenship 国籍或所在地区代码，请至少分配16个字节。
   * @param[out] chinese_name 中文姓名，请至少分配64个字节。
   * @param[out] expire_start_day 证件签发日期，请至少分配36个字节。
   * @param[out] expire_end_day 证件终止日期，请至少分配36个字节。
   * @param[out] birth_day 出生日期，请至少分配36个字节。
   * @param[out] version_number 证件版本号，请至少分配12个字节。
   * @param[out] department_code 当次申请受理机关代码，请至少分配20个字节。
   * @param[out] type_sign 证件类型标识，请至少分配8个字节。
   * @param[out] reserved 预留项，请至少分配16个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_ParseTextInfoForForeigner(HANDLE icdev, int charset, int info_len, const unsigned char *info, unsigned char *english_name, unsigned char *sex, unsigned char *id_number, unsigned char *citizenship, unsigned char *chinese_name, unsigned char *expire_start_day, unsigned char *expire_end_day, unsigned char *birth_day, unsigned char *version_number, unsigned char *department_code, unsigned char *type_sign, unsigned char *reserved);

  /**
   * @brief  解析相片信息。
   * @par    说明：
   * 解析相片信息，通过公安部相片解码库还原相片图像数据。
   * @param[in] icdev 设备标识符。
   * @param[in] type 相片图像数据的格式，0表示BMP文件，1表示BMP缓存，2表示BMP Base64字符串。
   * @param[in] info_len 相片信息的长度。
   * @param[in] info 相片信息。
   * @param[in,out] photo_len 数据的长度。
   * @n BMP文件 - 无效。
   * @n BMP缓存 - 传入 @a photo 分配的字节数，返回相片图像数据的长度。
   * @n BMP Base64字符串 - 传入 @a photo 分配的字节数，返回相片图像数据Base64字符串的长度，不含'\0'。
   * @param[in,out] photo 数据。
   * @n BMP文件 - 传入文件名，请确保有写入的权限。
   * @n BMP缓存 - 返回的相片图像数据，请至少分配65536个字节。
   * @n BMP Base64字符串 - 返回的相片图像数据Base64字符串，请至少分配65536个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_ParsePhotoInfo(HANDLE icdev, int type, int info_len, const unsigned char *info, int *photo_len, unsigned char *photo);

  /**
   * @brief  解析其它信息。
   * @par    说明：
   * 解析其它信息。
   * @param[in] icdev 设备标识符。
   * @param[in] flag 标志，0表示性别，1表示民族，2表示国籍。
   * @param[in] in_info 传入信息。
   * @param[out] out_info 返回的信息。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_ParseOtherInfo(HANDLE icdev, int flag, const unsigned char *in_info, unsigned char *out_info);

  /**
   * @brief  检测接触式CPU卡。
   * @par    说明：
   * 检测当前卡座中CPU卡的状态。
   * @param[in] icdev 设备标识符。
   * @return <0表示失败。
   * @n 0 - 状态未知。
   * @n 1 - 无卡。
   * @n 2 - 有卡，但卡类型未知。
   * @n 3 - 有卡，卡未上电。
   * @n 4 - 有卡，卡已上电。
   */
  short USER_API dc_CpuCardStatus(HANDLE icdev);

  /**
   * @brief  唤醒设备。
   * @par    说明：
   * 唤醒设备，此接口用于向设备发出唤醒请求，成功则表示设备已经唤醒。
   * @param[in] icdev 设备标识符。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_WakeDevice(HANDLE icdev);

  /**
   * @brief  休眠设备。
   * @par    说明：
   * 休眠设备，此接口用于向设备发出休眠请求，执行成功仅仅表示成功发出休眠请求，并不表示设备已经进入休眠状态。
   * @param[in] icdev 设备标识符。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_RestDevice(HANDLE icdev);

  /**
   * @brief  获取电池电量。
   * @par    说明：
   * 获取电池电量。
   * @param[in] icdev 设备标识符。
   * @param[out] value 电池百分比（0x00~0x64），0x00表示0%，0x64表示100%。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_GetBatteryValue(HANDLE icdev, unsigned char *value);

  /**
   * @brief  防卡冲突。
   * @par    说明：
   * 支持ISO 14443 Type A类型卡片的防卡冲突。
   * @param[in] icdev 设备标识符。
   * @param[in] mode 模式，0x93表示一级，0x95表示二级，0x97表示三级。
   * @param[in] _Bcnt 保留，固定为0x00。
   * @param[out] _Snr 返回的卡序列号。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_anticoll_mode(HANDLE icdev, unsigned char mode, unsigned char _Bcnt, unsigned int *_Snr);

  /**
   * @brief  选卡操作。
   * @par    说明：
   * 通过指定序列号，选取相应的卡片。
   * @param[in] icdev 设备标识符。
   * @param[in] mode 模式，0x93表示一级，0x95表示二级，0x97表示三级。
   * @param[in] _Snr 卡片序列号。
   * @param[out] _Size 返回的SAK值。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_select_mode(HANDLE icdev, unsigned char mode, unsigned int _Snr, unsigned char *_Size);

  /**
   * @brief  激活卡片。
   * @par    说明：
   * 支持ISO 14443 Type B类型卡片的激活。
   * @param[in] icdev 设备标识符。
   * @param[in] PUPI 伪唯一PICC标识符。
   * @param[in] CID 信道号。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_attribInt(HANDLE icdev, unsigned char *PUPI, unsigned char CID);

  /**
   * @brief  卡上电。
   * @par    说明：
   * 对指定卡座的卡片进行上电操作。
   * @param[in] icdev 设备标识符。
   * @param[in] icc_slot_no 卡座编号，用户卡为0x0n，SAM卡为0x1n，其中“n”的取值范围为1~F。
   * @param[out] response 返回的复位信息，请至少分配128个字节。
   * @return <0表示失败，否则为返回复位信息的长度。
   * @n -1 - 卡片类型不对。
   * @n -2 - 无卡。
   * @n -3 - 有卡未上电。
   * @n -4 - 卡片无应答。
   */
  short USER_API dc_rf_poweron(HANDLE icdev, unsigned char icc_slot_no, unsigned char *response);

  /**
   * @brief  卡下电。
   * @par    说明：
   * 对指定卡座的卡片进行下电操作。
   * @param[in] icdev 设备标识符。
   * @param[in] icc_slot_no 卡座编号，用户卡为0x0n，SAM卡为0x1n，其中“n”的取值范围为1~F。
   * @return <0表示失败，==0表示成功。
   * @n -1 - 卡片类型不对。
   * @n -2 - 无卡。
   * @n -3 - 有卡未上电。
   * @n -4 - 卡片无应答。
   */
  short USER_API dc_rf_poweroff(HANDLE icdev, unsigned char icc_slot_no);

  /**
   * @brief  获取卡状态。
   * @par    说明：
   * 获取指定卡座的卡片状态。
   * @param[in] icdev 设备标识符。
   * @param[in] icc_slot_no 卡座编号，用户卡为0x0n，SAM卡为0x1n，其中“n”的取值范围为1~F。
   * @return <0表示失败，==0表示有卡且已上电。
   * @n -1 - 卡片类型不对。
   * @n -2 - 无卡。
   * @n -3 - 有卡未上电。
   * @n -4 - 卡片无应答。
   */
  short USER_API dc_rf_getstatus(HANDLE icdev, unsigned char icc_slot_no);

  /**
   * @brief  卡指令交互。
   * @par    说明：
   * 对指定卡座的卡片进行指令交互操作。
   * @param[in] icdev 设备标识符。
   * @param[in] icc_slot_no 卡座编号，用户卡为0x0n，SAM卡为0x1n，其中“n”的取值范围为1~F。
   * @param[in] length_of_command_apdu 发送数据的长度。
   * @param[in] command_apdu 发送数据的长度。
   * @param[in] length_of_command_apdu 发送数据。
   * @param[out] response_apdu 返回的数据。
   * @return <0表示失败，否则为返回数据的长度。
   * @n -1 - 卡片类型不对。
   * @n -2 - 无卡。
   * @n -3 - 有卡未上电。
   * @n -4 - 卡片无应答。
   */
  short USER_API dc_rf_application(HANDLE icdev, unsigned char icc_slot_no, int length_of_command_apdu, unsigned char *command_apdu, unsigned char *response_apdu);

  /**
   * @brief  获取多张Type A卡UID。
   * @par    说明：
   * 获取多张Type A卡UID。
   * @param[in] icdev 设备标识符。
   * @param[out] uid_data 返回的数据，请至少分配256个字节。格式为：【1字节UID条目数量】【1字节UID长度】【UID】【1字节UID2长度】【UID2】...。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_RequestMultiCard(HANDLE icdev, unsigned char *uid_data);

  /**
   * @brief  选择一张Type A卡并激活。
   * @par    说明：
   * 选择一张Type A卡并激活。
   * @param[in] icdev 设备标识符。
   * @param[in] uid_len 传入UID的长度。
   * @param[in] uid 传入UID。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_ActivateCard(HANDLE icdev, unsigned char uid_len, const unsigned char *uid);

  /**
   * @brief  获取最后响应码。
   * @par    说明：
   * 获取最后一次和设备交互时设备返回的响应状态代码，此接口获取的响应码依赖设备内部固件代码的实现，不同的设备可能有不一致的响应码。
   * @param[in] icdev 设备标识符。
   * @param[out] code 返回的响应码。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_GetLastResponseCode(HANDLE icdev, unsigned int *code);

  /**
   * @brief  多个Flash扇区擦除。
   * @par    说明：
   * 擦除指定Flash扇区中的数据。
   * @param[in] icdev 设备标识符。
   * @param[in] type 类型，0x00表示核心板上的Flash，0x01表示主Spi的Flash，0x02表示备份Spi的Flash，0x03表示语音存储的Flash，0x04表示字库存储的Flash。
   * @param[in] sector 扇区地址，0xFFFFFFFF表示擦除全部。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_MultiFlashErase(HANDLE icdev, unsigned char type, unsigned int sector);

  /**
   * @brief  多个Flash读数据。
   * @par    说明：
   * 读取指定Flash中的数据。
   * @param[in] icdev 设备标识符。
   * @param[in] type 类型，0x00表示核心板上的Flash，0x01表示主Spi的Flash，0x02表示备份Spi的Flash，0x03表示语音存储的Flash，0x04表示字库存储的Flash。
   * @param[in] offset_h 偏移地址（高位）。
   * @param[in] offset_l 偏移地址（低位）。
   * @param[in] length_h 读取长度（高位）。
   * @param[in] length_l 读取长度（低位）。
   * @param[out] data_buffer 返回的数据。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_MultiFlashRead(HANDLE icdev, unsigned char type, unsigned int offset_h, unsigned int offset_l, unsigned int length_h, unsigned int length_l, unsigned char *data_buffer);

  /**
   * @brief  多个Flash写数据。
   * @par    说明：
   * 写入数据到指定Flash中。
   * @param[in] icdev 设备标识符。
   * @param[in] type 类型，0x00表示核心板上的Flash，0x01表示主Spi的Flash，0x02表示备份Spi的Flash，0x03表示语音存储的Flash，0x04表示字库存储的Flash。
   * @param[in] offset_h 偏移地址（高位）。
   * @param[in] offset_l 偏移地址（低位）。
   * @param[in] length_h 读取长度（高位）。
   * @param[in] length_l 读取长度（低位）。
   * @param[in] data_buffer 传入数据。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_MultiFlashWrite(HANDLE icdev, unsigned char type, unsigned int offset_h, unsigned int offset_l, unsigned int length_h, unsigned int length_l, const unsigned char *data_buffer);

  /**
   * @brief  多个FLASH容量大小获取。
   * @par    说明：
   * 获取指定Flash的容量大小。
   * @param[in] icdev 设备标识符。
   * @param[in] type 类型，0x00表示核心板上的Flash，0x01表示主Spi的Flash，0x02表示备份Spi的Flash，0x03表示语音存储的Flash，0x04表示字库存储的Flash。
   * @param[out] length_h 返回的长度（高位）。
   * @param[out] length_l 返回的长度（低位）。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_MultiFlashGetSize(HANDLE icdev, unsigned char type, unsigned int *length_h, unsigned int *length_l);

  /**
   * @brief  多重寻卡。
   * @par    说明：
   * 有卡寻卡、无卡寻卡、多卡防冲突。
   * @param[in] icdev 设备标识符。
   * @return <0表示失败。
   * @n 0 - 操作成功。
   * @n 1 - 未检测到射频卡。
   * @n 2 - 检测到身份证。
   * @n 3 - 多卡报错。
   * @n 4 - 其它射频卡。
   * @n 5 - 检测到Type A / Type B CPU卡。
   * @n 6 - 检测到有卡后的卡片还在感应区。
   */
  short USER_API dc_RfMultiRequest(HANDLE icdev);

  /**
   * @brief  TTS语音播放。
   * @par    说明：
   * TTS语音播放。
   * @param[in] icdev 设备标识符。
   * @param[in] type 类型，0x00表示停止播放，0x01表示播放内容为UCS2编码，0x02表示播放内容为GBK编码。
   * @param[in] content 播放内容。
   * @param[in] content_len 播放内容的长度。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_TtsVoicePlay(HANDLE icdev, unsigned char type, const unsigned char *content, int content_len);

  /**
   * @brief  TTS语音设置。
   * @par    说明：
   * TTS语音设置。
   * @param[in] icdev 设备标识符。
   * @param[in] type 类型，0x01表示设置语速，0x02表示设置音量，0x03表示设置音色。
   * @param[in] value 增益值（0x00~0xFF），正常为0x80。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_TtsVoiceConfig(HANDLE icdev, unsigned char type, unsigned char value);

  /**
   * @brief  配置二维码工作模式。
   * @par    说明：
   * 配置二维码工作模式。
   * @param[in] icdev 设备标识符。
   * @param[in] content 配置内容。
   * @param[in] content_len 配置内容的长度。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_Config2DBarcode(HANDLE icdev, const unsigned char *content, int content_len);

  /**
   * @brief  扫描二维码。
   * @par    说明：
   * 扫描二维码。
   * @param[in] icdev 设备标识符。
   * @param[in] time_ms 设备超时值，单位为毫秒。
   * @param[out] message_data 二维码，数据格式为'\0'结尾的字符串。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_Scan2DBarcode(HANDLE icdev, unsigned short time_ms, char *message_data);

  /**
   * @brief  打开密码键盘。
   * @par    说明：
   * 打开密码键盘并且分配相关资源。
   * @param[in] icdev 设备标识符。
   * @param[in] number 编号，0表示内置密码键盘，1表示外置密码键盘。
   * @param[out] version 返回的版本字符串，请至少分配128个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_KeypadOpen(HANDLE icdev, int number, char *version);

  /**
   * @brief  关闭密码键盘。
   * @par    说明：
   * 关闭密码键盘并且释放相关资源。
   * @param[in] icdev 设备标识符。
   * @param[in] number 编号，0表示内置密码键盘，1表示外置密码键盘。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_KeypadClose(HANDLE icdev, int number);

  /**
   * @brief  装载密钥。
   * @par    说明：
   * 装载密钥到密码键盘中永久保存。
   * @param[in] icdev 设备标识符。
   * @param[in] number 编号，0表示内置密码键盘，1表示外置密码键盘。
   * @param[in] set_index 密钥套索引（0~15）。
   * @param[in] sub_index 密钥索引（0~15），其中0表示主密钥。
   * @param[in] type 密钥类型，0表示单DES，1表示三DES，2表示24字节三DES，16表示SM4。
   * @param[in] mode 装载模式，0表示明文装载，1表示密文装载。
   * @param[in] key_data 密钥数据。
   * @param[in] key_len 密钥数据的长度。
   * @param[in] flag 标志，0表示不验证，1表示验证类别1，2表示验证类别2。
   * @param[in,out] ex_data 附加数据，含义由 @a flag 的值来决定。
   * @n flag为1 - ex_data为out形式的参数，返回加密全0x00后的数据。
   * @n flag为2 - ex_data为In形式的参数，传入加密全0x00后的数据。
   * @param[in,out] ex_len 附加数据的长度，含义由 @a flag 的值来决定。
   * @n flag为1 - ex_len为Out形式的参数，返回 @a ex_data 的长度。
   * @n flag为2 - ex_len为In形式的参数，传入 @a ex_data 的长度。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_KeypadLoadKey(HANDLE icdev, int number, int set_index, int sub_index, int type, int mode, const unsigned char *key_data, int key_len, int flag, unsigned char *ex_data, int *ex_len);

  /**
   * @brief  清除密钥。
   * @par    说明：
   * 清除密码键盘中指定的密钥。
   * @param[in] icdev 设备标识符。
   * @param[in] number 编号，0表示内置密码键盘，1表示外置密码键盘。
   * @param[in] set_index 密钥套索引（0~15），-1表示全部密钥套。
   * @param[in] sub_index 密钥索引（0~15），其中0表示主密钥，-1表示全部密钥。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_KeypadClearKey(HANDLE icdev, int number, int set_index, int sub_index);

  /**
   * @brief  获取密钥类型。
   * @par    说明：
   * 获取密码键盘中指定密钥的类型。
   * @param[in] icdev 设备标识符。
   * @param[in] number 编号，0表示内置密码键盘，1表示外置密码键盘。
   * @param[in] set_index 密钥套索引（0~15）。
   * @param[in] sub_index 密钥索引（0~15），其中0表示主密钥。
   * @param[out] type 密钥类型，0表示单DES，1表示三DES，2表示24字节三DES，16表示SM4。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_KeypadGetKeyType(HANDLE icdev, int number, int set_index, int sub_index, int *type);

  /**
   * @brief  数据加解密。
   * @par    说明：
   * 使用密码键盘中装载的密钥进行数据加解密操作。
   * @param[in] icdev 设备标识符。
   * @param[in] number 编号，0表示内置密码键盘，1表示外置密码键盘。
   * @param[in] set_index 密钥套索引（0~15）。
   * @param[in] sub_index 密钥索引（0~15），其中0表示主密钥。
   * @param[in] flag 标志，0表示使用密钥默认算法，1表示使用密钥0~7字节算单DES，2表示使用密钥8~15字节算单DES，3表示使用密钥16~23字节算单DES。
   * @param[in] mode 模式，0表示加密，1表示解密。
   * @param[in] in_data 输入数据。
   * @param[in] in_len 输入数据的长度。
   * @param[out] out_data 输出数据。
   * @param[out] out_len 输出数据的长度。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_KeypadAlgorithm(HANDLE icdev, int number, int set_index, int sub_index, int flag, int mode, const unsigned char *in_data, int in_len, unsigned char *out_data, int *out_len);

  /**
   * @brief  启动按键输入。
   * @par    说明：
   * 启动密码键盘的按键输入，这时设备将开始接收用户的按键输入操作。
   * @param[in] icdev 设备标识符。
   * @param[in] number 编号，0表示内置密码键盘，1表示外置密码键盘。
   * @param[in] mode 模式，0表示获取明文，1表示获取ANSI X9.8 PIN BLOCK加密的按键数据，2表示获取IBM3624加密的按键数据，3表示获取ANSII加密的按键数据。
   * @param[in] set_index 密钥套索引（0~15），明文模式内部将忽略它的传入。
   * @param[in] sub_index 密钥索引（0~15），其中0表示主密钥，明文模式内部将忽略它的传入。
   * @param[in] in_data 输入数据，依赖于模式，明文模式内部将忽略它的传入，密文模式为卡号，固定为12个字节。
   * @param[in] in_len 输入数据的长度。
   * @param[in] min_len 最小长度。
   * @param[in] max_len 最大长度。
   * @param[in] auto_end 按键时结束控制（此处的结束表示的仅仅是设备是否会自动加入【确认】键值），0表示不自动结束，1表示自动结束。
   * @param[in] enable_beep 按键时蜂鸣声控制，0表示不使用蜂鸣，1表示使用蜂鸣。
   * @param[in] time_s 从开始按键后，两次按键之间的时间间隔超时值，单位为秒，其中-1表示不使用时间间隔超时值，0表示缺省值（由设备实现决定）。
   * @param[out] out_data 输出数据。
   * @param[out] out_len 输出数据的长度。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_KeypadStartInput(HANDLE icdev, int number, int mode, int set_index, int sub_index, const unsigned char *in_data, int in_len, int min_len, int max_len, int auto_end, int enable_beep, int time_s, unsigned char *out_data, int *out_len);

  /**
   * @brief  获取键值。
   * @par    说明：
   * 获取一个按下的按键值，每次只能获取一个。
   * @param[in] icdev 设备标识符。
   * @param[in] number 编号，0表示内置密码键盘，1表示外置密码键盘。
   * @param[out] value 明文输入模式下数值键为键值的ASCII值，如键盘1为0x31；密文输入模式下数值键为0x2A；任何输入模式下控制键的键值一致，【退格】为0x08，【确认】为0x0D，【取消】为0x1B，【清除】为0x7F；另外没有按键按下为0xFF，输入超时为0x80。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_KeypadGetKeyValue(HANDLE icdev, int number, unsigned char *value);

  /**
   * @brief  退出并且获取密码数据。
   * @par    说明：
   * 退出并且获取密码键盘的密码数据，这时设备将停止接收用户的按键输入操作。
   * @param[in] icdev 设备标识符。
   * @param[in] number 编号，0表示内置密码键盘，1表示外置密码键盘。
   * @param[in] mode 模式，0表示仅退出，1表示退出并且获取数据。
   * @param[out] out_data 输出数据。
   * @param[out] out_len 输出数据的长度。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_KeypadExitAndGetInput(HANDLE icdev, int number, int mode, unsigned char *out_data, int *out_len);

  /**
   * @brief  设置键值。
   * @par    说明：
   * 设置一个按下的按键值，每次只能设置一个。
   * @param[in] icdev 设备标识符。
   * @param[in] number 编号，0表示内置密码键盘，1表示外置密码键盘。
   * @param[in] value 数值键为键值的ASCII值，如键盘1为0x31；控制键【退格】为0x08，【确认】为0x0D，【取消】为0x1B，【清除】为0x7F。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_KeypadSetKeyValue(HANDLE icdev, int number, unsigned char value);

  /**
   * @brief  获取设备唯一识别码。
   * @par    说明：
   * 获取设备内部写入的唯一识别码。
   * @param[in] icdev 设备标识符。
   * @param[out] uid 返回的唯一识别码字符串，请至少分配33个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_GetDeviceUid(HANDLE icdev, char *uid);

  /**
   * @brief  获取设备商户号。
   * @par    说明：
   * 获取设备内部写入的商户号。
   * @param[in] icdev 设备标识符。
   * @param[out] number 返回的商户号字符串，请至少分配33个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_GetDeviceTradeNumber(HANDLE icdev, char *number);

  /**
   * @brief  获取设备终端号。
   * @par    说明：
   * 获取设备内部写入的终端号。
   * @param[in] icdev 设备标识符。
   * @param[out] number 返回的终端号字符串，请至少分配33个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_GetDeviceTerminalNumber(HANDLE icdev, char *number);

  /**
   * @brief  读取设备自定义信息。
   * @par    说明：
   * 读取设备自定义信息。
   * @param[in] icdev 设备标识符。
   * @param[out] info 返回的信息，固定为8个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_ReadDeviceCustomInfo(HANDLE icdev, unsigned char *info);

  /**
   * @brief  写入设备自定义信息。
   * @par    说明：
   * 写入设备自定义信息。
   * @param[in] icdev 设备标识符。
   * @param[in] info 传入信息，固定为8个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_WriteDeviceCustomInfo(HANDLE icdev, const unsigned char *info);

  /**
   * @brief  读取设备型号名称。
   * @par    说明：
   * 读取设备型号名称。
   * @param[in] icdev 设备标识符。
   * @param[out] name 返回的型号名称字符串，请至少分配33个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_ReadDeviceTypeName(HANDLE icdev, char *name);

  /**
   * @brief  写入设备型号名称。
   * @par    说明：
   * 写入设备型号名称。
   * @param[in] icdev 设备标识符。
   * @param[in] name 传入型号名称，数据格式为'\0'结尾的字符串。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_WriteDeviceTypeName(HANDLE icdev, const char *name);

  /**
   * @brief  无线模块电源控制。
   * @par    说明：
   * 无线模块电源控制。
   * @param[in] icdev 设备标识符。
   * @param[in] value 开关，0x00表示关闭，0x01表示开启。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_WirelessPowerControl(HANDLE icdev, unsigned char value);

  /**
   * @brief  打开TCP链接。
   * @par    说明：
   * 打开TCP链接。
   * @param[in] icdev 设备标识符。
   * @param[in] type 无线模块类型，0x00表示CDMA，0x01表示GPRS，0x02表示WIFI。
   * @param[in] network_address IP地址或域名，数据格式为'\0'结尾的字符串。
   * @param[in] network_port IP端口号，数据格式为'\0'结尾的字符串。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_WirelessTcpOpen(HANDLE icdev, unsigned char type, const char *network_address, const char *network_port);

  /**
   * @brief  关闭TCP链接。
   * @par    说明：
   * 关闭TCP链接。
   * @param[in] icdev 设备标识符。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_WirelessTcpClose(HANDLE icdev);

  /**
   * @brief  查询网络状态。
   * @par    说明：
   * 查询网络状态。
   * @param[in] icdev 设备标识符。
   * @param[out] value 状态值，固定为1个字节。
   * @n 0x00 - 表示TCP初始状态。
   * @n 0x01 - 表示无线模块无法通讯。
   * @n 0x02 - 表示无线模块电源关闭。
   * @n 0x03 - 表示无线模块电源开启。
   * @n 0x04 - 表示SIM卡异常或者无卡。
   * @n 0x05 - 表示网络信号异常。
   * @n 0x06 - 表示无线模块自检成功。
   * @n 0x07 - 表示TCP空闲状态。
   * @n 0x08 - 表示TCP已经连接成功。
   * @n 0x09 - 表示TCP已经断开连接。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_WirelessGetStatus(HANDLE icdev, unsigned char *value);

  /**
   * @brief  发送数据到网络端。
   * @par    说明：
   * 发送数据到网络端。
   * @param[in] icdev 设备标识符。
   * @param[in] type 无线模块类型，0x00表示CDMA，0x01表示GPRS，0x02表示WIFI。
   * @param[in] data_buffer 发送数据。
   * @param[in] data_len 发送数据的长度。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_WirelessSend(HANDLE icdev, unsigned char type, const unsigned char *data_buffer, int data_len);

  /**
   * @brief  从网络端接收数据。
   * @par    说明：
   * 从网络端接收数据。
   * @param[in] icdev 设备标识符。
   * @param[in] type 无线模块类型，0x00表示CDMA，0x01表示GPRS，0x02表示WIFI。
   * @param[in] mode 模式，0x00表示接收的数据格式不带格式头符号，0x01表示接收的数据格式带格式头符号，WIFI模块此参数无效。
   * @param[in] time_100ms 设备超时值，单位为100毫秒。
   * @param[out] data_buffer 返回的数据。
   * @param[out] data_len 返回数据的长度。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_WirelessRecv(HANDLE icdev, unsigned char type, unsigned char mode, unsigned char time_100ms, unsigned char *data_buffer, int *data_len);

  /**
   * @brief  配置WIFI参数。
   * @par    说明：
   * 配置WIFI参数。
   * @param[in] icdev 设备标识符。
   * @param[in] type 无线模块类型，0x00表示CDMA，0x01表示GPRS，0x02表示WIFI。
   * @param[in] ssid WIFI SSID，数据格式为'\0'结尾的字符串。
   * @param[in] password WIFI密码，数据格式为'\0'结尾的字符串。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_WirelessWifiConfig(HANDLE icdev, unsigned char type, const char *ssid, const char *password);

  /**
   * @brief  获取GPS信息。
   * @par    说明：
   * 获取GPS信息。
   * @param[in] icdev 设备标识符。
   * @param[in] time_ms 设备超时值，单位为毫秒。
   * @param[out] data_buffer 返回的数据。
   * @param[out] data_len 返回数据的长度。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_GpsGetInfo(HANDLE icdev, int time_ms, unsigned char *data_buffer, int *data_len);

  /**
   * @brief  设置接触式CPU卡616C配置。
   * @par    说明：
   * 设置接触式CPU卡616C配置。
   * @param[in] icdev 设备标识符。
   * @param[in] value 配置值，0x00表示设备不处理616C，0x01表示设备处理616C。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_SetCpuCard616C(HANDLE icdev, unsigned char value);

  /**
   * @brief  获取接触式CPU卡616C配置。
   * @par    说明：
   * 获取接触式CPU卡616C配置。
   * @param[in] icdev 设备标识符。
   * @param[out] value 配置值，0x00表示设备不处理616C，0x01表示设备处理616C。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_GetCpuCard616C(HANDLE icdev, unsigned char *value);

  /**
   * @brief  获取芯片唯一ID号。
   * @par    说明：
   * 获取芯片唯一ID号。
   * @param[in] icdev 设备标识符。
   * @param[out] number 返回的ID号字符串，请至少分配128个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_GetChipIdNumber(HANDLE icdev, char *number);

  /**
   * @brief  数码管显示。
   * @par    说明：
   * 数码管显示。
   * @param[in] icdev 设备标识符。
   * @param[in] number 数码管编号（1~12）。
   * @param[in] mode 模式，0x00表示数据正常显示，0x01表示数据闪烁显示，0x02表示数据不闪烁显示，0x03表示数据带小数点显示。
   * @param[in] value 显示数据值。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_LedDisplay(HANDLE icdev, unsigned char number, unsigned char mode, unsigned char value);

  /**
   * @brief  数码管显示设置。
   * @par    说明：
   * 数码管显示设置。
   * @param[in] icdev 设备标识符。
   * @param[in] mode 模式。
   * @n 0x00 - 左移。
   * @n 0x01 - 右移。
   * @n 0x02 - 左循环。
   * @n 0x03 - 右循环。
   * @n 0x04 - 显示清除。
   * @n 0x05 - 显示置位。
   * @n 0x06 - 显示亮度增加。
   * @n 0x07 - 显示亮度降低。
   * @n 0x08 - 开显示。
   * @n 0x09 - 关显示。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_LedControl(HANDLE icdev, unsigned char mode);

  /**
   * @brief  透传CRC模式配置。
   * @par    说明：
   * 透传CRC模式配置。
   * @param[in] icdev 设备标识符。
   * @param[in] tx_crc TXCRC模式，0x00表示内部不处理TXCRC，0x01表示内部处理TXCRC（只支持ISO14443标准卡）。
   * @param[in] rx_crc RXCRC模式，0x00表示内部不处理RXCRC，0x01表示内部处理RXCRC（只支持ISO14443标准卡）。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_RfCrcModeConfig(HANDLE icdev, unsigned char tx_crc, unsigned char rx_crc);

  /**
   * @brief  获取TCP信息。
   * @par    说明：
   * 获取TCP信息。
   * @param[in] icdev 设备标识符。
   * @param[in] type 类型，0x01表示请求获得模块型号，0x02表示请求获得当前信号强度。
   * @param[out] data_buffer 返回的数据。
   * @param[out] data_len 返回数据的长度。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_TcpGetInfo(HANDLE icdev, unsigned char type, unsigned char *data_buffer, int *data_len);

  /**
   * @brief  射频天线打开。
   * @par    说明：
   * 射频天线打开。
   * @param[in] icdev 设备标识符。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_RfMarch(HANDLE icdev);

  /**
   * @brief  选择天线。
   * @par    说明：
   * 选择天线。
   * @param[in] icdev 设备标识符。
   * @param[in] number 天线编号，从1开始编号。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_SelectAntenna(HANDLE icdev, unsigned char number);

  /**
   * @brief  读网卡MAC地址。
   * @par    说明：
   * 读网卡MAC地址。
   * @param[in] icdev 设备标识符。
   * @param[out] data_buffer 返回的网卡地址。
   * @param[out] data_len 返回网卡地址的长度。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_ReadNicMacAddress(HANDLE icdev, unsigned char *data_buffer, int *data_len);

  /**
   * @brief  写网卡MAC地址。
   * @par    说明：
   * 写网卡MAC地址。
   * @param[in] icdev 设备标识符。
   * @param[in] data_buffer 传入网卡地址。
   * @param[in] data_len 传入网卡地址的长度。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_WriteNicMacAddress(HANDLE icdev, const unsigned char *data_buffer, int data_len);

  /**
   * @brief  测试网卡。
   * @par    说明：
   * 测试网卡。
   * @param[in] icdev 设备标识符。
   * @param[in] data_buffer 传入IP地址。
   * @param[in] data_len 传入IP地址的长度。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_TestNic(HANDLE icdev, const unsigned char *data_buffer, int data_len);

  /**
   * @brief  测试USB。
   * @par    说明：
   * 测试USB。
   * @param[in] icdev 设备标识符。
   * @param[in] data_buffer 保留。
   * @param[in] data_len 保留，固定为0。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_TestUsb(HANDLE icdev, const unsigned char *data_buffer, int data_len);

  /**
   * @brief  测试串口。
   * @par    说明：
   * 测试串口。
   * @param[in] icdev 设备标识符。
   * @param[in] number 串口编号（1~3）。
   * @param[in] name 主机串口名称，如："COM1:115200"。
   * @param[in,out] data_buffer 通讯数据。
   * @param[in,out] data_len 通讯数据的长度。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_TestCom(HANDLE icdev, unsigned char number, const char *name, unsigned char *data_buffer, int *data_len);

  /**
   * @brief  设定临时IP地址。
   * @par    说明：
   * 设定临时IP地址。
   * @param[in] icdev 设备标识符。
   * @param[in] data_buffer 传入IP地址。
   * @param[in] data_len 传入IP地址的长度。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_ConfigTempIpAddress(HANDLE icdev, const unsigned char *data_buffer, int data_len);

  /**
   * @brief  磁条卡数据自动上传数据模式获取。
   * @par    说明：
   * 获取磁条卡数据自动上传数据模式。
   * @param[in] icdev 设备标识符。
   * @param[out] mode 模式。
   * @n 0 - 输出数据中如果带字母，字母转化为大写字母。
   * @n 1 - 输出数据是原始数据（默认）。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_GetMagFormat(HANDLE icdev, int *mode);

  /**
   * @brief  磁条卡参数获取。
   * @par    说明：
   * 获取操作磁条卡的参数，参数仅针对自动输出的模式有效。
   * @param[in] icdev 设备标识符。
   * @param[out] mode 模式，0x00表示不用输出，0x01表示自动输出。
   * @param[out] track1 1轨道参数。
   * @n bit0 - 轨道数据输出设置，0表示不输出，1表示输出。
   * @n bit1 - 轨道数据头设置，0表示无数据头，1表示有数据头。
   * @n bit2 - 轨道数据尾设置，0表示无数据尾，1表示有数据尾。
   * @n bit3 - 轨道数据换行符设置，0表示无换行符，1表示有换行符。
   * @n bit4 - 轨道数据等号与其后数据设置，0表示不输出，1表示输出。
   * @n bit5~bit7 - 保留。
   * @param[out] track2 2轨道参数。
   * @n bit0 - 轨道数据输出设置，0表示不输出，1表示输出。
   * @n bit1 - 轨道数据头设置，0表示无数据头，1表示有数据头。
   * @n bit2 - 轨道数据尾设置，0表示无数据尾，1表示有数据尾。
   * @n bit3 - 轨道数据换行符设置，0表示无换行符，1表示有换行符。
   * @n bit4 - 轨道数据等号与其后数据设置，0表示不输出，1表示输出。
   * @n bit5~bit7 - 保留。
   * @param[out] track3 3轨道参数。
   * @n bit0 - 轨道数据输出设置，0表示不输出，1表示输出。
   * @n bit1 - 轨道数据头设置，0表示无数据头，1表示有数据头。
   * @n bit2 - 轨道数据尾设置，0表示无数据尾，1表示有数据尾。
   * @n bit3 - 轨道数据换行符设置，0表示无换行符，1表示有换行符。
   * @n bit4 - 轨道数据等号与其后数据设置，0表示不输出，1表示输出。
   * @n bit5~bit7 - 保留。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_GetMag(HANDLE icdev, unsigned char *mode, unsigned char *track1, unsigned char *track2, unsigned char *track3);

  /**
   * @brief  获取串口设备通讯波特率。
   * @par    说明：
   * 获取串口设备通讯波特率。
   * @param[in] icdev 设备标识符。
   * @param[out] baud 波特率。
   * @n 0x00 - 115200。
   * @n 0x01 - 57600。
   * @n 0x02 - 38400。
   * @n 0x03 - 19200。
   * @n 0x04 - 9600。
   * @n 0x05 - 4800。
   * @n 0x06 - 2400。
   * @n 0x07 - 1200。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_GetDeviceBaud(HANDLE icdev, unsigned char *baud);

  /**
   * @brief  获取USB模式。
   * @par    说明：
   * 获取USB通讯模式。
   * @param[in] icdev 设备标识符。
   * @param[out] ucmode 模式。
   * @n 0x00 - 表示中断发送和中断接收，此时VID=257B，PID=3010。
   * @n 0x01 - 表示控制发送和控制接收，此时VID=257B，PID=3011。
   * @n 0x02 - 表示控制发送和中断接收，此时VID=0471，PID=7002。
   * @n 0x03 - 表示控制发送和中断接收，此时VID=0471，PID=7003。
   * @n 0x04 - 表示控制发送和中断接收，此时VID=0471，PID=7003，支持磁条卡自动上传功能。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_GetUsbMode(HANDLE icdev, unsigned char *ucmode);

  /**
   * @brief  接触式CPU卡指令交互。
   * @par    说明：
   * 对当前卡座CPU卡进行指令交互操作，注意此接口已封装卡协议部分，内部处理了SW1为0x61和0x6C的情况。
   * @param[in] icdev 设备标识符。
   * @param[in] slen 发送数据的长度。
   * @param[in] sendbuffer 发送数据。
   * @param[out] rlen 返回数据的长度。
   * @param[out] databuffer 返回的数据。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_cpuapduresponInt(HANDLE icdev, unsigned int slen, unsigned char *sendbuffer, unsigned int *rlen, unsigned char *databuffer);

  /**
   * @brief  接触式CPU卡指令交互。
   * @par    说明：
   * ::dc_cpuapduresponInt 的HEX形式接口，参数 @a sendbuffer @a databuffer 为HEX格式。
   */
  short USER_API dc_cpuapduresponInt_hex(HANDLE icdev, unsigned int slen, char *sendbuffer, unsigned int *rlen, char *databuffer);

  /**
   * @brief  开始扫描二维码。
   * @par    说明：
   * 开始扫描二维码。
   * @param[in] icdev 设备标识符。
   * @param[in] mode 保留，固定为0x00。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_Scan2DBarcodeStart(HANDLE icdev, unsigned char mode);

  /**
   * @brief  获取二维码数据。
   * @par    说明：
   * 获取二维码数据。
   * @param[in] icdev 设备标识符。
   * @param[out] rlen 返回数据的长度。
   * @param[out] rdata 返回的数据。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_Scan2DBarcodeGetData(HANDLE icdev, int *rlen, unsigned char *rdata);

  /**
   * @brief  退出扫描二维码。
   * @par    说明：
   * 退出扫描二维码。
   * @param[in] icdev 设备标识符。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_Scan2DBarcodeExit(HANDLE icdev);

  /**
   * @brief  写磁条卡参数设置。
   * @par    说明：
   * 写磁条卡参数设置。
   * @param[in] icdev 设备标识符。
   * @param[in] mode 模式，0表示写三轨共移动三次，1表示写三轨共移动一次。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_SelfServiceDeviceWriteMagConfig(HANDLE icdev, unsigned char mode);

  /**
   * @brief  抖动模式设置。
   * @par    说明：
   * 抖动模式设置。
   * @param[in] icdev 设备标识符。
   * @param[in] mode 模式，0表示抖动模式，1表示非抖动模式。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_SelfServiceDeviceShakeConfig(HANDLE icdev, unsigned char mode);

  /**
   * @brief  语音播放及显示。
   * @par    说明：
   * 播放设备内置语音以及是否需要显示。
   * @param[in] icdev 设备标识符。
   * @param[in] mode 语音段号（0~8）。
   * @n 0 - 请输入密码。
   * @n 1 - 请输入原密码。
   * @n 2 - 请再输入一次。
   * @n 3 - 请输入新密码。
   * @n 4 - 请确认新密码。
   * @n 5 - 密码修改成功。
   * @n 6 - 请插卡。
   * @n 7 - 请刷卡。
   * @n 8 - 密码错误。
   * @param[in] type 显示类型，0表示显示语音播放内容，1表示不显示语音播放内容。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_VoicePlayAndDisplay(HANDLE icdev, unsigned char mode, unsigned char type);

  /**
   * @brief  前门电闸门设置。
   * @par    说明：
   * 前门电闸门设置。
   * @param[in] icdev 设备标识符。
   * @param[in] mode 模式，0表示存在前门电闸门，1表示不存在前门电闸门。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_SelfServiceDeviceSetFrontSwitch(HANDLE icdev, unsigned char mode);

  /**
   * @brief  前门电闸门获取。
   * @par    说明：
   * 前门电闸门获取。
   * @param[in] icdev 设备标识符。
   * @param[out] mode 模式，0表示存在前门电闸门，1表示不存在前门电闸门。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_SelfServiceDeviceGetFrontSwitch(HANDLE icdev, unsigned char *mode);

  /**
   * @brief  清除设备配置。
   * @par    说明：
   * 清除设备配置。
   * @param[in] icdev 设备标识符。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_ClearDeviceConfig(HANDLE icdev);

  /**
   * @brief  接触式CPU卡PPS配置设置。
   * @par    说明：
   * 接触式CPU卡PPS配置设置。
   * @param[in] icdev 设备标识符。
   * @param[in] mode 模式，0表示底层不支持PPS，1表示底层支持PPS。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_SetCpuCardPps(HANDLE icdev, unsigned char mode);

  /**
   * @brief  接触式CPU卡PPS配置获取。
   * @par    说明：
   * 接触式CPU卡PPS配置获取。
   * @param[in] icdev 设备标识符。
   * @param[out] mode 模式，0表示底层不支持PPS，1表示底层支持PPS。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_GetCpuCardPps(HANDLE icdev, unsigned char *mode);

  /**
   * @brief  保留。
   */
  short USER_API dc_checkcopy_m1(HANDLE icdev, unsigned char mode);

  /**
   * @brief  刷新返回主界面。
   * @par    说明：
   * 刷新返回主界面。
   * @param[in] icdev 设备标识符。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_RefreshAndDisplayMainUI(HANDLE icdev);

  /**
   * @brief  保留。
   */
  short USER_API dc_GlyProCommand(HANDLE icdev, unsigned int slen, unsigned char *sendbuffer, unsigned int *rlen, unsigned char *databuffer, unsigned char timeout);

  /**
   * @brief  保留。
   */
  short USER_API dc_GlyProCommand_hex(HANDLE icdev, unsigned int slen, char *sendbuffer, unsigned int *rlen, char *databuffer, unsigned char timeout);

  /**
   * @brief  读取SAM_A模块序列号。
   * @par    说明：
   * 读取SAM_A模块序列号。
   * @param[in] icdev 设备标识符。
   * @param[out] number 返回的序列号字符串，请至少分配64个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_SamAReadSerialNumber(HANDLE icdev, char *number);

  /**
   * @brief  2.4G APDU指令交互。
   * @par    说明：
   * 2.4G APDU指令交互。
   * @param[in] icdev 设备标识符。
   * @param[in] slen 发送数据的长度。
   * @param[in] sendbuffer 发送数据。
   * @param[out] rlen 返回数据的长度。
   * @param[out] databuffer 返回的数据。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_2dot4Apdu(HANDLE icdev, unsigned int slen, unsigned char *sendbuffer, unsigned int *rlen, unsigned char *databuffer);

  /**
   * @brief  2.4G APDU指令交互。
   * @par    说明：
   * ::dc_2dot4Apdu 的HEX形式接口，参数 @a sendbuffer @a databuffer 为HEX格式。
   */
  short USER_API dc_2dot4Apdu_hex(HANDLE icdev, unsigned int slen, char *sendbuffer, unsigned int *rlen, char *databuffer);

  /**
   * @brief  显示图像。
   * @par    说明：
   * 在屏幕上显示图像，这里的图像指的是前景图像。
   * @param[in] icdev 设备标识符。
   * @param[in] x 图像显示的起始X坐标。
   * @param[in] y 图像显示的起始Y坐标。
   * @param[in] w 图像显示的宽度。
   * @param[in] h 图像显示的高度。
   * @param[in] time_s 显示时间，单位为秒，0表示一直显示。
   * @param[in] image_data 图像数据。格式为：【4个字节图像信息长度（Big-Endian）】【图像信息】。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_ScreenDisplayImage(HANDLE icdev, int x, int y, int w, int h, int time_s, const unsigned char *image_data);

  /**
   * @brief  清除显示。
   * @par    说明：
   * 清除屏幕上的显示，这里清除的显示为前景。
   * @param[in] icdev 设备标识符。
   * @param[in] x 清除显示的起始X坐标。
   * @param[in] y 清除显示的起始Y坐标。
   * @param[in] w 清除显示的宽度。
   * @param[in] h 清除显示的高度。
   * @param[in] time_s 延时清除时间，单位为秒，0表示立即清除。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_ScreenClearDisplay(HANDLE icdev, int x, int y, int w, int h, int time_s);

  /**
   * @brief  装载背景图像。
   * @par    说明：
   * 装载背景图像到设备内部。
   * @param[in] icdev 设备标识符。
   * @param[in] number 图像序号，从1开始编号。
   * @param[in] image_data 图像数据。格式为：【4个字节图像信息长度（Big-Endian）】【图像信息】。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_ScreenLoadBgImage(HANDLE icdev, int number, const unsigned char *image_data);

  /**
   * @brief  显示背景图像。
   * @par    说明：
   * 显示设备内部装载的背景图像。
   * @param[in] icdev 设备标识符。
   * @param[in] number 图像序号，从1开始编号。
   * @param[in] x 图像显示的起始X坐标。
   * @param[in] y 图像显示的起始Y坐标。
   * @param[in] w 图像显示的宽度。
   * @param[in] h 图像显示的高度。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_ScreenDisplayBgImage(HANDLE icdev, int number, int x, int y, int w, int h);

  /**
   * @brief  获取显示配置。
   * @par    说明：
   * 获取显示配置。
   * @param[in] icdev 设备标识符。
   * @param[in] tag 标签。
   * @n 0x01 - 熄屏时间，配置信息长度固定为4个字节，单位为秒（Big-Endian）。如：config_data = {0x04,0x00,0x00,0x00,0x10}表示熄屏时间为16秒。
   * @n 0x02 - 显示分辨率，配置信息长度固定为4个字节，前2个字节为水平分辨率（Big-Endian），后2个字节为垂直分辨率（Big-Endian）。如：config_data = {0x04,0x02,0x80,0x01,0xE0}表示分辨率为640x480。
   * @param[out] config_data 配置数据。格式为：【1字节配置信息长度】【配置信息】。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_ScreenDisplayGetConfig(HANDLE icdev, unsigned char tag, unsigned char *config_data);

  /**
   * @brief  设置显示配置。
   * @par    说明：
   * 设置显示配置。
   * @param[in] icdev 设备标识符。
   * @param[in] tag 标签。
   * @n 0x01 - 熄屏时间，配置信息长度固定为4个字节，单位为秒（Big-Endian）。如：config_data = {0x04,0x00,0x00,0x00,0x10}表示熄屏时间为16秒。
   * @n 0x02 - 显示分辨率，配置信息长度固定为4个字节，前2个字节为水平分辨率（Big-Endian），后2个字节为垂直分辨率（Big-Endian）。如：config_data = {0x04,0x02,0x80,0x01,0xE0}表示分辨率为640x480。
   * @param[in] config_data 配置数据。格式为：【1字节配置信息长度】【配置信息】。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_ScreenDisplaySetConfig(HANDLE icdev, unsigned char tag, const unsigned char *config_data);

  /**
   * @brief  显示文字。
   * @par    说明：
   * 在屏幕上显示文字，注意文字也属于前景。
   * @param[in] icdev 设备标识符。
   * @param[in] font_size 字体大小。
   * @param[in] fg_rgb 文字前景色，3个字节RGB值，第一个字节为R，第二个字节为G，第三个字节为B。
   * @param[in] bg_rgb 文字背景色，3个字节RGB值，第一个字节为R，第二个字节为G，第三个字节为B。
   * @param[in] x 文字显示的起始X坐标。
   * @param[in] y 文字显示的起始Y坐标。
   * @param[in] time_s 显示时间，单位为秒，0表示一直显示。
   * @param[in] line_flag 换行标志，0表示不自动换行，1表示自动换行。
   * @param[in] voice_flag 语音标志，0表示不播放语音，1表示播放语音。
   * @param[in] text 文本字符串。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_ScreenDisplayText(HANDLE icdev, unsigned char font_size, const unsigned char *fg_rgb, const unsigned char *bg_rgb, int x, int y, int time_s, unsigned char line_flag, unsigned char voice_flag, const char *text);

  /**
   * @brief  填充背景。
   * @par    说明：
   * 使用指定颜色填充背景。
   * @param[in] icdev 设备标识符。
   * @param[in] rgb 颜色，3个字节RGB值，第一个字节为R，第二个字节为G，第三个字节为B。
   * @param[in] x 起始X坐标。
   * @param[in] y 起始Y坐标。
   * @param[in] w 宽度。
   * @param[in] h 高度。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_ScreenDisplayBgImageByColor(HANDLE icdev, const unsigned char *rgb, int x, int y, int w, int h);

  /**
   * @brief  NTAG标签交互。
   * @par    说明：
   * NTAG标签交互。
   * @param[in] icdev 设备标识符。
   * @param[in] type 保留，固定为0x00。
   * @param[in] mode 模式。
   * @param[in] slen 发送数据的长度。
   * @param[in] sdata 发送数据。
   * @param[out] rlen 返回数据的长度。
   * @param[out] rdata 返回的数据。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_NtagCommand(HANDLE icdev, unsigned char type, unsigned char mode, unsigned int slen, const unsigned char *sdata, unsigned int *rlen, unsigned char *rdata);

  /**
   * @brief  设置接触式CPU卡电压。
   * @par    说明：
   * 设置接触式CPU卡电压。
   * @param[in] icdev 设备标识符。
   * @param[in] voltage 电压值，0x00表示5V，0x01表示3.3V，0x02表示1.8V。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_SetCpuVoltage(HANDLE icdev, unsigned char voltage);

  /**
   * @brief  LCD显示文字。
   * @par    说明：
   * 在设备LCD显示屏上显示文字。
   * @param[in] icdev 设备标识符。
   * @param[in] line 行号。
   * @param[in] offset 偏移。
   * @param[in] mode 模式，0表示正色，1表示反色。
   * @param[in] charset 字符集。
   * @n 0 - ASCII。
   * @n 1 - GB2312。
   * @n 2 - GBK。
   * @n 3 - GB18030。
   * @n 4 - ANSI。
   * @n 5 - UNICODE（Little-Endian）。
   * @n 6 - UNICODE（Big-Endian）。
   * @param[in] text 文本字符串。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_LcdDisplayText(HANDLE icdev, unsigned char line, unsigned char offset, unsigned char mode, unsigned char charset, const unsigned char *text);

  /**
   * @brief  装载文件数据。
   * @par    说明：
   * 装载文件数据到设备中。
   * @param[in] icdev 设备标识符。
   * @param[in] file_type 文件类型。
   * @param[in] file_size 文件大小。
   * @param[in] flag 传输标志。
   * @n 0 - 准备传输。
   * @n 1~0xFFFFFFFE - 非结尾传输。
   * @n 0xFFFFFFFF - 结尾传输。
   * @param[in] data 数据，当 @a flag 不为0时有效。
   * @param[in,out] data_size 数据大小。
   * @n flag为0 - data_size为Out形式的参数，返回设备支持的最大分包长度。
   * @n flag不为0 - data_size为In形式的参数，传入 @a data 的长度。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_DownloadFileData(HANDLE icdev, unsigned int file_type, unsigned int file_size, unsigned int flag, const unsigned char *data, unsigned int *data_size);

  /**
   * @brief  检测1608卡。
   * @par    说明：
   * 检测是否存在1608卡。
   * @param[in] icdev 设备标识符。
   * @return <0表示失败或不存在，==0表示存在。
   */
  short USER_API dc_check_1608(HANDLE icdev);

  /**
   * @brief  1608卡下电。
   * @par    说明：
   * 对1608卡进行下电操作。
   * @param[in] icdev 设备标识符。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_down_1608(HANDLE icdev);

  /**
   * @brief  读1608卡。
   * @par    说明：
   * 读取1608卡的数据。
   * @param[in] icdev 设备标识符。
   * @param[in] zone 数据区。
   * @n 0~7 - 表示用户区。
   * @n 8 - 表示配置区。
   * @param[in] offset 偏移。
   * @param[in] length 读取长度。
   * @param[out] readdata 返回的数据。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_read_1608(HANDLE icdev, unsigned char zone, unsigned int offset, unsigned int length, unsigned char *readdata);

  /**
   * @brief  读1608卡。
   * @par    说明：
   * ::dc_read_1608 的HEX形式接口，参数 @a readdata 为HEX格式。
   */
  short USER_API dc_read_1608_hex(HANDLE icdev, unsigned char zone, unsigned int offset, unsigned int length, unsigned char *readdata);

  /**
   * @brief  写1608卡。
   * @par    说明：
   * 写入数据到1608卡中。
   * @param[in] icdev 设备标识符。
   * @param[in] zone 数据区。
   * @n 0~7 - 表示用户区。
   * @n 8 - 表示配置区。
   * @param[in] offset 偏移。
   * @param[in] length 写入长度。
   * @param[in] writedata 传入数据。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_write_1608(HANDLE icdev, unsigned char zone, unsigned int offset, unsigned int length, unsigned char *writedata);

  /**
   * @brief  写1608卡。
   * @par    说明：
   * ::dc_write_1608 的HEX形式接口，参数 @a writedata 为HEX格式。
   */
  short USER_API dc_write_1608_hex(HANDLE icdev, unsigned char zone, unsigned int offset, unsigned int length, unsigned char *writedata);

  /**
   * @brief  验证1608卡密码。
   * @par    说明：
   * 使用传入的密码来验证1608卡密码。
   * @param[in] icdev 设备标识符。
   * @param[in] zone 数据区。
   * @n 0~7 - 表示用户区。
   * @n 8 - 表示配置区。
   * @param[in] type 类型，0表示验证写密钥，1表示验证读密钥。
   * @param[in] password 密码，固定为3个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_checkpass_1608(HANDLE icdev, unsigned char zone, unsigned char type, unsigned char *password);

  /**
   * @brief  验证1608卡密码。
   * @par    说明：
   * ::dc_checkpass_1608 的HEX形式接口，参数 @a password 为HEX格式。
   */
  short USER_API dc_checkpass_1608_hex(HANDLE icdev, unsigned char zone, unsigned char type, unsigned char *password);

  /**
   * @brief  初始化1608卡认证。
   * @par    说明：
   * 使用传入的数据来初始化1608卡认证。
   * @param[in] icdev 设备标识符。
   * @param[in] databuffer 数据，固定为8个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_init_auth_1608(HANDLE icdev, unsigned char *databuffer);

  /**
   * @brief  初始化1608卡认证。
   * @par    说明：
   * ::dc_init_auth_1608 的HEX形式接口，参数 @a databuffer 为HEX格式。
   */
  short USER_API dc_init_auth_1608_hex(HANDLE icdev, unsigned char *databuffer);

  /**
   * @brief  核对1608卡认证。
   * @par    说明：
   * 使用传入的数据来核对1608卡认证。
   * @param[in] icdev 设备标识符。
   * @param[in] databuffer 数据，固定为8个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_check_auth_1608(HANDLE icdev, unsigned char *databuffer);

  /**
   * @brief  核对1608卡认证。
   * @par    说明：
   * ::dc_check_auth_1608 的HEX形式接口，参数 @a databuffer 为HEX格式。
   */
  short USER_API dc_check_auth_1608_hex(HANDLE icdev, unsigned char *databuffer);

  /**
   * @brief  写1608卡熔丝。
   * @par    说明：
   * 写1608卡熔丝。
   * @param[in] icdev 设备标识符。
   * @param[in] value 保留，固定为0x00。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_write_fuse_1608(HANDLE icdev, unsigned char value);

  /**
   * @brief  读1608卡熔丝。
   * @par    说明：
   * 读1608卡熔丝。
   * @param[in] icdev 设备标识符。
   * @param[out] value 状态值。
   * @n bit0 - FAB，Atmel公司发行熔丝，0表示已熔丝，1表示未熔丝。
   * @n bit1 - CMA，卡发行商发行熔丝，0表示已熔丝，1表示未熔丝。
   * @n bit2 - PER，个人化发行熔丝，0表示已熔丝，1表示未熔丝。
   * @n bit3~bit7 - 保留。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_read_fuse_1608(HANDLE icdev, unsigned char *value);

  /**
   * @brief  检测153卡。
   * @par    说明：
   * 检测是否存在153卡。
   * @param[in] icdev 设备标识符。
   * @return <0表示失败或不存在，==0表示存在。
   */
  short USER_API dc_check_153(HANDLE icdev);

  /**
   * @brief  153卡下电。
   * @par    说明：
   * 对153卡进行下电操作。
   * @param[in] icdev 设备标识符。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_down_153(HANDLE icdev);

  /**
   * @brief  读153卡。
   * @par    说明：
   * 读取153卡的数据。
   * @param[in] icdev 设备标识符。
   * @param[in] zone 数据区。
   * @n 0~2 - 表示用户区。
   * @n 3 - 表示配置区。
   * @param[in] offset 偏移。
   * @param[in] length 读取长度。
   * @param[out] readdata 返回的数据。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_read_153(HANDLE icdev, unsigned char zone, unsigned int offset, unsigned int length, unsigned char *readdata);

  /**
   * @brief  读153卡。
   * @par    说明：
   * ::dc_read_153 的HEX形式接口，参数 @a readdata 为HEX格式。
   */
  short USER_API dc_read_153_hex(HANDLE icdev, unsigned char zone, unsigned int offset, unsigned int length, unsigned char *readdata);

  /**
   * @brief  写153卡。
   * @par    说明：
   * 写入数据到153卡中。
   * @param[in] icdev 设备标识符。
   * @param[in] zone 数据区。
   * @n 0~2 - 表示用户区。
   * @n 3 - 表示配置区。
   * @param[in] offset 偏移。
   * @param[in] length 写入长度。
   * @param[in] writedata 传入数据。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_write_153(HANDLE icdev, unsigned char zone, unsigned int offset, unsigned int length, unsigned char *writedata);

  /**
   * @brief  写153卡。
   * @par    说明：
   * ::dc_write_153 的HEX形式接口，参数 @a writedata 为HEX格式。
   */
  short USER_API dc_write_153_hex(HANDLE icdev, unsigned char zone, unsigned int offset, unsigned int length, unsigned char *writedata);

  /**
   * @brief  验证153卡密码。
   * @par    说明：
   * 使用传入的密码来验证153卡密码。
   * @param[in] icdev 设备标识符。
   * @param[in] zone 数据区。
   * @n 0~2 - 表示用户区。
   * @n 3 - 表示配置区。
   * @param[in] type 类型，0表示验证写密钥，1表示验证读密钥。
   * @param[in] password 密码，固定为3个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_checkpass_153(HANDLE icdev, unsigned char zone, unsigned char type, unsigned char *password);

  /**
   * @brief  验证153卡密码。
   * @par    说明：
   * ::dc_checkpass_153 的HEX形式接口，参数 @a password 为HEX格式。
   */
  short USER_API dc_checkpass_153_hex(HANDLE icdev, unsigned char zone, unsigned char type, unsigned char *password);

  /**
   * @brief  初始化153卡认证。
   * @par    说明：
   * 使用传入的数据来初始化153卡认证。
   * @param[in] icdev 设备标识符。
   * @param[in] databuffer 数据，固定为8个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_init_auth_153(HANDLE icdev, unsigned char *databuffer);

  /**
   * @brief  初始化153卡认证。
   * @par    说明：
   * ::dc_init_auth_153 的HEX形式接口，参数 @a databuffer 为HEX格式。
   */
  short USER_API dc_init_auth_153_hex(HANDLE icdev, unsigned char *databuffer);

  /**
   * @brief  核对153卡认证。
   * @par    说明：
   * 使用传入的数据来核对153卡认证。
   * @param[in] icdev 设备标识符。
   * @param[in] databuffer 数据，固定为8个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_check_auth_153(HANDLE icdev, unsigned char *databuffer);

  /**
   * @brief  核对153卡认证。
   * @par    说明：
   * ::dc_check_auth_153 的HEX形式接口，参数 @a databuffer 为HEX格式。
   */
  short USER_API dc_check_auth_153_hex(HANDLE icdev, unsigned char *databuffer);

  /**
   * @brief  写153卡熔丝。
   * @par    说明：
   * 写153卡熔丝。
   * @param[in] icdev 设备标识符。
   * @param[in] value 保留，固定为0x00。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_write_fuse_153(HANDLE icdev, unsigned char value);

  /**
   * @brief  读153卡熔丝。
   * @par    说明：
   * 读153卡熔丝。
   * @param[in] icdev 设备标识符。
   * @param[out] value 状态值。
   * @n bit0 - FAB，Atmel公司发行熔丝，0表示已熔丝，1表示未熔丝。
   * @n bit1 - CMA，卡发行商发行熔丝，0表示已熔丝，1表示未熔丝。
   * @n bit2 - PER，个人化发行熔丝，0表示已熔丝，1表示未熔丝。
   * @n bit3~bit7 - 保留。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_read_fuse_153(HANDLE icdev, unsigned char *value);

  /**
   * @brief  多天线启动或停止。
   * @par    说明：
   * 多天线启动或停止。
   * @param[in] icdev 设备标识符。
   * @param[in] flag 标记，0表示停止，1表示启动。
   * @param[in,out] mask 掩码值，32bit分别表示32路天线，相应bit位为1表示天线有效，传入为期待值，返回为实际值。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_MultiAntennaStartOrStop(HANDLE icdev, unsigned char flag, unsigned int *mask);

  /**
   * @brief  多天线获取卡状态。
   * @par    说明：
   * 多天线获取卡状态。
   * @param[in] icdev 设备标识符。
   * @param[out] rlen 返回数据的长度。
   * @param[out] rdata 返回的数据。
   * @n 0x00 - 无卡。
   * @n 0x8A - 有卡，Type A CPU卡。
   * @n 0x8B - 有卡，Type B CPU卡。
   * @n 0x80 - 有卡，未知卡型。
   * @n 0x81 - 有卡，M1卡。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_MultiAntennaGetCardStatus(HANDLE icdev, int *rlen, unsigned char *rdata);

  /**
   * @brief  获取银行卡帐户号码。
   * @par    说明：
   * 获取银行卡帐户号码。
   * @param[in] icdev 设备标识符。
   * @param[in] type 类型，0表示非接触式，1表示接触式。
   * @param[out] number 返回的银行卡帐户号码字符串，请至少分配64个字节。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_GetBankAccountNumber(HANDLE icdev, int type, char *number);

  /**
   * @brief  生成身份证正面和背面图像。
   * @par    说明：
   * 生成身份证正面和背面图像。
   * @param[in] icdev 设备标识符。
   * @param[in] type 类型，0表示中国人居民身份证，1表示外国人永久居留证。
   * @param[in] text_len 文字信息的长度。
   * @param[in] text 文字信息。
   * @param[in] photo_len 相片信息的长度。
   * @param[in] photo 相片信息。
   * @param[in] front_file 传入正面图像文件名，请确保有写入的权限。
   * @param[in] back_file 传入背面图像文件名，请确保有写入的权限。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_IdCardImageBuild(HANDLE icdev, int type, int text_len, const unsigned char *text, int photo_len, const unsigned char *photo, const char *front_file, const char *back_file);

  /**
   * @brief  摄像视觉库加载。
   * @par    说明：
   * 摄像视觉库加载。
   * @param[in] icdev 设备标识符。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_CvLibLoad(HANDLE icdev);

  /**
   * @brief  摄像视觉库卸载。
   * @par    说明：
   * 摄像视觉库卸载。
   * @param[in] icdev 设备标识符。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_CvLibUnload(HANDLE icdev);

  /**
   * @brief  开启摄像头。
   * @par    说明：
   * 开启指定的摄像头。
   * @param[in] icdev 设备标识符。
   * @param[in] number 摄像头编号。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_CvOpen(HANDLE icdev, int number);

  /**
   * @brief  关闭摄像头。
   * @par    说明：
   * 关闭指定的摄像头。
   * @param[in] icdev 设备标识符。
   * @param[in] number 摄像头编号。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_CvClose(HANDLE icdev, int number);

  /**
   * @brief  拍照。
   * @par    说明：
   * 使用指定的摄像头进行拍照。
   * @param[in] icdev 设备标识符。
   * @param[in] number 摄像头编号。
   * @param[in] mode 模式。
   * @param[in] file_name 文件名，请确保有写入的权限。
   * @return <0表示失败，==0表示成功。
   */
  short USER_API dc_CvCapture(HANDLE icdev, int number, int mode, const char *file_name);

#ifdef __cplusplus
}
#endif

#endif // DCRF32_H_

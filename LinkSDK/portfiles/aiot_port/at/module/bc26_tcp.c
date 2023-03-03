#include "aiot_at_api.h"
#include <stdio.h>

/* 模块初始化命令表 */
static core_at_cmd_item_t at_ip_init_cmd_table[] = {
    {	/* UART通道测试 */
		.cmd = "AT\r\n",
		.cmd_len = sizeof("AT\r\n") - 1,
		.rsp = "OK",
		.handler = NULL,
	},
    {	/* 获取通信模块 IMEI 号 */
		.cmd = "AT+CGSN\r\n",
		.cmd_len = sizeof("AT+CGSN\r\n") - 1,
		.rsp = "OK",
		.handler = NULL,
	},
	{	/* 获取模组固件版本号 */
		.cmd = "AT+CGMR\r\n",
		.cmd_len = sizeof("AT+CGMR\r\n") - 1,
		.rsp = "OK",
		.handler = NULL,
	},
	{	/* 检查SIM卡 */
		.cmd = "AT+CPIN?\r\n",
		.cmd_len = sizeof("AT+CPIN?\r\n") - 1,
		.rsp = "READY",
		.handler = NULL,
	},
	{	/* 查询网 */
		.cmd = "AT+CEREG?\r\n",
		.cmd_len = sizeof("AT+CEREG?\r\n") - 1,
		.rsp = "0,1",
		.handler = NULL,
	},
    {	/* 查询本地IP地址 */
		.cmd = "AT+CGPADDR\r\n",
		.cmd_len = sizeof("AT+CGPADDR\r\n") - 1,
		.rsp = ".",
		.handler = NULL,
	},
};

/* TCP建立连接AT命令表 */
static core_at_cmd_item_t at_connect_cmd_table[] = {
    {   /* 建立TCP连接 */
        .fmt = "AT+QIOPEN=0,%d,\"TCP\",\"%s\",%d\r\n",
        .rsp = "+QIOPEN",
    },
};

static core_at_cmd_item_t at_send_cmd_table[] = {
    {
        .fmt = "AT+CIPSEND=%d,%d\r\n",
        .rsp = ">",    /* 收到`>`字符后做短延时处理, N720模组要求 */
    },
    {
        /*.fmt 为纯数据，没有格式*/
        .rsp = "DATA ACCEPT",
    },
};

/* TCP关闭连接AT命令表 */
static core_at_cmd_item_t at_disconn_cmd_table[] = {
    {   /* 建立TCP连接 */
        .fmt = "AT+CIPCLOSE=%d\r\n",
        .rsp = "CLOSE OK",
    }
};
static core_at_recv_data_prefix at_recv = {
    .prefix = "+RECEIVE",
    .fmt = "+RECEIVE,%d,%d:\r\n",
};

at_device_t air724_at_cmd = {
    .ip_init_cmd = at_ip_init_cmd_table,
    .ip_init_cmd_size = sizeof(at_ip_init_cmd_table) / sizeof(core_at_cmd_item_t),

    .open_cmd = at_connect_cmd_table,
    .open_cmd_size = sizeof(at_connect_cmd_table) / sizeof(core_at_cmd_item_t),

    .send_cmd = at_send_cmd_table,
    .send_cmd_size = sizeof(at_send_cmd_table) / sizeof(core_at_cmd_item_t),

    .close_cmd = at_disconn_cmd_table,
    .close_cmd_size = sizeof(at_disconn_cmd_table) / sizeof(core_at_cmd_item_t),

    .recv = &at_recv,
    .error_prefix = "ERROR",
};

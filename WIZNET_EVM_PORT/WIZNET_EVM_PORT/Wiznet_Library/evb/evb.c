 /*
 * (c)COPYRIGHT
 * ALL RIGHT RESERVED
 *
 * FileName : main.c
 * Brief : source codes for WIZ-Embedded WebServer A.K
 * This code is optimized at AVR-GCC 4.3.3(20090313).
 */
#include <stdio.h> 
#include <string.h>
#include "../Wiznet_Library/mcu/types.h"
#include "../Wiznet_Library/mcu/serial.h"
#include "../Wiznet_Library/evb/lcd.h"
#include "../Wiznet_Library/evb/evb.h"
#include "../Wiznet_Library/iinchip/socket.h"
#include "../Wiznet_Library/evb/romfile.h"
#include "../Wiznet_Library/evb/lcd.h"
#include "../Wiznet_Library/inet/httpd.h"
#include "../Wiznet_Library/evb/config.h"
#include "../Wiznet_Library/util/sockutil.h"
#include "C:\Users\kolel\Documents\Atmel Studio\7.0\AVR_Projects\WIZNET_EVM_PORT\WIZNET_EVM_PORT\task_config.h"
#include "C:\Users\kolel\Documents\Atmel Studio\7.0\AVR_Projects\WIZNET_EVM_PORT\WIZNET_EVM_PORT\dhcp_task.h"
//-----------------------------------------------------------------------------

//#define  WEB_DEBUG

#define MY_NET_MAC			{0x00, 0x08, 0xdc, 0x00, 0x00, 0x00}	// MY Mac Address : 00.08.DC.00.00.00

#define MY_NET_GWIP			{192,  168, 0,  1}	// MY Gateway IP    : 192.168.0.1
#define MY_DESTINATIONIP	{192,  168, 0,  2}	// MY Destination   : 192.168.0.2
#define MY_SOURCEIP			{192,  168, 1,  3}	// MY Source IP     : 192.168.0.3
#define MY_SUBNET			{255, 255, 255,   0}

#define MY_NET_MEMALLOC		0x55					// MY iinchip memory allocation

#define MY_LISTEN_PORT		5000					// MY Listen Port  : 5000 
#define MY_CONNECT_PORT		3000					// MY Connect Port : 3000

#define SOCK_TCPC			0
#define SOCK_TCPS			1


#define DEFAULT_HTTP_PORT			80
//-----------------------------------------------------------------------------

#define EVB_NET_SIP	"$SRC_IP_ADDRES$"
#define EVB_NET_GWIP	"$GW_IP_ADDRESS$"
#define EVB_NET_SN	"$SUB_NET__MASK$"
#define EVB_NET_DNS	"$DNS_SERVER_IP$"
#define EVB_NET_MAC	"$SRC_MAC_ADDRESS$"

#define EVB_LCD_TEXT 	"$LCD_TEXT_VALUE$"
#define EVB_LED0_IMG	"$LED0_IMG$"
#define EVB_LED1_IMG	"$LED1_IMG$"
#define EVB_LED2_IMG	"$LED2_IMG$"
#define EVB_LED3_IMG	"$LED3_IMG$"
#define EVB_LED0_STAT	"$LED_0$"
#define EVB_LED1_STAT	"$LED_1$"
#define EVB_LED2_STAT	"$LED_2$"
#define EVB_LED3_STAT	"$LED_3$"


void evb_lcd_logo(void);
void RomFileTest(void);
void ProcessWebSever(u_char ch);
static u_int replace_sys_env_value(u_char* base, u_int len);

static u_char* http_response;		/**< Pointer to HTTP response */
static st_http_request *http_request;	/**< Pointer to HTTP request */
extern StrConfigParam NetworkParam, MSGConfig;

unsigned char bchannel_start;

unsigned char m_FlagWrite = 0;
unsigned char m_FlagFlashWrite = 0;

unsigned long m_FileSize = 0;
unsigned long m_FileWriteCount = 0;

//  
//-----------------------------------------------------------------------------
void NetInit(void)
{
	volatile unsigned long dd = 100000;
  /* 
	unsigned char mac[6]	= MY_NET_MAC;
	unsigned char sm[4]	= MY_SUBNET;
	unsigned char gwip[4]	= MY_NET_GWIP;
	unsigned char m_sip[4]	= MY_SOURCEIP;
*/
	unsigned char tx_mem_conf[8] = {8,8,8,8,8,8,8,8};          // for setting TMSR regsiter
//	unsigned char rx_mem_conf[8] = {8,8,8,8,8,8,8,8};          // for setting RMSR regsiter
	
	//W5300 Chip Init
	iinchip_init();

	while(dd--);
	/*
	//Set MAC Address
	setSHAR(mac);

	//Set Gateway
	setGAR(gwip);

	//Set Subnet Mask
	setSUBR(sm);

	//Set My IP
	setSIPR(m_sip);*/
	

#ifdef __DEF_IINCHIP_INT__
	setIMR(0xEF);
#endif
	
	//sysinit(MY_NET_MEMALLOC, MY_NET_MEMALLOC);

   /* allocate internal TX/RX Memory of W5300 */
   if(!sysinit(tx_mem_conf, tx_mem_conf))           
   {
  //    printf("MEMORY CONFIG ERR.\r\n");
      while(1);
   }	
}
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------

/**
 @brief	Analyse HTTP request and then services WEB.
*/

/**
 @brief	Replace HTML's variables to system configuration value
*/

void mcu_init(void)
{
	
}

void evb_init(void)
{
	
}

void led_init(void)
{
	
}
void led_toggle(u_char led)
{
	
}
void led_off(u_char led)
{
	
}
void led_on(u_char led)
{
	
}
u_char led_state(u_char led)
{
	
}

void evb_set_lcd_text(u_char row, u_char* lcd)
{
	
}
u_char* evb_get_lcd_text(u_char row)
{
	
}

void sw_init(void)
{
	
}
u_char sw_state(unsigned char num)
{
	
}

void AdcInit(void)
{
	
}
unsigned int AdcRead(unsigned char Channel)
{
	
}
void evb_soft_reset(void)
{
	
}


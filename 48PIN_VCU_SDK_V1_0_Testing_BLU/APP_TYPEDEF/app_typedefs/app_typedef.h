/***************************************************************************************************
 *    FILENAME    : app_typedefs.h
 *
 *    DESCRIPTION : File declares type definitions for Diagnostic stacks. 
 *
 *    $Id         : $    
 *
 ***************************************************************************************************
 * Revision history
 * 
 * Ver Author       Date        Description
 * 1   Sloki             25/09/2017
 ***************************************************************************************************
*/

#ifndef _APP_TYPEDEFS_H_
#define _APP_TYPEDEFS_H_
/************************** PRE-PROCESSOR DIRECTIVES *************************/

#include <stdint.h>
#include <stdbool.h>
//#include "vcu_conf.h"
#include"r_cg_macrodriver.h"


#ifndef __TYPEDEF__
    typedef unsigned char         bool;
    typedef signed char           int8_t;
    typedef unsigned char         uint8_t;
    typedef signed short          int16_t;
    typedef unsigned short        uint16_t;
    typedef signed long           int32_t;
    typedef unsigned long         uint32_t;
    typedef signed long long      int64_t;
    typedef unsigned long long    uint64_t;
    typedef unsigned short        MD_STATUS;
    #define __TYPEDEF__
#endif

typedef		int8_t			SINT8;
typedef		uint8_t	        	UINT8;  
typedef		uint16_t	    	UINT16;
typedef		int16_t			SINT16;
typedef		uint32_t        	UINT32;
typedef		int32_t 		SINT32;
//typedef     	uint64_t        	UINT64;
typedef unsigned char         bool;
#define     BOOL            		UINT8 
typedef float              float32_t;
extern volatile UINT32 _1msTimer_u32;

#define GET_TIME_MS()       (_1msTimer_u32)
#define INC_TIME_MS()       (_1msTimer_u32++)
#define TIME_DIFF_MS(v)     ((UINT32) ((GET_TIME_MS()) - (v)))

#define ELEMENT_CNT(x)      (UINT32)(sizeof(x) / (sizeof(x[0])))

/**
* macros for converting time units in to ticks and vice versa
*/
#define MICRO_SECONDS_TO_TICKS(time_us) (/*TODO Sloki SYS_CLK_HAL_TICKS_IN_ONE_MICRO_SECOND*/ (80L) * (time_us) )
#define MILLI_SECONDS_TO_TICKS(time_ms) (/*TODO Sloki SYS_CLK_HAL_TICKS_IN_ONE_MICRO_SECOND*/ (80L) * (time_ms) * (1000L))

#define TICKS_TO_MICRO_SECONDS(ticks)   ((ticks) / /*TODO Sloki SYS_CLK_HAL_TICKS_IN_ONE_MICRO_SECOND*/ (80L) )
#define TICKS_TO_MILLI_SECONDS(ticks)   ((ticks) / /*TODO Sloki SYS_CLK_HAL_TICKS_IN_ONE_MICRO_SECOND*/ (80L)  * (1000L))

#define PARAM_NOTUSED(x) (x)=(x)

//#define 	NULL		0
#ifndef NULL
	#define NULL ((void *)0)
#endif /* NULL */

#define 	U1 			uint8_t
#define 	U2 			uint16_t
#define 	U3 			uint24_t
#define 	U4 			uint32_t
//#define     U6      	uint64_t
#define 	PASS		((U1)1)					/* OK	 						*/
#define 	FAIL		((U1)0)					/* NG	 						*/
#define 	ON 			1
#define 	OFF 		0
#define 	OK      	((U1)1)    /* OK          */

#ifndef INT8_MIN
#define INT8_MIN    			(-128)
#endif

#ifndef INT8_MAX
#define INT8_MAX    			(127)
#endif

#ifndef UINT8_MAX
#define UINT8_MAX   			(255)
#endif

#ifndef INT16_MIN
#define INT16_MIN   			(-32768)
#endif

#ifndef INT16_MAX
#define INT16_MAX   			(32767)
#endif

#ifndef uint16_t_MAX
#define uint16_t_MAX  			(65535)
#endif

#ifndef UINT24_MAX
#define UINT24_MAX 				(16777215)
#endif


#ifndef INT32_MIN
#define INT32_MIN   			(-2147483648)
#endif

#ifndef INT32_MAX
#define INT32_MAX   			(2147483647)
#endif

#ifndef uint32_t_MAX
#define uint32_t_MAX  			(4294967295)
#endif

#ifndef UINT64_MAX
#define UINT64_MAX  			(18446744073709551615l)
#endif

#pragma pack(1)
typedef union
{
    uint32_t  wrd_u32;

    struct
    {
        uint16_t h_u16;
        uint16_t l_u16;
    }hwd_St;

    struct
    {
        uint8_t hh_u8;
        uint8_t hl_u8;
        uint8_t lh_u8;
        uint8_t ll_u8;
    }byt_St;

}U32_St_t;

#pragma pack(1)
typedef union
{
    struct
    {
        uint8_t h_u8;
        uint8_t l_u8;
    }byt_St;
    uint16_t  hwd_u16;

}U16_St_t;



/**/

typedef unsigned long long  U6;

#define RESET               0x00
#define CLEAR               0X00
#define DEFAULT             0x00

#define TURN_ON             0x01
#define TURN_OFF            0x00

#define ENABLE             0x01
#define DISABLE            0x00

#define ACTIVATE            0X01
#define DEACTIVATE          0X02

#define true				0x01
#define false				0x00

#define TRUE                (0x01U)
#define FALSE               (0x00U)
#define SET                 (0x01U)

#define BIT0        ((U1)0x01)
#define BIT1        ((U1)0x02)
#define BIT2        ((U1)0x04)
#define BIT3        ((U1)0x08)
#define BIT4        ((U1)0x10)
#define BIT5        ((U1)0x20)
#define BIT6        ((U1)0x40)
#define BIT7        ((U1)0x80)
#define BIT_U1      ((U1)0xFF)              /* 1 byte in all                */

#define BIT00       ((U2)0x0001)
#define BIT01       ((U2)0x0002)
#define BIT02       ((U2)0x0004)
#define BIT03       ((U2)0x0008)
#define BIT04       ((U2)0x0010)
#define BIT05       ((U2)0x0020)
#define BIT06       ((U2)0x0040)
#define BIT07       ((U2)0x0080)
#define BIT08       ((U2)0x0100)
#define BIT09       ((U2)0x0200)
#define BIT10       ((U2)0x0400)
#define BIT11       ((U2)0x0800)
#define BIT12       ((U2)0x1000)
#define BIT13       ((U2)0x2000)
#define BIT14       ((U2)0x4000)
#define BIT15       ((U2)0x8000)
#define BIT16       ((U4)0x00010000)
#define BIT17       ((U4)0x00020000)
#define BIT18       ((U4)0x00040000)
#define BIT19       ((U4)0x00080000)
#define BIT20       ((U4)0x00100000)
#define BIT21       ((U4)0x00200000)
#define BIT22       ((U4)0x00400000)
#define BIT23       ((U4)0x00800000)
#define BIT24       ((U4)0x01000000)
#define BIT25       ((U4)0x02000000)
#define BIT26       ((U4)0x04000000)
#define BIT27       ((U4)0x08000000)
#define BIT28       ((U4)0x10000000)
#define BIT29       ((U4)0x20000000)
#define BIT30       ((U4)0x40000000)
#define BIT31       ((U4)0x80000000)

#define BIT_U2      ((U2)0xFFFF)            /* 2 bytes in all               */

#define BIT000      (0x00000001)
#define BIT001      (0x00000002)
#define BIT002      (0x00000004)
#define BIT003      (0x00000008)
#define BIT004      (0x00000010)
#define BIT005      (0x00000020)
#define BIT006      (0x00000040)
#define BIT007      (0x00000080)
#define BIT008      (0x00000100)
#define BIT009      (0x00000200)
#define BIT010      (0x00000400)
#define BIT011      (0x00000800)
#define BIT012      (0x00001000)
#define BIT013      (0x00002000)
#define BIT014      (0x00004000)
#define BIT015      (0x00008000)
#define BIT016      (0x00010000)
#define BIT017      (0x00020000)
#define BIT018      (0x00040000)
#define BIT019      (0x00080000)
#define BIT020      (0x00100000)
#define BIT021      (0x00200000)
#define BIT022      (0x00400000)
#define BIT023      (0x00800000)
#define BIT024      (0x01000000)
#define BIT025      (0x02000000)
#define BIT026      (0x04000000)
#define BIT027      (0x08000000)
#define BIT028      (0x10000000)
#define BIT029      (0x20000000)
#define BIT030      (0x40000000)
#define BIT031      (0x80000000)
#define BIT_U4      (0xFFFFFFFF)            /* 4���������S��                */


#define MASK_1BIT (0x01u)
#define MASK_2BIT (0x03u)
#define MASK_3BIT (0x07u)
#define MASK_4BIT (0x0Fu)
#define MASK_5BIT (0x1Fu)
#define MASK_6BIT (0x3Fu)
#define MASK_7BIT (0x7Fu)
#define MASK_8BIT (0xFFu)

#define SHIFT_1BIT   (0x01)
#define SHIFT_2BIT   (0x02)
#define SHIFT_3BIT   (0x03)
#define SHIFT_4BIT   (0x04)
#define SHIFT_5BIT   (0x05)
#define SHIFT_6BIT   (0x06)
#define SHIFT_7BIT   (0x07)
#define SHIFT_8BIT   (0x08)




// #define ZERO                (0U)
// #define ONE                 (1U)
// #define TWO                 (2U)
// #define THREE               (3U)
// #define FOUR                (4U)
// #define FIVE                (5U)
// #define SIX                 (6U)
// #define SEVEN               (7U)
// #define EIGHT               (8U)
// #define NINE                (9U)
// #define TEN                 (10U)
// #define FOURTY              (40U) 
#endif


#define on 1
#define off 0
#define OK ((U1)1) /* OK          */

#define _1000MS 1000
#define _2000MS 2000
#define _3000MS 3000
#define _4000MS 4000
#define _5000MS 5000
/* *****************************************************************************
 End of File
 */




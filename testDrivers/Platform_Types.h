/******************************************************************************
 *
 * Module: Common - Platform Abstraction
 *
 * File Name: Platform_Types.h
 *
 * Description: Platform types for ARM Cortex-M4F
 *
 * Author: Ziad Hisham
 *
 *******************************************************************************/

#ifndef PLATFORM_TYPES_H
#define PLATFORM_TYPES_H

/* Id for the company in the AUTOSAR
 * for example Ziad Hisham's ID = 1000 :) */
#define PLATFORM_VENDOR_ID (1000U)

/*
 * Module Version 1.0.0
 */
#define PLATFORM_SW_MAJOR_VERSION (1U)
#define PLATFORM_SW_MINOR_VERSION (0U)
#define PLATFORM_SW_PATCH_VERSION (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PLATFORM_AR_RELEASE_MAJOR_VERSION (4U)
#define PLATFORM_AR_RELEASE_MINOR_VERSION (0U)
#define PLATFORM_AR_RELEASE_PATCH_VERSION (3U)

/*
 * CPU register type width
 */
#define CPU_TYPE_8 (8U)
#define CPU_TYPE_16 (16U)
#define CPU_TYPE_32 (32U)

/*
 * Bit order definition
 */
#define MSB_FIRST (0u) /* Big endian bit ordering        */
#define LSB_FIRST (1u) /* Little endian bit ordering     */

/*
 * Byte order definition
 */
#define HIGH_BYTE_FIRST (0u) /* Big endian byte ordering       */
#define LOW_BYTE_FIRST (1u)  /* Little endian byte ordering    */

/*
 * Platform type and endianess definitions, specific for ARM Cortex-M4F
 */
#define CPU_TYPE CPU_TYPE_32

#define CPU_BIT_ORDER MSB_FIRST
#define CPU_BYTE_ORDER HIGH_BYTE_FIRST

/*
 * Boolean Values
 */
#define NULL ((void *)0)

#ifndef FALSE
#define FALSE (0u)
#endif
#ifndef TRUE
#define TRUE (1u)
#endif

typedef unsigned char boolean;

typedef unsigned char uint8;       /*           0 .. 255             */
typedef signed char sint8;         /*        -128 .. +127            */
typedef unsigned short uint16;     /*           0 .. 65535           */
typedef signed short sint16;       /*      -32768 .. +32767          */
typedef unsigned long uint32;      /*           0 .. 4294967295      */
typedef signed long sint32;        /* -2147483648 .. +2147483647     */
typedef unsigned long long uint64; /*       0..18446744073709551615  */
typedef signed long long sint64;   /* -9223372036854775808 .. 9223372036854775807 */
typedef float float32;
typedef double float64;

typedef volatile signed char vint8;
typedef volatile unsigned char vuint8;
typedef volatile signed short vint16;
typedef volatile unsigned short vuint16;
typedef volatile signed long vint32;
typedef volatile unsigned long vuint32;

/*
 *  Describes the standard Return Type Definitions used in the project
 */
typedef uint32 Std_ReturnType;

#define STD_HIGH ((Std_ReturnType)0x01U) /* Standard HIGH */
#define STD_LOW ((Std_ReturnType)0x00U)  /* Standard LOW */

#define STD_ACTIVE 0x01U /* Logical state active */
#define STD_IDLE 0x00U   /* Logical state idle */

#define STD_ON ((Std_ReturnType)0x01U)  /* Standard ON */
#define STD_OFF ((Std_ReturnType)0x00U) /* Standard OFF */

#define E_OK ((Std_ReturnType)0x00U)     /* Function Return OK */
#define E_NOT_OK ((Std_ReturnType)0x01U) /* Function Return NOT OK */

#endif /* PLATFORM_TYPES_H */

/******************************************************************************
 *    FILENAME    : utils.h
 *    DESCRIPTION : This file contains declarations and s of SIOCONN_CONT_Utils.c
 ******************************************************************************
 * Revision history
 *
 * Ver Author       Date               Description
 * 1   Sloki     18/01/2017		   Initial version
 ******************************************************************************
 */
/* ************************************************************************** */

#ifndef _SIOCONN_CONT_UTILS_H /* Guard against multiple inclusion */
#define _SIOCONN_CONT_UTILS_H

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

/* This section lists the other files that are included in this file.
 */

/* TODO:  Include other files here if needed. */
#include <stdint.h>
#include "diag_typedefs.h"
/* Provide C++ Compatibility */
#ifdef __cplusplus
"C"
{
#endif

  /* ************************************************************************** */
  /* ************************************************************************** */
  /* Section: Constants                                                         */
  /* ************************************************************************** */
  /* ************************************************************************** */

  /*  A brief description of a section can be given directly below the section
      banner.
   */

  // *****************************************************************************
  // *****************************************************************************
  // Section: Data Types
  // *****************************************************************************
  // *****************************************************************************
  typedef union
  {
    uint16_t type_conv_u16;
    uint8_t type_conv_au8[2];
  } typeconv_u16_Un_t;

  typedef union
  {
    uint32_t type_conv_u32;
    uint8_t type_conv_au8[4];
  } typeconv_u32_Un_t;

  typedef union
  {
    uint64_t type_conv_u64;
    uint8_t type_conv_au8[8];
  } typeconv_u64_Un_t;
  // *****************************************************************************
  // *****************************************************************************
  // Section: Interface Functions
  // *****************************************************************************
  // *****************************************************************************

  /*  A brief description of a section can be given directly below the section
      banner.
   */

  // *****************************************************************************

#define FILTER_FACTOR_1 0.1f
#define FILTER_FACTOR_2 0.2f
#define FILTER_FACTOR_3 0.3f
#define FILTER_FACTOR_4 0.4f
#define FILTER_FACTOR_5 0.5f
#define FILTER_FACTOR_6 0.6f
#define FILTER_FACTOR_7 0.7f
#define FILTER_FACTOR_8 0.8f
#define FILTER_FACTOR_9 0.9f
#define FILTER_FACTOR_10 1.0f
#define FILTER_FACTOR_11 0.05f

  /*******************************************************************************
   *  STRUCTURES, ENUMS and TYPEDEFS
   ******************************************************************************/

  /*******************************************************************************
   *  EXTERN GLOBAL VARIABLES
   ******************************************************************************/

  /*******************************************************************************
   *  EXTERN FUNCTION
   ******************************************************************************/

  /*
    @Function
      void delay_1sec(void)

    @Summary
   This Funciton gives delay of 1sec

   */
  void delay_1sec(void);

  /**
    @Function
      void delay_ms(uint16_t delay))

    @Summary
   This Function produces specified milli seconds of delay.

   */
  void delay_ms(uint16_t delay);

  /* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _EXAMPLE_FILE_NAME_H */

/* *****************************************************************************
 End of File
 */

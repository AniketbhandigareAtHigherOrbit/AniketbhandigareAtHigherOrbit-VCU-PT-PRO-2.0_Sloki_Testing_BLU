/*******************************************************************************
|-------------------------------------------------------------------------------
|   FILE DESCRIPTION
|-------------------------------------------------------------------------------
|    File           :  dcan_tp_stack_version.h
|    Project        : MIL_PBL_CV
|    Description    : This file contains version # of ISO 15765-2 stack software.
 *                  This is an internal version # to track the stack development.
 *                  This version # does not refer to ver # of ISO15765 standard.
|-------------------------------------------------------------------------------
|
|-------------------------------------------------------------------------------
|               A U T H O R   I D E N T I T Y
|-------------------------------------------------------------------------------
|   Date              Name                        Company
| ----------     ---------------     -----------------------------------
| 31/07/2024       Manikandan S             Sloki Software Technologies LLP
|-------------------------------------------------------------------------------
|******************************************************************************/ 
#ifndef	_DCAN_TP_STACK_VERSION_H_
#define _DCAN_TP_STACK_VERSION_H_

// The number to be incremented whenever a new release happens internally/to customer.
/**
Format
	Version numbering schemes: A.B.C.D
	A - incremented whenever a new module/file is added.
	B - incremented whenever a new API/function is added.
	C - incremented whenever a buf fixing with file/module/function/API
	D - incremented for any minor/cosmetics/comments/...etc changes.
*/
#define DCANTP_STACK_VERSION	"V1.0.0.0"

#endif

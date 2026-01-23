/******************************************************************************
 *    FILENAME    : fm_stack_version.h
 *    DESCRIPTION : This file contains version # of Fault manager stack.
 ******************************************************************************
 * Revision history
 *  
 * Ver Author       Date               Description
 * 1   Sloki     18/01/2017		   Initial version
 ******************************************************************************
*/    

#ifndef	_FM_STACK_VERSION_H_
#define _FM_STACK_VERSION_H_

// The number to be incremented whenever a new release happens internally/to customer.
/**
Format
	Version numbering schemes: A.B.C.D
	A - incremented whenever a new module/file is added.
	B - incremented whenever a new API/function is added.
	C - incremented whenever a buf fixing with file/module/function/API
	D - incremented for any minor/cosmetics/comments/...etc changes.
*/
#define FM_STACK_VERSION	"V1.1.0.0"

#endif

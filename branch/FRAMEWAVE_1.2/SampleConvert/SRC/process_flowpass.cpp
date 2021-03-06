/*
Copyright (c) 2006-2008 Advanced Micro Devices, Inc. All Rights Reserved.
This software is subject to the Apache v2.0 License.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>


#include"globals.h"
#include"process_API.h"


/*!
 *************************************************************************************
 * \function process_flowpass
 *
 * \brief
 *    This function processes Lowpass Filter operation.
 *
 *
 *************************************************************************************
 */

void
process_flowpass(st_API_parameters *p)
{
	int		api_return_val = 0;

	TIME_START		/* Start Timer */

	/*--------------------------------------------------------------------------------*/
	/* Calling API "fwiFilterLowpass_8u_C3R" :                                   */
	/*                                                                                */
	/*	This function steps through an ROI in a source buffer,						  */
	/*	applies a low-pass operator  to the source data,							  */
	/*	and writes the filtered data to a destination buffer.                         */
	/*  The function uses a 3X3 kernel.                                               */
    /*                                                                                */
    /*																				  */
	/*--------------------------------------------------------------------------------*/
#ifndef SOL
	api_return_val = fwiFilterLowpass_8u_C3R(p->pSrc , p->srcStep, &p->pDst[(p->bor_width * 3) + 3] , p->dstStep, p->dstRoiSize, p->maskSize_filter);
#endif


	TIME_FINISH(p)	/* Stop  Timer */

	if (api_return_val<0)
		throw api_return_val ;
}






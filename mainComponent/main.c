/*
 * Copyright (C) 2016-2017 Renfell Engineering Pty Ltd - All Rights Reserved
 *
 * Use of this work is subject to license and solely for use with hardware
 * supplied by Renfell Engineering Pty Ltd.
 *
 * Proprietary and confidential.
 * This file or any part thereof may not be used, distributed, copied, or
 * modified for use for any purpose other than that for which it was
 * originally provided without first receiving written permission of the
 * copyright holder.
 *
 * This source code is provided 'as is' without warranty of any kind, either
 * expressed or implied by consumer legislation or otherwise, including but
 * not limited to the implied warranties of merchantability and/or fitness
 * for a particular purpose.
 *
 * The end user acknowledges that this software is a "work in progress", and
 * as such should not be relied upon in a commercial environment or other
 * situations where economic loss or harm to persons may arise due to a
 * failure to perform to the end users specific requirements.
 *
 * By use of this software you agree to the use of the above terms.
 *
 */

#include "legato.h"
#include "interfaces.h" /* include auto-generated api interfaces from Component.cdef */

le_timer_Ref_t VendTimerHandle = NULL;

le_timer_Ref_t otherEventTimerHandle = NULL;

//-------------------------------------------------------------------------------------------------
/*
 * Timer Handler
 */
//-------------------------------------------------------------------------------------------------
void vendTimerHandler(le_timer_Ref_t pTimerRef )
{
    le_result_t __attribute__ ((unused)) result;
    static uint8_t id = 0;
    static uint32_t data = 0;

    LE_INFO ("Test: start");

    async_Test(id, &data);

    LE_INFO( "Test: result id[%d] data[%d]", id, data);
    id++;

    //le_timer_Restart( pTimerRef );

    return;
}



void otherTimerHandler(le_timer_Ref_t pTimerRef )
{
	static int32_t ctr = 0;
    LE_INFO ("other timer: cnt %d", ctr++);
}

COMPONENT_INIT
{
    LE_INFO( "main Init" );

    VendTimerHandle = le_timer_Create("ATimer");
    le_timer_SetHandler ( VendTimerHandle, vendTimerHandler );
    le_timer_SetMsInterval( VendTimerHandle, 1000 );
    le_timer_SetRepeat( VendTimerHandle, 1);	// run once

    le_timer_Start( VendTimerHandle );

    otherEventTimerHandle = le_timer_Create("otherTimer");
    le_timer_SetHandler ( otherEventTimerHandle, otherTimerHandler );
    le_timer_SetMsInterval( otherEventTimerHandle, 500 );
    le_timer_SetRepeat( otherEventTimerHandle, 20);

    le_timer_Start( otherEventTimerHandle );


}


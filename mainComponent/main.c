/*
 * Copyright (C) 2016-2017 Renfell Engineering Pty Ltd - All Rights Reserved
 *
MIT License

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
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


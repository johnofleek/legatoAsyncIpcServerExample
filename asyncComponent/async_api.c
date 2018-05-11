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


void async_Test
(
    async_ServerCmdRef_t _cmdRef,
    uint8_t pId
)
{
    LE_INFO("%s: enter", __FUNCTION__);

    async_TestRespond( _cmdRef, pId+1 );
    sleep(6);

    LE_INFO("%s: exit", __FUNCTION__);
    return;
}

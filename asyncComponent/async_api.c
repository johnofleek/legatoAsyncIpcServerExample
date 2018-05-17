/*
 * Copyright (C) 2016-2017 Renfell Engineering Pty Ltd - All Rights Reserved
 *
MIT License

Copyright (c) 2017 John

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

/*
 * Copyright 2020 D'Arcy Smith + the BCIT CST Datacommunications Option students.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#include "netdb.h"
#include "error.h"
#include <netdb.h>
#include <stdlib.h>
#include <errno.h>


struct hostent *dc_gethostbyaddr(const void *addr, socklen_t len, int type)
{
    return dc_gethostbyaddr_error(dc_handle_error, addr, len, type);
}
struct hostent *dc_gethostbyaddr_error(dc_errno_handler handler, const void *addr, socklen_t len, int type)
{
    struct hostent *entry;

    entry = gethostbyaddr(addr, len, type);

    if(entry == NULL)
    {
        if(handler)
        {
            handler("open", __FILE__, __LINE__, errno);
        }
    }

    return entry;
}

struct hostent *dc_gethostbyname(const char *name)
{
    return dc_gethostbyname_error(dc_handle_error, name);
}

struct hostent *dc_gethostbyname_error(dc_errno_handler handler, const char *name)
{
    struct hostent *entry;

    entry = gethostbyname(name);

    if(entry == NULL)
    {
        if(handler)
        {
            handler("open", __FILE__, __LINE__, errno);
        }
    }

    return entry;
}

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


#include "error.h"
#include "fcntl.h"
#include <errno.h>
#include <fcntl.h>
#include <stdarg.h>
#include <stdlib.h>


int dc_open(const char *path, int oflag, ...)
{
    va_list args;
    int fd;
    
    va_start(args, oflag);
    fd = dc_open_error(dc_handle_error, path, oflag, args);
    
    return fd;
}


int dc_open_error(dc_errno_handler handler, const char *path, int oflag, ...)
{
    va_list args;
    int fd;

    va_start(args, oflag);
    fd = open(path, oflag, args);
    
    if(fd == -1)
    {
        if(handler)
        {
            handler("open", __FILE__, __LINE__, errno);
        }
    }
    
    return fd;
}

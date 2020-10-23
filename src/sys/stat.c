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


#include "../error.h"
#include "stat.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>


void dc_stat(const char *restrict path, struct stat *restrict buf)
{
    dc_stat_error(dc_handle_error, path, buf);
}

void dc_stat_error(void (*handler)(const char *, const char *, int, int), const char *restrict path, struct stat *restrict buf)
{
    int status;
    
    status = stat(path, buf);
    
    if(status == -1)
    {
        if(handler)
        {
            handler("stat", __FILE__, __LINE__, errno);
        }
    }
}


void dc_mkfifo(const char *path, mode_t mode, bool can_exist)
{
    dc_mkfifo_error(dc_handle_error, path, mode, can_exist);
}


void dc_mkfifo_error(dc_errno_handler handler, const char *path, mode_t mode, bool can_exist)
{
    int status;
    
    status = mkfifo(path, S_IFIFO | mode);
    
    if(status == -1)
    {
        printf("%d\n", errno);
        if(errno != EEXIST || !(can_exist))
        {
            if(handler)
            {
                handler("mkfifo", __FILE__, __LINE__, errno);
            }
        }
    }
}


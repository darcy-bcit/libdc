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
#include "stdio.h"
#include <errno.h>
#include <stdio.h>


int dc_remove(const char *path, bool must_exist)
{
    return dc_remove_error(dc_handle_error, path, must_exist);
}


int dc_remove_error(dc_errno_handler handler, const char *path, bool must_exist)
{
    int ret_val;

    ret_val = remove(path);

    if(ret_val < 0)
    {
        if(errno != ENOENT || (errno == ENOENT && must_exist))
        {
            if(handler)
            {
                handler("remove", __FILE__, __LINE__, errno);
            }
        }
    }

    return ret_val;
}

FILE *dc_fopen(const char *restrict pathname, const char *restrict mode, bool must_exist)
{
    return dc_fopen_error(dc_handle_error, pathname, mode, must_exist);
}

FILE *dc_fopen_error(dc_errno_handler handler, const char *restrict pathname, const char *restrict mode, bool must_exist)
{
    FILE *file;

    file = fopen(pathname, mode);

    if(file == NULL)
    {
        if(errno != ENOENT || (errno == ENOENT && must_exist))
        {
            if(handler)
            {
                handler("fopen", __FILE__, __LINE__, errno);
            }
        }
    }

    return file;
}

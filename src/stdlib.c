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
#include "stdlib.h"
#include <errno.h>
#include <stdlib.h>


void *dc_malloc(size_t bytes)
{
    void *memory;

    memory = dc_malloc_error(dc_handle_error, bytes);

    return memory;
}


void *dc_malloc_error(dc_errno_handler handler, size_t bytes)
{
    void *memory;

    memory = calloc(1, bytes);

    if(memory == NULL)
    {
        if(handler)
        {
            handler("calloc", __FILE__, __LINE__, errno);
        }
    }

    return memory;
}

void *dc_realloc(void *ptr, size_t bytes)
{
    void *memory;

    memory = dc_realloc_error(dc_handle_error, ptr, bytes);

    return memory;
}


void *dc_realloc_error(dc_errno_handler handler, void *ptr, size_t bytes)
{
    void *memory;

    memory = realloc(ptr, bytes);

    if(memory == NULL)
    {
        if(handler)
        {
            handler("realloc", __FILE__, __LINE__, errno);
        }
    }

    return memory;
}

int dc_mkstemp(char *template)
{
    return dc_mkstemp_error(dc_handle_error, template);
}

int dc_mkstemp_error(dc_errno_handler  handler, char *template)
{
    int fd;

    fd = mkstemp(template);

    if(fd == -1)
    {
        if(handler)
        {
            handler("mkstemp", __FILE__, __LINE__, errno);
        }
    }

    return fd;
}

long dc_strtol(const char *restrict nptr, char **restrict endptr, int base)
{
    return dc_strtol_error(dc_handle_error, nptr, endptr, base);
}

long dc_strtol_error(dc_errno_handler handler, const char *restrict nptr, char **restrict endptr, int base)
{
    long val;
    char *tmp_ptr;

    val = strtol(nptr, &tmp_ptr, base);

    if(endptr)
    {
        *endptr = tmp_ptr;
    }

    if(nptr == tmp_ptr)
    {
        if(handler)
        {
            // this is broken, errno isn't set... hmmmm
            handler("strtol", __FILE__, __LINE__, errno);
        }
    }

    if(val == -1)
    {
        if(handler)
        {
            handler("strtol", __FILE__, __LINE__, errno);
        }
    }

    return val;
}

long long dc_strtoll(const char *restrict nptr, char **restrict endptr, int base)
{
    return dc_strtoll_error(dc_handle_error, nptr, endptr, base);
}

long long dc_strtoll_error(dc_errno_handler handler, const char *restrict nptr, char **restrict endptr, int base)
{
    long val;
    char *tmp_ptr;

    val = strtoll(nptr, &tmp_ptr, base);

    if(endptr)
    {
        *endptr = tmp_ptr;
    }

    if(nptr == tmp_ptr)
    {
        if(handler)
        {
            // this is broken, errno isn't set... hmmmm
            handler("strtol", __FILE__, __LINE__, errno);
        }
    }

    if(val == -1)
    {
        if(handler)
        {
            handler("strtoll", __FILE__, __LINE__, errno);
        }
    }

    return val;
}

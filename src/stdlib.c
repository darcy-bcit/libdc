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

void dc_free(void **pmemory)
{
    free(*pmemory);
    *pmemory = NULL;
}

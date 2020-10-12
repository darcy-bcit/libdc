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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void dc_handle_error(const char *func, const char *file_name, int line_number, int errno)
{
    char *message;
    
    message = strerror(errno);
    dc_handle_error_message(func, file_name, line_number, message);
}

void dc_handle_error_message(const char *func, const char *file_name, int line_number, const char *message)
{
    fprintf(stderr, "%s (%d) - %s: %s\n", file_name, line_number, func, message);
    exit(EXIT_FAILURE);
}

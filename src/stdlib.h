#ifndef DC_STDLIB_H
#define DC_STDLIB_H


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
#include <stddef.h>
#include <stdio.h>


void *dc_malloc(size_t bytes);
void *dc_malloc_error(dc_errno_handler handler, size_t bytes);
void *dc_realloc(void * ptr, size_t bytes);
void *dc_realloc_error(dc_errno_handler handler, void * ptr, size_t bytes);
void dc_free(void **pmemory);
int dc_mkstemp(char * template);
int dc_mkstemp_error(dc_errno_handler handler, char * template);
long dc_strtol(const char *restrict nptr, char **restrict endptr, int base);
long dc_strtol_error(dc_errno_handler handler, const char *restrict nptr, char **restrict endptr, int base);
long long dc_strtoll(const char *restrict nptr, char **restrict endptr, int base);
long long dc_strtoll_error(dc_errno_handler handler, const char *restrict nptr, char **restrict endptr, int base);


#endif

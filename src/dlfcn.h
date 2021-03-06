#ifndef DLFCN_H
#define DLFCN_H


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


void *dc_dlopen(const char * restrict file, int mode);
void *dc_dlopen_error(dc_message_handler handler, const char * restrict file, int mode);
void dc_dlclose(void * restrict handle);
void dc_dlclose_error(dc_message_handler handler, void * restrict handle);
void *dc_dlsym(void * restrict handle, const char * restrict name);
void *dc_dlsym_error(dc_message_handler handler, void * restrict handle, const char * restrict name);


#endif

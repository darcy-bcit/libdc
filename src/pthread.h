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


#ifndef DC_PTHREAD_H
#define DC_PTHREAD_H

#include "error.h"
#include <pthread.h>

int dc_pthread_join(pthread_t thread, void ** value_ptr);
int dc_pthread_join_error(dc_errno_handler handler, pthread_t thread, void ** value_ptr);
int dc_pthread_create(pthread_t * thread, const pthread_attr_t * attr, void *(* start_routine)(void *), void * arg);
int dc_pthread_create_error(dc_errno_handler handler, pthread_t * thread, const pthread_attr_t * attr,
                         void *(* start_routine)(void *), void * arg);
int dc_pthread_detach(pthread_t thread);
int dc_pthread_detach_error(dc_errno_handler handler, pthread_t thread);

#endif //DC_PTHREAD_H

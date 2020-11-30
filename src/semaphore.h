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

#ifndef DC_SEMAPHORE_H
#define DC_SEMAPHORE_H

#include <semaphore.h>

int    dc_sem_close(sem_t * sem);
int    dc_sem_close_error(void (*error_handler)(const char *, const char *, int, int), sem_t * sem);
int    dc_sem_wait(sem_t * sem);
int    dc_sem_wait_error(void (*error_handler)(const char *, const char *, int, int), sem_t * sem);
int    dc_sem_destroy(sem_t * sem);
int    dc_sem_destroy_error(void (*error_handler)(const char *, const char *, int, int), sem_t * sem);
int    dc_sem_getvalue(sem_t *restrict sem, int *restrict sval);
int    dc_sem_getvalue_error(void (*error_handler)(const char *, const char *, int, int), sem_t *restrict sem,
                             int *restrict sval);
int    dc_sem_init(sem_t * sem, int pshared, unsigned int value);
int    dc_sem_init_error(void (*error_handler)(const char *, const char *, int, int), sem_t * sem, int pshared,
                         unsigned int value);
sem_t * dc_sem_open(const char * name, int oflag, ...);
sem_t * dc_sem_open_error(void (*error_handler)(const char *, const char *, int, int), const char * name, int oflag, ...);
int    dc_sem_post(sem_t * sem);
int    dc_sem_post_error(void (*error_handler)(const char *, const char *, int, int), sem_t * sem);

int    dc_sem_unlink(const char * name);
int    dc_sem_unlink_error(void (*error_handler)(const char *, const char *, int, int), const char * name);
int    dc_sem_trywait(sem_t * sem);
int    dc_sem_trywait_error(void (*error_handler)(const char *, const char *, int, int), sem_t * sem);

#endif //DC_SEMAPHORE_H

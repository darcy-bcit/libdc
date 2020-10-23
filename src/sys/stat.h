#ifndef DC_SYS_STAT_H
#define DC_SYS_STAT_H


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


#include <fcntl.h>
#include <stdbool.h>
#include <sys/stat.h>


void dc_stat(const char *restrict path, struct stat *restrict buf);
void dc_stat_error(void (*error_handler)(const char *, const char *, int, int), const char *restrict path, struct stat *restrict buf);
void dc_mkfifo(const char *path, mode_t mode, bool can_exit);
void dc_mkfifo_error(void (*error_handler)(const char *, const char *, int, int), const char *path, mode_t mode, bool can_exit);


#endif

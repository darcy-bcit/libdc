#ifndef DC_UNISTD_H
#define DC_UNISTD_H


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
#include <sys/types.h>


ssize_t dc_read(int fd, void *data, size_t length);
ssize_t dc_read_error(dc_errno_handler handler, int fd, void *data, size_t length);
ssize_t dc_write(int fd, const void *data, size_t length);
ssize_t dc_write_error(dc_errno_handler handler, int fd, const void *data, size_t length);
void dc_close(int fd);
void dc_close_error(dc_errno_handler handler, int fd);
void dc_pipe(int fds[2]);
void dc_pipe_error(dc_errno_handler handler, int fds[2]);
off_t dc_lseek(int fd, off_t offset, int whence);
off_t dc_lseek_error(dc_errno_handler handler, int fd, off_t offset, int whence);
int dc_unlink( const char * pathname);
int dc_unlink_error(dc_errno_handler handler, const char * pathname);

#endif

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
#include "unistd.h"
#include <errno.h>
#include <unistd.h>


ssize_t dc_read(int fd, void *data, size_t length)
{
    return dc_read_error(dc_handle_error, fd, data, length);
}


ssize_t dc_read_error(dc_errno_handler handler, int fd, void *data, size_t length)
{
    ssize_t status;
    
    status = read(fd, data, length);
    
    if(status == -1)
    {
        if(handler)
        {
            handler("read", __FILE__, __LINE__, errno);
        }
    }
    
    return status;
}


ssize_t dc_write(int fd, const void *data, size_t length)
{
    return dc_write_error(dc_handle_error, fd, data, length);
}


ssize_t dc_write_error(dc_errno_handler handler, int fd, const void *data, size_t length)
{
    ssize_t status;
    
    status = write(fd, data, length);
    
    if(status == -1)
    {
        if(handler)
        {
            handler("write", __FILE__, __LINE__, errno);
        }
    }
    
    return status;
}


void dc_close(int fd)
{
    dc_close_error(dc_handle_error, fd);
}


void dc_close_error(dc_errno_handler handler, int fd)
{
    int status;
    
    status = close(fd);
    
    if(status == -1)
    {
        if(handler)
        {
            handler("close", __FILE__, __LINE__, errno);
        }
    }
}


void dc_pipe(int fds[2])
{
    dc_pipe_error(dc_handle_error, fds);
}


void dc_pipe_error(dc_errno_handler handler, int fds[2])
{
    ssize_t status;
    
    status = pipe(fds);
    
    if(status == -1)
    {
        if(handler)
        {
            handler("pipe", __FILE__, __LINE__, errno);
        }
    }
}

off_t dc_lseek(int fd, off_t offset, int whence)
{
    return dc_lseek_error(dc_handle_error, fd, offset, whence);
}


off_t dc_lseek_error(dc_errno_handler handler, int fd, off_t offset, int whence)
{
    off_t position;

    position = lseek( fd, offset, whence);

    if( position == -1)
    {
        if(handler)
        {
            handler("lseek", __FILE__, __LINE__, errno);
        }
    }

    return position;
}

int dc_unlink( const char * pathname)
{
    return dc_unlink_error(dc_handle_error, pathname);
}


int dc_unlink_error(dc_errno_handler handler, const char * pathname)
{
    int status;

    status = unlink(pathname);

    if(status == -1)
    {
        if(handler)
        {
            handler("lseek", __FILE__, __LINE__, errno);
        }
    }

    return status;
}

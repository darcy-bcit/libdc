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


#include "../error.h"
#include "socket.h"
#include <errno.h>


int dc_socket(int domain, int type, int protocol)
{
    return dc_socket_error(dc_handle_error, domain, type, protocol);
}

int dc_socket_error(dc_errno_handler handler, int domain, int type, int protocol)
{
    int fd;

    fd = socket(domain, type, protocol);

    if(fd < 0)
    {
        if(handler)
        {
            handler("socket", __FILE__, __LINE__, errno);
        }
    }

    return fd;
}

int dc_bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen)
{
    return dc_bind_error(dc_handle_error, sockfd, addr, addrlen);
}

int dc_bind_error(dc_errno_handler handler, int sockfd, const struct sockaddr *addr, socklen_t addrlen)
{
    int ret_val;

    ret_val = bind(sockfd, addr, addrlen);

    if(ret_val < 0)
    {
        if(handler)
        {
            handler("bind", __FILE__, __LINE__, errno);
        }
    }

    return ret_val;
}

int dc_listen(int sockfd, int backlog)
{
    return dc_listen_error(dc_handle_error, sockfd, backlog);
}

int dc_listen_error(dc_errno_handler handler, int sockfd, int backlog)
{
    int ret_val;

    ret_val = listen(sockfd, backlog);

    if(ret_val < 0)
    {
        if(handler)
        {
            handler("listen", __FILE__, __LINE__, errno);
        }
    }

    return ret_val;
}

int dc_accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen)
{
    return dc_accept_error(dc_handle_error, sockfd, addr, addrlen);
}

int dc_accept_error(dc_errno_handler handler, int sockfd, struct sockaddr *addr, socklen_t *addrlen)
{
    int ret_val;

    ret_val = accept(sockfd, addr, addrlen);

    if(ret_val < 0)
    {
        if(handler)
        {
            handler("accept", __FILE__, __LINE__, errno);
        }
    }

    return ret_val;
}

int dc_connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen)
{
    return dc_connect_error(dc_handle_error, sockfd, addr, addrlen);
}

int dc_connect_error(dc_errno_handler handler, int sockfd, const struct sockaddr *addr, socklen_t addrlen)
{
    int ret_val;

    ret_val = connect(sockfd, addr, addrlen);

    if(ret_val < 0)
    {
        if(handler)
        {
            handler("connect", __FILE__, __LINE__, errno);
        }
    }

    return ret_val;
}

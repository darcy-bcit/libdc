#ifndef DC_SOCKET_H
#define DC_SOCKET_H


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
#include <sys/socket.h>


int dc_socket(int domain, int type, int protocol);
int dc_socket_error(dc_errno_handler handler, int domain, int type, int protocol);
int dc_bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
int dc_bind_error(dc_errno_handler handler, int sockfd, const struct sockaddr *addr, socklen_t addrlen);
int dc_listen(int sockfd, int backlog);
int dc_listen_error(dc_errno_handler handler, int sockfd, int backlog);
int dc_accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
int dc_accept_error(dc_errno_handler handler, int sockfd, struct sockaddr *addr, socklen_t *addrlen);
int dc_connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
int dc_connect_error(dc_errno_handler handler, int sockfd, const struct sockaddr *addr, socklen_t addrlen);


#endif


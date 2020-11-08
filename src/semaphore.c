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
#include <errno.h>
#include <fcntl.h>
#include <stdarg.h>
#include "semaphore.h"

int dc_sem_close(sem_t * sem) {
    return dc_sem_close_error(dc_handle_error, sem);
}

int dc_sem_close_error(dc_errno_handler handler, sem_t * sem) {
    int status;

    status = sem_close(sem);

    if(status == -1)
    {
        if(handler)
        {
            handler("sem_close", __FILE__, __LINE__, errno);
        }
    }

    return status;
}

int dc_sem_wait(sem_t * sem) {
    return dc_sem_wait_error(dc_handle_error, sem);
}

int dc_sem_wait_error(dc_errno_handler handler, sem_t * sem) {
    int status;

    status = sem_wait(sem);

    if(status == -1)
    {
        if(handler)
        {
            handler("sem_wait", __FILE__, __LINE__, errno);
        }
    }

    return status;
}

int dc_sem_destroy(sem_t * sem) {
    return dc_sem_destroy_error(dc_handle_error, sem);
}

int dc_sem_destroy_error(dc_errno_handler handler, sem_t * sem) {
    int status;

    status = sem_destroy(sem);

    if(status == -1)
    {
        if(handler)
        {
            handler("sem_destroy", __FILE__, __LINE__, errno);
        }
    }

    return status;
}

int dc_sem_getvalue(sem_t *restrict sem, int *restrict sval) {
    return dc_sem_getvalue_error(dc_handle_error, sem, sval);
}

int dc_sem_getvalue_error(dc_errno_handler handler, sem_t *restrict sem, int *restrict sval) {
    int status;

    status = sem_getvalue(sem, sval);

    if(status == -1)
    {
        if(handler)
        {
            handler("sem_getvalue", __FILE__, __LINE__, errno);
        }
    }

    return status;
}

int dc_sem_init(sem_t * sem, int pshared, unsigned int value) {
    return dc_sem_init_error(dc_handle_error, sem, pshared, value);
}

int dc_sem_init_error(dc_errno_handler handler, sem_t * sem, int pshared, unsigned int value) {
    int status;

    status = sem_init(sem, pshared, value);

    if(status == -1)
    {
        if(handler)
        {
            handler("sem_init", __FILE__, __LINE__, errno);
        }
    }

    return status;
}

sem_t * dc_sem_open(const char * name, int oflag, ...) {
    va_list args;
    return dc_sem_open_error(dc_handle_error, name, oflag, args);
}

sem_t * dc_sem_open_error(dc_errno_handler handler, const char * name, int oflag, ...) {
    va_list args;

    sem_t * sem;

    sem = sem_open(name, oflag, args);

    if(sem == SEM_FAILED)
    {
        if(handler)
        {
            handler("sem_open", __FILE__, __LINE__, errno);
        }
    }

    return sem;
}

int dc_sem_post(sem_t * sem) {
    return dc_sem_post_error(dc_handle_error, sem);
}

int dc_sem_post_error(dc_errno_handler handler, sem_t * sem) {
    int status;

    status = sem_post(sem);

    if(status == -1)
    {
        if(handler)
        {
            handler("sem_post", __FILE__, __LINE__, errno);
        }
    }

    return status;
}

int dc_sem_timedwait(sem_t *restrict sem, const struct timespec *restrict abstime) {
    return dc_sem_timedwait_error(dc_handle_error, sem, abstime);
}

int dc_sem_timedwait_error(dc_errno_handler handler, sem_t *restrict sem, const struct timespec *restrict abstime) {
    int status;

    status = sem_timedwait(sem, abstime);

    if(status == -1)
    {
        if(handler)
        {
            handler("sem_timedwait", __FILE__, __LINE__, errno);
        }
    }

    return status;
}

int dc_sem_unlink(const char * name) {
    return dc_sem_unlink_error(dc_handle_error, name);
}

int dc_sem_unlink_error(dc_errno_handler handler, const char * name) {
    int status;

    status = sem_unlink(name);

    if(status == -1)
    {
        if(handler)
        {
            handler("sem_unlink", __FILE__, __LINE__, errno);
        }
    }

    return status;
}

int dc_sem_trywait(sem_t * sem) {
    return dc_sem_trywait_error(dc_handle_error, sem);
}

int dc_sem_trywait_error(dc_errno_handler handler, sem_t * sem) {
    int status;

    status = sem_trywait(sem);

    if(status == -1)
    {
        if(handler)
        {
            handler("sem_trywait", __FILE__, __LINE__, errno);
        }
    }

    return status;
}


cmake_minimum_required(VERSION 3.17.3)
project(dc C)

set(CMAKE_C_STANDARD 11)
include_directories(/usr/local/include)
link_directories(/usr/local/lib)

add_library(dc SHARED dlfcn.c error.c fcntl.c netdb.c stdio.c stdlib.c unistd.c sys/mman.c sys/stat.c sys/socket.c pthread.c)
target_compile_options(dc PRIVATE -Wpedantic -Wall -Wextra -fPIC)

find_library(LIBDL dl)
if(LIBDL)
  target_link_libraries(dc ${LIBDL})
endif()

find_library(LIBRT rt)
if(LIBRT)
  target_link_libraries(dc ${LIBRT})
endif()

install(TARGETS dc DESTINATION lib)
install(FILES dlfcn.h error.h fcntl.h netdb.h stdio.h stdlib.h unistd.h pthread.h DESTINATION include/dc)
install(FILES sys/mman.h sys/socket.h sys/stat.h DESTINATION include/dc/sys)

cmake_minimum_required(VERSION 3.17.3)
project(dc C)

set(CMAKE_C_STANDARD 11)
include_directories(/usr/local/include)
link_directories(/usr/local/lib)

add_library(dc SHARED dlfcn.c error.c fcntl.c netdb.c stdio.c stdlib.c unistd.c sys/mman.c sys/stat.c sys/socket.c)
# target_link_libraries(dc dl pthread)
target_compile_options(dc PRIVATE -Wpedantic -Wall -Wextra -fPIC)

install(TARGETS dc DESTINATION lib)
install(FILES dlfcn.h error.h fcntl.h netdb.h stdio.h stdlib.h unistd.h DESTINATION include/dc)
install(FILES sys/mman.h sys/socket.h sys/stat.h DESTINATION include/dc/sys)

cmake_minimum_required(VERSION 3.0)
project(ft_select)

set(CMAKE_CXX_STANDARD 11)
#set (CMAKE_C_FLAGS "-g -Wall -Werror -Wextra")

set(SOURCE_FILES
        srcs/core/main.c
        srcs/core/init.c
        srcs/signals/signals.c
        srcs/utils/utils.c
        srcs/core/exit.c
        srcs/display/clear_screen_from_text.c
        srcs/core/input_loop.c
        srcs/display/print_words.c
        srcs/display/refresh_screen.c
        srcs/core/return_highlighted_words.c)

include_directories(includes)

#Libcbc
add_subdirectory(libft)
include_directories(libft/includes)

add_executable(ft_select ${SOURCE_FILES})

target_link_libraries(ft_select ft curses)
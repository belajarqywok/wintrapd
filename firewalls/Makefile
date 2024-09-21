TARGET = firewalls.exe
RELEASE_DIR = target/release
DEBUG_DIR = target/debug

.PHONY: run build-release build-debug clean

run:
	cargo run

build-release:
	cargo build --release
	mv $(RELEASE_DIR)/$(TARGET) ./

build-debug:
	cargo build --debug

clean:
	cargo clean
	
cc = gcc
vcpkg_root = /home/blaze/vcpkg

# flags
cflags_linux = -std=c11 -Isrc/include -I$(vcpkg_root)/installed/x64-linux/include
ldflags_linux = -L$(vcpkg_root)/installed/x64-linux/lib \
  -lraylib -lopus -lvorbis -lvorbisfile -lm -ldl -lpthread -lglfw3 -lGL -lX11 -lrt

cc_win = x86_64-w64-mingw32-gcc
cflags_win = -std=c11 -Isrc/include -I$(vcpkg_root)/installed/x64-mingw-static/include
ldflags_win = -L$(vcpkg_root)/installed/x64-mingw-static/lib \
  -lraylib -lvorbis -lvorbisfile -lm -lpthread -lglfw3 -lopengl32 -lgdi32 -lwinmm

target_linux = builds/main
target_win = builds/wmain.exe

.phony: all linux windows clean

all: linux windows

linux: $(target_linux)

windows: $(target_win)

# Add intermediate .o file to let Bear track compilation
builds/%.o: %.c
	mkdir -p builds
	$(cc) $(cflags_linux) -c $< -o $@

$(target_linux): builds/main.o
	$(cc) $^ -o $@ $(ldflags_linux)

$(target_win): main.c
	$(cc_win) $(cflags_win) $^ $(ldflags_win) -o $@

clean:
	rm -f $(target_linux) $(target_win) builds/*.o



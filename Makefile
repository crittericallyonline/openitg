# INCLUDE = -Isrc/lua-5.0/include
# CC = em++
# DEFINE = -DWITHOUT_NETWORKING
# ASSETS = --include-file ./assets@/
FLAGS = -sUSE_WEBGL2 -sFULL_ES3 -sUSE_GLFW -sUSE_ZLIB

# main: src/**/*
# 	mkdir -p out/scripts
# 	$(CC) src/*.cpp src/**/*.cpp $(INCLUDE) -o ./out/scripts/OpenITG.js $(DEFINE) $(FLAGS)

main: lua
	em++ binaries/lua.wasm -sMAIN_MODULE $(FLAGS) src/*.cpp src/**/*.cpp -I./lib/lua-5.0/include

# Lua-5.0
lua: lib/lua-5.0/*
	mkdir -p binaries
	emcc ./lib/lua-5.0/src/*.c ./lib/lua-5.0/src/lib/*.c -o binaries/lua.wasm -I./lib/lua-5.0/include -O3 -sSIDE_MODULE

clean:
	rm -rf out/
# INCLUDE = -Isrc/lua-5.0/include
# CC = em++
# DEFINE = -DWITHOUT_NETWORKING
# ASSETS = --include-file ./assets@/
FLAGS = -sUSE_WEBGL2 -sFULL_ES3 -sUSE_GLFW -sUSE_ZLIB

#paths
SRC = ./src
BIN = ./bin
LIB = ./lib

# main: src/**/*
# 	mkdir -p out/scripts
# 	$(CC) src/*.cpp src/**/*.cpp $(INCLUDE) -o ./out/scripts/OpenITG.js $(DEFINE) $(FLAGS)

WebITG:
	mkdir -p ./out/scripts
	em++ $(BIN)/*.wasm -sMAIN_MODULE $(FLAGS) $(SRC)/*.cpp $(SRC)/**/*.cpp $(SRC)/**/*.c -I$(LIB)/lua/include -DWITHOUT_NETWORKING -o out/scripts/OITG.js

#./bin/*.wasm
binaries: lua aes

# Lua-5.0
lua:
	mkdir -p $(BIN)
	emcc $(LIB)/$@/src/*.c $(LIB)/$@/src/lib/*.c -o $(BIN)/$@.wasm -I$(LIB)/$@/include -O3 -sSIDE_MODULE

# AES encryption?
aes:
	mkdir -p $(BIN)
	emcc $(LIB)/$@/*.c -o $(BIN)/$@.wasm -O3 -sSIDE_MODULE

clean:
	rm -rf out/ bin/
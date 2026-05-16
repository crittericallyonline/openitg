ASSETS = ./assets@/
FLAGS = -sUSE_WEBGL2 -sFULL_ES3 -sUSE_GLFW -sUSE_ZLIB

#paths
SRC = ./src
BIN = ./bin
LIB = ./lib

WebITG:
	mkdir -p ./out/scripts
	em++ $(BIN)/*.wasm -sMAIN_MODULE \
	$(FLAGS) $(SRC)/*.cpp $(SRC)/**/*.cpp $(SRC)/**/*.c \
	-I$(LIB) -I$(LIB)/lua/include/ -I$(LIB)/mad/ -I$(LIB)/stb/ \
	-DWITHOUT_NETWORKING \
	--use-port=vorbis --use-port=ogg \
	-o out/scripts/OITG.js

#./bin/*.wasm
binaries: lua aes mad

# Lua-5.0
lua:
	mkdir -p $(BIN)
	emcc $(LIB)/$@/src/*.c $(LIB)/$@/src/lib/*.c -o $(BIN)/$@.wasm -I$(LIB)/$@/include -O3 -sSIDE_MODULE

# libmad
mad:
	mkdir -p $(BIN)
	emcc $(LIB)/$@/*.c -o $(BIN)/$@.wasm -O3 -sSIDE_MODULE -DFPM_64BIT -DNDEBUG -I$(LIB)/mad

# AES encryption?
aes:
	mkdir -p $(BIN)
	emcc $(LIB)/$@/*.c -o $(BIN)/$@.wasm -O3 -sSIDE_MODULE

clean:
	rm -rf out/ bin/
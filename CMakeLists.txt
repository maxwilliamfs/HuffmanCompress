cmake_minimum_required(VERSION 3.10)
project(HuffmanCompress)
set(CMAKE_C_STANDARD 11)
add_executable(Huff.exe src/HuffmanCompressor.c src/BytesIO.c src/Compressor.c src/Descompressor.c src/Structures.c src/TBuilder.c)
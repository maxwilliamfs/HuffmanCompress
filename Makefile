all:
	gcc src/BytesIO.c src/Compressor.c src/Descompressor.c src/Structures.c src/TBuilder.c src/HuffmanCompressor.c -o HuffmanCompressor

run:
	clear && ./HuffmanCompressor

clean:
	rm HuffmanCompressor
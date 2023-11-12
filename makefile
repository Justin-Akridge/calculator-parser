make:
	clear && clang++ token-stream.cpp token.cpp main.cpp -o main && ./main

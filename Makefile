build:
	cd src/ && C_INCLUDE_PATH=../include gcc -c *.c
	cd src/ && C_INCLUDE_PATH=../include gcc *.o -o ../simple-autograd
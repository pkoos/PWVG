all:
	g++ main.cpp PasswordValidator.cpp -o main.o

clean :
	rm main.o
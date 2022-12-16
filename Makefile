PROJECT_BASE = $(shell pwd)

all:
	g++ lib/main.cpp lib/PasswordValidator.cpp -I$(PROJECT_BASE)/include/ -o main.o

clean:
	rm main.o

run:
	./main.o
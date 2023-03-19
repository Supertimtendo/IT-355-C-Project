main: main.c bank.c account.c
	gcc -Wall -g -o main main.c bank.c account.c -lm

clean:
	rm main
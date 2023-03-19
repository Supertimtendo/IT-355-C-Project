all: FIO30 FIO37_39 FLP32 MSC32

FIO30: FIO30.c
	gcc -o FIO30 FIO30.c

FIO37_39: FIO37_39.c
	gcc -o FIO37_39 FIO37_39.c

FLP32: FLP32.c
	gcc -o FLP32 FLP32.c

MSC32: MSC32.c
	gcc -o MSC32 MSC32.c

clean:
	rm FIO30 FIO37_39 FLP32 MSC32
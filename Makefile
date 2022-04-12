main: main.o GCD.o modular.o primes.o encode.o
	gcc -o main main.o GCD.o modular.o primes.o encode.o -lgmp
main.o: main.c GCD.h
	gcc -c -g main.c
GCD.o: GCD.c GCD.h
	gcc -c -g GCD.c
modular.o: modular.c modular.h
	gcc -c -g modular.c
primes.o: primes.c primes.h
	gcc -c -g primes.c
encode.o: encode.c encode.h
	gcc -c -g encode.c

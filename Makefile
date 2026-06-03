all:
	musl-gcc -static -pipe -c stds/printf.c -o stds/printf.o
	./nas test.nasm test -I stds/ || chmod +x ./nas

clean:
	rm ./test

install:
	cp ./stds/* /asm/stds/

install-nas:
	sudo cp ./nas /usr/bin/nas


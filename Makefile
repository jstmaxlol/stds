all:
	./nas test.nasm test
install:
	cp ./stds.inc /asm/
clean:
	rm ./test

all:
	./nas test.nasm test || chmod +x ./nas

clean:
	rm ./test

install:
	cp ./stds/* /asm/stds/

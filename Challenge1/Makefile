CC = gcc
CFLAGS = -Wall -Wextra

prepare_steps: answer1.S
	$(CC) $(CFLAGS) challenge1.c -S -o challenge1.S

reprepare_steps: answer1.S

reprepare: reprepare_steps encrypt
	$(CC) $(CFLAGS) compare_files.c -o compare_files
	chmod +x compare_files

begin: prepare_steps encrypt_challenge1
	$(CC) $(CFLAGS) compare_files.c -o compare_files

answer1.S: answer1.c
	$(CC) $(CFLAGS) answer1.c -S -o answer1.S

# Create an empty answer1.c file
answer1.c:
	touch answer1.c

# Build the encryption program and mark it as executable
encrypt: encryption.c
	$(CC) $(CFLAGS) encryption.c -o encryption
	chmod +x encryption

# Encrypt the challenge1.c file using encryption
encrypt_challenge1: encrypt challenge1.c
	./encryption challenge1.c

test: prepare challenge1.S answer1.S
	./compare_files challenge1.S answer1.S

.PHONY: prepare encrypt_challenge1 prepare_steps

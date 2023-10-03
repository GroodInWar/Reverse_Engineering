# x86 to C and Decription

The challenge is to find what program in C was written for [challenge1.c] to achieve the assembly 
code in [challenge1.S]. The challenge also has an encryption/decryption approach to the challenge
for finding the contents of the file [challenge1.c]. Don't open any file until you have run 
"$make begin".

## Table of Contents

- [Features](#features)
- [Usage](#usage)
- [Creator](#creator)


## Features

- Reverse x86 to C.
- Encryption/Decryption.

## Usage:

- Run "$make begin" to initiate your code for the challenge. 
- DO NOT run "$make begin" twice.
- Run "$make test" to test your code.
- Run "$make clean" to clean object files and [answer1.S].
- Run "$make redo" to recover the object files and an empty [answer1.S] file.
- Through decryption you will not receive a percentage of how close to the original code you are,
you will need to replace [answer1.c] with what you have found in [challenge.c].

## Creator:
- name: Gustavo Sakamoto de Toledo
- GitHub: https://github.com/GroodInWar

```bash
# Clone the repository
git clone https://github.com/GroodInWar/Reverse_Engineering.git

# Change to the project directory
cd Challenge1

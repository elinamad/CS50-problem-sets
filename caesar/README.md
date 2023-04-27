<h1>Caesar</h1>

This program takes a single command-line argument, a key, and prompts the user for a plaintext. It then converts the plaintext to ciphertext using the key by rotating each letter by the key value.

The program first checks if the user entered only one command-line argument and if that argument contains only digits using a function called only_digits.

If the user enters an invalid argument, the program outputs an error message and exits. If the user enters a valid argument, the program converts the argument to an integer using the atoi function.

The program then prompts the user to enter a plaintext and calls the rotate function to convert each letter in the plaintext to ciphertext by rotating it by the key value.

The rotate function takes a character p and an integer k as input and returns a character c. If p is a letter, the function rotates it by k places and returns the rotated letter. If p is not a letter, the function returns the original character.

The program then outputs the resulting ciphertext to the console.


<h1>Scrabble</h1>

This program calculates the score of two players' input words based on the points assigned to each letter of the alphabet.

The program first defines an integer array called POINTS, which contains the number of points assigned to each letter of the alphabet in order.

The program then defines a function called compute_score, which takes a string as input and calculates the score of the string based on the points assigned to each letter of the alphabet in the POINTS array. The function uses a for loop to iterate through each character of the string, checks if it is a letter or not, and adds the appropriate number of points to the score based on the letter's index in the POINTS array.

The program then prompts the user to input words for two players and calculates the score of each word using the compute_score function. The program then compares the scores and outputs the winner or if it's a tie.
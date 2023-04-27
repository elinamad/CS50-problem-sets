<h1>Readability</h1>

This program calculates the reading level of a given text based on the Coleman-Liau index formula. The program counts the number of letters, words, and sentences in the text, calculates the average number of letters and sentences per 100 words, and then calculates the Coleman-Liau index using these averages. The resulting index is then rounded to the nearest integer, and the program outputs the corresponding reading level based on the index.

The program defines three functions: count_letters, count_words, and count_sentences. These functions use loops to count the number of letters, words, and sentences in the text, respectively.

The program then prompts the user to input a text, calls the count functions to get the letter, word, and sentence counts, calculates the Coleman-Liau index using the counts, and outputs the corresponding reading level based on the index.

If the resulting index is less than 1, the program outputs "Before Grade 1." If the index is between 1 and 15 (inclusive), the program outputs "Grade x," where x is the index rounded to the nearest integer. If the index is 16 or higher, the program outputs "Grade 16+."

<h2>Specification</h2>

+ Implement your program in a file called readability.c in a directory called readability.
+ Your program must prompt the user for a string of text using <code>get_string</code>.
+ Your program should count the number of letters, words, and sentences in the text. You may assume that a letter is any lowercase character from a to z or any uppercase character from A to Z, any sequence of characters separated by spaces should count as a word, and that any occurrence of a period, exclamation point, or question mark indicates the end of a sentence.
+ Your program should print as output "Grade X" where X is the grade level computed by the Coleman-Liau formula, rounded to the nearest integer.
If the resulting index number is 16 or higher (equivalent to or greater than a senior undergraduate reading level), your program should output "Grade 16+" instead of giving the exact index number. If the index number is less than 1, your program should output "Before Grade 1".
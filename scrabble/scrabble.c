#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet in order
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print the winner

    if (score1 > score2)
    {
        printf("player 1 wins!\n");
    }

    if (score1 < score2)
    {
        printf("player 2 wins!\n");
    }

    if (score1 == score2)
    {
        printf("it's a tie!\n");

    }
}

int compute_score(string word)
{

    // Compute and return score for string

    int score = 0;

    //repeat for the lenght of the word

    for (int i = 0; i < strlen(word); i++)
    {

        //if on ascii value below 65 dont add points (not a letter)

        if (word[i] < 65)
        {
            score = score + 0;
        }

        //not letters

        if (word[i] > 90 && word[i] < 97)
        {
            score = score + 0;
        }

        //not letters

        if (word[i] > 122)
        {
            score = score + 0;
        }

        //if uppercase

        if (word[i] > 65 && word[i] < 90)
        {
            score = score + POINTS [word[i] - 65];
        }

        //if lowercase
        
        if (word[i] > 97 && word [i] < 122)
        {
            score = score + POINTS [word[i] - 97];
        }



    }

    return score;
}

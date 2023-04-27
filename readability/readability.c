#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

//      Coleman-Liau index formula: index = 0.0588 * L - 0.296 + S - 15.8
//      L = average number of letters per 100 words
//      S = average number of sentences per 100 words

//      program should: count the number of letters, words and sentences in the text.
//      A-Z, a-z sequences seperated by space are words, any occurence of . ! ? indicates end of sentence
//      output: "grade x" , where x is the grade level calculated by the formula rounded to the nearest integer
//      if the resuting number is 16 or highter program should output "grade 16+", if the index is less than 1 program outputs "before grade 1"


int count_letters(string text);
int count_words(string text);
int count_sentences(string text);


int main(void)
{
    //ask user to input text

    string text = get_string("text: ");

    //get functions

    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    //debug the count function

    //printf("letters: %i\n", letters);
    //printf("words: %i\n", words);
    //printf("sentences: %i\n", sentences);

    // calculate the averages

    float l = (((float)letters / (float)words) * 100);
    float s = (((float)sentences / (float)words) * 100);

    //calculate the Coleman-Liau index

    float subindex = (0.0588 * l - 0.296 * s - 15.8);
    int index = round(subindex);


    // display the reading level

    if (index < 1)
    {
        printf("Before Grade 1\n");
        //printf("index:%i", index);
    }

    if (index >= 1 && index <= 15)
    {
        printf("Grade %i\n", index);
        //printf("index:%i", index);
    }

    if (index >= 16)
    {
        printf("Grade 16+\n");
        //printf("index:%i", index);
    }


}

//count the letters in text

int count_letters(string text)
{
    int letters = 0;
    for (int i = 0; strlen(text) > i; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
        else
        {
            letters = letters + 0;
        }
    }

    return letters;
}

//count words in text

int count_words(string text)
{
    int words = 0;

    for (int i = 0; strlen(text) > i; i++)
    {
        while (i < strlen(text))
        {
            if (text[i] == 32)
            {
                break;
            }
            i++;
        }

        words++;

    }
    return words;
}

//count sentences in text

int count_sentences(string text)
{
    int sentences = 0;

    for (int i = 0; strlen(text) > i ; i++)
    {
        while (i < strlen(text))
        {
            if (text[i] == 33 || text[i] == 46 || text[i] == 63)
            {
                break;
            }
            i++;
        }

        sentences++;
    }

    return sentences;
}


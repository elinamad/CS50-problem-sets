#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//program asks for key and plaintext, converts plaintext to cipher text using key

bool only_digits(string s);
char rotate(char p, int k);

int main(int argc, string argv[])
{

    //Check if entered only one argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    //call function only_digits to see if argument only has digits
    string s = argv[1];
    int isdigits = only_digits(s);

    if (isdigits != true)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    //turn string into an int

    int k = atoi(s);

    //ask user to input plaintext

    string plaintext = get_string("plaintext:  ");


    //turn plaintext into ciphertext by calling the rotate function

    int n = 0;
    char c = 0;
    printf("ciphertext:  ");
    for (int i = 0; i < strlen(plaintext); i++)
    {
        printf("%c", rotate(plaintext[i], k));
    }
    printf("\n");

}



//function to check if argument only has digits

bool only_digits(string s)
{
    int n = 0;
    for (int i = 0; strlen(s) > i; i ++)
    {
        if (isdigit(s[n]))
        {
            n++;
        }
        else
        {
            return false;
        }
    }
    return true;
}


//rotate letters by key

char rotate(char p, int k)
{
    char c = p;

    if (isalpha(p))
    {
        if (isupper(p))
        {
            c = ((((p - 65) + k) % 26) + 65);
            return c;
        }

        if (islower(p))
        {
            c = ((((p - 97) + k) % 26) + 97);
            return c;
        }
    }

    return c;

}
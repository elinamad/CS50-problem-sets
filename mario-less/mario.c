#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //input and height
    int x;
    //counter
    int i;
    //spaces
    int j;
    //hashes
    int k;

    //ask for height input x while x > 8
    do
    {
        x = get_int("Enter the height 1-8: ");
    }
    while (x > 8 || x <= 0);

    //do x times (height)
    for (i = 1; i < x + 1; i++)
    {

        //print x-1 spaces
        for (j = x - i; j > 0; j--)
        {
            printf(" ");
        }

        //print 0+1 hashes
        for (k = 0; k < i; k++)
        {
            printf("#");
        }

        //next line
        printf("\n");

    }
}

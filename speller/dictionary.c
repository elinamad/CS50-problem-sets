// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 27;

// Hash table
node *table[N];

unsigned int word_count = 0;




// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Convert word to lowercase
    char lowercase_word[LENGTH + 1];
    for (int i = 0; word[i]; i++)
    {
        lowercase_word[i] = tolower(word[i]);
    }
    lowercase_word[LENGTH] = '\0';

    // Hash word to get index in hash table
    int index = hash(lowercase_word);

    // Traverse linked list at that index
    node *cursor = table[index];
    while (cursor != NULL)
    {
        if (strcmp(cursor->word, lowercase_word) == 0)
        {
            // Word is in dictionary
            return true;
        }
        cursor = cursor->next;
    }

    // Word is not in dictionary
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function

    return tolower(word[0]) - 'a';




}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO

    char buffer[LENGTH + 1];
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        printf("could not open the file\n");
        return false;
    }

    while (fscanf(dict, "%s", buffer) == 1)
    {
        char *word = buffer;
        int bucket = hash(word);

        node *new = malloc(sizeof(node));
        if (new == NULL)
        {
            return false;
        }

        strcpy(new->word, word);
        new->next = table[bucket];
        table[bucket] = new;
        word_count++;
    }

    if (dict != NULL)
    {
        fclose(dict);
    }
    return true;



}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    word_count = 0;

    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while (cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }




    return true;
}

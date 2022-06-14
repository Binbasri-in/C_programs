// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include <cs50.h>
#include <stdlib.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

//size counter
int wordscounter = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int index = hash(word);
    node *curser = table[index];

    while (curser != NULL)
    {
        if (strcasecmp(curser->word, word) == 0)
        {
            return true;
        }
        curser = curser->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    char first = toupper(word[0]);
    return (int)first - 65;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }
    char words[LENGTH + 1];
    int index;
    while (fscanf(file, "%s", words) != EOF)
    {
        wordscounter++;
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }
        strcpy(n->word, words);
        index = hash(words);
        n->next = table[index];
        table[index] = n;

    }
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return wordscounter;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    node *curser = NULL;
    for (int i = 0; i < N; i++)
    {
        curser = table[i];
        while (curser != NULL)
        {
            node *tmp = curser->next;
            free(curser);
            curser = tmp;

        }
    }
    return true;
}

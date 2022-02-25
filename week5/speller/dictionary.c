// Implements a dictionary's functionality

#include <stdbool.h>

#include "dictionary.h"

#include <strings.h>

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

int word_count = 0;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO

    // http://www.partow.net/programming/hashfunctions/index.html
    // DJB Hash Function
    // An algorithm produced by Professor Daniel J. Bernstein;

        // unsigned int DJBHash(const char* str, unsigned int length)
        // {
        //   unsigned int hash = 5381;
        //   unsigned int i    = 0;

        //   for (i = 0; i < length; ++str, ++i)
        //   {
        //       hash = ((hash << 5) + hash) + (*str);
        //   }

        //   return hash;
        // }


    return 0;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Open dictionary file -> fopen();
    FILE *dictionaryPointer = fopen(dictionary, "r");

    // Check if the return value is NULL;
    if (dictionaryPointer == NULL)
    {
        return 1;
    }

    // LOOP until EOF
    // Read strings from dictionary, one at a time (load into hash table);
    // fscanf(file, "%s", buffer); // will return EOF once it reaches End Of File;
    // buffer
    char wordBuffer[LENGTH + 1];

    while (fscanf(dictionaryPointer, "%s", wordBuffer) != EOF)
    {
    // with each of those individual words:
    // Create a new node for each word -> allocate memory for a new node;
        node *new_node = malloc(sizeof(node));

    // check if the return value is NULL;
        if (new_node == NULL)
        {
            return 1;
        }

    // put data into the node -> copy word into node;
    // strcpy(n->word, "Hello");
    // n->next = NULL;
    strcpy(new_node->word, wordBuffer);
    new_node->next = NULL;
    words_count++;

    // hash word to obtain a hash value (index into the hash table);
    // call hash function -> hash();




    // insert node into hash table at that location;
    // add a new node to a linked list;
    // array of node pointers / linked lists =>> Hash table = node *table[N];


    }

    // fclose();

    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    return false;
}

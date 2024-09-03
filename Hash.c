#include<stdio.h>
#include<stdlib.h>


#define HASH_COL_SIZE (3)
#define HASH_ROW_SIZE (26)
#define MAX_INPUT_SIZE (13)


// Types
typedef struct Hash_s
{
    char* word;
    struct Hash_s* next;
}Hash_t, *pHash_t;

typedef enum
{
    SHORT_LENGTH = 3,
    MEDIUM_LENGTH = 7,
    LONG_LENGTH = 12,
}Length_t;


// Global variables
Hash_t Hash[HASH_COL_SIZE][HASH_ROW_SIZE];


// Functions
void SetUpHashTable(void)
{
    // HashTable 
    // 3 charactor or less : Hash[0]
    // 7 charactor or less : Hash[1]
    // 12 charactor or less : Hash[2]
    // The first index of the array is the size of the letter, and the second index is the alphabet.

    for(int i = 0; i < HASH_COL_SIZE; ++i)
    {
        for(int j = 0; j < HASH_ROW_SIZE; ++j)
        {
            Hash[i][j].word = NULL;
            Hash[i][j].next = NULL;
        }
    }
}

int GetCharactorLength(char* word)
{
    int cnt = 0;
    for(; word[cnt] != '\0'; ++ cnt){}

    if(cnt <= SHORT_LENGTH)
    {
        // Hash[0] location
        return 0;
    }
    else if(cnt <= MEDIUM_LENGTH)
    {
        // Hash[1] location
        return 1;
    }
    else
    {
        // Hash[2] location
        return 2;
    }
}

void InsertData(char* word, int length)
{
    char* wordSapce = NULL;
    Hash_t** hashTable = Hash;
    char initial = (word[0] | 32);


    switch(length)
    {
        case 0:
            wordSapce = malloc(sizeof(char) * SHORT_LENGTH);
            for(int i = 0; i < SHORT_LENGTH; ++i)
            {
                wordSapce[i] = word[i];
            }
            break;
        case 1:
            wordSapce = malloc(sizeof(char) * MEDIUM_LENGTH);
            for(int i = 0; i < MEDIUM_LENGTH; ++i)
            {
                wordSapce[i] = word[i];
            }
            break;
        case 2:
            wordSapce = malloc(sizeof(char) * LONG_LENGTH);
            for(int i = 0; i < LONG_LENGTH; ++i)
            {
                wordSapce[i] = word[i];
            }
            break;
        default: 
            printf("Out of range.");
            return;    
    }

    ((hashTable + length) + initial - 'a')->word = wordSapce;
}  


// Main
int main(void)
{   
    char word[MAX_INPUT_SIZE];

    return 0;
}
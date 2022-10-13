#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "additionalFuncs.h"

int* keyCreator(char* string);
char* incryptor(char* string, int* keys);
char* decryptor(char* string, int* keys);


int main()
{
    char* string = "Hi, my name is Mike Wazowski!";

    printf("%s\n", string);

    printf("%d\n", strlen_(string));

    arrayShow(keyCreator(string), 4);

    char* newString = incryptor(string, keyCreator(string));

    printf("%s\n", newString);

    printf("%s", decryptor(newString, keyCreator(string)));

    return 0;
}


int* keyCreator(char* string)
{
    srand(time(0));

    int length = strlen_(string);
    int* keys = malloc(length * sizeof(int));
    int randNum = rand() % length + 1;

    for (int i = 0; i < length; i++)
    {
        while (isInArray(keys, randNum, length))
        {
            randNum = rand() % length + 1;
        }
        keys[i] = randNum;
    }
    return keys;
}

char* incryptor(char* string, int* keys)
{
    int length = strlen_(string);
    char* incryptedString = calloc(length + 1, sizeof(char));

    for (int i = 0; i <= length + 1; i++)
    {
        for (int j = 0; j < length; j++)
        {
            if (i + 1 == keys[j])
            {
                incryptedString[j] = string[i];
                break;
            }
        }
    }
    return incryptedString;
}

char* decryptor(char* string, int* keys)
{
    int length = strlen_(string);
    char* decryptedString = calloc(length + 1, sizeof(char));

    for (int i = 0; i < length; i++)
        decryptedString[keys[i] - 1] = string[i];


    return decryptedString;
}

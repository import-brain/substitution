#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>
#include <math.h>
#include <ctype.h>

int detectDuplicateCharacters(string input); // function prototype

int main(int argc, string argv[])
{
    if (argc != 2) // check for two command line arguments, including ./substitution
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1]; // after computer confirms argv[1] exists, store it in a string

    if (strlen(key) != 26) // if key is not 26 characters, return error
    {
        printf("Key must contain 26 letters\n");
        return 1;
    }

    for (int i = 0, n = strlen(key); i < n; i++)
    { // for every char in key, if not in alphabet, return error and exit
        if (!isalpha(key[i]))
        {
            printf("Key must contain letters (not numbers, spaces, etc.)\n");
            return 1;
        }
    }
    // call duplicate char checking function
    int duplicateFailure = detectDuplicateCharacters(key);
    // if duplicate chars detected, return error message
    if (duplicateFailure == 1)
    {
        return 1;
    }
    // gets plaintext string from user
    string plaintext = get_string("plaintext: ");

}

int detectDuplicateCharacters(string input)
{
    int occurrences[26] = {0}; // array for occurences of each letter
    bool failure = false;
    
    for (int i = 0, n = strlen(input); i < n; i++) // ASCII magic to check for duplications
    {
        if (isupper(input[i]))
        {
            if (occurrences[(int) input[i] - 65] != 0)
            {
               failure = true;
            }
            else if (occurrences[(int) input[i] - 65] == 0)
            {
               occurrences[(int) input[i] - 65] = 1; 
            }
        }
        if (islower(input[i]))
        {
            if (occurrences[(int) input[i] - 97] != 0)
            {
               failure = true;
            }
            else if (occurrences[(int) input[i] - 97] == 0)
            {
               occurrences[(int) input[i] - 97] = 1; 
            }
        }
    }
    
    if (failure == true)
    {
        printf("Key must contain no duplicate letters\n");
        return 1;
    }
    else
    {
        return 0;
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>
#include <math.h>
#include <ctype.h>

int detectDuplicateCharacters(string input);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];

    if (strlen(key) != 26)
    {
        printf("Key must contain 26 letters\n");
        return 1;
    }

    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Key must contain letters (not numbers, spaces, etc.)\n");
            return 1;
        }
    }

    int duplicateFailure = detectDuplicateCharacters(key);

    if (duplicateFailure == 1)
    {
        return 0;
    }

    string plaintext = get_string("plaintext: ");

}

int detectDuplicateCharacters(string input)
{
    int occurrences[26] = {0};
    bool failure = false;
    
    for (int i = 0, n = strlen(input); i < n; i++)
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
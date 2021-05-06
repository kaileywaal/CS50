#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


string encipher(string text, string KEY);


int main(int argc, string argv[])
{
// KEY VALIDATION
    const string KEY = argv[1];

    // User must provide key
    if (argc == 1)
    {
        printf("Must provide substitution key\n");
        return 1;
    }

    // Key must be 26 letters
    if (strlen(KEY) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // Loop through each character in key
    for (int i = 0, n = strlen(KEY); i < n; i++)
    {
        // Check that all 26 characters are letters.
        if (! isalpha(KEY[i]))
        {
            printf("Key must only contain letters.\n");
            return 1;
        }

        // Check that each letter is used only once.
        else
        {
            for (int j = 0; j != i && j < n; j++)
            {
                if (toupper(KEY[i]) == toupper(KEY[j]))
                {
                    printf("Key must not repeat any characters\n");
                    return 1;
                }
            }
        }
    }

    // Get string as input
    string text = get_string("plaintext: ");

    // encipher input using provided key
    string encipheredText = encipher(text, KEY);

    // print enciphered text
    printf("ciphertext: %s\n", encipheredText);
}


string encipher(string text, string KEY)
{
    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // Go through each letter in text
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        //store index that matches letter found
        int matchIndex;

        // Find index of letter in alphabet
        for (int j = 0; j < strlen(alpha); j++)
        {
            if (toupper(text[i]) == alpha[j])
            {
                matchIndex = j;
            }
        }
        // Replace any letters with lowercase or uppercase version of key based on initial input
        if (isalpha(text[i]) && islower(text[i]))
        {
            text[i] = tolower(KEY[matchIndex]);
        }

        else if (isalpha(text[i]) && isupper(text[i]))
        {
            text[i] = toupper(KEY[matchIndex]);
        }
    }

    // Return the enciphered text
    return text;
}
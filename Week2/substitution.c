#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{

    if (argc != 2) //check for correct usage
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    if (strlen(argv[1]) != 26) //check that string is 26 characters
    {
        printf("Key must be 26 characters.\n");
        return 1;
    }
    for (int i = 0; i < strlen(argv[1]); i++) //check invalid characters
    {
        if ((argv[1][i] < 65 || argv[1][i] > 90) && (argv[1][i] < 97 || argv[1][i] > 122))
        {
            printf("Key must be 26 alphabetic characters.");
            return 1;
        }
    }
    for (int i = 0; i < strlen(argv[1]) - 1; i++) //-1 because we don't have to check the last character
    {
        for (int j = i + 1; j < strlen(argv[1]); j++)
        {

            if (argv[1][i] == argv[1][j])
            {
                printf("Key must not include duplicates.");
                return 1;
            }
        }
    }


    string key = argv[1];
    char keyArrLower[26];
    char keyArrUpper[26];
    string inputText = get_string("plaintext: ");


    for (int i = 0; i < strlen(key); i++) //map key into an array for lowercase

    {
        keyArrLower[i] = tolower(key[i]);
        keyArrUpper[i] = toupper(key[i]);
    }
    // printf("letter: %c\nvalue: %d\nencrypted value: %d", textInput[])


    for (int i = 0; i < strlen(inputText); i++) //encrypt by substitution of single char values
    {
        if (inputText[i] >= 'a' && inputText[i] <= 'z')
        {
            inputText[i] = keyArrLower[(int) inputText[i] - 97];
            //   printf("%d\n", (int) inputText[i]);
            //   printf("%c\n", keyArr[(int) inputText[i] - 97]);
        }
        else if (inputText[i] >= 'A' && inputText[i] <= 'Z')
        {
            inputText[i] = keyArrUpper[(int) inputText[i] - 65];
        }

    }

    printf("ciphertext: %s\n", inputText);
    return 0;

}

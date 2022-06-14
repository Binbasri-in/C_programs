#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

string encrypt(string text, int k);

int main(int argc, string argv[])
{
    //check the usage is correct
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    //check key is a number
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    //get plaintext and encrypt it
    int key = atoi(argv[1]);
    string ptext = get_string("plaintext: ");
    string ctext = encrypt(ptext, key);

    //print out ciphertext
    printf("ciphertext: %s\n", ctext);




}

string encrypt(string text, int k)
{
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        char c = text[i];
        if (isalpha(c))
        {
            if (islower(c))
            {
                int ci = (((int) c - 96) + k) % 26;
                text[i] = (char)(ci + 96);
            }
            else
            {
                int ci = (((int) c - 64) + k) % 26;
                text[i] = (char)(ci + 64);
            }
        }

    }
    return text;
}
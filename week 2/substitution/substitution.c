#define _CRT_SECURE_NO_WARNINGS
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char Key[26]; // a mapping of each of the letters of the alphabet to the letter it should correspond
              // to when we encrypt it.

char *encrypt(char *c);
void decrypt(char *c);
char *read_line(void);
bool is_substitution_key(int argc, char *argv[]);
bool text_is_all_alpha(char text[]);
int get_index(char letter);
bool letter_repeated(char letter, char *text);

int main(int argc, char *argv[])
{

    if (!is_substitution_key(argc, argv))
    {
        return 1;
    }
    else
    {
        strcpy(Key, argv[1]);
        // printf("Key is valid: %s\n", Key);
        printf("plaintext: ");
        char *plaintext = read_line();
        char *ciphertext = encrypt(plaintext);
        printf("ciphertext: %s\n", ciphertext);
        return 0;
    }
}

bool is_substitution_key(int argc, char *argv[])
{
    // check if the key is valid
    if (argc != 2 || !text_is_all_alpha(argv[1]))
    {
        printf("Usage: ./substitution key\n");
        return false;
    }
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return false;
    }
    else
    {
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            if (letter_repeated(argv[1][i], argv[1]))
            {
                // printf("Letter %c is repeated in the key.\n", argv[1][i]);
                printf("Key must not contain repeated characters.\n");
                return false;
            }
        }
    }
    return true;
}

char *read_line(void)
{
    char *buffer = NULL;
    size_t size = 0;
    size_t used = 0;

    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        if (used + 1 >= size)
        {
            size = size ? size * 2 : 16; // double buffer
            buffer = realloc(buffer, size);
            if (!buffer)
                return NULL;
        }
        buffer[used++] = c;
    }

    if (buffer)
        buffer[used] = '\0';
    return buffer;
}

bool text_is_all_alpha(char text[])
{
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (!isalpha(text[i]))
        {
            return false;
        }
    }
    return true;
}

int get_index(char letter)
{
    if (isupper(letter))
    {
        return letter - 'A';
    }
    else if (islower(letter))
    {
        return letter - 'a';
    }
    else
    {
        return -1; // not an alphabet
    }
}

char *encrypt(char *c)
{
    // eplacing every letter with another letter.  (l <- l + Key)
    char *ciphertext = malloc(strlen(c) + 1);
    // int indexs_array[strlen(c)];
    for (int i = 0; i <= strlen(c); i++)
    {
        if (isalpha(c[i]))
        {
            int index = get_index(c[i]);
            if (islower(c[i]))
            {
                ciphertext[i] = tolower(Key[index]);
            }
            else
            {
                ciphertext[i] = toupper(Key[index]);
            }
        }
        else
            ciphertext[i] = c[i];
    }
    return ciphertext;
}

void decrypt(char *c)
{
    // the receiver of the message would need to know the key, so that they can reverse the process:
    // translating the encrypt text (generally called ciphertext) back into the original message
    // (generally called plaintext).
    char *plaintext = c;
    strcpy(c, plaintext);
}

bool letter_repeated(char letter, char *text)
{
    int count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (toupper(text[i]) == toupper(letter))
        {
            // printf("Letter %c is repeated in the text in [%d].\n", letter, i);
            count++;
            if (count > 1)
            {
                return true;
            }
        }
    }
    // printf("Letter %c is not repeated in the text.\n", letter);
    return false;
}

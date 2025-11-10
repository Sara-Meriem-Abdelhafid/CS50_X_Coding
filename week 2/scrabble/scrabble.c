#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

const char alphabit[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const int alphabit_score[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int get_word_score(char word[]);
int get_letter_score(char letter);

int main(void)
{
    char word1[15];
    char word2[15];

    printf("Player 1: ");
    scanf("%s", word1);
    printf("Player 2: ");
    scanf("%s", word2);

    int word1_score = get_word_score(word1);
    int word2_score = get_word_score(word2);

    if (word1_score == word2_score)
    {
        printf("Tie!\n");
    }
    else if (word1_score > word2_score)
    {
        printf("Player 1 wins!\n");
    }
    else
    {
        printf("Player 2 wins!\n");
    }

    return 0;
}

int get_word_score(char word[])
{
    int score = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        score += get_letter_score(word[i]);
    }
    return score;
}

int get_letter_score(char letter)
{
    letter = toupper(letter);
    for (int i = 0; i < strlen(alphabit); i++)
    {
        if (letter == alphabit[i])
        {
            return alphabit_score[i];
        }
    }
    return 0;
}
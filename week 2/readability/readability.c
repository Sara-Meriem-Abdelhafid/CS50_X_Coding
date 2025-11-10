#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

char *read_line(void);
int calculate_words(char *text, int text_length);
int letter_count(char *text, int text_length);
int sentence_count(char *text, int text_length);     
float average_per_100(int count, int total_words);

int main(int argc, char *argv[])
{
    float grade =0.0;
    printf("Text: ");
    char *text = read_line();
    int text_length = strlen(text);
    int words_num = calculate_words(text, text_length);
    int letters_num = letter_count(text, text_length);
    int sentences_num = sentence_count(text, text_length);
    //printf("text length: %d\n", text_length);
    //printf("words number: %d\n", words_num);
    //printf("letters number: %d\n", letters_num);
    //printf("sentence number: %d\n", sentences_num);
    //index = 0.0588 * L - 0.296 * S - 15.8
    //L is the average number of letters per 100 words in the text
    //S is the average number of sentences per 100 words in the text
    float L = average_per_100(letters_num, words_num);
    float S = average_per_100(sentences_num, words_num);
    grade = (int)(0.0588 * L - 0.296 * S - 15.8 + 0.5); // +0.5 for rounding to nearest integer
    //printf("L: %.2f\n", L);
    //printf("S: %.2f\n", S);

    if(grade <=1)
    {
        printf("Before Grade 1\n");
    }
    else if(grade >16)
    {
        printf("Grade 16+\n");     
    }
    else
    {
        printf("Grade %d\n", (int)grade);
    }

 

    free(text);  // free memory
    return 0;
}


char *read_line(void) {
    char *buffer = NULL;
    size_t size = 0;
    size_t used = 0;

    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        if (used + 1 >= size) {
            size = size ? size * 2 : 16;  // double buffer
            buffer = realloc(buffer, size);
            if (!buffer) return NULL;
        }
        buffer[used++] = c;
    }

    if (buffer) buffer[used] = '\0';
    return buffer;
}

int calculate_words(char *text, int text_length)
{
    int words = 0;
    bool new_space = true;
 
    for (int i = 0; i < text_length; i++)
    {
        if (isspace(text[i]) && new_space)
        {
            new_space = false;
            words++;
        }
        else
        {
            new_space = true;
        }
    }
   
    return words + 1; // add 1 for the last word
}

int letter_count(char *text, int text_length)
{
    int letters = 0;
 
    for (int i = 0; i < text_length; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
   
    return letters;
}

int sentence_count(char *text, int text_length)
{
    int sentences = 0;
 
    for (int i = 0; i < text_length; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }
   
    return sentences;
}

float average_per_100(int count, int total_words)
{
    return ((float)count / (float)total_words) * 100.0;
}
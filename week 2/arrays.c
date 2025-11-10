#define _CRT_SECURE_NO_WARNINGS

//preprocessor directives
#include <stdio.h>
#include <string.h>
#include <ctype.h>
//constents
const int n =3;

//prototypes
float average(int length, int array[]);
void string_print(char string[]);
void string_modify_pointer_content(char *string, char new_content[]);

int main(void)
{
    //int score[n];
    char s[]="HI!"; //array of characters (string)
    char *t="BYE!"; //pointer to a string literal, t[i] is not modifiable (read-only)
    char strings[][5] = {"HI!", "BYE!"}; // declare the size of the strings 
    char *strings1[] = {"HI!", "BYE!"}; // array of pointers to string literals

    printf("Enter your name: ");
    char name[10];
    char *name_pointer;
    scanf("%s", name);
    name_pointer = name;
    printf("Your name's length: %llu\n", strlen(name));
    printf("Your name_pointer's length: %llu\n", strlen(name_pointer));

    string_print(name);
    string_print(name_pointer);
    string_modify_pointer_content(name, "Modified!");
    string_modify_pointer_content(name_pointer, "Modified!");
    printf("your name is now %s\n", name);
    printf("your name_pointer content is now %s\n", name_pointer);
    printf("Your name's length after modification: %llu\n", strlen(name));
    printf("Your name_pointer's length after modification: %llu\n", strlen(name_pointer));
    printf("strings1 length %llu\n", strlen(strings1));
    //printf("%c %c %c %i\n", s[0], s[1], s[2], s[3]);
    /*printf("%s\n", s);
    printf("%s\n", t);
    printf("%s\n", strings[0]);
    printf("%s\n", strings[1]);
    printf("%s\n", strings1[0]);
    printf("%s\n", strings1[1]);
    printf("lingth (%s)= %llu\n", s, strlen(s));
    printf("lingth (%s)= %llu\n", t, strlen(t));
    printf("lingth (%s)= %llu\n", strings[0], strlen(strings[0]));
    printf("lingth (%s)= %llu\n", strings[1], strlen(strings[1]));
    printf("lingth (%s)= %llu\n", strings1[0], strlen(strings1[0]));
    printf("lingth (%s)= %llu\n", strings1[1], strlen(strings1[1]));*/
    /*
    //printf("%i %i %i \n", c1, c2, c3);
    for (int i = 0; i < n; i++)
    {
        printf("Enter score %d: ", i + 1);
        scanf_s("%d", &score[i]);
    }

    printf("Average = %f \n", average(n, score));
    */
    return 0;
}

float average(int length, int array[]){
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += array[i];
    }
    return sum / (float) length;
}


void string_modify_pointer_content(char *string, char new_content[]){
    strcpy(string, new_content);
}

void string_print(char string[]){
    for (int i = 0, n=strlen(string); i < n; i++)
    {
        printf("%c", string[i]);
    }
    printf("\n");
}
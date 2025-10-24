#include <stdio.h>
#include <string.h>

int get_positive_input(void);
void print_pyramids(int tall);
void print_raw(int level, int tall);


int main(void)
{
    printf("Height: ");
    char tall = get_positive_input();
    print_pyramids(tall);
}

int get_positive_input(void)
{
    char input[10]; 
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    if(input[0]<'1' || input[0]>'8')
    {
        do{
            printf("Height: ");
            fgets(input, sizeof(input), stdin);
            input[strcspn(input, "\n")] = '\0';
        }while (input[0]<'1' || input[0]>'8' );
    }
    return input[0]-'0';
}

void print_raw(int level, int tall)
{
    for(int j=0; j<(tall-level); j++)
    {
        printf(" ");
    }
    for(int k=(tall-level); k<tall; k++)
    {
        printf("#");
    }
    printf("  ");
    for(int k=(tall-level); k<tall; k++)
    {
        printf("#");
    }
    for(int j=0; j<(tall-level); j++)
    {
        printf(" ");
    }
    printf("\n");
}

void print_pyramids(int tall)
{
    int l = 1;
    while (l <= tall)
    {
        print_raw( l, tall);
        l++;
    }
}


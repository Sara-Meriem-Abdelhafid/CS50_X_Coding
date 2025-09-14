#include <stdio.h>

int get_positive_input(void);
void print_pyramids(int tall);
void print_raw(int level, int tall);


int main(void)
{
    printf("Height: ");
    int tall = get_positive_input();
    //print_pyramids(tall);
}

int get_positive_input(void)
{
    char n; 

    scanf(" %c", &n);
    if(n<'1' || n>'8'){
    do{
        printf("\nentre a positive value between [1-8]: ");
        scanf(" %c", &n);
    }while (n<'1' || n>'8');
    }
    return n-'0';
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


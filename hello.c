/*
Commends to remembre
code hello.c      # CS50 commend to create a file
make hello        # compile the c code
./hello           # run hello.c file
ctrl + l          # clear terminal
\                 # alt + shift + : 
%c                # char
%s                # string
%i                # int 32 bits
%li               # lang "long int" 64 bits

%f                # flout
%?                # double

cd                # entre a folder
cp                # make a copy
ls                # show the content of direction as a list
mkdir             # create a folder
mv                # move a file to a folder "mv hello.c output".    or rename a file "mv hello.c old_hello.c".  move it back "mv hello.c .."
mr                # remove a file
mrdir             # remove a folder




to use the function printf we need a library which is inside the header file stdio.h "stander io", and to learn more about header files -> see the Manual Pages (documentation for C language) manual.cs50.io 

"say" in scratch = "printf" in c (why f at the end of print"f" because we print a format) 

check50 cs50/problems/2025/x/me           # to check the work’s correctness
style50 hello.c                           # to check the style
submit50 cs50/problems/2025/x/me          # to submit the solution

*/
#include <stdio.h>
#include <stdbool.h>
void meaw(int n);
int get_positive_input(void);
bool get_valid_bool(void);


int main(void)
{    
    const int col_num =3;
    char name[20];
    int accepted_age = 18, x, y, age, input, num=3;
    bool c;
    int dollars = 1;

    ///*
    printf("Hello world!\n");
    printf("what's your name: ");
    scanf("%s", name);
    printf("entre your age: ");
    scanf("%d", &age);
    if (age >= accepted_age)
    {
        printf("Hello! %s, your age is : %d  >= %d accepted\n", name, age, accepted_age);
    }
    else 
    {
        printf("Hello! %s, your age is : %d  < %d refused\n", name, age, accepted_age);
    }
    //* /


    //////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///*
    printf("do you wanna divide to numbers ?");
    //scanf(" %c", &c); //this space tells scanf to skip any whitespace before reading the character
    c = get_valid_bool();
    if (c == 1)
    {  
        printf("What's x : ");
        scanf("%d", &x);
        printf("What's y : ");
        scanf("%d", &y);
    
        if (x<y)
        {
            printf("%d is less then %d\n", x, y);
        }
        else if (x>y)
        {
            printf("%d is more then %d\n", x, y);
        }
        else
        {
            printf("%d is equal to %d\n", x, y);
        }
        printf("%.50f\n", (float)x/y);
    
    }
    //*/

    printf("How many times do you want to repeat : \n");
    input=get_positive_input();
    meaw(input);


    while (num > 0)
    {
        printf("meow?\n");
        num --;
    }


    for(int i= 0; i < col_num; i++)
    {
        printf("meow!\n");

    }

    /* while (true)
    {
        printf("meow :) \n");
    }*/


    while (true)
    {
        printf("Here's $%d, Double it and give it to the next person? ",dollars);
        bool ch = get_valid_bool(); 
        if (ch == 1)
        {
            dollars *= 2;
        }
        else
        {
            break;
        }
    }
    printf("Here's $%d Dollars\n", dollars);
    
}

int get_positive_input(void)
{
    int n;
    do{
        printf("entre a positive input : ");
        scanf("%d", &n);
    }while (n<1);

    return n;
}

bool get_valid_bool(void){
    char c;
    do
    {
        printf("(Y or y)-> Yes, (N or n)-> No : ");
        scanf(" %c", &c);
    }while (c!='Y' && c!='y' && c!='N' && c!='n');
    if(c=='Y' || c=='y' ){return 1;}
    else if(c=='N' || c=='n' ){return 0;}

}

void meaw(int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("meow :) \n");
    }
}
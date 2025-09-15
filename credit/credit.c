/*
-AMEX\n : All American Express numbers start with 34 or 37; uses 15-digit numbers 
-MASTERCARD\n : Some MasterCard numbers start with 51, 52, 53, 54, or 55 (they also have some other potential starting numbers which we won’t concern ourselves with for this problem);  16-digit numbers,  
-VISA\n : All Visa numbers start with 4. Visa uses 13- and 16-digit numbers

INVALID\n : !=  {
    Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
    Add the sum to the sum of the digits that weren’t multiplied by 2.
    If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!}
*/

#include <stdio.h>
#include <string.h>

char* get_card_num(void);
void valid_card(char* num);

int main(void)
{
    char* num = get_card_num();
    printf("%s\n", num);
    int len= strlen(num);
    printf("len outside : %d \n", len);


    valid_card(num);
}


char* get_card_num(void)
{
    char input[25]; 

        do{
            printf("Number: ");
            fgets(input, sizeof(input), stdin);
            input[strcspn(input, "\n")] = '\0';
        }while (strlen(input)!=13 && strlen(input)!=15 && strlen(input)!=16 );//strlen(input)<13 || strlen(input)>16 || strlen(input)==14
    printf("input %s\n", input);
    printf("len inside %d\n", strlen(input));


    return input;
}

void valid_card(char* num){
    int len= strlen(num);
    printf("%s\n", num);
    printf("len outside : %d \n", len);

}
/*
4003-6000-0000-0014
foo
6176292929
4003600000000014
*/
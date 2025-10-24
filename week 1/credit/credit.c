/*
-AMEX\n : All American Express numbers start with 34 or 37; uses 15-digit numbers
-MASTERCARD\n : Some MasterCard numbers start with 51, 52, 53, 54, or 55 (they also have some other potential starting numbers which we won’t concern ourselves with for this problem);  16-digit numbers,
-VISA\n : All Visa numbers start with 4. Visa uses 13- and 16-digit numbers

INVALID\n : !=  {
    Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
    Add the sum to the sum of the digits that weren’t multiplied by 2.
    If the total’s last digit is 0 (or, put more formally, if the  total modulo 10 is congruent to 0), the number is valid!}
    */

#include <stdio.h>
#include <string.h>
#include <ctype.h>  // for isdigit()
#include <stdbool.h>


char* get_card_num(void);
int valid_card(char* num);
bool all_digits(char* num);
bool confirm_valid_card(char* num);

int main(void)
{
    char* num = get_card_num();
    //printf("%s\n", num);
    //int len= strlen(num);
    //printf("len outside : %d \n", len);


    //valid_card(num);
}


char* get_card_num(void)
{
    int valid ;
    static char input[25];
        do{
            printf("Number: ");
            fgets(input, sizeof(input), stdin);
            input[strcspn(input, "\n")] = '\0';
            //valid = valid_card(input);
        }while (valid_card(input)== -1 || ( strlen(input)!=13 && strlen(input)!=15 && strlen(input)!=16));//strlen(input)<13 || strlen(input)>16 || strlen(input)==14
    //printf("input %s\n", input);
    //printf("len inside %lu\n", strlen(input));

    return input;
}

int valid_card(char* num){
    int len= strlen(num);
    int type = 10;
    //printf("all_digits(num) = %d\n", all_digits(num));


    if(all_digits(num)==1)
    {   //printf("strlen(num) = %lu\n", strlen(num));
        //printf("num[0] = %c\n", num[0]);
        //printf("num[1] = %c\n", num[1]);

        if(strlen(num)== 13)
        {   //printf("strlen(num) = %lu\n", strlen(num));

            if(num[0] == '4')
            {

                if(confirm_valid_card(num)==1)
                {
                    //printf("num[0] = %c\n", num[0]);
                    //VISA\n
                    printf("VISA\n");
                    //printf("function returns = %d\n", 1);
                    type = 1;
                }
                else
                {
                    printf("INVALID\n");
                    //printf("function returns = %d\n", 0);
                    type = 0;
                }
            }
            else
            {
                printf("INVALID\n");
                //printf("function returns = %d\n", 0);
                type = 0;
            }
        }
        else if(strlen(num)== 15)
        {
            //printf("strlen(num) = %lu\n", strlen(num));

            if(num[0] == '3' && (num[1] == '4'|| num[1] == '7'))
            {

                if(confirm_valid_card(num)==1)
                {
                    //printf("num[0] = %c\n", num[0]);
                    //printf("num[1] = %c\n", num[1]);
                    //AMEX\n
                    printf("AMEX\n");
                    //printf("function returns = %d\n", 3);
                    type = 3;
                }
                else
                {
                    printf("INVALID\n");
                    //printf("function returns = %d\n", 0);
                    type = 0;
                }


            }
            else
            {
                printf("INVALID\n");
                //printf("function returns = %d\n", 0);
                type = 0;
            }
        }
        else if(strlen(num) == 16)
        {
            //printf("strlen(num) = %lu\n", strlen(num));

            if(num[0] == '4')
            {
                //printf("num[0] = %c\n", num[0]);
                //VISA\n
                if(confirm_valid_card(num)==1)
                {
                    printf("VISA\n");
                    //printf("function returns = %d\n", 1);
                    type = 1;
                }
                else
                {
                    printf("INVALID\n");
                    //printf("function returns = %d\n", 0);
                    type = 0;
                }
            }
            else if(num[0] == '5' && (num[1] == '1' || num[1] == '2' || num[1] == '3' || num[1] == '4' || num[1] == '5'))
            {
                //printf("num[0] = %c\n", num[0]);
                //printf("num[1] = %c\n", num[1]);
                //MASTERCARD\n
                if(confirm_valid_card(num)==1)
                {
                    printf("MASTERCARD\n");
                    //printf("function returns = %d\n", 2);
                    type = 2;
                }
                else
                {
                    printf("INVALID\n");
                    //printf("function returns = %d\n", 0);
                    type = 0;
                }

            }
            else
            {
                printf("INVALID\n");
                //printf("function returns = %d\n", 0);
                type = 0;
            }

        }
        else
        {
            printf("INVALID\n");
            //printf("function returns = %d\n", 0);
            type = 0;
        }
    }
    else
    {
        //printf("function returns = %d\n", -1);
        type = -1;
    }
    //printf("function returns = %d\n", type);
    return type;
}

bool all_digits(char* num){
    int len= strlen(num);
    int i=0;
    //printf("%s\n", num);
    //printf("len outside : %d \n", len);
    while(i < len){
        if(isdigit(num[i])){
            i++;
        }
        else{
            return 0;
        }
    }
    return 1;
}

/*
4003-6000-0000-0014
foo
6176292929
4003600000000014
378282246310005
*/
/*int card_types(char* num){
    if(strlen(num)== 13)
    {
        else if(num[0] == 4)
        {
            //VISA\n
            printf("VISA\n");

        }
    }
    else if(strlen(num)== 15)
    {
        if(num[0] == 3 && (num[1] == 4 || num[1] == 7))
        {
            //AMEX\n
            printf("AMEX\n");

        }
    }
    else if(strlen(num)== 16)
    {
        if(num[0] == 5 && (num[1] == 1 || num[1] == 2 || num[1] == 3 || num[1] == 4 || num[1] == 5))
        {
            //MASTERCARD\n
            printf("MASTERCARD\n");

        }
        else if(num[0] == 4)
        {
            //VISA\n
            printf("VISA\n");

        }

    }



}*/

bool confirm_valid_card (char* num){
    int other_mult_2, sum_digits=0, total_sum=0;
    int len = strlen(num);
    //printf("len = %lu \n",strlen(num));

    int i=len-2;
    int j = len-1;
    while (i >= 0)
    {
        other_mult_2 = (num[i]-'0')*2;
        //printf(" %d * 2 + ", num[i]-'0' );

        if(other_mult_2 < 10) // if the result of the num multiplicated by 2 = 1 digit
        {
            sum_digits = sum_digits + other_mult_2;
        }
        else  //if the result of the num multiplicated by 2 = 2 digit
        {
            sum_digits += other_mult_2 / 10; // first digit
            sum_digits += other_mult_2 % 10; // second digit

        }
        i=i-2;
    }
    total_sum = sum_digits;
    //printf("\ntotal sum = %d\n", total_sum);

    while (j > 0)
    {
        total_sum = total_sum + (num[j]-'0');
        //printf(" + %d ", num[j]-'0');
        j=j-2;
    }
    //printf("\ntotal sum = %d\n", total_sum);

    if (total_sum % 10 == 0) {return 1;}
    else {return 0;}

}

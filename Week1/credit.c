#include <stdio.h>
#include <cs50.h>

int checkValid(long number);
string checkProvider(long number);

int main(void)
{
    int checkSum;
    string provider;
    long creditCard = get_long("Enter credit card number: ");
    checkSum = checkValid(creditCard);
    //printf("checksum: %i\n", checkSum);
    if (checkSum == 1)
    {
        provider = checkProvider(creditCard);
        printf("%s\n", provider);
    }
    else 
    {
        printf("INVALID\n");
    }
}

int checkValid(long number)
{
    int digit;
    int sum1 = 0; //for second to last digits
    int sum2 = 0; //for last digits
    while (true)
    {
        digit = ((number % 100) / 10); //step 1 get second to last digit and every other digit backwards
        //printf("card number left: %ld\ncurrent digit1: %i\n", number, digit);
        if ((digit * 2) >= 10) //to add those products digits
        {
            sum1 = sum1 + ((digit * 2) / 10) + ((digit * 2) % 10);
        }
        else 
        {
            sum1 = sum1 + (digit * 2);
        }

        digit = ((number % 100) % 10); //get last digits
        //printf("card number left: %ld\ncurrent digit2: %i", number, digit);
        sum2 = sum2 + digit;

        number = number / 100;
        if (number == 0)
        {
            break;
        }
    }
    //printf("sum1: %i\n", sum1);
    //printf("sum2: %i\n", sum2);
    if ((sum1 + sum2) % 10 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

string checkProvider(long number)
{
    int numCount = 0;
    long first = number;
    int second;

    while (first >= 10) //get first and second digit
    {
        first = first / 10;
        if (first >= 10)
        {
            second = first % 10;
        }
    }
    while (number > 0)
    {
        number = number / 10;
        numCount++;
    }
    //printf("numbers on card: %i\nfirst: %ld\nsecond: %i\n", numCount, first, second);
    if (numCount == 15 && (first == 3 && (second == 4 || second == 7))) //check AMEX
    {
        return "AMEX";
    } 
    if (numCount == 16 && (first == 5 && (second == 1 || second == 2 || second == 3 || second == 4 || second == 5))) //check MASTERCARD
    {
        return "MASTERCARD";
    } 
    if ((numCount == 13 || numCount == 16) && (first == 4)) //check VISA
    {
        return "VISA";
    } 
    return "INVALID";
}

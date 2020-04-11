#include <cs50.h>
#include <stdio.h>

void createSpace(int n);
void createBlocks(int n);

int main(void)
{
    int num;
    //ask for input between 1 to 8
    do
    {
        num = get_int("How high do you want the pyramids to be?\n");
    } 
    while (num < 1 || num > 8);

    for (int i = 0; i < num; i++) 
    {
        createSpace(num - 1 - i); //print spaces
        createBlocks(i + 1); // print blocks
        createSpace(2); //print gap
        createBlocks(i + 1); //print blocks
        //createSpace(num - 1 - i); // print spaces, but the submission doesn't want this
        printf("\n"); //go to new line for next iteration
    }
}

void createSpace(int n) //use void if function doesn't return anything
{ 
    for (int i = 0; i < n; i++) 
    {
        printf(" ");
    }
}

void createBlocks(int n) //use void if function doesn't return anything
{ 
    for (int i = 0; i < n; i++) 
    {
        printf("#");
    }
}

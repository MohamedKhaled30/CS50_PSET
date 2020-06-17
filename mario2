#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int count = 1 ; 
    int height ;
    //prompt user to enter an int value between 1 and 8 
    do

    {
        height = get_int("height: ");
    }
     while(height < 1 || height > 8);
    for(int i = 0 ; i < height ; i++)
    {
        for(int j = 0 ; j < height ; j++)
        {
            if(j>=height - count)
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }
        count++;
        printf("  ");
        for(int k = 0 ; k < height ; k++)
        {
            if(k <= i)
            {
                printf("#");
            }
        }
        printf("\n");
    }

}

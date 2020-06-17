#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //initial value for height
    int height = 0;
    //this is used to count number of # necessary for each line
    int count = 1;
    //prompt user to enter value between 1 & 8
    do{
     height = get_int("Height : ");
    }
    while(height < 1 || height > 8);
    for(int i = 0 ; i < height ; i++ )
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
        printf("\n");
        count++;
        }
    
}

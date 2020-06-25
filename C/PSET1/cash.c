#include<cs50.h>
#include<stdio.h>
#include <math.h>
int main(void)
{
    
    float input;
    //prompt user for input
    do{
        input = get_float("input: ");
    }while(input<0);
    //convert from float to int 
    int coins = round(input * 100)  ;    
    
    int output = 0;
    //calculate output
    while(coins>0)
    {
        if((coins / 25) > 0) 
        {
            coins -= 25;
            output++;
        }
        else if((coins / 10) > 0)
        {
            coins -= 10;
            output++;
        }
        else if((coins / 5) > 0)
        {
            coins -= 5;
            output++;
        }
        else
        {
            coins -= 1;
            output++;
        }
        
    }

printf("%d\n",output);
}

#include<cs50.h>
#include <stdio.h>

int main(void)
{
    //prompt the user to enter his name
    string name = get_string("Whats your name?\n");
    //print out hello and his name
    printf("hello, %s\n", name);
}

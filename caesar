#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int main(int argc, string argv[])
{

    int key = 0;
    string p;
    
    
    if (argc != 2)
    {
        printf("Usage: %s Key", argv[0]);
        return 1 ;
    }

    if (argc != 2 && !(isdigit(argv[1]))  && atoi(argv[1]) < 0)
    {
        printf("Usage: %s Key", argv[0]);
        return 1 ;
    }
    else
    {
        //to check that itsn't start with a digit then an alpha
        for (int i = 0 ; i < strlen(argv[1]) ; i++)
        {
            if (!(isdigit(argv[1][i])))
            {
                printf("Usage: %s Key\n", argv[0]);
                return 1 ;
            }
            else if (argv[1][i] == ' ')
            {
                printf("Usage: %s Key\n", argv[0]);
                return 1 ;
            }
        }

        //convert key from string to int
        key = atoi(argv[1]);
    }

    // get user plaintext
    p = get_string("plaintext: ");

    // cesar algorithm
    for (int i = 0, j = strlen(p); i < j; i++)
    {
        // for lowercase letters
        if (p[i] >= 'a' && p[i] <= 'z')
        {
            p[i] = (p[i] - 'a' + key) % 26 + 97;
        }

        // for uppercase letters
        else if (p[i] >= 'A' && p[i] <= 'Z')
        {
            p[i] = (p[i] - 'A' + key) % 26 + 65;
        }

    }
    //print the output ciphertext
    printf("ciphertext: %s\n", p);
 

    // No errors exist!
    return 0;


}

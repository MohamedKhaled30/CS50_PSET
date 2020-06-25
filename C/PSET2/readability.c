#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main(void)
{
    //initialize my counters
    int letter = 0 ;
    int word = 0 ;
    int sentence = 0;
    //prompt user to input the text
    string text = get_string("Text: ");

    for (int i = 0, j = strlen(text); i < j ; i++)
    {
        //calculate the letters
        if (isalpha(text[i]))
        {
            letter++;
        }
        //calculate the words
        if (isalpha(text[i]) && !isalpha(text[i + 1]))
        {
            if (text[i + 1] != '-')
            {
                if (text[i + 1] != '\'')
                {
                    word++;
                }

            }
        }
        //calculate the sentences
        if (text[i] == '?' || text[i] == '!' || text[i] == '.')
        {
            sentence++;
        }
    }
    float L, S ;
    //calculate L and S
    L = ((float)letter * 100) / word;
    S = ((float)sentence *  100) / word;

    float index = round((0.0588 * L) - (0.296 * S) - 15.8);
    //if before grades
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    //if master or above
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    //normal case
    else
    {
        printf("Grade %i\n", (int)index);
    }

}

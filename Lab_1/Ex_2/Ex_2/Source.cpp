/*
    --------------------------------------------Condition:--------------------------------------------------------

    Write a program in C - Language that open the file "in.txt", and prints the sum of the numbers that are found
    on each line of the file in.txt.To open the file use fopen API.Write your own function that converts a string
    to a number(similar cu atoi API). To print something to the screen, use the printf API.

    Example: let's consider the following "ini.txt" file:

    123
    198698
    5009
    983279

    The program will print to the screen 1187109.
*/

#include <iostream>

using namespace std;

int main()
{
    FILE* file;
    file = fopen("ini.txt", "r");

    char line[200];
    int len;
    int number;
    int sum = 0;
    bool isNum;

    if (file)
    {
        while (fgets(line, sizeof line, file))
        {
            number = 0;
            isNum = true;
            len = (int)strlen(line);
            if (len)
            {
                if (line[len - 1] == '\n')
                    len--;
                for (int i = 0; i < len && isNum; i++)
                {
                    switch (line[i])
                    {
                    case '0':
                        break;
                    case '1':
                        number += pow(10, len - i - 1);
                        break;
                    case '2':
                        number += 2 * pow(10, len - i - 1);
                        break;
                    case '3':
                        number += 3 * pow(10, len - i - 1);
                        break;
                    case '4':
                        number += 4 * pow(10, len - i - 1);
                        break;
                    case '5':
                        number += 5 * pow(10, len - i - 1);
                        break;
                    case '6':
                        number += 6 * pow(10, len - i - 1);
                        break;
                    case '7':
                        number += 7 * pow(10, len - i - 1);
                        break;
                    case '8':
                        number += 8 * pow(10, len - i - 1);
                        break;
                    case '9':
                        number += 9 * pow(10, len - i - 1);
                        break;
                    default:
                        printf("%s", "The text written doesn't represent a number!\n");
                        isNum = false;
                        break;
                    }
                }
                if (isNum)
                    sum += number;
            }                
        }
        printf("%i", sum);
        fclose(file);
    }
    else
    {
        printf("%s", "The file doesn't exist!");
    }
}
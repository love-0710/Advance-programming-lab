//WAP to separate  all the tokens in a given expression. the expressions should be given at run time


#include <stdio.h>

int main()
{
    char expression[100];
    char tokens[100];
    int counter = 0;
    printf("Enter the expression: ");
    scanf("%s", expression);
    printf("The tokens in the expression are: \n");
    for (int i = 0; expression[i] != '\0'; i++)
    {
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/' || (expression[i] >= '0' && expression[i] <= '9'))
        {
            printf("%c ", expression[i]);
        }
        else
        {
            tokens[counter] = expression[i];
            counter++;
        }
    }
    tokens[counter++] = '\0';
    printf("\nThe expressions are : \n");
    for (int i = 0; tokens[i] != '\0'; i++)
    {
        printf("%c ", tokens[i]);
    }

    //file handling
    FILE *filePointer ; 

    filePointer = fopen("new.txt", "w");
    fprintf(filePointer, "The expressions are : %s\n",tokens);
    fprintf(filePointer, "The tokens are : %s", expression);
    return 0;
}

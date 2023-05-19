#include<stdio.h>
int main()
{
        char expression[100];
        char tokens[100];
        int counter=0;
//      FILE *filepointer;
        printf("Enter the  expression: \n ");
        scanf("%s", expression);
//      filepointer=fopen("new1.txt", "r");
//      fscanf(filepointer, expression );
        printf("The tokens in the expression are: \n");

                for(int i=0; expression[i]!='\0'; i++)
                {
                        if(expression[i]=='+'||expression[i]=='-' ||expression[i]=='*' ||expression[i]=='/' ||expression[i]=='=' || (expression[i]>=0 && expression[i]<=9))
                        {
                                printf("%c ", expression[i]);
                        }
                        else
                        {
                                tokens[counter]=expression[i];
                                counter++;
                        }
                }
                tokens[counter++]='\0';
                printf("\nThe expressions are :\n");
                for(int i=0; tokens[i]!='\0'; i++)
                {
                        printf("%c " , tokens[i]);
                }

                //file handling
                        FILE *filepointer;
                        filepointer=fopen("new.txt", "w");
                        fprintf(filepointer, "The expression are : %s\n", expression);
                        fprintf(filepointer, "The tokens are : %s", tokens);


  return 0;
}





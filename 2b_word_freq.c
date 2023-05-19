#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max_words 1000
int main()
{
        char input[1000], *words[max_words];
        int i, word_count=0, word_freq[max_words]={0};
        printf("Enter a paragraph:\n");
        gets(input);

        char *token=stroke(input, " ");
        while(token!=NULL)
        {
                words[word_count]=token;
                word_count++;
                token=strtok(NULL, " ");
        }

}




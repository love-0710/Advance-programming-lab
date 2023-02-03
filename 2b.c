// WAP to read a paragraph from the user and count the frequency of each word present in the paragraph

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 100

int main() {
    char input[1000], *words[MAX_WORDS];
    int i, word_count = 0, word_freq[MAX_WORDS] = {0};

    printf("Enter a paragraph: ");
    gets(input);

    // Tokenize the input into words
    char *token = strtok(input, " ");
    while (token != NULL) {
        words[word_count] = token;
        word_count++;
        token = strtok(NULL, " ");
    }

    // Count the frequency of each word
    for (i = 0; i < word_count; i++) {
        int j;
        for (j = 0; j < word_count; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                word_freq[i]++;
            }
        }
    }

    // Print the frequency of each word
    for (i = 0; i < word_count; i++) {
        if (word_freq[i] > 0) {
            printf("%s: %d\n", words[i], word_freq[i]);
        }
    }

    return 0;
}

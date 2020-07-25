/* 문자열과 포인터*/
#include <stdio.h>

int size_of_string(char word[]);
int main() {
    char word[30] = {"long sentence"};
    char *str = word;

    printf("%s \n", str);
    printf("문자열 길이 : %d \n", size_of_string(str));

    return 0;
}

// int size_of_string(char *word) {
int size_of_string(char word[]) {
    int size=0;
    int i=0;

    while (1) {
        if (word[i] == 0) {
            return size;
        }
        size++;
        i++;
    }
}
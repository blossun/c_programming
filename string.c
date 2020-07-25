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
    int i=0;

    while (word[i]) { //str[i] 가 0 이 될 때 까지 i 의 값을 계속 증가
        i++;
    }

    //str[i]가 0이면 null을 만난 것
    return i; //i : 맨 마지막의 NULL 문자를 제외한 나머지 문자들의 총 개수
}
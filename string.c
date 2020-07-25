/* 문자열 리터럴과 문자 배열*/
#include <stdio.h>

int main() {
    char *p_str = "abcdefgh";
    char str_array[] = {"qwerasdf"};
    printf("%s \n", p_str);
    printf("%s \n", str_array);


    // p_str[0] = 'x';
    str_array[0] = 'x';
    printf("%s \n", p_str);
    printf("%s \n", str_array);

    return 0;
}

/* 디버그 */
#include <stdio.h>

int main()
{
    char arr[10];
    // int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int i;

    for (i=0; i<10; i++) 
    {
        printf("\n입력 : ");
        scanf("%s", &arr[i]); //%d 뒤에 공백을 넣으면 11번쨰까지 입력을 받네,,,, 왜지?
    }

    for (i=0; i<=10; i++) {
        printf("%d \n", arr[i]);
    }
    return 0;
    
}
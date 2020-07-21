#include <stdio.h>

int main() {
    /* 비트 연산 */
    int a = 0xAF; // 10101111
    int b = 0xB5; // 10110101

    printf("%x \n", a & b);  // a & b = 10100101
    printf("%x \n", a | b);  // a | b =10111111
    printf("%x \n", a ^ b);  // a ^ b = 00011010
    printf("%x \n", ~a);     // ~a = 1....1 01010000
    printf("%x \n", a << 2); // a << 2 = 1010111100
    printf("%x \n", b >> 3); // b >> 3 = 00010110

    int c = 10;
    printf("c << 1 : %d \n", c << 1); // c * 2^1 //20 : 00010100
    printf("c << 2 : %d \n", c << 2); // c * 2^2 //40 : 00101000
    printf("c << 3 : %d \n", c << 3); // c * 2^3 //80 : 01010000
    printf("c << 4 : %d \n", c << 4); // c * 2^4 //160 : 10100000
    printf("c << 5 : %d \n", c << 5); // c * 2^5 //320 : (1)01000000
    printf("c >> 3 : %d \n", c >> 1); // c / 2^1 //5
    printf("c >> 3 : %d \n", c >> 2); // c / 2^2 //2
    printf("c >> 3 : %d \n", c >> 3); // c / 2^3 //1
    printf("c >> 4 : %d \n", c >> 4); // c / 2^4 //0
    printf("c >> 5 : %d \n", c >> 5); // c / 2^5 //0
    return 0;
}
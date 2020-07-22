/* 과목 평균 구하기 */
#include <stdio.h>
int main() {
    int i;
    int subject, score;
    double totalScore;

    printf("과목 수 입력 : ");
    scanf("%d", &subject);

    for (i=0; i<subject; i++) {
        printf("과목%d : ", i+1);
        scanf("%d", &score);
        totalScore += score;
    }

    printf("평균 : %.2f \n", totalScore/subject);

    return 0;
}
/* 배열 */
// 각 학생들의 성적들을 입력받아서 평균 보다 낮은 사람들의 번호 옆에 '불합격', 
// 평균 이상의 사람들에게 '합격' 이라는 메세지 까지 출력
#include <stdio.h>
int main() {
    int score[10];
    int sum = 0;
    int avg;

    for (int i=0; i<10; i++) {
        printf("%d번쨰 학생 점수 : ", i+1);
        scanf("%d", &score[i]); //&(score[i]) 라고 안해도 된다.
        sum += score[i];
    }

    avg = sum / 10; //size를 따로 구할 수 없음...?

    for (int i=0; i<10; i++) {
        printf("학생 %d : ", i+1);
        if (score[i] >= avg) {
            printf("합격 \n");
        } else {
            printf("불합격 \n");
        }
    }

    return 0;
}
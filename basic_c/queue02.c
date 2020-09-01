// 원형 큐
#include <stdio.h>
#include <stdbool.h>

const int MAX_SIZE = 10;

int selectNumber(void);
void add(int* rear, int* size, int queue[]);
void pop(int* front, int* size);
void display(int front, int size, int queue[]);
void nextIndex(int* pointer);

int main(void)
{
    bool flag = true;
    int queue[MAX_SIZE];
    int front = 0, rear = 0, size = 0;
    
    while (flag)
    {
        int n = selectNumber();
        switch(n)
        {
            case 1:
                add(&rear, &size, queue);
                break;
            case 2:
                pop(&front, &size);
                break;
            case 3:
                display(front, size, queue);
                break;
            case 4:
                flag = false;
                break;
            default:
                printf("다시 입력해주세요.\n");
        }
    }
    
    return 0;
}

int selectNumber(void)
{
    int input = 0;
    
    printf("(1) add, (2) pop, (3) display, (4) quit\n");
    printf("선택: ");
    scanf("%d", &input);
    
    return input;
}

void add(int* rear, int* size, int queue[])
{
    // 만약 Queue가 가득 찼다면
    if (*size >= MAX_SIZE)
    {
        printf("Queue가 꽉 찼습니다.\n");
        return;
    }
    
    int data = 0;
    
    printf("숫자: ");
    scanf("%d", &data);
    
    // 입력받은 숫자를 Queue에 삽입
    queue[(*rear)++] = data;
    
    // rear가 배열 끝을 넘어서면 0으로 리셋한다.
    nextIndex(rear);
    (*size)++;
}

void pop(int* front, int* size)
{
    // 만약 Queue가 비었다면
    if (*size <= 0)
    {
        printf("Queue가 비었습니다.\n");
        return;
    }
    
    // 원형 큐이므로 굳이 배열의 값을 변경할 필요없이 front만 다음 인덱스로 이동시킨다.
    (*front)++;

    // front가 배열 끝을 넘어서면 0으로 리셋한다.
    nextIndex(front);
    (*size)--;
}

void display(int front, int size, int queue[])
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", queue[(front + i) % MAX_SIZE]);
    }
    printf("\n");
}

void nextIndex(int* pointer)
{
    if (*pointer == MAX_SIZE)
    {
        *pointer = 0;
    }
}
/* 큐(Queue) 원형 배열 */
#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define QUE_LEN 10

typedef struct Queue {
    int arr[QUE_LEN];
    int front;
    int rear;
} Queue;

void QInit(Queue *pqueue) {
    pqueue->front = 0;
    pqueue->rear = 0;
}

int QIsEmpty(Queue *pqueue) {
    return pqueue->front == pqueue->rear;
}

int NextPosIdx(int pos) {
    if (pos == QUE_LEN-1) {
        return 0;
    } else {
        return pos+1;
    }
}

int insert(Queue *pqueue, int *order) {
    if (NextPosIdx(pqueue->rear) == pqueue->front) {
        printf("Queue가 꽉 찼습니다.\n");
        return 1;
    }

    pqueue->rear = NextPosIdx(pqueue->rear);
    pqueue->arr[pqueue->rear] = *order;

    printf("순서 : %d번 대기 \n", *order);
    (*order)++;
    return 0;
}

int delete(Queue *pqueue) {
    if (QIsEmpty(pqueue)) {
        printf("Queue가 비었습니다.\n");
        return -1;
    }

    pqueue->front = NextPosIdx(pqueue->front);
    return pqueue->arr[pqueue->front];
}

int display(Queue *pqueue) {
    int start = pqueue->front+1;
    if (QIsEmpty(pqueue)) {
        printf("Queue가 비었습니다.\n");
        return 1;
    }
    while (TRUE) {
        printf("%d ", pqueue->arr[start]);
        if (start == pqueue->rear) {
            break;
        }
        start = NextPosIdx(start);
    }

    printf("\n");

    return 0;
}

int main(void) {
    Queue queue;
    QInit(&queue);

    int choice;
    int order = 1;
    int data;

    while(TRUE) {
        printf("(1)add (2)pop (3)display (4)quit 선택 : ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                insert(&queue, &order);
                break;
            case 2:
                data = delete(&queue);
                if (data != -1) {
                    printf("%d 호출 \n", data);
                }
                break;
            case 3:
                display(&queue);
                break;
            case 4:
                return 0;
            default:
                continue;
        }
    }

    return 0;
}
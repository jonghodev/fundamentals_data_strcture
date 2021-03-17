// Circular Queue
// 메모리 공간을 계속 사용할 수 있다.

// 처음에 Front Rear 는 같은 곳을 바라본다.
// Enqueue 될 때마다 Rear 가 증가한다.
// 이때 데이터를 꽉채우지 않고
// 전체 길이 - 1 일 때 꽉찼다고 본다.
// 이렇게 해야지, Front Rear 가 같은 위치에 있을 때 빈 값이고
// Rear 가 Front 뒤에 있을 때, 즉 Rear 가 Front 를 가리킬 때 데이터가 꽉찼다라는 걸 알 수 있다.

#ifndef CircularQueue_h
#define CircularQueue_h

#define TRUE 1
#define FALSE 0

#define QUE_LEN 100

typedef int Data;

typedef struct _cQueue
{
    int front;
    int rear;
    Data queArr[QUE_LEN];
} CQueue;

typedef CQueue Queue;

void QueueInit(Queue *pq);
int QIsEmpty(Queue *pq);

void Enqueue(Queue *pq, Data data);
Data Dequeue(Queue *pq);

Data QPeek(Queue *pq);

#endif

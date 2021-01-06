#ifndef CLinkedList_h
#define CLinkedList_h

# define TRUE 1
# define FALSE 0

typedef int LData;

typedef struct _node
{
    LData data;
    struct _node * next;
} Node;

typedef struct _linkedlist
{
    Node * tail;
    Node * cur;
    Node * before;
    int numOfData;
    int (*comp)(LData d1, LData d2);
} LinkedList;

typedef LinkedList List;

void ListInit(List *plist);
void LInsert(List *plist, LData data);
void LInsertFront(List *plist, LData data);

int LFirst(List *plist, LData * pdata);
int LNext(List *plist, LData * pdata);

LData LRemove(List *plist);
int LCount(List *plist);

#endif


/**
 circular linked list 에서 head 가 아니라 tail 을 두는 이유
 head 와 tail 에 모두 추가할 때 용이하기 때문이다.
 만약 head 만 있다면 데이터를 tail 에 추가하기 위해서 o(n) 의 복잡도가 요구 된다.
 그런데 tail 을 두면
 tail 에 추가하기 위해선 tail 에 넣으면 되고
 head 에 넣기 위해선 tail->next 를 참조하면 되니 모두 o(1) 의 접근시간에서 해결된다.
 */

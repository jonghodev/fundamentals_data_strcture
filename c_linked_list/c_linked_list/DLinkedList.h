#ifndef DLinkedList_h
#define DLinkedList_h

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
    Node * head;
    Node * cur;
    Node * before;
    int numOfData;
    int (*comp)(LData d1, LData d2);
} LinkedList;

typedef LinkedList List;

void ListInit(List *plist);
void LInsert(List *plist, LData data);

int LFirst(List *plist, LData * pdata);
int LNext(List *plist, LData * pdata);

LData LRemove(List *plist);
int LCount(List *plist);

void SetSortRule(List *plist, int (*comp)(LData d1, LData d2));

#endif

/**
 before 을 두는 이유
 데이터를 삭제하기 위해선 삭제 후 이전 노드를 참조해야 한다.
 만약 before 가 없다면 그 이전 노드를 참조하기 위한  o(n) 의 복잡도가 존재한다.
 */

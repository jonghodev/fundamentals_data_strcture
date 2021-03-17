#include "Heap.h"

void HeapInit(Heap *ph, PriorityComp *comp)
{
    ph->numOfData = 0;
    ph->com = comp;
}

int HIsEmpty(Heap *ph)
{
    if (ph->numOfData == 0)
        return TRUE;
    else
        return FALSE;
}


int GetParentIdx(int idx)
{
    return idx / 2;
}

int GetLChildIdx(int idx)
{
    return idx * 2;
}

int GetRChildIdx(int idx)
{
    return GetLChildIdx(idx) + 1;
}

int GetHiPriChildIdx(Heap *ph, int idx)
{
    if (GetLChildIdx(idx) > ph->numOfData)
        return 0;
    
    else if (GetLChildIdx(idx) == ph->numOfData)
        return GetLChildIdx(idx);
    else
        if (ph->com(ph->heapArr[GetLChildIdx(idx)], ph->heapArr[GetRChildIdx(idx)]) < 0)
            return GetRChildIdx(idx);
        else
            return GetLChildIdx(idx);
}



void HInsert(Heap *ph, HData data)
{
    int idx = ph->numOfData + 1;
    
    while(idx != 1)
    {
        if (ph->com(data, ph->heapArr[GetParentIdx(idx)]) > 0)
        {
            ph->heapArr[idx] = ph->heapArr[GetParentIdx(idx)];
            idx = GetParentIdx(idx);
        }
        else
            break;
    }
    
    ph->heapArr[idx] = data;
    ph->numOfData++;
}

HData HDelete(Heap *ph)
{
    HData retData = ph->heapArr[1];
    HData lastElem = ph->heapArr[ph->numOfData];
    
    int parentIdx = 1;
    int childIndex;
    
    
    while (childIndex = GetHiPriChildIdx(ph, parentIdx))
    {
        if (ph->com(lastElem, ph->heapArr[childIndex]) >= 0)
            break;
        
        ph->heapArr[parentIdx] = ph->heapArr[childIndex];
        parentIdx = childIndex;
    }
    
    ph->heapArr[parentIdx] = lastElem;
    ph->numOfData -= 1;
    
    return retData;
}


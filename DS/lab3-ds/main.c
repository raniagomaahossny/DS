#include <stdio.h>
#include <stdlib.h>
#include "head.h"

int main()
{void Swap(Node *first, Node *second)
{
    printf("swap is here, %d, %d\n",first->X,second->X);

    int temp = first->X;
    first->X = second->X;
    second->X = temp;
}

void BubbleSort(Node *Ptrdata, int size)
{
    int counter, index;
    int sorted = 0;

    if (head == NULL)
    {
        return;
    }

    for(counter = 0; counter < size - 1 && !sorted; counter++)
    {
        sorted = 1;

        for(index = 0; index < size - 1 - counter && NULL != Ptrdata->Next; index++)
        {
            printf("round %d\n",index);
            if(Ptrdata->X > Ptrdata->Next->X)
            {
                Swap(Ptrdata, Ptrdata->Next);
                sorted = 0;
            }
            Ptrdata = Ptrdata->Next;
        }
    }
}

void SelectionSort(int *data, int size)
{
    int counter;

    for(counter = 0; counter < size - 1; counter++)
    {
        int minIndex = counter, index;

        for(index = minIndex + 1; index < size; index++)
        {
            if(data[index] < data[minIndex])
                minIndex = index;
        }

        Swap(&data[counter], &data[minIndex]);
    }
}

void InsertionSort(int *data, int size)
{
    int counter, key, index;

    for(counter = 1; counter < size; counter++)
    {
        key = data[counter];
        index = counter - 1;

        while(index >= 0 && data[index] > key)
        {
            data[index + 1] = data[index];
            index--;
        }
        data[index+1] = key;
    }
}

Node *middle (Node *start, Node *finish)
{
    Node *slow = start;
    Node *fast = start->Next;

    if (NULL == start)
        return NULL;

    while (finish != fast)
    {
        fast = fast->Next;
        if (finish != fast)
        {
            slow = slow->Next;
            fast = fast->Next;
        }
    }
    return slow;

}


Node* BinarySearch(int item, Node *Ptrdata)
{
    Node* minIndex = head;
    Node* maxIndex = tail;
    Node* midIndex;

    do
    {
        midIndex = middle(minIndex,maxIndex);

        if (NULL == middle)
        {
            return NULL;
        }

        if(item == Ptrdata->X)
        {
            return midIndex;
        }

        if(item > Ptrdata->X)
        {
            minIndex = midIndex->Next;
        }
        else
            maxIndex = midIndex;

    }while(minIndex != maxIndex || NULL == minIndex);

    return NULL;
}


int main()
{
    int len=0;
    int arr[] = {4, 3, 5, 6, 2, 1};
    for (len=0; arr[len]!=NULL; len++) {}
    int i;
    for (i=0; i<len; i++)
    {
        Add (arr[i]);
    }

    BubbleSort(head, 6);

    Display(6);

    Node* found = BinarySearch(5,head);
    printf("We found the value %d in your list",found->X);


    return 0;
}

void Display(int size)
{
    int i=0;
    Node *current = head;

    while(current != NULL && size > i)
    {
        printf("%d   ", current->X);
        current = current->Next;
        i++;
    }
}


void Add(int data)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->X = data;
    newNode->Prev = newNode->Next = NULL;

    if(head == NULL)
    {
        head = tail = newNode;
    }
    else
    {
        tail->Next = newNode;
        newNode->Prev = tail;
        tail = newNode;
        tail->Next = NULL;
    }
}

    return 0;
}

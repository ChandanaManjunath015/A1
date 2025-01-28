#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* partition(struct ListNode* head, struct ListNode* end, struct ListNode** newHead, struct ListNode** newEnd) 
{
    struct ListNode* pivot = end;
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    struct ListNode* tail = pivot;
    while (curr != pivot) 
    {
        if (curr->val < pivot->val)
        {
            if (*newHead == NULL) 
            {
                *newHead = curr;
            }
            prev = curr;
            curr = curr->next;
        } 
        else
        {
            if (prev)
            {
                prev->next = curr->next;
            }
            struct ListNode* temp = curr->next;
            curr->next = NULL;
            tail->next = curr;
            tail = curr;
            curr = temp;
        }
    }

    if (*newHead == NULL)
    {
        *newHead = pivot;
    }
    *newEnd = tail;
    return pivot;
}

struct ListNode* quickSortRecur(struct ListNode* head, struct ListNode* end)
{
    if (!head || head == end) 
    {
        return head;
    }
    struct ListNode *newHead = NULL, *newEnd = NULL;
    struct ListNode* pivot = partition(head, end, &newHead, &newEnd);
    if (newHead != pivot) 
    {
        struct ListNode* temp = newHead;
        while (temp->next != pivot)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        newHead = quickSortRecur(newHead, temp);
        temp = newHead;
        while (temp->next != NULL) 
        {
            temp = temp->next;
        }
        temp->next = pivot;
    }
    pivot->next = quickSortRecur(pivot->next, newEnd);
    return newHead;
}

struct ListNode* getTail(struct ListNode* head)
{
    while (head != NULL && head->next != NULL) 
    {
        head = head->next;
    }
    return head;
}

void printList(struct ListNode* head) 
{
    while (head != NULL) 
    {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

struct ListNode* newNode(int val) 
{
    struct ListNode* node = (struct ListNode*) malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

int main() 
{
    struct ListNode* head = newNode(4);
    head->next = newNode(2);
    head->next->next = newNode(1);
    head->next->next->next = newNode(3);
    printf("Original List: \n");
    printList(head);
    struct ListNode* tail = getTail(head);
    head = quickSortRecur(head, tail);
    printf("Sorted List: \n");
    printList(head);
    return 0;
}

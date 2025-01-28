#include <stdio.h>
#include <stdlib.h>

struct ListNode 
{
    int val;
    struct ListNode* next;
};

struct ListNode* getMiddle(struct ListNode* head)
{
    if (!head) return NULL;
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

struct ListNode* merge(struct ListNode* left, struct ListNode* right) 
{
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* tail = dummy;
    while (left != NULL && right != NULL) 
    {
        if (left->val <= right->val) 
        {
            tail->next = left;
            left = left->next;
        } 
        else 
        {
            tail->next = right;
            right = right->next;
        }
        tail = tail->next;
    }
    if (left != NULL)
    {
        tail->next = left;
    }
    if (right != NULL)
    {
        tail->next = right;
    }
    struct ListNode* result = dummy->next;
    free(dummy);  
    return result;
}

struct ListNode* mergeSort(struct ListNode* head)
{
    if (head == NULL || head->next == NULL) 
    {
        return head;
    }
    struct ListNode* middle = getMiddle(head);
    struct ListNode* nextToMiddle = middle->next;
    middle->next = NULL;
    struct ListNode* left = mergeSort(head);
    struct ListNode* right = mergeSort(nextToMiddle);
    return merge(left, right);
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
    head = mergeSort(head);
    printf("Sorted List: \n");
    printList(head);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
    int val;
    struct ListNode *next;
}ListNode;

ListNode* createNode(int v)
{
    ListNode *node = (ListNode*)malloc(sizeof(ListNode));
    node -> val = v;
    node -> next = NULL;
    return node;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
    ListNode *head = NULL, *tail, *newNode;
    int v, carry = 0;
    while (l1 || l2)
    {
        if (l1 && l2)
        {
            v = l1 -> val + l2 -> val + carry;
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        else if (!l1 && l2)
        {
            v = l2 -> val + carry;
            l2 = l2 -> next;
        }
        else
        {
            v = l1 -> val + carry;
            l1 = l1 -> next;
        }

        carry = v / 10;
        v = v % 10;

        newNode = createNode(v);
        if (head == NULL)
            head = newNode;
        else
            tail -> next = newNode;
        tail = newNode;
    }

    if (carry != 0)
    {
        newNode = createNode(carry);
        tail -> next = newNode;
        tail = newNode;
    }
    return head;
}

void printList(ListNode *num)
{
    if (!num) return;
    while (num)
    {
        printf("%d -> ", num->val);
        num = num -> next;
    }
    printf("NULL\n");
}

int main()
{
    ListNode *num1 = NULL, *num2 = NULL, *tail;
    int n1, n2;
    printf("Enter the numbers to add: ");
    scanf("%d %d", &n1, &n2);

    while (n1)
    {
        ListNode *newNode = createNode(n1%10);
        if (num1 == NULL)   num1 = newNode;
        else tail -> next = newNode;
        tail = newNode;
        n1 /= 10;
    }

    while (n2)
    {
        ListNode *newNode = createNode(n2%10);
        if (num2 == NULL)   num2 = newNode;
        else tail -> next = newNode;
        tail = newNode;
        n2 /= 10;
    }
    
    printList(num1);
    printf("+\n");
    printList(num2);
    printf("-------------------\n");
    ListNode *num3 = addTwoNumbers(num1, num2);
    printList(num3);
}

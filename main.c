#include <stdio.h>
#include <stdlib.h>

typedef struct linked_list_node{
    int value;
    struct linked_list_node* next;
} Node;

typedef Node* List;

List Insert(List head, int value, int asc)
{
    Node *ptr = (List)malloc(sizeof(Node)); // allocate a piece of memory for the new node
    ptr->value = value;
    if(head==NULL || value < head->value && asc == 1 || value > head->value && asc == 0)
    {
        ptr->next = head;
        return ptr;
    }
    Node *current = head;
    while(1)
    {
        if(asc == 1){ // ascending order
            // code here
            if(value<current->value){
                head->value=ptr->value;
                head->next=current;
            }
            else{
                if(current->next==NULL){
                    current->next=ptr;
                    ptr->next=NULL;
                    break;
                }else if(value<current->next->value){
                    ptr->next=current->next;
                    current->next=ptr;
                    break;
                }else{
                    current=current->next;
                }
            }
        }
        else if(asc == 0){ // descending order
            // code here
            if(value>current->value){
                head->value=ptr->value;
                head->next=current;
            }else{
                if(current->next==NULL){
                    current->next=ptr;
                    ptr->next=NULL;
                    break;
                }else if(value>current->next->value){
                    ptr->next=current->next;
                    current->next=ptr;
                    break;
                }else{
                    current=current->next;
                }
            }
        }
    }
    return head;
}

int NumberOfPairsSumToK(List headA, List headB, int k)
{
    int numberOfPairs = 0;
    // code here
    List currentA=headA, currentB=headB;
    while(currentB!=NULL){
        while(currentA!=NULL){
            int sum=currentA->value+currentB->value;
            if(sum>k){
                currentB=currentB->next;
                currentA=headA;
                break;
            }else if(sum==k){
                numberOfPairs+=1;
                currentA=currentA->next;
            }else{
                currentA=currentA->next;
            }
            if(currentA==NULL){
                currentA=headA;
                currentB=currentB->next;
                break;
            }
        }
    }
    return numberOfPairs;
}

void Print(List head)
{
    // do not forget to print a '\n'
    // code here
    List p=head;
    while(p!=NULL){
        printf("%d ",p->value);
        p=p->next;
    }
    printf("\n");
}

int main()
{
    List headA = NULL;
    List headB = NULL;
    int n, m, k;
    int value;

    printf("Input the number of integers in A:\n");
    scanf("%d", &n);
    printf("Input these integers:\n");
    for(int i=0; i<n; i++)
    {
        scanf("%d", &value);
        headA = Insert(headA, value, 1);
    }

    printf("Input the number of integers in B:\n");
    scanf("%d", &m);
    printf("Input these integers:\n");
    for(int i=0; i<m; i++)
    {
        scanf("%d", &value);
        headB = Insert(headB, value, 0);
    }
    printf("Input k:\n");
    scanf("%d", &k);

    int noOfPairs;
    noOfPairs = NumberOfPairsSumToK(headA, headB, k);

    Print(headA);
    Print(headB);
    printf("Number of pairs summed to k:\n");
    printf("%d\n", noOfPairs);
    return 0;
}

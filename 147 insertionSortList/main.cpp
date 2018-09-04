#include <iostream>
using namespace std;

/*
 * 对链表进行插入排序。
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    /*
     * 时间复杂度：n(n^2)
     * 遍历链表，每个结点i都与前面的结点进行比较，若大于i结点，则将i结点插入到该点前面
     */
    ListNode* insertionSortList(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *pre = dummy;
        ListNode *cur = NULL;
        ListNode *next = NULL;
        ListNode *tmp = NULL;
        int flag = 0;

        while(pre->next){
            cur = pre->next;
            tmp = dummy;
            flag = 0;
            while(tmp->next != cur){
                if (tmp->next->val > cur->val){
                    next = tmp->next;
                    tmp->next = cur;
                    pre->next = cur->next;
                    cur->next = next;
                    flag = 1;
                    break;
                }
                tmp = tmp->next;
            }
            if (!flag){
                pre = pre->next;
            }
        }
        return dummy->next;
    }
};

ListNode* createList(int arr[], int n)
{
    if (n == 0)
        return NULL;
    ListNode *head = new ListNode(arr[0]);

    ListNode *curNode = head;

    for (int i = 1; i < n; i ++){
        curNode->next = new ListNode(arr[i]);
        curNode = curNode->next;
    }
    return head;
}

int printList(ListNode *head)
{
    ListNode *curNode = head;

    while(curNode != NULL){
        cout << curNode->val <<" -> ";
        curNode = curNode->next;
    }
    cout << "NULL" << endl;
    return 0;
}

int delList(ListNode *head)
{
    if (head == NULL)
        return 0;
    ListNode *curNode = head;
    while(curNode != NULL){
        ListNode *delNode = curNode;
        curNode = curNode->next;
        delete delNode;
    }
    return 0;
}

int main() {
    //int arr1[] = {4,2,1,3};
    int arr1[] = {-1,5,3,4,0};
    ListNode *head1 = createList(arr1,sizeof(arr1)/sizeof(arr1[0]));
    printList(head1);
    Solution s;
    ListNode * head3 = s.insertionSortList(head1);
    printList(head3);
    delList(head1);
    return 0;
}
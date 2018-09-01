#include <iostream>
using namespace std;

/*
 * 给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *pre = dummy;
        ListNode *cur = NULL;
        ListNode *next = NULL;
        int delflag = 0;

        while(pre->next && pre->next->next){
            cur = pre->next;
            next = pre->next->next;

            if (cur->val == next->val){
                cur->next = next->next;
                delflag = 1;
                delete next;
            } else{
                if (delflag == 1){
                    delflag = 0;
                    pre->next = cur->next;
                    delete cur;
                    continue;
                }
                pre = pre->next;
            }
        }
        if (delflag == 1){
            pre->next = cur->next;
            delete cur;
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
    //int arr1[] = {1,2,3,3,4,4,5};
    int arr1[] = {1,1};
    ListNode *head1 = createList(arr1,sizeof(arr1)/sizeof(arr1[0]));
    printList(head1);
    Solution s;
    ListNode * head3 = s.deleteDuplicates(head1);
    printList(head3);
    delList(head1);
    return 0;
}
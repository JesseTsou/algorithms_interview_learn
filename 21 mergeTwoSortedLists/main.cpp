#include <iostream>
using namespace std;

/*
 * 将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    /*
     * 时间复杂度：O(n)
     * 添加新链表头，从头遍历两个链表，值较小的记录到新链表中，并后移动一位
     * 考虑两个链表长度可能不一致，同时遍历完成后，还需要对较长的链表进行遍历，添加到新链表尾部
     */
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0);
        ListNode *pre = dummy;

        ListNode *cur1 = l1;
        ListNode *cur2 = l2;

        while (cur1 && cur2){
            if (cur1->val <= cur2->val){
                pre->next = cur1;
                cur1 = cur1->next;
            } else{
                pre->next = cur2;
                cur2 = cur2->next;
            }
            pre = pre->next;
        }

        ListNode *last = (cur1 != NULL)?cur1:cur2;
        pre->next = last;

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
    int arr1[] = {1,2,4};
    int arr2[] = {1,3,4};
    //int arr1[] = {1,1};
    ListNode *head1 = createList(arr1,sizeof(arr1)/sizeof(arr1[0]));
    ListNode *head2 = createList(arr2,sizeof(arr2)/sizeof(arr2[0]));
    printList(head1);
    printList(head2);
    Solution s;
    ListNode * head3 = s.mergeTwoLists(head1,head2);
    printList(head3);
    delList(head1);
    return 0;
}
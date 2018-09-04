#include <iostream>
using namespace std;

/*
 * 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
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
     * 双指针，两指针间隔为n，向后移动，当后一个指针到达尾部时，前一个指针即是需要删除的结点
     * 此处使用pre->next来代表前一个指针，方便删除操作
     */
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *cur = dummy->next;
        ListNode *pre = dummy;
        ListNode *del = NULL;

        for(int i = 0;i < n; i++){
            cur = cur->next;
        }
        ListNode *nNode = cur;

        while(nNode){
            nNode = nNode->next;
            pre = pre->next;
        }

        if (pre->next){
            del = pre->next;
            pre->next = pre->next->next;
            delete del;
        }
        return dummy->next;
    }

    /*
     * 时间复杂度：O(n)
     * 两遍循环，第一次得到链表长度，然后计算出倒数第n个结点是第几个结点
     * 第二次循环得到结点位置，然后进行删除操作
     */
    ListNode* removeNthFromEnd2(ListNode* head, int n) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *cur = dummy->next;
        ListNode *pre = dummy;
        ListNode *del = NULL;
        int count = 0;
        while(cur){
            count ++;
            cur = cur->next;
        }

        for (int i = 0; i < count - n; i ++){
            pre = pre->next;
        }

        del = pre->next;
        pre->next = del->next;
        delete del;

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
    int arr1[] = {1,2,3,4,5};
    ListNode *head1 = createList(arr1,sizeof(arr1)/sizeof(arr1[0]));
    printList(head1);
    Solution s;
    ListNode *head3 = s.removeNthFromEnd2(head1,4);
    printList(head3);
    delList(head1);
    return 0;
}
#include <iostream>
using namespace std;

/*
 *给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    /*
     * 时间复杂度：O(n^2)
     * 先找到中间结点mid
     * 从head遍历到mid，遍历时，将对应的尾部结点插入到当前结点之后
     */
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return;
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *mid = slow;
        ListNode *pre = head;
        ListNode *lastpre = NULL;
        ListNode *tmp = NULL;
        ListNode *moveNode = NULL;

        while(pre != mid){
            lastpre = mid;
            while(lastpre->next && lastpre->next->next)//找到尾部结点前一个结点
                lastpre = lastpre->next;
            moveNode = lastpre->next;
            tmp = pre->next;
            pre->next = moveNode;
            moveNode->next = tmp;
            lastpre->next = NULL;
            pre = tmp;
        }
        return ;
    }

    /*
     * 时间复杂度：O(n)
     * 找到中结点后，将之后的链表进行反转
     * 然后从两个链表头结点（即原链表的头尾）开始遍历
     * 将反向链表的相应结点插入到正向链表之后
     */
    void reorderList2(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return;
        ListNode *slow = head;
        ListNode *fast = head;

        //找到中间结点
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *mid = slow;
        ListNode *pre = NULL;
        ListNode *last = mid->next;
        ListNode *tmp = NULL;
        ListNode *tmp1 = NULL;

        //中结点之后置为空，正向链表尾部指向NULL
        mid->next = NULL;
        //反转中结点之后的链表，反向链表尾部指向初始的pre即NULL
        while(last){
            tmp = last->next;
            last->next = pre;
            pre = last;
            last = tmp;
        }

        ListNode *headNode = head;
        ListNode *tailNode = pre;

        //同时遍历正向与反向链表，将反向链表对应结点插入到正向链表结点之后
        while(headNode && tailNode){
            tmp = headNode->next;
            tmp1 = tailNode->next;
            headNode->next = tailNode;
            tailNode->next = tmp;
            headNode = tmp;
            tailNode = tmp1;
        }
        return ;
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
    int arr1[] = {1,2,3,4};
    //int arr1[] = {1,2};
    ListNode *head1 = createList(arr1,sizeof(arr1)/sizeof(arr1[0]));
    printList(head1);
    Solution s;
    s.reorderList2(head1);
    printList(head1);
    delList(head1);
    return 0;
}

#include <iostream>
using namespace std;

/*
 * 给出一个链表，每 k 个节点一组进行翻转，并返回翻转后的链表。
 * k 是一个正整数，它的值小于或等于链表的长度。
 * 如果节点总数不是 k 的整数倍，那么将最后剩余节点保持原有顺序。
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
     * 首先遍历链表，记录结点个数，当满足个数等于k时，开始进行反转，反转完成后，个数重新计数
     * 使用pre指向[n,n+k]区间的前一个结点（即n-1），使用cur进行遍历，满足条件时，cur指向n+k这个结点
     * [n,n+k]这个区间进行反转操作后，需要将pre指向n+k这个结点，并且n这个结点需要指向n+k+1这个结点
     * 这个是为了使[n,n+k]这个区间的结点能够与两边串联起来
     */
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *pre = dummy;
        ListNode *pre_in = NULL; //[n,n+k]区间操作时的前结点
        ListNode *cur = NULL;    //遍历整个结点
        ListNode *cur_in = NULL; //[n,n+k]区间操作时的当前结点
        ListNode *next = NULL;   //[n,n+k]区间操作时的下一结点
        ListNode *first = NULL;  //记录n这个结点
        int count = 0;

        cur = pre->next;
        while(cur){
            count ++;
            if (count == k){
                pre_in = pre;
                cur_in = pre->next;
                first = cur_in;
                for (int i = 0; i < k; i ++){//反转操作
                    next = cur_in->next;
                    cur_in->next = pre_in;
                    pre_in = cur_in;
                    cur_in = next;
                }
                pre->next = pre_in;  //pre指向n+k这个结点
                first->next = next;  //n这个结点需要指向n+k+1这个结点
                pre = first;         //移动pre结点到n结点，是为下一个k长度区间的前一个结点
                cur = pre->next;
                count = 0;           //重新计数
                continue;
            }
            cur = cur->next;
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
    int arr1[] = {1,2,3,4,5};
    ListNode *head1 = createList(arr1,sizeof(arr1)/sizeof(arr1[0]));
    printList(head1);
    Solution s;
    ListNode * head3 = s.reverseKGroup(head1,1);
    printList(head3);
    delList(head1);
    return 0;
}
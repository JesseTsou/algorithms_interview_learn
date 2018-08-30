#include <iostream>
using namespace std;

/*
 * 反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。
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
     * 对于m=1的情况需要作特殊处理。
     */
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *pm_pre = head;

        //记录m前一个结点
        for (int i = 1; i < m - 1; i ++){
            pm_pre = pm_pre->next;
        }

        //创建虚拟头结点，其下一个结点为m位置结点
        ListNode *newhead = new ListNode(0);
        if (m == 1)
            newhead->next = pm_pre;
        else
            newhead->next = pm_pre->next;

        //反转m至n的结点
        ListNode *pre = newhead;
        ListNode *cur = newhead->next;
        ListNode *next = NULL;
        ListNode *temp = cur;//m结点位置
        for (int i = m; i <= n; i ++){
            if (cur == NULL)
                break;
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }

        //将m结点的next指向原来n的下一个结点
        temp->next = cur;
        if (m == 1) {
            //若m==1，即n结点即头结点
            head = pre;
        }else{
            //将m前一个结点的next指向反转后的第一个结点(即n结点)
            pm_pre->next = pre;
        }
        delete newhead;
        return head;
    }

    /*
     * 时间复杂度：O(n)
     * 创建虚拟头结点
     * 先将m的下一点指向自身，最后再处理m的下一个结点
     */
    ListNode* reverseBetween2(ListNode* head, int m, int n) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *pre = dummy;
        //m点前一点pre
        for (int i = 1; i <=m - 1; i ++){
            pre = pre->next;
        }
        ListNode *cur = pre->next;
        ListNode *pm = cur;
        ListNode *next = NULL;
        for (int i = m; i <= n; i ++){
            next = cur->next;//记录当前点的下一点
            cur->next = pre->next;//对于m点，指向自身；对于（m,n]指向其前一点
            pre->next = cur;//记录当前点，即下一点的前一点
            cur = next;//当前点移动到下一点
        }
        pm->next = cur;//m点下一结点指向n的下一结点
        return dummy->next;//dummy点始终未变
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
    int arr[] = {1,2,3,4,5};
    //int arr[] = {3,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    ListNode *head = createList(arr,n);
    printList(head);
    Solution s;
    ListNode * head2 = s.reverseBetween2(head,1,2);
    printList(head2);
    delList(head2);
    return 0;
}
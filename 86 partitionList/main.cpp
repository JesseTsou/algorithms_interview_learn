#include <iostream>
#include <unordered_map>
using namespace std;

/*
 *给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。
 * 你应当保留两个分区中每个节点的初始相对位置。
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
     * 记录最后一低点小于x的点less
     * 遍历链表，当遍历到的点(pre)的下一个点(cur)小于x时，将下一点(cur)插入到less之后，less相应向后移动一位
     * 并且pre需要指向原cur的下一个点（next），保证链表不会断，所以要以pre来遍历
     * 特殊情况：当满足条件时，当less与当前点前一点重合时，只需要向后移动一位即可
     */
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL)
            return NULL;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *pre = dummy;
        ListNode *less = dummy;
        ListNode *cur = NULL;
        ListNode *cur_next = NULL;

        while(pre->next){
            cur = pre->next;
            if (cur->val < x){
                if (pre == less){
                    less = less->next;
                    pre = pre->next;
                    continue;
                }
                cur_next = cur->next;//记录当前点下一个结点
                cur->next = less->next;//当前点指向less的下一个结点
                less->next = cur;//less指向当前点，即完成插入操作
                pre->next = cur_next;//前一点指向所记录的原当前点下一个结点，保持链表完整性
                less = less->next;//less后移，pre不需要后移，因为其next已经变化了
            } else
                pre = pre->next;
        }
        return dummy->next;
    }
    /*
     * 时间复杂度：O(n)
     * 添加两个链表
     * 小于x的记录到一个链表
     * 其他大于等于的记录到另一外链表
     * 然后两个链表拼接
     * 注意:最后一个结点需要指向NULL
     */
    ListNode* partition2(ListNode* head, int x) {
        ListNode *lessNode = new ListNode(0);
        ListNode *moreNode = new ListNode(0);

        ListNode *lessCur = lessNode;
        ListNode *moreCur = moreNode;

        ListNode *cur = head;
        while(cur){
            if (cur->val < x){
                lessCur->next = cur;
                lessCur = lessCur->next;
            }else{
                moreCur->next = cur;
                moreCur = moreCur->next;
            }
            cur = cur->next;
        }

        lessCur->next = moreNode->next;
        moreCur->next = NULL;
        return lessNode->next;
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
    int arr[] = {1,4,3,2,5,2};
    //int arr[] = {1,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    ListNode *head = createList(arr,n);
    printList(head);
    Solution s;
    ListNode * head2 = s.partition2(head,3);
    printList(head2);
    delList(head2);
    return 0;
}
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
    /*
     * 时间复杂度：O(n)
     * 遍历链表，若cur的下一个结点与cur的值相等，则删除下一结点，并标记cur为待删除结点（delflag = 1）
     * 直到不再有相等的，再将cur删除，并将delflag置0
     * 注意：链表遍历结束时，需要判断一下delflag
     */
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

    /*
     * 时间复杂度：O(n)
     * 与上一种解法不同的是，遇到相等的点，删除相等前一个点，遍历指针后移
     * 遇到了相等的点，开始遍历找到所有相等的点也是需要借鉴的
     */
    ListNode* deleteDuplicates2(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *pre = dummy;
        ListNode *cur = NULL;
        ListNode *del = NULL;
        ListNode *next = NULL;

        while(pre->next){
            cur  = pre->next;

            if (cur->next && cur->val == cur->next->val){
                int x = cur->val;

                while (cur->next && cur->next->val == x){
                    del = cur;
                    cur = cur->next;
                    delete del;
                }

                pre->next = cur->next;
                delete cur;
            } else
                pre = pre->next;
        }

        return dummy->next;
    }

    /*
     * 时间复杂度：O(n)
     * 根据第二种解法改造第一种解法
     * 遇到了相等的结点，则进行循环遍历，找到所有相等的点
     * 与第二种解法不同的是 这里是删除新找到的结点
     */
    ListNode* deleteDuplicates3(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *pre = dummy;
        ListNode *cur = NULL;
        ListNode *next = NULL;
        ListNode *del = NULL;

        while(pre->next) {
            cur = pre->next;

            if (cur->next && cur->next->val == cur->val) {
                int x = cur->val;

                while (cur->next && cur->next->val == x) {
                    del = cur->next;
                    cur->next = cur->next->next;
                    delete del;
                }

                pre->next = cur->next;
                delete cur;
            } else
                pre = pre->next;
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
    int arr1[] = {1,2,3,3,4,4,5};
    //int arr1[] = {1,1};
    ListNode *head1 = createList(arr1,sizeof(arr1)/sizeof(arr1[0]));
    printList(head1);
    Solution s;
    ListNode * head3 = s.deleteDuplicates3(head1);
    printList(head3);
    delList(head1);
    return 0;
}
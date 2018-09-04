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
            //从dummy->next开始遍历直到cur，找到第一个大于cur的结点
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
            //没有找到，则直到后移一位
            if (!flag){
                pre = pre->next;
            }
        }
        return dummy->next;
    }

    /*
     * 时间复杂度：O(n^2)
     * 遍历链表，如果当前结点i的值比后一个结点的值大，则需要排序
     * 从头结点开始遍历，找到第一个大于i结点的结点，将i结点插入到该点之前
     */
    ListNode* insertionSortList2(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *cur = head;
        ListNode *tmp = NULL;
        ListNode *findNode = NULL;
        ListNode *insertNode = NULL;

        while(cur){
            //当前结点的值比后一个结点的值大，则需要排序
            if (cur->next && cur->next->val < cur->val){
                insertNode = cur->next;
                findNode = dummy;
                //遍历链表，找到第一个大于目标结点的结点
                while(findNode->next && findNode->next->val < insertNode->val)
                    findNode = findNode->next;
                //将目标结点插入到该点之前
                tmp = findNode->next;
                findNode->next = insertNode;
                cur->next = insertNode->next;
                insertNode->next = tmp;
            } else
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
    //int arr1[] = {4,2,1,3};
    int arr1[] = {-1,5,3,4,0};
    ListNode *head1 = createList(arr1,sizeof(arr1)/sizeof(arr1[0]));
    printList(head1);
    Solution s;
    ListNode * head3 = s.insertionSortList2(head1);
    printList(head3);
    delList(head1);
    return 0;
}
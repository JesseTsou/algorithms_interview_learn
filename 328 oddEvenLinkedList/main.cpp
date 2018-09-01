#include <iostream>
#include <unordered_map>
using namespace std;

/*
 * 给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。
 * 请尝试使用原地算法完成。你的算法的空间复杂度应为 O(1)，时间复杂度应为 O(nodes)，nodes 为节点总数。
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
     * 用index来判断是是否为奇偶，记录最后一个奇数结点oddptr
     * 遍历链表将奇数结点插入到oddptr之后
     */
    ListNode* oddEvenList(ListNode* head) {
        ListNode *pre = head;
        ListNode *oddptr = head;
        ListNode *cur = NULL;
        ListNode *cur_next = NULL;
        int index = 1;

        while(pre && pre->next){
            index ++;
            cur = pre->next;

            if (index % 2){
                cur_next = cur->next;
                cur->next = oddptr->next;
                oddptr->next = cur;
                pre->next = cur_next;
                oddptr = oddptr->next;
            } else{
                pre = pre->next;
            }
        }
        return head;
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
    int arr[] = {1,2,3,4,5,6};
    //int arr[] = {1,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    ListNode *head = createList(arr,n);
    printList(head);
    Solution s;
    ListNode * head2 = s.oddEvenList(head);
    printList(head2);
    delList(head2);
    return 0;
}
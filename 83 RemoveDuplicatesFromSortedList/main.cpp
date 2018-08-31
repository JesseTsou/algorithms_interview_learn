#include <iostream>
#include <unordered_map>
using namespace std;

/*
 *给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
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
     * 没有看清题，排序这个条件没看到
     */
    ListNode* deleteDuplicates(ListNode* head) {
        unordered_map<int,int> map1;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *pre = dummy;
        ListNode *cur = NULL;
        while(pre->next){
            cur = pre->next;
            if (map1[cur->val] > 0){
                pre->next = cur->next;
                delete cur;
            } else{
                map1[cur->val] ++;
                pre = pre->next;
            }
        }
        delete dummy;
        return head;
    }

    /*
     * 时间复杂度：O(n)
     * 考虑到排序了
     */
    ListNode* deleteDuplicates2(ListNode* head) {
        ListNode *cur = head;
        while(cur && cur->next){
            if (cur->val == cur->next->val){
                cur->next = cur->next->next;
                continue;//需要继续比较下一个
            }
            cur = cur->next;
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
    int arr[] = {1,1,2,3,3};
    //int arr[] = {3,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    ListNode *head = createList(arr,n);
    printList(head);
    Solution s;
    ListNode * head2 = s.deleteDuplicates2(head);
    printList(head2);
    delList(head2);
    return 0;
}
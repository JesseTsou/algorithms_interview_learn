#include <iostream>
#include <vector>
using namespace std;

/*
 * 请判断一个链表是否为回文链表。
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
     * 使用快慢指针得到中间结点，然后将中间结点之后的链表反转，得到反向链表
     * 然后同时遍历正向与反向链表，比较对应的值
     */
    bool isPalindrome(ListNode* head) {
        if(head == NULL)
            return true;
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode *mid = slow;
        ListNode *pre = NULL;
        ListNode *last = mid->next;
        mid->next = NULL;

        ListNode *tmp = NULL;
        while(last){
            tmp = last->next;
            last->next = pre;
            pre = last;
            last = tmp;
        }

        bool ispalindrome = true;

        while(head && pre){
            if (head->val != pre->val){
                ispalindrome = false;
                break;
            }
            pre = pre->next;
            head = head->next;
        }
        return ispalindrome;
    }
    /*
     * 时间复杂度：O(n)
     * 空间复杂度：O(n)
     * 用容器保存链表值，对容器对应元素比较即可
     */
    bool isPalindrome2(ListNode* head) {
        ListNode *cur = head;
        vector<int> vec;
        while(cur){
            vec.push_back(cur->val);
            cur = cur->next;
        }

        for (int i = 0; i < vec.size()/2; i ++){
            if (vec[i] != vec[vec.size() - 1 - i]){
                return false;
            }
        }
        return true;
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
    int arr1[] = {1,2,2,1};
    //int arr1[] = {1,2};
    ListNode *head1 = createList(arr1,sizeof(arr1)/sizeof(arr1[0]));
    printList(head1);
    Solution s;
    if(s.isPalindrome2(head1))
        cout << "is palindrome" << endl;
    else
        cout << "is not palindrome" << endl;
    delList(head1);
    return 0;
}

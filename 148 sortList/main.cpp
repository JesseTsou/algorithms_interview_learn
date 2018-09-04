#include <iostream>
using namespace std;

/*
 * 在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    /*
     * 时间复杂度：O(nlogn)
     * 归并排序
     */
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *slow = head;
        ListNode *fast = head->next;

        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode *half = slow->next;
        slow->next = NULL;

        return merge(sortList(head),sortList(half));
    }

    ListNode *merge(ListNode* head1,ListNode* head2)
    {
        ListNode *dummy = new ListNode(0);
        ListNode *l3 = dummy;

        ListNode *l1 = head1;
        ListNode *l2 = head2;

        while(l1 || l2 ){
            if (l1 && (l2 == NULL || l1->val < l2->val)){
                l3->next = l1;
                l1 = l1->next;
            } else if (l2 && (l1 == NULL || l1->val >= l2->val)){
                l3->next = l2;
                l2 = l2->next;
            }
            l3 = l3->next;
        }
        l3->next = NULL;
        ListNode *ret = dummy->next;
        delete dummy;
        return ret;
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
    ListNode * head3 = s.sortList(head1);
    printList(head3);
    delList(head1);
    return 0;
}
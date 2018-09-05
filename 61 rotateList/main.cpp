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
     * 时间复杂度：O(n)
     * 得到链表长度，k对其取余（对链表进行旋转次数是长度的整数倍数时，链表是不变的），求得的k值即有效的旋转次数
     * 每次旋转，将最后一个结点移到第一个结点位置
     * 所以每次都需要定位到最后一个结点前一个结点的位置，方便进行移动操作
     */
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *pre = dummy->next;
        ListNode *cur = NULL;

        if (pre == NULL || pre->next == NULL)
            return head;

        int len = 1;
        while(pre->next){
            pre=pre->next;
            len ++;
        }

        k = k % len;

        for (int i = 0; i < k; i ++){
            pre = dummy->next;
            while(pre->next->next)
                pre = pre->next;
            cur = pre->next;
            pre->next = cur->next;
            cur->next = dummy->next;
            dummy->next = cur;
        }
        return dummy->next;
    }

	/*
	 * 时间复杂度：O(n)
	 * 使用双指针，获取到需要旋转的区间，然后整体旋转到头部
	 */
    ListNode* rotateRight2(ListNode* head, int k) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *pre = dummy->next;
        ListNode *cur = NULL;
        ListNode *next = NULL;

        if (pre == NULL || pre->next == NULL)
            return head;

        int len = 1;
        while(pre->next){
            pre=pre->next;
            len ++;
        }

        k = k % len;
		if (k == 0)
			return head;
        ListNode *start = dummy->next;
        ListNode *end =  dummy->next;

        for (int i = 0; i < k; i ++){
            end = end->next;
        }

        while(end->next){
            start = start->next;
            end = end->next;
        }

        next = dummy->next;
        dummy->next = start->next;
        end->next = next;
        start->next = NULL;

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
    //int arr1[] = {1,2,3,4,5};
    int arr1[] = {1,2};
    ListNode *head1 = createList(arr1,sizeof(arr1)/sizeof(arr1[0]));
    printList(head1);
    Solution s;
    ListNode *head3 = s.rotateRight2(head1,2);
    printList(head3);
    delList(head1);
    return 0;
}

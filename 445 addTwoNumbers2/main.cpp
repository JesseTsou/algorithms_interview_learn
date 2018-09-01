#include <iostream>
using namespace std;

/*
 * 给定两个非空链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储单个数字。将这两数相加会返回一个新的链表。
 * 你可以假设除了数字 0 之外，这两个数字都不会以零开头。
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
     * 将两个链表进行反转，然后同2 add two number相同操作，最后再将结果进行反转:
     * 添加新链表存储和的结果
     * 每次相加，需要将两个链表对位数值与前一次的十位数 相加
     * 将和的个位数添加至新链表中
     * 和的十位数等待下一次相加
     * 两个链表长度可能不一致，所以对位相加完成后，还需要对长度更长的链表进行操作。
     * 最后可能十位数还有值，所以还要对十位数单独作判断，如果有值则添加到新链表
     */
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *cur1 = revertList(l1);
        ListNode *cur2 = revertList(l2);
        ListNode *l3 = new ListNode(0);
        ListNode *cur3 = l3;
        int tens  = 0;//和的十位数
        int units = 0;//和的个位数
        int sum = 0;//和的数值

        while(cur1 && cur2){
            sum = cur1->val + cur2->val + tens;
            units = sum % 10;
            tens = sum / 10;
            ListNode *temp = new ListNode(units);
            cur3->next = temp;
            cur3 = cur3->next;
            cur1 = cur1->next;
            cur2 = cur2->next;
        }

        ListNode *last = (cur1 == NULL)?cur2:cur1;//取非空
        while(last){
            sum = last->val + tens;
            units = sum % 10;
            tens = sum / 10;
            ListNode *temp = new ListNode(units);
            cur3->next = temp;
            cur3 = cur3->next;
            last = last->next;
        }

        if (tens){
            ListNode *temp = new ListNode(tens);
            cur3->next = temp;
            cur3 = cur3->next;
        }

        return revertList(l3->next);
    }

    /*
     * 在以上基础上
     * 结果链表可以不用反转：每次将新添加的结点放置到结果链表头部
     */
    ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2) {
        ListNode *cur1 = revertList(l1);
        ListNode *cur2 = revertList(l2);
        ListNode *cur3 = NULL;
        int tens  = 0;//和的十位数
        int units = 0;//和的个位数
        int sum = 0;//和的数值

        while(cur1 && cur2){
            sum = cur1->val + cur2->val + tens;
            units = sum % 10;
            tens = sum / 10;
            ListNode *temp = new ListNode(units);
            temp->next = cur3;
            cur3 = temp;
            cur1 = cur1->next;
            cur2 = cur2->next;
        }

        ListNode *last = (cur1 == NULL)?cur2:cur1;//取非空
        while(last){
            sum = last->val + tens;
            units = sum % 10;
            tens = sum / 10;
            ListNode *temp = new ListNode(units);
            temp->next = cur3;
            cur3 = temp;
            last = last->next;
        }

        if (tens){
            ListNode *temp = new ListNode(tens);
            temp->next = cur3;
            cur3 = temp;
        }

        return cur3;
    }

private:
    ListNode *revertList(ListNode* head)
    {
        ListNode *cur = head;
        ListNode *pre = NULL;
        ListNode *next = NULL;

        while (cur){
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }

        return pre;
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
    int arr1[] = {7,2,4,3};
    int arr2[] = {5,6,4};
    ListNode *head1 = createList(arr1,sizeof(arr1)/sizeof(arr1[0]));
    ListNode *head2 = createList(arr2,sizeof(arr2)/sizeof(arr2[0]));
    printList(head1);
    printList(head2);
    Solution s;
    ListNode * head3 = s.addTwoNumbers2(head1,head2);
    printList(head3);
    delList(head1);
    return 0;
}
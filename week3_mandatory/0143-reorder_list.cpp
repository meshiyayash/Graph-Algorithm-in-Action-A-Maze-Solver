/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {

        if(head==NULL || head->next==NULL){
            return ;
        }

        ListNode* mid;
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }

        mid=slow;
        slow=slow->next;
        mid->next=NULL;

        ListNode* cur;
        ListNode* a=NULL;

        while(slow->next!=NULL){
            cur=slow->next;
            slow->next=a;
            a=slow;
            slow=cur;
        }
        slow->next=a;

        ListNode* tempHead=head;

        a=slow;
while(a != NULL){
    ListNode* t1 = tempHead->next;
    ListNode* t2 = a->next;

    tempHead->next = a;
    a->next = t1;

    tempHead = t1;
    a = t2;
}
    }
};

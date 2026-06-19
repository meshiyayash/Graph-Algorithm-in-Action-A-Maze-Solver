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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int total=0;
        ListNode* a=head;

        while(a!=NULL){
            a=a->next;
            total++;
        }
        a=head;
        int ans=total-n;
        
        if(ans==0){
            head=head->next;
            return head;
        }

        while(ans>1){
            a=a->next;
            ans--;
        }

        ListNode* b=a->next;
        if(b==NULL){
            a->next=NULL;
        } else {
            ListNode* c=b->next;
            a->next=c;
        }

        return head;
    }
};

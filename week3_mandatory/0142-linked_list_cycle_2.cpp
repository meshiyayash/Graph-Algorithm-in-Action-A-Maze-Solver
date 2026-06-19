/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* s=head;
        ListNode* f=head;
        bool cycle=0;
        while(f!=NULL && f->next!=NULL){
            s=s->next;
            f=f->next->next;
            if(s==f){
                cycle=1;
                break;
            }
        }

        if(cycle){
            s=head;
            while(s!=f){
                s=s->next;
                f=f->next;
            }
            return s;
        } else {
            return NULL;
        }
    }
};

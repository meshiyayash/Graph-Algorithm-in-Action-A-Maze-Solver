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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans=NULL;
        ListNode* a=list1;
        ListNode* b=list2;
        
        if(a==NULL){
            return b;
        } else if(b==NULL){
            return a;
        }

        if(a->val >= b->val){
            ans=b;
            b=b->next;
        } else {
            ans=a;
            a=a->next;
        }

        ListNode* cur=ans;
        while(a!=NULL && b!=NULL){
            if(a->val >= b->val){
                cur->next=b;
                b=b->next;
            } else {
                cur->next=a;
                a=a->next;
            } 

            cur=cur->next;
        }

        if(a==NULL){
            cur->next=b;
        } else {
            cur->next=a;
        }
        return ans;
    }
};

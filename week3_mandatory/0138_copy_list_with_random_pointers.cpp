/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL){
            return NULL;
        }

        Node* newHead=new Node(head->val);
        Node* i=head->next;
        Node* prev=newHead;
        unordered_map<Node*,Node*> m;
        m[head]=newHead;
        while(i!=NULL){
            Node* a=new Node(i->val);
            m[i]=a;
            prev->next=a;
            prev=a;
            i=i->next;
        }

        i=head;
        Node *j=newHead;
        while(i!=NULL){
            j->random=m[i->random];
            i=i->next;
            j=j->next;
        }
        
        return newHead;
    }
};

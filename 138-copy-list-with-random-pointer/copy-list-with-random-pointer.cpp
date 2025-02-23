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
        if(!head) return nullptr;
        unordered_map<Node*, Node*> l2;

        Node* l1 = head;
        while(l1) {
            l2[l1] = new Node(l1->val);
            l1 = l1->next;
        }

        l1 = head;
        while(l1) {
            l2[l1]->next = l2[l1->next];
            l2[l1]->random = l2[l1->random];
            l1 = l1->next;
        }

        return l2[head];
    }
};
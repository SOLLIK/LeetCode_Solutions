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
        unordered_map<Node*, Node*> oldToNew;

        Node* l1 = head;
        while(l1) {
            oldToNew[l1] = new Node(l1->val);
            l1 = l1->next;
        }

        l1 = head;
        while(l1) {
            oldToNew[l1]->next = oldToNew[l1->next];
            oldToNew[l1]->random = oldToNew[l1->random];
            l1 = l1->next;
        }

        return oldToNew[head];
    }
};
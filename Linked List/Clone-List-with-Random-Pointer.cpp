class Solution {
public:
    Node* copyRandomList(Node* head) {
    Node* dummy = new Node(-1);
    Node* temp = head;
    Node* tempC = dummy;

    while(temp != NULL){
        Node* a = new Node(temp->val);
        tempC->next = a;
        tempC = tempC-> next;
        temp = temp->next;
    }

    Node* newa = head;
    Node* duplicate = dummy -> next;
    Node* newb = duplicate;
    dummy = new Node(-1);
    Node* tempD = dummy;

    while(newa != NULL){
        tempD-> next = newa;
        newa = newa->next;
        tempD = tempD -> next;
        tempD-> next = newb;
        newb = newb->next;
        tempD = tempD -> next;
    }

    dummy = dummy -> next;

    Node* trav = dummy;
    while(trav != NULL){
        Node* trav2 = trav-> next;
        if(trav->random != NULL){
            trav2->random = trav->random->next;
        }
            trav = trav->next->next;
    }


    Node* d1 = new Node(-1);
    Node* d2 = new Node(-1);
    trav = d1;
    Node* t2 = d2;
    Node* t = dummy;
    while(t != NULL){
        trav ->next = t;
        t = t->next;
        trav = trav->next;
        t2 ->next = t;
        t = t->next;
        t2 = t2->next;
    }
    trav->next = NULL;
    trav->next = NULL;
    d1 = d1->next;
    d2 = d2->next;

    return d2;
    }
};

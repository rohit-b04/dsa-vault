Node* merge(Node* down,Node* right){
    if(down==NULL){
        return right;
    }
    if(right==NULL){
        return down;
    }

    Node* ans = new Node(-1);
    Node* temp = ans;

    while(down!=NULL&& right!=NULL){
        if(down->data<right->data){
            temp->child = down;
            temp = down;
        	down = down->child;
        }

        else{
            temp->child = right;
            temp = right;
            right = right->child;
        }
    }

    while(down!=NULL){
        temp->child = down;
        temp = down;
        down = down->child;
    }

    while(right!=NULL){
        temp->child = right;
        temp = right;
        right = right->child;
    }

    ans = ans->child;
    return ans;
}

Node* flattenLinkedList(Node* head) 
{
    if(head==NULL||head->next==NULL){
        return head;
    }

    Node* down = head;

    Node* right  = flattenLinkedList(head->next);

    down->next = NULL;

    return merge(down,right);

}

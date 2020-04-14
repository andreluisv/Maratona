ListNode *detectCycle(ListNode *head) {
   ListNode* hare=head, *tortoise=head;
    while(1){
        if (hare!=NULL && hare->next!=NULL){
            tortoise = tortoise->next;
            hare = hare->next->next;
        }else return NULL;
        if (hare==tortoise) break;
    }
    while(tortoise!=head){
        tortoise = tortoise->next;
        head = head->next;
    }
    return head;
}

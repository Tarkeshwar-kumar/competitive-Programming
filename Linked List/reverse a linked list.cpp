//
// Created by admin on 21/11/2021.
//

/*
 * Given pointer to the head node of a linked list, the task is to reverse the linked list. We need to reverse the list by
 * changing the links between nodes.
 */
/*
   Initialize three pointers prev as NULL, curr as head and next as NULL.
   Iterate through the linked list. In loop, do following.
   // Before changing next of current,
   // store next node
   next = curr->next
   // Now change next of current
   // This is where actual reversing happens
   curr->next = prev
   // Move prev and curr one step forward
   prev = curr
   curr = next
*/
void reverse()
{
    Node* current = head;
    Node *prev = NULL, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}
void reverseUtil(Node* curr, Node* prev, Node** head)
{
    if (!curr->next) {
        *head = curr;
        curr->next = prev;
        return;
    }
    Node* next = curr->next;
    curr->next = prev;
    reverseUtil(next, curr, head);
}
void reverse(Node** head)
{
    if (!head)
        return;
    reverseUtil(*head, NULL, head);
}
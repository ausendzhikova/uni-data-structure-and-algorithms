/*
 * Complete the 'insertNodeAtPosition' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_SINGLY_LINKED_LIST llist
 *  2. INTEGER data
 *  3. INTEGER position
 */

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */


SinglyLinkedListNode* addAtFirstPos(SinglyLinkedListNode* head, SinglyLinkedListNode* nodeToAdd) {
    if (!head) {
        head = nodeToAdd;
    }
    else {
        SinglyLinkedListNode* current = head;
        nodeToAdd->next = head;
        head = nodeToAdd;
    }
    return head;
}

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* linkedListHead, int data, int position) {
    SinglyLinkedListNode* nodeToAdd = new SinglyLinkedListNode(data);
    if (position == 0) {
        return addAtFirstPos(linkedListHead, nodeToAdd);
    }
    SinglyLinkedListNode* current = linkedListHead;
    for (int i = 1; i < position; i++) {
        current = current->next;
    }
    SinglyLinkedListNode* next = current->next;
    current->next = nodeToAdd;
    nodeToAdd->next = next;
    
    return linkedListHead;
}
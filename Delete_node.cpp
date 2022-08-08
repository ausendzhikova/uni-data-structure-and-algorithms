/*
 * Complete the 'deleteNode' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_SINGLY_LINKED_LIST llist
 *  2. INTEGER position
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

SinglyLinkedListNode* deleteAtFirstPos(SinglyLinkedListNode* linkedListHead) {
    if (linkedListHead == nullptr) {
        return nullptr;
    }
    SinglyLinkedListNode* newHead = linkedListHead->next;
    linkedListHead = newHead;

    return linkedListHead;
}

SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* linkedListHead, int position) {
    if (position == 0) {
        return deleteAtFirstPos(linkedListHead);
    }

    SinglyLinkedListNode* current = linkedListHead;
    for (int i = 1; i < position; i++) {
        current = current->next;
    }
    SinglyLinkedListNode* nodeToDelete = current->next;
    current->next = nodeToDelete->next;
    return linkedListHead;
}
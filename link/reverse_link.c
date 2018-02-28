#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>


ListNode * ReverseList(ListNode* phead){
    ListNode *pReverseHead = NULL;
    ListNode *pNode = pHead;
    ListNode *pPrev = NULL;
    while(pNode != NULL){
        ListNode *pNext = pNode->next;

        if (pNext == NULL)
            pReverseHead = pNode;
        pNode->next = pPrev;

        pPrev = pNode
        pNode = pNext
    }
    return pReverseHead;
}

Node *NodeRervese(Node *node){
    if (node == NULL) return NULL;
    if (node->next == NULL) return node;
    Node *n = NodeRervese(node->next);
    if(n != NULL){
        n->next = node;
        node->next = NULL;
    }
    return node;
}
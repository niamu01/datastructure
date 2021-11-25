void reverseLinkedList(LinkedList* pList) 
{
    ListNode *pNode = NULL, *pCurrentNode = NULL, *pPrevNode = NULL;
    if (pList != NULL) 
    {
        pNode = pList->headerNode.pLink;
        while(pNode != NULL) 
        {
            pPrevNode = pCurrentNode;
            pCurrentNode = pNode;
            pNode = pNode->pLink; pCurrentNode->pLink = pPrevNode;
        }
    pList->headerNode.pLink = pCurrentNode;
    }
}
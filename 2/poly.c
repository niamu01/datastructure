int addPolyNodeLast(LinkedList* pList, float coef, int degree)
{
    int ret=FALSE,i=0;

    ListNode node = {0,};
    node.coef = coef;
    node.degree = degree;

    if (pList != NULL) 
    {
        int length = getLinkedListLength(pList);
        ret = addLLElement(pList, length, node);
    }

    return ret;
}

void addPoly(ListHead* A, ListHead* B, ListHead* C)
{
    Node* pA = A->head;
    Node* pB = B->head;
    
     int sum;
    while(pA && pB){ if(pA->expo == pB->expo){ sum = pA->coef + pB->coef;
    addLastNode(C, sum, pA->expo);
    pA=pA->link;
    pB=pB->link;
    } else if(pA->expo > pB->expo){ addLastNode(C, pA->coef, pA->expo);
    pA=pA->link;
    } else{ addLastNode(C, pB->coef, pB->expo);
    pB=pB->link;
    } } for( ;
    pA!=NULL;
    pA=pA->link) addLastNode(C, pA->coef, pA->expo);
    for( ;
    pB!=NULL;
    pB=pB->link) addLastNode(C, pB->coef, pB->expo);
}
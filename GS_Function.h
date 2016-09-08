#ifndef GS_FUNCTION_H_
#define GS_FUNCTION_H_



#include "RC_LinkedList.h"


void IntializeLinkedList ( RC_LinkedList * pHead , RC_LinkedList * pTail ) ;
void CardShuffle ( int irgCardList [ 48 ] , RC_LinkedList * pTail ) ;
void Distribution ( RC_LinkedList * pDeckTail , RC_LinkedList * pHandTail , bool bHand ) ;



RC_LinkedList * pDeckHead ;
RC_LinkedList * pDeckTail ;

RC_LinkedList * pAHandHead ;
RC_LinkedList * pAHandTail ;

RC_LinkedList * pBHandHead ;
RC_LinkedList * pBHandTail ;

RC_LinkedList * pCHandHead ;
RC_LinkedList * pCHandTail ;

RC_LinkedList * pAGetHead ;
RC_LinkedList * pAGetTail ;

RC_LinkedList * pBGetHead ;
RC_LinkedList * pBGetTail ;

RC_LinkedList * pCGetHead ;
RC_LinkedList * pCGetTail ;

RC_LinkedList * pFieldHead ;
RC_LinkedList * pFieldTail ;



#endif
#include "GS_Function.h"
#include "RC_LinkedList.h"



/*
 * 1 = ±¤
 * 2 = ¸Û
 * 3 = ¶ì
 * 4 = ÀÏ¹ÝÇÇ
 * 5 = ½ÖÇÇ
 */
int irgCardList [ 12 ] [ 4 ] = { { 1 , 3 , 4 , 4 } , { 2 , 3 , 4 , 4 } , { 1 , 3 , 4 , 4 } , { 2 , 3 , 4 , 4 } ,
							{ 2 , 3 , 4 , 4 } , { 2 , 3 , 4 , 4 } , { 2 , 3 , 4 , 4 } , { 1 , 2 , 4 , 4 } ,
							{ 2 , 3 , 4 , 4 } , { 2 , 3 , 4 , 4 } , { 1 , 4 , 4 , 5 } , { 1 , 2 , 3 , 5 } } ;


/*
 * 1 = ±¤
 * 2 = ¸Û
 * 3 = ¶ì
 * 4 = ÀÏ¹ÝÇÇ
 * 5 = ½ÖÇÇ
 */
int irgList [ 48 ] = { 11 , 13 , 14 , 14 ,
						22 , 23 , 24 , 24 ,
						31 , 33 , 34 , 34 ,
						42 , 43 , 44 , 44 ,
						52 , 53 , 54 , 54 ,
						62 , 63 , 64 , 64 ,
						72 , 73 , 74 , 74 ,
						81 , 82 , 84 , 84 ,
						92 , 93 , 94 , 94 ,
						102 , 103 , 104 , 104 ,
						111 , 114 , 114 , 115 ,
						121 , 122 , 123 , 125 } ;
/*
 * 1 = ¾ÆÁ÷ ¾È³ª¿È
 * 0 = ´©±º°¡ ¸ÔÀ½
 */
bool brgCardStatus [ 12 ] [ 4 ] = { true } ;


int main ()
{
	IntializeLinkedList ( pDeckHead , pDeckTail ) ;
	IntializeLinkedList ( pAHandHead , pAHandTail ) ;
	IntializeLinkedList ( pBHandHead , pBHandTail ) ;
	IntializeLinkedList ( pCHandHead , pCHandTail ) ;
	IntializeLinkedList ( pAGetHead , pAGetTail ) ;
	IntializeLinkedList ( pBGetHead , pBGetTail ) ;
	IntializeLinkedList ( pCGetHead , pCGetTail ) ;
	IntializeLinkedList ( pFieldHead , pFieldTail ) ;

	CardShuffle ( irgList , pDeckTail ) ;

	Distribution ( pDeckTail , pAHandTail , true ) ;
	Distribution ( pDeckTail , pBHandTail , true ) ;
	Distribution ( pDeckTail , pCHandTail , true ) ;
	Distribution ( pDeckTail , pFieldTail , false ) ;

	/*pDeckHead = ( RC_LinkedList * ) malloc ( sizeof ( RC_LinkedList ) ) ;
	pDeckTail = ( RC_LinkedList * ) malloc ( sizeof ( RC_LinkedList ) ) ;

	pDeckHead -> m_pPrev = NULL ;
	pDeckTail -> m_pNext = NULL ;
	pDeckHead -> m_pNext = pDeckTail ;
	pDeckTail -> m_pPrev = pDeckHead ;*/

}
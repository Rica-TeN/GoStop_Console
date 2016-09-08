#include "RC_LinkedList.h"
#include "GS_Function.h"



/*
 * Initiailize LinkedList's Head and Tail.
 */
void IntializeLinkedList ( RC_LinkedList * pHead , RC_LinkedList * pTail )
{
	pHead = ( RC_LinkedList * ) malloc ( sizeof ( RC_LinkedList ) ) ;
	pTail = ( RC_LinkedList * ) malloc ( sizeof ( RC_LinkedList ) ) ;

	pHead -> m_pPrev = NULL ;
	pTail -> m_pNext = NULL ;
	pHead -> m_pNext = pTail ;
	pTail -> m_pPrev = pHead ;
}


/*
 * Shuffle Card.
 */
void CardShuffle ( int irgCardList [ 48 ] , RC_LinkedList * pTail )
{
	int iCount = 48 ;
	int iRand = 0 ;
	int i = 0 ;


	while ( iCount )
	{
		RC_LinkedList * pNode = ( RC_LinkedList * ) malloc ( sizeof ( RC_LinkedList ) ) ;


		srand ( time ( NULL ) ) ;
		iRand = rand () % iCount ;
		
		pNode -> m_iMonth = irgCardList [ iRand ] / 10 ;
		pNode -> m_iType = irgCardList [ iRand ] % 10 ;
		
		pTail -> m_pPrev -> m_pNext = pNode ;
		pNode -> m_pPrev = pTail -> m_pPrev ;
		pNode -> m_pNext = pTail ;
		pTail -> m_pPrev = pNode ;

		for ( i = iRand ; i < iCount - 1 ; ++i )
		{
			irgCardList [ iRand ] = irgCardList [ iRand + 1 ] ;
		}

		-- iCount ;
	}
}


/*
 * Distribute Card.
 */
void Distribution ( RC_LinkedList * pDeckTail , RC_LinkedList * pHandTail , bool bHand )
{
	//RC_LinkedList * pNode ;
	int i = 0 ;

	if ( true )
	{
		for ( i = 0 ; i < 7 ; ++i )
		{
			RC_LinkedList * pNode = ( RC_LinkedList * ) malloc ( sizeof ( RC_LinkedList ) ) ;
			RC_LinkedList * pDelete = pDeckTail -> m_pPrev ;
			RC_LinkedList * pDelPrev = NULL ;
			RC_LinkedList * pDelNext = NULL ;


			pNode -> m_iMonth = pDelete -> m_iMonth ;
			pNode -> m_iType = pDelete -> m_iType ;

			pHandTail -> m_pPrev -> m_pNext = pNode ;
			pNode -> m_pPrev = pHandTail -> m_pPrev ;
			pNode -> m_pNext = pHandTail ;
			pHandTail -> m_pPrev = pNode ;

			pDelPrev = pDelete -> m_pPrev ;
			pDelNext = pDelete -> m_pNext ;
			pDelPrev -> m_pNext = pDelNext ;
			pDelNext -> m_pPrev = pDelPrev ;


			free ( pDelete ) ;
		}
	}
	else
	{
		for ( i = 0 ; i < 6 ; ++i )
		{
			RC_LinkedList * pNode = ( RC_LinkedList * ) malloc ( sizeof ( RC_LinkedList ) ) ;
			RC_LinkedList * pDelete = pDeckTail -> m_pPrev ;
			RC_LinkedList * pDelPrev = NULL ;
			RC_LinkedList * pDelNext = NULL ;


			pNode -> m_iMonth = pDelete -> m_iMonth ;
			pNode -> m_iType = pDelete -> m_iType ;

			pHandTail -> m_pPrev -> m_pNext = pNode ;
			pNode -> m_pPrev = pHandTail -> m_pPrev ;
			pNode -> m_pNext = pHandTail ;
			pHandTail -> m_pPrev = pNode ;

			pDelPrev = pDelete -> m_pPrev ;
			pDelNext = pDelete -> m_pNext ;
			pDelPrev -> m_pNext = pDelNext ;
			pDelNext -> m_pPrev = pDelPrev ;


			free ( pDelete ) ;
		}
	}

	//int iRand = 0 ;
	//int iCount = 0 ;
	//int iTurn = 0 ;
	//
	//
	//while ( iCount < 28 )
	//{
	//	srand ( time ( NULL ) ) ;
	//	iRand = rand () % 48 ;


	//	if ( brgCardStatus [ iRand / 4 ] [ iRand % 4 ] )
	//	{
	//		if ( ! iTurn )	// Player1
	//		{
	//			irgPlayer1Card [ iCount ] = ( iRand / 4 ) * 10 + iRand % 4 ;
	//			brgCardStatus [ iRand / 4 ] [ iRand % 4 ] = false ;
	//		}
	//		else if ( 1 == iTurn )	//Player2
	//		{
	//			irgPlayer2Card [ iCount - 10 ] = ( iRand / 4 ) * 10 + iRand % 4 ;
	//			brgCardStatus [ iRand / 4 ] [ iRand % 4 ] = false ;
	//		}
	//		else
	//		{
	//			irgField [ iCount - 20 ] = ( iRand / 4 ) * 10 + iRand % 4 ;
	//			brgCardStatus [ iRand / 4 ] [ iRand % 4 ] = false ;
	//		}
	//	}


	//	++ iCount ;

	//	
	//	if ( 10 == iCount )
	//		++ iTurn ;
	//	else if ( 20 == iCount )
	//		++ iTurn ;
	//}
}


/*
 * Interface. View Card List.
 */
void ViewInterface ( RC_LinkedList * pHand )
{

}


/* TODO
 * 
 */
void TossCard ( bool brgCardStatus [] [ 4 ] , int irgPlayer1Card [] , int irgPlayer2Card [] , int irgField [] , int iTurn )
{
	if ( iTurn )	// Player1
	{
		int iRand = 0 ;
		int iChoose = 0 ;


		iChoose = iPickCard ( iChoose ) ;
	}
	else	// Player2
	{

	}
}


/*
 *
 */
int iPickCard ( int iChoose )
{

}

























/*
 * TODO List
 * 패 분배 -> Distribution
 * 필드 8장 ↑
 * 카드 선택 -> iPickCard
 * 카드가 버리는건지, 같은게 있는지 확인 -> TossCard
 * 뻑 폭탄 흔들기 따닥 쪽 쓸이
 * 띠 345광 고도리
 * 점수 계산
 * 패가 어디있냐에 따라 brgCardStatus 조정
 */
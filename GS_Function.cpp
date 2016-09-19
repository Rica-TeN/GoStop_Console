#include "RC_LinkedList.h"
#include "GS_Function.h"



/*
 * Initiailize LinkedList's Head and Tail.
 */
void InitializeLinkedList ( RC_LinkedList * pHead , RC_LinkedList * pTail )
{
	pHead = ( RC_LinkedList * ) malloc ( sizeof ( RC_LinkedList ) ) ;
	pTail = ( RC_LinkedList * ) malloc ( sizeof ( RC_LinkedList ) ) ;

	pHead -> m_pPrev = NULL ;
	pTail -> m_pNext = NULL ;
	pHead -> m_pNext = pTail ;
	pTail -> m_pPrev = pHead ;
}

/*
 * Initialize UserState.
 */
void InitializeUserState ( UserState * pUser )
{
	pUser -> iPlayerTurn = 1 ;
	pUser -> iAPiCount = 0 ;
	pUser -> iBPiCount = 0 ;
	pUser -> iCPiCount = 0 ;
	pUser -> iGoCount = 0 ;
	pUser -> iShakeCount = 0 ;
	pUser -> iBBukCount = 0 ;
	pUser -> iGwangCount = 0 ;
	pUser -> iMungCount = 0 ;
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
			RC_LinkedList * pSort = NULL ;


			pNode -> m_iMonth = pDelete -> m_iMonth ;
			pNode -> m_iType = pDelete -> m_iType ;

			/*pHandTail -> m_pPrev -> m_pNext = pNode ;
			pNode -> m_pPrev = pHandTail -> m_pPrev ;
			pNode -> m_pNext = pHandTail ;
			pHandTail -> m_pPrev = pNode ;*/

			pSort = SortHand ( pNode , pHandTail ) ;

			pSort -> m_pNext -> m_pPrev = pNode ;
			pNode -> m_pNext = pSort -> m_pNext ;
			pSort -> m_pNext = pNode ;
			pNode -> m_pPrev = pSort ;

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
 * Parameter pNode need to be sorted.
 * Compare Node's month and type, and find sequence.
 * return value is pSort.
 * pCompareNode -> m_pNext = pNode
 */
RC_LinkedList * SortHand ( RC_LinkedList * pNode , RC_LinkedList * pHandTail )
{
	RC_LinkedList * pCompareNode = pHandTail ;


	while ( NULL != ( pCompareNode -> m_pPrev -> m_pPrev ) )
	{
		pCompareNode = pCompareNode -> m_pPrev ;

		if ( pNode -> m_iMonth > pCompareNode -> m_iMonth )						// pCompareNode is 11 , pNode is 12
		{
			break ;
		}
		else if ( pNode -> m_iMonth == pCompareNode -> m_iMonth )				// pCompareNode is 12 , pNode is 12
		{
			if ( pNode -> m_iType >= pCompareNode -> m_iType )					// pCompareNode is Mung , pNode is DDi
			{
				break ;
			}
		}
		else																	// pCompareNode is 12 , pNode is 11
		{
			// Here need to be empty.
		}
	}


	if ( NULL == ( pCompareNode -> m_pPrev -> m_pPrev ) )
	{
		pCompareNode = pCompareNode -> m_pPrev ;
	}


	return pCompareNode ;
}


/*
 * Interface. View Card List.
 */
void ViewInterface ( RC_LinkedList * pAHandHead , RC_LinkedList * pBHandHead , RC_LinkedList * pCHandHead ,
					RC_LinkedList * pAGetHead , RC_LinkedList * pBGetHead , RC_LinkedList * pCGetHead , RC_LinkedList * pFieldHead , UserState * pUser )
{
	/*printf ( "A\t : Hand) " ) ;
	RenderHandState ( pAHandHead ) ;
	printf ( "(Score : %d) Got Card) " , iScoreReturn ( pAGetHead ) ) ;
	RenderHandState ( pAGetHead ) ;

	printf ( "B\t : Hand) " ) ;
	RenderHandState ( pBHandHead ) ;
	printf ( "(Score : %d) Got Card) " , iScoreReturn ( pBGetHead ) ) ;
	RenderHandState ( pBGetHead ) ;

	printf ( "C\t : Hand) " ) ;
	RenderHandState ( pCHandHead ) ;
	printf ( "(Score : %d) Got Card) " , iScoreReturn ( pCGetHead ) ) ;
	RenderHandState ( pCGetHead ) ;*/

	RenderUserState ( pAHandHead , pAGetHead , pUser , 1 ) ;
	RenderUserState ( pBHandHead , pBGetHead , pUser , 2 ) ;
	RenderUserState ( pCHandHead , pCGetHead , pUser , 3 ) ;
	RenderField ( pFieldHead ) ;

	printf ( "��� : " ) ;
}


/*
 * Render Player's Hand.
 * This is FUCKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKk
 * I don't use this anymore. Use RenderUserState Function!!!!!!!!!!!!!!!!!!!!
 */
void RenderHandState ( RC_LinkedList * pHead )
{
	RC_LinkedList * pNode = pHead ;


	while ( NULL != ( pNode -> m_pNext -> m_pNext ) )
	{
		pNode = pNode -> m_pNext ;

		printf ( "%d%d " , pNode -> m_iMonth , pNode -> m_iType ) ;
	}

	printf ( "\n" ) ;
}


/*
 * Render Player's State.
 */
void RenderUserState ( RC_LinkedList * pHandHead , RC_LinkedList * pGetHead , UserState * pUser , int iPlayer )
{
	// FFFFFFFFFFFUUUUUUUUUUUUUUUCCCCCCCCCCCCCCCKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK


	RC_LinkedList * pNode = pHandHead ;
	int iGo = 0 ;
	int iShake = 0 ;


	if ( iPlayer == ( pUser -> iPlayerTurn ) )
		printf ( "*" ) ;

	if ( 1 == iPlayer )
	{
		printf ( "A" ) ;
		iGo = ( pUser -> iGoCount ) / 100 ;
		iShake = ( pUser -> iShakeCount ) / 100 ;
	}
	else if ( 2 == iPlayer )
	{
		printf ( "B" ) ;
		iGo = ( pUser -> iGoCount ) % 100 / 10 ;
		iShake = ( pUser -> iShakeCount ) % 100 / 10 ;
	}
	else
	{
		printf ( "C" ) ;
		iGo = ( pUser -> iGoCount ) % 10 ;
		iShake = ( pUser -> iShakeCount ) % 10 ;
	}


	if ( iGo )
		printf ( "%d��\t" , iGo ) ;
	else
		printf ( "\t" ) ;
	if ( iShake )
		printf ( "%d�� ���\t" , iShake ) ;
	else
		printf ( "\t" ) ;

	printf ( ": ��) " ) ;


	while ( NULL != ( pNode -> m_pNext -> m_pNext ) )
	{
		pNode = pNode -> m_pNext ;

//		printf ( "%d%d " , pNode -> m_iMonth , pNode -> m_iType ) ;
		printf ( "%d" , pNode -> m_iMonth ) ;
		if ( 1 == pNode -> m_iType )
			printf ( "��" ) ;
		else if ( 2 == pNode -> m_iType )
			printf ( "��" ) ;
		else if ( 3 == pNode -> m_iType )
			printf ( "��" ) ;
		else if ( 4 == pNode -> m_iType )
			printf ( "��" ) ;
		else
			printf ( "����" ) ;
	}

	printf ( "\n" ) ;


	printf ( "(���� : %d) �� ȭ��) " , iScoreReturn ( pGetHead , pUser , iPlayer ) ) ;

	pNode = pGetHead ;

	while ( NULL != ( pNode -> m_pNext -> m_pNext ) )
	{
		pNode = pNode -> m_pNext ;

//		printf ( "%d%d " , pNode -> m_iMonth , pNode -> m_iType ) ;
		printf ( "%d" , pNode -> m_iMonth ) ;
		if ( 1 == pNode -> m_iType )
			printf ( "��" ) ;
		else if ( 2 == pNode -> m_iType )
			printf ( "��" ) ;
		else if ( 3 == pNode -> m_iType )
			printf ( "��" ) ;
		else if ( 4 == pNode -> m_iType )
			printf ( "��" ) ;
		else
			printf ( "����" ) ;
	}

	printf ( "\n\n" ) ;


	/*switch ( iPlayer )
	{
		default :
		case 1 :
			if ( iPlayer == ( pUser -> iPlayerTurn ) )
				printf ( "*" ) ;

			printf ( "A") ;

			if ( ( pUser -> iGoCount ) / 100 )
				printf ( "%d��\t" , ( pUser -> iGoCount ) / 100 ) ;
			else
				printf ( "\t" ) ;
			if ( ( pUser -> iShakeCount ) / 100 )
				printf ( "%d�� ���\t" , ( pUser -> iGoCount ) / 100 ) ;
			else
				printf ( "\t" ) ;

			printf ( ": ��) " ) ;


			while ( NULL != ( pNode -> m_pNext -> m_pNext ) )
			{
				pNode = pNode -> m_pNext ;

				printf ( "%d%d " , pNode -> m_iMonth , pNode -> m_iType ) ;
			}

			printf ( "\n" ) ;


			printf ( "(���� : %d) �� ȭ��) " , iScoreReturn ( pGetHead ) ) ;

			pNode = pGetHead ;

			while ( NULL != ( pNode -> m_pNext -> m_pNext ) )
			{
				pNode = pNode -> m_pNext ;

				printf ( "%d%d " , pNode -> m_iMonth , pNode -> m_iType ) ;
			}

			printf ( "\n\n" ) ;


			break ;

		
		case 3 :
		default:
			break;
	}*/


}

void RenderField ( RC_LinkedList * pFieldHead )
{
	RC_LinkedList * pNode = pFieldHead ;

	
	printf ( "�� ��) " ) ;


	while ( NULL != ( pNode -> m_pNext -> m_pNext ) )
	{
		pNode = pNode -> m_pNext ;

//		printf ( "%d%d " , pNode -> m_iMonth , pNode -> m_iType ) ;
		printf ( "%d" , pNode -> m_iMonth ) ;
		if ( 1 == pNode -> m_iType )
			printf ( "��" ) ;
		else if ( 2 == pNode -> m_iType )
			printf ( "��" ) ;
		else if ( 3 == pNode -> m_iType )
			printf ( "��" ) ;
		else if ( 4 == pNode -> m_iType )
			printf ( "��" ) ;
		else
			printf ( "����" ) ;
	}

	printf ( "\n\n" ) ;
}


/*
 * Return Player's Score.
 */
int iScoreReturn ( RC_LinkedList * pGetHead , UserState * pUser , int iPlayer )
{
	RC_LinkedList * pNode = pGetHead ;
	int iScore = 0 ;
	int iGwang = 0 ;										// ���� ������ �����ڸ��� 1.
	int iMung = 0 ;											// ����. �� ������� 1, 2, 4�� �����Ͽ� �����ڸ����� �߰�. ��� �����ڸ��� 7�̵Ǹ� ������ 5�� �߰��Ǵ°���.
															// 9���ǰ� �ִٸ� �����ڸ��� 1. ���� ��� ���ߴٸ� �����ڸ��� 1�̰�, ����ؼ� ������ �°Ÿ� 2.
	int iDDi = 0 ;											// �� ���� ����. �� �츦 �ڸ��� �и��ϱⰡ �ѳ� ������.
	int iRedDDi = 0 ;										// ȫ��.
	int iGreenDDi = 0 ;										// �ʴ�.
	int iBlueDDi = 0 ;										// û��.
	int iPi = 0 ;											// 9���ǰ� �ִٸ� �����ڸ��� 1. ���� ��� ���ߴٸ� �����ڸ��� 1, ����ؼ� �ǰ� �ȰŸ� 2.


	while ( NULL != ( pNode -> m_pNext -> m_pNext ) )
	{
		pNode = pNode -> m_pNext ;


		if ( 1 == pNode -> m_iType )
		{
			++ iGwang ;


			if ( 12 == pNode -> m_iMonth )
				iGwang += 10 ;
		}
		else if ( 2 == pNode -> m_iType )
		{
			++ iMung ;


			if ( 2 == pNode -> m_iMonth )
				iMung += 10 ;
			else if ( 4 == pNode -> m_iMonth )
				iMung += 20 ;
			else if ( 8 == pNode -> m_iMonth )
				iMung += 40 ;
			if ( 9 == pNode -> m_iMonth )					// ��� ���θ� �޾ƿ;���.
				iMung += 100 ;
		}
		else if ( 3 == pNode -> m_iType )
		{
			++ iDDi ;


			//if ( 1 == pNode -> m_iMonth )
			//	++ iRedDDi ;
			//else if ( 2 == pNode -> m_iMonth )
			//	iRedDDi += 2 ;
			//else if ( 3 == pNode -> m_iMonth )
			//	iRedDDi += 4 ;
			//else if ( 4 == pNode -> m_iMonth )
			//	++ iGreenDDi ;
			//else if ( 5 == pNode -> m_iMonth )
			//	iGreenDDi += 2 ;
			//else if ( 7 == pNode -> m_iMonth )
			//	iGreenDDi += 4 ;
			//else if ( 6 == pNode -> m_iMonth )
			//	++ iBlueDDi ;
			//else if ( 9 == pNode -> m_iMonth )
			//	iBlueDDi += 2 ;
			//else if ( 19 == pNode -> m_iMonth )
			//	iBlueDDi += 4 ;


			if ( ( 1 == pNode -> m_iMonth ) || ( 2 == pNode -> m_iMonth ) || ( 3 == pNode -> m_iMonth ) )
				++ iRedDDi ;
			else if ( ( 4 == pNode -> m_iMonth ) || ( 5 == pNode -> m_iMonth ) || ( 7 == pNode -> m_iMonth ) )
				++ iGreenDDi ;
			else if ( ( 6 == pNode -> m_iMonth ) || ( 9 == pNode -> m_iMonth ) || ( 10 == pNode -> m_iMonth ) )
				++ iBlueDDi ;
		}
		else if ( 5 == pNode -> m_iType )
		{
			iPi += 2 ;				// 9���� ��ۿ��� �޾ƿ���
		}
		else
			++ iPi ;
	}


	if ( 3 <= ( iGwang % 10 ) )
	{
		if ( 4 == ( iGwang % 10 ) )
			iScore += 4 ;
		else if ( 15 == iGwang )
			iScore += 15 ;
		else if ( 3 == iGwang )
			iScore += 3 ;
		else
			iScore += 2 ;
	}
	
	if ( 5 <= ( iMung % 10 ) )
	{
		iScore += ( iMung - 4 ) ;
	}

	if ( 3 == iRedDDi )
		iScore += 3 ;
	if ( 3 == iGreenDDi )
		iScore += 3 ;
	if ( 3 == iBlueDDi )
		iScore += 3 ;
	if ( 5 <= iDDi )
		iScore += ( iDDi - 4 ) ;

	if ( 10 <= iPi )
		iScore += ( iPi - 9 ) ;

	
	if ( 1 == iPlayer )
	{
		if ( 6 <= iPi )
			pUser -> iAPiCount = 6 ;
		else
			pUser -> iAPiCount = iPi ;

		pUser -> iGwangCount = iGwang % 10 ;
		pUser -> iMungCount = iMung % 10 ;
			
	}
	else if ( 2 == iPlayer )
	{
		if ( 6 <= iPi )
			pUser -> iAPiCount = 6 ;
		else
			pUser -> iAPiCount = iPi ;

		pUser -> iGwangCount = iGwang % 10 ;
		pUser -> iMungCount = iMung % 10 ;
	}
	else
	{
		if ( 6 <= iPi )
			pUser -> iAPiCount = 6 ;
		else
			pUser -> iAPiCount = iPi ;

		pUser -> iGwangCount = iGwang % 10 ;
		pUser -> iMungCount = iMung % 10 ;
	}


	return iScore ;
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
 * �� �й� -> Distribution
 * �ʵ� 8�� ��
 * ī�� ���� -> iPickCard
 * ī�尡 �����°���, ������ �ִ��� Ȯ�� -> TossCard
 * �� ��ź ���� ���� �� ����
 * �� 345�� ����
 * ���� ���
 * �а� ����ֳĿ� ���� brgCardStatus ����
 */
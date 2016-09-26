#ifndef RC_LINKEDLIST_H
#define RC_LINKEDLIST_H



#include <Windows.h>
#include <tchar.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>


typedef struct RC_LinkedList
{
	int m_iMonth ;
	int m_iType ;

	struct RC_LinkedList * m_pPrev ;
	struct RC_LinkedList * m_pNext ;
} RC_LinkedList ;


/*
 * Include User State.
 * 피박은 점수 마지막 계산시 확인하는걸로.
 * 고박, 흔들기, 멍박 포함.
 * N고는 각 유저별로 저장해놓기.
 * 결론적으로 각 유저의 피 개수는 0~6 까지만. 6개 이상이면 6으로.
 * 고, 흔들기, 뻑, 광, 멍은 변수 하나에 저장. 세자리로 각 자리가 유저 각자의 횟수.
 * 백의자리가 A, 십의자리가 B, 일의자리가 C
 */
typedef struct UserState
{
	int m_iPlayerTurn ;
	int m_iAPiCount ;
	int m_iBPiCount ;
	int m_iCPiCount ;
	int m_iGoCount ;
	int m_iShakeCount ;
	int m_iBBukCount ;
	int m_iGwangCount ;
	int m_iMungCount ;
} UserState ;


#endif
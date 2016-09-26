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
 * �ǹ��� ���� ������ ���� Ȯ���ϴ°ɷ�.
 * ���, ����, �۹� ����.
 * N��� �� �������� �����س���.
 * ��������� �� ������ �� ������ 0~6 ������. 6�� �̻��̸� 6����.
 * ��, ����, ��, ��, ���� ���� �ϳ��� ����. ���ڸ��� �� �ڸ��� ���� ������ Ƚ��.
 * �����ڸ��� A, �����ڸ��� B, �����ڸ��� C
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
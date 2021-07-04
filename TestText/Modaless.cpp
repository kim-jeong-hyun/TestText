// Modaless.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "TestText.h"
#include "Modaless.h"
#include "afxdialogex.h"


// CModaless 대화 상자입니다.

IMPLEMENT_DYNAMIC(CModaless, CDialogEx)

CModaless::CModaless(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MODALESS, pParent)
{

}

CModaless::~CModaless()
{
}

void CModaless::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CModaless, CDialogEx)
END_MESSAGE_MAP()


// CModaless 메시지 처리기입니다.

// Modaless.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "TestText.h"
#include "Modaless.h"
#include "afxdialogex.h"


// CModaless ��ȭ �����Դϴ�.

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


// CModaless �޽��� ó�����Դϴ�.

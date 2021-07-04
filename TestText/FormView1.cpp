// FormView1.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "TestText.h"
#include "FormView1.h"


// CFormView1

IMPLEMENT_DYNCREATE(CFormView1, CFormView)

CFormView1::CFormView1()
	: CFormView(IDD_FORMVIEW1)
{
	//m_pTextDlg = NULL;
}

CFormView1::~CFormView1()
{
}

void CFormView1::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TESTLIST, m_listCtrl);
	DDX_Control(pDX, IDC_ADDBUTTON, m_addButton);
}

BEGIN_MESSAGE_MAP(CFormView1, CFormView)
	ON_BN_CLICKED(IDC_ADDBUTTON, &CFormView1::OnBnClickedAddbutton)
END_MESSAGE_MAP()


// CFormView1 진단입니다.

#ifdef _DEBUG
void CFormView1::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CFormView1::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CFormView1 메시지 처리기입니다.


void CFormView1::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	m_listCtrl.InsertColumn(0, "헤더 시작", LVCFMT_CENTER, 50);
	m_listCtrl.InsertColumn(1, "2", LVCFMT_CENTER, 50);
	m_listCtrl.InsertColumn(2, "3", LVCFMT_CENTER, 50);
	m_listCtrl.InsertColumn(3, "4", LVCFMT_CENTER, 50);
	m_listCtrl.InsertColumn(4, "5", LVCFMT_CENTER, 50);
	m_listCtrl.InsertColumn(5, "6", LVCFMT_CENTER, 50);
	m_listCtrl.InsertColumn(6, "7", LVCFMT_CENTER, 80);
	m_listCtrl.InsertColumn(7, "헤더 끝", LVCFMT_CENTER, 70);

	m_addButton.SetWindowText("추가");
}

void CFormView1::OnBnClickedAddbutton()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CTestTextDlg* pMainDlg = (CTestTextDlg*)::AfxGetMainWnd(); //메인 Dlg에 접근

	CString temp, str1, str2, str3;
	pMainDlg->getHeader(temp); //다른 클래스 접근해서 header데이터 가지고 오기

	int ii;
	int aa,bb,cc;

	for (ii = 0; ii < temp.GetLength(); ii++) {
		if (ii == 0) {
			aa = temp.Find("2253", ii) + 4; //2253까지 포함 위치
			str1 = temp.Left(aa); //"0001\r\n0064\r\n0000\r\nHLA\r\n0573\r\n000\r\n200511161753\r\n2253" 40 + 7*2 = 52 \r\n중 r n만 인식함
			str1.Replace("\r\n", " ");
		}
		else if (ii > 0 && ii < temp.GetLength() / 3) {
			bb = temp.Find("2253", aa) + 4;
			str2 = temp.Mid(aa+2,bb-aa-2); // temp.Mid(54, 52); 
			str2.Replace("\r\n", " ");
		}
		else {
			cc = temp.Find("2253", bb) + 4;
			str3 = temp.Mid(bb+2,cc-bb-2); //temp.Mid(108, 52); 
			str3.Replace("\r\n", " ");
		}
	} 
	sliceSpace(str1, 1);
	sliceSpace(str2, 2);
	sliceSpace(str3, 3);
}

void CFormView1::sliceSpace(CString str, int a) {
	CTestTextDlg* pMainDlg = (CTestTextDlg*)::AfxGetMainWnd(); //메인 Dlg에 접근

	CStringArray headArray;
	headArray.SetSize(str.GetLength());
	int i;
	int nCount = pMainDlg->GetFineCharCount(str, ' ');
	switch (a) {
	case 1:
		for (i = 0; i <= nCount; i++) {
			AfxExtractSubString(headArray[i], str, i, ' ');
		}
		m_listCtrl.InsertItem(0, headArray[0]);
		for (i = 1; i <= nCount; i++) {
			m_listCtrl.SetItemText(0,i, headArray[i]);
		}
		break;
	case 2:
		for (i = 0; i <= nCount; i++) {
			AfxExtractSubString(headArray[i], str, i, ' ');
		}
		m_listCtrl.InsertItem(1, headArray[0]);
		for (i = 1; i <= nCount; i++) {
			m_listCtrl.SetItemText(1,i, headArray[i]);
		}
		break;
	case 3:
		for (i = 0; i <= nCount; i++) {
			AfxExtractSubString(headArray[i], str, i, ' ');
		}
		m_listCtrl.InsertItem(2, headArray[0]);
		for (i = 1; i <= nCount; i++) {
			m_listCtrl.SetItemText(2,i, headArray[i]);
		}
		break;
	}
}

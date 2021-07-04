// FormView1.cpp : ���� �����Դϴ�.
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


// CFormView1 �����Դϴ�.

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


// CFormView1 �޽��� ó�����Դϴ�.


void CFormView1::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.

	m_listCtrl.InsertColumn(0, "��� ����", LVCFMT_CENTER, 50);
	m_listCtrl.InsertColumn(1, "2", LVCFMT_CENTER, 50);
	m_listCtrl.InsertColumn(2, "3", LVCFMT_CENTER, 50);
	m_listCtrl.InsertColumn(3, "4", LVCFMT_CENTER, 50);
	m_listCtrl.InsertColumn(4, "5", LVCFMT_CENTER, 50);
	m_listCtrl.InsertColumn(5, "6", LVCFMT_CENTER, 50);
	m_listCtrl.InsertColumn(6, "7", LVCFMT_CENTER, 80);
	m_listCtrl.InsertColumn(7, "��� ��", LVCFMT_CENTER, 70);

	m_addButton.SetWindowText("�߰�");
}

void CFormView1::OnBnClickedAddbutton()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CTestTextDlg* pMainDlg = (CTestTextDlg*)::AfxGetMainWnd(); //���� Dlg�� ����

	CString temp, str1, str2, str3;
	pMainDlg->getHeader(temp); //�ٸ� Ŭ���� �����ؼ� header������ ������ ����

	int ii;
	int aa,bb,cc;

	for (ii = 0; ii < temp.GetLength(); ii++) {
		if (ii == 0) {
			aa = temp.Find("2253", ii) + 4; //2253���� ���� ��ġ
			str1 = temp.Left(aa); //"0001\r\n0064\r\n0000\r\nHLA\r\n0573\r\n000\r\n200511161753\r\n2253" 40 + 7*2 = 52 \r\n�� r n�� �ν���
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
	CTestTextDlg* pMainDlg = (CTestTextDlg*)::AfxGetMainWnd(); //���� Dlg�� ����

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

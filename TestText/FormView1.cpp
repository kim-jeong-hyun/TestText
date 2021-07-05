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
}

CFormView1::~CFormView1()
{
}

void CFormView1::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TESTLIST, m_listCtrl);
	DDX_Control(pDX, IDC_ADDBUTTON, m_addButton);
	DDX_Control(pDX, IDC_ADDDATABUTTON, m_addData);
	DDX_Control(pDX, IDC_DELETEBUTTON, m_deleteButton);
}

BEGIN_MESSAGE_MAP(CFormView1, CFormView)
	ON_BN_CLICKED(IDC_ADDBUTTON, &CFormView1::OnBnClickedAddbutton)
	ON_BN_CLICKED(IDC_ADDDATABUTTON, &CFormView1::OnBnClickedAdddatabutton)
	ON_BN_CLICKED(IDC_DELETEBUTTON, &CFormView1::OnBnClickedDeletebutton)
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
	m_listCtrl.SetExtendedStyle(LVS_EX_FULLROWSELECT); //������ ������ �� �� �� ��ü ����

	m_listCtrl.InsertColumn(0, "���", LVCFMT_CENTER, 30);
	m_listCtrl.InsertColumn(1, "2", LVCFMT_CENTER, 30);
	m_listCtrl.InsertColumn(2, "3", LVCFMT_CENTER, 30);
	m_listCtrl.InsertColumn(3, "4", LVCFMT_CENTER, 30);
	m_listCtrl.InsertColumn(4, "5", LVCFMT_CENTER, 30);
	m_listCtrl.InsertColumn(5, "6", LVCFMT_CENTER, 30);
	m_listCtrl.InsertColumn(6, "7", LVCFMT_CENTER, 50);
	m_listCtrl.InsertColumn(7, "���", LVCFMT_CENTER, 30);

	m_addButton.SetWindowText("��� �߰�");
	m_addData.SetWindowText("������ �߰�");
	m_deleteButton.SetWindowText("������ ����");
}

void CFormView1::OnBnClickedAddbutton()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CTestTextDlg* pMainDlg = (CTestTextDlg*)::AfxGetMainWnd(); //���� Dlg �� ����

	CString tempHeader, str1, str2, str3;

	pMainDlg->getHeader(tempHeader); //�ٸ� Ŭ���� �����ؼ� header ������ ������ ����

	int ii;
	int aa,bb,cc;

	for (ii = 0; ii < tempHeader.GetLength(); ii++) {
		if (ii == 0) {
			aa = tempHeader.Find("2253", ii) + 4; //2253���� ���� ��ġ
			str1 = tempHeader.Left(aa); //"0001\r\n0064\r\n0000\r\nHLA\r\n0573\r\n000\r\n200511161753\r\n2253" 40 + 7*2 = 52 \r\n �� r,n �� �ν���
			str1.Replace("\r\n", " ");
		}
		else if (ii > 0 && ii < tempHeader.GetLength() / 3) {
			bb = tempHeader.Find("2253", aa) + 4;
			str2 = tempHeader.Mid(aa+2,bb-aa-2); // temp.Mid(54, 52); 
			str2.Replace("\r\n", " ");
		}
		else {
			cc = tempHeader.Find("2253", bb) + 4;
			str3 = tempHeader.Mid(bb+2,cc-bb-2); //temp.Mid(108, 52); 
			str3.Replace("\r\n", " ");
		}
	} 
	sliceSpace(str1, 1);
	sliceSpace(str2, 2);
	sliceSpace(str3, 3);
}

void CFormView1::sliceSpace(CString str, int a) {

	CTestTextDlg* pMainDlg = (CTestTextDlg*)::AfxGetMainWnd(); //���� Dlg �� ����
	CStringArray headArray;
	headArray.SetSize(str.GetLength());
	int i;
	int nCount = pMainDlg->GetFineCharCount(str, ' ');
	switch (a) {
	case 1:
		for (i = 0; i <= nCount; i++) {
			AfxExtractSubString(headArray[i], str, i, ' ');
		}
		m_listCtrl.InsertItem(0, headArray[0]); //ù��° �� ù ��
		for (i =1; i <= nCount; i++) {
			m_listCtrl.SetItemText(0,i, headArray[i]); //ù��° �� �ι�° ������ ��� ���
		}
		break;
	case 2:
		for (i = 0; i <= nCount; i++) {
			AfxExtractSubString(headArray[i], str, i, ' ');
		}
		m_listCtrl.InsertItem(1, headArray[0]); //�ι�° �� ù ��
		for (i = 1; i <= nCount; i++) {
			m_listCtrl.SetItemText(1,i, headArray[i]);
		}
		break;
	case 3:
		for (i = 0; i <= nCount; i++) {
			AfxExtractSubString(headArray[i], str, i, ' ');
		}
		m_listCtrl.InsertItem(2, headArray[0]); //����° �� ù ��
		for (i = 1; i <= nCount; i++) {
			m_listCtrl.SetItemText(2,i, headArray[i]);
		}
		break;
	}
}

//������ �߰�
void CFormView1::OnBnClickedAdddatabutton()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CTestTextDlg* pMainDlg = (CTestTextDlg*)::AfxGetMainWnd(); //���� Dlg �� ����
	CString tempData;
	pMainDlg->getData(tempData); //�ٸ� Ŭ������ �����ؼ� data ������ ������ ����

	CString data1, data2, data3;
	
	AfxExtractSubString(data1, tempData, 0, ':');
	AfxExtractSubString(data2, tempData, 1, ':');
	AfxExtractSubString(data3, tempData, 2, ':');

	//������ �� �÷� �߰�
	for (int i = 0; i <= 20; i++) {
		CString temp;
		temp.Format("%d", i);
		m_listCtrl.InsertColumn(i + 8, "data : " + temp, LVCFMT_LEFT, 70);
	} 

	showData(data1, 1);
 	showData(data2, 2);
 	showData(data3, 3);
}

//Ÿ Ŭ�������� data���� �����ͼ� ����ϱ�
void CFormView1::showData(CString str, int a) {
	
	CTestTextDlg* pMainDlg = (CTestTextDlg*)::AfxGetMainWnd(); //���� Dlg �� ����

	int nCount = pMainDlg->GetFineCharCount(str, '^');
	int iSub;
	
	CStringArray subArray;
	subArray.SetSize(nCount+1);

	for (iSub = 0; iSub <= nCount; iSub++) {
		AfxExtractSubString(subArray[iSub], str, iSub, '^'); //�ڸ���
	}

	switch (a) {
	case 1:
		for (iSub = 0; iSub <= nCount; iSub++) {
			if (subArray[iSub].IsEmpty()) {
				m_listCtrl.SetItemText(0, iSub + 8, "������ ����"); //0��° �࿡�� 7�������� ��� ������ ��
			}
			else {
				m_listCtrl.SetItemText(0, iSub + 8, subArray[iSub]); //0��° �࿡�� 7�������� ��� ������ ��
			}
		}
		break;
	case 2:
		for (iSub = 0; iSub <= nCount; iSub++) {
			if (subArray[iSub].IsEmpty()) {
				m_listCtrl.SetItemText(1, iSub + 8, "������ ����"); //0��° �࿡�� 7�������� ��� ������ ��
			}
			else {
				m_listCtrl.SetItemText(1, iSub + 8, subArray[iSub]);
			}
		}
		break;
	case 3:
		for (iSub = 0; iSub <= nCount; iSub++) {
			if (subArray[iSub].IsEmpty()) {
				m_listCtrl.SetItemText(2, iSub + 8, "������ ����"); //0��° �࿡�� 7�������� ��� ������ ��
			} 
			else {
				m_listCtrl.SetItemText(2, iSub + 8, subArray[iSub]);
			}
		}
		break;
	}
}

//���õ� �� ����
void CFormView1::OnBnClickedDeletebutton()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE); //��Ʈ�� ���� ������ 
	POSITION pos = m_listCtrl.GetFirstSelectedItemPosition();
	int index = m_listCtrl.GetNextSelectedItem(pos);
	m_listCtrl.DeleteItem(index);
	UpdateData(FALSE); //���� ���� ��Ʈ��
}

//��ư ������ ������ �־��� ������ �����ͺ���
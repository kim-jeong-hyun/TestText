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
	m_listCtrl.SetExtendedStyle(LVS_EX_FULLROWSELECT); //아이템 선택할 때 한 줄 전체 반전

	m_listCtrl.InsertColumn(0, "헤더", LVCFMT_CENTER, 30);
	m_listCtrl.InsertColumn(1, "2", LVCFMT_CENTER, 30);
	m_listCtrl.InsertColumn(2, "3", LVCFMT_CENTER, 30);
	m_listCtrl.InsertColumn(3, "4", LVCFMT_CENTER, 30);
	m_listCtrl.InsertColumn(4, "5", LVCFMT_CENTER, 30);
	m_listCtrl.InsertColumn(5, "6", LVCFMT_CENTER, 30);
	m_listCtrl.InsertColumn(6, "7", LVCFMT_CENTER, 50);
	m_listCtrl.InsertColumn(7, "헤더", LVCFMT_CENTER, 30);

	m_addButton.SetWindowText("헤더 추가");
	m_addData.SetWindowText("데이터 추가");
	m_deleteButton.SetWindowText("데이터 삭제");
}

void CFormView1::OnBnClickedAddbutton()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CTestTextDlg* pMainDlg = (CTestTextDlg*)::AfxGetMainWnd(); //메인 Dlg 에 접근

	CString tempHeader, str1, str2, str3;

	pMainDlg->getHeader(tempHeader); //다른 클래스 접근해서 header 데이터 가지고 오기

	int ii;
	int aa,bb,cc;

	for (ii = 0; ii < tempHeader.GetLength(); ii++) {
		if (ii == 0) {
			aa = tempHeader.Find("2253", ii) + 4; //2253까지 포함 위치
			str1 = tempHeader.Left(aa); //"0001\r\n0064\r\n0000\r\nHLA\r\n0573\r\n000\r\n200511161753\r\n2253" 40 + 7*2 = 52 \r\n 중 r,n 만 인식함
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

	CTestTextDlg* pMainDlg = (CTestTextDlg*)::AfxGetMainWnd(); //메인 Dlg 에 접근
	CStringArray headArray;
	headArray.SetSize(str.GetLength());
	int i;
	int nCount = pMainDlg->GetFineCharCount(str, ' ');
	switch (a) {
	case 1:
		for (i = 0; i <= nCount; i++) {
			AfxExtractSubString(headArray[i], str, i, ' ');
		}
		m_listCtrl.InsertItem(0, headArray[0]); //첫번째 행 첫 열
		for (i =1; i <= nCount; i++) {
			m_listCtrl.SetItemText(0,i, headArray[i]); //첫번째 행 두번째 열부터 헤더 출력
		}
		break;
	case 2:
		for (i = 0; i <= nCount; i++) {
			AfxExtractSubString(headArray[i], str, i, ' ');
		}
		m_listCtrl.InsertItem(1, headArray[0]); //두번째 행 첫 열
		for (i = 1; i <= nCount; i++) {
			m_listCtrl.SetItemText(1,i, headArray[i]);
		}
		break;
	case 3:
		for (i = 0; i <= nCount; i++) {
			AfxExtractSubString(headArray[i], str, i, ' ');
		}
		m_listCtrl.InsertItem(2, headArray[0]); //세번째 행 첫 열
		for (i = 1; i <= nCount; i++) {
			m_listCtrl.SetItemText(2,i, headArray[i]);
		}
		break;
	}
}

//데이터 추가
void CFormView1::OnBnClickedAdddatabutton()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CTestTextDlg* pMainDlg = (CTestTextDlg*)::AfxGetMainWnd(); //메인 Dlg 에 접근
	CString tempData;
	pMainDlg->getData(tempData); //다른 클래스에 접근해서 data 데이터 가지고 오기

	CString data1, data2, data3;
	
	AfxExtractSubString(data1, tempData, 0, ':');
	AfxExtractSubString(data2, tempData, 1, ':');
	AfxExtractSubString(data3, tempData, 2, ':');

	//데이터 들어갈 컬럼 추가
	for (int i = 0; i <= 20; i++) {
		CString temp;
		temp.Format("%d", i);
		m_listCtrl.InsertColumn(i + 8, "data : " + temp, LVCFMT_LEFT, 70);
	} 

	showData(data1, 1);
 	showData(data2, 2);
 	showData(data3, 3);
}

//타 클래스에서 data변수 가져와서 출력하기
void CFormView1::showData(CString str, int a) {
	
	CTestTextDlg* pMainDlg = (CTestTextDlg*)::AfxGetMainWnd(); //메인 Dlg 에 접근

	int nCount = pMainDlg->GetFineCharCount(str, '^');
	int iSub;
	
	CStringArray subArray;
	subArray.SetSize(nCount+1);

	for (iSub = 0; iSub <= nCount; iSub++) {
		AfxExtractSubString(subArray[iSub], str, iSub, '^'); //자르기
	}

	switch (a) {
	case 1:
		for (iSub = 0; iSub <= nCount; iSub++) {
			if (subArray[iSub].IsEmpty()) {
				m_listCtrl.SetItemText(0, iSub + 8, "데이터 없음"); //0번째 행에서 7번까지는 헤더 데이터 들어감
			}
			else {
				m_listCtrl.SetItemText(0, iSub + 8, subArray[iSub]); //0번째 행에서 7번까지는 헤더 데이터 들어감
			}
		}
		break;
	case 2:
		for (iSub = 0; iSub <= nCount; iSub++) {
			if (subArray[iSub].IsEmpty()) {
				m_listCtrl.SetItemText(1, iSub + 8, "데이터 없음"); //0번째 행에서 7번까지는 헤더 데이터 들어감
			}
			else {
				m_listCtrl.SetItemText(1, iSub + 8, subArray[iSub]);
			}
		}
		break;
	case 3:
		for (iSub = 0; iSub <= nCount; iSub++) {
			if (subArray[iSub].IsEmpty()) {
				m_listCtrl.SetItemText(2, iSub + 8, "데이터 없음"); //0번째 행에서 7번까지는 헤더 데이터 들어감
			} 
			else {
				m_listCtrl.SetItemText(2, iSub + 8, subArray[iSub]);
			}
		}
		break;
	}
}

//선택된 행 삭제
void CFormView1::OnBnClickedDeletebutton()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE); //컨트롤 값을 변수로 
	POSITION pos = m_listCtrl.GetFirstSelectedItemPosition();
	int index = m_listCtrl.GetNextSelectedItem(pos);
	m_listCtrl.DeleteItem(index);
	UpdateData(FALSE); //변수 값을 컨트롤
}

//버튼 눌러서 기존에 넣었던 데이터 가져와보기
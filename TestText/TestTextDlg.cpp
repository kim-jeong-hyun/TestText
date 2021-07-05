
// TestTextDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "TestText.h"
#include "TestTextDlg.h"
#include "afxdialogex.h"
#include "Resource.h"
#include <afxtempl.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 대화 상자 데이터입니다.
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
public:
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)

	ON_WM_SIZE()
END_MESSAGE_MAP()

// CTestTextDlg 대화 상자
CTestTextDlg::CTestTextDlg(CWnd* pParent /*=NULL*/)
: CDialogEx(CTestTextDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

//폼 picture 에 생성하기->따로 위치 지정해줄 필요없음
void CTestTextDlg::AllocForm()
{
	CCreateContext context;
	ZeroMemory(&context, sizeof(context));
	
	CView *pView = (CView*)RUNTIME_CLASS(CFormView1)->CreateObject();

	CRect rectOfPanelArea;
	GetDlgItem(IDC_PICTURE)->GetWindowRect(&rectOfPanelArea);
	ScreenToClient(&rectOfPanelArea);
	
	pView->Create(NULL, NULL, WS_CHILD, rectOfPanelArea, this, IDD_FORMVIEW1, &context);
	pView->OnInitialUpdate();
	m_pFormView1 = pView;

	m_pFormView1->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_PICTURE)->DestroyWindow();
}

void CTestTextDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_edit_text);
	DDX_Control(pDX, IDC_EDIT3, m_editHeader);
	DDX_Control(pDX, IDC_EDIT4, m_editData1);
	DDX_Control(pDX, IDC_EDIT2, m_editLine);
	DDX_Control(pDX, IDC_EDIT7, m_editData2);
	DDX_Control(pDX, IDC_EDIT8, m_editData3);
	DDX_Control(pDX, IDC_NUMDATA, m_NumData);
	DDX_Control(pDX, IDC_X, m_xData);
	DDX_Control(pDX, IDC_Y, m_yData);
	DDX_Control(pDX, IDC_COMBO_NUM2, m_ComboNum2);
	DDX_Control(pDX, IDC_COMBO_COUNT, m_ComboCount);
	DDX_Control(pDX, IDC_ENGCOMBO, m_ComboEng);
	DDX_Control(pDX, IDC_ENGNUM, m_EngNum);
	DDX_Control(pDX, IDC_PACKET, m_editPacket);
	DDX_Control(pDX, IDC_NUM, m_editNum);
	DDX_Control(pDX, IDC_TOTALPACKET, m_editTotalPacket);
	DDX_Control(pDX, IDC_NUMSPIN, m_numSpin);
	DDX_Control(pDX, IDC_EDITSPIN, m_editSpin);
	DDX_Control(pDX, IDC_RADIO2, m_rb1);
	DDX_Control(pDX, IDC_RADIO3, m_rb2);
	DDX_Control(pDX, IDC_RADIO4, m_rb3);
	DDX_Control(pDX, IDC_RADIO5, m_rb4);
	DDX_Control(pDX, IDC_RADIO6, m_rb5);
	DDX_Control(pDX, IDC_RADIO7, m_rb6);
	DDX_Control(pDX, IDC_RADIOBUTTON, m_rbButton);
	DDX_Control(pDX, IDC_PACKETPROGRESSBAR, m_progress);
	DDX_Control(pDX, IDC_VSCROLLBAR, m_vScrollBar);
	DDX_Control(pDX, IDC_HSCROLLBAR, m_hScrollBar);
}

BEGIN_MESSAGE_MAP(CTestTextDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CTestTextDlg::OnBnClickedButtonWrite)
	ON_BN_CLICKED(IDC_BUTTON2, &CTestTextDlg::OnBnClickedButtonSlice)
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_OUTPUTBUTTON, &CTestTextDlg::OnBnClickedOutputbutton)
	ON_BN_CLICKED(IDC_CLEARBUTTON, &CTestTextDlg::OnBnClickedClear)
	ON_BN_CLICKED(IDC_INPUTNUMBUTTON, &CTestTextDlg::OnBnClickedInputnumbutton)
	ON_BN_CLICKED(IDC_INPUTENGBUTTON, &CTestTextDlg::OnBnClickedInputengbutton)
	ON_BN_CLICKED(IDC_INPUTCOORDBUTTON, &CTestTextDlg::OnBnClickedInputcoordbutton)
	ON_BN_CLICKED(IDC_SAVEBUTTON, &CTestTextDlg::OnBnClickedSavebutton)
	ON_NOTIFY(UDN_DELTAPOS, IDC_NUMSPIN, &CTestTextDlg::OnDeltaposNumspin)
	ON_BN_CLICKED(IDC_RADIOBUTTON, &CTestTextDlg::OnBnClickedRadiobutton)
	ON_WM_VSCROLL()
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDC_MODALBUTTON, &CTestTextDlg::OnBnClickedModalbutton)
	ON_BN_CLICKED(IDC_BUTTONFORM, &CTestTextDlg::OnBnClickedButtonform)
	ON_BN_CLICKED(IDC_FORMHIDE, &CTestTextDlg::OnBnClickedFormhide)
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()


// CTestTextDlg 메시지 처리기

BOOL CTestTextDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}
	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	//FormView 실제 생성
	AllocForm();

	//변수 초기화
	totalPacket.SetSize(150);//전체 패킷 길이 설정
	nEng = 1;
	nCount = 0;
	totalCount = 0;
	//변수 초기화

	//번호 데이터 길이 제한
	m_NumData.SetLimitText(100);
	
	//스핀 컨트롤 초기화
	m_editSpin.SetWindowText(_T("0"));//0으로 설정

	m_numSpin.SetRange(0, 500); //0-500까지
	m_numSpin.SetPos(0); 
	//스핀 컨트롤 초기화

	//스크롤바
	CRect VScroll; //스크롤바 위치 저장 변수
	CRect HScroll;
	m_vScrollBar.GetWindowRect(&VScroll); //수직 스크롤바 위치 가지고 오기
	m_hScrollBar.GetWindowRect(&HScroll); //수평 스크롤바 위치 가지고 오기

	m_vScrollBar.SetScrollRange(0, VScroll.Height()); //수직스크롤바 범위 설정
	m_hScrollBar.SetScrollRange(0, HScroll.Width()); //수평스크롤바 범위 설정

	vc.x = 0;
	vc.y = 0; //포인트 변수 초기화

	origin.x = HScroll.left; //origin 초기화
	origin.y = VScroll.top;
	//스크롤바

	//라디오 버튼 초기화
	m_rbButton.SetWindowText(_T("라디오 버튼 확인"));
	m_rb1.SetCheck(BST_CHECKED); //체크된 상태
	m_rb2.SetCheck(BST_UNCHECKED);
	m_rb3.SetCheck(BST_UNCHECKED);
	m_rb4.SetCheck(BST_UNCHECKED);
	m_rb5.SetCheck(BST_UNCHECKED);
	m_rb6.SetCheck(BST_UNCHECKED);

	//프로그레스 바
	m_progress.SetRange(0, 100);
	m_progress.SetPos(0);
	m_progress.SetBarColor(RGB(132, 231, 36));
	//프로그레스 바

	//영문 번호 추가
	m_ComboNum2.AddString(_T("751"));
	m_ComboNum2.AddString(_T("752"));
	m_ComboNum2.AddString(_T("753"));
	m_ComboNum2.AddString(_T("754"));
	
	//영문 반복횟수 추가
	m_ComboCount.AddString(_T("1"));
	m_ComboCount.AddString(_T("2"));
	m_ComboCount.AddString(_T("3"));
	m_ComboCount.AddString(_T("4"));
	m_ComboCount.AddString(_T("5"));
	m_ComboCount.AddString(_T("6"));

	//영문 데이터 추가
	m_ComboEng.AddString(_T("SMALL.ARMS.V"));
	m_ComboEng.AddString(_T("66MM.V"));
	m_ComboEng.AddString(_T("60MM.MTR.HE.V"));
	m_ComboEng.AddString(_T("60MM.MTR.SMK.V"));
	m_ComboEng.AddString(_T("JP8.III"));
	m_ComboEng.AddString(_T("DEMOLITIONS.V"));
	m_ComboEng.AddString(_T("LIGHT.TRUCK.4X4"));
	m_ComboEng.AddString(_T("60MM.MTR"));
	m_ComboEng.AddString(_T("AP.MINE.V"));
	m_ComboEng.AddString(_T("AT.MINE.V"));
	m_ComboEng.AddString(_T("HQ/SVC/SPT/PERS"));
	m_ComboEng.AddString(_T("DISMNTD.TROOPS"));
	m_ComboEng.AddString(_T("PERSONNEL.ALL"));
	m_ComboEng.AddString(_T("66MM.LAW.M72"));
	m_ComboEng.AddString(_T("GRND.LASER.DES"));
	m_ComboEng.AddString(_T("OTHER.EQUIP"));
	m_ComboEng.AddString(_T("INFANTRY/E5-E6")); 
	m_ComboEng.AddString(_T("INFANTRY/E7-E9")); 
	m_ComboEng.AddString(_T("INFANTRY/O1-O3")); 

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CTestTextDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}

void CTestTextDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CTestTextDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();

		CClientDC dc(this);
		
// 		CString str;
// 		str.Format("x: %d, y: %d", pos.x, pos.y);
// 		dc.TextOutA(pos.x, pos.y, str);

		POINT t;
		t.x = vc.x + origin.x;
		t.y = vc.y + origin.y;
		dc.Ellipse(t.x, t.y, t.x + 10, t.y + 10);
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CTestTextDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//Text파일 한줄씩 읽기
void CTestTextDlg::OnBnClickedButtonWrite()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CStdioFile text_file;
	if (text_file.Open("text.txt", CFile::modeRead | CFile::typeText)) {
		CString str;
		while (text_file.ReadString(str)) { //한줄씩 읽기
			list_str += str;
			list_str += "\r\n";
		}
		SetDlgItemText(IDC_EDIT1, list_str);
		text_file.Close();
	}
}

//1줄씩 읽은 str을 자르기
void CTestTextDlg::OnBnClickedButtonSlice()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	GetDlgItemText(IDC_EDIT1, str);

	//첫줄 : 한줄씩 출력하기
	CString oneLine, oneWord, twoLine, twoWord, threeLine, threeWord; //한줄씩, 한줄만

	AfxExtractSubString(oneLine, str, 0, '>'); //한줄씩 자르기
	AfxExtractSubString(twoLine, str, 1, '>'); //한줄씩 자르기
	AfxExtractSubString(threeLine, str, 2, '>'); //한줄씩 자르기

	replaceSpace(oneLine);
	replaceSpace(twoLine);
	replaceSpace(threeLine);
	//한줄씩 출력하기

	//헤더: 헤더 출력
	AfxExtractSubString(oneWord, oneLine, 0, '<'); //헤더만 분리
	RemoveChar(&oneWord, 3);

	AfxExtractSubString(twoWord, twoLine, 0, '<'); //헤더만 분리
	RemoveChar(&twoWord, 3);

	AfxExtractSubString(threeWord, threeLine, 0, '<'); //헤더만 분리
	RemoveChar(&threeWord, 3);

	showHeader(&oneWord, 1);
	showHeader(&twoWord, 2);
	showHeader(&threeWord, 3);
	//헤더 출력

	//데이터 : 데이터 출력
	CString l_data_1st, l_data_2nd, l_data_3rd;

	AfxExtractSubString(l_data_1st, oneLine, 1, '<'); //데이터 분리 <를 기준으로 뒤에꺼를 말함
	AfxExtractSubString(l_data_2nd, twoLine, 1, '<'); //데이터 분리 <를 기준으로 뒤에꺼를 말함
	AfxExtractSubString(l_data_3rd, threeLine, 1, '<'); //데이터 분리 <를 기준으로 뒤에꺼를 말함
	
	sliceStr(m_editData1, &l_data_1st, 1);
	sliceStr(m_editData2, &l_data_2nd, 2);
	sliceStr(m_editData3, &l_data_3rd, 3);
	
	m_data += l_data_1st + ":" + l_data_2nd + ":" + l_data_3rd;
	//데이터 : 데이터 출력

}

//한줄 출력
void CTestTextDlg::replaceSpace(CString pStr) {
	CString temp;
	temp = pStr;
	temp.Replace('<', ' ');

	AppendText(m_editLine, temp);
}

//헤더 출력
void CTestTextDlg::showHeader(CString *pText, int a) {

	int iSub = 0;
	CStringArray strArray;
	strArray.SetSize(8);//크기 설정
	CString tempHeader;
	
	for (iSub = 0; iSub < 8; iSub++) {
		AfxExtractSubString(strArray[iSub], *pText, iSub, '^'); //헤더 ^로 자르기
	}
	for (iSub = 0; iSub < 8; iSub++) {
		tempHeader += strArray.GetAt(iSub);
		tempHeader += "\r\n";
	}

	switch (a) {
	case 1:
		SetDlgItemText(IDC_EDIT3, tempHeader);
		m_header += tempHeader;
		break;
	case 2:
		SetDlgItemText(IDC_EDIT5, tempHeader);
		m_header += tempHeader;
		break;
	case 3:
		SetDlgItemText(IDC_EDIT6, tempHeader);
		m_header += tempHeader;
		break;
	}

}

//데이터 출력
void CTestTextDlg::sliceStr(CEdit& edit, CString *pStr, int a) {
	//구분해서 담을 배열 생성
	CStringArray dataArray;//데이터 구분자로 나눠서 담을 변수
	dataArray.SetSize(100);

	int iSub = 0;
	int nCount = GetFineCharCount(*pStr, '^'); //^개수

	//^로 구분한거 문자배열에 넣기
	for (iSub = 0; iSub <= nCount; iSub++) {
		AfxExtractSubString(dataArray[iSub], *pStr, iSub, '^');
	}

	for (iSub = 0; iSub <= nCount; iSub++) {
		CString data;//데이터 변수
		data += dataArray.GetAt(iSub);
		data += "\r\n";
		//데이터 시작부분
		switch (a) {
		case 1: //첫번째 데이터
			if (iSub == 0) {
				firstRepeat(edit, &data, iSub);
			}
			if (iSub == 1 || iSub == 2 || iSub == 3 || iSub == 4 || iSub == 6
				|| iSub == 7 || iSub == 8 || iSub == 9 || iSub == 10 || iSub == 11
				|| iSub == 12 || iSub == 13 || iSub == 14 || iSub == 15 || iSub == 16 || iSub == 18 || iSub == 19 || iSub == 20)
			{
				semicolonMtd(edit, &data, iSub);
			}
			if (iSub == 5 || iSub == 17)
			{
				RepeatMtd(edit, &data, iSub);
			}
			break;
		case 2: //두번재 데이터
			if (iSub == 0) {
				firstRepeat(edit, &data, iSub);
			}
			if (iSub == 2 || iSub == 4 || iSub == 5 || iSub == 7 || iSub == 8 || iSub == 9 || iSub == 10 || iSub == 11
				|| iSub == 12 || iSub == 13 || iSub == 14 || iSub == 15 || iSub == 16 || iSub == 17 || iSub == 19 || iSub == 20)
			{
				semicolonMtd(edit, &data, iSub);
			}
			if (iSub == 1 || iSub == 6 || iSub == 18) {
				RepeatMtd(edit, &data, iSub);
			}
			break;
		case 3: //세번째 데이터
			if (iSub == 0 || iSub == 1 || iSub == 2 || iSub == 4 || iSub == 5 || iSub == 6
				|| iSub == 7 || iSub == 8 || iSub == 9 || iSub == 10 || iSub == 11
				|| iSub == 12 || iSub == 13 || iSub == 14 || iSub == 16 || iSub == 17) {
				semicolonMtd(edit, &data, iSub);
			}
			if (iSub == 3 || iSub == 15) {
				RepeatMtd(edit, &data, iSub);
			}
			break;
		}
	}
}

//초반에 반복되는 경우 함수
void CTestTextDlg::firstRepeat(CEdit& edit, CString *pStr, int iSub)
{
	CString dataStart;
	dataStart = pStr->Left(6);
	CString s_count = pStr->Mid(6, 1);
	dataStart += s_count;
	dataStart += "개\r\n";
	AppendText(edit, dataStart);

	CString data2nd = pStr->Mid(8); //5개 이후의 문자 추출
	data2nd += "\r\n";

	sliceData(edit, &data2nd, iSub, s_count);
}

//:써야하는 함수
void CTestTextDlg::semicolonMtd(CEdit& edit, CString *pStr, int iSub) {
	CString temp;
	int a = pStr->Find(' ');
	temp = pStr->Left(a);
	temp += " : ";
	temp += pStr->Mid(a);
	AppendText(edit, temp);
}

//나중에 반복되는 경우 함수
void CTestTextDlg::RepeatMtd(CEdit& edit, CString *pStr, int iSub) {
	CString temp;
	temp = pStr->Left(6);
	CString s_count = pStr->Mid(6, 1);
	temp += s_count;
	temp += "개\r\n";
	AppendText(edit, temp);
	temp = "";

	temp = pStr->Mid(8);
	sliceData(edit, &temp, iSub, s_count);
}

void CTestTextDlg::sliceData(CEdit& edit, CString *pStr, int iSub, CString s_count) {
	int t = 0; //12->t
	int count = 0;//잘린 횟수
	CString temp;
	int k = pStr->GetLength();
	for (int i = 0; i < k; i++) {
		int c = pStr->Find(' ', i);

		if (i == c) {
			++count;
			if (count == 1) //맨 처음 잘린 경우
			{
				temp += pStr->Mid(t, c);
			}
			else
			{
				temp += pStr->Mid(t, c - t);
			}
			t = c;
			if (count % 4 == 0) { //4개씩 잘렸을 때 
				temp += "\r\n";
				if (count != 4) {
					temp.Delete(0, 1);
				}
				addSpace(&temp);
				AppendText(edit, temp);
				temp = "";
			}
		}

		if (i == k - 1) { //마지막 i 에서 공백을 못찾아서 따로 뺌
			temp += pStr->Mid(t, i - t);
			if (iSub > 0) temp += "\r\n";
			if (count % 4 != 0) {
				if (s_count != "1")
					temp.Delete(0, 1);
			}
			addSpace(&temp); //쉼표 넣고 출력하기
			AppendText(edit, temp);
			temp = "";
		}
	}
}

//공백에 ,넣기 함수
CString CTestTextDlg::addSpace(CString *str) {
	CUIntArray array;
	int j;
	int a;
	int countSpace = GetFineCharCount(*str, ' '); //스페이스 개수
	array.SetSize(10);

	for (j = 0; j < countSpace; j++) { //스페이스 개수만큼 반복
		if (j == 0) { //첫번째 스페이스 찾기
			a = str->Find(' ');
			array[j] = a;
		}
		else {
			int b = str->Find(' ', a + 1);
			array[j] = b;
			a = b;
		}
	}
	for (int i = 1; i < countSpace; i++) {
		if (i == 1) {
			str->Insert(array[i], ',');
		}
		else
		{
			str->Insert(array[i] + 1, ',');
		}
	}
	return *str;
}

//edit컨트롤에 줄바꿈 추가
void CTestTextDlg::AppendText(CEdit& edit, LPCTSTR pText) {
	int n_len = edit.GetWindowTextLength();
	edit.SetFocus();
	edit.SetSel(n_len, n_len);
	edit.ReplaceSel(pText);
}

//특정 문자 제거
void CTestTextDlg::RemoveChar(CString *pStr, int a) {
	switch (a) {
	case 0:
		pStr->Remove('#');
		break;
	case 1:
		pStr->Remove('\n');
		break;
	case 2:
		pStr->Remove('\r');
		break;
	case 3:
		pStr->Remove('#');
		pStr->Remove('\n');
		pStr->Remove('\r');
		break;
	}
}

//특정 문자 수 
int CTestTextDlg::GetFineCharCount(CString str, char find_char) {
	int str_len = str.GetLength();
	int find_cnt = 0;

	for (int i = 0; i < str_len; i++) {
		if (str[i] == find_char) {
			find_cnt++;
		}
	}
	return find_cnt;
}

//숫자 데이터 입력
void CTestTextDlg::OnBnClickedInputnumbutton()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//입력된 숫자 데이터 가져오기
	CString numData;
	GetDlgItemText(IDC_NUMDATA, numData);
	if (numData.IsEmpty() != TRUE) { //비어있지 않으면
		addNumData(&numData);
	}
	else {
		MessageBox(_T("데이터 입력하세요"));
	}
	//CString temp; //임시변수설정
	if (numData.Find("93 101") != -1) { //패킷 종료임을 알림 -1이 없는경우
		totalCount++;
		numData.Delete(numData.GetLength() - 1, 1);
		total += numData;
		totalPacket[totalCount - 1] = total;//현재까지 데이터 배열에 넣기
		total += "\r\n";
		SetDlgItemText(IDC_PACKET, total);
	}
	else { //패킷 작성상태임
		total += numData;
		SetDlgItemText(IDC_PACKET, total); //추가적으로 붙이기
	}

	SetDlgItemText(IDC_NUM, "");
	SetDlgItemText(IDC_NUMDATA, "");
}
//숫자 데이터 입력
void CTestTextDlg::addNumData(CString *pStr) {
	//숫자 데이터의 번호 가져오기
	CString num;
	GetDlgItemText(IDC_NUM, num);

	if (num.IsEmpty())
	{
		MessageBox(_T("번호 또는 데이터를 입력하세요"));
		pStr->Empty();
	}
	else {
		if (num == "302") { //번호가 302인 경우
			pStr->Insert(1, '*');
			pStr->Insert(3, '*');
			CString temp = pStr->Right(5);
			pStr->Replace(temp, "*****");
		}
		num += " " + *pStr + "^";
		*pStr = num;
		totalNum = *pStr;
	}
}
//영문 데이터 입력
void CTestTextDlg::OnBnClickedInputengbutton()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString EngData;
	GetDlgItemText(IDC_ENGCOMBO, EngData);
	if (EngData.IsEmpty() != TRUE) {
		addEngData(&EngData);
	}
	else {
		MessageBox(_T("데이터 입력하세요"));
	}
	total += EngData;
	SetDlgItemText(IDC_PACKET, total);
	
	SetDlgItemText(IDC_ENGCOMBO, "");
	SetDlgItemText(IDC_ENGNUM, "");
}
//영문 데이터 입력
void  CTestTextDlg::addEngData(CString *pStr) {

	CString num, numCount;
	int numC;
	GetDlgItemText(IDC_COMBO_NUM2, num); //ex) 751
	num += " ";
	GetDlgItemText(IDC_COMBO_COUNT, numCount); //ex) 751 2
	numC = _ttoi(numCount); //반복횟수 int로 변환
	num += numCount + ' ';

	int nLength;
	nLength = pStr->GetLength();

	CString engNum;
	GetDlgItemText(IDC_ENGNUM, engNum); //ex) 751 2 ANSIC ANSIC 0 0

	if (engNum.IsEmpty() || num.IsEmpty() || numCount.IsEmpty()){
		MessageBox(_T("번호 또는 영문을 입력하세요"));
		pStr->Empty();
	}
	else {
		engNum.Replace(',', ' ');

		if (*pStr == "INFANTRY/E5-E6" || *pStr == "INFANTRY/E7-E9") {
			CString temp = "ENL";
			*pStr = temp + *pStr;
			pStr->Insert(temp.GetLength(), " ");
		}
		else if (*pStr == "INFANTRY/O1-O3") {
			CString temp = "OFFICERS";
			*pStr = temp + *pStr;
			pStr->Insert(temp.GetLength(), " ");
		}
		else {
			*pStr += *pStr;
			pStr->Insert(nLength, " "); //ANSIC ANSIC
		}

		*pStr += " " + engNum; //ANSIC ANSIC 0 0

		if (nEng == 1) {
			*pStr = num + *pStr + " ";
			totalEng = *pStr;

			if (nEng == numC) {//반복 다 했으면
				pStr->Delete(pStr->GetLength() - 1, 2);
				*pStr += "^";
				nEng = 1;
				nCount = 2; //반복 끝
			}
			else {
				nEng++;
				nCount = 1;
			}
		}
		else if (nEng > 1 && nEng <= numC) { //반복횟수 2 이상
			totalEng = *pStr + " ";
			*pStr = totalEng;

			if (nEng == numC) {//반복 다 했으면
				pStr->Delete(pStr->GetLength() - 1, 2);
				*pStr += "^";
				nEng = 1;
				nCount = 2; //반복 끝
			}
			else{
				nEng++;
				nCount = 1;
			}
		}
	}
}
//좌표 데이터 입력
void CTestTextDlg::OnBnClickedInputcoordbutton()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString xData, yData, sum;
	GetDlgItemText(IDC_X, xData);
	GetDlgItemText(IDC_Y, yData);
	if (xData.GetLength() != 6 || yData.GetLength() != 7) {
		MessageBox(_T("x좌표는 6자리, y좌표는 7자리를 입력하세요"));
		xData.Empty();
		yData.Empty();
	}
	else {
		if (xData.IsEmpty() != TRUE && yData.IsEmpty() != TRUE) {
			sum = xData + " " + yData;
			addCoordData(&sum);
		} 
		total += sum;
		SetDlgItemText(IDC_PACKET, total);

		SetDlgItemText(IDC_X, "");
		SetDlgItemText(IDC_Y, "");
	}
}
//좌표 데이터 입력
void CTestTextDlg::addCoordData(CString *pStr) {
	CString num;
	num += "400 " + *pStr + "^";
	*pStr = num;
	totalCoord = num;
	*pStr = totalCoord;
}

//초기화
void CTestTextDlg::OnBnClickedClear()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	totalNum.Empty();
	totalEng.Empty();
	totalCoord.Empty();
	total.Empty();

	nEng = 1;

	SetDlgItemText(IDC_PACKET, "");

	totalCount = 0;
	SetDlgItemText(IDC_TOTALPACKET, "");
}
//텍스트 파일로 저장
void CTestTextDlg::OnBnClickedSavebutton()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString m_strPath;//파일경로
	CStdioFile file;

	CFileException ex;
	CFileDialog dlg(FALSE, _T("*.txt"), NULL, OFN_FILEMUSTEXIST | OFN_OVERWRITEPROMPT, _T("txt Files(*.txt)|*.txt|"), NULL);
	bool bOpen = false;
	if (dlg.DoModal() == IDOK) {
		m_strPath = dlg.GetPathName();
		if (m_strPath.Right(4) != _T(".txt")) {
			m_strPath += _T(".txt");
		}

		file.Open(m_strPath, CFile::modeCreate | CFile::modeReadWrite, &ex);

		CString str;
		GetDlgItemText(IDC_TOTALPACKET, str);
		str.Replace("\r\n", "\n");
		file.WriteString(str);

		file.Close();
		bOpen = true;
	}

	if (bOpen == true) {
		MessageBox(_T("파일 저장 완료"));
	}
	else {
		MessageBox(_T("파일 저장 실패"));
	}
}

//패킷 전송
void CTestTextDlg::OnBnClickedOutputbutton()
{
	//출력 버튼 누르면 
	//전체 데이터 출력
	if (totalCount == 0) {
		MessageBox(_T("패킷 미완성"));
		TRACE0(_T("패킷 미완성"));
	}
	else if (totalCount == 1) {
		CString temp = totalPacket[totalCount - 1];
		temp.Insert(0, '<');
		temp.Delete(temp.GetLength(), 1);
		temp.Insert(temp.GetLength(), ">\r\n"); // < >로 묶기
		outputText(&temp);
	}
	else {
		CString temp = totalPacket[totalCount - 1];
		temp.Delete(0, totalPacket[totalCount - 2].GetLength() + 2);
		temp.Insert(0, '<');
		temp.Delete(temp.GetLength(), 1);
		temp.Insert(temp.GetLength(), ">\r\n"); // < >로 묶기
		outputText(&temp);
	}
}

void CTestTextDlg::outputText(CString *pStr) {
	CString header = "#0001^0064^0000^HLA^0573^000^200511161753^2253";
	if (totalCount == 1) {
		*pStr = header + *pStr;
		AppendText(m_editTotalPacket, *pStr);
		pStr->Empty();
		m_progress.SetPos(100 / 3);
	}
	else if (totalCount == 2) {
		header.Replace("0573", "0700");
		*pStr = header + *pStr;
		AppendText(m_editTotalPacket, *pStr);
		pStr->Empty();
		m_progress.SetPos(100 / 2);
	}
	else if (totalCount == 3) {
		header.Replace("0573", "0251");
		*pStr = header + *pStr;
		AppendText(m_editTotalPacket, *pStr);
		pStr->Empty();
		m_progress.SetPos(100 / 1);
		MessageBox(_T("전송 100% 패킷 전송 완료"));
	}
	else {
		m_progress.SetPos(100 / 1);
		MessageBox(_T("패킷 읽기 종료"));
		m_editPacket.SetSel(-1, -1);
		m_editPacket.Clear();
	}
}

void CTestTextDlg::OnDeltaposNumspin(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	//값이 바뀌기 전 값들로 변한 뒤 값 연산
	// 값 = 현재 값+증/감
	int iVal = pNMUpDown->iPos + pNMUpDown->iDelta;

	if ((0 <= iVal) && (iVal <= 500)) {
		CString str;
		str.Format(_T("%d\n"), iVal);
		m_editSpin.SetWindowText(str);
		m_editNum.SetWindowText(str);
	}

	*pResult = 0;
}

void CTestTextDlg::OnBnClickedRadiobutton()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString temp;
	if (m_rb1.GetCheck() == BST_CHECKED) {
		GetDlgItemText(IDC_RADIO2, temp);
		temp += "\r\n";
		SetDlgItemText(IDC_PACKET, temp);
	}
	else if (m_rb2.GetCheck() == BST_CHECKED) {
		GetDlgItemText(IDC_RADIO3, temp);
		temp += "\r\n";
		AppendText(m_editPacket, temp);
	}
	else if (m_rb3.GetCheck() == BST_CHECKED) {
		GetDlgItemText(IDC_RADIO4, temp);
		temp += "\r\n";
		AppendText(m_editPacket, temp);
	}
	else if (m_rb4.GetCheck() == BST_CHECKED) {
		GetDlgItemText(IDC_RADIO5, temp);
		temp += "\r\n";
		AppendText(m_editPacket, temp);
	}
	else if (m_rb4.GetCheck() == BST_CHECKED) {
		GetDlgItemText(IDC_RADIO5, temp);
		temp += "\r\n";
		AppendText(m_editPacket, temp);
	}
	else if (m_rb5.GetCheck() == BST_CHECKED) {
		GetDlgItemText(IDC_RADIO6, temp);
		temp += "\r\n";
		AppendText(m_editPacket, temp);
	}
	else if (m_rb6.GetCheck() == BST_CHECKED) {
		GetDlgItemText(IDC_RADIO7, temp);

		AppendText(m_editPacket, temp);
	}
}

void CTestTextDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (pScrollBar->GetSafeHwnd() == m_hScrollBar.GetSafeHwnd()) {
	//ScrollBar ID확인
		int pos;
		pos = m_hScrollBar.GetScrollPos();//스크롤 현재 위치 가지고 오기

		if (nSBCode == SB_LINEDOWN) {
			m_hScrollBar.SetScrollPos(pos + 10); //line 단위 이동 event
		}
		else if (nSBCode == SB_LINEUP) {
			m_hScrollBar.SetScrollPos(pos - 10);
		}
		else if (nSBCode == SB_PAGEDOWN) {
			m_hScrollBar.SetScrollPos(pos + 50); //page 단위 이동
		} 
		else if (nSBCode == SB_PAGEUP) {
			m_hScrollBar.SetScrollPos(pos - 50);
		}
		else if (nSBCode == SB_THUMBTRACK) { //스크롤 마우스로 끌때 
			m_hScrollBar.SetScrollPos(nPos);
		}
		vc.x = m_hScrollBar.GetScrollPos(); //현재 스크롤 위치 포인트에 저장

		OnPaint(); //윈도 다시 그리기

	}
	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CTestTextDlg::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	int pos;
	pos = m_vScrollBar.GetScrollPos(); //현재 위치

	if (nSBCode == SB_LINEDOWN) {
		m_vScrollBar.SetScrollPos(pos + 10);
	}
	else if (nSBCode == SB_LINEUP) {
		m_vScrollBar.SetScrollPos(pos - 10);
	}
	else if (nSBCode == SB_PAGEDOWN) {
		m_vScrollBar.SetScrollPos(pos + 50);
	}
	else if (nSBCode == SB_PAGEUP) {
		m_vScrollBar.SetScrollPos(pos - 50);
	}
	else if (nSBCode == SB_THUMBTRACK) {
		m_vScrollBar.SetScrollPos(nPos);
	}
	
	vc.y = m_vScrollBar.GetScrollPos();
	OnPaint();

	CDialogEx::OnVScroll(nSBCode, nPos, pScrollBar);
}

//모달 생성
void CTestTextDlg::OnBnClickedModalbutton()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_pDlg = new CModaless;
	if (m_pDlg->GetSafeHwnd() == NULL) {
		m_pDlg->Create(IDD_MODALESS);
	}
	m_pDlg->ShowWindow(SW_SHOW);
}
//폼 나타내기
void CTestTextDlg::OnBnClickedButtonform()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다
	m_pFormView1->ShowWindow(SW_SHOW);
}
//폼 숨기기
void CTestTextDlg::OnBnClickedFormhide()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_pFormView1->ShowWindow(SW_HIDE);
}

void CTestTextDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
// 	pos = point;
// 	Invalidate();
	CDialogEx::OnMouseMove(nFlags, point);
}

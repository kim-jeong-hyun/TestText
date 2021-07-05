
// TestTextDlg.cpp : ���� ����
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

// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	// �����Դϴ�.
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

// CTestTextDlg ��ȭ ����
CTestTextDlg::CTestTextDlg(CWnd* pParent /*=NULL*/)
: CDialogEx(CTestTextDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

//�� picture �� �����ϱ�->���� ��ġ �������� �ʿ����
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


// CTestTextDlg �޽��� ó����

BOOL CTestTextDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
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
	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	//FormView ���� ����
	AllocForm();

	//���� �ʱ�ȭ
	totalPacket.SetSize(150);//��ü ��Ŷ ���� ����
	nEng = 1;
	nCount = 0;
	totalCount = 0;
	//���� �ʱ�ȭ

	//��ȣ ������ ���� ����
	m_NumData.SetLimitText(100);
	
	//���� ��Ʈ�� �ʱ�ȭ
	m_editSpin.SetWindowText(_T("0"));//0���� ����

	m_numSpin.SetRange(0, 500); //0-500����
	m_numSpin.SetPos(0); 
	//���� ��Ʈ�� �ʱ�ȭ

	//��ũ�ѹ�
	CRect VScroll; //��ũ�ѹ� ��ġ ���� ����
	CRect HScroll;
	m_vScrollBar.GetWindowRect(&VScroll); //���� ��ũ�ѹ� ��ġ ������ ����
	m_hScrollBar.GetWindowRect(&HScroll); //���� ��ũ�ѹ� ��ġ ������ ����

	m_vScrollBar.SetScrollRange(0, VScroll.Height()); //������ũ�ѹ� ���� ����
	m_hScrollBar.SetScrollRange(0, HScroll.Width()); //����ũ�ѹ� ���� ����

	vc.x = 0;
	vc.y = 0; //����Ʈ ���� �ʱ�ȭ

	origin.x = HScroll.left; //origin �ʱ�ȭ
	origin.y = VScroll.top;
	//��ũ�ѹ�

	//���� ��ư �ʱ�ȭ
	m_rbButton.SetWindowText(_T("���� ��ư Ȯ��"));
	m_rb1.SetCheck(BST_CHECKED); //üũ�� ����
	m_rb2.SetCheck(BST_UNCHECKED);
	m_rb3.SetCheck(BST_UNCHECKED);
	m_rb4.SetCheck(BST_UNCHECKED);
	m_rb5.SetCheck(BST_UNCHECKED);
	m_rb6.SetCheck(BST_UNCHECKED);

	//���α׷��� ��
	m_progress.SetRange(0, 100);
	m_progress.SetPos(0);
	m_progress.SetBarColor(RGB(132, 231, 36));
	//���α׷��� ��

	//���� ��ȣ �߰�
	m_ComboNum2.AddString(_T("751"));
	m_ComboNum2.AddString(_T("752"));
	m_ComboNum2.AddString(_T("753"));
	m_ComboNum2.AddString(_T("754"));
	
	//���� �ݺ�Ƚ�� �߰�
	m_ComboCount.AddString(_T("1"));
	m_ComboCount.AddString(_T("2"));
	m_ComboCount.AddString(_T("3"));
	m_ComboCount.AddString(_T("4"));
	m_ComboCount.AddString(_T("5"));
	m_ComboCount.AddString(_T("6"));

	//���� ������ �߰�
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

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CTestTextDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CTestTextDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
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

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CTestTextDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//Text���� ���پ� �б�
void CTestTextDlg::OnBnClickedButtonWrite()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CStdioFile text_file;
	if (text_file.Open("text.txt", CFile::modeRead | CFile::typeText)) {
		CString str;
		while (text_file.ReadString(str)) { //���پ� �б�
			list_str += str;
			list_str += "\r\n";
		}
		SetDlgItemText(IDC_EDIT1, list_str);
		text_file.Close();
	}
}

//1�پ� ���� str�� �ڸ���
void CTestTextDlg::OnBnClickedButtonSlice()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString str;
	GetDlgItemText(IDC_EDIT1, str);

	//ù�� : ���پ� ����ϱ�
	CString oneLine, oneWord, twoLine, twoWord, threeLine, threeWord; //���پ�, ���ٸ�

	AfxExtractSubString(oneLine, str, 0, '>'); //���پ� �ڸ���
	AfxExtractSubString(twoLine, str, 1, '>'); //���پ� �ڸ���
	AfxExtractSubString(threeLine, str, 2, '>'); //���پ� �ڸ���

	replaceSpace(oneLine);
	replaceSpace(twoLine);
	replaceSpace(threeLine);
	//���پ� ����ϱ�

	//���: ��� ���
	AfxExtractSubString(oneWord, oneLine, 0, '<'); //����� �и�
	RemoveChar(&oneWord, 3);

	AfxExtractSubString(twoWord, twoLine, 0, '<'); //����� �и�
	RemoveChar(&twoWord, 3);

	AfxExtractSubString(threeWord, threeLine, 0, '<'); //����� �и�
	RemoveChar(&threeWord, 3);

	showHeader(&oneWord, 1);
	showHeader(&twoWord, 2);
	showHeader(&threeWord, 3);
	//��� ���

	//������ : ������ ���
	CString l_data_1st, l_data_2nd, l_data_3rd;

	AfxExtractSubString(l_data_1st, oneLine, 1, '<'); //������ �и� <�� �������� �ڿ����� ����
	AfxExtractSubString(l_data_2nd, twoLine, 1, '<'); //������ �и� <�� �������� �ڿ����� ����
	AfxExtractSubString(l_data_3rd, threeLine, 1, '<'); //������ �и� <�� �������� �ڿ����� ����
	
	sliceStr(m_editData1, &l_data_1st, 1);
	sliceStr(m_editData2, &l_data_2nd, 2);
	sliceStr(m_editData3, &l_data_3rd, 3);
	
	m_data += l_data_1st + ":" + l_data_2nd + ":" + l_data_3rd;
	//������ : ������ ���

}

//���� ���
void CTestTextDlg::replaceSpace(CString pStr) {
	CString temp;
	temp = pStr;
	temp.Replace('<', ' ');

	AppendText(m_editLine, temp);
}

//��� ���
void CTestTextDlg::showHeader(CString *pText, int a) {

	int iSub = 0;
	CStringArray strArray;
	strArray.SetSize(8);//ũ�� ����
	CString tempHeader;
	
	for (iSub = 0; iSub < 8; iSub++) {
		AfxExtractSubString(strArray[iSub], *pText, iSub, '^'); //��� ^�� �ڸ���
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

//������ ���
void CTestTextDlg::sliceStr(CEdit& edit, CString *pStr, int a) {
	//�����ؼ� ���� �迭 ����
	CStringArray dataArray;//������ �����ڷ� ������ ���� ����
	dataArray.SetSize(100);

	int iSub = 0;
	int nCount = GetFineCharCount(*pStr, '^'); //^����

	//^�� �����Ѱ� ���ڹ迭�� �ֱ�
	for (iSub = 0; iSub <= nCount; iSub++) {
		AfxExtractSubString(dataArray[iSub], *pStr, iSub, '^');
	}

	for (iSub = 0; iSub <= nCount; iSub++) {
		CString data;//������ ����
		data += dataArray.GetAt(iSub);
		data += "\r\n";
		//������ ���ۺκ�
		switch (a) {
		case 1: //ù��° ������
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
		case 2: //�ι��� ������
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
		case 3: //����° ������
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

//�ʹݿ� �ݺ��Ǵ� ��� �Լ�
void CTestTextDlg::firstRepeat(CEdit& edit, CString *pStr, int iSub)
{
	CString dataStart;
	dataStart = pStr->Left(6);
	CString s_count = pStr->Mid(6, 1);
	dataStart += s_count;
	dataStart += "��\r\n";
	AppendText(edit, dataStart);

	CString data2nd = pStr->Mid(8); //5�� ������ ���� ����
	data2nd += "\r\n";

	sliceData(edit, &data2nd, iSub, s_count);
}

//:����ϴ� �Լ�
void CTestTextDlg::semicolonMtd(CEdit& edit, CString *pStr, int iSub) {
	CString temp;
	int a = pStr->Find(' ');
	temp = pStr->Left(a);
	temp += " : ";
	temp += pStr->Mid(a);
	AppendText(edit, temp);
}

//���߿� �ݺ��Ǵ� ��� �Լ�
void CTestTextDlg::RepeatMtd(CEdit& edit, CString *pStr, int iSub) {
	CString temp;
	temp = pStr->Left(6);
	CString s_count = pStr->Mid(6, 1);
	temp += s_count;
	temp += "��\r\n";
	AppendText(edit, temp);
	temp = "";

	temp = pStr->Mid(8);
	sliceData(edit, &temp, iSub, s_count);
}

void CTestTextDlg::sliceData(CEdit& edit, CString *pStr, int iSub, CString s_count) {
	int t = 0; //12->t
	int count = 0;//�߸� Ƚ��
	CString temp;
	int k = pStr->GetLength();
	for (int i = 0; i < k; i++) {
		int c = pStr->Find(' ', i);

		if (i == c) {
			++count;
			if (count == 1) //�� ó�� �߸� ���
			{
				temp += pStr->Mid(t, c);
			}
			else
			{
				temp += pStr->Mid(t, c - t);
			}
			t = c;
			if (count % 4 == 0) { //4���� �߷��� �� 
				temp += "\r\n";
				if (count != 4) {
					temp.Delete(0, 1);
				}
				addSpace(&temp);
				AppendText(edit, temp);
				temp = "";
			}
		}

		if (i == k - 1) { //������ i ���� ������ ��ã�Ƽ� ���� ��
			temp += pStr->Mid(t, i - t);
			if (iSub > 0) temp += "\r\n";
			if (count % 4 != 0) {
				if (s_count != "1")
					temp.Delete(0, 1);
			}
			addSpace(&temp); //��ǥ �ְ� ����ϱ�
			AppendText(edit, temp);
			temp = "";
		}
	}
}

//���鿡 ,�ֱ� �Լ�
CString CTestTextDlg::addSpace(CString *str) {
	CUIntArray array;
	int j;
	int a;
	int countSpace = GetFineCharCount(*str, ' '); //�����̽� ����
	array.SetSize(10);

	for (j = 0; j < countSpace; j++) { //�����̽� ������ŭ �ݺ�
		if (j == 0) { //ù��° �����̽� ã��
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

//edit��Ʈ�ѿ� �ٹٲ� �߰�
void CTestTextDlg::AppendText(CEdit& edit, LPCTSTR pText) {
	int n_len = edit.GetWindowTextLength();
	edit.SetFocus();
	edit.SetSel(n_len, n_len);
	edit.ReplaceSel(pText);
}

//Ư�� ���� ����
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

//Ư�� ���� �� 
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

//���� ������ �Է�
void CTestTextDlg::OnBnClickedInputnumbutton()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	//�Էµ� ���� ������ ��������
	CString numData;
	GetDlgItemText(IDC_NUMDATA, numData);
	if (numData.IsEmpty() != TRUE) { //������� ������
		addNumData(&numData);
	}
	else {
		MessageBox(_T("������ �Է��ϼ���"));
	}
	//CString temp; //�ӽú�������
	if (numData.Find("93 101") != -1) { //��Ŷ �������� �˸� -1�� ���°��
		totalCount++;
		numData.Delete(numData.GetLength() - 1, 1);
		total += numData;
		totalPacket[totalCount - 1] = total;//������� ������ �迭�� �ֱ�
		total += "\r\n";
		SetDlgItemText(IDC_PACKET, total);
	}
	else { //��Ŷ �ۼ�������
		total += numData;
		SetDlgItemText(IDC_PACKET, total); //�߰������� ���̱�
	}

	SetDlgItemText(IDC_NUM, "");
	SetDlgItemText(IDC_NUMDATA, "");
}
//���� ������ �Է�
void CTestTextDlg::addNumData(CString *pStr) {
	//���� �������� ��ȣ ��������
	CString num;
	GetDlgItemText(IDC_NUM, num);

	if (num.IsEmpty())
	{
		MessageBox(_T("��ȣ �Ǵ� �����͸� �Է��ϼ���"));
		pStr->Empty();
	}
	else {
		if (num == "302") { //��ȣ�� 302�� ���
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
//���� ������ �Է�
void CTestTextDlg::OnBnClickedInputengbutton()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString EngData;
	GetDlgItemText(IDC_ENGCOMBO, EngData);
	if (EngData.IsEmpty() != TRUE) {
		addEngData(&EngData);
	}
	else {
		MessageBox(_T("������ �Է��ϼ���"));
	}
	total += EngData;
	SetDlgItemText(IDC_PACKET, total);
	
	SetDlgItemText(IDC_ENGCOMBO, "");
	SetDlgItemText(IDC_ENGNUM, "");
}
//���� ������ �Է�
void  CTestTextDlg::addEngData(CString *pStr) {

	CString num, numCount;
	int numC;
	GetDlgItemText(IDC_COMBO_NUM2, num); //ex) 751
	num += " ";
	GetDlgItemText(IDC_COMBO_COUNT, numCount); //ex) 751 2
	numC = _ttoi(numCount); //�ݺ�Ƚ�� int�� ��ȯ
	num += numCount + ' ';

	int nLength;
	nLength = pStr->GetLength();

	CString engNum;
	GetDlgItemText(IDC_ENGNUM, engNum); //ex) 751 2 ANSIC ANSIC 0 0

	if (engNum.IsEmpty() || num.IsEmpty() || numCount.IsEmpty()){
		MessageBox(_T("��ȣ �Ǵ� ������ �Է��ϼ���"));
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

			if (nEng == numC) {//�ݺ� �� ������
				pStr->Delete(pStr->GetLength() - 1, 2);
				*pStr += "^";
				nEng = 1;
				nCount = 2; //�ݺ� ��
			}
			else {
				nEng++;
				nCount = 1;
			}
		}
		else if (nEng > 1 && nEng <= numC) { //�ݺ�Ƚ�� 2 �̻�
			totalEng = *pStr + " ";
			*pStr = totalEng;

			if (nEng == numC) {//�ݺ� �� ������
				pStr->Delete(pStr->GetLength() - 1, 2);
				*pStr += "^";
				nEng = 1;
				nCount = 2; //�ݺ� ��
			}
			else{
				nEng++;
				nCount = 1;
			}
		}
	}
}
//��ǥ ������ �Է�
void CTestTextDlg::OnBnClickedInputcoordbutton()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString xData, yData, sum;
	GetDlgItemText(IDC_X, xData);
	GetDlgItemText(IDC_Y, yData);
	if (xData.GetLength() != 6 || yData.GetLength() != 7) {
		MessageBox(_T("x��ǥ�� 6�ڸ�, y��ǥ�� 7�ڸ��� �Է��ϼ���"));
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
//��ǥ ������ �Է�
void CTestTextDlg::addCoordData(CString *pStr) {
	CString num;
	num += "400 " + *pStr + "^";
	*pStr = num;
	totalCoord = num;
	*pStr = totalCoord;
}

//�ʱ�ȭ
void CTestTextDlg::OnBnClickedClear()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	totalNum.Empty();
	totalEng.Empty();
	totalCoord.Empty();
	total.Empty();

	nEng = 1;

	SetDlgItemText(IDC_PACKET, "");

	totalCount = 0;
	SetDlgItemText(IDC_TOTALPACKET, "");
}
//�ؽ�Ʈ ���Ϸ� ����
void CTestTextDlg::OnBnClickedSavebutton()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString m_strPath;//���ϰ��
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
		MessageBox(_T("���� ���� �Ϸ�"));
	}
	else {
		MessageBox(_T("���� ���� ����"));
	}
}

//��Ŷ ����
void CTestTextDlg::OnBnClickedOutputbutton()
{
	//��� ��ư ������ 
	//��ü ������ ���
	if (totalCount == 0) {
		MessageBox(_T("��Ŷ �̿ϼ�"));
		TRACE0(_T("��Ŷ �̿ϼ�"));
	}
	else if (totalCount == 1) {
		CString temp = totalPacket[totalCount - 1];
		temp.Insert(0, '<');
		temp.Delete(temp.GetLength(), 1);
		temp.Insert(temp.GetLength(), ">\r\n"); // < >�� ����
		outputText(&temp);
	}
	else {
		CString temp = totalPacket[totalCount - 1];
		temp.Delete(0, totalPacket[totalCount - 2].GetLength() + 2);
		temp.Insert(0, '<');
		temp.Delete(temp.GetLength(), 1);
		temp.Insert(temp.GetLength(), ">\r\n"); // < >�� ����
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
		MessageBox(_T("���� 100% ��Ŷ ���� �Ϸ�"));
	}
	else {
		m_progress.SetPos(100 / 1);
		MessageBox(_T("��Ŷ �б� ����"));
		m_editPacket.SetSel(-1, -1);
		m_editPacket.Clear();
	}
}

void CTestTextDlg::OnDeltaposNumspin(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	//���� �ٲ�� �� ����� ���� �� �� ����
	// �� = ���� ��+��/��
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (pScrollBar->GetSafeHwnd() == m_hScrollBar.GetSafeHwnd()) {
	//ScrollBar IDȮ��
		int pos;
		pos = m_hScrollBar.GetScrollPos();//��ũ�� ���� ��ġ ������ ����

		if (nSBCode == SB_LINEDOWN) {
			m_hScrollBar.SetScrollPos(pos + 10); //line ���� �̵� event
		}
		else if (nSBCode == SB_LINEUP) {
			m_hScrollBar.SetScrollPos(pos - 10);
		}
		else if (nSBCode == SB_PAGEDOWN) {
			m_hScrollBar.SetScrollPos(pos + 50); //page ���� �̵�
		} 
		else if (nSBCode == SB_PAGEUP) {
			m_hScrollBar.SetScrollPos(pos - 50);
		}
		else if (nSBCode == SB_THUMBTRACK) { //��ũ�� ���콺�� ���� 
			m_hScrollBar.SetScrollPos(nPos);
		}
		vc.x = m_hScrollBar.GetScrollPos(); //���� ��ũ�� ��ġ ����Ʈ�� ����

		OnPaint(); //���� �ٽ� �׸���

	}
	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CTestTextDlg::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	int pos;
	pos = m_vScrollBar.GetScrollPos(); //���� ��ġ

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

//��� ����
void CTestTextDlg::OnBnClickedModalbutton()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_pDlg = new CModaless;
	if (m_pDlg->GetSafeHwnd() == NULL) {
		m_pDlg->Create(IDD_MODALESS);
	}
	m_pDlg->ShowWindow(SW_SHOW);
}
//�� ��Ÿ����
void CTestTextDlg::OnBnClickedButtonform()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�
	m_pFormView1->ShowWindow(SW_SHOW);
}
//�� �����
void CTestTextDlg::OnBnClickedFormhide()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_pFormView1->ShowWindow(SW_HIDE);
}

void CTestTextDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
// 	pos = point;
// 	Invalidate();
	CDialogEx::OnMouseMove(nFlags, point);
}

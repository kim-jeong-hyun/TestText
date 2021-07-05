
// TestTextDlg.h : ��� ����
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "Modaless.h"
#include "FormView1.h"

// CTestTextDlg ��ȭ ����
class CTestTextDlg : public CDialogEx
{
	// �����Դϴ�.
public:
	CTestTextDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.
public:
	CModaless *m_pDlg;
	void AllocForm();
	CView* m_pFormView1;
	CPoint pos;
	// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TESTTEXT_DIALOG };

	void getHeader(CString& str) { str = m_header; }
	void getData(CString& str) { str = m_data; }
protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.
private:
	CString m_header;
	CString m_data;
	// �����Դϴ�.
protected:
	HICON m_hIcon;
	CString list_str;
	CEdit m_edit_text; //�ؽ�Ʈ ��Ʈ��
	CEdit m_editHeader; //��� ��Ʈ��
	CEdit m_editData1; //ù���� ������ ��Ʈ��
	CEdit m_editLine; //ù�� ��Ʈ��
	CEdit m_editData2; //2��° ������ ��Ʈ��
	CEdit m_editData3; //3��° ������ ��Ʈ��
	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:

public:
	afx_msg void OnBnClickedButtonWrite();
	afx_msg void OnBnClickedButtonSlice();

	void showHeader(CString *pText, int a);

	void sliceStr(CEdit& edit, CString *pStr, int a);

	void AppendText(CEdit& edit, LPCTSTR pText);
	void RemoveChar(CString *pStr, int a);

	void firstRepeat(CEdit& edit, CString *pStr, int iSub);
	void semicolonMtd(CEdit& edit, CString *pStr, int iSub);
	void RepeatMtd(CEdit& edit, CString *pStr, int iSub);

	void sliceData(CEdit& edit, CString *pStr, int iSub, CString s_count);

	void replaceSpace(CString pStr);
	CString addSpace(CString *str);

	int GetFineCharCount(CString str, char find_char);

	afx_msg void OnSize(UINT nType, int cx, int cy);

public:
	CEdit m_NumData;
	CEdit m_xData;
	CEdit m_yData;
public:
	void addEngData(CString *pStr);
	void outputText(CString *pStr);
	void addNumData(CString *pStr);
	void addCoordData(CString *pStr);
public:
	CComboBox m_ComboNum2;
	CComboBox m_ComboCount;
	CComboBox m_ComboEng;
	CEdit m_EngNum;
	CStringArray totalPacket;
	CString total, totalNum, totalEng, totalCoord;
	int nEng, nCount;
	int totalCount;
public:
	afx_msg void OnBnClickedOutputbutton();
	afx_msg void OnBnClickedClear();
	afx_msg void OnBnClickedInputnumbutton();
	afx_msg void OnBnClickedInputengbutton();
	afx_msg void OnBnClickedInputcoordbutton();
	afx_msg void OnBnClickedSavebutton();
	afx_msg void OnDeltaposNumspin(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedRadiobutton();
public:
	CEdit m_editPacket;
	CEdit m_editNum;
	CEdit m_editTotalPacket;
	CSpinButtonCtrl m_numSpin;
	CEdit m_editSpin;
	CButton m_rb1;
	CButton m_rb2;
	CButton m_rb3;
	CButton m_rb4;
	CButton m_rb5;
	CButton m_rb6;
	CButton m_rbButton;
	CProgressCtrl m_progress;
	CScrollBar m_vScrollBar;

	POINT vc; //��ũ�� �� ��ġ�� ���� ����Ʈ ��ġ ����
	POINT origin; //�������� ��ũ�� �� ��ġ

	CScrollBar m_hScrollBar;
public:
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnBnClickedModalbutton();
	afx_msg void OnBnClickedButtonform();
	afx_msg void OnBnClickedFormhide();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

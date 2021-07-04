#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include "TestTextDlg.h"

// CFormView1 폼 뷰입니다.

class CFormView1 : public CFormView
{
	DECLARE_DYNCREATE(CFormView1)

protected:
	CFormView1();           // 동적 만들기에 사용되는 protected 생성자입니다.
	virtual ~CFormView1();
private:
	//CTestTextDlg* m_pTextDlg;
public:
	
	//void GetTextDlg(CTestTextDlg * ap_m_pTextDlg) { m_pTextDlg = ap_m_pTextDlg; } //두 클래스 연결 form에 text를 연결해서 text의 함수를 이용하도록
	enum { IDD = IDD_FORMVIEW1 };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual void OnInitialUpdate();

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_listCtrl;
	afx_msg void OnBnClickedAddbutton();
	void sliceSpace(CString str, int a);
	CButton m_addButton;
};



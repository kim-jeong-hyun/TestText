#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include "TestTextDlg.h"

// CFormView1 �� ���Դϴ�.

class CFormView1 : public CFormView
{
	DECLARE_DYNCREATE(CFormView1)

protected:
	CFormView1();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.
	virtual ~CFormView1();
private:
	//CTestTextDlg* m_pTextDlg;
public:
	
	//void GetTextDlg(CTestTextDlg * ap_m_pTextDlg) { m_pTextDlg = ap_m_pTextDlg; } //�� Ŭ���� ���� form�� text�� �����ؼ� text�� �Լ��� �̿��ϵ���
	enum { IDD = IDD_FORMVIEW1 };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual void OnInitialUpdate();

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_listCtrl;
	afx_msg void OnBnClickedAddbutton();
	void sliceSpace(CString str, int a);
	CButton m_addButton;
};



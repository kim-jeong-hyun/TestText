#pragma once


// CModaless ��ȭ �����Դϴ�.

class CModaless : public CDialogEx
{
	DECLARE_DYNAMIC(CModaless)

public:
	CModaless(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CModaless();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_MODALESS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

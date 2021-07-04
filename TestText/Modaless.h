#pragma once


// CModaless 대화 상자입니다.

class CModaless : public CDialogEx
{
	DECLARE_DYNAMIC(CModaless)

public:
	CModaless(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CModaless();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_MODALESS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};


// TestText.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CTestTextApp:
// �� Ŭ������ ������ ���ؼ��� TestText.cpp�� �����Ͻʽÿ�.
//

class CTestTextApp : public CWinApp
{
public:
	CTestTextApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CTestTextApp theApp;

// kaskad.h : ������� ���� ��������� ��� ���������� PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"		// �������� �������


// CkaskadApp:
// � ���������� ������� ������ ��. kaskad.cpp
//

class CkaskadApp : public CWinApp
{
public:
	CkaskadApp();

// ���������������
public:
	virtual BOOL InitInstance();

// ����������

	DECLARE_MESSAGE_MAP()
};

extern CkaskadApp theApp;
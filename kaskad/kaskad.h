
// kaskad.h : главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CkaskadApp:
// О реализации данного класса см. kaskad.cpp
//

class CkaskadApp : public CWinApp
{
public:
	CkaskadApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CkaskadApp theApp;
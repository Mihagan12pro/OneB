
// OneB.h: основной файл заголовка для приложения OneB
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// COneBApp:
// Сведения о реализации этого класса: OneB.cpp
//

class COneBApp : public CWinApp
{
public:
	COneBApp() noexcept;


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern COneBApp theApp;

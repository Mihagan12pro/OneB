﻿
// MainFrm.h: интерфейс класса CMainFrame
//

#pragma once
class COneBView;
class ConeBDoc;

#include "mysql.h"
#include <locale>
#include <string>
#include <lm.h>
class CMainFrame : public CFrameWnd
{
	
protected: // создать только из сериализации
	CMainFrame() noexcept;
	DECLARE_DYNCREATE(CMainFrame)

// Атрибуты
public:

// Операции
public:

// Переопределение
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Реализация
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // встроенные члены панели элементов управления
	CToolBar          m_wndToolBar;
	CStatusBar        m_wndStatusBar;
	CSplitterWnd      m_wndSplitter;

// Созданные функции схемы сообщений
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()

	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);

	friend class COneBDoc;
public:
	afx_msg void OnClose();
private:
	void OnOpenMySql();

	MYSQL* conn;
	MYSQL_RES* res;
	MYSQL_ROW row;


	friend class COneBDoc;
};



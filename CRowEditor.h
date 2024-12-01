#pragma once
#include "afxdialogex.h"


// Диалоговое окно CRowEditor

class CRowEditor : public CDialog
{
	DECLARE_DYNAMIC(CRowEditor)

public:
	CRowEditor(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~CRowEditor();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CRowEditor };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};

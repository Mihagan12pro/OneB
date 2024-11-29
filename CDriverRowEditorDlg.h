#pragma once
#include "afxdialogex.h"


// Диалоговое окно CDriverRowEditorDlg
class CMainFrame;
class COneBView;
class CDriverRowEditorDlg : public CDialog
{
	DECLARE_DYNAMIC(CDriverRowEditorDlg)

public:
	CDriverRowEditorDlg(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~CDriverRowEditorDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CDriverRowEditorDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV
	CString m_driverId;
	CString m_driverName;
	CString m_driverSurname;
	DECLARE_MESSAGE_MAP()
public:
	
};

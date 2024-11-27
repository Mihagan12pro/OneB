#pragma once
#include "afxdialogex.h"


// Диалоговое окно CCarRowEditorDlg
class CMainFrame;
class COneBView;

class CCarRowEditorDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCarRowEditorDlg)

public:
	CCarRowEditorDlg(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~CCarRowEditorDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CarRowEditor };
#endif

protected:
	COneBView* pView;
	CMainFrame * pFrame;
	CString m_carNumber;
	CString m_carBrand;
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	void GetVars(CString carNumber,CString carBrand);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);

};

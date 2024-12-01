#pragma once
#include "afxdialogex.h"


// Диалоговое окно CRowEditorDlg

class CRowEditorDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CRowEditorDlg)

public:
	CRowEditorDlg(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~CRowEditorDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ROW_EDITOR };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_carNumberEDIT;
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnEnChangeCarNumberEdit();
	virtual BOOL OnInitDialog();
};

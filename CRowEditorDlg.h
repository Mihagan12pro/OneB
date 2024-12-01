#pragma once
#include "afxdialogex.h"
#include"tables.h"
using namespace enums;
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
	void InitializingEditor(table tbl);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnEnChangeCarNumberEdit();
	virtual BOOL OnInitDialog();
private:
	
private:
	table m_selectedTable;
	

	
private:
	CStatic m_carNumberSTATIC;
	CStatic m_carBrandSTATIC;
	CEdit m_carNumberEDIT;
	CEdit m_carBrandEditor;

	CString m_carNumberVALUE;
	CString m_carBrandVALUE;

public:
	void SetCarTableItems(CString carNumber,CString carBrand);

	CString* GetCarTableItems();
};

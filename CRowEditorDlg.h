#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "afxdialogex.h"
#include"tables.h"
#include<vector>
using namespace std;
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
	void SetCarTableItems(CString carNumber, CString carBrand);
	CString* GetTableItems();

private:
	CStatic m_driverSurnameSTATIC;
	CEdit m_driverSurnameEDIT;
	CStatic m_driverNameSTATIC;
	CEdit m_driverNameEDIT;
	CStatic m_driverPatronymicSTATIC;
	CEdit m_driverPatronymicEDIT;


	CString m_driverSurnameVALUE;
	CString m_driverNameVALUE;
	CString m_driverPatronymicVALUE;
public:
	void SetDriverTableItems(CString surname, CString name, CString patronymic);
private:


	afx_msg void OnCbnSelchangeDriverfullnameCombo();
	afx_msg void OnCbnSelchangerouteCarNumberCombo();
private:
	//CComboBox m_carNumberCOMBO;
	CStatic m_routeIdSTATIC;
	CEdit m_routeIdEDIT;
	CStatic m_arrivalSTATIC;
	CEdit m_arrivalEDIT;
	
	CStatic m_driverFullnameSTATIC;
	CComboBox m_driverFullnameCOMBO;
	CStatic m_routeCarNumberSTATIC;


private:
	CString m_currentNumber, m_currentFullname;
	

	CString m_driverId;
	CString m_carId;
public:
	void SetRoutesTableItems(CString routeId, CString driverId,CString carId,CString arrival);
private:
	CComboBox m_routeCarNumberCOMBO;

	CString m_arrivalVALUE;
public:
	CString m_routeIdVALUE;
};

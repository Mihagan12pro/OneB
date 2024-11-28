﻿// CCarRowEditorDlg.cpp: файл реализации
//

#include "pch.h"
#include "OneB.h"
#include "afxdialogex.h"
#include "CCarRowEditorDlg.h"
#include"MainFrm.h"
#include"OneBView.h"
#include"afxlistctrl.h"
#include"tables.h"
// Диалоговое окно CCarRowEditorDlg

IMPLEMENT_DYNAMIC(CCarRowEditorDlg, CDialogEx)

CCarRowEditorDlg::CCarRowEditorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CarRowEditor, pParent)
	, m_carNumber(_T(""))
	, m_carBrand(_T(""))
{

}

CCarRowEditorDlg::~CCarRowEditorDlg()
{
}

void CCarRowEditorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_CarNumberEDIT, m_carNumber);
	DDX_Text(pDX, IDC_CarBrandEDIT, m_carBrand);
}


BEGIN_MESSAGE_MAP(CCarRowEditorDlg, CDialogEx)
	ON_WM_CREATE()
	ON_BN_CLICKED(IDOK, &CCarRowEditorDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// Обработчики сообщений CCarRowEditorDlg


int CCarRowEditorDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	pFrame = (CMainFrame*)AfxGetMainWnd();
	pView = (COneBView*)AfxGetMainWnd();

	
	
	// TODO:  Добавьте специализированный код создания

	return 0;
}
void CCarRowEditorDlg::GetVars(CString carNumber, CString carBrand)
{
	 m_carNumber = carNumber;
	 m_oldCarBrand = m_carBrand = carBrand;
}

void CCarRowEditorDlg::OnBnClickedOk()
{
	// TODO: добавьте свой код обработчика уведомлений
	
	

	CDialogEx::OnOK();
	if (m_carBrand != m_oldCarBrand)
	{
		std::string newBrand = CT2A(m_carBrand);
		std::string car_id = CT2A(m_carNumber);
		std::string query = "UPDATE cars SET car_brand = '" + newBrand + "' WHERE car_id = " + car_id;
		int result = mysql_query(pFrame->conn, query.c_str());

		if (pFrame->res = mysql_store_result(pFrame->conn))
		{
			pView -> ClearTable();
			pView -> FillTable(cars_tbl);
	
		}

		
	}
}
/*
	if (m_carBrand != m_oldCarBrand)
	{
		std::string newBrand = CT2A(m_carBrand);
		std::string car_id = CT2A(m_carNumber);
		std::string query = "UPDATE cars SET car_brand = '" + newBrand + "' WHERE car_id = " + car_id;
		int result = mysql_query(pFrame->conn, query.c_str());

		if (pFrame->res = mysql_store_result(pFrame->conn))
		{
		}
	}


*/

void CCarRowEditorDlg::OnOK()
{
	// TODO: добавьте специализированный код или вызов базового класса
	if (m_carBrand != m_oldCarBrand)
	{
		std::string newBrand = CT2A(m_carBrand);
		std::string car_id = CT2A(m_carNumber);
		std::string query = "UPDATE cars SET car_brand = '" + newBrand + "' WHERE car_id = " + car_id;
		int result = mysql_query(pFrame->conn, query.c_str());

		if (pFrame->res = mysql_store_result(pFrame->conn))
		{
		}
	}
	CDialogEx::OnOK();
}

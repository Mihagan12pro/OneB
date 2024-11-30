// CCarRowEditorDlg.cpp: файл реализации
//

#include "pch.h"
#include "OneB.h"
#include "afxdialogex.h"
#include "CRowEditorDlg.h"
#include"MainFrm.h"
#include"OneBView.h"
#include"afxlistctrl.h"
#include"tables.h"
// Диалоговое окно CCarRowEditorDlg

IMPLEMENT_DYNAMIC(CRowEditorDlg
	, CDialogEx)

CRowEditorDlg::CRowEditorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CarRowEditor, pParent)
	, m_carNumber(_T(""))
	, m_carBrand(_T(""))
{

}

CRowEditorDlg::~CRowEditorDlg()
{
}

void CRowEditorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_CarNumberEDIT, m_carNumber);
	DDX_Text(pDX, IDC_CarBrandEDIT, m_carBrand);
}


BEGIN_MESSAGE_MAP(CRowEditorDlg, CDialogEx)
	ON_WM_CREATE()
	ON_BN_CLICKED(IDOK, &CRowEditorDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// Обработчики сообщений CCarRowEditorDlg


int CRowEditorDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	pFrame = (CMainFrame*)AfxGetMainWnd();
	pView = (COneBView*)AfxGetMainWnd();

	
	
	// TODO:  Добавьте специализированный код создания

	return 0;
}
void CRowEditorDlg::GetCars(CString carNumber, CString carBrand)
{
	if (!varsInitialized)
	{
		m_carNumber = carNumber;
		m_carBrand = carBrand;

		varsInitialized = true;
	}	
}
CString CRowEditorDlg::GetCarNumber()
{
	return m_carNumber;
}
CString CRowEditorDlg::GetCarBrand()
{
	return m_carBrand;
}
void CRowEditorDlg::OnBnClickedOk()
{
	// TODO: добавьте свой код обработчика уведомлений
	
	

	CDialogEx::OnOK();
	//if (m_carBrand != m_oldCarBrand)
	//{
	//	std::string newBrand = CT2A(m_carBrand);
	//	std::string car_id = CT2A(m_carNumber);
	//	std::string query = "UPDATE cars SET car_brand = '" + newBrand + "' WHERE car_id = " + car_id;
	//	int result = mysql_query(pFrame->conn, query.c_str());

	//	if (pFrame->res = mysql_store_result(pFrame->conn))
	//	{
	//		pView -> ClearTable();
	//		pView -> FillTable(cars_tbl);
	//
	//	}
	//}
}



void CRowEditorDlg::OnOK()
{
//	// TODO: добавьте специализированный код или вызов базового класса
//	if (m_carBrand != m_oldCarBrand)
//	{
//		std::string newBrand = CT2A(m_carBrand);
//		std::string car_id = CT2A(m_carNumber);
//		std::string query = "UPDATE cars SET car_brand = '" + newBrand + "' WHERE car_id = " + car_id;
//		int result = mysql_query(pFrame->conn, query.c_str());
//
//		if (pFrame->res = mysql_store_result(pFrame->conn))
//		{
//		}
//	}
	CDialogEx::OnOK();
}

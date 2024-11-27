// CCarRowEditorDlg.cpp: файл реализации
//

#include "pch.h"
#include "OneB.h"
#include "afxdialogex.h"
#include "CCarRowEditorDlg.h"
#include"MainFrm.h"
#include"OneBView.h"
#include"afxlistctrl.h"

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
	 m_carBrand = carBrand;
}
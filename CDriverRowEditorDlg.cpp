// CDriverRowEditorDlg.cpp: файл реализации
//

#include "pch.h"
#include "OneB.h"
#include "afxdialogex.h"
#include "CDriverRowEditorDlg.h"


// Диалоговое окно CDriverRowEditorDlg

IMPLEMENT_DYNAMIC(CDriverRowEditorDlg, CDialog)

CDriverRowEditorDlg::CDriverRowEditorDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_CDriverRowEditorDlg, pParent)
	, m_driverId(_T(""))
	, m_driverName(_T(""))
	, m_driverSurname(_T(""))
{

}

CDriverRowEditorDlg::~CDriverRowEditorDlg()
{
}

void CDriverRowEditorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, ID_DriverIdEDIT, m_driverId);
	DDX_Text(pDX, IDC_NameEDIT, m_driverName);
	DDX_Text(pDX, IDC_SurnameEDIT, m_driverSurname);
}


BEGIN_MESSAGE_MAP(CDriverRowEditorDlg, CDialog)
END_MESSAGE_MAP()


// Обработчики сообщений CDriverRowEditorDlg

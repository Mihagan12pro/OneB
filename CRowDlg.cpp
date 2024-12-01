// CRowDlg.cpp: файл реализации
//

#include "pch.h"
#include "OneB.h"
#include "afxdialogex.h"
#include "CRowDlg.h"


// Диалоговое окно CRowDlg

IMPLEMENT_DYNAMIC(CRowDlg, CDialogEx)

CRowDlg::CRowDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_RowDlg, pParent)
{

}

CRowDlg::~CRowDlg()
{
}

void CRowDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CRowDlg, CDialogEx)
END_MESSAGE_MAP()


// Обработчики сообщений CRowDlg

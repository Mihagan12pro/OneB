// CRowEditor.cpp: файл реализации
//

#include "pch.h"
#include "OneB.h"
#include "afxdialogex.h"
#include "CRowEditor.h"


// Диалоговое окно CRowEditor

IMPLEMENT_DYNAMIC(CRowEditor, CDialog)

CRowEditor::CRowEditor(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_CRowEditor, pParent)
{

}

CRowEditor::~CRowEditor()
{
}

void CRowEditor::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CRowEditor, CDialog)
	ON_WM_CREATE()
END_MESSAGE_MAP()


// Обработчики сообщений CRowEditor


int CRowEditor::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	GetDlgItem(IDD_CRowEditor)->ShowWindow(SW_SHOW);


	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Добавьте специализированный код создания

	return 0;
}

// CRowEditorDlg.cpp: файл реализации
//

#include "pch.h"
#include "OneB.h"
#include "afxdialogex.h"
#include "CRowEditorDlg.h"


// Диалоговое окно CRowEditorDlg

IMPLEMENT_DYNAMIC(CRowEditorDlg, CDialogEx)

CRowEditorDlg::CRowEditorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ROW_EDITOR, pParent)
	, m_carNumberVALUE(_T(""))
	, m_carBrandVALUE(_T(""))
{

}

CRowEditorDlg::~CRowEditorDlg()
{
}

void CRowEditorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_Car_Number_EDIT, m_carNumberEDIT);
	DDX_Control(pDX, IDC_Car_NumberSTATIC, m_carNumberSTATIC);
	DDX_Control(pDX, IDC_carBrandSTATIC, m_carBrandSTATIC);
	DDX_Control(pDX, IDC_Car_Brand_EDIT, m_carBrandEditor);
	DDX_Text(pDX, IDC_Car_Number_EDIT, m_carNumberVALUE);
	DDX_Text(pDX, IDC_Car_Brand_EDIT, m_carBrandVALUE);
}


BEGIN_MESSAGE_MAP(CRowEditorDlg, CDialogEx)
	ON_WM_CREATE()
	ON_EN_CHANGE(IDC_Car_Number_EDIT, &CRowEditorDlg::OnEnChangeCarNumberEdit)
END_MESSAGE_MAP()


// Обработчики сообщений CRowEditorDlg


int CRowEditorDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	
	
	// TODO:  Добавьте специализированный код создания

	return 0;
}


void CRowEditorDlg::OnEnChangeCarNumberEdit()
{
	// TODO:  Если это элемент управления RICHEDIT, то элемент управления не будет
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// функция и вызов CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Добавьте код элемента управления
}


BOOL CRowEditorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Добавить дополнительную инициализацию
	
	UpdateData(TRUE);

	switch (m_selectedTable)
	{
		case cars_tbl:
		{
			m_carNumberEDIT.ShowWindow(SW_SHOW);
			m_carNumberSTATIC.ShowWindow(SW_SHOW);
			m_carBrandSTATIC.ShowWindow(SW_SHOW);
			m_carBrandEditor.ShowWindow(SW_SHOW);
			break;
		}
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	// Исключение: страница свойств OCX должна возвращать значение FALSE
}
void CRowEditorDlg::InitializingEditor(table selectedTable)
{
	m_selectedTable = selectedTable;
}
void CRowEditorDlg::SetCarTableItems(CString carNumber, CString carBrand)
{
	m_carNumberVALUE  = carNumber;
	m_carBrandVALUE   = carBrand;

	
}
CString* CRowEditorDlg::GetCarTableItems()
{
	CString items[2];

	items[0] = m_carNumberVALUE;
	items[1] = m_carBrandVALUE;

	return items;
}
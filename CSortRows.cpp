// CSortRows.cpp: файл реализации
//

#include "pch.h"
#include "OneB.h"
#include "CSortRows.h"


// CSortRows

IMPLEMENT_DYNCREATE(CSortRowsView, CFormView)

CSortRowsView::CSortRowsView()
	: CFormView(IDD_CSortRows)
{

}

CSortRowsView::~CSortRowsView()
{
}

void CSortRowsView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CSortRowsView, CFormView)
	ON_BN_CLICKED(IDC_drop_sort_BUTTON, &CSortRowsView::OnBnClickeddropsortButton)
	ON_BN_CLICKED(IDC_Sort_BUTTON, &CSortRowsView::OnBnClickedSortButton)
END_MESSAGE_MAP()


// Диагностика CSortRows

#ifdef _DEBUG
void CSortRowsView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CSortRowsView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// Обработчики сообщений CSortRows


void CSortRowsView::OnBnClickeddropsortButton()
{
	// TODO: добавьте свой код обработчика уведомлений
}


void CSortRowsView::OnBnClickedSortButton()
{
	// TODO: добавьте свой код обработчика уведомлений
}
void CSortRowsView ::TableWasSelected(table tbl)
{
	HideElements();

	switch (tbl)
	{
		case cars_tbl:
		{
			GetDlgItem(IDC_car_number_STATIC)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_How_sort_car_numbers_COMBO)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_car_numberEDIT)->ShowWindow(SW_SHOW);

			GetDlgItem(IDC_car_brand_STATIC)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_Car_brand_COMBO)->ShowWindow(SW_SHOW);
			GetDlgItem(IDC_Car_Brand_EDIT)->ShowWindow(SW_SHOW);
			break;
		}
	}
}
void CSortRowsView::HideElements()
{
	GetDlgItem(IDC_car_number_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_How_sort_car_numbers_COMBO)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_car_numberEDIT)->ShowWindow(SW_HIDE);

	GetDlgItem(IDC_car_brand_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_Car_brand_COMBO)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_Car_Brand_EDIT)->ShowWindow(SW_HIDE);
}
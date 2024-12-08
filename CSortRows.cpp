// CSortRows.cpp: файл реализации
//

#include "pch.h"
#include "OneB.h"
#include "CSortRows.h"
#include"MainFrm.h"

// CSortRows

IMPLEMENT_DYNCREATE(CFilterRowsView, CFormView)

CFilterRowsView::CFilterRowsView()
	: CFormView(IDD_CSortRows)
{

}

CFilterRowsView::~CFilterRowsView()
{
}

void CFilterRowsView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_How_sort_car_numbers_COMBO, m_carNumberCOMBO);
	DDX_Control(pDX, IDC_Car_brand_COMBO, m_carBrandCOMBO);
	DDX_Control(pDX, IDC_car_numberEDIT, m_carNumberEDIT);
	DDX_Control(pDX, IDC_Car_Brand_EDIT, m_carBrandEDIT);
}

BEGIN_MESSAGE_MAP(CFilterRowsView, CFormView)
	ON_BN_CLICKED(IDC_drop_sort_BUTTON, &CFilterRowsView::OnBnClickedDropFiltersButton)
	ON_BN_CLICKED(IDC_Sort_BUTTON, &CFilterRowsView::OnBnClickedFilterButton)
END_MESSAGE_MAP()


// Диагностика CSortRows

#ifdef _DEBUG
void CFilterRowsView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CFilterRowsView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// Обработчики сообщений CSortRows


void CFilterRowsView::OnBnClickedDropFiltersButton()
{
	// TODO: добавьте свой код обработчика уведомлений
	switch (m_tbl)
	{
		case cars_tbl:
		{

			m_carNumberEDIT.SetWindowText(L"");
			m_carBrandEDIT.SetWindowText(L"");
			m_carNumberCOMBO.SetCurSel(-1);
			m_carBrandCOMBO.SetCurSel(-1);

			m_pView->FillTable(cars_tbl, "SELECT car_number,car_brand FROM cars");

			break;
		}
	}
}


void CFilterRowsView::OnBnClickedFilterButton()
{
	// TODO: добавьте свой код обработчика уведомлений
	string sql = "SELECT ";
	switch (m_tbl)
	{
		case cars_tbl:
		{
			sql += "car_number,car_brand FROM cars";


			m_pFrame->m_Connection.Connect();

			CString str;
			m_carNumberEDIT.GetWindowText(str);
			string number = CT2A(str);
			
			
			if (m_carNumberCOMBO.GetCurSel() != -1)
			{
				switch (m_carNumberCOMBO.GetCurSel())
				{
					case 0:
					{
						sql += " WHERE car_number <> '"+number+"'";

						

						break;
					}
					case 1:
						sql += " WHERE car_number = '" + number + "'";

						
						break;
					default:
						sql += " WHERE  instr(car_number, '"+number+"')>0";

						
						break;
				}
			}
			m_carBrandEDIT.GetWindowText(str);
			string brand = CT2A(str);
			if (m_carBrandCOMBO.GetCurSel() != -1)
			{
				

				switch (m_carBrandCOMBO.GetCurSel())
				{
					case 0:
					{
						if (m_carNumberCOMBO.GetCurSel() != -1)
							sql += " AND ";
						else
							sql += " WHERE ";
						sql += "  car_brand <> '" + brand + "'";

						

						break;
					}
					case 1:
						if (m_carNumberCOMBO.GetCurSel() != -1)
							sql += " AND ";
						else
							sql += " WHERE ";
						sql += " car_brand = '" + brand + "'";

						
						break;
					default:
						if (m_carNumberCOMBO.GetCurSel() != -1)
							sql += " AND ";
						else
							sql += " WHERE ";
						sql += " instr(car_brand, '" + brand + "')>0";

						
						break;
				}
			}
			
			m_pView->FillTable(cars_tbl, sql);

			break;
		}
	};
}
void CFilterRowsView ::TableWasSelected(table tbl)
{
	HideElements();

	m_tbl = tbl;

	switch (m_tbl)
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
void CFilterRowsView::HideElements()
{
	GetDlgItem(IDC_car_number_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_How_sort_car_numbers_COMBO)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_car_numberEDIT)->ShowWindow(SW_HIDE);

	GetDlgItem(IDC_car_brand_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_Car_brand_COMBO)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_Car_Brand_EDIT)->ShowWindow(SW_HIDE);
}
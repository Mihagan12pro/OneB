﻿// CMyTree.cpp: файл реализации
//

#include "pch.h"
#include<iostream>
#include "OneB.h"
#include "CMyTree.h"
#include "MainFrm.h"
#include "OneBView.h"
#include<vector>
#include<string>

#define CARS 0
#define DRIVERS 1
#define ROUTES 2

#define COLUMN_WIDTH 240

using namespace std;
// CMyTree

IMPLEMENT_DYNCREATE(CTableExplorerView, CTreeView)

CTableExplorerView::CTableExplorerView()
{

}

CTableExplorerView::~CTableExplorerView()
{
}

BEGIN_MESSAGE_MAP(CTableExplorerView, CTreeView)
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_KEYDOWN()
	ON_WM_MOUSEACTIVATE()
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDBLCLK()
	ON_NOTIFY_REFLECT(TVN_ITEMEXPANDED, &CTableExplorerView::OnTvnItemexpanded)
END_MESSAGE_MAP()


// Диагностика CMyTree

#ifdef _DEBUG
void CTableExplorerView::AssertValid() const
{
	CTreeView::AssertValid();
}

#ifndef _WIN32_WCE
void CTableExplorerView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}



void CTableExplorerView::FillTree()
{
	CTreeCtrl& tree = GetTreeCtrl();
	tree.DeleteAllItems();

	m_hTablesList = tree.InsertItem(L"Таблицы", -1, -1, NULL, TVI_FIRST);

	m_hDrivers = tree.InsertItem(L"Водители", -1, -1, m_hTablesList, TVI_FIRST);
	m_hCars = tree.InsertItem(L"Машины", -1, -1, m_hTablesList, TVI_FIRST);
	m_hRoutes = tree.InsertItem(L"Рейсы", -1, -1, m_hTablesList, TVI_FIRST);


	tree.SetItemData(m_hTablesList, -1);

	tree.SetItemData(m_hRoutes,0);
	tree.SetItemData(m_hCars, 1);
	tree.SetItemData(m_hDrivers, 2);




	tree.Expand(m_hTablesList, TVE_EXPAND);

	//tree.SelectItem(m_hTablesList);
}


#endif
#endif //_DEBUG


// Обработчики сообщений CMyTree


int CTableExplorerView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	lpCreateStruct->style |= TVS_HASLINES | TVS_HASBUTTONS | TVS_LINESATROOT | TVS_SHOWSELALWAYS;
	if (CTreeView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Добавьте специализированный код создания

	return 0;
}





void CTableExplorerView::OnLButtonDown(UINT nFlags, CPoint point)
{
	CTreeCtrl& tree = GetTreeCtrl();
	HTREEITEM item = tree.GetSelectedItem();

	setlocale(LC_ALL, "rus");
	
	
	string sqlSelectQuery = "SELECT * FROM ";
	
	if (item != m_hTablesList)
	{
		CListCtrl *pTable = m_pMainView -> GetTable();

		pTable->DeleteAllItems();

		CHeaderCtrl *pTableHeaders = pTable->GetHeaderCtrl();

		int fieldsCount = pTableHeaders->GetItemCount();

		for (int i = 0; i < fieldsCount;i++)
		{
			pTable->DeleteColumn(0);
		}

		if (item == m_hRoutes)
		{
			sqlSelectQuery += "routes";
			pTable->InsertColumn(0,L"Номер рейса", LVCFMT_LEFT, COLUMN_WIDTH);
			pTable->InsertColumn(1, L"Табельный номер водителя", LVCFMT_LEFT, COLUMN_WIDTH);
			pTable->InsertColumn(2, L"Номер машины", LVCFMT_LEFT, COLUMN_WIDTH);
			pTable->InsertColumn(3, L"Пункт назначения", LVCFMT_LEFT, COLUMN_WIDTH);
		}

		else if (item == m_hDrivers)
		{
			pTable->InsertColumn(0, L"Табельный номер водителя", LVCFMT_LEFT, COLUMN_WIDTH);
			pTable->InsertColumn(1, L"Имя водителя", LVCFMT_LEFT, COLUMN_WIDTH);
			pTable->InsertColumn(2, L"Фамилия водителя", LVCFMT_LEFT, COLUMN_WIDTH);
			sqlSelectQuery += "drivers";
		}

		else if (item == m_hCars)
		{
			pTable->InsertColumn(0, L"Номер машины", LVCFMT_LEFT, COLUMN_WIDTH);
			pTable->InsertColumn(1, L"Марка машины", LVCFMT_LEFT, COLUMN_WIDTH);
			sqlSelectQuery += "cars";
		}




		

		
		

		


		int result = mysql_query(pMainFrm->conn, sqlSelectQuery.c_str());

		cout << endl << result;

		if (pMainFrm->res = mysql_store_result(pMainFrm->conn))
		{
			while (pMainFrm->row = mysql_fetch_row(pMainFrm->res))
			{
				CString str;

				CString columnItem0 = CString( pMainFrm->row[0]);
			
				//str.Format(L"%s",columnItem0);

				int row = pTable ->InsertItem(mysql_num_fields(pMainFrm->res), columnItem0, -1 );


				
				for (int i = 1; i < mysql_num_fields(pMainFrm->res); i++)
				{
						CString columnItem = CString(pMainFrm->row[i]);
						char* ch = pMainFrm->row[i];
						char* ch2 = ch;
					//str.Format(L"%s", columnItem);

					pTable -> SetItemText(row,i,columnItem);
				}
				std::cout << "\n";
			}
		}
		else
			fprintf(stderr, "%s\n", mysql_error(pMainFrm->conn));


		
	}

CTreeView::OnLButtonDown(nFlags, point);
}


//void CTableExplorerView::OnLButtonDblClk(UINT nFlags, CPoint point)
//{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
//	CTreeCtrl& tree = GetTreeCtrl();
//	HTREEITEM item = tree.GetSelectedItem();
//
//	if (item == m_hRoutes)
//	{
		//Мой код
//		int a = 1;
//	}
//
//	else if (item == m_hDrivers)
//	{
		//Мой код
//		int a = 1;
//	}
//
//	else if (item == m_hCars)
//	{
		//Мой код
//		int a = 1;
//	}
//
//	CTreeView::OnLButtonDblClk(nFlags, point);
//}


void CTableExplorerView::OnTvnItemexpanded(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: добавьте свой код обработчика уведомлений
	*pResult = 0;
}

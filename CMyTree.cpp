// CMyTree.cpp: файл реализации
//

#include "pch.h"
#include<iostream>
#include "OneB.h"
#include "CMyTree.h"
#include "MainFrm.h"
#include "OneBView.h"
#include<string>

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
	
	string query = " SELECT *";
	

	if (item == m_hRoutes)
	{
		//Мой код
		//int a = 1;
		query = "FROM 'routes'" + query;
		
		
	}

	else if (item == m_hDrivers)
	{
		//Мой код
		//int a = 1;
		query = "FROM 'drivers'" + query;
	}

	else if (item == m_hCars)
	{
		//Мой код
		//int a = 1;
		query = "FROM 'cars'" + query;
	}
	string sql = "SELECT * FROM cars";

	int result = mysql_query(pMainFrm->conn, sql.c_str());

	cout << endl << result;

	if (pMainFrm->res = mysql_store_result(pMainFrm->conn))
	{
		while (pMainFrm->row = mysql_fetch_row(pMainFrm->res))
		{
			for (int i = 0; i < mysql_num_fields(pMainFrm->res); i++) 
			{
				auto a = pMainFrm->row[i];
				auto b = a;
				std::cout << pMainFrm->row[i] << "\t"; //Выводим все что есть в базе через цикл
			}
			std::cout << "\n";
		}
	}
	else
		fprintf(stderr, "%s\n", mysql_error(pMainFrm->conn));


	


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

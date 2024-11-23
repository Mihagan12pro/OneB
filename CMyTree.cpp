// CMyTree.cpp: файл реализации
//

#include "pch.h"
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
	ON_NOTIFY_REFLECT(NM_CLICK, &CTableExplorerView::OnNMClick)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
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


	tree.Expand(m_hTablesList, TVE_EXPAND);
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


void CTableExplorerView::OnNMClick(NMHDR* pNMHDR, LRESULT* pResult)
{
	//CTreeCtrl& tree = GetTreeCtrl();

	//CPoint usersCurcsor;
	//GetCursorPos(&usersCurcsor);
	//ScreenToClient(&usersCurcsor);

	//// Получаем элемент по позиции курсора
	//HTREEITEM hClickedItem = tree.HitTest(usersCurcsor);

	//CString strItemText;
	//strItemText = tree.GetItemText(hClickedItem);

	//if (strItemText != L"Таблицы")
	//{
	//	CListCtrl& table = m_pMainView -> GetListCtrl();

	//	string sql;

	//
	//	
	//}



		// TODO: добавьте свой код обработчика уведомлений
	*pResult = 0;
}


void CTableExplorerView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного

	CTreeCtrl& tree = GetTreeCtrl();
	
	HTREEITEM selectedItem = tree.GetSelectedItem();

	if (selectedItem != m_hTablesList)
	{
		string sqlQuery="SELECT *";
	
		if (selectedItem == m_hCars)
		{
			sqlQuery = "FROM 'cars'" + sqlQuery;
		}
		else if (selectedItem == m_hDrivers)
		{
			sqlQuery = "FROM 'drivers'" + sqlQuery;
		}
		else if (selectedItem == m_hRoutes)
		{
			sqlQuery = "FROM 'routes'" + sqlQuery;
		}



	}





CTreeView::OnLButtonDown(nFlags, point);



}


void CTableExplorerView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	CTreeView::OnLButtonUp(nFlags, point);
}

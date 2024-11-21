// CMyTree.cpp: файл реализации
//

#include "pch.h"
#include "OneB.h"
#include "CMyTree.h"


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

}


#endif
#endif //_DEBUG


// Обработчики сообщений CMyTree


int CTableExplorerView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	lpCreateStruct->style |= TVS_HASLINES | TVS_HASBUTTONS | TVS_LINESATROOT | TVS_SHOWSELALWAYS | TVS_CHECKBOXES;
	if (CTreeView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Добавьте специализированный код создания

	return 0;
}

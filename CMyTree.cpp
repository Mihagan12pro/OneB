// CMyTree.cpp: файл реализации
//

#include "pch.h"
#include "OneB.h"
#include "CMyTree.h"


// CMyTree

IMPLEMENT_DYNCREATE(CMyTree, CTreeView)

CMyTree::CMyTree()
{

}

CMyTree::~CMyTree()
{
}

BEGIN_MESSAGE_MAP(CMyTree, CTreeView)
	ON_WM_CREATE()
END_MESSAGE_MAP()


// Диагностика CMyTree

#ifdef _DEBUG
void CMyTree::AssertValid() const
{
	CTreeView::AssertValid();
}

#ifndef _WIN32_WCE
void CMyTree::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}



void CMyTree::FillTree()
{
	CTreeCtrl& tree = GetTreeCtrl();
	tree.DeleteAllItems();

	m_hLinesRoot = tree.InsertItem(L"Линии", -1, -1, NULL, TVI_FIRST);

	m_hLine1 = tree.InsertItem(L"Прямая1", -1, -1, m_hLinesRoot, TVI_FIRST);
	m_hLine2 = tree.InsertItem(L"Прямая2", -1, -1, m_hLinesRoot, TVI_FIRST);
	m_hCircle = tree.InsertItem(L"Окружность", -1, -1, m_hLinesRoot, TVI_FIRST);

}


#endif
#endif //_DEBUG


// Обработчики сообщений CMyTree


int CMyTree::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	lpCreateStruct->style |= TVS_HASLINES | TVS_HASBUTTONS | TVS_LINESATROOT | TVS_SHOWSELALWAYS | TVS_CHECKBOXES;
	if (CTreeView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Добавьте специализированный код создания

	return 0;
}

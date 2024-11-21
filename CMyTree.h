#pragma once

class COneBDoc;
// Просмотр CMyTree
#include"afxcview.h"
class CTableExplorerView : public CTreeView
{
	DECLARE_DYNCREATE(CTableExplorerView)

protected:
	CTableExplorerView();           // защищенный конструктор, используемый при динамическом создании
	virtual ~CTableExplorerView();

public:
	COneBDoc* m_pDoc;
	HTREEITEM m_hTablesList, m_hDrivers, m_hRoutes, m_hCars;
	void FillTree();

#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};



#pragma once

class COneBDoc;
class CMainFrame;
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
	HTREEITEM m_hTablesList, m_hDrivers, m_hCircle, m_hCars;
	void FillTree();

#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	CMainFrame* pMainFrm;
	friend class CMainFrame;

	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnNMClick(NMHDR* pNMHDR, LRESULT* pResult);
};



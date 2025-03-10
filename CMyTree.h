﻿#pragma once

class COneBDoc;
class COneBView;
class CMainFrame;
class CFilterRowsView;

#include"afxcview.h"

class CTableExplorerView : public CTreeView
{
	DECLARE_DYNCREATE(CTableExplorerView)

protected:
	CFilterRowsView* m_pFormView;
	CTableExplorerView();           // защищенный конструктор, используемый при динамическом создании
	virtual ~CTableExplorerView();

public:
	
	void FillTree();

#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	
	
	
	HTREEITEM m_hTablesList, m_hDrivers, m_hRoutes, m_hCars;
	int m_LastTable;

	int m_lastTableFieldCount = 0;
	
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
//	afx_msg void OnNMClick(NMHDR* pNMHDR, LRESULT* pResult);
private:
	CMainFrame* pMainFrm;
	COneBDoc* m_pDoc;
	COneBView* m_pMainView;
private:
	friend class CMainFrame;
	friend class COneBDoc;
public:

	int CTableExplorerView::GetSelectedItem();

	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);

//	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnTvnItemexpanded(NMHDR* pNMHDR, LRESULT* pResult);
};



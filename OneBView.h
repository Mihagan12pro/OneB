﻿
// OneBView.h: интерфейс класса COneBView
//

#pragma once

class COneBDoc;
#include"tables.h"
#include<string>
using namespace std;
class CTableExplorerView;

class COneBView : public CListView
{
protected: // создать только из сериализации
	enum table{drivers_tbl = 0, cars_tbl=1,routes_tbl=2};
	CListCtrl* pTable;
	int m_selectedCellIndex;
	COneBView() noexcept;
	DECLARE_DYNCREATE(COneBView)

// Атрибуты
public:
	COneBDoc* GetDocument() const;

	CListCtrl *GetTable();
// Операции
public:
	void FillTable(int tableType,string sql);
	void ClearTable();
// Переопределение
public:
	virtual void OnDraw(CDC* pDC);  // переопределено для отрисовки этого представления
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // вызывается в первый раз после конструктора
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	CString GetPrimalKey(table tableType,int cellId);


// Реализация
public:
	void SetTreeView(CTableExplorerView* pTree);
	virtual ~COneBView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CTableExplorerView* m_pTreeView;
	friend class CRowEditorDlg;
// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
//	afx_msg void OnLvnEndlabeledit(NMHDR* pNMHDR, LRESULT* pResult);
//	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
//	afx_msg void OnNMClick(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnAddNewDriver();
	afx_msg void OnAddNewCar();
	afx_msg void OnAddNewRoute();
};

#ifndef _DEBUG  // версия отладки в OneBView.cpp
inline COneBDoc* COneBView::GetDocument() const
   { return reinterpret_cast<COneBDoc*>(m_pDocument); }
#endif


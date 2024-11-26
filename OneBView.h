
// OneBView.h: интерфейс класса COneBView
//

#pragma once

class COneBDoc;
class COneBView : public CListView
{
protected: // создать только из сериализации

	CListCtrl* pTable;

	COneBView() noexcept;
	DECLARE_DYNCREATE(COneBView)

// Атрибуты
public:
	COneBDoc* GetDocument() const;

	CListCtrl *GetTable();
// Операции
public:

// Переопределение
public:
	virtual void OnDraw(CDC* pDC);  // переопределено для отрисовки этого представления
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // вызывается в первый раз после конструктора
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);


// Реализация
public:
	virtual ~COneBView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnLvnEndlabeledit(NMHDR* pNMHDR, LRESULT* pResult);
};

#ifndef _DEBUG  // версия отладки в OneBView.cpp
inline COneBDoc* COneBView::GetDocument() const
   { return reinterpret_cast<COneBDoc*>(m_pDocument); }
#endif


#pragma once

class COneBDoc;
// Просмотр CMyTree
#include"afxcview.h"
class CMyTree : public CTreeView
{
	DECLARE_DYNCREATE(CMyTree)

protected:
	CMyTree();           // защищенный конструктор, используемый при динамическом создании
	virtual ~CMyTree();

public:
	COneBDoc* m_pDoc;
	HTREEITEM m_hLinesRoot, m_hLine1, m_hCircle, m_hLine2;
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



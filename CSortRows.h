#pragma once


#include"tables.h"

using namespace enums;

#include"OneBView.h"

class CMainFrame;


class CFilterRowsView : public CFormView
{
	DECLARE_DYNCREATE(CFilterRowsView)

protected:
	CFilterRowsView();           // защищенный конструктор, используемый при динамическом создании
	virtual ~CFilterRowsView();

	table m_tbl;

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CSortRows };
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	
	friend class COneBView;
	friend class CMainFrame;
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV
	void HideElements();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedDropFiltersButton();
	afx_msg void OnBnClickedFilterButton();

	void TableWasSelected(table tbl);

protected:
	CComboBox m_carNumberCOMBO;
	CComboBox m_carBrandCOMBO;
	CEdit m_carNumberEDIT;
	CEdit m_carBrandEDIT;
private:
	COneBView* m_pView;
	CMainFrame* m_pFrame;
};



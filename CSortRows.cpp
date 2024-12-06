// CSortRows.cpp: файл реализации
//

#include "pch.h"
#include "OneB.h"
#include "CSortRows.h"


// CSortRows

IMPLEMENT_DYNCREATE(CSortRowsView, CFormView)

CSortRowsView::CSortRowsView()
	: CFormView(IDD_CSortRows)
{

}

CSortRowsView::~CSortRowsView()
{
}

void CSortRowsView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CSortRowsView, CFormView)
END_MESSAGE_MAP()


// Диагностика CSortRows

#ifdef _DEBUG
void CSortRowsView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CSortRowsView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// Обработчики сообщений CSortRows


// OneBDoc.cpp: реализация класса COneBDoc 
//

#include "pch.h"
#include "framework.h"


using namespace std;


// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "OneB.h"
#endif
#include"MainFrm.h"
#include"CMyTree.h"
#include "OneBDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// COneBDoc



IMPLEMENT_DYNCREATE(COneBDoc, CDocument)

BEGIN_MESSAGE_MAP(COneBDoc, CDocument)
END_MESSAGE_MAP()


// Создание или уничтожение COneBDoc

COneBDoc::COneBDoc() noexcept
{
	// TODO: добавьте код для одноразового вызова конструктора

}

COneBDoc::~COneBDoc()
{
}

BOOL COneBDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: добавьте код повторной инициализации
	// (Документы SDI будут повторно использовать этот документ)


	CWnd* MainWnd = AfxGetMainWnd();

	if (MainWnd)
	{

		m_pTreeView = (CTableExplorerView*)((CMainFrame*)MainWnd)->m_wndSplitter.GetPane(0, 0);

		m_pTreeView->m_pDoc = this;
		m_pView = (COneBView*)((CMainFrame*)MainWnd)->m_wndSplitter.GetPane(0, 1);

	}
	m_pTreeView->FillTree();

	return TRUE;
}




// Сериализация COneBDoc

void COneBDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: добавьте код сохранения
	}
	else
	{
		// TODO: добавьте код загрузки
	}
}

#ifdef SHARED_HANDLERS

// Поддержка для эскизов
void COneBDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Измените этот код для отображения данных документа
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Поддержка обработчиков поиска
void COneBDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Задание содержимого поиска из данных документа.
	// Части содержимого должны разделяться точкой с запятой ";"

	// Например:  strSearchContent = _T("точка;прямоугольник;круг;объект ole;");
	SetSearchContent(strSearchContent);
}

void COneBDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// Диагностика COneBDoc

#ifdef _DEBUG
void COneBDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void COneBDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// Команды COneBDoc

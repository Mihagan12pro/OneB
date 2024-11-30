
// MainFrm.cpp: реализация класса CMainFrame
//

#include "pch.h"
#include "framework.h"
#include "OneB.h"
#include"OneBDoc.h"
#include"CMyTree.h"
#include "MainFrm.h"
#include"OneBView.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace std;
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_CLOSE()
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // индикатор строки состояния
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// Создание или уничтожение CMainFrame

CMainFrame::CMainFrame() noexcept
{
	// TODO: добавьте код инициализации члена
}

CMainFrame::~CMainFrame()
{
}


void CMainFrame::OnOpenMySql()
{
	

	int i = 0;
	// Получаем дескриптор соединения
	conn = mysql_init(NULL);
	if (conn == NULL)
	{
		// Если дескриптор не получен – выводим сообщение об ошибке
		fprintf(stderr, "Error: can'tcreate MySQL-descriptor\n");

	}
	// Подключаемся к серверу
	if (!mysql_real_connect(conn, "localhost", "root", "7kjwf*jaksdfVHJ8ds", "logistic", NULL, NULL, 0))
	{
		// Если нет возможности установить соединение с сервером
		// базы данных выводим сообщение об ошибке
		
		MessageBox(L"Unfortunately, we have some troubles with connecting to database!");
		OnClose();
	}
	else
	{

	}
	mysql_set_character_set(conn,"cp1251");
	//mysql_set_character_set(conn, "utf8mb3");
	//Смотрим изменилась ли кодировка на нужную, по умалчанию идёт latin1



	//string logon = string();

	////cout << logon;

	//DWORD sz = 256;

	//char buff[256];

	//GetComputerNameA(buff, &sz);

	//string compname(buff);
	//sz = 256;

	//GetUserNameA(buff, &sz);
	//string user(buff);

}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Не удалось создать панель инструментов\n");
		return -1;      // не удалось создать
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("Не удалось создать строку состояния\n");
		return -1;      // не удалось создать
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO: Удалите эти три строки, если не собираетесь закреплять панель инструментов
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);









	OnOpenMySql();








	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return TRUE;
}

// Диагностика CMainFrame

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// Обработчики сообщений CMainFrame



BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	// TODO: добавьте специализированный код или вызов базового класса
	m_wndSplitter.CreateStatic(this,1,2);

	m_wndSplitter.CreateView(0, 0, RUNTIME_CLASS(CTableExplorerView), CSize(200, 0), pContext);
	m_wndSplitter.CreateView(0, 1, RUNTIME_CLASS(COneBView), CSize(0, 0), pContext);

	SetActiveView((CView*)m_wndSplitter.GetPane(0, 1));

	COneBDoc* pDoc = (COneBDoc*)GetActiveDocument();

	pDoc->m_pTreeView = (CTableExplorerView*)m_wndSplitter.GetPane(0, 0);
	pDoc->m_pView = (COneBView*)m_wndSplitter.GetPane(0, 1);

	pDoc->m_pTreeView->m_pDoc = pDoc;


	pDoc->m_pTreeView->pMainFrm = this;
	pDoc->m_pTreeView->m_pMainView = (pDoc->m_pView);
	pDoc->m_pView->SetTreeView(pDoc->m_pTreeView);

	return TRUE;
}


void CMainFrame::OnClose()
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	

	mysql_close(conn);
	CFrameWnd::OnClose();
}


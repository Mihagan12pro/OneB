
// OneBView.cpp: реализация класса COneBView
//

#include "pch.h"
#include<iostream>
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "OneB.h"
#endif
#include"CMyTree.h"
#include "OneBDoc.h"
#include "OneBView.h"
#include<afxcview.h>
#include"MainFrm.h"
#include"tables.h"
#include"CRowEditorDlg.h"
#include<string>
#include"tables.h"
#include<vector>
#define COLUMN_WIDTH 150
using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

struct routesField
{
	CString driver_id, car_id;
};
// COneBView

IMPLEMENT_DYNCREATE(COneBView, CListView)

BEGIN_MESSAGE_MAP(COneBView, CListView)
	// Стандартные команды печати
	ON_COMMAND(ID_FILE_PRINT, &CListView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CListView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CListView::OnFilePrintPreview)
	ON_WM_CREATE()
	//ON_NOTIFY_REFLECT(LVN_ENDLABELEDIT, &COneBView::OnLvnEndlabeledit)
	ON_WM_LBUTTONDOWN()
	//ON_NOTIFY_REFLECT(NM_CLICK, &COneBView::OnNMClick)
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// Создание или уничтожение COneBView

COneBView::COneBView() noexcept
{
	// TODO: добавьте код создания

}

COneBView::~COneBView()
{
}

BOOL COneBView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CListView::PreCreateWindow(cs);
}
CListCtrl *COneBView::GetTable()
{
	return pTable;
}

void COneBView::OnDraw(CDC* /*pDC*/)
{
	COneBDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: добавьте здесь код отрисовки для собственных данных
}


void COneBView::OnInitialUpdate()
{
	CListView::OnInitialUpdate();


	// TODO: ListView можно заполнить элементами посредством непосредственного обращения
	//  к элементам управления этого списка через вызов GetListCtr().
}


// Печать COneBView

BOOL COneBView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// подготовка по умолчанию
	return DoPreparePrinting(pInfo);
}

void COneBView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте дополнительную инициализацию перед печатью
}

void COneBView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте очистку после печати
}


// Диагностика COneBView

#ifdef _DEBUG
void COneBView::AssertValid() const
{
	CListView::AssertValid();
}

void COneBView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}

COneBDoc* COneBView::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(COneBDoc)));
	return (COneBDoc*)m_pDocument;
}
#endif //_DEBUG


// Обработчики сообщений COneBView


int COneBView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CListView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Добавьте специализированный код создания

	pTable = &GetListCtrl();
	pTable->ModifyStyle(0, LVS_REPORT | LVS_SORTASCENDING | LVS_SHOWSELALWAYS);

	return 0;
}




void COneBView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного

	CListView::OnLButtonDblClk(nFlags, point);

	LVHITTESTINFO info;
	info.pt = point;
	info.flags = LVHT_ONITEMLABEL;

	if (pTable->SubItemHitTest(&info) >= 0)
	{
		int row = info.iItem;
		int column = info.iSubItem;

		CRect rect;
		pTable->GetSubItemRect(row,column,LVIR_LABEL,rect);

		

		m_selectedCellIndex = info.iItem;

		CString primalKey;
		switch (m_pTreeView->GetSelectedItem())
		{
			case drivers_tbl:
				break;
			case cars_tbl:
			{
				CRowEditorDlg dlg;

				CString number, brand;

				number = pTable->GetItemText(info.iItem, 0);
				brand = pTable->GetItemText(info.iItem, 1);

				primalKey = GetPrimalKey(cars_tbl,row);
			

				dlg.GetCars(number,brand);
				if (dlg.DoModal() == IDOK)
				{
					if (number != dlg.GetCarNumber())
					{
						CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();

						
					}
				}
				break;
			}
				
			case routes_tbl:
				primalKey = GetPrimalKey(routes_tbl, row);
				auto a = primalKey;
				break;
		}
		Invalidate();

	}

}
void  COneBView::SetTreeView(CTableExplorerView* pTree)
{
	m_pTreeView = pTree;
}
void COneBView::FillTable(int tableType)
{
	std::string sqlSelectQuery = "SELECT ";
	switch (tableType)
	{
		case drivers_tbl:
		{
			pTable->InsertColumn(1, L"Имя водителя", LVCFMT_LEFT, COLUMN_WIDTH);
			pTable->InsertColumn(2, L"Фамилия водителя", LVCFMT_LEFT, COLUMN_WIDTH);
			sqlSelectQuery += " driver_name,driver_surname  FROM drivers";
			break;
		}
		case cars_tbl:
		{
			pTable->InsertColumn(0, L"Номер машины", LVCFMT_LEFT, COLUMN_WIDTH);
			pTable->InsertColumn(1, L"Марка машины", LVCFMT_LEFT, COLUMN_WIDTH);
			sqlSelectQuery += " car_number, car_brand FROM cars";
			break;
		}
		case routes_tbl:
		{
			sqlSelectQuery += "* FROM routes";
			pTable->InsertColumn(0, L"Номер рейса", LVCFMT_LEFT, COLUMN_WIDTH);
			pTable->InsertColumn(1, L"Фамилия водителя", LVCFMT_LEFT, COLUMN_WIDTH);
			pTable->InsertColumn(2, L"Имя водителя", LVCFMT_LEFT, COLUMN_WIDTH);
			pTable->InsertColumn(3, L"Отчество водителя", LVCFMT_LEFT, COLUMN_WIDTH);
			pTable->InsertColumn(4, L"Номер машины", LVCFMT_LEFT, COLUMN_WIDTH);
			pTable->InsertColumn(5, L"Место отправления", LVCFMT_LEFT, COLUMN_WIDTH);

			break;
		}
		default:
		{
			throw exception("Undefined table!");
			break;
		}
	}

	CMainFrame* pMainFrm = (CMainFrame*)AfxGetMainWnd();
	
	int result = mysql_query(pMainFrm->conn, sqlSelectQuery.c_str());

	vector<routesField>routesFieldVector;
	vector<int>rowIds;
	if (pMainFrm->res = mysql_store_result(pMainFrm->conn))
	{
	
		while (pMainFrm->row = mysql_fetch_row(pMainFrm->res))
		{

			if (tableType != routes_tbl)
			{
				int rowId = pTable->InsertItem(mysql_num_fields(pMainFrm->res), CString(pMainFrm->row[0]), -1);
				rowIds.push_back(rowId);

				for (int i = 1; i < mysql_num_fields(pMainFrm->res); i++)
				{
				
					CString columnItem = CString(pMainFrm->row[i]);
					pTable->SetItemText(rowId, i, columnItem);
				}
			}
			else
			{
				int rowId = pTable->InsertItem(mysql_num_fields(pMainFrm->res), CString(pMainFrm->row[0]), -1);

				routesField field;
				for (int i = 1; i < mysql_num_fields(pMainFrm->res); i++)
				{
					switch (i)
					{
						case 1:
						{
							field.driver_id = CString(pMainFrm->row[i]);
							break;
						}
						case 2:
						{
							field.car_id = CString(pMainFrm->row[i]);
							break;
						}
						case 3:
						{
							CString columnItem = CString(pMainFrm->row[i]);
							pTable->SetItemText(rowId, 5, columnItem);
							break;
						}
						
					}
					
				}
				routesFieldVector.push_back(field);
			}
		}
		
	}
	if (tableType == routes_tbl)
	{
	
		int n = -1;
		for (int i = 0; i < routesFieldVector.size();i++)
		{
			string str = CT2A(routesFieldVector[i].driver_id);
			string sqlSelectQuery2 = string("SELECT * FROM drivers WHERE driver_id = "+str);

			mysql_query(pMainFrm->conn, sqlSelectQuery2.c_str());
			n++;
			if (pMainFrm->res = mysql_store_result(pMainFrm->conn))
			{
				pMainFrm->row = mysql_fetch_row(pMainFrm->res);
				
				
					pTable->SetItemText(n,1, CString(pMainFrm->row[1]));

					pTable->SetItemText(n, 2, CString(pMainFrm->row[2]));
					pTable->SetItemText(n, 3, CString(pMainFrm->row[3]));

				
			}
			str = CT2A(routesFieldVector[i].car_id);
			sqlSelectQuery2 = string("SELECT * FROM cars WHERE car_id = " + str);

			mysql_query(pMainFrm->conn, sqlSelectQuery2.c_str());

			if (pMainFrm->res = mysql_store_result(pMainFrm->conn))
			{
				pMainFrm->row = mysql_fetch_row(pMainFrm->res);
			
				pTable->SetItemText(n, 4, CString(pMainFrm->row[2]));
				
			}
		}	
	}
}
void COneBView::ClearTable()
{
	pTable->DeleteAllItems();

	CHeaderCtrl* pTableHeaders = pTable->GetHeaderCtrl();

	int fieldsCount = pTableHeaders->GetItemCount();

	for (int i = 0; i < fieldsCount;i++)
	{
		pTable->DeleteColumn(0);
	}
}
CString COneBView::GetPrimalKey(table tableType, int cellId)
{
	

	switch (tableType)
	{
		case routes_tbl:
		{
			return pTable->GetItemText(cellId,0);
		}
		case cars_tbl:
		{
			CMainFrame* pMainFrm = (CMainFrame*)AfxGetMainWnd();

			string carNumber = CT2A(pTable->GetItemText(cellId, 0));
			string carBrand = CT2A(pTable->GetItemText(cellId, 1));
			//string query = string("SELECT * FROM cars WHERE car_number = 'А123ВР77' AND car_brand = 'КАМАЗ'");
			string query = string("SELECT * FROM cars WHERE car_number = '"+carNumber+"' AND car_brand = '"+carBrand+"'");
			int ex = mysql_query(pMainFrm->conn, query.c_str());

			pMainFrm->res = mysql_store_result(pMainFrm->conn);
			
				pMainFrm->row = mysql_fetch_row(pMainFrm->res);

				
				return CString(pMainFrm->row[0]);
				
		
		}
		case drivers_tbl:
		{
			/*string driverSurname = CT2A(pTable->GetItemText(cellId, 0));
			string driverName = CT2A(pTable->GetItemText(cellId, 1));
			string driverPatronymic = CT2A(pTable->GetItemText(cellId, 2));
			string query = "FROM cars SELECT car_id WHERE driver_surname = " + driverSurname + " AND driver_name = " + driverName+" AND driver_patronymic = "+driverPatronymic;

			mysql_query(pMainFrm->conn, query.c_str());

			if (pMainFrm->res = mysql_store_result(pMainFrm->conn))
			{
				pMainFrm->row = mysql_fetch_row(pMainFrm->res);

				return CString(pMainFrm->row[0]);

			}*/
			break;
		}
	}
	return L"";
}
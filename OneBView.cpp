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
#include<string>
#include<vector>
#include"CRowEditorDlg.h"

#define COLUMN_WIDTH 150
using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
using namespace enums;

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
	ON_COMMAND(ID_add_new_driver, &COneBView::OnAddNewDriver)
	ON_COMMAND(ID_add_new_car, &COneBView::OnAddNewCar)
	ON_COMMAND(ID_add_new_route, &COneBView::OnAddNewRoute)
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
CListCtrl* COneBView::GetTable()
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


	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();

	pFrame->m_Connection.Connect();

	if (pTable->SubItemHitTest(&info) >= 0)
	{
		int row = info.iItem;
		int column = info.iSubItem;

		CRect rect;
		pTable->GetSubItemRect(row, column, LVIR_LABEL, rect);

		string sql;

		m_selectedCellIndex = info.iItem;

		CString primaryKey;
		CRowEditorDlg dlg;
		string StrPrimaryKey;
		switch (m_pTreeView->GetSelectedItem())
		{
		case drivers_tbl:
		{
			string surname = CT2A(pTable->GetItemText(row,0));
			string name = CT2A(pTable->GetItemText(row, 1));
			string patronymic = CT2A(pTable->GetItemText(row, 2));
			sql = "SELECT driver_id FROM drivers WHERE driver_surname = '"+surname+"' AND driver_name = '"+name+"' AND driver_patronymic = '"+patronymic+"'";
			primaryKey = CString(pFrame->m_Connection.SELECT(sql)[0][0]);
			dlg.InitializingEditor(enums::drivers_tbl);
			dlg.SetDriverTableItems(pTable->GetItemText(row, 0), pTable->GetItemText(row, 1), pTable->GetItemText(row, 2));
			if (dlg.DoModal() == IDOK)
			{
				StrPrimaryKey = CT2A(primaryKey);
				surname = CT2A(dlg.GetTableItems()[0]);
				name = CT2A(dlg.GetTableItems()[1]);
				patronymic = CT2A(dlg.GetTableItems()[2]);

				sql = "UPDATE drivers SET driver_surname = '" + surname + "' WHERE driver_id = " + StrPrimaryKey + " AND driver_surname <> '" + surname + "'";
				pFrame->m_Connection.UPDATE(sql);
				sql = "UPDATE drivers SET driver_name = '" + name + "' WHERE driver_id = " + StrPrimaryKey + " AND driver_name <> '" + name + "'";
				pFrame->m_Connection.UPDATE(sql);
				sql = "UPDATE drivers SET driver_patronymic = '" + patronymic + "' WHERE driver_id = " + StrPrimaryKey + " AND driver_patronymic <> '" + patronymic + "'";
				pFrame->m_Connection.UPDATE(sql);
				
			}

			break;
		}
		case cars_tbl:
		{
			string carNumber = CT2A(pTable->GetItemText(row,0));
			string carBrand = CT2A(pTable->GetItemText(row, 1));

			sql = "SELECT car_id FROM cars ";
			primaryKey = CString(pFrame->m_Connection.SELECT(sql)[0][0]);
			dlg.InitializingEditor(enums::cars_tbl);
			dlg.SetCarTableItems(pTable->GetItemText(row, 0), pTable->GetItemText(row, 1));
			if (dlg.DoModal() == IDOK)
			{
				StrPrimaryKey = CT2A(primaryKey);
				carNumber = CT2A(dlg.GetTableItems()[0]);
				carBrand = CT2A(dlg.GetTableItems()[1]);



				// "UPDATE cars SET car_brand = '" + newBrand + "' WHERE car_id = " + car_id;
				sql = "UPDATE cars SET car_number = '" + carNumber + "' WHERE car_id = " + StrPrimaryKey + " AND car_number <> '" + carNumber + "'";
				pFrame->m_Connection.UPDATE(sql);
				sql = "UPDATE cars SET car_brand = '" + carBrand + "' WHERE car_id = " + StrPrimaryKey + " AND car_brand <> '" + carBrand + "'";
				pFrame->m_Connection.UPDATE(sql);



			}

			break;
		}

		case routes_tbl:
		{
			primaryKey = pTable->GetItemText(row,0);

			string driver_surname = CT2A(pTable->GetItemText(row, 1));
			string driver_name = CT2A(pTable->GetItemText(row, 2));
			string driver_patronymic = CT2A(pTable->GetItemText(row, 3));
			string arrival = CT2A(pTable->GetItemText(row, 5));

			string car_number = CT2A(pTable->GetItemText(row, 4));
			sql = "SELECT driver_id FROM drivers WHERE driver_surname = '" + driver_surname + "' AND driver_name = '" + driver_name + "' AND driver_patronymic = '" + driver_patronymic + "'";
			CString driver_id = pFrame->m_Connection.SELECT(sql)[0][0];
			CString car_id = pFrame->m_Connection.SELECT("SELECT car_id FROM cars WHERE car_number = '"+car_number+"'")[0][0];
			dlg.InitializingEditor(enums::routes_tbl);
			dlg.SetRoutesTableItems(primaryKey, driver_id, car_id, CString(arrival.c_str()));

			if (dlg.DoModal() == IDOK)
			{
				string strPrimaryKey = CT2A(primaryKey);

				string newDriver_id = CT2A(dlg.GetTableItems()[0]);
				string newCar_id = CT2A(dlg.GetTableItems()[1]);
				arrival = CT2A(dlg.GetTableItems()[2]);

				pFrame -> m_Connection.UPDATE("UPDATE routes SET driver_id = "+ newDriver_id + " WHERE route_id = "+ strPrimaryKey+" AND driver_id <> "+newDriver_id);
				pFrame->m_Connection.UPDATE("UPDATE routes SET car_id = "+newCar_id+" WHERE route_id = " + strPrimaryKey + " AND car_id <> " + newCar_id);
				pFrame->m_Connection.UPDATE("UPDATE routes SET arrival = '"+arrival+"' WHERE route_id = " + strPrimaryKey + " AND arrival <> '" + arrival+"'");
			}
			

			break;
		}
			
		}
		pFrame->m_Connection.DisConnectr();

	}

}







void  COneBView::SetTreeView(CTableExplorerView* pTree)
{
	m_pTreeView = pTree;
}






void COneBView::FillTable(int tableType, string sql)
{
	
	switch (tableType)
	{
		case drivers_tbl:
		{
			pTable->InsertColumn(0, L"Фамилия водителя", LVCFMT_LEFT, COLUMN_WIDTH);
			pTable->InsertColumn(1, L"Имя водителя", LVCFMT_LEFT, COLUMN_WIDTH);

			pTable->InsertColumn(2, L"Отчество водителя", LVCFMT_LEFT, COLUMN_WIDTH);
			sql += " driver_surname,driver_name, driver_patronymic  FROM drivers";
			break;
		}
		case cars_tbl:
		{
			pTable->InsertColumn(0, L"Номер машины", LVCFMT_LEFT, COLUMN_WIDTH);
			pTable->InsertColumn(1, L"Марка машины", LVCFMT_LEFT, COLUMN_WIDTH);
			sql += " car_number, car_brand FROM cars";
			break;
		}
		case routes_tbl:
		{
			sql = "SELECT routes.route_id, drivers.driver_surname, drivers.driver_name, drivers.driver_patronymic,cars.car_number, arrival FROM routes JOIN drivers ON drivers.driver_id = routes.driver_id JOIN cars ON cars.car_id = routes.car_id";
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
			return;
		}
	}

	CMainFrame* pMainFrm = (CMainFrame*)AfxGetMainWnd();

	pMainFrm -> m_Connection.Connect();

	vector<vector<CString>> tableItems = pMainFrm->m_Connection.SELECT(sql.c_str());

	CListCtrl& table = GetListCtrl();
	for (int i = 0; i < tableItems.size(); i++)
	{
		int rowId = pTable->InsertItem(0, tableItems[i][0], -1);
		for (int j = 1; j < tableItems[0].size();j++)
		{
			pTable->SetItemText(rowId, j, tableItems[i][j]);
		}
	}
	pMainFrm->m_Connection.DisConnectr();

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
//CString COneBView::GetPrimalKey(table tableType, int cellId)
//{
//	CMainFrame* pMainFrm = (CMainFrame*)AfxGetMainWnd();
//	switch (tableType)
//	{
//	case routes_tbl:
//	{
//		return pTable->GetItemText(cellId, 0);
//	}
//	case cars_tbl:
//	{
//		string carNumber = CT2A(pTable->GetItemText(cellId, 0));
//		string carBrand = CT2A(pTable->GetItemText(cellId, 1));
//		//string query = string("SELECT * FROM cars WHERE car_number = 'А123ВР77' AND car_brand = 'КАМАЗ'");
//		string query = string("SELECT * FROM cars WHERE car_number = '" + carNumber + "' AND car_brand = '" + carBrand + "'");
//		int ex = mysql_query(pMainFrm->conn, query.c_str());
//
//		pMainFrm->res = mysql_store_result(pMainFrm->conn);
//
//		pMainFrm->row = mysql_fetch_row(pMainFrm->res);
//
//		return CString(pMainFrm->row[0]);
//		break;
//	}
//	case drivers_tbl:
//	{
//
//		string driverSurname = CT2A(pTable->GetItemText(cellId, 0));
//		string driverName = CT2A(pTable->GetItemText(cellId, 1));
//		string driverPatronymic = CT2A(pTable->GetItemText(cellId, 2));
//
//		string query = string("SELECT * FROM drivers WHERE driver_surname = '" + driverSurname + "' AND driver_name = '" + driverName + "'" + " AND driver_patronymic = '" + driverPatronymic + "'");
//		int ex = mysql_query(pMainFrm->conn, query.c_str());
//
//		pMainFrm->res = mysql_store_result(pMainFrm->conn);
//
//		pMainFrm->row = mysql_fetch_row(pMainFrm->res);
//
//
//		return CString(pMainFrm->row[0]);
//		break;
//	}
//	}
//	return L"";
//}

void COneBView::OnAddNewDriver()
{
	// TODO: добавьте свой код обработчика команд

	CRowEditorDlg dlg;

	dlg.InitializingEditor(enums::drivers_tbl);

	if (dlg.DoModal() == IDOK)
	{
		if (dlg.GetTableItems().size() > 0)
		{
			string driver_surname = CT2A(dlg.GetTableItems()[0]);
			string driver_name = CT2A(dlg.GetTableItems()[1]);
			string driver_patronymic = CT2A(dlg.GetTableItems()[2]);

			string sql = "INSERT INTO drivers (driver_surname, driver_name, driver_patronymic) VALUES ('"+driver_surname+"', '"+driver_name+"', '"+driver_patronymic+"')";
			
			CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();

			pFrame->m_Connection.Connect();

			pFrame->m_Connection.INSERT(sql);

			pFrame->m_Connection.DisConnectr();



			return;
		}
		AfxMessageBox(L"Были поданы некорректные данные! Таблица обновлена не будет!");
	}
}


void COneBView::OnAddNewCar()
{
	// TODO: добавьте свой код обработчика команд
	CRowEditorDlg dlg;
	dlg.InitializingEditor(enums::cars_tbl);

	if (dlg.DoModal() == IDOK)
	{
		if (dlg.GetTableItems().size() > 0)
		{
			string car_number = CT2A(dlg.GetTableItems()[0]);
			string car_brand = CT2A(dlg.GetTableItems()[1]);
			string sql = "INSERT INTO cars (car_number,car_brand) VALUES ('" + car_number + "', '" +car_brand + "')";

			CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();

			pFrame->m_Connection.Connect();

			pFrame->m_Connection.INSERT(sql);

			pFrame->m_Connection.DisConnectr();
			return;
		}
		AfxMessageBox(L"Были поданы некорректные данные! Таблица обновлена не будет!");
	}
}


void COneBView::OnAddNewRoute()
{
	// TODO: добавьте свой код обработчика команд
	CRowEditorDlg dlg;
	dlg.InitializingEditor(enums::routes_tbl);

	if (dlg.DoModal() == IDOK)
	{
		if (dlg.GetTableItems().size() > 0)
		{

			string driver_id = CT2A(dlg.GetTableItems()[0]);
			string car_id = CT2A(dlg.GetTableItems()[1]);
			string arrival = CT2A(dlg.GetTableItems()[2]);
			string sql = "INSERT INTO routes (driver_id,car_id, arrival ) VALUES ('" + driver_id + "', '" + car_id + "', '" + arrival  + "')";

			CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();

			pFrame->m_Connection.Connect();

			pFrame->m_Connection.INSERT(sql);

			pFrame->m_Connection.DisConnectr();

			return;
		}
		AfxMessageBox(L"Были поданы некорректные данные! Таблица обновлена не будет!");
	}
}

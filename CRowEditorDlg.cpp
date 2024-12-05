// CRowEditorDlg.cpp: файл реализации
//

#include "pch.h"
#include "OneB.h"
#include "afxdialogex.h"
#include "CRowEditorDlg.h"
#include"MainFrm.h"
#include<sstream>
// Диалоговое окно CRowEditorDlg

IMPLEMENT_DYNAMIC(CRowEditorDlg, CDialogEx)

CRowEditorDlg::CRowEditorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ROW_EDITOR, pParent)
	, m_carNumberVALUE(_T(""))
	, m_carBrandVALUE(_T(""))
	, m_driverSurnameVALUE(_T(""))
	, m_driverNameVALUE(_T(""))
	, m_driverPatronymicVALUE(_T(""))
	, m_arrivalVALUE(_T(""))
	, m_routeIdVALUE(_T(""))
{

}

CRowEditorDlg::~CRowEditorDlg()
{
}

void CRowEditorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_Car_Number_EDIT, m_carNumberEDIT);
	DDX_Control(pDX, IDC_Car_NumberSTATIC, m_carNumberSTATIC);
	DDX_Control(pDX, IDC_carBrandSTATIC, m_carBrandSTATIC);
	DDX_Control(pDX, IDC_Car_Brand_EDIT, m_carBrandEditor);
	DDX_Text(pDX, IDC_Car_Number_EDIT, m_carNumberVALUE);
	DDX_Text(pDX, IDC_Car_Brand_EDIT, m_carBrandVALUE);
	DDX_Control(pDX, IDC_DriverSurnameSTATIC, m_driverSurnameSTATIC);
	DDX_Control(pDX, IDC_DriversSurnameEDIT, m_driverSurnameEDIT);
	DDX_Control(pDX, IDC_DriverNameSTATIC, m_driverNameSTATIC);
	DDX_Control(pDX, IDC_DriverNameEDIT, m_driverNameEDIT);
	DDX_Control(pDX, IDC_DriverPatronymicSTATIC, m_driverPatronymicSTATIC);
	DDX_Control(pDX, IDC_DriverPatronymicEDIT, m_driverPatronymicEDIT);
	DDX_Text(pDX, IDC_DriversSurnameEDIT, m_driverSurnameVALUE);
	DDX_Text(pDX, IDC_DriverNameEDIT, m_driverNameVALUE);
	DDX_Text(pDX, IDC_DriverPatronymicEDIT, m_driverPatronymicVALUE);
	DDX_Control(pDX, IDC_Driver_fullname_STATIC, m_driverFullnameSTATIC);
	DDX_Control(pDX, IDC_Driver_fullname_COMBO, m_driverFullnameCOMBO);
	DDX_Control(pDX, IDC_Route_Id_STATIC, m_routeIdSTATIC);
	DDX_Control(pDX, IDC_Route_Id_EDIT, m_routeIdEDIT);
	DDX_Control(pDX, IDC_Arrival_STATIC, m_arrivalSTATIC);
	DDX_Control(pDX, IDC_Arrival_EDIT, m_arrivalEDIT);

	DDX_Control(pDX, IDC_Route_Car_NumberSTATIC, m_routeCarNumberSTATIC);
	DDX_Control(pDX, IDC_route_Car_Number_COMBO, m_CarNumberCOMBO);
	DDX_Text(pDX, IDC_Arrival_EDIT, m_arrivalVALUE);
	DDX_Text(pDX, IDC_Route_Id_EDIT, m_routeIdVALUE);
}


BEGIN_MESSAGE_MAP(CRowEditorDlg, CDialogEx)
	ON_WM_CREATE()
	ON_EN_CHANGE(IDC_Car_Number_EDIT, &CRowEditorDlg::OnEnChangeCarNumberEdit)
	ON_CBN_SELCHANGE(IDC_Driver_fullname_COMBO, &CRowEditorDlg::OnCbnSelchangeDriverfullnameCombo)
	ON_CBN_SELCHANGE(IDC_route_Car_Number_COMBO, &CRowEditorDlg::OnCbnSelchangerouteCarNumberCombo)
END_MESSAGE_MAP()


// Обработчики сообщений CRowEditorDlg


int CRowEditorDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;



	// TODO:  Добавьте специализированный код создания

	return 0;
}


void CRowEditorDlg::OnEnChangeCarNumberEdit()
{
	// TODO:  Если это элемент управления RICHEDIT, то элемент управления не будет
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// функция и вызов CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Добавьте код элемента управления
}


BOOL CRowEditorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Добавить дополнительную инициализацию

	UpdateData(TRUE);

	switch (m_selectedTable)
	{
	case cars_tbl:
	{
		m_carNumberEDIT.ShowWindow(SW_SHOW);
		m_carNumberSTATIC.ShowWindow(SW_SHOW);
		m_carBrandSTATIC.ShowWindow(SW_SHOW);
		m_carBrandEditor.ShowWindow(SW_SHOW);
		break;
	}
	case drivers_tbl:
	{
		m_driverNameEDIT.ShowWindow(SW_SHOW);
		m_driverNameSTATIC.ShowWindow(SW_SHOW);
		m_driverPatronymicEDIT.ShowWindow(SW_SHOW);
		m_driverPatronymicSTATIC.ShowWindow(SW_SHOW);
		m_driverSurnameSTATIC.ShowWindow(SW_SHOW);
		m_driverSurnameEDIT.ShowWindow(SW_SHOW);
		break;
	}
	case routes_tbl:
	{
		m_driverFullnameSTATIC.ShowWindow(SW_SHOW);
		m_routeIdSTATIC.ShowWindow(SW_SHOW);
		m_arrivalSTATIC.ShowWindow(SW_SHOW);
		m_routeCarNumberSTATIC.ShowWindow(SW_SHOW);

		m_routeIdEDIT.ShowWindow(SW_SHOW);
		m_arrivalEDIT.ShowWindow(SW_SHOW);

		//m_routeCarNumberCOMBO.ShowWindow(SW_SHOW);
		m_driverFullnameCOMBO.ShowWindow(SW_SHOW);
		m_CarNumberCOMBO.ShowWindow(SW_SHOW);
		
		CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();

		string query = "SELECT * FROM drivers";

		mysql_query(pFrame->conn,query.c_str());
		pFrame->res = mysql_store_result(pFrame->conn);

		
		while (pFrame->row = mysql_fetch_row(pFrame->res))
		{
			string surname = pFrame -> row[1];
			string name = pFrame -> row[2];
			string patronymic = pFrame->row[3];

			string full = surname + ' ' + name + ' ' + patronymic;

			m_driverFullnameCOMBO.AddString(CString(full.c_str()));
		}

		query = "SELECT * FROM cars";
		mysql_query(pFrame->conn, query.c_str());
		pFrame->res = mysql_store_result(pFrame->conn);
		while (pFrame->row = mysql_fetch_row(pFrame->res))
		{
			m_CarNumberCOMBO.AddString(CString(pFrame -> row[1]));

		}



		string driver_id = CT2A(m_driverId);
		query = "SELECT * FROM drivers WHERE driver_id = "+driver_id;

		

		mysql_query(pFrame->conn, query.c_str());
		pFrame->res = mysql_store_result(pFrame->conn);
		pFrame->row = mysql_fetch_row(pFrame->res);

		string surname = pFrame->row[1];
		string name = pFrame->row[2];
		string patronymic = pFrame->row[3];

		CString full =CString( (surname + ' ' + name + ' ' + patronymic).c_str());

		for (int i = 0;i < m_driverFullnameCOMBO.GetCount();i++)
		{
			
			CString comboFull = L"";

			m_driverFullnameCOMBO.GetLBText(i, comboFull);

			string strFull = CT2A(comboFull);


			if (comboFull == full)
			{
				m_driverFullnameCOMBO.SetCurSel(i);
				i = m_driverFullnameCOMBO.GetCount();
			}
		}



		string car_id = CT2A(m_carId);
		query = "SELECT car_number FROM cars WHERE car_id = " + car_id;
		mysql_query(pFrame->conn, query.c_str());
		pFrame->res = mysql_store_result(pFrame->conn);
		pFrame->row = mysql_fetch_row(pFrame->res);

		string car_number = pFrame->row[0];

		int a = m_CarNumberCOMBO.GetCount();

		for (int i = 0; i < m_CarNumberCOMBO.GetCount(); i++)
		{

			CString comboFull = L"";

			m_CarNumberCOMBO.GetLBText(i, comboFull);

			string strNumber= CT2A(comboFull);


			if (strNumber == car_number)
			{
				m_CarNumberCOMBO.SetCurSel(i);
				i = m_CarNumberCOMBO.GetCount();
			}
		}

		break;
	}
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	// Исключение: страница свойств OCX должна возвращать значение FALSE
}
void CRowEditorDlg::InitializingEditor(table selectedTable)
{
	m_selectedTable = selectedTable;
}
void CRowEditorDlg::SetCarTableItems(CString carNumber, CString carBrand)
{
	m_carNumberVALUE = carNumber;
	m_carBrandVALUE = carBrand;


}
CString* CRowEditorDlg::GetTableItems()
{
	switch (m_selectedTable)
	{
	case cars_tbl:
	{
		CString items[2];

		items[0] = m_carNumberVALUE;
		items[1] = m_carBrandVALUE;

		return items;
	}
	case drivers_tbl:
	{
		CString items[3];

		items[0] = m_driverSurnameVALUE;
		items[1] = m_driverNameVALUE;
		items[2] = m_driverPatronymicVALUE;

		return items;
	}
	case routes_tbl:
	{
		CString items[3];
		items[0] = m_driverId;
		items[1] = m_carId;
		items[2] = m_arrivalVALUE;

		return items;

		break;
	}
	default:
	{
		return NULL;
	}

	}

}

void CRowEditorDlg::SetDriverTableItems(CString surname, CString name, CString patronymic)
{
	m_driverNameVALUE = name;
	m_driverSurnameVALUE = surname;
	m_driverPatronymicVALUE = patronymic;
}
void CRowEditorDlg::SetRoutesTableItems(CString routeId, CString driverId, CString carId, CString arrival)
{
	m_routeIdVALUE = routeId;
	m_driverId = driverId;
	m_carId = carId;
	m_arrivalVALUE = arrival;
}

void CRowEditorDlg::OnCbnSelchangeDriverfullnameCombo()	
{
	// TODO: добавьте свой код обработчика уведомлений
	CString fullName;

	m_driverFullnameCOMBO.GetLBText(m_driverFullnameCOMBO.GetCurSel(),fullName);

	string strFullName = CT2A(fullName);
	

	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();

	istringstream iss(strFullName);

	

	string surname,name,patronymic;

	int i = 0;
	string str;
	while (iss >> str)
	{
		switch (i)
		{
			case 0:
				surname = str;
				break;
			case 1:
				name = str;
				break;
			default:
				patronymic = str;
				break;
		}
		i++;
	}

	string sql = "SELECT driver_id FROM drivers WHERE driver_surname = '"+surname+"' AND driver_name = '"+name+"' AND driver_patronymic = '"+patronymic+"'";

	mysql_query(pFrame->conn,sql.c_str());

	pFrame -> res = mysql_store_result(pFrame->conn);

	pFrame->row = mysql_fetch_row(pFrame->res);

	m_driverId = CString(pFrame->row[0]);	
}


void CRowEditorDlg::OnCbnSelchangerouteCarNumberCombo()
{
	
	CString carNumber;
	m_CarNumberCOMBO.GetLBText(m_CarNumberCOMBO.GetCurSel(), carNumber);

	string strCarNumber = CT2A(carNumber);

	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();

	string sql = "SELECT car_id FROM cars WHERE car_number = '"+strCarNumber+"'";

	mysql_query(pFrame->conn,sql.c_str());

	pFrame->res = mysql_store_result(pFrame->conn);
	pFrame->row = mysql_fetch_row(pFrame->res);

	m_carId = CString(pFrame->row[0]);
	auto a = m_carId;
	
	// TODO: добавьте свой код обработчика уведомлений
}

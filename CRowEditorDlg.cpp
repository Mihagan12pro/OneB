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

		pFrame->m_Connection.Connect();
		string driver_id = CT2A(m_driverId);

		string sql = "SELECT CONCAT( driver_surname, ' ',driver_name,' ',driver_patronymic) FROM drivers	WHERE driver_id = " + driver_id;
		
		CString fullname = CString(pFrame -> m_Connection.SELECT(sql)[0][0]);
		sql = "SELECT CONCAT( driver_surname, ' ',driver_name,' ',driver_patronymic) FROM drivers";

		

		for (int i = 0; i < pFrame->m_Connection.SELECT(sql).size();i++)
		{
			m_driverFullnameCOMBO.AddString(CString(pFrame->m_Connection.SELECT(sql)[i][0]));

			if (fullname == CString(pFrame->m_Connection.SELECT(sql)[i][0]))
			{
				m_driverFullnameCOMBO.SetCurSel(i);
			}
		} 
		string car_id = CT2A(m_carId);
		sql = "SELECT car_number FROM cars	WHERE car_id = " + car_id;
		
		CString car_number = pFrame -> m_Connection.SELECT(sql)[0][0];
		sql = "SELECT car_number FROM cars";

		for (int i = 0; i < pFrame->m_Connection.SELECT(sql).size();i++)
		{
			m_CarNumberCOMBO.AddString(pFrame->m_Connection.SELECT(sql)[i][0]);

			if (car_number == pFrame->m_Connection.SELECT(sql)[i][0])
			{
				m_CarNumberCOMBO.SetCurSel(i);
			}
		}
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
vector<CString> CRowEditorDlg::GetTableItems()
{
	vector<CString>items;
	switch (m_selectedTable)
	{
	case cars_tbl:
	{
		if (m_carNumberVALUE != L"" && m_carBrandVALUE != L"")
		{
			items.push_back(m_carNumberVALUE);
			items.push_back(m_carBrandVALUE);
		}
		
		break;
	}
	case drivers_tbl:
	{
		if (m_driverSurnameVALUE != L"" && m_driverNameVALUE != L"" && m_driverPatronymicVALUE != L"")
		{
			items.push_back(m_driverSurnameVALUE);
			items.push_back(m_driverNameVALUE);
			items.push_back(m_driverPatronymicVALUE);
		}
		break;
	}
	case routes_tbl:
	{
		if (m_driverId != L"" && m_carId != "" && m_arrivalVALUE != L"")
		{
			items.push_back(m_driverId);
			items.push_back(m_carId);
			items.push_back(m_arrivalVALUE);
		}
		break;
	}
	default:
	{
		break;
	}

	}
	return items;
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


	

	m_driverId = CString(pFrame->m_Connection.SELECT(sql)[0][0]);
}


void CRowEditorDlg::OnCbnSelchangerouteCarNumberCombo()
{
	
	CString carNumber;
	m_CarNumberCOMBO.GetLBText(m_CarNumberCOMBO.GetCurSel(), carNumber);

	string strCarNumber = CT2A(carNumber);

	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();

	string sql = "SELECT car_id FROM cars WHERE car_number = '"+strCarNumber+"'";

	m_carId = pFrame->m_Connection.SELECT(sql)[0][0];
	
	// TODO: добавьте свой код обработчика уведомлений
}

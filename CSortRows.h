#pragma once



// представление формы CSortRows

class CSortRowsView : public CFormView
{
	DECLARE_DYNCREATE(CSortRowsView)

protected:
	CSortRowsView();           // защищенный конструктор, используемый при динамическом создании
	virtual ~CSortRowsView();

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
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
};



﻿
// OneBDoc.h: интерфейс класса COneBDoc 
//


#pragma once
class CTableExplorerView;
class COneBView;
class CFilterRowsView;
class COneBDoc : public CDocument
{
protected: // создать только из сериализации
	COneBDoc() noexcept;
	DECLARE_DYNCREATE(COneBDoc)

// Атрибуты
public:
	CTableExplorerView* m_pTreeView;
	COneBView* m_pView;
	CFilterRowsView* m_pFormView;
// Операции
public:

// Переопределение
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Реализация
public:
	virtual ~COneBDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	 friend class CMainFrame;
// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Вспомогательная функция, задающая содержимое поиска для обработчика поиска
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};

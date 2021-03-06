
// TreeViewDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TreeView.h"
#include "TreeViewDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CTreeViewDlg dialog



CTreeViewDlg::CTreeViewDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_TREEVIEW_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTreeViewDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE1, m_TreeCtrl);
}

BEGIN_MESSAGE_MAP(CTreeViewDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE1, &CTreeViewDlg::OnTvnSelchangedTree1)
END_MESSAGE_MAP()


// CTreeViewDlg message handlers

BOOL CTreeViewDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);
	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	
	populateTree();

return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTreeViewDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTreeViewDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTreeViewDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTreeViewDlg::OnTvnSelchangedTree1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}
HTREEITEM CTreeViewDlg::addNode(LPWSTR name) {
	TVINSERTSTRUCT tvInsert;
	tvInsert.hParent = NULL;
	tvInsert.hInsertAfter = NULL;
	tvInsert.item.mask = TVIF_TEXT;
	tvInsert.item.pszText = name;

	HTREEITEM hCountry = m_TreeCtrl.InsertItem(&tvInsert);
	return hCountry;
}

HTREEITEM CTreeViewDlg::addItem(LPWSTR text, HTREEITEM node) {
	HTREEITEM hPA = m_TreeCtrl.InsertItem(TVIF_TEXT,
		text, 0, 0, 0, 0, 0, node, NULL);
	return hPA;
}

HTREEITEM CTreeViewDlg::insertAfter(HTREEITEM node,HTREEITEM subNode,LPWSTR name) {
	HTREEITEM hWA = m_TreeCtrl.InsertItem(name,
		0, 0, node, subNode);
	return hWA;
}

void CTreeViewDlg::populateTree() {
	HTREEITEM list1 = addNode(_T("List 1"));
	HTREEITEM list2 = addNode(_T("List 2"));
	HTREEITEM list3 = addNode(_T("List 3"));
	HTREEITEM item1 = addItem(_T("Item 1"), list1);
	HTREEITEM item2 = addItem(_T("Item 1"), list2);
	HTREEITEM item3 = addItem(_T("Item 1"), list3);
	insertAfter(list1, item1, _T("Item # 1, Sub Item # 1"));
	insertAfter(list1, item1, _T("Item # 1, Sub Item # 2"));
	insertAfter(list2, item2, _T("Item # 2, Sub Item # 1"));
	insertAfter(list2, item2, _T("Item # 2, Sub Item # 2"));
	insertAfter(list3, item3, _T("Item # 3, Sub Item # 1"));
}
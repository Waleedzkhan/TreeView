
// TreeViewDlg.h : header file
//

#pragma once
#include "afxcmn.h"


// CTreeViewDlg dialog
class CTreeViewDlg : public CDialog
{
// Construction
public:
	CTreeViewDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TREEVIEW_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CTreeCtrl m_TreeCtrl;
	afx_msg void OnTvnSelchangedTree1(NMHDR *pNMHDR, LRESULT *pResult);
	HTREEITEM addNode(LPWSTR Name); // Adds a head Node
	HTREEITEM addItem(LPWSTR text,HTREEITEM node); // Adds a first level subNode
	HTREEITEM insertAfter(HTREEITEM node,HTREEITEM subNode,LPWSTR txt); // Adds a node after a specified node
	void populateTree();
};

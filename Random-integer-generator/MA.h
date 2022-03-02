#pragma once
#include "afxdialogex.h"


// MA 对话框

class MA : public CDialogEx
{
	DECLARE_DYNAMIC(MA)

public:
	MA(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~MA();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_MAIN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnStart();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
//	virtual void OnOK();
//	afx_msg void OnClose();
//	virtual void OnOK();
//	virtual void OnCancel();
	afx_msg void OnBnClickedButtonSaveConfig();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedMinCut();
	afx_msg void OnBnClickedMinAdd();
	afx_msg void OnBnClickedMaxCut();
	afx_msg void OnBnClickedMaxAdd();
	afx_msg void OnBnClickedTimesCut();
	afx_msg void OnBnClickedTimesAdd();
};

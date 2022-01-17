
// Random_integer_generatorDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "Random_integer_generator.h"
#include "Random_integer_generatorDlg.h"
#include "afxdialogex.h"
#include "MA.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CRandom_integer_generatorDlg 对话框



CRandom_integer_generatorDlg::CRandom_integer_generatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Random_integer_generator_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
}

void CRandom_integer_generatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CRandom_integer_generatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CRandom_integer_generatorDlg::OnBnClickedOk)
//	ON_WM_MOUSEMOVE()
ON_WM_NCHITTEST()
ON_BN_CLICKED(IDC_BTN_OPENM, &CRandom_integer_generatorDlg::OnBnClickedBtnOpenm)
END_MESSAGE_MAP()


// CRandom_integer_generatorDlg 消息处理程序

BOOL CRandom_integer_generatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	HICON icon;
	icon = AfxGetApp()->LoadIcon(IDI_ICON1);
	SetIcon(icon, TRUE);			// 设置大图标
	SetIcon(icon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	CRect rectDlg;
	HDC desktopDc = ::GetDC(NULL);
	int s = GetDeviceCaps(desktopDc, VERTRES);
	double sk = GetDeviceCaps(desktopDc, LOGPIXELSY) / static_cast<double>(96);
	GetWindowRect(rectDlg);//x,y为对话框左上角的坐标 w,h为对话框的宽高
	SetWindowPos(NULL, 0, int(s-120*sk), rectDlg.Width(), rectDlg.Height(), NULL);
	CString con = AfxGetApp()->m_lpCmdLine;
	if (con != _T("-silence"))
	{
		MA* pOneDlgObj = new MA;
		if (pOneDlgObj)
		{
			BOOL ret = pOneDlgObj->Create(IDD_DIALOG_MAIN, GetDesktopWindow());
		}
		pOneDlgObj->ShowWindow(SW_SHOW);
	}
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CRandom_integer_generatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CRandom_integer_generatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CRandom_integer_generatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CRandom_integer_generatorDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


LRESULT CRandom_integer_generatorDlg::OnNcHitTest(CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CRect rc;
	GetClientRect(&rc);
	ClientToScreen(&rc);
	return rc.PtInRect(point) ? HTCAPTION : CDialog::OnNcHitTest(point);
}


void CRandom_integer_generatorDlg::OnBnClickedBtnOpenm()
{
	// TODO: 在此添加控件通知处理程序代码
	MA* pOneDlgObj = new MA;
	if (pOneDlgObj)
	{
		BOOL ret = pOneDlgObj->Create(IDD_DIALOG_MAIN, GetDesktopWindow());
	}
	pOneDlgObj->ShowWindow(SW_SHOW);
}

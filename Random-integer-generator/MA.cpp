// MA.cpp: 实现文件
//

#include "pch.h"
#include "Random_integer_generator.h"
#include "afxdialogex.h"
#include "MA.h"


// MA 对话框

IMPLEMENT_DYNAMIC(MA, CDialogEx)

MA::MA(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_MAIN, pParent)
{

}

MA::~MA()
{
}

void MA::DoDataExchange(CDataExchange* pDX)
{
	HDC desktopDc = ::GetDC(NULL);
	double sk = GetDeviceCaps(desktopDc, LOGPIXELSY) / static_cast<double>(96);
	CFont* f;
	f = new CFont;
	f->CreateFont(
		int(75 * sk), // nHeight
		0, // nWidth
		0, // nEscapement
		0, // nOrientation
		TRUE, // nWeight
		FALSE, // bItalic
		FALSE, // bUnderline
		0, // cStrikeOut
		NULL, // nCharSet
		NULL, // nOutPrecision
		NULL, // nClipPrecision
		NULL, // nQuality
		NULL, // nPitchAndFamily
		_T("微软雅黑")); // lpszFac
	GetDlgItem(IDC_EDIT_OUT)->SetFont(f);
	CFont* d;
	d = new CFont;
	d->CreateFont(
		int(30 * sk), // nHeight
		0, // nWidth
		0, // nEscapement
		0, // nOrientation
		FALSE, // nWeight
		FALSE, // bItalic
		FALSE, // bUnderline
		0, // cStrikeOut
		NULL, // nCharSet
		NULL, // nOutPrecision
		NULL, // nClipPrecision
		NULL, // nQuality
		NULL, // nPitchAndFamily
		_T("微软雅黑")); // lpszFac
	GetDlgItem(IDC_EDIT_MIN)->SetFont(d);
	GetDlgItem(IDC_EDIT_MAX)->SetFont(d);
	GetDlgItem(IDC_EDIT_TIMES)->SetFont(d);
	CFont* a;
	a = new CFont;
	a->CreateFont(
		int(50 * sk), // nHeight
		0, // nWidth
		0, // nEscapement
		0, // nOrientation
		TRUE, // nWeight
		FALSE, // bItalic
		FALSE, // bUnderline
		0, // cStrikeOut
		NULL, // nCharSet
		NULL, // nOutPrecision
		NULL, // nClipPrecision
		NULL, // nQuality
		NULL, // nPitchAndFamily
		_T("微软雅黑")); // lpszFac
	GetDlgItem(IDC_BTN_START)->SetFont(a);
	CFont* h;
	h = new CFont;
	h->CreateFont(
		int(100 * sk), // nHeight
		0, // nWidth
		0, // nEscapement
		0, // nOrientation
		TRUE, // nWeight
		FALSE, // bItalic
		FALSE, // bUnderline
		0, // cStrikeOut
		NULL, // nCharSet
		NULL, // nOutPrecision
		NULL, // nClipPrecision
		NULL, // nQuality
		NULL, // nPitchAndFamily
		_T("华文中宋")); // lpszFac
	GetDlgItem(IDC_STATIC_TITLE)->SetFont(h);
	CFont* e;
	e = new CFont;
	e->CreateFont(
		int(30 * sk), // nHeight
		0, // nWidth
		0, // nEscapement
		0, // nOrientation
		FALSE, // nWeight
		FALSE, // bItalic
		FALSE, // bUnderline
		0, // cStrikeOut
		NULL, // nCharSet
		NULL, // nOutPrecision
		NULL, // nClipPrecision
		NULL, // nQuality
		NULL, // nPitchAndFamily
		_T("微软雅黑")); // lpszFac
	GetDlgItem(IDC_STATIC_GROUP1)->SetFont(e);
	GetDlgItem(IDC_STATIC_GROUP2)->SetFont(e);
	GetDlgItem(IDC_STATIC_MORE)->SetFont(e);
	GetDlgItem(IDC_STATIC_ABOUT)->SetFont(e);
	CFont* k;
	k = new CFont;
	k->CreateFont(
		int(20 * sk), // nHeight
		0, // nWidth
		0, // nEscapement
		0, // nOrientation
		FALSE, // nWeight
		FALSE, // bItalic
		FALSE, // bUnderline
		0, // cStrikeOut
		NULL, // nCharSet
		NULL, // nOutPrecision
		NULL, // nClipPrecision
		NULL, // nQuality
		NULL, // nPitchAndFamily
		_T("微软雅黑")); // lpszFac
	GetDlgItem(IDC_STATIC_MIN)->SetFont(k);
	GetDlgItem(IDC_STATIC_MAX)->SetFont(k);
	GetDlgItem(IDC_STATIC_TIMES)->SetFont(k);
	GetDlgItem(IDC_CHECK_R)->SetFont(k);
	GetDlgItem(IDC_BUTTON_SAVE_CONFIG)->SetFont(k);
	GetDlgItem(IDC_STATIC_SAVE)->SetFont(k);
	GetDlgItem(IDC_STATIC_INF1)->SetFont(k);
	CString get_min;
	CString get_max;
	CString get_times;
	CString get_allow_repetition;
	CString sPath;
	GetModuleFileName(NULL, sPath.GetBufferSetLength(MAX_PATH + 1), MAX_PATH);
	sPath.ReleaseBuffer();
	int nPos;
	nPos = sPath.ReverseFind('\\');
	sPath = sPath.Left(nPos) + _T("\\config.ini");
	GetPrivateProfileString(_T("config"), _T("min"), _T(""), get_min.GetBuffer(MAX_PATH), MAX_PATH, sPath);
	GetPrivateProfileString(_T("config"), _T("max"), _T(""), get_max.GetBuffer(MAX_PATH), MAX_PATH, sPath);
	GetPrivateProfileString(_T("config"), _T("times"), _T(""), get_times.GetBuffer(MAX_PATH), MAX_PATH, sPath);
	GetPrivateProfileString(_T("config"), _T("allow_repetition"), _T("FALSE"), get_allow_repetition.GetBuffer(MAX_PATH), MAX_PATH, sPath);
	GetDlgItem(IDC_EDIT_MIN)->SetWindowText(get_min);
	GetDlgItem(IDC_EDIT_MAX)->SetWindowText(get_max);
	GetDlgItem(IDC_EDIT_TIMES)->SetWindowText(get_times);
	if (get_allow_repetition == _T("TRUE"))((CButton*)GetDlgItem(IDC_CHECK_R))->SetCheck(1);
}


BEGIN_MESSAGE_MAP(MA, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_START, &MA::OnBnClickedBtnStart)
//	ON_WM_CLOSE()
ON_BN_CLICKED(IDC_BUTTON_SAVE_CONFIG, &MA::OnBnClickedButtonSaveConfig)
END_MESSAGE_MAP()


// MA 消息处理程序


void MA::OnBnClickedBtnStart()
{
	// TODO: 在此添加控件通知处理程序代码
	CStringArray output;
	CString str_min;
	CString str_max;
	CString times;
	BOOL ifc;
	BOOL ifcy;
	int num;
	CString Cnum;
	GetDlgItem(IDC_EDIT_MIN)->GetWindowText(str_min);
	GetDlgItem(IDC_EDIT_MAX)->GetWindowText(str_max);
	GetDlgItem(IDC_EDIT_TIMES)->GetWindowText(times);
	if (((CButton*)GetDlgItem(IDC_CHECK_R))->GetCheck() == 1) {
		ifc = TRUE;
	}
	else ifc = FALSE;
	if(_wtoi(str_max)< _wtoi(str_min) || str_min.IsEmpty()|| str_max.IsEmpty() || times.IsEmpty()||(!ifc&& _wtoi(str_max)- _wtoi(str_min)+1<_wtoi(times))|| _wtoi(str_max) == INT_MAX)
	{
		CString errs = _T("错误：");
		if (_wtoi(str_max) < _wtoi(str_min))errs += _T("\r\n最大值大于最小值");
		if (str_min.IsEmpty())errs += _T("\r\n最小值为空");
		if (str_max.IsEmpty())errs += _T("\r\n最大值为空");
		if (times.IsEmpty())errs += _T("\r\n次数为空");
		if (!ifc && _wtoi(str_max) - _wtoi(str_min) + 1 < _wtoi(times))errs += _T("\r\n次数大于可取值个数");
		if (_wtoi(str_max) == INT_MAX) {
			CString i_max;
			i_max.Format(_T("%d"), INT_MAX);
			errs += _T("\r\n最大值大于或等于INT_MAX(=")+i_max+_T(")");
		}
		MessageBox(errs, _T("错误"), MB_ICONERROR);
		return;
	}
	int t = 1;
	for (; t <= _wtoi(times);) {
		num = rand() % (_wtoi(str_max) - _wtoi(str_min) + 1) + _wtoi(str_min);
		Cnum.Format(_T("%d"), num);
		if (!ifc) {
			ifcy = TRUE;
			for (int xp = 0;xp< output.GetCount(); xp++) {
				if (output[xp] == Cnum) {
					ifcy = FALSE;
					break;
				}
			}
			if (ifcy) {
				output.Add(Cnum);
				t++;
			}
		}
		else {
			output.Add(Cnum);
			t++;
		}
	}
	CString print_out;
	for (int i = 0; i < output.GetCount(); i++)
	{
		if ((i + 1) % 5 == 0 && static_cast<long long>(i) + 1 == output.GetCount())print_out += output[i];
		else if ((i + 1) % 5 == 0 && static_cast<long long>(i) + 1 != output.GetCount())print_out += output[i] + _T("\r\n");
		else print_out += output[i] + _T(" ");
	}
	GetDlgItem(IDC_EDIT_OUT)->SetWindowText(print_out);
}


BOOL MA::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	if (WM_KEYDOWN == pMsg->message && 13 == pMsg->wParam)
	{
		OnBnClickedBtnStart();
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}

void MA::OnBnClickedButtonSaveConfig()
{
	// TODO: 在此添加控件通知处理程序代码
	CFileFind Cfind;
	CString str_min;
	CString str_max;
	CString times;
	GetDlgItem(IDC_EDIT_MIN)->GetWindowText(str_min);
	GetDlgItem(IDC_EDIT_MAX)->GetWindowText(str_max);
	GetDlgItem(IDC_EDIT_TIMES)->GetWindowText(times);
	CString sPath;
	GetModuleFileName(NULL, sPath.GetBufferSetLength(MAX_PATH + 1), MAX_PATH);
	sPath.ReleaseBuffer();
	int nPos;
	nPos = sPath.ReverseFind('\\');
	sPath = sPath.Left(nPos)+_T("\\config.ini");
	WritePrivateProfileString(_T("config"),_T("min"), str_min,sPath);
	WritePrivateProfileString(_T("config"),_T("max"), str_max,sPath);
	WritePrivateProfileString(_T("config"),_T("times"), times,sPath);
	if (((CButton*)GetDlgItem(IDC_CHECK_R))->GetCheck() == 1)WritePrivateProfileString(_T("config"), _T("allow_repetition"), _T("TRUE"), sPath);
	else WritePrivateProfileString(_T("config"), _T("allow_repetition"), _T("FALSE"), sPath);
}


BOOL MA::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	HICON icon;
	icon = AfxGetApp()->LoadIcon(IDI_ICON1);
	SetIcon(icon, TRUE);			// 设置大图标
	SetIcon(icon, FALSE);		// 设置小图标

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

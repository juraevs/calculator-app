
// calculatorDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "calculator.h"
#include "calculatorDlg.h"
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


// CcalculatorDlg dialog



CcalculatorDlg::CcalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCULATOR_DIALOG, pParent)
	, m_output(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CcalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_RESULT, m_output);
	DDX_Control(pDX, IDC_BUTTON_0, m_button_0);
	DDX_Control(pDX, IDC_BUTTON_1, m_button_1);
	DDX_Control(pDX, IDC_BUTTON_2, m_button_2);
	DDX_Control(pDX, IDC_BUTTON_3, m_button_3);
	DDX_Control(pDX, IDC_BUTTON_4, m_button_4);
	DDX_Control(pDX, IDC_BUTTON_5, m_button_5);
	DDX_Control(pDX, IDC_BUTTON_6, m_button_6);
	DDX_Control(pDX, IDC_BUTTON_7, m_button_7);
	DDX_Control(pDX, IDC_BUTTON_8, m_button_8);
	DDX_Control(pDX, IDC_BUTTON_9, m_button_9);
	DDX_Control(pDX, IDC_BUTTON_POINT, m_button_point);
	DDX_Control(pDX, IDC_BUTTON_ADD, m_button_add);
	DDX_Control(pDX, IDC_BUTTON_MINUS, m_button_minus);
	DDX_Control(pDX, IDC_BUTTON_DIVIDE, m_button_divide);
	DDX_Control(pDX, IDC_BUTTON_MIN_PLUS, m_button_minplus);
	DDX_Control(pDX, IDC_BUTTON_EQUAL, m_button_equal);
	DDX_Control(pDX, IDC_BUTTON_CLEAR, m_button_clear);
	DDX_Control(pDX, IDC_BUTTON_MULTIPLY, m_button_multiply);
	DDX_Control(pDX, IDC_EDIT_RESULT, m_display);
}

BEGIN_MESSAGE_MAP(CcalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_0, &CcalculatorDlg::OnBnClickedButton0)
	ON_BN_CLICKED(IDC_BUTTON_1, &CcalculatorDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON_2, &CcalculatorDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON_3, &CcalculatorDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON_4, &CcalculatorDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON_5, &CcalculatorDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON_6, &CcalculatorDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON_7, &CcalculatorDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON_8, &CcalculatorDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON_9, &CcalculatorDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON_POINT, &CcalculatorDlg::OnBnClickedButtonPoint)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CcalculatorDlg::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_MINUS, &CcalculatorDlg::OnBnClickedButtonMinus)
	ON_BN_CLICKED(IDC_BUTTON_MULTIPLY, &CcalculatorDlg::OnBnClickedButtonMultiply)
	ON_BN_CLICKED(IDC_BUTTON_DIVIDE, &CcalculatorDlg::OnBnClickedButtonDivide)
	ON_BN_CLICKED(IDC_BUTTON_MIN_PLUS, &CcalculatorDlg::OnBnClickedButtonMinPlus)
	ON_BN_CLICKED(IDC_BUTTON_EQUAL, &CcalculatorDlg::OnBnClickedButtonEqual)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, &CcalculatorDlg::OnBnClickedButtonClear)
END_MESSAGE_MAP()


// CcalculatorDlg message handlers

BOOL CcalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	m_font.CreateFont(25, 0, 0, 0, FW_BOLD, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, _T("SF Mono"));
	m_resFont.CreateFont(32, 0, 0, 0, FW_BOLD, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, _T("Syne Mono"));
	m_button_0.SetFont(&m_font);
	m_button_1.SetFont(&m_font);
	m_button_2.SetFont(&m_font);
	m_button_3.SetFont(&m_font);
	m_button_4.SetFont(&m_font);
	m_button_5.SetFont(&m_font);
	m_button_6.SetFont(&m_font);
	m_button_7.SetFont(&m_font);
	m_button_8.SetFont(&m_font);
	m_button_9.SetFont(&m_font);
	m_button_point.SetFont(&m_font);
	m_button_add.SetFont(&m_font);
	m_button_minus.SetFont(&m_font);
	m_button_divide.SetFont(&m_font);
	m_button_minplus.SetFont(&m_font);
	m_button_equal.SetFont(&m_font);
	m_button_clear.SetFont(&m_font);
	m_button_multiply.SetFont(&m_font);
	m_display.SetFont(&m_resFont);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CcalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CcalculatorDlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CcalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CcalculatorDlg::addDigit(char digit)
{
	m_output += digit;
	UpdateData(FALSE);
}

void CcalculatorDlg::OnBnClickedButton0()
{
	// TODO: Add your control notification handler code here
	addDigit('0');
}


void CcalculatorDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	addDigit('1');
}


void CcalculatorDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	addDigit('2');
}


void CcalculatorDlg::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
	addDigit('3');
}


void CcalculatorDlg::OnBnClickedButton4()
{
	// TODO: Add your control notification handler code here
	addDigit('4');
}


void CcalculatorDlg::OnBnClickedButton5()
{
	// TODO: Add your control notification handler code here
	addDigit('5');
}


void CcalculatorDlg::OnBnClickedButton6()
{
	// TODO: Add your control notification handler code here
	addDigit('6');
}


void CcalculatorDlg::OnBnClickedButton7()
{
	// TODO: Add your control notification handler code here
	addDigit('7');
}


void CcalculatorDlg::OnBnClickedButton8()
{
	// TODO: Add your control notification handler code here
	addDigit('8');
}


void CcalculatorDlg::OnBnClickedButton9()
{
	// TODO: Add your control notification handler code here
	addDigit('9');
}


void CcalculatorDlg::OnBnClickedButtonPoint()
{
	// TODO: Add your control notification handler code here
	addDigit('.');
}


void CcalculatorDlg::OnBnClickedButtonAdd()
{
	// TODO: Add your control notification handler code here
	addDigit('+');
}


void CcalculatorDlg::OnBnClickedButtonMinus()
{
	// TODO: Add your control notification handler code here
	addDigit('-');
}


void CcalculatorDlg::OnBnClickedButtonMultiply()
{
	// TODO: Add your control notification handler code here
	addDigit('x');
}


void CcalculatorDlg::OnBnClickedButtonDivide()
{
	// TODO: Add your control notification handler code here
	addDigit('/');
}


void CcalculatorDlg::OnBnClickedButtonMinPlus()
{
	// TODO: Add your control notification handler code here
}


void CcalculatorDlg::OnBnClickedButtonEqual()
{
	// TODO: Add your control notification handler code here
}


void CcalculatorDlg::OnBnClickedButtonClear()
{
	// TODO: Add your control notification handler code here
}

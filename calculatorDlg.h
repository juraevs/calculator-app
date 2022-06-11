
// calculatorDlg.h : header file
//

#pragma once


// CcalculatorDlg dialog
class CcalculatorDlg : public CDialogEx
{
// Construction
public:
	CcalculatorDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULATOR_DIALOG };
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
private:
	CFont m_font;
	CFont m_resFont;
	CString m_output;
	void addDigit(char digit);
public:
	afx_msg void OnBnClickedButton0();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButtonPoint();
	afx_msg void OnBnClickedButtonAdd();
	afx_msg void OnBnClickedButtonMinus();
	afx_msg void OnBnClickedButtonMultiply();
	afx_msg void OnBnClickedButtonDivide();
	afx_msg void OnBnClickedButtonMinPlus();
	afx_msg void OnBnClickedButtonEqual();
	afx_msg void OnBnClickedButtonClear();
private:
	CButton m_button_0;
	CButton m_button_1;
	CButton m_button_2;
	CButton m_button_3;
	CButton m_button_4;
	CButton m_button_5;
	CButton m_button_6;
	CButton m_button_7;
	CButton m_button_8;
	CButton m_button_9;
	CButton m_button_point;
	CButton m_button_add;
	CButton m_button_minus;
	CButton m_button_divide;
	CButton m_button_multiply;
	CButton m_button_minplus;
	CButton m_button_equal;
	CButton m_button_clear;

	CEdit m_display;
};

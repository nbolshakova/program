
// kaskadDlg.h : ���� ���������
//

#pragma once
#include "afxcmn.h"

// ���������� ���� CkaskadDlg
class CkaskadDlg : public CDialogEx
{
// ��������
public:
	CkaskadDlg(CWnd* pParent = NULL);	// ����������� �����������

// ������ ����������� ����
	enum { IDD = IDD_KASKAD_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// ��������� DDX/DDV


// ����������
protected:
	HICON m_hIcon;

	// ��������� ������� ����� ���������
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();

    bool flag1,flag2;
	int cnt_err_del1,cnt_err_del2;
	float m_veroyat;
	UINT m_lenght_message;
	CString m_potok_error;
	float m_nu;
	float m_alfa;
	UINT m_dlit;
	afx_msg void OnBnClickedButton2();
	CString m_error_for_OPP;
	CListCtrl m_list;
	CListCtrl m_listDCK;
	afx_msg void OnLvnItemchangedList4(NMHDR *pNMHDR, LRESULT *pResult);
};

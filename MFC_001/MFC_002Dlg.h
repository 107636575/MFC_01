
// MFC_002Dlg.h : ͷ�ļ�
//

#pragma once


// MFC_002 �Ի���
class MFC_002 : public CDialogEx
{
// ����
public:
	MFC_002(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFC_001_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedCheck2();
	void DebugText(int line_temp, const char *func_temp,int Ctlr_ID);
	afx_msg void OnBnClickedBtnPwsubmit();
	afx_msg void OnBnClickedOk();
	afx_msg void OnEnChangeEditPw();
	CString Edit_PW;
};

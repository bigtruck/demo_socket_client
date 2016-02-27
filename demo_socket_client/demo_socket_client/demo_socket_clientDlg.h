
// demo_socket_clientDlg.h : 头文件
//

#pragma once
#include "afxwin.h"

#include "demo_socket_client.h"
#include "ClientSocket.h"

class CClientSocket;

// Cdemo_socket_clientDlg 对话框
class Cdemo_socket_clientDlg : public CDialogEx
{
// 构造
public:
	Cdemo_socket_clientDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DEMO_SOCKET_CLIENT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	bool m_connect;
	CClientSocket* pSock;                        // 客户端套接字指针对象
	BOOL WChar2MByte(LPCWSTR lpSrc, LPSTR lpDest, int nlen);
	//字符转换函数
public:
	CEdit m_CERecv;
	CEdit m_CESend;
	afx_msg void OnBnClickedConnect();
	afx_msg void OnBnClickedSend();
	CButton m_CBuClient;
};

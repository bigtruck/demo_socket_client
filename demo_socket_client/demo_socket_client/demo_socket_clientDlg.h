
// demo_socket_clientDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"

#include "demo_socket_client.h"
#include "ClientSocket.h"

class CClientSocket;

// Cdemo_socket_clientDlg �Ի���
class Cdemo_socket_clientDlg : public CDialogEx
{
// ����
public:
	Cdemo_socket_clientDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DEMO_SOCKET_CLIENT_DIALOG };
#endif

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
	bool m_connect;
	CClientSocket* pSock;                        // �ͻ����׽���ָ�����
	BOOL WChar2MByte(LPCWSTR lpSrc, LPSTR lpDest, int nlen);
	//�ַ�ת������
public:
	CEdit m_CERecv;
	CEdit m_CESend;
	afx_msg void OnBnClickedConnect();
	afx_msg void OnBnClickedSend();
	CButton m_CBuClient;
};

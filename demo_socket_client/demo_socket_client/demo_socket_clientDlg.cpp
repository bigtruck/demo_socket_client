
// demo_socket_clientDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "demo_socket_client.h"
#include "demo_socket_clientDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// Cdemo_socket_clientDlg �Ի���



Cdemo_socket_clientDlg::Cdemo_socket_clientDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DEMO_SOCKET_CLIENT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cdemo_socket_clientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_CERecv);
	DDX_Control(pDX, IDC_EDIT2, m_CESend);
	DDX_Control(pDX, IDC_Connect, m_CBuClient);
}

BEGIN_MESSAGE_MAP(Cdemo_socket_clientDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_Connect, &Cdemo_socket_clientDlg::OnBnClickedConnect)
	ON_BN_CLICKED(IDC_Send, &Cdemo_socket_clientDlg::OnBnClickedSend)
END_MESSAGE_MAP()


// Cdemo_socket_clientDlg ��Ϣ�������

BOOL Cdemo_socket_clientDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void Cdemo_socket_clientDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void Cdemo_socket_clientDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR Cdemo_socket_clientDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



BOOL Cdemo_socket_clientDlg::WChar2MByte(LPCWSTR lpSrc, LPSTR lpDest, int nlen)
{
	int n = 0;
	n = WideCharToMultiByte(CP_OEMCP, 0, lpSrc, -1, lpDest, 0, 0, FALSE);
	if (n<nlen)return FALSE;
	WideCharToMultiByte(CP_OEMCP, 0, lpSrc, -1, lpDest, nlen, 0, FALSE);
	return TRUE;
}

void Cdemo_socket_clientDlg::OnBnClickedConnect()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	if (m_connect)                             // ����Ѿ����ӣ���Ͽ�������
	{
		m_connect = false;
		pSock->Close();
		delete pSock;
		pSock = NULL;
		m_CBuClient.SetWindowTextW(_T("���ӷ�����"));
		UpdateData(false);
		return;
	}
	else                                                // δ���ӣ������ӷ�����
	{
		pSock = new CClientSocket();
		if (!pSock->Create())         //�����׽���
		{
			AfxMessageBox(_T("�����׽���ʧ�ܣ�"));
			return;
		}
	}
	if (!pSock->Connect(_T("127.0.0.1"), 8000))    //���ӷ�����
	{
		AfxMessageBox(_T("���ӷ�����ʧ�ܣ�"));
		return;
	}
	else
	{
		m_connect = true;
		m_CBuClient.SetWindowTextW(_T("�Ͽ�������"));
		UpdateData(false);
	}
}


void Cdemo_socket_clientDlg::OnBnClickedSend()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (!m_connect)return;                               //δ���ӷ�������ִ��
	UpdateData(true);                                     //��ȡ��������
	CString m_DataSend;
	m_CESend.GetWindowTextW(m_DataSend);
	if (m_DataSend != "")
	{
		char* pBuff = new char[m_DataSend.GetLength() * 2];
		memset(pBuff, 0, m_DataSend.GetLength() * 2);
		WChar2MByte(m_DataSend.GetBuffer(0), pBuff, m_DataSend.GetLength() * 2);
		pSock->SendMSG(pBuff, m_DataSend.GetLength() * 2);
	}
}

#include "stdafx.h"
#include "ClientSocket.h"

#include "demo_socket_clientDlg.h"

CClientSocket::CClientSocket()
{
}


CClientSocket::~CClientSocket()
{
}


void CClientSocket::OnReceive(int nErrorCode)
{
	// TODO: 在此添加专用代码和/或调用基类
	char* pData = NULL;
	pData = new char[1024];
	memset(pData, 0, sizeof(char) * 1024);
	UCHAR leng = 0;
	CString str;
	leng = Receive(pData, 1024, 0);
	str = pData;
	// 在编辑框中显示接收到的数据
	((Cdemo_socket_clientDlg*)theApp.GetMainWnd())->SetDlgItemTextW(IDC_DataReceive, str);
	delete pData;
	pData = NULL;
	CSocket::OnReceive(nErrorCode);
}

BOOL CClientSocket::SendMSG(LPSTR lpBuff, int nlen)
{
	//生成协议头
	if (Send(lpBuff, nlen) == SOCKET_ERROR)
	{
		AfxMessageBox(_T("发送错误！"));
		return FALSE;
	}
	return TRUE;
}

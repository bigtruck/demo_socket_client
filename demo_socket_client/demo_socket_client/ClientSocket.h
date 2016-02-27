#pragma once
#include "afxsock.h"
#include "demo_socket_clientDlg.h"

class CClientSocket :
	public CSocket
{
public:
	CClientSocket();
	~CClientSocket();
	virtual void OnReceive(int nErrorCode);
	BOOL SendMSG(LPSTR lpBuff, int nlen);
};


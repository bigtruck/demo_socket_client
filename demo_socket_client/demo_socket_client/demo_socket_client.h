
// demo_socket_client.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// Cdemo_socket_clientApp: 
// �йش����ʵ�֣������ demo_socket_client.cpp
//

class Cdemo_socket_clientApp : public CWinApp
{
public:
	Cdemo_socket_clientApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern Cdemo_socket_clientApp theApp;
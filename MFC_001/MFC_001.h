
// MFC_001.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// MFC_001:
// �йش����ʵ�֣������ MFC_001.cpp
//

class MFC_001 : public CWinApp
{
public:
	MFC_001();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern MFC_001 theApp;
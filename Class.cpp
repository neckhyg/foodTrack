// Class.cpp: implementation of the CClass class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "foodTrack.h"
#include "Class.h"
#include "Student.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CClass::CClass()
{
	m_F_AutoNo = _T("");
	m_F_Teacher = _T("");
	m_F_Date = 0;
	m_F_NoonID = 0;
	m_F_Remark = _T("");
}

CClass::~CClass()
{
	for(int i=0;i<m_arrStudent.GetSize();i++)
	{
		delete m_arrStudent[i];
	}
	m_arrStudent.RemoveAll();
}

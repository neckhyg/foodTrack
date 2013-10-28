// Student.cpp: implementation of the CStudent class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "foodTrack.h"
#include "Student.h"
#include "Item.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CStudent::CStudent()
{
	m_F_Sex = _T("");
	m_F_SN = _T("");
	m_F_Address = _T("");
	m_F_Tel = _T("");
	m_F_Date = 0;
	m_F_AutoNo = _T("");
	m_F_TypeID = 0;

	m_tmUpAuto = 0;
	m_tmExamField = 0;
	m_tmExamRoad = 0;
	m_nExamTypeID = 0;
	m_tmEnd = 0;

}

CStudent::~CStudent()
{

}

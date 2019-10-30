#pragma once

#include "pch.hpp"
#include "process.hpp"

VOID CProcess::InsertModule(const CModule& mod)
{
	m_ModuleList.push_back(mod);
}

CProcess::CProcess(CRefPtr<CLogEvent> pEvent) :
	CProcCreateInfoView(pEvent)
{
	
	//
	// Create new ProcessInfo
	//
	
	m_ProcessInfo = new CProcInfo(GetImagePath());

}

CProcess::~CProcess()
{
	
}

VOID CProcess::Dump()
{

}

std::vector<CModule>& CProcess::GetModuleList()
{
	return m_ModuleList;
}

CRefPtr<CProcInfo> CProcess::GetProcInfo()
{
	return m_ProcessInfo;
}

CProcInfo::CProcInfo(const CString& strPath)
{
	Parse(strPath);
}

CProcInfo::~CProcInfo()
{

}

BOOL CProcInfo::Parse(const CString& strPath)
{
	
	//
	// Query file version info
	//
	
	UtilGetFileVersionInfo(strPath, m_strDisplay, m_strCompanyName, m_strVersion);

	//
	// Query EXE file icon.
	//
	
	UtilExtractIcon(strPath, m_SmallIcon, m_LargeIcon);

	return TRUE;
}
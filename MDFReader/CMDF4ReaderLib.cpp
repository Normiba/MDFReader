#include "stdafx.h"
#include "CMDF4ReaderLib.h"


CMDF4ReaderLib::CMDF4ReaderLib(const char* pszDLLPathName)
{
	m_hMod = LoadLibraryEx(pszDLLPathName, NULL, LOAD_WITH_ALTERED_SEARCH_PATH);
	if (m_hMod)
	{
		(FARPROC&)m_pfInitDll = GetProcAddress(m_hMod, "M4RDInitDll");
		(FARPROC&)m_pfExitDll = GetProcAddress(m_hMod, "M4RDExitDll");
		(FARPROC&)m_pfOpenMDF4 = GetProcAddress(m_hMod, "M4RDOpenMDF4");
		(FARPROC&)m_pfGetFileTime = GetProcAddress(m_hMod, "M4RDGetFileTime");
		(FARPROC&)m_pfGetTimeFraction = GetProcAddress(m_hMod, "M4RDGetTimeFraction");
		(FARPROC&)m_pfGetNanoTimeUTC = GetProcAddress(m_hMod, "M4RDGetNanoTimeUTC");
		(FARPROC&)m_pfGetNGroups = GetProcAddress(m_hMod, "M4RDGetNGroups");
		(FARPROC&)m_pfGetGroupName = GetProcAddress(m_hMod, "M4RDGetGroupName");
		(FARPROC&)m_pfLoadGroup = GetProcAddress(m_hMod, "M4RDLoadGroup");
		(FARPROC&)m_pfGetNSignals = GetProcAddress(m_hMod, "M4RDGetNSignals");
		(FARPROC&)m_pfGetNSamples = GetProcAddress(m_hMod, "M4RDGetNSamples");
		(FARPROC&)m_pfGetFirstTimestamp = GetProcAddress(m_hMod, "M4RDGetFirstTimestamp");
		(FARPROC&)m_pfGetLastTimestamp = GetProcAddress(m_hMod, "M4RDGetLastTimestamp");
		(FARPROC&)m_pfTimeToIndex = GetProcAddress(m_hMod, "M4RDTimeToIndex");
		(FARPROC&)m_pfLoadTimeSignal = GetProcAddress(m_hMod, "M4RDLoadTimeSignal");
		(FARPROC&)m_pfLoadSignal = GetProcAddress(m_hMod, "M4RDLoadSignal");
		(FARPROC&)m_pfGetTimeSignal = GetProcAddress(m_hMod, "M4RDGetTimeSignal");
		(FARPROC&)m_pfGetSignal = GetProcAddress(m_hMod, "M4RDGetSignal");
		(FARPROC&)m_pfGetData = GetProcAddress(m_hMod, "M4RDGetData");
		(FARPROC&)m_pfCacheData = GetProcAddress(m_hMod, "M4RDCacheData");
		(FARPROC&)m_pfGetCachedValue = GetProcAddress(m_hMod, "M4RDGetCachedValue");
		(FARPROC&)m_pfGetComment = GetProcAddress(m_hMod, "M4RDGetComment");
		(FARPROC&)m_pfGetNoOfSRBlocks = GetProcAddress(m_hMod, "M4RDGetNoOfSRBlocks");
		(FARPROC&)m_pfGetSRdt = GetProcAddress(m_hMod, "M4RDGetSRdt");
		(FARPROC&)m_pfGetSRCycleCount = GetProcAddress(m_hMod, "M4RDGetSRCycleCount");
		(FARPROC&)m_pfCacheSRData = GetProcAddress(m_hMod, "M4RDCacheSRData");
		(FARPROC&)m_pfGetCachedSRValues = GetProcAddress(m_hMod, "M4RDGetCachedSRValues");
		(FARPROC&)m_pfGetMDF4File = GetProcAddress(m_hMod, "M4RDGetMDF4File");
		(FARPROC&)m_pfGetSignalDetail = GetProcAddress(m_hMod, "M4RDGetSignalDetail");
		(FARPROC&)m_pfGetRecordSize = GetProcAddress(m_hMod, "M4RDGetRecordSize");
		(FARPROC&)m_pfGetRecord = GetProcAddress(m_hMod, "M4RDGetRecord");
		(FARPROC&)m_pfGetInvalidBytes = GetProcAddress(m_hMod, "M4RDGetInvalidBytes");
		(FARPROC&)m_pfGetTimerQualityClass = GetProcAddress(m_hMod, "M4RDGetTimerQualityClass");
		(FARPROC&)m_pfGetVersion = GetProcAddress(m_hMod, "M4RDGetVersion");
		(FARPROC&)m_pfget_tz_offset_min = GetProcAddress(m_hMod, "M4RDget_tz_offset_min");
		(FARPROC&)m_pfget_dst_offset_min = GetProcAddress(m_hMod, "M4RDget_dst_offset_min");
		(FARPROC&)m_pfget_time_flags = GetProcAddress(m_hMod, "M4RDget_time_flags");
		(FARPROC&)m_pfGetDataEx = GetProcAddress(m_hMod, "M4RDGetDataEx");
	}
}


CMDF4ReaderLib::~CMDF4ReaderLib()
{
	if (m_hMod)
		FreeLibrary(m_hMod);
	m_hMod = NULL;
}

INT_PTR CMDF4ReaderLib::InitDll(void)
{
	m_hHandle = (*m_pfInitDll)();
	return m_hHandle;
}
void CMDF4ReaderLib::ExitDll()
{
	(*m_pfExitDll)(m_hHandle);
}

BOOL CMDF4ReaderLib::OpenMDF4(const wchar_t* strPathName)
{
	return (*m_pfOpenMDF4)(m_hHandle, strPathName);
}
long CMDF4ReaderLib::GetFileTime()
{
	return (*m_pfGetFileTime)(m_hHandle);
}
double CMDF4ReaderLib::GetTimeFraction()
{
	return (*m_pfGetTimeFraction)(m_hHandle);
}
__int64 CMDF4ReaderLib::GetNanoTimeUTC()
{
	return (*m_pfGetNanoTimeUTC)(m_hHandle);
}
long CMDF4ReaderLib::GetNGroups()
{
	return (*m_pfGetNGroups)(m_hHandle);
}
const wchar_t* CMDF4ReaderLib::GetGroupName(long iGroupIndex)
{
	return (*m_pfGetGroupName)(m_hHandle, iGroupIndex);
}
BOOL CMDF4ReaderLib::LoadGroup(long iGroupIndex)
{
	return (*m_pfLoadGroup)(m_hHandle, iGroupIndex);
}
long CMDF4ReaderLib::GetNSignals()
{
	return (*m_pfGetNSignals)(m_hHandle);
}
unsigned __int64 CMDF4ReaderLib::GetNSamples()
{
	return (*m_pfGetNSamples)(m_hHandle);
}
double CMDF4ReaderLib::GetFirstTimestamp()
{
	return (*m_pfGetFirstTimestamp)(m_hHandle);
}
double CMDF4ReaderLib::GetLastTimestamp()
{
	return (*m_pfGetLastTimestamp)(m_hHandle);
}
__int64 CMDF4ReaderLib::TimeToIndex(double TimeStamp, long lStartIndex)
{
	return (*m_pfTimeToIndex)(m_hHandle, TimeStamp, lStartIndex);
}
const wchar_t* CMDF4ReaderLib::LoadTimeSignal()
{
	return (*m_pfLoadTimeSignal)(m_hHandle);
}
const wchar_t* CMDF4ReaderLib::LoadSignal(long iSignalIndex)
{
	return (*m_pfLoadSignal)(m_hHandle, iSignalIndex);
}
BOOL CMDF4ReaderLib::GetTimeSignal(wchar_t* pszUnit, long* monotony, double* rmin, double* rmax, double* raster, long* bIsVirtual)
{
	return (*m_pfGetTimeSignal)(m_hHandle, pszUnit, monotony, rmin, rmax, raster, bIsVirtual);
}
BOOL CMDF4ReaderLib::GetSignal(wchar_t* pszDisplayName, wchar_t* pszAliasName, wchar_t* pszUnit, wchar_t* pszComment, long* discrete)
{
	return (*m_pfGetSignal)(m_hHandle, pszDisplayName, pszAliasName, pszUnit, pszComment, discrete);
}
__int64 CMDF4ReaderLib::GetData(BOOL bTime, long lFirstIndex, long lLastIndex, double* pBuffer)
{
	return (*m_pfGetData)(m_hHandle, bTime, lFirstIndex, lLastIndex, pBuffer);
}
long CMDF4ReaderLib::CacheData(BOOL bTime, long lFirstIndex, long lLastIndex)
{
	return (*m_pfCacheData)(m_hHandle, bTime, lFirstIndex, lLastIndex);
}
double CMDF4ReaderLib::GetCachedValue(BOOL bTime, long lIndex)
{
	return (*m_pfGetCachedValue)(m_hHandle, bTime, lIndex);
}
const wchar_t* CMDF4ReaderLib::GetComment(long nBlock, long nElement)
{
	return (*m_pfGetComment)(m_hHandle, nBlock, nElement);
}
long CMDF4ReaderLib::GetNoOfSRBlocks()
{
	return (*m_pfGetNoOfSRBlocks)(m_hHandle);
}
double CMDF4ReaderLib::GetSRdt(long nBlock)
{
	return (*m_pfGetSRdt)(m_hHandle, nBlock);
}
long CMDF4ReaderLib::GetSRCycleCount(long nBlock)
{
	return (*m_pfGetSRCycleCount)(m_hHandle, nBlock);
}
long CMDF4ReaderLib::CacheSRData(long nBlock, BOOL bTime, long lFirstIndex, long lLastIndex)
{
	return (*m_pfCacheSRData)(m_hHandle, nBlock, bTime, lFirstIndex, lLastIndex);
}
BOOL CMDF4ReaderLib::GetCachedSRValues(BOOL bTime, long lIndex, double* Min, double* Max, double* Mean)
{
	return (*m_pfGetCachedSRValues)(m_hHandle, bTime, lIndex, Min, Max, Mean);
}
UINT_PTR CMDF4ReaderLib::GetMDF4File()
{
	return (*m_pfGetMDF4File)(m_hHandle);
}
BOOL CMDF4ReaderLib::GetSignalDetail(long* lDataType, long* nFirstBit, long* nBits, double* Factor, double* Offset, double* RawMin, double* RawMax, long* bHasNoValues, long* invalPos)
{
	return (*m_pfGetSignalDetail)(m_hHandle, lDataType, nFirstBit, nBits, Factor, Offset, RawMin, RawMax, bHasNoValues, invalPos);
}
long CMDF4ReaderLib::GetRecordSize()
{
	return (*m_pfGetRecordSize)(m_hHandle);
}
BOOL CMDF4ReaderLib::GetRecord(__int64 i64StartIndex, __int64 i64EndIndex, BYTE* pBuffer)
{
	return (*m_pfGetRecord)(m_hHandle, i64StartIndex, i64EndIndex, pBuffer);
}
long CMDF4ReaderLib::GetInvalidBytes()
{
	return (*m_pfGetInvalidBytes)(m_hHandle);
}
long CMDF4ReaderLib::GetTimerQualityClass()
{
	return (*m_pfGetTimerQualityClass)(m_hHandle);
}
long CMDF4ReaderLib::GetVersion()
{
	return (*m_pfGetVersion)(m_hHandle);
}
long CMDF4ReaderLib::get_tz_offset_min()
{
	return (*m_pfget_tz_offset_min)(m_hHandle);
}
long CMDF4ReaderLib::get_dst_offset_min()
{
	return (*m_pfget_dst_offset_min)(m_hHandle);
}
long CMDF4ReaderLib::get_time_flags()
{
	return (*m_pfget_time_flags)(m_hHandle);
}
__int64 CMDF4ReaderLib::GetDataEx(BOOL bTime, long lFirstIndex, long lLastIndex, double* pBuffer)
{
	return (*m_pfGetDataEx)(m_hHandle, bTime, lFirstIndex, lLastIndex, pBuffer);
}

#pragma once
class CMDF4ReaderLib
{
public:
	CMDF4ReaderLib(const char* pszDLLPathName);
	~CMDF4ReaderLib();

	BOOL IsValid(void)
	{
		return m_hMod != 0;
	}

	INT_PTR InitDll(void);
	void ExitDll();
	BOOL OpenMDF4(const wchar_t* strPathName);
	long GetFileTime();
	double GetTimeFraction();
	__int64 GetNanoTimeUTC();
	long GetNGroups();
	const wchar_t* GetGroupName(long iGroupIndex);
	BOOL LoadGroup(long iGroupIndex);
	long GetNSignals();
	unsigned __int64 GetNSamples();
	double GetFirstTimestamp();
	double GetLastTimestamp();
	__int64 TimeToIndex(double TimeStamp, long lStartIndex);
	const wchar_t* LoadTimeSignal();
	const wchar_t* LoadSignal(long iSignalIndex);
	BOOL GetTimeSignal(wchar_t* pszUnit, long* monotony, double* rmin, double* rmax, double* raster, long* bIsVirtual);
	BOOL GetSignal(wchar_t* pszDisplayName, wchar_t* pszAliasName, wchar_t* pszUnit, wchar_t* pszComment, long* discrete);
	__int64 GetData(BOOL bTime, long lFirstIndex, long lLastIndex, double* pBuffer);
	long CacheData(BOOL bTime, long lFirstIndex, long lLastIndex);
	double GetCachedValue(BOOL bTime, long lIndex);
	const wchar_t* GetComment(long nBlock, long nElement);
	long GetNoOfSRBlocks();
	double GetSRdt(long nBlock);
	long GetSRCycleCount(long nBlock);
	long CacheSRData(long nBlock, BOOL bTime, long lFirstIndex, long lLastIndex);
	BOOL GetCachedSRValues(BOOL bTime, long lIndex, double* Min, double* Max, double* Mean);
	UINT_PTR GetMDF4File();
	BOOL GetSignalDetail(long* lDataType, long* nFirstBit, long* nBits, double* Factor, double* Offset, double* RawMin, double* RawMax, long* bHasNoValues, long* invalPos);
	long GetRecordSize();
	BOOL GetRecord(__int64 i64StartIndex, __int64 i64EndIndex, BYTE* pBuffer);
	long GetInvalidBytes();
	long GetTimerQualityClass();
	long GetVersion();
	long get_tz_offset_min();
	long get_dst_offset_min();
	long get_time_flags();
	__int64 GetDataEx(BOOL bTime, long lFirstIndex, long lLastIndex, double* pBuffer);

protected:
	HMODULE m_hMod;
	INT_PTR m_hHandle;

	INT_PTR(*m_pfInitDll)(void);
	void(*m_pfExitDll)(INT_PTR hHandle);
	BOOL(*m_pfOpenMDF4)(INT_PTR hHandle, const wchar_t* strPathName);
	long(*m_pfGetFileTime)(INT_PTR hHandle);
	double(*m_pfGetTimeFraction)(INT_PTR hHandle);
	__int64(*m_pfGetNanoTimeUTC)(INT_PTR hHandle);
	long(*m_pfGetNGroups)(INT_PTR hHandle);
	const wchar_t*(*m_pfGetGroupName)(INT_PTR hHandle, long iGroupIndex);
	BOOL(*m_pfLoadGroup)(INT_PTR hHandle, long iGroupIndex);
	long(*m_pfGetNSignals)(INT_PTR hHandle);
	unsigned __int64(*m_pfGetNSamples)(INT_PTR hHandle);
	double(*m_pfGetFirstTimestamp)(INT_PTR hHandle);
	double(*m_pfGetLastTimestamp)(INT_PTR hHandle);
	__int64(*m_pfTimeToIndex)(INT_PTR hHandle, double TimeStamp, long lStartIndex);
	const wchar_t*(*m_pfLoadTimeSignal)(INT_PTR hHandle);
	const wchar_t*(*m_pfLoadSignal)(INT_PTR hHandle, long iSignalIndex);
	BOOL(*m_pfGetTimeSignal)(INT_PTR hHandle, wchar_t* pszUnit, long* monotony, double* rmin, double* rmax, double* raster, long* bIsVirtual);
	BOOL(*m_pfGetSignal)(INT_PTR hHandle, wchar_t* pszDisplayName, wchar_t* pszAliasName, wchar_t* pszUnit, wchar_t* pszComment, long* discrete);
	__int64(*m_pfGetData)(INT_PTR hHandle, BOOL bTime, long lFirstIndex, long lLastIndex, double* pBuffer);
	long(*m_pfCacheData)(INT_PTR hHandle, BOOL bTime, long lFirstIndex, long lLastIndex);
	double(*m_pfGetCachedValue)(INT_PTR hHandle, BOOL bTime, long lIndex);
	const wchar_t*(*m_pfGetComment)(INT_PTR hHandle, long nBlock, long nElement);
	long(*m_pfGetNoOfSRBlocks)(INT_PTR hHandle);
	double(*m_pfGetSRdt)(INT_PTR hHandle, long nBlock);
	long(*m_pfGetSRCycleCount)(INT_PTR hHandle, long nBlock);
	long(*m_pfCacheSRData)(INT_PTR hHandle, long nBlock, BOOL bTime, long lFirstIndex, long lLastIndex);
	BOOL(*m_pfGetCachedSRValues)(INT_PTR hHandle, BOOL bTime, long lIndex, double* Min, double* Max, double* Mean);
	UINT_PTR(*m_pfGetMDF4File)(INT_PTR hHandle);
	BOOL(*m_pfGetSignalDetail)(INT_PTR hHandle, long* lDataType, long* nFirstBit, long* nBits, double* Factor, double* Offset, double* RawMin, double* RawMax, long* bHasNoValues, long* invalPos);
	long(*m_pfGetRecordSize)(INT_PTR hHandle);
	BOOL(*m_pfGetRecord)(INT_PTR hHandle, __int64 i64StartIndex, __int64 i64EndIndex, BYTE* pBuffer);
	long(*m_pfGetInvalidBytes)(INT_PTR hHandle);
	long(*m_pfGetTimerQualityClass)(INT_PTR hHandle);
	long(*m_pfGetVersion)(INT_PTR hHandle);
	long(*m_pfget_tz_offset_min)(INT_PTR hHandle);
	long(*m_pfget_dst_offset_min)(INT_PTR hHandle);
	long(*m_pfget_time_flags)(INT_PTR hHandle);
	__int64(*m_pfGetDataEx)(INT_PTR hHandle, BOOL bTime, long lFirstIndex, long lLastIndex, double* pBuffer);

};


#pragma once

#include <vector>

using namespace std;

typedef struct dataElement
{
	CHAR* signalName;
	vector<double> SignalTime;
	vector<double> SignalValue;
}DATAELEMENT;

class CMDFData
{
public:
	CMDFData(void);
	~CMDFData(void);
	
};

extern vector<DATAELEMENT> mdfData;


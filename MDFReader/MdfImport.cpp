#include "StdAfx.h"
#include "MdfImport.h"
#include "afxdialogex.h"
#include <string>

using namespace std;


#pragma comment(lib,"python38.lib")


CMDFImport::CMDFImport(void)
{
}


CMDFImport::~CMDFImport(void)
{
}


int CMDFImport::import(void)
{
	CString x;
	Py_Initialize();
	// ����ʼ���Ƿ�ɹ�
	if (!Py_IsInitialized())
	{
		return -1;
	}
	// ��ӵ�ǰ·��
	//��������ַ�����ΪPython����ֱ�����У�����0
	//��ʾ�ɹ���-1��ʾ�д����ʱ���������Ϊ�ַ���
	//�����﷨����
	PyRun_SimpleString("import sys");
	PyRun_SimpleString("sys.path.append('.\')");
	//PyRun_SimpleString("import subprocess");
	PyObject *pModule, *pDict, *pFunc, *pArgs;
	// ������Ϊ1�Ľű�
	pModule = PyImport_ImportModule("1test");

	if (!pModule)
	{
		x.Format(_T("cannot import test"));
		return -1;
	}
	pDict = PyModule_GetDict(pModule);
	if (!pDict)
	{

		x.Format(_T("cannot get dict"));
		return -2;
	}
	// �ҳ�������Ϊadd�ĺ���
	pFunc = PyDict_GetItemString(pDict, "add_func");
	if (!pFunc || !PyCallable_Check(pFunc))
	{
		x.Format(_T("cannot add func"));
		return -3;
	}
	// ������ջ
	pArgs = PyTuple_New(2);
	//  PyObject* Py_BuildValue(char *format, ...)
	//  ��C++�ı���ת����һ��Python���󡣵���Ҫ��
	//  C++���ݱ�����Pythonʱ���ͻ�ʹ������������˺���
	//  �е�����C��printf������ʽ��ͬ�����õĸ�ʽ��
	//  s ��ʾ�ַ�����
	//  i ��ʾ���ͱ�����
	//  f ��ʾ��������
	//  O ��ʾһ��Python����
	PyTuple_SetItem(pArgs, 0, Py_BuildValue("i", 3));  //"l" (integer) [long int] :��C���͵�longת����Pyhon�е�int����
	PyTuple_SetItem(pArgs, 1, Py_BuildValue("i", 4));
	// ����Python����
	PyObject* pRet = PyObject_CallObject(pFunc, pArgs);
	int res =  0;
	PyArg_Parse(pRet, "i", &res);

	//pFunc = PyDict_GetItemString(pDict, "redis");
	//pArgs = PyTuple_New(1);
	//PyTuple_SetItem(pArgs, 0, Py_BuildValue("")); //
	//PyObject_CallObject(pFunc, pArgs);
	Py_DECREF(pArgs);
	Py_DECREF(pFunc);
	Py_DECREF(pDict);
	Py_DECREF(pRet);
	Py_DECREF(pModule);


	// �ر�Python
	Py_Finalize();

	return res;
}


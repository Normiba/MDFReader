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
	// 检查初始化是否成功
	if (!Py_IsInitialized())
	{
		return -1;
	}
	// 添加当前路径
	//把输入的字符串作为Python代码直接运行，返回0
	//表示成功，-1表示有错。大多时候错误都是因为字符串
	//中有语法错误。
	PyRun_SimpleString("import sys");
	PyRun_SimpleString("sys.path.append('.\')");
	//PyRun_SimpleString("import subprocess");
	PyObject *pModule, *pDict, *pFunc, *pArgs;
	// 载入名为1的脚本
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
	// 找出函数名为add的函数
	pFunc = PyDict_GetItemString(pDict, "add_func");
	if (!pFunc || !PyCallable_Check(pFunc))
	{
		x.Format(_T("cannot add func"));
		return -3;
	}
	// 参数进栈
	pArgs = PyTuple_New(2);
	//  PyObject* Py_BuildValue(char *format, ...)
	//  把C++的变量转换成一个Python对象。当需要从
	//  C++传递变量到Python时，就会使用这个函数。此函数
	//  有点类似C的printf，但格式不同。常用的格式有
	//  s 表示字符串，
	//  i 表示整型变量，
	//  f 表示浮点数，
	//  O 表示一个Python对象。
	PyTuple_SetItem(pArgs, 0, Py_BuildValue("i", 3));  //"l" (integer) [long int] :将C类型的long转换成Pyhon中的int对象。
	PyTuple_SetItem(pArgs, 1, Py_BuildValue("i", 4));
	// 调用Python函数
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


	// 关闭Python
	Py_Finalize();

	return res;
}


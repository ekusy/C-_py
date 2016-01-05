#include "main.h"


main::main()
{
}


main::~main()
{
}

void main(void){
	Py_Initialize();
	PyObject *pModule, *pTmp;
	PyObject *pName,*module,*pFunc,*module2,*pFunc2;
	char *str;
	PyRun_SimpleString("print('testtest')");
	pName = PyUnicode_FromString("func");
	module = PyImport_Import(pName);
	pFunc = PyObject_GetAttrString(module, "printTest");
	if (PyCallable_Check(pFunc)){
		printf("callback OK\n");
	}
	PyObject_CallObject(pFunc,NULL);
	pFunc2 = PyObject_GetAttrString(module, "writeTime");
	PyObject_CallObject(pFunc2, NULL);

	/*
	pModule = PyImport_ImportModule("func.py");
	pTmp = PyObject_CallMethod(pModule, "writeTime", NULL);
	PyArg_Parse(pTmp, "s", &str);
	printf("%s\n", str);
	*/
	Py_Finalize();
}
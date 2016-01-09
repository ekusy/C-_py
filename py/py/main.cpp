#include "main.h"

int main()
{
	PyObject *pName,*pModule, *pFunc1,*pFunc2,*pFunc3,*pFunc4;
	Py_Initialize();
	pName = PyUnicode_FromString("ser");
	pModule = PyImport_Import(pName);
	pFunc1 = PyObject_GetAttrString(pModule, "serialOpen");
	pFunc2 = PyObject_GetAttrString(pModule, "serialReadLine");
	pFunc3 = PyObject_GetAttrString(pModule, "serialClose");
	pFunc4 = PyObject_GetAttrString(pModule, "testFunc");
	PyObject_CallObject(pFunc4, NULL);
	PyObject *rec;
	rec = PyObject_CallObject(pFunc4, NULL);
	printf("%s\n", PyString_AsString(rec));
	PyObject_CallObject(pFunc1, NULL);
	while (1){
		rec = PyObject_CallObject(pFunc2, NULL);
		std::vector<std::string> str;
		split(rec, ",", str);
		printf("%s\n", PyString_AsString(rec));
		if (GetAsyncKeyState(VK_ESCAPE)){
			//printf("GetKey\n");

			break;
		}
	}
	PyObject_CallObject(pFunc3, NULL);
	Py_Finalize();
	return 0;
}

template <typename List>
void split(const std::string& s, const std::string& delim, List& result)
{
	result.clear();

	using string = std::string;
	string::size_type pos = 0;

	while (pos != string::npos)
	{
		string::size_type p = s.find(delim, pos);

		if (p == string::npos)
		{
			result.push_back(s.substr(pos));
			break;
		}
		else {
			result.push_back(s.substr(pos, p - pos));
		}

		pos = p + delim.size();
	}
}
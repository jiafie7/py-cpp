#include <iostream>
#include <Python.h>

int main()
{
  Py_Initialize();
  if (!Py_IsInitialized())
  {
    std::cout << "python init failed." << '\n';
    return -1;
  }

  PyRun_SimpleString("import sys");
  PyRun_SimpleString("sys.path.append('./../script')");

  PyObject* module = PyImport_ImportModule("add");
  if (module == nullptr)
  {
    std::cout << "module import failed." << '\n';
    return -1;
  }
  
  PyObject* func = PyObject_GetAttrString(module, "add");
  if (func == nullptr)
  {
    std::cout << "funtion not found." << '\n';
    return -1;
  }
  if (!PyCallable_Check(func))
  {
    std::cout << "not a callable object." << '\n';
    return -1;
  }

  PyObject* args = PyTuple_New(2);
  PyTuple_SetItem(args, 0, Py_BuildValue("i", 1));
  PyTuple_SetItem(args, 1, Py_BuildValue("i", 2));

  PyObject* res = PyObject_CallObject(func, args);
  
  int result;
  PyArg_Parse(res, "i", &result);

  std::cout << "result = " << result << '\n';

  Py_Finalize();

  return 0;
}

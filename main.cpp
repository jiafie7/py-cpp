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

  PyObject* test1 = PyImport_ImportModule("test1");
  if (test1 == nullptr)
  {
    std::cout << "module import failed." << '\n';
    return -1;
  }

  // ------------------------
  PyObject* say = PyObject_GetAttrString(test1, "say");
  if (say == nullptr)
  {
    std::cout << "funtion not found." << '\n';
    return -1;
  }
  if (!PyCallable_Check(say))
  {
    std::cout << "not callable obejct." << '\n';
    return -1;
  }

  PyObject_CallObject(say, nullptr);
    
  // -------------------------
  PyObject* add = PyObject_GetAttrString(test1, "add");
  if (add == nullptr)
  {
    std::cout << "funtion not found." << '\n';
    return -1;
  }
  if (!PyCallable_Check(add))
  {
    std::cout << "not a callable object." << '\n';
    return -1;
  }

  PyObject* args = PyTuple_New(2);
  PyTuple_SetItem(args, 0, Py_BuildValue("i", 1));
  PyTuple_SetItem(args, 1, Py_BuildValue("i", 2));

  PyObject* res = PyObject_CallObject(add, args);
  
  int result;
  PyArg_Parse(res, "i", &result);

  std::cout << "result = " << result << '\n';

  // ---------------------------

  Py_Finalize();

  return 0;
}

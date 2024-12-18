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

  PyObject* add_args = PyTuple_New(2);
  PyTuple_SetItem(add_args, 0, Py_BuildValue("i", 1));
  PyTuple_SetItem(add_args, 1, Py_BuildValue("i", 2));

  PyObject* res = PyObject_CallObject(add, add_args);
  
  int result;
  PyArg_Parse(res, "i", &result);

  std::cout << "result = " << result << '\n';

  // ---------------------------
  PyObject* Person = PyObject_GetAttrString(test1, "Person");
  if (Person == nullptr)
  {
    std::cout << "class not found." << '\n';
    return -1;
  }
  
  PyObject* person_args = PyTuple_New(2);
  PyTuple_SetItem(person_args, 0, Py_BuildValue("s", "Michael"));
  PyTuple_SetItem(person_args, 1, Py_BuildValue("i", 21));
  PyObject* person = PyObject_CallObject(Person, person_args);

  PyObject* foo = PyObject_GetAttrString(person, "foo");
  if (foo == nullptr || !PyCallable_Check(foo))
  {
    std::cout << "function not found: foo" << '\n';
    return -1;
  }
  PyObject_CallObject(foo, nullptr);

  Py_Finalize();

  return 0;
}

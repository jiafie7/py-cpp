#include "py/python.h"
        
using namespace melon::py;

Python::Python()
{
  Py_Initialize();
  if (!Py_IsInitialized())
    throw std::logic_error("python init failed.");
}

Python::~Python()
{
  Py_Finalize();
}

void Python::run(const std::string& str)
{
  PyRun_SimpleString(str.c_str());
}


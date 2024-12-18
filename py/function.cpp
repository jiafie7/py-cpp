#include "py/function.h"
using namespace melon::py;

Function::Function(const Module & module, const std::string & name)
{
  m_function = PyObject_GetAttrString(module.m_module, name.c_str());
  if (!m_function || !PyCallable_Check(m_function))
    throw std::logic_error("function not found: " + name);
}

Function::Function(const Object& object, const std::string & name)
{
  m_function = PyObject_GetAttrString(object.m_object, name.c_str());
  if (!m_function || !PyCallable_Check(m_function))
    throw std::logic_error("function not found: " + name);
}

void Function::call()
{
  PyObject_CallObject(m_function, nullptr);
}


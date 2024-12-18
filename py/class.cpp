#include "py/class.h"

using namespace melon::py;

Class::Class(const Module& module, const std::string& name)
{
  m_class = PyObject_GetAttrString(module.m_module, name.c_str());
  if (m_class == nullptr)
    throw std::logic_error("class not found: " + name);
}


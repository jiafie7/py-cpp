#include "py/object.h"

using namespace melon::py;

Object::Object(const Class& cls)
{
  m_object = PyObject_CallObject(cls.m_class, nullptr);
  if (m_object == nullptr)
    throw std::logic_error("create object failed");
}


#pragma once

#include "py/module.h"

namespace melon
{
  namespace py
  {
    class Class
    {
      friend class Object;
    public:
      Class() = default;
      Class(const Module& module, const std::string& name);
      ~Class() = default;

    private:
      PyObject* m_class = nullptr;
    };
  }
}

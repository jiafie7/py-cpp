#pragma once

#include <Python.h>
#include <stdexcept>
#include <string>

namespace melon
{
  namespace py
  {
    class Module
    {
        friend class Function;
        friend class Class;
      public:
        Module() = default;
        Module(const std::string& name);
        ~Module() = default;

        void import(const std::string& name);

      private:
        PyObject* m_module = nullptr;
    };
  }
}

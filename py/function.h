#pragma once

#include <string>
#include "py/module.h"

namespace melon
{
  namespace py
  {
    class Function
    {
      public:
        Function() = default;
        Function(const Module & module, const std::string & name);
        ~Function() = default;

        void call();


      private:
        PyObject * m_function = nullptr;
    };
  }
}

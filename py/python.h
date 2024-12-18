#pragma once

#include <Python.h>
#include <stdexcept>
#include <string>

#include "py/module.h"
#include "py/function.h"

namespace melon
{
  namespace py
  {
    class Python
    {
      public:
        Python();
        ~Python();

        void run(const std::string& str);
    };
  }
}

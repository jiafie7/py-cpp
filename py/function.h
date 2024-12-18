#pragma once

#include <string>
#include "py/module.h"
#include "py/argument.h"
#include "py/object.h"

namespace melon
{
  namespace py
  {
    class Function
    {
      public:
        Function() = default;
        Function(const Module& module, const std::string & name);
        Function(const Object& object, const std::string & name);
        ~Function() = default;

        void call();
      
        template <typename T>
        T call();

        template <typename T, typename... Args>
        T call(Args... args);

      private:
        PyObject * m_function = nullptr;
    };
            
    template <typename T>
    T Function::call()
    {
      PyObject* res = PyObject_CallObject(m_function, nullptr);
      Argument arg;
      return arg.parseResult<T>(res);
    }

    template <typename T, typename... Args>
    T Function::call(Args... args)
    {
      Argument arg;
      arg.bind(args...);
      PyObject* res = PyObject_CallObject(m_function, arg.m_args);
      return arg.parseResult<T>(res);
    }
  }
}

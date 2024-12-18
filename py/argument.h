#pragma once

#include <Python.h>
#include <string>

namespace melon
{
  namespace py
  {
    class Argument
    {
        friend class Function;
      public:
        Argument() = default;
        ~Argument() = default;

        template <typename... Args>
        void bind(Args... args);

        template <typename T>
        T parseResult(PyObject* res);

      private:
        template <typename T, typename... Args>
        void bindInner(T arg, Args... args);

        void bindInner() {}
        
        template <typename T>
        std::string getType();

      private:
        PyObject* m_args = nullptr;
        int m_num = 0;
        int m_pos = 0;
    };

    template <typename... Args>
    void Argument::bind(Args... args)
    {
      m_num = sizeof...(Args);
      m_pos = 0;
      m_args = PyTuple_New(m_num);
      bindInner(args...);
    }

    template <typename T>
    T Argument::parseResult(PyObject* res)
    {
      T result;
      std::string type = getType<T>();
      PyArg_Parse(res, type.c_str(), &result);
      return result;
    }
        
    template <typename T, typename... Args>
    void Argument::bindInner(T arg, Args... args)
    {
      std::string type = getType<T>();
      PyTuple_SetItem(m_args, m_pos ++ , Py_BuildValue(type.c_str(), arg));
      bindInner(args...);
    }

    template <typename T>
    std::string Argument::getType()
    {
      std::string type;
      if (typeid(T) == typeid(bool))
        type = "b";
      else if (typeid(T) == typeid(int))
        type = "i";
      else if (typeid(T) == typeid(unsigned int))
        type = "I";
      else if (typeid(T) == typeid(float))
        type = "f";
      else if (typeid(T) == typeid(double))
        type = "d";
      else if (typeid(T) == typeid(const char*))
        type = "s";

      return type;
    }
  }
}

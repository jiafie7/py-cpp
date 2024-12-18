#include <py/module.h>      

using namespace melon::py;

Module::Module(const std::string& name)
{
  import(name);  
}

void Module::import(const std::string& name)
{
  m_module = PyImport_ImportModule(name.c_str());
  if (m_module == nullptr)
      throw std::logic_error("module not found: " + name);
}

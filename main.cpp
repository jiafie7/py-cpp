#include <iostream>

#include "py/python.h"

using namespace melon::py;

int main()
{
  Python py;
  py.run("import sys");
  py.run("sys.path.append('./../script')");

  try
  {
    Module test1("test1");

    Function say(test1, "say");
    say.call();
  }
  catch (std::exception& e)
  {
    std::cout << e.what() << '\n';
    return 1;
  }

  return 0;
}

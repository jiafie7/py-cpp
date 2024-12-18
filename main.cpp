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

    Function add(test1, "add");
    add.call<int>(1, 2);
  }
  catch (std::exception& e)
  {
    std::cout << e.what() << '\n';
    return 1;
  }

  return 0;
}

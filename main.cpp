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

    Class Person(test1, "Person"); 
    Object person_1(Person, "Michael", 21);
    Function foo_1(person_1, "foo");
    foo_1.call();
    
    Object person_2(Person, "Jerry", 27);
    Function foo_2(person_2, "foo");
    foo_2.call();
  }
  catch (std::exception& e)
  {
    std::cout << e.what() << '\n';
    return 1;
  }

  return 0;
}

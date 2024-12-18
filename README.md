# py-cpp

This py-cpp simplifies the process of executing Python scripts and interacting with Python objects directly within C++ code. It encapsulates the Python C API into intuitive C++ classes, providing a structured way to initialize the Python interpreter, execute Python scripts, import Python modules, call Python functions, manage arguments, and interact with Python classes and objects.

## Features

- **Python Interpreter Management**: Start and stop the Python interpreter with ease.
- **Script Execution**: Execute Python scripts from C++.
- **Module Management**: Import Python modules and access their functions or classes.
- **Function Handling**: Call Python functions with or without arguments, and retrieve results.
- **Argument Management**: Simplify argument creation and result parsing for Python function calls.
- **Class and Object Handling**: Access Python classes, create instances, and interact with Python objects.

## Getting Started

1. Prerequisites

   - C++ 11 or later
   - Python Development Headers: ensure Python is installed, and the python3-dev package is available

2. Clone the Repository

```bash
git clone https://github.com/jiafie7/py-cpp.git
cd py-cpp
```

## Usage

1. Example Code

```c
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
```

2. Build the Project

Modify the Python.h header file and dynamic library file path in CMakelists.txt

```bash
mkdir build
cd build
cmake ..
make
./main
```

3. Output

```bash
hello python!
1 + 2 = 3
my name is Michael, my age is 21.
my name is Jerry, my age is 27.
```

## API Reference

### Python Class

- `Python()`: Constructor that initializes Python.
- `~Python()`: Destructor that finalizes Python.
- `void run(const std::string& str)`: Executes a Python script string.

### Module Class

- `Module(const std::string& name)`: Constructor to import a module by name.
- `void import(const std::string& name)`: Imports a module.

### Function Class

- `Function(const Module& module, const std::string& name)`: Accesses a function from a module.
- `Function(const Object& object, const std::string& name)`: Accesses a method from an object.
- `void call()`: Calls a function without arguments.
- `template <typename T> T call()`: Calls a function and retrieves the result.
- `template <typename T, typename... Args> T call(Args... args)`: Calls a function with arguments and retrieves the result.

### Argument Class

- `template <typename... Args> void bind(Args... args)`: Binds multiple arguments for a function call.
- `template <typename T> T parseResult(PyObject* res)`: Parses and converts Python results into C++ types.

### Class Class

- `Class(const Module& module, const std::string& name)`: Accesses a class from a module.

### Object Class

- `Object(const Class& cls)`: Creates an object from a Python class.
- `template <typename... Args> Object(const Class& cls, Args... args)`: Instantiates an object with arguments.

## License

This project is licensed under the MIT License. See the LICENSE file for details.

## Contributions

Contributions, bug reports, and feature requests are welcome. Feel free to fork the repository, open issues, or submit pull requests.

#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <iostream>
#include <exception>
using namespace std;

class MyException : public exception
{
public:
  const char * what () const throw ()
  {
    return "Out of memeory";
  }
};
#endif // EXCEPTION_H

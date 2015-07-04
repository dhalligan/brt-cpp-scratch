// <Copyright Holder>. Copyright (C) <Copyright Year(s)>. <License>.
#ifndef HEADER_SRC_APP_H_INCLUDED
#define HEADER_SRC_APP_H_INCLUDED

#include <cctype>
#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <memory>
#include <chrono>
#include <thread>
#include <exception>
#include <stdexcept>
#include <stdint.h>

#include "Random.h"
#include "Matrix.h"
#include "io.hpp"

class App
{
 public:
  App(int& argc, char** argv);
  ~App();

  int exec();

 private:
  int& _argc;
  char** _argv;

};

#endif

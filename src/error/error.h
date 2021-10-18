// Copyright (c) 2021 Kandakov Danil (p2034 or the_lll_end)
// https://github.com/p2034



#ifndef ERROR_H
#define ERROR_H

#include <iostream>



namespace error {
  class Error {
  private:
    std::string name_;
  public:
    Error(std::string name);

    std::string line();
  };

  class CanNotOpenFile : public Error {
  public:
    CanNotOpenFile(std::string fileName);
  };

  class FileIsAlreadyOpened : public Error {
  public:
    FileIsAlreadyOpened(std::string fileName);
  };

  class FileIsNotOpened : public Error {
  public:
    FileIsNotOpened();
  };

  class FileIsBroken : public Error {
  public:
    FileIsBroken(std::string fileName);
  };

  class Undefined : public Error {
  public:
    Undefined(std::string line);
  };
}

#endif
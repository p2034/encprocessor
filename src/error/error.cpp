// Copyright (c) 2021 Kandakov Danil (p2034 or the_lll_end)
// https://github.com/p2034



#include "error.h"



namespace error {
  Error::Error(std::string name) : name_(name) {}

  std::string Error::line() {
    return name_;
  }
  
  CanNotOpenFile::CanNotOpenFile(std::string fileName) :
    Error("Can't open file '" + fileName + "'.\n") {}

  FileIsAlreadyOpened::FileIsAlreadyOpened(std::string fileName) :
    Error("File '" + fileName + "' is already opened.\n") {}

  FileIsNotOpened::FileIsNotOpened() :
     Error("File is not opened.\n") {}

  FileIsBroken::FileIsBroken(std::string fileName) :
     Error("File " + fileName + " is broken.\n") {}

  Undefined::Undefined(std::string line) :
    Error(line) {}
}
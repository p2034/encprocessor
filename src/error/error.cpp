// Copyright (c) 2021 Kandakov Danil (p2034 or the_lll_end)
// https://github.com/p2034



#include "error.h"



namespace nc_error {
  nc_Error::nc_Error(std::string name) : name_(name) {}

  std::string nc_Error::line() {
    return name_;
  }
  
  nc_CanNotOpenFile::nc_CanNotOpenFile(std::string fileName) :
    nc_Error("Can't open file '" + fileName + "'.\n") {}

  nc_FileIsAlreadyOpened::nc_FileIsAlreadyOpened(std::string fileName) :
    nc_Error("File '" + fileName + "' is already opened.\n") {}

  nc_FileIsNotOpened::nc_FileIsNotOpened() :
    nc_Error("File is not opened.\n") {}

  nc_FileIsBroken::nc_FileIsBroken(std::string fileName) :
    nc_Error("File " + fileName + " is broken.\n") {}

  nc_Undefined::nc_Undefined(std::string line) :
    nc_Error(line) {}
}
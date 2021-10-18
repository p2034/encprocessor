// Copyright (c) 2021 Kandakov Danil (p2034 or the_lll_end)
// https://github.com/p2034



#ifndef ERROR_H
#define ERROR_H

#include <iostream>



namespace nc_error {
  class nc_Error {
  private:
    std::string name_;
  public:
    nc_Error(std::string name);

    std::string line();
  };

  class nc_CanNotOpenFile : public nc_Error {
  public:
    nc_CanNotOpenFile(std::string fileName);
  };

  class nc_FileIsAlreadyOpened : public nc_Error {
  public:
    nc_FileIsAlreadyOpened(std::string fileName);
  };

  class nc_FileIsNotOpened : public nc_Error {
  public:
    nc_FileIsNotOpened();
  };

  class nc_FileIsBroken : public nc_Error {
  public:
    nc_FileIsBroken(std::string fileName);
  };

  class nc_Undefined : public nc_Error {
  public:
    nc_Undefined(std::string line);
  };
}

#endif
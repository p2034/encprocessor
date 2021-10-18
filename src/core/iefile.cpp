// Copyright (c) 2021 Kandakov Danil (p2034 or the_lll_end)
// https://github.com/p2034



#include <fstream>

#include "iefile.h"



void iefile::open(std::string fileName) {
  std::ifstream file;

  file.open(fileName); {
    if (!file.is_open())
      throw nc_error::nc_CanNotOpenFile(fileName);
    
    int r = this->idata_.open(&file);

    if (r == -1)
      throw nc_error::nc_FileIsAlreadyOpened(fileName);
    else if (r == -2)
      throw nc_error::nc_FileIsBroken(fileName);

  } file.close();
}



int iefile::decrypt(uint8_t* key, uint16_t keySize, uint8_t** data, uint32_t& dataSize) {
  int r = this->idata_.decrypt(key, keySize, data, dataSize);

  if (r == -1)
    throw nc_error::nc_FileIsNotOpened();

  return r;
}



void iefile::close() {
  this->idata_.close();
}



iefile::~iefile() {
  this->close();
}
// Copyright (c) 2021 Kandakov Danil (p2034 or the_lll_end)
// https://github.com/p2034



#include <fstream>

#include "iefile.h"



void iefile::open(std::string fileName) {
  std::ifstream file;

  file.open(fileName); {
    if (!file.is_open())
      throw error::CanNotOpenFile(fileName);
    
    int r = this->idata_.open(&file);

    if (r == -1)
      throw error::FileIsAlreadyOpened(fileName);
    else if (r == -2)
      throw error::FileIsBroken(fileName);

  } file.close();
}



int iefile::decrypt(uint8_t* key, uint16_t keySize, uint8_t** data, uint32_t& dataSize) {
  int r = this->idata_.decrypt(key, keySize, data, dataSize);

  if (r == -1)
    throw error::FileIsNotOpened();

  return r;
}



void iefile::close() {
  this->idata_.close();
}



iefile::~iefile() {
  this->close();
}
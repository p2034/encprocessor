// Copyright (c) 2021 Kandakov Danil (p2034 or the_lll_end)
// https://github.com/p2034



#include <fstream>
#include <stdexcept>

#include "core/iefile.h"



void iefile::open(std::string fileName) {
  std::ifstream file;

  file.open(fileName); {
    if (!file.is_open())
      throw std::invalid_argument("Can not open file '" + fileName + "'");
    
    int r = this->idata_.open(&file);

    if (r == -1)
      throw std::logic_error("File '" + fileName + "' is already opened");
    else if (r == -2)
      throw std::invalid_argument("File '" + fileName + "' is broken");

  } file.close();
}



int iefile::decrypt(uint8_t* key, uint16_t keySize, uint8_t** data, uint32_t& dataSize) {
  int r = this->idata_.decrypt(key, keySize, data, dataSize);

  if (r == -1)
    throw std::logic_error("File is not opened");

  return r;
}



void iefile::close() {
  this->idata_.close();
}



iefile::~iefile() {
  this->close();
}
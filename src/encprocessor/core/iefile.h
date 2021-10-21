// Copyright (c) 2021 Kandakov Danil (p2034 or the_lll_end)
// https://github.com/p2034



#ifndef EC_IEFILE_H
#define EC_IEFILE_H



#include "iedata.h"



/**
 * INPUT ENCRYPTED FILE
 *
 * 1) open() to get decrypted data from file
 * 2) decrypt() to decrypt data
 * 3) you must close() to delete memmory from this object
 **/

class iefile {
private:
  iedata idata_;
public:
  iefile() {}

  void open(std::string fileName);

  /**
   * 1 - all is ok
   * 0 - key is wrong
   **/
  int decrypt(uint8_t* key, uint16_t keySize, uint8_t** data, uint32_t& dataSize);

  void close();
  
  ~iefile();
};



#endif
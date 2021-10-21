// Copyright (c) 2021 Kandakov Danil (p2034 or the_lll_end)
// https://github.com/p2034



#ifndef EC_IEDATA_H
#define EC_IEDATA_H



#include "../crypto/aes.h"
#include "../crypto/crc32.h"

#include "encdata.h"


/**
 * INPUT ENCRYPTED DATA
 *
 * 1) open() to get decrypted data from stream
 * 2) decrypt() to decrypt data
 * 3) you must close() to delete memmory from this object
 **/

class iedata {
private:
  uint8_t* ecdata_ = nullptr;
  uint32_t ecdataSize_ = 0;

  uint8_t* ectail_ = nullptr;

public:
  iedata() {}

  /**
   *  1 - all is ok
   * -1 - data is already opened
   * -2 - data is broken, signature is wrong
   **/
  int open(std::istream* istr);

  /**
   *  1 - all is ok
   *  0 - key is wrong
   * -1 - data is not opened
   **/
  int decrypt(uint8_t* key, uint16_t keySize, uint8_t** data, uint32_t& dataSize);

  void close();
  
  ~iedata();
};



#endif
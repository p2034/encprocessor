// Copyright (c) 2021 Kandakov Danil (p2034 or the_lll_end)
// https://github.com/p2034



#ifndef EC_OEDATA_H
#define EC_OEDATA_H



#include "../error/error.h"
#include "../crypto/aes.h"
#include "../crypto/crc32.h"
 
#include "encdata.h"



/**
 * OUTPUT ENCRYPTED DATA
 *
 * just use save()
 **/

class oedata {
public:
  oedata() {}

  /**
   * save data in stream with encryption AES in stream
   *  1 - all is ok
   * -1 - undefined error, something changed in crypto
   **/
  int save(const uint8_t* key, uint16_t keySize, const uint8_t* data, uint32_t dataSize, std::ostream* ostr);
};



#endif
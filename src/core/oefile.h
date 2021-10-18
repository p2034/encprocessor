// Copyright (c) 2021 Kandakov Danil (p2034 or the_lll_end)
// https://github.com/p2034



#ifndef EC_OEFILE_H
#define EC_OEFILE_H



#include "oedata.h"



/**
 * OUT ENCRYPTED FILE
 *
 * just use save()
 **/

class oefile {
private:
  oedata odata_;
public:
  oefile() {}

  /**
   * create file and save data with encryption AES
   **/
  void save(const uint8_t* key, uint16_t keySize, const uint8_t* data, uint32_t dataSize, std::string fileName);
};



#endif
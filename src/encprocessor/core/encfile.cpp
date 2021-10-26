// Copyright (c) 2021 Kandakov Danil (p2034 or the_lll_end)
// https://github.com/p2034



/**
 * @file
 * @brief encfile class implementation
 * 
 * Here is implementation for reading data from file (encfile::decrypt()) and writing in it (encfile::encrypt()).
 */



#include <fstream>
#include <stdexcept>

#include "core/encdata.h"
#include "core/encfile.h"



uint32_t encfile::decrypt(std::string fileName, const uint8_t* key, uint16_t keySize, uint8_t** data) {
  std::ifstream file; ///< std::istream for encdata::decrypt()
  encdata datastream; ///< object for decryption

  uint32_t dataSize; ///< decrypted data size

  // get decrypted data from file
  file.open(fileName); {
    if (!file.is_open())
      throw std::invalid_argument("Can not open file '" + fileName + "'");

    dataSize = datastream.decrypt(&file, key, keySize, data);
  } file.close();

  return dataSize; 
}



void encfile::encrypt(std::string fileName, const uint8_t* key, uint16_t keySize,
                                            const uint8_t* data, uint32_t dataSize) {
  std::ofstream file; ///< std::ostream for decdata::decrypt()
  encdata datastream; ///< object for encryption

  // write data in file
  file.open(fileName); {
    if (!file.is_open())
      throw std::invalid_argument("Can not open file '" + fileName + "'");

    datastream.encrypt(&file, key, keySize, data, dataSize);
  } file.close();
}
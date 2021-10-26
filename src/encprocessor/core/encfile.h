// Copyright (c) 2021 Kandakov Danil (p2034 or the_lll_end)
// https://github.com/p2034



/**
 * @file
 * @brief encfile class declaration
 * 
 * Here is implementation for reading data from file (encfile::decrypt()) and writing in it (encfile::encrypt()).
 */



#ifndef ENC_ENCFILE_H
#define ENC_ENCFILE_H



/**
 * @brief encrypted data (std::iostream) processor
 *
 **/
class encfile {
public:
  uint32_t decrypt(std::string fileName, const uint8_t* key, uint16_t keySize, uint8_t** data);

  void encrypt(std::string fileName, const uint8_t* key, uint16_t keySize,
                                     const uint8_t* data, uint32_t dataSize);
};



#endif
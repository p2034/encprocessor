// Copyright (c) 2021 Kandakov Danil (p2034 or the_lll_end)
// https://github.com/p2034



/**
 * @file
 * @brief class encdata declaration
 */



#ifndef ENC_ENCDATA_H
#define ENC_ENCDATA_H



/**
 * @brief encrypted data (std::iostream) processor
 *
 * 
 */
class encdata {
public:
  uint32_t decrypt(std::istream* istr, const uint8_t* key, uint16_t keySize, uint8_t** data);

  void encrypt(std::ostream* ostr, const uint8_t* key, uint16_t keySize,
                                   const uint8_t* data, uint32_t dataSize);
};



#endif
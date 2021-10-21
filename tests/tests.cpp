// Copyright (c) 2021 Kandakov Danil (p2034 or the_lll_end)
// https://github.com/p2034



#include <string>
#include <sstream>
#include <stdlib.h> /* srand, rand */
#include <time.h> /* time */
#include <stdexcept>

#include "core/oedata.h"
#include "core/iedata.h"

#include "tests.h"



// with check
void test_type1(uint8_t* key, uint32_t keySize, uint8_t* data, uint32_t dataSize, std::string check) {
  // encryption
  std::stringstream sstr;
  oedata data_o;
  data_o.save(key, keySize, data, dataSize, &sstr);

  if (sstr.str() != check)
    throw std::logic_error("Wrong data after encryption");

  // decryption
  iedata data_i;
  uint8_t* data_;

  data_i.open(&sstr); {
    int a = data_i.decrypt(key, keySize, &data_, dataSize);

    if (a == 0)
      throw std::logic_error("Wrong key");
    else
      if (sstr.str() != std::string(reinterpret_cast<char*>(data), dataSize))
        throw std::logic_error("Wrong data after decryption");
  } data_i.close();
}



void test_type2(uint8_t* key, uint32_t keySize, uint8_t* data, uint32_t dataSize) {
  // encryption
  std::stringstream sstr;
  oedata data_o;
  data_o.save(key, keySize, data, dataSize, &sstr);

  // decryption
  iedata data_i;
  uint8_t* data_;
  uint32_t dataSize_;

  data_i.open(&sstr); {
    int a = data_i.decrypt(key, keySize, &data_, dataSize_);

    if (a == 0)
      throw std::logic_error("Wrong key");
    else
      if (std::string(reinterpret_cast<char*>(data_), dataSize_) != std::string(reinterpret_cast<char*>(data), dataSize))
        throw std::logic_error("Wrong data after decryption");
  } data_i.close();
}



void globalTests() {
  uint8_t* data;
  uint32_t dataSize;
  uint8_t* key;
  uint32_t keySize;

  srand(time(NULL));

  for (int j = 1; j < 1000; j++) {
    keySize = 32;
    key = (uint8_t*) new uint8_t[keySize];
    for (int i = 0; i < keySize; i++)
      key[i] = rand() % 128;

    dataSize = j;
    data = (uint8_t*) new uint8_t[dataSize];
    for (int i = 0; i < dataSize; i++)
      data[i] = rand() % 128;

    test_type2(key, keySize, data, dataSize);

    delete[] key;
    delete[] data;
  }
}
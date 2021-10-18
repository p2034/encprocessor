// Copyright (c) 2021 Kandakov Danil (p2034 or the_lll_end)
// https://github.com/p2034



#include "iedata.h"



// save encrypted data from stream to decrypt it in next command (function decrypt())
int iedata::open(std::istream* istr) {
  if (ecdata_ != nullptr || ectail_ != nullptr)
    // data already opened
    return -1;
  
  // get HEADER
  uint8_t* header = (uint8_t *) new uint8_t[EC_SIGNATURE_SIZE + EC_DATALENGTH_SIZE];
  istr->read(reinterpret_cast<char*>(header), EC_SIGNATURE_SIZE + EC_DATALENGTH_SIZE);
  // check signature
  for (int i = 0; i < EC_SIGNATURE_SIZE; i++)
    if (header[i] != std::string(EC_SIGNATURE)[i])
      // signature is wrong
      return -2;
  // get length of data
  memcpy(&ecdataSize_, &(header[EC_SIGNATURE_SIZE]), EC_DATALENGTH_SIZE);
  delete[] header;
  
  // get ENCRYPTED DATA
  ecdata_ = (uint8_t*) new uint8_t[ecdataSize_];
  istr->read(reinterpret_cast<char*>(ecdata_), ecdataSize_);
  
  // get TAIL
  ectail_ = (uint8_t*) new uint8_t[EC_ENCRYPTED_TAIL_SIZE];
  istr->read(reinterpret_cast<char*>(ectail_), EC_ENCRYPTED_TAIL_SIZE);

  return 1;
}



// key must have 256 bits (32 bytes/symbols) (size in bytes), or 128/192 bits
// data - free pointer for new data, dataSize will set with info from encrypted file
int iedata::decrypt(uint8_t* key, uint16_t keySize, uint8_t** data, uint32_t& dataSize) {
  AES aes(keySize * 8);

  if (ecdata_ == nullptr || ectail_ == nullptr)
    // we did not open data
    return -1;

  // decrypt ENCRYPTED DATA
  uint8_t* dcdata = aes.DecryptECB(ecdata_, ecdataSize_, key);
  // decrypt TAIL
  uint8_t* dctail = aes.DecryptECB(ectail_, EC_ENCRYPTED_TAIL_SIZE, key);
  
  // get hash from file
  uint32_t hashFromFile;
  memcpy(&hashFromFile, dctail, EC_HASH_SIZE);
  // get decrypted data length
  uint32_t dcdataSize;
  memcpy(&dcdataSize, &(dctail[EC_HASH_SIZE]), EC_DATALENGTH_SIZE);

  // get hash from data
  uint32_t hashFromData = crcdetail::compute(reinterpret_cast<const char*>(dcdata), dcdataSize);

  // check hashes
  if (hashFromData != hashFromFile)
    // if key is wrong
    return 0;

  *data = dcdata;
  dataSize = dcdataSize;

  return 1;
}



// clear memory
void iedata::close() {
  if (ecdata_ != nullptr)
    delete[] ecdata_;
  ecdata_ = nullptr;

  if (ectail_ != nullptr)
    delete[] ectail_;
  ectail_ = nullptr;
}



iedata::~iedata() {
  this->close();
}
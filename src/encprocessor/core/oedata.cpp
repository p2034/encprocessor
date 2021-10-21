// Copyright (c) 2021 Kandakov Danil (p2034 or the_lll_end)
// https://github.com/p2034



#include "core/oedata.h"



// key must have 256 bits (32 bytes/symbols) (size in bytes), or 128/192 bits
int oedata::save(const uint8_t* key, uint16_t keySize, const uint8_t* data, uint32_t dataSize,
                  std::ostream* ostr) {
  AES aes(keySize * 8);

  // create TAIL
  // get hash
  uint32_t hash = crcdetail::compute(reinterpret_cast<const char*>(data), dataSize);
  // set hash and data length in one array
  uint8_t* tail = (uint8_t*) new uint8_t[EC_HASH_SIZE + EC_DATALENGTH_SIZE];
  memcpy(tail, &hash, EC_HASH_SIZE);
  memcpy(&(tail[EC_HASH_SIZE]), &dataSize, EC_DATALENGTH_SIZE);
  // encrypt hash and length with AES 256
  uint32_t ectailLength = 0;
  uint8_t* ectail = aes.EncryptECB(reinterpret_cast<uint8_t*>(tail), EC_HASH_SIZE + EC_DATALENGTH_SIZE,
                                   const_cast<uint8_t*>(key), ectailLength);

  // check changed something in encryption or not
  if (ectailLength != EC_ENCRYPTED_TAIL_SIZE)
    // undefined error, something changed in crypto
    return -1;

  // get ENCRYPTED DATA
  uint32_t ecdataSize = 0;
  uint8_t* ecdata = aes.EncryptECB(const_cast<uint8_t*>(data), dataSize, const_cast<uint8_t*>(key),
                                   ecdataSize);

  // create HEADER
  uint8_t* header = (uint8_t *) new uint8_t[EC_SIGNATURE_SIZE + EC_DATALENGTH_SIZE];
  // set signature in header
  for (int i = 0; i < EC_SIGNATURE_SIZE; i++)
    header[i] = std::string(EC_SIGNATURE)[i];
  // set encrypted data size in header
  memcpy(&(header[EC_SIGNATURE_SIZE]), &ecdataSize, EC_DATALENGTH_SIZE);

  // write data
  ostr->write(reinterpret_cast<char*>(header), EC_SIGNATURE_SIZE + EC_DATALENGTH_SIZE);
  ostr->write(reinterpret_cast<char*>(ecdata), ecdataSize);
  ostr->write(reinterpret_cast<char*>(ectail), EC_ENCRYPTED_TAIL_SIZE);
  
  delete[] tail;
  delete[] ectail;
  delete[] ecdata;
  delete[] header;

  return 1;
}
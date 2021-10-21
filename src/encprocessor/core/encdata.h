// Copyright (c) 2021 Kandakov Danil (p2034 or the_lll_end)
// https://github.com/p2034


#ifndef EC_ENCDATA_H
#define EC_ENCDATA_H



#define EC_SIGNATURE_SIZE 8
#define EC_SIGNATURE "NCRYPTED"
#define EC_DATALENGTH_SIZE 4
#define EC_HASH_SIZE 4
#define EC_ENCRYPTED_TAIL_SIZE 16



/**
 * Data Format:
 *           < HEADER >                   < ENCRYPTED DATA >                  < TAIL >
 *           signature +                    encrypted data            hash of unencrypted data +
 *       encrypted data length                                         unencrypted data length
 *          not encrypted                        AES                            AES
 * 
 *   signature  | enc.d. length  |         encrypted data          |    hash    | unenc.d. length
 *    8 bytes   |  4 bytes       |  "encrypted data length" bytes  |  4 bytes   |  4 bytes
 *            12 bytes                                               16 bytes (after encryption)
 *
 *                                                                     crc32
 **/
 


#endif
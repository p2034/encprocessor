<h1>ENCPROCESSOR</h1>

Encryption processor - two classes iedata and oedata for encrypt and decrypt data from stream using AES and CRC32 as hash function.

<h2>Data Format:</h2>

```
          < HEADER >                   < ENCRYPTED DATA >                  < TAIL >
          signature +                    encrypted data            hash of unencrypted data +
      encrypted data length                                         unencrypted data length
        not encrypted                        AES                            AES

  signature  | enc.d. length  |         encrypted data          |    hash    | unenc.d. length
   8 bytes   |  4 bytes       |  "encrypted data length" bytes  |  4 bytes   |  4 bytes
          12 bytes                                                16 bytes (after encryption)

                                                                    crc32
```

<h2>Usage:</h2>

<p>You can find simple tests in tests/</p>
<p>If you want to use it in your project: Copy files (/src) in your src folder and link them in CMakeLists.txt</p>

<h3>Examples:</h3>
<p>All tests and ewxamples are in tests/encprocessor_encprocessors.cpp file.</p>

<h3>Stream:</h3>

<p>You can encrypt data with class oedata and function save()</p>
<p>To decryption you must use class iedata and functions open(), decrypt(), close() consistently</p>

<h3>Files:</h3>

<p>You can encrypt file with class oefile and function save()</p>
<p>To decryption you must use class iefile and functions open(), decrypt(), close() consistently</p>

<h2>Compile:</h2>

1. Go to tmp
2. Run:

```bash
cmake ../
make
```

3. And now you have test.out file in tmp

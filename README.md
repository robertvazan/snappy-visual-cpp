# Snappy for Visual C++ #

This is a Windows port of [Snappy compression algorithm](https://google.github.io/snappy/).

* [Website](https://snappy.machinezoo.com/)
* [Tutorial for C++](https://snappy.machinezoo.com/#cpp)
* [Source code (main repository)](https://bitbucket.org/robertvazan/snappy-visual-cpp/src/default/)
* [BSD license](https://opensource.org/licenses/BSD-3-Clause)
* [Upstream Snappy](https://google.github.io/snappy/)

***

```cpp
char compressed[1000];
size_t compressedLength = 1000;
snappy_status status = snappy_compress(
    "Hello World!", 12, compressed, &compressedLength);
char uncompressed[1000];
size_t uncompressedLength = 1000;
snappy_status status = snappy_uncompress(
    compressed, compressedLength, uncompressed, &uncompressedLength);
```


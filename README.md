# Snappy for Visual C++ #

This is a Windows port of [Snappy compression algorithm](https://google.github.io/snappy/).

* Documentation: [Home](https://snappy.machinezoo.com/), [Tutorial for C++](https://snappy.machinezoo.com/#cpp)
* Download: see [Tutorial for C++](https://snappy.machinezoo.com/#cpp)
* Sources: [GitHub](https://github.com/robertvazan/snappy-visual-cpp), [Bitbucket](https://bitbucket.org/robertvazan/snappy-visual-cpp)
* Issues: [GitHub](https://github.com/robertvazan/snappy-visual-cpp/issues), [Bitbucket](https://bitbucket.org/robertvazan/snappy-visual-cpp/issues)
* License: [BSD license](https://opensource.org/licenses/BSD-3-Clause)
* See also [upstream Snappy](https://google.github.io/snappy/)

***

```cpp
char compressed[1000];
size_t length = 1000;
snappy_status status = snappy_compress(
    "Hello World!", 12, compressed, &length);
```


Quoting from [upstream Snappy](http://code.google.com/p/snappy/) homepage:

> Snappy is a compression/decompression library. It does not aim for maximum compression, or compatibility with any other compression library;
> instead, it aims for very high speeds and reasonable compression. For instance, compared to the fastest mode of zlib,
> Snappy is an order of magnitude faster for most inputs, but the resulting compressed files are anywhere from 20% to 100% bigger.
> On a single core of a Core i7 processor in 64-bit mode, Snappy compresses at about 250 MB/sec or more and decompresses at about 500 MB/sec or more.

This is a Windows fork of Snappy. It builds out of the box in Visual C++ 2013.
It produces nice clean DLLs with both 32-bit and 64-bit versions available.
The DLLs have no dependencies since they are linked statically to C++ runtime.
You can download the DLLs, LIB, and header files here:

[snappy-dlls-1.1.1-rev2.zip](https://bitbucket.org/robertvazan/snappy-visual-cpp/downloads/snappy-dlls-1.1.1-rev2.zip)

Tests have been ported as well and they show that this Windows port is correct and fast.
Results below have been measured on Core i7 3.4GHz. The BM_ZFlat results are important.

## 32-bit test results

	C:\...\snappy-visual-cpp>Release\runtests.exe
	Running microbenchmarks.
	Benchmark            Time(ns)    CPU(ns) Iterations
	---------------------------------------------------
	BM_UFlat/0              84677      81179       2306 1.2GB/s  html
	BM_UFlat/1             857468     862982        235 775.9MB/s  urls
	BM_UFlat/2               5631       5391      34722 21.9GB/s  jpg
	BM_UFlat/3                132        128    1333333 1.4GB/s  jpg_200
	BM_UFlat/4              28827      28372       6598 3.1GB/s  pdf
	BM_UFlat/5             347182     327847        571 1.2GB/s  html4
	BM_UFlat/6              30001      29104       6432 806.2MB/s  cp
	BM_UFlat/7              13268      13216      14164 804.5MB/s  c
	BM_UFlat/8               3779       3689      46511 961.8MB/s  lsp
	BM_UFlat/9            1263449    1283550        158 765.1MB/s  xls
	BM_UFlat/10               301        288     540540 660.9MB/s  xls_200
	BM_UFlat/11            281462     267812        699 541.6MB/s  txt1
	BM_UFlat/12            244078     250062        811 477.4MB/s  txt2
	BM_UFlat/13            750725     751114        270 541.8MB/s  txt3
	BM_UFlat/14           1008432    1019100        199 450.9MB/s  txt4
	BM_UFlat/15            407737     381264        491 1.3GB/s  bin
	BM_UFlat/16               268        271     689655 702.7MB/s  bin_200
	BM_UFlat/17             50483      52160       3888 699.2MB/s  sum
	BM_UFlat/18              4920       4736      39525 851.1MB/s  man
	BM_UFlat/19             82241      85823       2363 1.3GB/s  pb
	BM_UFlat/20            311606     294804        635 596.3MB/s  gaviota
	BM_UValidate/0          39427      37941       4934 2.5GB/s  html
	BM_UValidate/1         449156     418794        447 1.6GB/s  urls
	BM_UValidate/2            192        196     952380 601.5GB/s  jpg
	BM_UValidate/3             74         67     689655 2.7GB/s  jpg_200
	BM_UValidate/4          12977      12166      14104 7.2GB/s  pdf
	BM_ZFlat/0             193887     197854       1025 493.6MB/s  html (22.31 %)
	BM_ZFlat/1            2280530    2340020        100 286.1MB/s  urls (47.77 %)
	BM_ZFlat/2              36831      31354       5473 3.8GB/s  jpg (99.87 %)
	BM_ZFlat/3                564        582     240963 327.3MB/s  jpg_200 (79.00 %)
	BM_ZFlat/4              94952      90304       2073 996.2MB/s  pdf (82.07 %)
	BM_ZFlat/5             766381     774049        262 504.7MB/s  html4 (22.51 %)
	BM_ZFlat/6              84180      87489       2318 268.2MB/s  cp (48.12 %)
	BM_ZFlat/7              31136      32850       4274 323.7MB/s  c (42.40 %)
	BM_ZFlat/8               9426       9229      20283 384.5MB/s  lsp (48.37 %)
	BM_ZFlat/9            2283280    2184010        100 449.7MB/s  xls (41.23 %)
	BM_ZFlat/10               704        692     270270 275.4MB/s  xls_200 (78.00 %)
	BM_ZFlat/11            685517     641099        292 226.2MB/s  txt1 (57.87 %)
	BM_ZFlat/12            602479     607188        334 196.6MB/s  txt2 (61.93 %)
	BM_ZFlat/13           1850046    1877787        108 216.7MB/s  txt3 (54.92 %)
	BM_ZFlat/14           2417840    2340020        100 196.4MB/s  txt4 (66.22 %)
	BM_ZFlat/15            669451     682831        297 716.8MB/s  bin (18.11 %)
	BM_ZFlat/16               202        202     769230 940.5MB/s  bin_200 (7.50 %)
	BM_ZFlat/17            137649     130091       1439 280.3MB/s  sum (48.96 %)
	BM_ZFlat/18             12818      12345      15163 326.5MB/s  man (59.36 %)
	BM_ZFlat/19            160654     163813       1238 690.4MB/s  pb (19.64 %)
	BM_ZFlat/20            570796     566483        358 310.3MB/s  gaviota (37.72 %)
	
	
	Running correctness tests.
	All tests passed.

## 64-bit test results

	C:\...\snappy-visual-cpp>x64\Release\runtests.exe
	Running microbenchmarks.
	Benchmark            Time(ns)    CPU(ns) Iterations
	---------------------------------------------------
	BM_UFlat/0              59829      59420       3413 1.6GB/s  html
	BM_UFlat/1             626984     620186        327 1.1GB/s  urls
	BM_UFlat/2               7110       7199      28169 16.4GB/s  jpg
	BM_UFlat/3                 85         85    1818181 2.2GB/s  jpg_200
	BM_UFlat/4              19910      19544       9578 4.5GB/s  pdf
	BM_UFlat/5             251147     255416        794 1.5GB/s  html4
	BM_UFlat/6              20645      21000       9657 1.1GB/s  cp
	BM_UFlat/7               9913       9129      18796 1.1GB/s  c
	BM_UFlat/8               2636       2605      77821 1.3GB/s  lsp
	BM_UFlat/9             951347     979714        207 1002.4MB/s  xls
	BM_UFlat/10               217        224     833333 849.1MB/s  xls_200
	BM_UFlat/11            206930     208001        975 697.3MB/s  txt1
	BM_UFlat/12            180908     179788       1128 664.0MB/s  txt2
	BM_UFlat/13            556884     569665        356 714.4MB/s  txt3
	BM_UFlat/14            749063     756720        268 607.3MB/s  txt4
	BM_UFlat/15            303989     312964        648 1.5GB/s  bin
	BM_UFlat/16               210        215     869565 886.0MB/s  bin_200
	BM_UFlat/17             36107      36027       5629 1012.2MB/s  sum
	BM_UFlat/18              3492       3517      48780 1.1GB/s  man
	BM_UFlat/19             57090      57695       3515 1.9GB/s  pb
	BM_UFlat/20            216315     218300        929 805.2MB/s  gaviota
	BM_UValidate/0          35957      36266       5592 2.6GB/s  html
	BM_UValidate/1         416740     394938        474 1.7GB/s  urls
	BM_UValidate/2            160        159    1176470 743.1GB/s  jpg
	BM_UValidate/3             51         51    3333333 3.6GB/s  jpg_200
	BM_UValidate/4          11885      11671      17376 7.5GB/s  pdf
	BM_ZFlat/0             156085     157088       1291 621.7MB/s  html (22.31 %)
	BM_ZFlat/1            1866207    1913216        106 350.0MB/s  urls (47.77 %)
	BM_ZFlat/2              33859      28154       6095 4.2GB/s  jpg (99.87 %)
	BM_ZFlat/3                469        470     298507 405.5MB/s  jpg_200 (79.00 %)
	BM_ZFlat/4              62515      62629       2989 1.4GB/s  pdf (82.07 %)
	BM_ZFlat/5             621187     624003        325 626.0MB/s  html4 (22.51 %)
	BM_ZFlat/6              65297      63782       2935 367.9MB/s  cp (48.12 %)
	BM_ZFlat/7              22803      22296       8396 476.9MB/s  c (42.40 %)
	BM_ZFlat/8               6772       6524      28694 543.9MB/s  lsp (48.37 %)
	BM_ZFlat/9            1810918    1843645        110 532.7MB/s  xls (41.23 %)
	BM_ZFlat/10               593        624     200000 305.7MB/s  xls_200 (78.00 %)
	BM_ZFlat/11            580576     592985        342 244.6MB/s  txt1 (57.87 %)
	BM_ZFlat/12            509501     516033        393 231.3MB/s  txt2 (61.93 %)
	BM_ZFlat/13           1538765    1584382        128 256.9MB/s  txt3 (54.92 %)
	BM_ZFlat/14           2016670    2028010        100 226.6MB/s  txt4 (66.22 %)
	BM_ZFlat/15            560387     564905        359 866.4MB/s  bin (18.11 %)
	BM_ZFlat/16               216        205     833333 926.3MB/s  bin_200 (7.50 %)
	BM_ZFlat/17            112226     113997       1779 319.9MB/s  sum (48.96 %)
	BM_ZFlat/18              9380       9472      19762 425.6MB/s  man (59.36 %)
	BM_ZFlat/19            133696     136382       1487 829.2MB/s  pb (19.64 %)
	BM_ZFlat/20            472681     485169        418 362.3MB/s  gaviota (37.72 %)
	
	
	Running correctness tests.
	Crazy decompression lengths not checked on 64-bit build
	All tests passed.

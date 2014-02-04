Quoting from [upstream Snappy](http://code.google.com/p/snappy/) homepage:

> Snappy is a compression/decompression library. It does not aim for maximum compression, or compatibility with any other compression library;
> instead, it aims for very high speeds and reasonable compression. For instance, compared to the fastest mode of zlib,
> Snappy is an order of magnitude faster for most inputs, but the resulting compressed files are anywhere from 20% to 100% bigger.
> On a single core of a Core i7 processor in 64-bit mode, Snappy compresses at about 250 MB/sec or more and decompresses at about 500 MB/sec or more.

This is a Windows fork of Snappy. It builds out of the box in Visual C++ 2013.
It produces nice clean DLLs with both 32-bit and 64-bit versions available.
The DLLs have no dependencies since they are linked statically to C++ runtime.
You can download the DLLs, LIB, and header files here:

[snappy-dlls-1.1.1-rev1.zip](https://bitbucket.org/robertvazan/snappy-visual-cpp/downloads/snappy-dlls-1.1.1-rev1.zip)

Tests have been ported as well and they show that this Windows port is correct and fast.
Results below have been measured on Core i7 3.4GHz. The BM_ZFlat results are important.

## 32-bit test results

	C:\...\snappy-visual-cpp>Release\runtests.exe
	Running microbenchmarks.
	Benchmark            Time(ns)    CPU(ns) Iterations
	---------------------------------------------------
	BM_UFlat/0              83852      79121       1183 1.2GB/s  html
	BM_UFlat/1             821183     780004        240 858.4MB/s  urls
	BM_UFlat/2               5447       5681      32948 20.8GB/s  jpg
	BM_UFlat/3                130        124    1250000 1.5GB/s  jpg_200
	BM_UFlat/4              28330      27388       6835 3.2GB/s  pdf
	BM_UFlat/5             335499     343148        591 1.1GB/s  html4
	BM_UFlat/6              29050      29681       6307 790.5MB/s  cp
	BM_UFlat/7              12984      12524      14947 849.0MB/s  c
	BM_UFlat/8               3795       3865      48426 918.0MB/s  lsp
	BM_UFlat/9            1236320    1275477        159 769.9MB/s  xls
	BM_UFlat/10               295        291     588235 653.8MB/s  xls_200
	BM_UFlat/11            276084     276295        734 525.0MB/s  txt1
	BM_UFlat/12            240347     242295        837 492.7MB/s  txt2
	BM_UFlat/13            726970     695914        269 584.8MB/s  txt3
	BM_UFlat/14            985079     931348        201 493.4MB/s  txt4
	BM_UFlat/15            400787     379718        493 1.3GB/s  bin
	BM_UFlat/16               262        265     645161 717.1MB/s  bin_200
	BM_UFlat/17             50340      48185       3885 756.8MB/s  sum
	BM_UFlat/18              4842       4736      39525 851.1MB/s  man
	BM_UFlat/19             79934      76879       2435 1.4GB/s  pb
	BM_UFlat/20            304122     307740        659 571.2MB/s  gaviota
	BM_UValidate/0          38201      37320       5016 2.6GB/s  html
	BM_UValidate/1         430923     454710        446 1.4GB/s  urls
	BM_UValidate/2            190        188     909090 626.4GB/s  jpg
	BM_UValidate/3             71         70    2222222 2.7GB/s  jpg_200
	BM_UValidate/4          12698      12205      15337 7.2GB/s  pdf
	BM_ZFlat/0             230173     221539        845 440.8MB/s  html (22.31 %)
	BM_ZFlat/1            2597270    2652020        100 252.5MB/s  urls (47.77 %)
	BM_ZFlat/2              36323      29579       5274 4.0GB/s  jpg (99.87 %)
	BM_ZFlat/3                539        561     250000 339.6MB/s  jpg_200 (79.00 %)
	BM_ZFlat/4              98964      93059       1844 966.7MB/s  pdf (82.07 %)
	BM_ZFlat/5             941366     952117        213 410.3MB/s  html4 (22.51 %)
	BM_ZFlat/6              93079      94282       2151 248.9MB/s  cp (48.12 %)
	BM_ZFlat/7              33086      33766       4158 314.9MB/s  c (42.40 %)
	BM_ZFlat/8               7903       8322      20618 426.4MB/s  lsp (48.37 %)
	BM_ZFlat/9            2172920    1872010        100 524.6MB/s  xls (41.23 %)
	BM_ZFlat/10               657        652     263157 292.5MB/s  xls_200 (78.00 %)
	BM_ZFlat/11            868777     866670        234 167.4MB/s  txt1 (57.87 %)
	BM_ZFlat/12            745652     765286        265 156.0MB/s  txt2 (61.93 %)
	BM_ZFlat/13           2275070    2340020        100 173.9MB/s  txt3 (54.92 %)
	BM_ZFlat/14           2943800    2808020        100 163.7MB/s  txt4 (66.22 %)
	BM_ZFlat/15            806244     811204        250 603.4MB/s  bin (18.11 %)
	BM_ZFlat/16               194        197     869565 966.5MB/s  bin_200 (7.50 %)
	BM_ZFlat/17            158271     135225       1269 269.7MB/s  sum (48.96 %)
	BM_ZFlat/18             11093      11274      15220 357.5MB/s  man (59.36 %)
	BM_ZFlat/19            185579     178286       1050 634.3MB/s  pb (19.64 %)
	BM_ZFlat/20            657443     671526        302 261.8MB/s  gaviota (37.72 %)
	
	
	Running correctness tests.
	All tests passed.

## 64-bit test results

	C:\...\snappy-visual-cpp>x64\Release\runtests.exe
	Running microbenchmarks.
	Benchmark            Time(ns)    CPU(ns) Iterations
	---------------------------------------------------
	BM_UFlat/0              60443      58391       1603 1.6GB/s  html
	BM_UFlat/1             616623     631778        321 1.0GB/s  urls
	BM_UFlat/2               7012       7006      28943 16.9GB/s  jpg
	BM_UFlat/3                 83         84    2222222 2.2GB/s  jpg_200
	BM_UFlat/4              20062      20706       9794 4.2GB/s  pdf
	BM_UFlat/5             245737     248835        815 1.5GB/s  html4
	BM_UFlat/6              19815      19684       9510 1.2GB/s  cp
	BM_UFlat/7               9255       9501      21344 1.1GB/s  c
	BM_UFlat/8               2510       2514      80645 1.4GB/s  lsp
	BM_UFlat/9             922018     934566        217 1.0GB/s  xls
	BM_UFlat/10               212        214     800000 889.2MB/s  xls_200
	BM_UFlat/11            204867     208214        974 696.6MB/s  txt1
	BM_UFlat/12            177047     169873       1102 702.8MB/s  txt2
	BM_UFlat/13            543329     552591        367 736.5MB/s  txt3
	BM_UFlat/14            732869     753907        269 609.5MB/s  txt4
	BM_UFlat/15            303812     309147        656 1.5GB/s  bin
	BM_UFlat/16               209        205     909090 926.3MB/s  bin_200
	BM_UFlat/17             36239      35076       5337 1.0GB/s  sum
	BM_UFlat/18              3408       3276      57142 1.2GB/s  man
	BM_UFlat/19             56846      56301       3325 2.0GB/s  pb
	BM_UFlat/20            216671     221157        917 794.8MB/s  gaviota
	BM_UValidate/0          35370      37095       5467 2.6GB/s  html
	BM_UValidate/1         416705     408872        496 1.6GB/s  urls
	BM_UValidate/2            157        154    1111111 765.6GB/s  jpg
	BM_UValidate/3             52         51    3333333 3.6GB/s  jpg_200
	BM_UValidate/4          11644      11387      17809 7.7GB/s  pdf
	BM_ZFlat/0             186174     180347       1038 541.5MB/s  html (22.31 %)
	BM_ZFlat/1            2161910    2184010        100 306.6MB/s  urls (47.77 %)
	BM_ZFlat/2              33238      23652       5936 5.0GB/s  jpg (99.87 %)
	BM_ZFlat/3                526        538     289855 354.4MB/s  jpg_200 (79.00 %)
	BM_ZFlat/4              67249      66595       2811 1.3GB/s  pdf (82.07 %)
	BM_ZFlat/5             775098     795298        255 491.2MB/s  html4 (22.51 %)
	BM_ZFlat/6              76058      78727       2576 298.0MB/s  cp (48.12 %)
	BM_ZFlat/7              22641      21450       8000 495.7MB/s  c (42.40 %)
	BM_ZFlat/8               5898       5851      29325 606.4MB/s  lsp (48.37 %)
	BM_ZFlat/9            1818192    1860559        109 527.8MB/s  xls (41.23 %)
	BM_ZFlat/10               529        514     333333 370.5MB/s  xls_200 (78.00 %)
	BM_ZFlat/11            715182     726885        279 199.5MB/s  txt1 (57.87 %)
	BM_ZFlat/12            636532     654196        310 182.5MB/s  txt2 (61.93 %)
	BM_ZFlat/13           1909115    1950009        104 208.7MB/s  txt3 (54.92 %)
	BM_ZFlat/14           2499900    2496020        100 184.1MB/s  txt4 (66.22 %)
	BM_ZFlat/15            687826     650003        288 753.0MB/s  bin (18.11 %)
	BM_ZFlat/16               223        215     869565 886.0MB/s  bin_200 (7.50 %)
	BM_ZFlat/17            133267     130272       1437 279.9MB/s  sum (48.96 %)
	BM_ZFlat/18              8206       8330      22471 483.9MB/s  man (59.36 %)
	BM_ZFlat/19            156375     152568       1227 741.3MB/s  pb (19.64 %)
	BM_ZFlat/20            575264     562165        333 312.7MB/s  gaviota (37.72 %)
	
	
	Running correctness tests.
	Crazy decompression lengths not checked on 64-bit build
	All tests passed.

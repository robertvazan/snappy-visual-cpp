Quoting from [upstream Snappy](http://code.google.com/p/snappy/) homepage:

> Snappy is a compression/decompression library. It does not aim for maximum compression, or compatibility with any other compression library;
> instead, it aims for very high speeds and reasonable compression. For instance, compared to the fastest mode of zlib,
> Snappy is an order of magnitude faster for most inputs, but the resulting compressed files are anywhere from 20% to 100% bigger.
> On a single core of a Core i7 processor in 64-bit mode, Snappy compresses at about 250 MB/sec or more and decompresses at about 500 MB/sec or more.

This is a Windows fork of Snappy. It builds out of the box in Visual C++ 2013.
It produces nice clean DLLs with both 32-bit and 64-bit versions available,
which you can download here:

[snappy-dlls-1.1.1.zip](https://bitbucket.org/robertvazan/snappy-visual-cpp/downloads/snappy-dlls-1.1.1.zip)

Note that these DLLs depend on [Visual C++ 2013 Redistributable](http://www.microsoft.com/en-us/download/details.aspx?id=40784),
particularly on the two C++ runtime DLLs in it: msvcp120.dll and msvcr120.dll (32-bit and 64-bit versions respectively).

Tests have been ported as well and they show that this Windows port is correct and fast.
Results below have been measured on Core i7 3.4GHz. The BM_ZFlat results are important.

## 32-bit test results

	C:\...\snappy-visual-cpp>Release\runtests.exe
	Running microbenchmarks.
	Benchmark            Time(ns)    CPU(ns) Iterations
	---------------------------------------------------
	BM_UFlat/0              82805      83629       2425 1.1GB/s  html
	BM_UFlat/1             838253     855700        237 782.5MB/s  urls
	BM_UFlat/2               5433       5447      34364 21.7GB/s  jpg
	BM_UFlat/3                133        128    1333333 1.4GB/s  jpg_200
	BM_UFlat/4              28308      29670       6835 3.0GB/s  pdf
	BM_UFlat/5             339063     346668        585 1.1GB/s  html4
	BM_UFlat/6              29009      29082       6437 806.8MB/s  cp
	BM_UFlat/7              13034      13506      15015 787.3MB/s  c
	BM_UFlat/8               3766       3689      46511 961.8MB/s  lsp
	BM_UFlat/9            1225006    1244177        163 789.3MB/s  xls
	BM_UFlat/10               311        308     555555 617.5MB/s  xls_200
	BM_UFlat/11            281645     255390        733 567.9MB/s  txt1
	BM_UFlat/12            242644     226910        825 526.1MB/s  txt2
	BM_UFlat/13            733444     745591        272 545.9MB/s  txt3
	BM_UFlat/14            991719     999019        203 460.0MB/s  txt4
	BM_UFlat/15            388137     383366        529 1.2GB/s  bin
	BM_UFlat/16               262        274     454545 694.7MB/s  bin_200
	BM_UFlat/17             49825      48000       3900 759.8MB/s  sum
	BM_UFlat/18              4900       4659      36832 865.2MB/s  man
	BM_UFlat/19             78618      79874       2539 1.4GB/s  pb
	BM_UFlat/20            298402     296926        683 592.0MB/s  gaviota
	BM_UValidate/0          38928      38902       5213 2.5GB/s  html
	BM_UValidate/1         442964     447684        453 1.5GB/s  urls
	BM_UValidate/2            184        188     909090 626.4GB/s  jpg
	BM_UValidate/3             71         68    1818181 2.7GB/s  jpg_200
	BM_UValidate/4          12700      12756      15898 6.9GB/s  pdf
	BM_ZFlat/0             229905     213212        878 458.0MB/s  html (22.31 %)
	BM_ZFlat/1            2616060    2652020        100 252.5MB/s  urls (47.77 %)
	BM_ZFlat/2              24115      23523       7958 5.0GB/s  jpg (99.87 %)
	BM_ZFlat/3                540        535     204081 356.5MB/s  jpg_200 (79.00 %)
	BM_ZFlat/4              98041      95559       1959 941.4MB/s  pdf (82.07 %)
	BM_ZFlat/5             915284     901337        225 433.4MB/s  html4 (22.51 %)
	BM_ZFlat/6              92552      91630       2043 256.1MB/s  cp (48.12 %)
	BM_ZFlat/7              33022      32882       5693 323.4MB/s  c (42.40 %)
	BM_ZFlat/8               8301       8082      21231 439.0MB/s  lsp (48.37 %)
	BM_ZFlat/9            2234470    2184010        100 449.7MB/s  xls (41.23 %)
	BM_ZFlat/10               674        670     232558 284.3MB/s  xls_200 (78.00 %)
	BM_ZFlat/11            850777     866670        234 167.4MB/s  txt1 (57.87 %)
	BM_ZFlat/12            756408     759554        267 157.2MB/s  txt2 (61.93 %)
	BM_ZFlat/13           2272870    2340020        100 173.9MB/s  txt3 (54.92 %)
	BM_ZFlat/14           2971630    2652020        100 173.3MB/s  txt4 (66.22 %)
	BM_ZFlat/15            814947     824394        246 593.7MB/s  bin (18.11 %)
	BM_ZFlat/16               204        193     645161 986.0MB/s  bin_200 (7.50 %)
	BM_ZFlat/17            160105     149045       1256 244.7MB/s  sum (48.96 %)
	BM_ZFlat/18             11042      10787      14461 373.7MB/s  man (59.36 %)
	BM_ZFlat/19            179303     184868       1097 611.8MB/s  pb (19.64 %)
	BM_ZFlat/20            653457     658444        308 267.0MB/s  gaviota (37.72 %)
	
	
	Running correctness tests.
	All tests passed.

## 64-bit test results

	C:\...\snappy-visual-cpp>x64\Release\runtests.exe
	Running microbenchmarks.
	Benchmark            Time(ns)    CPU(ns) Iterations
	---------------------------------------------------
	BM_UFlat/0              57994      50696       2154 1.9GB/s  html
	BM_UFlat/1             605963     622088        326 1.1GB/s  urls
	BM_UFlat/2               6946       6804      27510 17.4GB/s  jpg
	BM_UFlat/3                 79         84    1111111 2.2GB/s  jpg_200
	BM_UFlat/4              19619      18983       9861 4.6GB/s  pdf
	BM_UFlat/5             234921     237471        854 1.6GB/s  html4
	BM_UFlat/6              19192      18945       9881 1.2GB/s  cp
	BM_UFlat/7               9052       9079      20618 1.1GB/s  c
	BM_UFlat/8               2518       2548      67340 1.4GB/s  lsp
	BM_UFlat/9             928534     943260        215 1.0GB/s  xls
	BM_UFlat/10               211        210     740740 905.7MB/s  xls_200
	BM_UFlat/11            207539     205472        987 705.9MB/s  txt1
	BM_UFlat/12            180266     182868       1109 652.8MB/s  txt2
	BM_UFlat/13            554752     552591        367 736.5MB/s  txt3
	BM_UFlat/14            740758     765286        265 600.5MB/s  txt4
	BM_UFlat/15            295945     277746        674 1.7GB/s  bin
	BM_UFlat/16               207        210     666666 905.7MB/s  bin_200
	BM_UFlat/17             36462      35887       5651 1016.2MB/s  sum
	BM_UFlat/18              3415       3379      55401 1.2GB/s  man
	BM_UFlat/19             53019      54575       3716 2.0GB/s  pb
	BM_UFlat/20            209915     216899        935 810.4MB/s  gaviota
	BM_UValidate/0          37251      36619       5538 2.6GB/s  html
	BM_UValidate/1         409787     241595        452 2.7GB/s  urls
	BM_UValidate/2            159         29    1052631 3989.2GB/s  jpg
	BM_UValidate/3             50         32    2857142 5.7GB/s  jpg_200
	BM_UValidate/4          12302      11840      15810 7.4GB/s  pdf
	BM_ZFlat/0             185469     190244       1066 513.3MB/s  html (22.31 %)
	BM_ZFlat/1            2173740    2184010        100 306.6MB/s  urls (47.77 %)
	BM_ZFlat/2              33716      30334       5657 3.9GB/s  jpg (99.87 %)
	BM_ZFlat/3                432        461     270270 413.1MB/s  jpg_200 (79.00 %)
	BM_ZFlat/4              69500      70859       2862 1.2GB/s  pdf (82.07 %)
	BM_ZFlat/5             771360     786050        258 496.9MB/s  html4 (22.51 %)
	BM_ZFlat/6              77014      80540       2518 291.3MB/s  cp (48.12 %)
	BM_ZFlat/7              23293      22593       7595 470.6MB/s  c (42.40 %)
	BM_ZFlat/8               6228       6318      29629 561.7MB/s  lsp (48.37 %)
	BM_ZFlat/9            1832209    1843645        110 532.7MB/s  xls (41.23 %)
	BM_ZFlat/10               535        522     298507 365.0MB/s  xls_200 (78.00 %)
	BM_ZFlat/11            727200     740149        274 196.0MB/s  txt1 (57.87 %)
	BM_ZFlat/12            650074     654196        310 182.5MB/s  txt2 (61.93 %)
	BM_ZFlat/13           1977640    2028010        100 200.7MB/s  txt3 (54.92 %)
	BM_ZFlat/14           2529470    2496020        100 184.1MB/s  txt4 (66.22 %)
	BM_ZFlat/15            680212     685138        296 714.4MB/s  bin (18.11 %)
	BM_ZFlat/16               216        214     800000 889.2MB/s  bin_200 (7.50 %)
	BM_ZFlat/17            121683     118107       1585 308.8MB/s  sum (48.96 %)
	BM_ZFlat/18              8357       8048      21321 500.9MB/s  man (59.36 %)
	BM_ZFlat/19            153873     157821       1285 716.6MB/s  pb (19.64 %)
	BM_ZFlat/20            588782     542611        345 324.0MB/s  gaviota (37.72 %)
	
	
	Running correctness tests.
	Crazy decompression lengths not checked on 64-bit build
	All tests passed.

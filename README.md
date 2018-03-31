# Hand-Coded-TPCH

A hand coded program can use the most efficient methods to gain the fastest query running speed, thus we can know the performance gap between current TiDB and the ideal database implementations.

## 1. How To Generate csv files for every table

```sh
git clone https://github.com/pingcap/tidb-bench.git
cd tidb-bench/tpch
make tbl
```

the last command will generate 1 csv file for 1 table:
```sh
➜ ls -l *.tbl
-rw-r--r--  1 jianzhang.zj  staff   24346144 Mar 30 21:55 customer.tbl
-rw-r--r--  1 jianzhang.zj  staff  759863287 Mar 30 21:55 lineitem.tbl
-rw-r--r--  1 jianzhang.zj  staff       2224 Mar 30 21:55 nation.tbl
-rw-r--r--  1 jianzhang.zj  staff  171952161 Mar 30 21:55 orders.tbl
-rw-r--r--  1 jianzhang.zj  staff   24135125 Mar 30 21:55 part.tbl
-rw-r--r--  1 jianzhang.zj  staff  118984616 Mar 30 21:55 partsupp.tbl
-rw-r--r--  1 jianzhang.zj  staff        389 Mar 30 21:55 region.tbl
-rw-r--r--  1 jianzhang.zj  staff    1409184 Mar 30 21:55 supplier.tbl
```

The defailt scale factor is 1, to generate a larger csv file, take a look at `Makefile` for more details.

## 2. What execution models can we consider

### 2.1 Hyper

[2011 VLDB: "Efficiently Compiling Efficient Query Plans for Modern Hardware"](http://www.vldb.org/pvldb/vol4/p539-neumann.pdf)
[2011 ICDE: "HyPer: A Hybrid OLTP&OLAP Main Memory Database System Based on Virtual Memory Snapshots"](https://www.cs.cmu.edu/~pavlo/courses/fall2013/static/slides/hyper.pdf)

### 2.2 Vectorwise

[2005 CIDR: "MonetDB/X100: Hyper-pipelining query execution"](http://15721.courses.cs.cmu.edu/spring2018/papers/18-execution/boncz-cidr2005.pdf)
[2012 ICDE: "Vectorwise: A vectorized analytical DBMS. In Data Engineering"](https://pdfs.semanticscholar.org/2e0d/128a5695b02eeb39bd4e06e8eb54990026dd.pdf)
[2012: "Query Optimization and Execution in Vectorwise MPP"](https://homepages.cwi.nl/~boncz/msc/2012-AndreiCosteaAdrianIonescu.pdf)
[2015 SIGMOD: "Rethinking SIMD Vectorization for In-Memory Databases"](http://www.cs.columbia.edu/~orestis/sigmod15.pdf)

### 2.3 Peloton

[2017 VLDB: "Relaxed Operator Fusion for In-Memory Databases: Making Compilation, Vectorization, and Prefetching Work Together At Last"](http://www.vldb.org/pvldb/vol11/p1-menon.pdf)
[2017 CIDR: "Self-Driving Database Management Systems"](https://www.cs.cmu.edu/~jarulraj/papers/2017.ai.cidr.pdf)

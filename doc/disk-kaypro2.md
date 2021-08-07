Disk: Kaypro II
========================

The Kaypro II is an unusual CP/M Computer because the entire case is made out of
metal. Kaypro's computers were an extension of their test instrument design philosophy:
rugged, reliable, reasonably priced, looking more like instruments than the creative,
communications (and business) tools that they really are. 

[All about the Kaypro II Computer](http://oldcomputers.net/kayproii.html)

It stored either 204kB on a double-sided 40-track drive or 408kB on a
double-sided 80 track drive. The disk format it used was 10 sectors of
512 bytes, a variation of the standard MFM IBM scheme --- sector numbering
starts at 0 rather than 1.  FluxEngine supports this.


Reading discs
-------------

Just do:

```
fluxengine read kaypro2
```

You should end up with an `kaypro2.img` which is 204800 or 409600 bytes long.
This is an alias for `fluxengine read ibm` with preconfigured parameters.  You
can pass this straight into [cpmtools](http://www.moria.de/~michael/cpmtools/):

```
$ cpmls -f kpii -D KAYPRO1.RAW
     Name    Bytes   Recs  Attr     update             create
------------ ------ ------ ---- -----------------  -----------------
ASM     .COM     8K     64
BASICLIB.REL    41K    324 
BAUD    .COM     1K      6 
CONFIG  .COM    12K     90 
COPY    .COM     2K     14 
DDT     .COM     5K     38 
DISKDEF .LIB     7K     49 
DPLAY   .BAS     1K      4 
DUMP    .ASM     5K     33 
DUMP    .COM     1K      4 
ED      .COM     7K     52 
FAC     .BAS     1K      2 
FAC     .COM     0K      0 
FORMAT  .COM     3K     18 
LOAD    .COM     2K     14 
MOVCPM  .COM    10K     76 
OVERLAYB.COM     7K     54 
PIP     .COM     8K     58
SBASIC  .COM    26K    204 
SBIOS   .ASM     9K     69 
STAT    .COM     6K     41 
SUBMIT  .COM     2K     10 
SYSGEN  .COM     1K      8 
TERM    .COM     1K      6 
USERLIB .REL     1K      6 
XAMN    .BAS    20K    154 
XSUB    .COM     1K      6 
   27 Files occupying    188K,       3K Free.


Useful references
-----------------

  - [The Kaypro II Computer](http://oldcomputers.net/kayproii.html)

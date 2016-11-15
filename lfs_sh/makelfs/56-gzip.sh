#!/bin/sh
set -e

cd /sources
tar -xvf gzip-1.6.tar.xz
cd gzip-1.6

./configure --prefix=/usr --bindir=/bin

make -j4
make check
make install

#mv -v /bin/{gzexe,uncompress,zcmp,zdiff,zegrep} /usr/bin
#mv -v /bin/{zfgrep,zforce,zgrep,zless,zmore,znew} /usr/bin

#rm -rf /sources/gzip-1.6
echo OK!

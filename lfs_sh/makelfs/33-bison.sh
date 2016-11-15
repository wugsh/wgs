#!/bin/sh
set -e
cd /sources
tar -xvf bison-3.0.4.tar.xz
cd bison-3.0.4

./configure --prefix=/usr --docdir=/usr/share/doc/bison-3.0.4

make -j4
make check
make install

rm -rf /sources/bison-3.0.4

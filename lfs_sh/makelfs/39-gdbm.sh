#!/bin/sh
set -e
cd /sources
tar -zxf gdbm-1.11.tar.gz
cd gdbm-1.11

./configure --prefix=/usr --enable-libgdbm-compat

make -j4
make check
make install

rm -rf /sources/gdbm-1.11
echo OK!

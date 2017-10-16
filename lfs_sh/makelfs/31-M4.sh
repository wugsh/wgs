#!/bin/sh
set -e
cd /sources
tar -xvf m4-1.4.17.tar.xz
cd m4-1.4.17

./configure --prefix=/usr

make -j4
make check
make install

rm -rf /sources/m4-1.4.17
echo OK!

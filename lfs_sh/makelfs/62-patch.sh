#!/bin/sh
set -e

cd /sources
tar -xvf patch-2.7.4.tar.xz
cd patch-2.7.4

./configure --prefix=/usr

make -j4
echo make_OK******
make check
echo check_OK******
make install
echo install_OK******

rm -rf /sources/patch-2.7.4
echo OK!

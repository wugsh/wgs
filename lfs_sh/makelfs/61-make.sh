#!/bin/sh
set -e
cd /sources
tar -xvf make-4.1.tar.bz2
cd make-4.1

:<<BLOCK 
./configure --prefix=/usr

make -j4 
echo make_OK********
make check
echo check_OK*******
BLOCK
make install
echo install_OK******

rm -rf /sources/make-4.1
echo OK!

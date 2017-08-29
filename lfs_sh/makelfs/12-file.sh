#!/bin/sh
#
# Linux API Headers
set -e
cd /sources
tar -xf file-5.22.tar.gz
cd file-5.22
./configure --prefix=/usr
make -j4 
make check
make install
cd ..
rm -rf file-5.22
echo OK!

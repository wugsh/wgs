#!/bin/sh
set -e 
cd /sources
tar -xvf autoconf-2.69.tar.xz
cd autoconf-2.69

./configure --prefix=/usr

make -j4

#make check

make install

rm -rf /sources/autoconf-2.69
echo OK!

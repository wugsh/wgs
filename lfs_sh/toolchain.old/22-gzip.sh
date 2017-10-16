#!/bin/sh
#
# Gzip
set -e
cd $LFS/sources
rm -rf gzip-1.6
tar -xvf gzip-1.6.tar.xz
cd gzip-1.6
./configure --prefix=/tools
make -j 5
#make check
make install
cd $LFS/sources
rm -rf gzip-1.6

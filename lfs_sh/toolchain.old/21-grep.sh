#!/bin/sh
#
# Grep
set -e
cd $LFS/sources
rm -rf grep-2.21
tar -xvf grep-2.21.tar.xz
cd grep-2.21
./configure --prefix=/tools
make -j 5
#make check
make install
cd $LFS/sources
rm -rf grep-2.21

#!/bin/sh
#
# M4
set -e
cd $LFS/sources
rm -rf m4-1.4.17
tar -xvf m4-1.4.17.tar.xz
cd m4-1.4.17
./configure --prefix=/tools
make -j 5
#make check
make install
cd $LFS/sources
rm -rf m4-1.4.17


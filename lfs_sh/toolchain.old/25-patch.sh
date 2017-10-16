#!/bin/sh
#
# Patch
set -e
cd $LFS/sources
rm -rf patch-2.7.4
tar -xvf patch-2.7.4.tar.xz
cd patch-2.7.4
./configure --prefix=/tools
make -j 5
#make check
make install
cd $LFS/sources
rm -rf patch-2.7.4

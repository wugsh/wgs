#!/bin/sh
#
# Xz
set -e
cd $LFS/sources
rm -rf xz-5.2.0
tar -xvf xz-5.2.0.tar.xz
cd xz-5.2.0
./configure --prefix=/tools                
make -j 5
#make check
make install
cd $LFS/sources
rm -rf xz-5.2.0

echo OK!

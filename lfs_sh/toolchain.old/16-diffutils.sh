#!/bin/sh
#
# Diffutils
set -e
cd $LFS/sources
rm -rf diffutils-3.3
tar -xvf diffutils-3.3.tar.xz
cd diffutils-3.3
./configure --prefix=/tools
make -j 5
#make check
make install
cd $LFS/sources
rm -rf diffutils-3.3


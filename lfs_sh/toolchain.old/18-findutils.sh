#!/bin/sh
#
# Findutils
set -e
cd $LFS/sources
rm -rf findutils-4.4.2
tar -xvf findutils-4.4.2.tar.gz
cd findutils-4.4.2
./configure --prefix=/tools
make -j 5
#make check
make install
cd $LFS/sources
rm -rf findutils-4.4.2


#!/bin/sh
#
# Sed
set -e
cd $LFS/sources
rm -rf sed-4.2.2
tar -xvf sed-4.2.2.tar.bz2
cd sed-4.2.2
./configure --prefix=/tools
make -j 5
#make check
make install
cd $LFS/sources
rm -rf sed-4.2.2


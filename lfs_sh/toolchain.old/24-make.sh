#!/bin/sh
#
# Make
set -e
cd $LFS/sources
rm -rf make-4.1
tar -xvf make-4.1.tar.bz2
cd make-4.1
./configure --prefix=/tools --without-guile
make -j 5
#make check
make install
cd $LFS/sources
rm -rf make-4.1

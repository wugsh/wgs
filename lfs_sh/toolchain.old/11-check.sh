#!/bin/sh
#
# Check
set -e
cd $LFS/sources
rm -rf check-0.9.14
tar -xvf check-0.9.14.tar.gz
cd check-0.9.14
PKG_CONFIG= ./configure --prefix=/tools
make -j 5
#make check
make install
cd $LFS/sources
rm -rf check-0.9.14



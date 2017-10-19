#!/bin/sh
#
# Texinfo
set -e
cd $LFS/sources
rm -rf texinfo-5.2
tar -xvf texinfo-5.2.tar.xz
cd texinfo-5.2
./configure --prefix=/tools 
make -j 5
#make check
make install
cd $LFS/sources
rm -rf texinfo-5.2


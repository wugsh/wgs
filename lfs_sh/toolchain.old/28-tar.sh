#!/bin/sh
#
# Tar
set -e
cd $LFS/sources
rm -rf tar-1.28
tar -xvf tar-1.28.tar.xz
cd tar-1.28
FORCE_UNSAFE_CONFIGURE=1 \
./configure --prefix=/tools 
make -j 5
#make check
make install
cd $LFS/sources
rm -rf tar-1.28

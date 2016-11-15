#!/bin/sh
#
# Gawk
set -e
cd $LFS/sources
rm -rf gawk-4.1.1
tar -xvf gawk-4.1.1.tar.xz
cd gawk-4.1.1
./configure --prefix=/tools
make -j 5
#make check (fails)
make install
cd $LFS/sources
rm -rf gawk-4.1.1



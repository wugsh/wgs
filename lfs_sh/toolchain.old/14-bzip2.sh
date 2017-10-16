#!/bin/sh
#
# Bzip2
set -e
cd $LFS/sources
rm -rf bzip2-1.0.6
tar -xvf bzip2-1.0.6.tar.gz
cd bzip2-1.0.6
make -j 5
make PREFIX=/tools install
cd $LFS/sources
rm -rf bzip2-1.0.6


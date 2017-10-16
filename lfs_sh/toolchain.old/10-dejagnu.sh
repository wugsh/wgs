#!/bin/sh
#
# DejaGNU
set -e
cd $LFS/sources
rm -rf dejagnu-1.5.2
tar -xvf dejagnu-1.5.2.tar.gz
cd dejagnu-1.5.2
./configure --prefix=/tools
make -j 5
make install
#make check
cd $LFS/sources
rm -rf dejagnu-1.5.2



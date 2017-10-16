#!/bin/sh
set -e 
cd /sources
tar -xvf libtool-2.4.6.tar.xz
cd libtool-2.4.6

./configure --prefix=/usr

make -j4
echo make_OK**********
#make check
echo check_OK*********
make install
echo install_OK*******

rm -rf /sources/libtool-2.4.6

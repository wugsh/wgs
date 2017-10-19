#!/bin/sh
#
# Linux API Headers
set -e
cd /sources
tar -xvf zlib-1.2.8.tar.xz
cd zlib-1.2.8
./configure --prefix=/usr
make -j4
make check
make install
mv -v /usr/lib/libz.so.* /lib
ln -sfv ../../lib/$(readlink /usr/lib/libz.so) /usr/lib/libz.so

cd ..
rm -rf zlib-1.2.8
echo OK!




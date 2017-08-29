#!/bin/sh
set -e 
cd /sources
tar -xvf libpipeline-1.4.0.tar.gz
cd libpipeline-1.4.0

PKG_CONFIG_PATH=/tools/lib/pkgconfig ./configure --prefix=/usr

make -j4
make check
make install

rm -rf /sources/libpipeline-1.4.0
echo OK!

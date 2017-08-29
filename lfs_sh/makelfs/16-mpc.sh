#!/bin/sh
#
# Linux API Headers
set -e
cd /sources
tar -xf mpc-1.0.2.tar.gz
cd mpc-1.0.2
./configure --prefix=/usr --docdir=/usr/share/doc/mpc-1.0.2

make -j4
make html
make check 
make install
make install-html

cd ..
rm -rf mpc-1.0.2
echo OK!

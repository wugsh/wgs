#!/bin/sh
set -e

cd /sources
tar -xvf gperf-3.0.4.tar.gz
cd gperf-3.0.4

./configure --prefix=/usr --docdir=/usr/share/doc/gperf-3.0.4

make -j4
echo make_OK*******
make check
echo check_OK******
make install
echo install_OK*****

rm -rf /sources/gperf-3.0.4

echo OK!

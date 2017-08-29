#!/bin/sh
set -e
cd /sources
tar -xvf groff-1.22.3.tar.gz
cd groff-1.22.3

PAGE=letter ./configure --prefix=/usr

make -j4
echo make_OK*******
make install
echo install_OK*******

rm -rf /sources/groff-1.22.3
echo OK!

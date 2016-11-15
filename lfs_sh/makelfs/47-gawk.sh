#!/bin/sh
set -e
cd /sources
tar -xvf gawk-4.1.1.tar.xz
cd gawk-4.1.1

./configure --prefix=/usr

make -j4
make check
make install

mkdir -v /usr/share/doc/gawk-4.1.1
#cp -v doc/{awkforai.txt,*.{eps,pdf,jpg}} /usr/share/doc/gawk-4.1.1

#rm -rf /sources/gawk-4.1.1
echo OK!

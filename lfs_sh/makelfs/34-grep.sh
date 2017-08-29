#!/bin/sh
set -e
cd /sources
tar -xvf grep-2.21.tar.xz
cd grep-2.21

sed -i -e '/tp++/a  if (ep <= tp) break;' src/kwset.c

./configure --prefix=/usr --bindir=/bin

make -j4
make check
make install

rm -rf /sources/grep-2.21

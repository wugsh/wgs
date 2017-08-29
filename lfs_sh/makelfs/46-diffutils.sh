#!/bin/sh
set -e
cd /sources
tar -xvf diffutils-3.3.tar.xz
cd diffutils-3.3

sed -i 's:= @mkdir_p@:= /bin/mkdir -p:' po/Makefile.in.in

./configure --prefix=/usr

make -j4
make check
make install

rm -rf /sources/diffutils-3.3
echo OK!

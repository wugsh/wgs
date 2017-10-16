#!/bin/sh
set -e 
cd /sources
tar -xvf tar-1.28.tar.xz
cd tar-1.28

FORCE_UNSAFE_CONFIGURE=1  \
./configure --prefix=/usr \
            --bindir=/bin

make -j4
make check

make install
make -C doc install-html docdir=/usr/share/doc/tar-1.28

rm -rf /sources/tar-1.28

echo OK!

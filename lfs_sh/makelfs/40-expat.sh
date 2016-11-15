#!/bin/sh
set -e
cd /sources
tar -xvf expat-2.1.0.tar.gz
cd expat-2.1.0

./configure --prefix=/usr

make -j4

make check
make install

install -v -dm755 /usr/share/doc/expat-2.1.0
# install -v -m644 doc/*.{html,png,css} /usr/share/doc/expat-2.1.0

# rm -rf /sources/expat-2.1.0

#!/bin/sh
#
# Gettext
set -e
cd /sources
rm -rf gettext-0.19.4
tar -xvf gettext-0.19.4.tar.xz
cd gettext-0.19.4

./configure --prefix=/usr --docdir=/usr/share/doc/gettext-0.19.4
make -j4
make check 
make install

cd /sources
rm -rf gettext-0.19.4
echo OK!


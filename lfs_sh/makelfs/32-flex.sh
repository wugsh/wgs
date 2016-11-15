#!/bin/sh
set -e 
cd /sources
tar -xvf flex-2.5.39.tar.bz2
cd flex-2.5.39

sed -i -e '/test-bison/d' tests/Makefile.in

./configure --prefix=/usr --docdir=/usr/share/doc/flex-2.5.39

make -j4
echo make_OK*********
make check
echo check_OK********

make install
echo install*********
ln -sv flex /usr/bin/lex

rm -rf /sources/flex-2.5.39
echo OK!

#!/bin/sh
set -e 
cd /sources
tar -xvf automake-1.15.tar.xz
cd automake-1.15

./configure --prefix=/usr --docdir=/usr/share/doc/automake-1.15

make -j4
echo make_OK*********
#sed -i "s:./configure:LEXLIB=/usr/lib/libfl.a &:" t/lex-{clean,depend}-cxx.sh
#make -j4 check

#make install

#rm -rf /sources/automake-1.15

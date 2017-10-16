#!/bin/sh
set -e
cd /sources
tar -xvf readline-6.3.tar.gz
cd readline-6.3

patch -Np1 -i ../readline-6.3-upstream_fixes-3.patch

sed -i '/MV.*old/d' Makefile.in
sed -i '/{OLDSUFF}/c:' support/shlib-install

./configure --prefix=/usr --docdir=/usr/share/doc/readline-6.3

make SHLIB_LIBS=-lncurses

make SHLIB_LIBS=-lncurses install
echo install_OK******
:<<BLOCK
mv -v /usr/lib/lib{readline,history}.so.* /lib
ln -sfv ../../lib/$(readlink /usr/lib/libreadline.so) /usr/lib/libreadline.so
ln -sfv ../../lib/$(readlink /usr/lib/libhistory.so ) /usr/lib/libhistory.so

install -v -m644 doc/*.{ps,pdf,html,dvi} /usr/share/doc/readline-6.3

rm -rf /sources/readline-6.3
BLOCK

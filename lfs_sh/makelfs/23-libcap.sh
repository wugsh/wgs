#!/bin/sh
#
# Ncurses
set -e
cd /sources
rm -rf libcap-2.24
tar -xvf libcap-2.24.tar.xz
cd libcap-2.24

make -j4
echo make_OK**********
make RAISE_SETFCAP=no prefix=/usr install
chmod -v 755 /usr/lib/libcap.so
echo install_OK*******
mv -v /usr/lib/libcap.so.* /lib
ln -sfv ../../lib/$(readlink /usr/lib/libcap.so) /usr/lib/libcap.so

cd /sources
rm -rf libcap-2.24
echo OK!



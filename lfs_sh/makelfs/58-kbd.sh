#!/bin/sh
set -e
cd /sources
tar -xvf kbd-2.0.2.tar.gz
cd kbd-2.0.2

patch -Np1 -i ../kbd-2.0.2-backspace-1.patch

sed -i 's/\(RESIZECONS_PROGS=\)yes/\1no/g' configure
sed -i 's/resizecons.8 //' docs/man/man8/Makefile.in

PKG_CONFIG_PATH=/tools/lib/pkgconfig ./configure --prefix=/usr --disable-vlock

make -j4
echo make_OK*******
make check
echo check_OK******
make install
echo install_OK*****

mkdir -v       /usr/share/doc/kbd-2.0.2
cp -R -v docs/doc/* /usr/share/doc/kbd-2.0.2

rm -rf /sources/kbd-2.0.2
echo OK!

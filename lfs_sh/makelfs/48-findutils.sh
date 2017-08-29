#!/bin/sh
set -e
cd /sources
tar -xvf findutils-4.4.2.tar.gz
cd findutils-4.4.2

./configure --prefix=/usr --localstatedir=/var/lib/locate

make -j4
echo make_OK**********
make check
echo check_OK*********
make install
echo install_OK*******

mv -v /usr/bin/find /bin
sed -i 's|find:=${BINDIR}|find:=/bin|' /usr/bin/updatedb

rm -rf /sources/findutils-4.4.2
echo OK!

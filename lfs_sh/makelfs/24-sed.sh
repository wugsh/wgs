#!/bin/sh
#
# Sed
set -e
cd /sources
rm -rf sed-4.2.2
tar -xvf sed-4.2.2.tar.bz2
cd sed-4.2.2
./configure --prefix=/usr --bindir=/bin --htmldir=/usr/share/doc/sed-4.2.2
make -j 5
echo make_OK*******
make html
echo html_OK*******
make check
echo check_OK********
make install
echo install_OK*******

make -C doc install-html
cd /sources
rm -rf sed-4.2.2
echo OK!


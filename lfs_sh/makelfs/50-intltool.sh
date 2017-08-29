#!/bin/sh
set -e
cd /sources
tar -xvf intltool-0.50.2.tar.gz
cd intltool-0.50.2

./configure --prefix=/usr

make -j4
echo make_OK*******
make check
echo check_OK******

make install
echo install_OK*****
install -v -Dm644 doc/I18N-HOWTO /usr/share/doc/intltool-0.50.2/I18N-HOWTO

rm -rf /sources/intltool-0.50.2
echo OK!

#!/bin/sh
#
# Linux API Headers
set -e
cd /sources
tar -xf pkg-config-0.28.tar.gz
cd pkg-config-0.28
./configure --prefix=/usr			  \
			--with-internal-glib      \
			--disable-host-tool       \
			--docdir=/usr/share/doc/pkg-config-0.28
make -j4
echo make_OK***************
make check
echo check_OK***********
make install
echo install_OK**********
cd /sources
rm -rf pkg-config-0.28
echo OK!

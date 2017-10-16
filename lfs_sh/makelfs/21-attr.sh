#!/bin/sh
#
# Linux API Headers
set -e
cd /sources
tar -xvf attr-2.4.47.src.tar.gz	
cd attr-2.4.47
sed -i -e 's|/@pkg_name@|&-@pkg_version@|' include/builddefs.in
sed -i -e "/SUBDIRS/s|man2||" man/Makefile
./configure --prefix=/usr
make -j1
echo make_OK**************
make -j1 tests root-tests
echo tests_OK*********
make install install-dev install-lib
echo install_OK*******
chmod -v 755 /usr/lib/libattr.so

mv -v /usr/lib/libattr.so.* /lib
ln -sfv ../../lib/$(readlink /usr/lib/libattr.so) /usr/lib/libattr.so

cd /sources
rm -rf attr-2.4.47
echo OK!




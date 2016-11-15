#!/bin/sh
#
# Tcl
set -e
cd $LFS/sources
rm -rf tcl8.6.3
tar -xvf tcl8.6.3-src.tar.gz
cd tcl8.6.3
cd unix
./configure --prefix=/tools
make -j 5
#TZ=UTC make test
make install
chmod -v u+w /tools/lib/libtcl8.6.so
make install-private-headers
ln -sv tclsh8.6 /tools/bin/tclsh
cd $LFS/sources
rm -rf tcl8.6.3






#!/bin/sh
#
# Util-linux
set -e
cd $LFS/sources
rm -rf util-linux-2.26
tar -xvf util-linux-2.26.tar.xz
cd util-linux-2.26
./configure --prefix=/tools                \
            --without-python               \
            --disable-makeinstall-chown    \
            --without-systemdsystemunitdir \
            PKG_CONFIG=""
make -j 5
make install
cd $LFS/sources
rm -rf util-linux-2.26


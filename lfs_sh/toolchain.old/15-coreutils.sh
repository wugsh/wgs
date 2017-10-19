#!/bin/sh
#
# Coreutils
set -e
cd $LFS/sources
rm -rf coreutils-8.23
tar -xvf coreutils-8.23.tar.xz
cd coreutils-8.23
FORCE_UNSAFE_CONFIGURE=1 \
./configure --prefix=/tools --enable-install-program=hostname
make -j 5
#make RUN_EXPENSIVE_TESTS=yes check
make install
cd $LFS/sources
rm -rf coreutils-8.23


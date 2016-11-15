#!/bin/sh
#
# Binutils Pass 2
set -e
cd $LFS/sources
rm -rf binutils-2.25 binutils-build
tar -xvf binutils-2.25.tar.bz2
mkdir -v binutils-build
cd binutils-build
CC=$LFS_TGT-gcc                \
AR=$LFS_TGT-ar                 \
RANLIB=$LFS_TGT-ranlib         \
../binutils-2.25/configure     \
    --prefix=/tools            \
    --disable-nls              \
    --disable-werror           \
    --with-lib-path=/tools/lib \
    --with-sysroot
make -j 5
make install
make -C ld clean
make -C ld LIB_PATH=/usr/lib:/lib
cp -v ld/ld-new /tools/bin
cd $LFS/sources
rm -rf binutils-2.25 binutils-build




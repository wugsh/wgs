#!/bin/sh
#
# Linux API Headers
set -e
cd $LFS/sources
rm -rf linux-3.19
tar -xf linux-3.19.tar.xz
cd linux-3.19
make mrproper
make INSTALL_HDR_PATH=dest headers_install
cp -rv dest/include/* /tools/include
cd $LFS/sources
rm -rf linux-3.19
echo OK!




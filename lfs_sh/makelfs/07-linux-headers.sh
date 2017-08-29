#!/bin/sh
#
# Linux API Headers
set -e
cd /sources
rm -rf linux-3.19
tar -xf linux-3.19.tar.xz
cd linux-3.19
make mrproper
make INSTALL_HDR_PATH=dest headers_install
find dest/include \( -name .install -o -name ..install.cmd \) -delete
cp -rv dest/include/* /usr/include
cd /sources
rm -rf linux-3.19
echo OK!




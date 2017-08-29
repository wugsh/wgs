#!/bin/sh
#
# Linux API Headers
set -e
cd /sources
tar -xf mpfr-3.1.2.tar.xz
cd mpfr-3.1.2
patch -Np1 -i ../mpfr-3.1.2-upstream_fixes-3.patch

./configure --prefix=/usr	\
			--enable-thread-safe		\
			--docdir=/usr/share/doc/mpfr-3.1.2

make -j4
make html
make check 
make install
make install-html

cd ..
rm -rf mpfr-3.1.2
echo OK!

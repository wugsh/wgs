#!/bin/sh
#
# Linux API Headers
set -e
cd /sources
tar -xf gmp-6.0.0a.tar.xz
cd gmp-6.0.0
./configure --prefix=/usr \
			--enable-cxx 	     \
			--docdir=/usr/share/doc/gmp-6.0.0a
make -j4
make html
make check 2>&1 | tee gmp-check-log
awk '/tests passed/{total+=$2} ; END{print total}' gmp-check-log
make install
make install-html

cd ..
rm -rf gmp-6.0.0
echo OK!

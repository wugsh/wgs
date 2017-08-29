#!/bin/sh
#
# Binutils 
set -e
cd /sources
rm -rf binutils-2.25 binutils-build
tar -xvf binutils-2.25.tar.bz2
cd binutils-2.25
expect -c "spawn ls"
mkdir -v ../binutils-build
cd ../binutils-build

../binutils-2.25/configure --prefix=/usr	\
						   --enable-shared 	\
						   --disable-werror
make tooldir=/usr
make -k check
make tooldir=/usr install


cd /sources
rm -rf binutils-2.25 binutils-build
echo OK!




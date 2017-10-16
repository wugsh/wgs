#!/bin/sh
set -e
cd /sources
tar -xvf iproute2-3.19.0.tar.xz
cd iproute2-3.19.0

sed -i '/^TARGETS/s@arpd@@g' misc/Makefile
sed -i /ARPD/d Makefile
sed -i 's/arpd.8//' man/man8/Makefile

make -j4
make DOCDIR=/usr/share/doc/iproute2-3.19.0 install

rm -rf /sources/iproute2-3.19.0
echo OK!

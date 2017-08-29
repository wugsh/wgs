#!/bin/sh
set -e
cd /sources
tar -xvf iana-etc-2.30.tar.bz2
cd iana-etc-2.30

make -j4
make install

rm -rf /sources/iana-etc-2.30
echo OK

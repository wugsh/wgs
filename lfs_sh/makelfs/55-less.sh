#!/bin/sh
set -e

cd /sources
tar -xvf less-458.tar.gz
cd less-458

./configure --prefix=/usr --sysconfdir=/etc

make -j4
make install

rm -rf /sources/less-458
echo OK!

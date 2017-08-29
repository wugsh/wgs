#!/bin/sh
set -e

cd /sources
tar -xvf man-db-2.7.1.tar.xz
cd man-db-2.7.1

./configure --prefix=/usr                        \
            --docdir=/usr/share/doc/man-db-2.7.1 \
            --sysconfdir=/etc                    \
            --disable-setuid                     \
            --with-browser=/usr/bin/lynx         \
            --with-vgrind=/usr/bin/vgrind        \
            --with-grap=/usr/bin/grap

make -j4
make check
make install

sed -i "s:man root:root root:g" /usr/lib/tmpfiles.d/man-db.conf

rm -rf /sources/man-db-2.7.1
echo OK!

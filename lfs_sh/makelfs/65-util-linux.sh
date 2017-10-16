#!/bin/sh
set -e

cd /sources
tar -xvf util-linux-2.26.tar.xz
cd util-linux-2.26

mkdir -pv /var/lib/hwclock

./configure ADJTIME_PATH=/var/lib/hwclock/adjtime   \
            --docdir=/usr/share/doc/util-linux-2.26 \
            --disable-chfn-chsh  \
            --disable-login      \
            --disable-nologin    \
            --disable-su         \
            --disable-setpriv    \
            --disable-runuser    \
            --disable-pylibmount \
            --without-python

make -j4
echo make_OK********
chown -Rv nobody .
su nobody -s /bin/bash -c "PATH=$PATH make -k check"
echo check_OK**********
make install
echo install_OK**********

rm -rf /sources/util-linux-2.26
echo OK!

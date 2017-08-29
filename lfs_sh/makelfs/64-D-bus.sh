#!/bin/sh
set -e
cd /sources
tar -xvf dbus-1.8.16.tar.gz
cd dbus-1.8.16

./configure --prefix=/usr                       \
            --sysconfdir=/etc                   \
            --localstatedir=/var                \
            --docdir=/usr/share/doc/dbus-1.8.16 \
            --with-console-auth-dir=/run/console

make -j4
make install

mv -v /usr/lib/libdbus-1.so.* /lib
ln -sfv ../../lib/$(readlink /usr/lib/libdbus-1.so) /usr/lib/libdbus-1.so
ln -sfv /etc/machine-id /var/lib/dbus

rm -rf /sources/dbus-1.8.16
echo OK!

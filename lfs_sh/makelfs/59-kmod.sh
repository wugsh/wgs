#!/bin/sh
set -e
cd /sources
tar -xvf kmod-19.tar.xz
cd kmod-19

./configure --prefix=/usr          \
            --bindir=/bin          \
            --sysconfdir=/etc      \
            --with-rootlibdir=/lib \
            --with-xz              \
            --with-zlib

make -j4
make check

make install
for target in depmod insmod lsmod modinfo modprobe rmmod; do
  ln -sv ../bin/kmod /sbin/$target
done

ln -sv kmod /bin/lsmod

rm -rf /sources/kmod-19
echo OK!

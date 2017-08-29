#!/bin/sh
set -e 
cd /sources
tar -xvf grub-2.02~beta2.tar.xz
cd grub-2.02~beta2

./configure --prefix=/usr          \
            --sbindir=/sbin        \
            --sysconfdir=/etc      \
            --disable-grub-emu-usb \
            --disable-efiemu       \
            --disable-werror

make -j4
make install

rm -rf /sources/grub-2.02~beta2
echo OK!

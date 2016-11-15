#!/bin/sh
set -e
cd /sources
tar -xvf xz-5.2.0.tar.xz
cd xz-5.2.0

./configure --prefix=/usr --docdir=/usr/share/doc/xz-5.2.0

make -j4
echo make_OK********
make check
echo check_OK**********

make install
echo install_OK*********
mv -v   /usr/bin/lzma /bin
mv -v   /usr/bin/unlzma /bin
mv -v   /usr/bin/lzcat /bin
mv -v   /usr/bin/xz /bin
mv -v   /usr/bin/unxz /bin
mv -v   /usr/bin/xzcat /bin

mv -v /usr/lib/liblzma.so.* /lib
ln -svf ../../lib/$(readlink /usr/lib/liblzma.so) /usr/lib/liblzma.so

rm -rf /sources/xz-5.2.0
echo OK!

#!/bin/sh
#
# Ncurses
set -e
cd /sources
rm -rf procps-ng-3.3.10
tar -xvf procps-ng-3.3.10.tar.xz
cd procps-ng-3.3.10

./configure --prefix=/usr  		\
			--exec-prefix= 		\
			--libdir=/usr/lib	\
			--docdir=/usr/share/doc/procps-ng-3.3.10 \
			--disable-static     \
			--disable-kill

make -j 5
echo make_OK**********
sed -i -r 's|(pmap_initname)\\\$|\1|' testsuite/pmap.test/pmap.exp
make check
echo check_OK*********
make install
echo install_OK*******

mv -v /usr/bin/pidof /bin
mv -v /usr/lib/libprocps.so.* /lib
ln -sfv ../../lib/$(readlink /usr/lib/libprocps.so) /usr/lib/libprocps.so

cd /sources
rm -rf procps-ng-3.3.10
echo OK!



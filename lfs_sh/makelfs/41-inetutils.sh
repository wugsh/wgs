#!/bin/sh
set -e 

cd /sources
tar -xvf inetutils-1.9.2.tar.gz
cd inetutils-1.9.2

echo '#define PATH_PROCNET_DEV "/proc/net/dev"' >> ifconfig/system/linux.h

./configure --prefix=/usr        \
            --localstatedir=/var \
            --disable-logger     \
            --disable-whois      \
            --disable-servers

make -j4
echo make_OK**********
make check
echo check_OK*********
make install
echo install_OK*******

mv -v /usr/bin/hostname     /bin
mv -v /usr/bin/ping 		/bin
mv -v /usr/bin/ping6        /bin
mv -v /usr/bin/traceroute   /bin
mv -v /usr/bin/ifconfig     /sbin

rm -rf /sources/inetutils-1.9.2

echo OK!

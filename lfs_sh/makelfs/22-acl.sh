#!/bin/sh
#
# Linux API Headers
set -e
cd /sources
tar -xvf acl-2.2.52.src.tar.gz	
cd acl-2.2.52
sed -i -e 's|/@pkg_name@|&-@pkg_version@|' include/builddefs.in
sed -i "s:| sed.*::g" test/{sbits-restore,cp,misc}.test
sed -i -e "/TABS-1;/a if (x > (TABS-1)) x = (TABS-1);" \
	libacl/__acl_to_any_text.c
./configure --prefix=/usr --libexecdir=/usr/lib
make -j4
echo make_OK********
make install install-dev install-lib
echo make_OK********
chmod -v 755 /usr/lib/libacl.so
mv -v /usr/lib/libacl.so.* /lib
ln -sfv ../../lib/$(readlink /usr/lib/libacl.so) /usr/lib/libacl.so


cd /sources
rm -rf acl-2.2.52
echo OK!




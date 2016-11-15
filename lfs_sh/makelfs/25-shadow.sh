#!/bin/sh
#
# Ncurses
set -e
cd /sources
rm -rf shadow-4.2.1
tar -xvf shadow-4.2.1.tar.xz
cd shadow-4.2.1
sed -i 's/groups$(EXEEXT) //' src/Makefile.in
find man -name Makefile.in -exec sed -i 's/groups\.1 / /' {} \;
sed -i -e 's@#ENCRYPT_METHOD DES@ENCRYPT_METHOD SHA512@' \
	   -e 's@/var/spool/mail@/var/mail@' etc/login.defs
sed -i 's/1000/999/' etc/useradd
./configure --sysconfdir=/etc --with-group-name-max-length=32
make -j4
echo make_OK**********
make install
echo install_OK*******
mv -v /usr/bin/passwd /bin

#cd /sources
#rm -rf libcap-2.24
echo OK!



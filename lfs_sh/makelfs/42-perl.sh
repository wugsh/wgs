#!/bin/sh
set -e 
cd /sources
tar -xvf perl-5.20.2.tar.bz2
cd perl-5.20.2

echo "127.0.0.1 localhost $(hostname)" > /etc/hosts

export BUILD_ZLIB=False
export BUILD_BZIP2=0

sh Configure -des -Dprefix=/usr                 \
                  -Dvendorprefix=/usr           \
                  -Dman1dir=/usr/share/man/man1 \
                  -Dman3dir=/usr/share/man/man3 \
                  -Dpager="/usr/bin/less -isR"  \
                  -Duseshrplib

make -j4
make -k test
echo make_OK*************
make install
echo install_OK**********
unset BUILD_ZLIB BUILD_BZIP2

rm -rf /sources/perl-5.20.2
echo OK!

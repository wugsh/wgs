#!/bin/sh
#
# Ncurses
set -e
cd /sources
rm -rf psmisc-22.21
tar -xvf psmisc-22.21.tar.gz
cd psmisc-22.21
./configure --prefix=/usr
make -j 5
echo make_OK**********
make install
echo install_OK*******
mv -v /usr/bin/fuser   /bin
mv -v /usr/bin/killall /bin

cd /sources
rm -rf psmisc-22.21
echo OK!



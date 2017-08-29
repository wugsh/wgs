#!/bin/sh
#
# Ncurses
set -e
cd $LFS/sources
rm -rf ncurses-5.9
tar -xvf ncurses-5.9.tar.gz
cd ncurses-5.9
./configure --prefix=/tools \
            --with-shared   \
            --without-debug \
            --without-ada   \
            --enable-widec  \
            --enable-overwrite
make -j 5
make install
cd $LFS/sources
rm -rf ncurses-5.9



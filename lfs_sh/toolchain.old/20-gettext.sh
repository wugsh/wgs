#!/bin/sh
#
# Gettext
set -e
cd $LFS/sources
rm -rf gettext-0.19.4
tar -xvf gettext-0.19.4.tar.xz
cd gettext-0.19.4
cd gettext-tools
EMACS="no" ./configure --prefix=/tools --disable-shared
make  -C gnulib-lib
make  -C intl pluralx.c 
make  -C src msgfmt
make  -C src msgmerge
make  -C src xgettext
cp -v src/msgfmt /tools/bin
cp -v src/msgmerge /tools/bin
cp -v src/xgettext /tools/bin
cd $LFS/sources
rm -rf gettext-0.19.4



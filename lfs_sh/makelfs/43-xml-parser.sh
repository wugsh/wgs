#!/bin/sh
set -e
cd /sources
tar -xvf XML-Parser-2.44.tar.gz
cd XML-Parser-2.44

perl Makefile.PL

make -j4
make test
make install

rm -rf /sources/XML-Parser-2.44
echo OK!

#!/bin/sh
set -e 
cd /sources
tar -xvf texinfo-5.2.tar.xz
cd texinfo-5.2

./configure --prefix=/usr

make -j4
make check

make install
make TEXMF=/usr/share/texmf install-tex

pushd /usr/share/info
rm -v dir
for f in *
  do install-info $f dir 2>/dev/null
done
popd

rm -rf /sources/texinfo-5.2

echo OK!

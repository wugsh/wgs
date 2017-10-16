#!/bin/sh
set -e
cd /sources
tar -xvf bash-4.3.30.tar.gz
cd bash-4.3.30

patch -Np1 -i ../bash-4.3.30-upstream_fixes-1.patch

./configure --prefix=/usr                       \
            --bindir=/bin                       \
            --docdir=/usr/share/doc/bash-4.3.30 \
            --without-bash-malloc               \
            --with-installed-readline

make -j4
echo make_OK********
chown -Rv nobody .

su nobody -s /bin/bash -c "PATH=$PATH make tests"

make install

exec /bin/bash --login +h

rm -rf /sources/bash-4.3.30

echo OK!

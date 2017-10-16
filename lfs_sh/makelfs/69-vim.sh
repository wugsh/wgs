#!/bin/sh
set -e


cd /sources
tar -xvf vim-7.4.tar.bz2
cd vim74
:<<BLOCK
echo '#define SYS_VIMRC_FILE "/etc/vimrc"' >> src/feature.h

./configure --prefix=/usr

make -j4
echo make_OK***********
make -j1 test
echo test_OK*************

make install
echo install_OK***********

ln -sv vim /usr/bin/vi
for L in  /usr/share/man/{,*/}man1/vim.1; do
    ln -sv vim.1 $(dirname $L)/vi.1
done
BLOCK

#ln -sv ../vim/vim74/doc /usr/share/doc/vim-7.4

#rm -rf /sources/vim74

cat > /etc/vimrc << "EOF"
" Begin /etc/vimrc

set nocompatible
set backspace=2
syntax on
if (&term == "iterm") || (&term == "putty")
  set background=dark
endif

" End /etc/vimrc
EOF

vim -c ':options'

echo OK!
done > /tmp/msg

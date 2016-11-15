#!/bin/sh
#
# Ncurses
set -e
cd /sources
rm -rf e2fsprogs-1.42.12
tar -xvf e2fsprogs-1.42.12.tar.gz
cd e2fsprogs-1.42.12
sed -e '/int.*old_desc_blocks/s/int/blk64_t/' \
	-e '/if (old_desc_blocks/s/super->s_first_meta_bg/desc_blocks/' \
	-i lib/ext2fs/closefs.c
mkdir -v build
cd build

LIBS=-L/tools/lib					 \
CFLAGS=-I/tools/include 			 \
PKG_CONFIG_PATH=/tools/lib/pkgconfig \
../configure --prefix=/usr		     \
		     --bindir=/bin		     \
			 --with-root-prefix=""   \
			 --enable-elf-shlibs	 \
			 --disable-libblkid      \
			 --disable-libuuid		 \
			 --disable-uuidd	     \		
			 --disable-fsck

make -j 5
echo make_OK**********
:<<BLOCK
ln -sfv /tools/lib/lib{blk,uu}id.so.1 lib


make LD_LIBRARY_PATH=/tools/lib check
echo check_OK*********
make install
echo install_OK*******
make install-libs

chmod -v u+w /usr/lib/{libcom_err,libe2p,libext2fs,libss}.a

gunzip -v /usr/share/info/libext2fs.info.gz
install-info --dir-file=/usr/share/info/dir /usr/share/info/libext2fs.info

makeinfo -o 	 doc/com_err.info ../lib/et/com_err.texinfo
install -v -m644 doc/com_err.info /usr/share/info
install-info --dir-file=/usr/share/info/dir /usr/share/info/com_err.info

cd /sources
rm -rf e2fsprogs-1.42.12
BLOCK
echo OK!



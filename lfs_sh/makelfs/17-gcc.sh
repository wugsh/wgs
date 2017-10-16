#!/bin/sh
#
# GCC Pass 1
set -e
cd /sources
#rm -rf gcc-4.9.2 gcc-build
#tar -xvf gcc-4.9.2.tar.bz2
cd gcc-4.9.2
#mkdir -v ../gcc-build

cd ../gcc-build
:<<BLOCK
ED=sed						 \
../gcc-4.9.2/configure  	 \
	--prefix=/usr       	 \
	--enable-languages=c,c++ \
	--disable-multilib	     \
	--disable-bootstrap      \
	--with-system-zlib		 \
	--with-gmp=/tools 		 \
    --with-mpfr=/tools       \
    --with-lib-gmp=/tools/lib \
	--with-lib-mpfr=/tools/lib

make -j 4
ulimit -s 32768
make -k check

../gcc-4.9.2/contrib/test_summary
make install
BLOCK
#ln -sv ../../usr/bin/cpp /lib
#ln -sv gcc /usr/bin/cc

#install -v -dm755 /usr/lib/bfd-plugins
ln -sfv ../../libexec/gcc/$(gcc -dumpmachine)/4.9.2/liblto_plugin.so /usr/lib/bfd-plugins/
echo ln_OK****************
echo 'main(){}' > dummy.c
cc dummy.c -v -Wl,--verbose &> dummy.log
readelf -l a.out | grep ': /lib'
grep -o '/usr/lib.*/crt[1in].*succeeded' dummy.log

grep -B4 '^ /usr/include' dummy.log
grep 'SEARCH.*/usr/lib' dummy.log |sed 's|; |\n|g'
grep "/lib.*/libc.so.6 " dummy.log
grep found dummy.log
echo dummy_OK
rm -v dummy.c a.out dummy.log
mkdir -pv /usr/share/gdb/auto-load/usr/lib
mv -v /usr/lib/*gdb.py /usr/share/gdb/auto-load/usr/lib
cd /sources
#rm -rf gcc-4.9.2 gcc-build
echo OK!

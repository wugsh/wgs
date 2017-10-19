#!/bin/sh
#
# GCC Pass 2
set -e
cd $LFS/sources
#rm -rf gcc-4.9.2 gcc-build
#tar -xvf gcc-4.9.2.tar.bz2
cd gcc-4.9.2
#cat gcc/limitx.h gcc/glimits.h gcc/limity.h > \
 # `dirname $($LFS_TGT-gcc -print-libgcc-file-name)`/include-fixed/limits.h
#tar -xf ../mpfr-3.1.2.tar.xz
#mv -v mpfr-3.1.2 mpfr
#tar -xf ../gmp-6.0.0a.tar.xz
#mv -v gmp-6.0.0 gmp
#tar -xf ../mpc-1.0.2.tar.gz
#mv -v mpc-1.0.2 mpc
for file in \
 $(find gcc/config -name linux64.h -o -name linux.h -o -name sysv4.h)
do
  cp -uv $file $file.orig
  sed -e 's@/lib\(64\)\?\(32\)\?/ld@/tools&@g' \
      -e 's@/usr@/tools@g' $file.orig > $file
  echo '
#undef STANDARD_STARTFILE_PREFIX_1
#undef STANDARD_STARTFILE_PREFIX_2
#define STANDARD_STARTFILE_PREFIX_1 "/tools/lib/"
#define STANDARD_STARTFILE_PREFIX_2 ""' >> $file
  touch $file.orig
done
sed -i 's/if \((code.*))\)/if (\1 \&\& \!DEBUG_INSN_P (insn))/' gcc/sched-deps.c
mkdir -v ../gcc-build
cd ../gcc-build
CC=$LFS_TGT-gcc                                      \
CXX=$LFS_TGT-g++                                     \
AR=$LFS_TGT-ar                                       \
RANLIB=$LFS_TGT-ranlib                               \
../gcc-4.9.2/configure                               \
    --prefix=/tools                                  \
    --with-local-prefix=/tools                       \
    --with-native-system-header-dir=/tools/include   \
    --enable-languages=c,c++                         \
    --disable-libstdcxx-pch                          \
    --disable-multilib                               \
    --disable-bootstrap                              \
    --disable-libgomp
make -j 5
make install
cd $LFS/sources
rm -rf gcc-4.9.2 gcc-build
ln -sv gcc /tools/bin/cc
echo "######## TEST ########"
echo 'main(){}' > dummy.c
cc dummy.c
readelf -l a.out | grep ': /tools'
rm -v dummy.c a.out
echo "######################"
echo OK!

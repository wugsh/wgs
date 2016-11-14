
##1.创建新分区

将硬盘查到我的电脑名称是sdd（你的也能是sdd、sdc），我的盘只有8GB ，将盘分成4个区swap(1GB)、/(3GB)、/boot(100MB)、/home(剩余空间)

<pre><code>root@DSLAB-wgs:/home/wgs# fdisk /dev/sdd

Command (m for help): n
Partition type:
   p   primary (0 primary, 0 extended, 4 free)
   e   extended
Select (default p): p
Partition number (1-4, default 1): 
Using default value 1
First sector (2048-15630335, default 2048): 
Using default value 2048
Last sector, +sectors or +size{K,M,G} (2048-15630335, default 15630335): +1GB

Command (m for help): n
Partition type:
   p   primary (1 primary, 0 extended, 3 free)
   e   extended
Select (default p): p
Partition number (1-4, default 2): 
Using default value 2
First sector (1955173-15630335, default 1955173): 
Using default value 1955173
Last sector, +sectors or +size{K,M,G} (1955173-15630335, default 15630335): +3GB
Command (m for help): n
Partition type:
   p   primary (2 primary, 0 extended, 2 free)
   e   extended
Select (default p): p
Partition number (1-4, default 3): 
Using default value 3
First sector (7814548-15630335, default 7814548): 
Using default value 7814548
Last sector, +sectors or +size{K,M,G} (7814548-15630335, default 15630335): +100MB

Command (m for help): n
Partition type:
   p   primary (3 primary, 0 extended, 1 free)
   e   extended
Select (default e): p
Selected partition 4
First sector (8009861-15630335, default 8009861): 
Using default value 8009861
Last sector, +sectors or +size{K,M,G} (8009861-15630335, default 15630335): 
Using default value 15630335
Command (m for help): p

Disk /dev/sdd: 8002 MB, 8002732032 bytes
247 heads, 62 sectors/track, 1020 cylinders, total 15630336 sectors
Units = sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 512 bytes
I/O size (minimum/optimal): 512 bytes / 512 bytes
Disk identifier: 0x6f20736b

   Device Boot      Start         End      Blocks   Id  System
/dev/sdd1            2048     1955172      976562+  83  Linux
/dev/sdd2         1955173     7814547     2929687+  83  Linux
/dev/sdd3         7814548     8009860       97656+  83  Linux
/dev/sdd4         8009861    15630335     3810237+  83  Linux

Command (m for help): w
The partition table has been altered!

Calling ioctl() to re-read partition table.
Syncing disks.
</code></pre>

##2.在分区上创建文件系统

<pre><code>root@DSLAB-wgs:/home/wgs# mkswap /dev/sdd1                  (sdd1=swap, sdd2=/, sdd3=/boot, sdd4=/home)
Setting up swapspace version 1, size = 976556 KiB
no label, UUID=41367752-4192-42d6-ae00-af06a8bc34dd

root@DSLAB-wgs:/home/wgs# mkfs -v -t ext4 /dev/sdd2  
</code></pre>

##3.挂载文件系统

<pre><code>root@DSLAB-wgs:/home/wgs# export LFS=/mnt/lfs
root@DSLAB-wgs:/home/wgs# mkdir -pv $LFS
mkdir: created directory ‘/mnt/lfs’

root@DSLAB-wgs:/home/wgs# mount -v -t ext4 /dev/sdd2 $LFS
/dev/sdd2 on /mnt/lfs type ext4 (rw)

root@DSLAB-wgs:/home/wgs# mkdir -v $LFS/boot
mkdir: created directory ‘/mnt/lfs/boot’
root@DSLAB-wgs:/home/wgs# mount -v -t ext4 /dev/sdd3 $LFS/boot
/dev/sdd3 on /mnt/lfs/boot type ext4 (rw)
root@DSLAB-wgs:/home/wgs# mkdir -v $LFS/home
mkdir: created directory ‘/mnt/lfs/home’
root@DSLAB-wgs:/home/wgs# mount -v -t ext4 /dev/sdd4 $LFS/home
/dev/sdd4 on /mnt/lfs/home type ext4 (rw)

****启用交换分区****
root@DSLAB-wgs:/home/wgs# /sbin/swapon -v /dev/sdd1
swapon on /dev/sdd1
swapon: /dev/sdd1: found swap signature: version 1, page-size 4, same byte order
swapon: /dev/sdd1: pagesize=4096, swapsize=999997440, devsize=1000000000
</code></pre>

##4.软件包

<pre><code>root@DSLAB-wgs:~# mkdir -v $LFS/sources
mkdir: created directory ‘/mnt/lfs/sources’

root@DSLAB-wgs:~# mkdir -v $LFS/tools
mkdir: created directory ‘/mnt/lfs/tools’
root@DSLAB-wgs:~# ln -sv $LFS/tools /
‘/tools’ -> ‘/mnt/lfs/tools’

root@DSLAB-wgs:~# chown -v lfs $LFS/tools
changed ownership of ‘/mnt/lfs/tools’ from root to lfs
root@DSLAB-wgs:/mnt/lfs/sources# chown -v lfs $LFS/sources/
changed ownership of ‘/mnt/lfs/sources/’ from root to lfs

root@DSLAB-wgs:/mnt/lfs/sources# su - lfs

lfs@DSLAB-wgs:~$ cat > ~/.bash_profile << "EOF"
> exec env -i HOME=$HOME TERM=$TERM PS1='\u:\w\$ ' /bin/bash
> EOF
lfs@DSLAB-wgs:~$ cat > ~/.bashrc << "EOF"
> set +h
> umask 022
> LFS=/mnt/lfs
> LC_ALL=POSIX
> LFS_TGT=$(uname -m)-lfs-linux-gnu
> PATH=/tools/bin:/bin:/usr/bin
> export LFS LC_ALL LFS_TGT PATH
> EOF



lfs@DSLAB-wgs:/mnt/lfs/sources$ tar jxvf binutils-2.25.tar.bz2
lfs@DSLAB-wgs:/mnt/lfs/sources/binutils-2.25$ mkdir -v ../binutils-build
mkdir: created directory '../binutils-build'

lfs@DSLAB-wgs:/mnt/lfs/sources/binutils-2.25$ cd ../binutils-build

../binutils-2.25/configure\
--prefix=/tools           \ 
--with-sysroot=$LFS	  \
--with-lib-path=/tools/lib\
--target=$LFS_TGT	  \
--disable-nls		  \	
--disable-werror

lfs@DSLAB-wgs:/mnt/lfs/sources/binutils-build$ make

case $(uname -m) in
x86_64) mkdir -v /tools/lib && ln -sv lib /tools/lib64 ;;
esac

lfs@DSLAB-wgs:/mnt/lfs/sources/gcc$ tar -xf ../mpfr-3.1.2
mpfr-3.1.2-upstream_fixes-3.patch  mpfr-3.1.2.tar.xz
lfs@DSLAB-wgs:/mnt/lfs/sources/gcc$ tar -xf ../mpfr-3.1.2.tar.xz 
lfs@DSLAB-wgs:/mnt/lfs/sources/gcc$ mv -v mpfr-3.1.2 mpfr
'mpfr-3.1.2' -> 'mpfr'
lfs@DSLAB-wgs:/mnt/lfs/sources/gcc$ tar -xf ../gmp-6.0.0a.tar.xz 
lfs@DSLAB-wgs:/mnt/lfs/sources/gcc$ mv -v gmp-6.0.0 gmp
'gmp-6.0.0' -> 'gmp'
lfs@DSLAB-wgs:/mnt/lfs/sources/gcc$ tar -xf ../mpc-1.0.2.tar.gz 
lfs@DSLAB-wgs:/mnt/lfs/sources/gcc$ mv -v mpc-1.0.2 mpc
'mpc-1.0.2' -> 'mpc'

lfs@DSLAB-wgs:/mnt/lfs/sources/gcc$ for file in $(find gcc/config -name linux64.h -o -name linux.h -o -name sysv4.h)                        
> do 
> cp -uv $file{,.orig}
> sed -e 's@/lib\(64\)\?\(32\)\?/ld@/tools&@g' \
> -e 's@/usr@/tools@g' $file.orig > $file
> echo '
> \#undef STANDARD_STARTFILE_PREFIX_1
> \#undef STANDARD_STARTFILE_PREFIX_2
> \#define STANDARD_STARTFILE_PREFIX_1 "/tools/lib/"
> \#define STANDARD_STARTFILE_PREFIX_2 ""' >> $file
> touch $file.orig
> done

lfs@DSLAB-wgs:/mnt/lfs/sources/gcc$ sed -i '/k prot/agcc_cv_libc_provides_ssp=yes' gcc/configure


lfs@DSLAB-wgs:/mnt/lfs/sources/gcc$mkdir -v ../gcc-build
lfs@DSLAB-wgs:/mnt/lfs/sources/gcc$cd ../gcc-build

../gcc-4.9.2/configure \ 
--target=$LFS_TGT  \ 
--prefix=/tools \ 
--with-sysroot=$LFS \
--with-newlib       \
--without-headers   \
--with-local-prefix=/tools \
--with-native-system-header-dir=/tools/include \
--disable-nls \
--disable-shared\
--disable-multilib\
--disable-decimal-float\
--disable-threads\
--disable-libatomic\
--disable-libgomp\
--disable-libitm\
--disable-libquadmath\
--disable-libsanitizer\
--disable-libssp\
--disable-libvtv\
--disable-libcilkrts\
--disable-libstdc++-v3\
--enable-languages=c,c++

lfs@DSLAB-wgs:make 


编译gcc出现错误：checking for suffix of object files... configure: error: in `/mnt/lfs/sources/gcc-build/x86_64-lfs-linux-gnu/libgcc':

configure: error: cannot compute suffix of object files: cannot compile

</code></pre>








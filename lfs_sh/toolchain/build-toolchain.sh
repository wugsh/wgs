#!/bin/sh
set -e
CWD=$(pwd)
export LFS=/mnt/lfs

# Clean start
if grep -q /mnt/lfs/boot /proc/mounts; then
  umount /mnt/lfs/boot
fi

if grep -q /mnt/lfs /proc/mounts; then
  umount /mnt/lfs
fi

if [[ $(swapon -s | grep -ci "/dev") -gt 0 ]]; then
  swapoff /dev/sda2
fi

rm -f /tools

# Create filesystems
mkfs -v -t ext2 /dev/sda1
mkswap /dev/sda2
mkfs -v -t ext4 /dev/sda3

# Mount filesystems
mount -v -t ext4 /dev/sda3 $LFS
mkdir -v $LFS/boot
mount -v -t ext2 /dev/sda1 $LFS/boot

# Activate swap partition
swapon -v /dev/sda2

# Placeholder for source archives and patches
mkdir -v $LFS/sources

# Toolchain programs will be installed here
mkdir -v $LFS/tools
ln -sv $LFS/tools /

# Set up a good working environment
cat > ~/.bash_profile << "EOF"
exec env -i HOME=$HOME TERM=$TERM PS1='\u:\w\$ ' /bin/bash
EOF

cat > ~/.bashrc << "EOF"
set +h
umask 022
LFS=/mnt/lfs
LC_ALL=POSIX
LFS_TGT=$(uname -m)-lfs-linux-gnu
PATH=/tools/bin:/usr/sbin:/sbin:/usr/bin:/bin
export LFS LC_ALL LFS_TGT PATH
# Colored output for 'ls'
eval `dircolors -b`
alias ls='ls --color=auto'

# Some handy aliases
alias ll='ls -al'
alias ..='cd ..'
alias ...='cd ../..'
alias cp='cp -i'
alias rm='rm -i'
alias mv='mv -i'
alias vi='vim'

# Coloured command prompt
WHITE='\[\033[1;37m\]'
RED='\[\033[0;33m\]'
NC='\[\033[0m\]'
PS1="$RED[$WHITE\u$NC@$WHITE\h$NC:$WHITE\W$RED] #$NC "

# Vim is our preferred editor
EDITOR=vim
VISUAL=$EDITOR
export EDITOR VISUAL
EOF

source ~/.bash_profile


#!/bin/sh
set -e
cat > /boot/grub/grub.cfg << "EOF"
# Begin /boot/grub/grub.cfg
set default=0
set timeout=5
insmod ext2
set root=(hd1,msdos3)
menuentry "GNU/Linux, Linux 3.19-lfs-7.7-systemd" {
linux /boot/vmlinuz-3.19-lfs-7.7-systemd root=/dev/sdb3 ro
}
EOF

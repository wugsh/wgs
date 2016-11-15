#!/bin/sh
set -e

cat > /etc/fstab << "EOF"
# Begin /etc/fstab

/dev/sdb2      /           ext4         defaults       1           1
/dev/sdb3	   /boot	   ext4 		defaults		0		   2
/dev/sdb4	   /home	   ext4			defaults		0		   2
/dev/sdb1      swap        swap          pri=1          0          0

# End /etc/fstab
EOF

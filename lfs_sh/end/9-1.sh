#!/bin/sh
set -e
cat > /etc/os-release << "EOF"
NAME="Linux From Scratch"
VERSION="7.7-systemd"
ID=lfs
PRETTY_NAME="Linux From Scratch 7.7-systemd"
EOF

echo 7.7-systemd > /etc/lfs-release

cat > /etc/lsb-release << "EOF"
DISTRIB_ID="Linux From Scratch"
DISTRIB_RELEASE="7.7-systemd"
DISTRIB_CODENAME="Dslab"
DISTRIB_DESCRIPTION="Linux From Scratch"
EOF
echo OK!

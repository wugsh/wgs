#!/bin/sh
set -e
mkdir -pv /etc/systemd/system/getty@tty1.service.d
cat > /etc/systemd/system/getty@tty1.service.d/noclear.conf << EOF
[Service]
TTYVTDisallocate=no
EOF

ln -sfv /dev/null /etc/systemd/system/tmp.mount

mkdir -pv /etc/systemd/system/foobar.service.d
cat > /etc/systemd/system/foobar.service.d/foobar.conf << EOF
[Service]
Restart=always
RestartSec=30
EOF

echo OK!

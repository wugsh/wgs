#!/bin/sh
set -e
cat > /etc/adjtime << "EOF"
0.0 0 0.0
0
LOCAL
EOF

#timedatectl set-local-rtc 1
echo OK!*********

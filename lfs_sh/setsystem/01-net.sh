#!/bin/sh
set -e
:<<BLOCK
cd / 
cat > /etc/systemd/network/10-static-eth0.network << "EOF"
[Match]
Name=eth0

[Network]
Address=192.168.0.2/24
Gateway=192.168.0.1
DNS=192.168.0.1
EOF
echo static-eth0.network_OK**********

cat > /etc/systemd/network/10-dhcp-eth0.network << "EOF"
[Match]
Name=eth0

[Network]
DHCP=yes
EOF
echo DHCP_OK*********
cat > /etc/resolv.conf << "EOF"
# Begin /etc/resolv.conf
#domain <Your Domain Name>
search dslab lzu.edu.cn
nameserver  202.201.0.131
nameserver  202.201.0.132
#nameserver  223.5.5.5
# End /etc/resolv.conf
EOF


ln -sfv /run/systemd/resolve/resolv.conf /etc/resolv.conf
echo resolv.conf_OK**************
BLOCK
echo ******7.2.3*****
echo "<lfs>" > /etc/hostname

cat > /etc/hosts << "EOF"
# Begin /etc/hosts (network card version)
127.0.0.1 localhost
::1		  localhost
127.0.1.1 debian.lzu.edu.cn  debian

# End /etc/hosts (network card version)
EOF
echo hosts_OK***********



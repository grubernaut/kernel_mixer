#!/usr/bin/env bash

PROFILE=/home/vagrant/.profile
apt-get update
apt-get install -y libgmp3-dev libmpfr-dev libisl-dev libcloog-isl-dev libmpc-dev vim

su vagrant
mkdir -p /home/vagrant/opt/cross/bin
echo "export PREFIX="/home/vagrant/opt/cross"" >> $PROFILE
echo "export TARGET=i686-elf" >> $PROFILE
echo "export PATH="/home/vagrant/opt/cross/bin:$PATH"" >> $PROFILE

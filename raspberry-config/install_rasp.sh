#! /bin/bash

sudo apt update -y
sudo apt upgrade -y
sudo apt install bossa bossa-cli -y
sudo apt install default-jre default-jdk -y
sudo apt install gcc make cmake dkms gcc-arm-none-eabi -y
sudo apt install automake autoconf build-essential texinfo libtool libftdi-dev -y
sudo apt install libusb-dev libusb-1.0-0 libusb-1.0-0-dev -y
sudo apt install git net-tools ht cutecom minicom putty socat unzip transmission gparted nmap -y
sudo apt install python3-pip -y

# sudo apt install gpsd gpsd-clients -y
# sudo systemctl stop gpsd.socket
# sudo systemctl disable gpsd.socket
# sudo gpsd /dev/ttyACM1 -F /var/run/gpsd.sock
# sudo systemctl stop serial-getty@serial0.service

# sudo apt install apache2 install php php-mbstring -y

# pip3 install websockets
pip3 install pyserial

# mkdir -p $HOME/.local/opt
# cd $HOME/.local/opt
# wget https://raw.githubusercontent.com/raspberrypi/pico-setup/master/pico_setup.sh
# chmod +x pico_setup.sh
# ./pico_setup.sh

# cd pico/openocd
# ./bootstrap
# ./configure --enable-ftdi --enable-sysfsgpio --enable-bcm2835gpio
# make -j3
# sudo make install

# cd $HOME


sudo apt autoclean
sudo apt autoremove



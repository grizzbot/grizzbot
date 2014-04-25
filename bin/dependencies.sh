#!/bin/bash
# taken from: https://shanetully.com/2011/11/making-the-irobot-create-command-module-play-nicely-with-linux/

install_rh()
{
    sudo yum install avrdude avr-gcc avr-gcc-c++ avr-libc avarice simulavr
}

install_ubuntu()
{
    sudo apt-get install avrdude avr-libc gcc-avr avarice simulavr
}

cat /etc/redhat-release && install_rh || install_ubuntu

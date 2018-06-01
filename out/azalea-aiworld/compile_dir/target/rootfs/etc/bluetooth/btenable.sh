#!/bin/ash
# $1: on or off

BSA_SERVER=/usr/bin/bsa_server

bt_on()
{
  echo 0 > /sys/class/rfkill/rfkill0/state
  sleep 1
  echo 1 > /sys/class/rfkill/rfkill0/state
  sleep 1

  $BSA_SERVER -all=0 -d$1 -p/lib/firmware/bcm43438a0.hcd -r12 &
  sleep 2
}

bt_off()
{
  killall bsa_server
  sleep 1

  echo 0 > /sys/class/rfkill/rfkill0/state
}

if [ "$1" = "on" ]; then
    echo "turn on bt"
    bt_on $2
else
    if [ "$1" = "off" ]; then
        echo "turn off bt"
        bt_off
    else
        echo "no paras"
        exit 1
    fi
fi

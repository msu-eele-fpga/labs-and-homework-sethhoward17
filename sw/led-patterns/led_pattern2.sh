#!/bin/bash
HPS_LED_CONTROL="/sys/devices/platform/ff200000.led_patterns/hps_led_control"
BASE_PERIOD="/sys/devices/platform/ff200000.led_patterns/base_period"
LED_REG="/sys/devices/platform/ff200000.led_patterns/led_reg"

# Enable software-control mode
echo 1 > $HPS_LED_CONTROL

while true
do
    # Custom LED pattern
    echo 1 > $HPS_LED_CONTROL
    echo 0x08 > $LED_REG
    sleep 0.25
    echo 0x14 > $LED_REG
    sleep 0.25
    echo 0x22 > $LED_REG
    sleep 0.25
    echo 0x41 > $LED_REG
    sleep 0.25
    echo 0x08 > $LED_REG
    sleep 0.25
    echo 0x14 > $LED_REG
    sleep 0.25
    echo 0x22 > $LED_REG
    sleep 0.25
    echo 0x41 > $LED_REG
    sleep 0.25
    echo 0x08 > $LED_REG
    sleep 0.25
    echo 0x14 > $LED_REG
    sleep 0.25
    echo 0x22 > $LED_REG
    sleep 0.25
    echo 0x41 > $LED_REG
    sleep 0.25

    # Hardware control mode
    echo 0 > $HPS_LED_CONTROL
    echo 0x07 > $BASE_PERIOD
    sleep 2
    echo 0x04 > $BASE_PERIOD
    sleep 2
    echo 0x01 > $BASE_PERIOD
    sleep 2

done
# Pico TinyUSB Keyboard

This is an adapted copy of the hid_composite example from [TinyUSB](https://github.com/hathach/tinyusb/tree/master/examples/device/hid_composite) showing how to build with TinyUSB when using the Raspberry Pi Pico SDK.

This repository optimizes the REPORT_ID_KEYBOARD reports. In `keyboard.h` a USB HID Keyboard report is created from pin inputs on the Pico. 

## Getting started

See [Getting Started with the Raspberry Pi Pico](https://rptl.io/pico-get-started) and the README in the [pico-sdk](https://github.com/raspberrypi/pico-sdk) for information on getting up and running.

If the pico-sdk is in your $PATH, you can keep this repository anywhere.

### Keyboard

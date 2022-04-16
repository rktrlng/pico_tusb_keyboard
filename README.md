# Pico TinyUSB Keyboard

USB HID Keyboard for Pico RP2040 with TinyUSB.

This is an adapted copy of the hid_composite example from [TinyUSB](https://github.com/hathach/tinyusb/tree/master/examples/device/hid_composite) showing how to build with TinyUSB when using the Raspberry Pi Pico SDK. This repository optimizes the REPORT_ID_KEYBOARD reports.

### Keyboard

In `keyboard.h` a USB HID Keyboard report is created from pin inputs on the Pico. 

Connect pins to keys:
```c++
const static int num_pins = 2; // max 32 pins (state is uint32_t)
const PinKey pin_keys[num_pins] = { // connect pin to keycode
	{ 16, HID_KEY_A },
	{ 17, HID_KEY_ENTER }
};
```

## Getting started

See [Getting Started with the Raspberry Pi Pico](https://rptl.io/pico-get-started) and the README in the [pico-sdk](https://github.com/raspberrypi/pico-sdk) for information on getting up and running.

If the pico-sdk is in your $PATH, you can keep this repository anywhere. Cmake will probably find it.

## Compiling and uploading

Insert the Pico with the BOOTSEL button pressed. After it's mounted:

```bash
./upload
```

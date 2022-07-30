/**
 * @file keyboard.h
 * @author @rktrlng
 * @brief create USB HID keycodes from pin inputs
 * @see https://github.com/rktrlng/pico_tusb_keyboard
 */

#ifndef KEYS_H
#define KEYS_H

#include "hardware/gpio.h" // gpio_*
#include "class/hid/hid.h" // HID_KEY_*

struct PinKey
{
	const uint8_t pin; // pico pin number
	const uint8_t key; // HID_KEY_*
};

class KeyBoard
{
private:
	// ===========================================================================
	// set these values to your situation
	const static size_t num_pins = 26;
	const PinKey pin_keys[num_pins] = { // map gpio pin to keycode
		{0, HID_KEY_1},             // 1 player
		{1, HID_KEY_5},             // coin slot 1
		{2, HID_KEY_ARROW_UP},
		{3, HID_KEY_ARROW_DOWN},
		{4, HID_KEY_ARROW_LEFT},
		{5, HID_KEY_ARROW_RIGHT},
		{6, HID_KEY_E},             // up (left stick)
		{7, HID_KEY_D},             // down (left stick)
		{8, HID_KEY_S},             // left (left stick)
		{9, HID_KEY_F},             // right (left stick)
		{10, HID_KEY_I},            // up (right stick)
		{11, HID_KEY_K},            // down (right stick)
		{12, HID_KEY_J},            // left (right stick)
		{13, HID_KEY_L},            // right (right stick)
		{14, HID_KEY_CONTROL_LEFT}, // button 1
		{15, HID_KEY_ALT_LEFT},     // button 2
		{16, HID_KEY_SPACE},        // button 3
		{17, HID_KEY_SHIFT_LEFT},   // button 4
		{18, HID_KEY_Z},            // button 5
		{19, HID_KEY_X},            // button 6
		{20, HID_KEY_C},            // button 7
		{21, HID_KEY_V},            // button 8
		{22, HID_KEY_ENTER},        // select
		{26, HID_KEY_ESCAPE},       // back
		{27, HID_KEY_SHIFT_RIGHT},
		{28, HID_KEY_BACKSPACE}
	};
	// ===========================================================================

public:
	uint8_t key_codes[6] = {0}; // we can send max 6 keycodes per hid-report

	KeyBoard()
	{
		// set all pins to pulled up inputs
		for (size_t i = 0; i < num_pins; i++)
		{
			gpio_init(pin_keys[i].pin);
			gpio_pull_up(pin_keys[i].pin);
			gpio_set_dir(pin_keys[i].pin, GPIO_IN);
		}
	}

	virtual ~KeyBoard() {}

	bool update()
	{
		// clear keycodes
		for (size_t i = 0; i < 6; i++)
		{
			key_codes[i] = 0;
		}

		// read pins and set max 6 keycodes
		uint8_t index = 0;
		bool changed = false;
		for (size_t i = 0; i < num_pins; i++)
		{
			int pin_state = gpio_get(pin_keys[i].pin); // read pin for this key
			if (pin_state == 0) // pressed
			{
				key_codes[index] = pin_keys[i].key; // set keycode
				changed = true;
				index++;
				if (index >= 6) // max is 6 key presses
				{
					break;
				}
			}
		}

		return changed;
	}
};

#endif /* KEYS_H */

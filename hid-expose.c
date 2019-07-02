/*
 *  HID driver that exposes all keys of the device it is bound to.
 */
/*
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 */
#include <linux/hid.h>
#include <linux/module.h>
static int exp_input_mapping(struct hid_device *hdev, struct hid_input *hi,
		struct hid_field *field, struct hid_usage *usage,
		unsigned long **bit, int *max)
{
        hid_map_usage_clear(hi, usage, bit, max, EV_KEY, KEY_UNKNOWN);
        return 0; /* Continue mapping standard keys */
}
static const struct hid_device_id exp_devices[] = { { } };
MODULE_DEVICE_TABLE(hid, exp_devices);
static struct hid_driver exp_driver = {
	.name = "expose",
	.id_table = exp_devices,
	.input_mapping = exp_input_mapping,
};
module_hid_driver(exp_driver);
MODULE_LICENSE("GPL");

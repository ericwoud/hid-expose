# Expose all HID keystrokes. 

Sometimes HID keystrokes do not get through, not even to evtest. This will help.

Expose for example Red, Green, Yellow and Blue buttons or Mp3, Tv, Media, Video, Camera and Tv2 buttons.

Tested up to Ubuntu 17.10.

This example is for the MS-Tech 1200 Remote, vendor=1d57 product=ac01. For other keyboards/remotes adjust the vendor and product values accordingly in the .rules and .hwdb file. Do not change caps.

Use evtest to get keycodes.

### Installing

```
git clone https://github.com/ericwoud/hid-expose.git
sudo apt-get install evtest build-essential linux-headers-$(uname -r)
cd hid-expose/
make
sudo mkdir /lib/modules/$(uname -r)/extra
sudo cp hid-expose.ko /lib/modules/$(uname -r)/extra/
sudo depmod -a
 
sudo cp 10-hid-expose.rules /etc/udev/rules.d/
sudo udevadm control --reload-rules

sudo cp 10-keyboard.hwdb /etc/udev/hwdb.d/
sudo udevadm -d hwdb --update
sudo udevadm -d trigger -v
```

Restart if necessary.


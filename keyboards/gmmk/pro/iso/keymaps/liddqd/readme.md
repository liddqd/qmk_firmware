# liddqd's gmmk pro config

- continued experimentation with debounce 5ms -> 10ms -> 16ms
	- moved config from keyboards/gmmk/pro/config.h to keymap/config.h
	- using *asym_eager_defer_pk* mixed algo in rules.mk, instead of default *sym_defer_pk*
- capslock indicators, set edit + modifier keys to red
- fn/mo(1) turn off alphas, set hotkeys to cyan
- bootloader/RESET = fn/mo(1)+b
	- bootloader/RESET set all rgb to red
- clear eeprom esc on boot

# gmmk board assembled as of 2021/11
![laser pewpew, no led](images/image1.jpg)
![laser pewpew, w led](images/image2.jpg)

# gmmk board assembled as of 2021/10
![gmmk pro assembled](images/assembled.jpg)

# pictures of pcb
![pcb #1](images/pcb1.jpg)
![pcb #2](images/pcb2.jpg)
![pcb #3](images/pcb3.jpg)
![pcb #4](images/pcb4.jpg)

# Tetris GBA

A simple port of Tetris to the Game Boy Advance.

`.gba` files can be found under the releases section.

## Build Instructions

Instructions are for Ubuntu 18.04.

### Dependencies

This project requires Brandon Whitehead's PPA. 

    $ sudo add-apt-repository ppa:tricksterguy87/ppa-gt-cs2110
    $ sudo apt install gcc-arm-none-eabi cs2110-vbam-sdl mednafen cs2110-gba-linker-script nin10kit
    
### Build

    $ make

# kColorPicker [![Build Status](https://travis-ci.org/DamirPorobic/kColorPicker.svg?branch=master)](https://travis-ci.org/DamirPorobic/kColorPicker)
QToolButton with color popup menu with lets you select a color. The popup featues a color dialog button which can be used to add custom colors to the popup menu.

Version 0.0.1

The tool is currently work in Progress

![kImageAnnotator](https://i.imgur.com/VkhUvFa.png "kColorPicker")

### Building from source
1. Get latest release from GitHub by cloning the repo:  
    `$ git clone https://github.com/DamirPorobic/kColorPicker`
2. Change to repo directory:  
    `$ cd kColorPicker`    
3. Make new build directory and enter it:  
    `$ mkdir build`  
    `$ cd build`  
4. Create the makefile and build the project:  
    `$ cmake ..`  
    `$ make`
5. Install shared library (not required when only using the example):  
    `$ sudo make install`
6. Run the example application:  
    `$ ./example/kColorPicker-example`

# kColorPicker [![Build Status][github-badge]][github-url]
QToolButton with color popup menu with lets you select a color. The popup features a color dialog button which can be used to add custom colors to the popup menu.

Version 0.3.1

![kColorPicker](https://i.imgur.com/VkhUvFa.png "kColorPicker")

### Building from source
1. Get the latest release from GitHub by cloning the repo:  
    `$ git clone https://github.com/ksnip/kColorPicker`
2. Change to repo directory:  
    `$ cd kColorPicker`  
3. Make new build directory and enter it:  
    `$ mkdir build && cd build`  
4. Create the makefile and build the project:  
    `$ cmake .. && make`  
    to build with Qt6, pass `-DBUILD_WITH_QT6=true` to the `cmake` command  
5. Install shared library (not required when only using the example):  
    `$ sudo make install`  
6. Run the example application:  
    `$ ./example/kColorPicker-example`  


### Shared vs Static
You can either build the project as shared library by providing the flag `-DBUILD_SHARED_LIBS=ON`
to cmake or `-DBUILD_SHARED_LIBS=OFF` to build as static library. On Windows we currently can
only build as static library.


### Integrate library in project

1. Let cmake find the shared library, optionally with version  
    `set(KCOLORPICKER_MIN_VERSION "0.x.x")`  
    to build with Qt5:  
    `find_package(kColorPicker-Qt5 ${KCOLORPICKER_MIN_VERSION} REQUIRED)`  
    to build with Qt6:  
    `find_package(kColorPicker-Qt6 ${KCOLORPICKER_MIN_VERSION} REQUIRED)`  

2. Link the library with your application 
    `target_link_libraries(myApp kColorPicker)`  


[github-badge]:        https://github.com/ksnip/kColorPicker/actions/workflows/build.yml/badge.svg
[github-url]:          https://github.com/ksnip/kColorPicker/actions

set(UnitTests
        buttons/ColorButtonTest.cpp
        )

add_library(kColorPickerStatic STATIC ${kcolorpicker_SRCS})

target_link_libraries(kColorPickerStatic Qt5::Widgets kColorPicker)

foreach (UnitTest ${UnitTests})
    get_filename_component(UnitTestName ${UnitTest} NAME_WE)
    add_executable(${UnitTestName} ${UnitTest})
    target_link_libraries(${UnitTestName} kColorPickerStatic Qt5::Test)
    add_test(${UnitTestName} ${UnitTestName})
endforeach (UnitTest)
set(UNITTEST_SRC
        buttons/ColorButtonTest.cpp
        )

add_library(KCOLORPICKER_STATIC STATIC ${KCOLORPICKER_SRCS})

target_link_libraries(KCOLORPICKER_STATIC Qt${QT_MAJOR_VERSION}::Widgets kColorPicker)

foreach (UnitTest ${UNITTEST_SRC})
    get_filename_component(UnitTestName ${UnitTest} NAME_WE)
    add_executable(${UnitTestName} ${UnitTest})
    target_link_libraries(${UnitTestName} KCOLORPICKER_STATIC Qt${QT_MAJOR_VERSION}::Test)
    add_test(${UnitTestName} ${UnitTestName})
endforeach (UnitTest)

set(kcolorpicker_SRCS
        ${CMAKE_SOURCE_DIR}/src/KColorPicker.cpp
        ${CMAKE_SOURCE_DIR}/src/PopupMenu.cpp
        ${CMAKE_SOURCE_DIR}/src/IconCreator.cpp
        ${CMAKE_SOURCE_DIR}/src/buttons/AbstractPopupMenuButton.cpp
        ${CMAKE_SOURCE_DIR}/src/buttons/ColorButton.cpp
        ${CMAKE_SOURCE_DIR}/src/buttons/ColorDialogButton.cpp
        )

set(kcolorpicker_SRCS ${kcolorpicker_SRCS} PARENT_SCOPE)

add_library(kColorPicker SHARED
        ${kcolorpicker_SRCS}
        ${CMAKE_SOURCE_DIR}/include/kColorPicker/KColorPicker.h
        ${CMAKE_SOURCE_DIR}/icons/kColorPicker_icons.qrc
        )

add_library(kColorPicker::kColorPicker ALIAS kColorPicker)

target_include_directories(kColorPicker
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
        )

target_link_libraries(kColorPicker PUBLIC Qt5::Widgets)

target_compile_definitions(kColorPicker PRIVATE KIMAGEANNOTATOR_LIB)

set_target_properties(kColorPicker
        PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
		SOVERSION ${PROJECT_VERSION}
        )

install(TARGETS kColorPicker
        EXPORT kColorPicker-targets
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        )

install(DIRECTORY ${CMAKE_SOURCE_DIR}/include/kColorPicker
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
        )

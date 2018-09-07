cmake_minimum_required(VERSION 3.5)
project(kColorPicker LANGUAGES CXX VERSION 0.0.1)

set(QT_MIN_VERSION "5.6.1")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 ${QT_MIN_VERSION} REQUIRED Widgets Test)

include(GNUInstallDirs)
include(FeatureSummary)

add_subdirectory(src)

enable_testing()
add_subdirectory(tests)

add_subdirectory(example)

include(CMakePackageConfigHelpers)

configure_package_config_file(${CMAKE_SOURCE_DIR}/cmake/kColorPickerConfig.cmake.in
                              ${CMAKE_BINARY_DIR}/cmake/kColorPickerConfig.cmake
                              INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/kColorPicker
                              )

write_basic_package_version_file(${CMAKE_BINARY_DIR}/cmake/kColorPickerConfig-version.cmake
                                 VERSION ${PROJECT_VERSION}
                                 COMPATIBILITY AnyNewerVersion
                                 )

install(FILES
        ${CMAKE_BINARY_DIR}/cmake/kColorPickerConfig.cmake
        ${CMAKE_BINARY_DIR}/cmake/kColorPickerConfig-version.cmake
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/kColorPicker
        )


export(EXPORT kColorPicker-targets
       FILE ${CMAKE_BINARY_DIR}/cmake/kColorPicker-targets.cmake
       NAMESPACE kColorPicker::
       )

install(EXPORT kColorPicker-targets
        FILE kColorPicker-targets.cmake
        NAMESPACE kColorPicker::
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/kColorPicker
        )
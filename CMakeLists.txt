cmake_minimum_required(VERSION 3.5)
project(kColorPicker LANGUAGES CXX VERSION 0.1.6)

set(QT_MIN_VERSION "5.9.4")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

option(BUILD_TESTS "Build Unit Tests" OFF)
option(BUILD_EXAMPLE "Build Example Application" ON)

find_package(Qt5 ${QT_MIN_VERSION} REQUIRED Widgets)

include(GNUInstallDirs)
include(FeatureSummary)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(src)

if (BUILD_EXAMPLE)
    add_subdirectory(example)
endif (BUILD_EXAMPLE)

if (BUILD_TESTS)
    find_package(Qt5 ${QT_MIN_VERSION} REQUIRED Test)
    enable_testing()
    add_subdirectory(tests)
endif (BUILD_TESTS)

include(CMakePackageConfigHelpers)

add_library(kColorPicker
			${KCOLORPICKER_SRCS}
			${CMAKE_CURRENT_SOURCE_DIR}/include/kColorPicker/KColorPicker.h
			${CMAKE_CURRENT_SOURCE_DIR}/icons/kColorPicker_icons.qrc
			)

add_library(kColorPicker::kColorPicker ALIAS kColorPicker)

target_include_directories(kColorPicker
						   PUBLIC
						   $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
						   $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>
						   $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
						   )

target_link_libraries(kColorPicker PUBLIC Qt5::Widgets)

target_compile_definitions(kColorPicker PRIVATE KIMAGEANNOTATOR_LIB)

set_target_properties(kColorPicker
					  PROPERTIES
					  ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib
					  LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib
					  RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin
		 			  VERSION ${PROJECT_VERSION}
					  SOVERSION 0
					  )

install(TARGETS kColorPicker
		EXPORT kColorPicker-targets
		ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
		LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
		RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
		)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/kColorPicker
		DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
		)

configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/cmake/kColorPickerConfig.cmake.in
                              ${CMAKE_CURRENT_BINARY_DIR}/cmake/kColorPickerConfig.cmake
                              INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/kColorPicker
                              )

write_basic_package_version_file(${CMAKE_CURRENT_BINARY_DIR}/cmake/kColorPickerConfig-version.cmake
                                 VERSION ${PROJECT_VERSION}
                                 COMPATIBILITY AnyNewerVersion
                                 )

install(FILES
        ${CMAKE_CURRENT_BINARY_DIR}/cmake/kColorPickerConfig.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/cmake/kColorPickerConfig-version.cmake
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/kColorPicker
        )


export(EXPORT kColorPicker-targets
       FILE ${CMAKE_CURRENT_BINARY_DIR}/cmake/kColorPicker-targets.cmake
       NAMESPACE kColorPicker::
       )

install(EXPORT kColorPicker-targets
        FILE kColorPicker-targets.cmake
        NAMESPACE kColorPicker::
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/kColorPicker
        )
        
# uninstall target
if(NOT TARGET uninstall)
    configure_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/cmake/cmake_uninstall.cmake.in"
        "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
        IMMEDIATE @ONLY)

    add_custom_target(uninstall COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake)
endif()


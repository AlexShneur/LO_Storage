cmake_minimum_required(VERSION 3.12)

project(LO_Storage VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
		
		dialogpullfile.cpp
		dialogpullfile.h
		dialogpullfile.ui
		
		dialogpushfile.cpp
		dialogpushfile.h
		dialogpushfile.ui
		
		pgconnection.cpp
		pgconnection.h
		pgoperations.cpp
		pgoperations.h
)

add_executable(LO_Storage main.cpp
	${PROJECT_SOURCES}
	
target_include_directories(LO_Storage
    PRIVATE "${CMAKE_BINARY_DIR}/include"
)

target_link_libraries(LO_Storage PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

install(TARGETS LO_Storage RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT alexsh93@live.ru)
include(CPack)
)

Visual Studio 2019:	
	1. Desktopentwicklung mit C++
	2. MSVC v142 - VS 2019 C++ x64/x86 build tools
	3. C++ CMake tools for Windows

Git Bash [version 2.48.1.windows.1]
	https://gitforwindows.org/

OpenCV
	https://github.com/opencv/opencv/releases
	opencv-4.11.0-windows.exe
	
	1. Клонируем основное репо OpenCV:		git clone https://github.com/opencv/opencv.git  (/c/Users/HP/opencv)
	2. Переходим в папку OpenCV			cd opencv / pwd
	3. Проверяем последнюю стабильную версию	git tag / git checkout 4.9.0


cmake [version 4.0.0-rc3]
	https://cmake.org/download/
	Windows x64 Installer:	cmake-4.0.0-rc4-windows-x86_64.msi

	1. Открой CMake GUI				cmake-gui
	2. Where is the source code			C:/Users/HP/opencv
	3. Where to build the binaries			C:/opencv-build
	4. Configure					Visual Studio 16 2019 и x64.
	5. BUILD_opencv_world 
	6. Generate

Компиляция в Visual Studio 2019:
	1. Open C:\opencv-build\OpenCV.sln in VS2019
	2. Выбери конфигурацию Debug и Release и платформу x64.
	3. Построй проект (BUILD_ALL).
	4. проект INSTALL


	1. Завести переменные окружения OpenCV
	setx OpenCV_DIR C:\opencv
	2. Добавить в переменную path для всех пользователей путь до динамических библиотек dll.
	C:\opencv\install\x64\vc16\bin

Настройка Visual Studio для работы с OpenCV
	

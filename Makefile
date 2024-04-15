APP_NAME = proj
BUILD_DIR = ./bin
CPP_FILES = ./src/main.cpp ./src/shader.cpp

APP_DEFINES:=
APP_INCLUDES:= -I./src/vendors/GLFW -I./src -framework Cocoa -framework OpenGL -framework IOKit
APP_LINKERS:= -L./src/vendors/GLFW/lib -lglfw3 -v

build:
	g++ $(CPP_FILES) -o $(BUILD_DIR)/$(APP_NAME) $(APP_INCLUDES) $(APP_LINKERS)
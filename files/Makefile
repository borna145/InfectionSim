CC = g++
CFLAGS = -Wall
LIBS = -lglfw

INCLUDE_PATH = /home/borna/C++/Glad/include
GLAD_SRC = /home/borna/C++/Glad/src/glad.c
IMGUI_PATH = /home/borna/C++/imgui-1.89.5
IMGUI_BACKEND_PATH = $(IMGUI_PATH)/backends
IMGUI_SRC = $(IMGUI_PATH)/imgui.cpp $(IMGUI_PATH)/imgui_draw.cpp $(IMGUI_PATH)/imgui_widgets.cpp $(IMGUI_PATH)/imgui_tables.cpp $(IMGUI_BACKEND_PATH)/imgui_impl_opengl3.cpp $(IMGUI_BACKEND_PATH)/imgui_impl_glfw.cpp
SOURCE = /home/borna/Desktop/Project2/files/Main.cpp

all: my_program

my_program:
	$(CC) $(CFLAGS) -I$(INCLUDE_PATH) -I$(IMGUI_PATH) $(SOURCE) $(GLAD_SRC) $(IMGUI_SRC) $(LIBS) -o my_program

clean:
	rm -f my_program imgui.ini

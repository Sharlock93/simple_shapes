HDR_DIR = header C:\dev\lib\include\ C:\dev\lib\include\Shar\headers
HEADER = $(addprefix -I,$(HDR_DIR))
LIB_DIR = C:\dev\lib\lib-glew\Release\x64\ C:\dev\lib\lib-mingw\ C:\dev\lib\lib-sharo
LIB = $(addprefix -L, $(LIB_DIR))
LIB_NAMES = glfw3 glew32s opengl32 gdi32 sharo
LIBRARY = $(addprefix -l,$(LIB_NAMES))
CCOPTION = std=gnu++11 D__USE_MINGW_ANSI_STDIO=1
FLAGS = $(addprefix -,$(CCOPTION))
CC = g++
OBJ_DIR = obj
OBJ = grid.o main.o 
BUILD_DIR = build
SRC_DIR = S:\Test\shape_test\src

$(BUILD_DIR)\shape_test.exe: $(addprefix $(OBJ_DIR)\,$(OBJ)) 
	 $(CC) $(FLAGS) $(addprefix $(OBJ_DIR)\,$(OBJ)) -o $(BUILD_DIR)\shape_test.exe $(LIB) $(LIBRARY)

$(OBJ_DIR)\grid.o: $(SRC_DIR)\grid.cpp 
	 $(CC) $(FLAGS) -c $(SRC_DIR)\grid.cpp -o $(OBJ_DIR)\grid.o $(HEADER)

$(OBJ_DIR)\main.o: $(SRC_DIR)\main.cpp 
	 $(CC) $(FLAGS) -c $(SRC_DIR)\main.cpp -o $(OBJ_DIR)\main.o $(HEADER)


clean: 
	del /Q $(OBJ_DIR)\*.o
	del /Q $(BUILD_DIR)\*.exe

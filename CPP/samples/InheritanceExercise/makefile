###################################################
# Written by Jerico G. Despe
###################################################

TARGET = CONSOLETEMPLATE_CXX

# COMPILER CONFIG
# ---------------------
CC  =clang
CXX =clang++

# Common flags used for both C and C++
CFLAGS    =-Wall

# Flags for C compiler
CCFLAGS   =${CFLAGS} -std=c99

# Flags for C++ compiler
CXXFLAGS  =${CFLAGS} -std=c++20

# BUILD TYPE : RELEASE | DEBUG (Default)
BUILD_TYPE ?=DEBUG

# PLATFORNS
# ---------------------
# WINDOWS
# LINUX (Default)
PLATFORM ?=LINUX

# PROGRAM ARCHITECTURE : X86 | X64 (Default)
ARCHITECTURE ?=X64

# Output Directory
BIN_DIR :=bin

# Directories
SRC_DIR :=src
OBJ_DIR :=obj

# Find all .c files inside SRC_DIR and its subdirectories
SRC_SUBDIRS =$(wildcard $(SRC_DIR)/*/ $(SRC_DIR)/*/*/)
SRC_C       =$(wildcard $(SRC_DIR)/*.c $(SRC_DIR)/*/*.c $(SRC_DIR)/*/*/*.c)
SRC_CXX     =$(wildcard $(SRC_DIR)/*.cpp $(SRC_DIR)/*/*.cpp $(SRC_DIR)/*/*/*.cpp)

# Define corresponding .o files in OBJ_DIR
OBJ_SUBDIRS =$(patsubst $(SRC_DIR)/%, $(OBJ_DIR)/%, $(SRC_SUBDIRS))
OBJ_C       =$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_C))
OBJ_CXX     =$(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC_CXX))

# Check what platform is selected for build process
# C COMPILER CONFIGURATION
ifeq ($(PLATFORM), WINDOWS)
	CC  =x86_64-w64-mingw32-gcc
	CXX =x86_64-w64-mingw32-g++
	# if ARCHITECTURE is set to 32bit
	ifeq ($(ARCHITECTURE), X86)
		CC  =i686-w64-mingw32-gcc
		CXX =i686-w64-mingw32-g++
	endif
endif

# Check what build type is selected
ifeq ($(BUILD_TYPE), RELEASE)
	CFLAGS    +=-O3 -s
else # Sets to DEBUG by default
	CFLAGS    +=-g
endif

# BUILD THE PROGRAM
$(TARGET): $(OBJ_CXX) $(OBJ_C) 
	@echo "[LOG] Creating bin directory... "; mkdir -p $(BIN_DIR)
	@echo -n "[LINKING] "
	$(CXX) $(OBJ_C) $(OBJ_CXX) ${LDFLAGS} -o $(BIN_DIR)/$@
	@echo "----- BUILD COMPLETE! -----"

# COMPILE C++ SOURCE FILES
$(OBJ_CXX): $(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp | $(OBJ_DIR) $(OBJ_SUBDIRS)
	@echo -n "[COMPILING] " 
	$(CXX) -c $< -o $@ $(CXXFLAGS) $(INCLUDE)

# COMPILE C SOURCE FILES
$(OBJ_C): $(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | $(OBJ_DIR) $(OBJ_SUBDIRS)
	@echo -n "[COMPILING] " 
	$(CC) -c $< -o $@ $(CCFLAGS) $(INCLUDE)

# Create obj directory if it doesn't exist
$(OBJ_DIR):
	@mkdir -p $@

$(OBJ_SUBDIRS):
	@mkdir -p $@

clean:
	@echo "[LOG] obj files are cleaned..."
	@rm -rf $(OBJ_DIR)/* $(OBJ_DIR)/*/*.o $(OBJ_DIR)/*/*/*.o $(BIN_DIR)/${OUT}

# Removes both bin and obj
cleanall:
	@echo "[LOG] obj and bin files are cleaned..."
	@rm -rf $(BIN_DIR) $(OBJ_DIR)

.PHONY: clean cleanall

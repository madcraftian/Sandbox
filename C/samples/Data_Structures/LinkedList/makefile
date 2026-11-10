###################################################
# Written by Jerico G. Despe
###################################################

TARGET = CONSOLETEMPLATE_C

# C COMPILER CONFIG
# ---------------------
CC     =clang
CFLAGS =-Wall -std=c99

# BUILD TYPE: RELEASE | DEBUG (Default)
BUILD_TYPE ?=DEBUG

# PLATFORMS
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
SRC         =$(wildcard $(SRC_DIR)/*.c $(SRC_DIR)/*/*.c $(SRC_DIR)/*/*/*.c)

# Define corresponding .o files in OBJ_DIR
OBJ_SUBDIRS =$(patsubst $(SRC_DIR)/%, $(OBJ_DIR)/%, $(SRC_SUBDIRS))
OBJ         =$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

# Check what platform is selected for build process
# C COMPILER CONFIGURATION
ifeq ($(PLATFORM), WINDOWS)
	CC  =x86_64-w64-mingw32-gcc
	# if ARCHITECTURE is set to 32bit
	ifeq ($(ARCHITECTURE), X86)
		CC  =i686-w64-mingw32-gcc
	endif
endif

# Check what build type is selected
ifeq ($(BUILD_TYPE), RELEASE)
	CFLAGS    +=-O3 -s
else # Sets to DEBUG by default
	CFLAGS    +=-g
endif

# BUILD THE PROGRAM
$(TARGET): $(OBJ) 
	@echo "[LOG] Creating bin directory... "; mkdir -p $(BIN_DIR)
	@echo -n "[LINKING] "
	$(CC) $(OBJ) -o $(BIN_DIR)/$@ ${LDFLAGS}
	@echo "----- BUILD COMPLETE! ------"

$(OBJ): $(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | $(OBJ_DIR) $(OBJ_SUBDIRS)
	@echo -n "[COMPILING] " 
	$(CC) -c $< -o $@ $(CFLAGS)

# Create obj directory if it doesn't exist
$(OBJ_DIR):
	@mkdir -p $@

$(OBJ_SUBDIRS):
	@mkdir -p $@

clean:
	@echo "[LOG] obj files are cleaned..."
	@rm -rf $(OBJ_DIR)/*.o $(OBJ_DIR)/*/*.o $(OBJ_DIR)/*/*/*.o $(BIN_DIR)/${OUT}

# Removes both bin and obj
cleanall:
	@echo "[LOG] obj and bin files are cleaned..."
	@rm -rf $(BIN_DIR) $(OBJ_DIR)

.PHONY: clean cleanall

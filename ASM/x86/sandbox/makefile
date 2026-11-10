###################################################
# Written by Jerico G. Despe
###################################################

TARGET = TEMPLATE_ELF32

# ASM COMPILER CONFIG
# ---------------------
ASM  =nasm
LD   =ld

ASM_FLAGS = -f elf32
LD_FLAGS  = -m elf_i386

# BUILD TYPE: RELEASE | DEBUG (Default)
BUILD_TYPE ?=DEBUG

# Output Directory
BIN_DIR :=bin

# Directories
SRC_DIR :=src
OBJ_DIR :=obj

# Find all .asm files inside SRC_DIR and its subdirectories
SRC_SUBDIRS =$(wildcard $(SRC_DIR)/*/ $(SRC_DIR)/*/*/)
SRC         =$(wildcard $(SRC_DIR)/*.asm $(SRC_DIR)/*/*.asm $(SRC_DIR)/*/*/*.asm)

# Define corresponding .o files in OBJ_DIR
OBJ_SUBDIRS =$(patsubst $(SRC_DIR)/%, $(OBJ_DIR)/%, $(SRC_SUBDIRS))
OBJ         =$(patsubst $(SRC_DIR)/%.asm, $(OBJ_DIR)/%.o, $(SRC))

# Check what build type is selected
ifeq ($(BUILD_TYPE), DEBUG)
	ASM_FLAGS +=-g -F dwarf
endif

# BUILD THE PROGRAM
$(TARGET): $(OBJ) 
	@echo "[LOG] Creating bin directory... "; mkdir -p $(BIN_DIR)
	@echo -n "[LINKING] "
	$(LD) $(LD_FLAGS) -o $(BIN_DIR)/$@ $(OBJ)
	@echo "----- BUILD COMPLETE! ------"

$(OBJ): $(OBJ_DIR)/%.o : $(SRC_DIR)/%.asm | $(OBJ_DIR) $(OBJ_SUBDIRS)
	@echo -n "[COMPILING] " 
	$(ASM) $(ASM_FLAGS) -o $@ $<

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

# Add .d to Make's recognized suffixes.
SUFFIXES += .d

# Project directory
BUILD := ./build
ARCHIVE := NSMBWProjectData
ASSETS := $(BUILD)/$(ARCHIVE).arc.d
ASSETS_SRC := ./assets
TARGET := project
LOADER := Loader
OUTPUT := ./output/riivolution/mkwcat-special-nsmbw-project
TOOLS := $(BUILD)/tools


# Compiler definitions
CLANG_DEFAULT := ./tools/clang/clang
# Fall back to clang on PATH if the default clang is not found
CLANG := $(if $(wildcard $(CLANG_DEFAULT)), $(CLANG_DEFAULT),clang)
HOST_CC := gcc
HOST_CXX := g++
LD := $(DEVKITPPC)/bin/powerpc-eabi-ld
OBJCOPY := $(DEVKITPPC)/bin/powerpc-eabi-objcopy
ELF2REL := $(TOOLS)/elf2rel
LZX := $(TOOLS)/lzx
GENSMAP := ./tools/generate_symbol_map.py
WUJ5 := ./tools/wuj5/wuj5.py

SOURCES :=
-include ./source/sources.mk
-include ./assets/assets.mk


OFILES := $(SOURCES:.cpp=_cpp.o)
OFILES := $(OFILES:.c=_c.o)
OFILES := $(addprefix $(BUILD)/, $(OFILES))
DEPS := $(OFILES:.o=.d)

OUTDIRS := $(sort $(dir $(OFILES)))

LOADER_CPPFILES := ./loader/Loader.cpp
LOADER_OFILES := $(LOADER_CPPFILES:.cpp=_cpp.o)
LOADER_OFILES := $(addprefix $(BUILD)/, $(LOADER_OFILES))
LOADER_DEPS	:= $(LOADER_OFILES:.o=.d)

# Compiler options
CXXOPTS := -std=c++23 -MMD --target=powerpc-eabi-kuribo -Os -nodefaultlibs -include System.h

# Warnings
# -Wno-out-of-line-declaration is required to suppress errors when defining out-of-line aliases
CXXOPTS += -Wno-out-of-line-declaration -Wno-gcc-compat -Wno-invalid-offsetof -Wno-nested-anon-types -Wno-gnu-anonymous-struct

# Flags
CXXOPTS += -fno-PIC -fno-rtti -fno-short-enums -fshort-wchar -ffreestanding -ffunction-sections -fdata-sections \
           -fno-exceptions -fno-threadsafe-statics -fno-use-cxa-atexit -fkeep-static-consts

# Includes
CXXOPTS += -I./source -I./source/msl/msl_c -I./source/msl/msl_cpp -I./source/wiimj2d

# Preprocessor definitions
CXXOPTS +=

# Linker options
LDOPTS := -T./source/module.ld --gc-sections -r -n


.PHONY: all
all: $(OUTPUT)/$(ARCHIVE).arc $(OUTPUT)/$(LOADER).img

.PHONY: clean
clean:
	@echo Cleaning...
	@rm -rf $(BUILD)


-include $(DEPS)

clang-exists := $(shell which $(CLANG))

# test null build and check for error
check-clang-ver := $(shell $(CLANG) -x c /dev/null --target=powerpc-eabi-kuribo -o /dev/null -c 2>&1)

ifeq ($(strip $(clang-exists)),)
$(error Clang not found. Please read README.md)
else ifneq ($(findstring error,$(check-clang-ver)),)
$(error Clang at $(clang-exists) is not compatible with the custom 'kuribo' version. Please read README.md)
endif

$(BUILD)/%_c.o: %.c
	@echo $<
	@mkdir -p $(dir $@)
	@$(CLANG) -x c++ -c ./$< $(CXXOPTS) -o ./$@

$(BUILD)/%_cpp.o: %.cpp
	@echo $<
	@mkdir -p $(dir $@)
	@$(CLANG) -x c++ -c ./$< $(CXXOPTS) -o ./$@

$(BUILD)/$(TARGET).elf: $(OFILES)
	@echo Link: $(notdir $@)
	@$(LD) $(LDOPTS) $(OFILES) -o $@

$(BUILD)/$(TARGET)_P1.rel: $(BUILD)/$(TARGET).elf $(TOOLS)/elf2rel
	@echo Output: $(notdir $@)
	@$(ELF2REL) $< $@

$(BUILD)/$(TARGET)_P2.rel: $(BUILD)/$(TARGET).elf $(ELF2REL)
	@echo Output: $(notdir $@)
	@$(ELF2REL) $< $@ P2
$(BUILD)/$(TARGET)_E1.rel: $(BUILD)/$(TARGET).elf $(ELF2REL)
	@echo Output: $(notdir $@)
	@$(ELF2REL) $< $@ E1
$(BUILD)/$(TARGET)_E2.rel: $(BUILD)/$(TARGET).elf $(ELF2REL)
	@echo Output: $(notdir $@)
	@$(ELF2REL) $< $@ E2
$(BUILD)/$(TARGET)_J1.rel: $(BUILD)/$(TARGET).elf $(ELF2REL)
	@echo Output: $(notdir $@)
	@$(ELF2REL) $< $@ J1
$(BUILD)/$(TARGET)_J2.rel: $(BUILD)/$(TARGET).elf $(ELF2REL)
	@echo Output: $(notdir $@)
	@$(ELF2REL) $< $@ J2
$(BUILD)/$(TARGET)_K1.rel: $(BUILD)/$(TARGET).elf $(ELF2REL)
	@echo Output: $(notdir $@)
	@$(ELF2REL) $< $@ K
$(BUILD)/$(TARGET)_W1.rel: $(BUILD)/$(TARGET).elf $(ELF2REL)
	@echo Output: $(notdir $@)
	@$(ELF2REL) $< $@ W
$(BUILD)/$(TARGET)_C1.rel: $(BUILD)/$(TARGET).elf $(ELF2REL)
	@echo Output: $(notdir $@)
	@$(ELF2REL) $< $@ C

$(ASSETS)/rels/%.rel.LZ: $(BUILD)/%.rel $(LZX)
	@echo Compress: $(notdir $@)
	@mkdir -p $(dir $@)
	@$(LZX) -ewb $< $@

$(ASSETS)/%: $(ASSETS_SRC)/%
	@echo $<
	@mkdir -p $(dir $@)
	@cp $< $@

$(ASSETS)/%.brlyt: $(ASSETS_SRC)/%.brlyt.json5
	@echo $<
	@mkdir -p $(dir $@)
	@python $(WUJ5) encode $< --outputs=$@

$(ASSETS)/%.brlan: $(ASSETS_SRC)/%.brlan.json5
	@echo $<
	@mkdir -p $(dir $@)
	@python $(WUJ5) encode $< --outputs=$@

$(OUTPUT)/$(ARCHIVE).arc: $(DVD_FILES)
	@echo Build: $(notdir $@)
	@mkdir -p $(dir $@)
	@python $(WUJ5) encode $(ASSETS) --root= --outputs=$@

$(ASSETS)/wiimj2d.SMAP: $(BUILD)/$(TARGET).elf
	@echo Make: $(notdir $@)
	@python $(GENSMAP) $< $@

$(BUILD)/$(LOADER).elf: $(LOADER_OFILES)
	@echo Link: $(notdir $@)
	@$(LD) -T./loader/Loader.ld --gc-sections -n $(LOADER_OFILES) -o $@ 

$(OUTPUT)/$(LOADER).img: $(BUILD)/$(LOADER).elf
	@echo Output: $(notdir $@)
	@mkdir -p $(dir $@)
	@$(OBJCOPY) $< $@ -O binary

# Tool recipes

$(ELF2REL): ./tools/elf2rel/elf2rel.cpp
	@echo Build: $(notdir $@)
	@mkdir -p $(dir $@)
	@$(HOST_CXX) -std=c++23 -O2 -I $(dir $<) $< -o $@ 

$(LZX): ./tools/lzx/lzx.c
	@echo Build: $(notdir $@)
	@mkdir -p $(dir $@)
	@$(HOST_CC) -O3 -Wno-deprecated-declarations -Wno-pointer-sign $< -o $@

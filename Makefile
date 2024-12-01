# Add .d to Make's recognized suffixes.
SUFFIXES += .d

# Project directory
BUILD := build
ARCHIVE := NSMBWProjectData
DVDDATA := $(BUILD)/$(ARCHIVE).arc.d
DVDDATA_SRC := assets/dvddata
TARGET := project_P1
LOADER := Loader
OUTPUT := output/riivolution/mkwcat-special-nsmbw-project
TOOLS := tools/x86_64-windows


# Compiler definitions
# CLANG := $(TOOLS)/clang
CLANG := D:\wii\repo\llvm-project\build\bin\clang
CC := $(CLANG)
LD := $(DEVKITPPC)/bin/powerpc-eabi-ld
OBJCOPY := $(DEVKITPPC)/bin/powerpc-eabi-objcopy
ELF2REL := $(TOOLS)/elf2rel
LZX := $(TOOLS)/lzx

SOURCES :=
-include sources.mk

OFILES := $(SOURCES:.cpp=_cpp.o)
OFILES := $(OFILES:.c=_c.o)
OFILES := $(addprefix $(BUILD)/, $(OFILES))
DEPS := $(OFILES:.o=.d)

OUTDIRS := $(sort $(dir $(OFILES)))
DUMMY != mkdir -p $(OUTDIRS)

LOADER_CPPFILES := loader/Loader.cpp
LOADER_OFILES := $(LOADER_CPPFILES:.cpp=_cpp.o)
LOADER_OFILES := $(addprefix $(BUILD)/, $(LOADER_OFILES))
LOADER_DEPS	:= $(LOADER_OFILES:.o=.d)

DUMMY != mkdir -p $(BUILD)/source $(BUILD)/loader $(OUTPUT) $(DVDDATA) 

CFLAGS := --target=powerpc-eabi-kuribo -fno-PIC -Os -fno-rtti -fno-short-enums -fshort-wchar -std=c++23 -Wno-out-of-line-declaration -Wno-gcc-compat -Wno-invalid-offsetof \
-fdeclspec -fno-exceptions -nodefaultlibs -ffreestanding -ffunction-sections -fdata-sections -fno-threadsafe-statics -fno-use-cxa-atexit \
-Isource -Isource/msl/msl_c -Isource/msl/msl_cpp -Isource/wiimj2d -DLOADER_REL_LZ -fkeep-static-consts -femit-all-decls -include System.h

default: $(OUTPUT)/$(ARCHIVE).arc $(OUTPUT)/$(LOADER).img

clean:
	@echo Cleaning...
	@rm -rf $(BUILD)

-include $(DEPS)


DVD_FILES := \
$(DVDDATA)/rels/$(TARGET).rel.LZ \
$(DVDDATA)/wiimj2d.SMAP \
$(DVDDATA)/Layout/charaChangeSelectContents/charaChangeSelectContents.arc/arc/blyt/characterChangeSelectContents_05.brlyt.json5 \
$(DVDDATA)/Layout/charaChangeSelectContents/charaChangeSelectContents.arc/arc/timg/Im_plofileMario_00.tpl \
$(DVDDATA)/Object/Kinopico.arc/g3d/model.brres \
$(DVDDATA)/Sound/BANK_SE_VOC_COURSE_KC.brbnk \
$(DVDDATA)/Sound/GROUP_SE_VOC_COURSE_KC.brwar


$(DVDDATA)/%: $(DVDDATA_SRC)/%
	@echo Copy: $<
	@mkdir -p $(dir $@)
	@cp $< $@

$(BUILD)/%_c.o: %.c
	@echo $<
	@$(CC) -x c++ -MMD $(CFLAGS) -c -o $@ ./$<

$(BUILD)/%_cpp.o: %.cpp
	@echo $<
	@$(CC) -x c++ -MMD $(CFLAGS) -c -o $@ ./$<

$(BUILD)/$(TARGET)_ungc.elf: $(OFILES)
	@echo Link: $(TARGET)_ungc.elf
	@$(LD) -Tmodule.ld -r $(OFILES) -o $@

$(BUILD)/$(TARGET).elf: $(OFILES)
	@echo Link: $(TARGET).elf
	@$(LD) -Tmodule.ld --gc-sections -r $(OFILES) -o $@

$(BUILD)/$(TARGET).rel: $(BUILD)/$(TARGET).elf
	@echo Rel: $(TARGET).rel
	@$(ELF2REL) $(BUILD)/$(TARGET).elf $@

$(DVDDATA)/rels/$(TARGET).rel.LZ: $(BUILD)/$(TARGET).rel
	@echo Compress: $(TARGET).rel.LZ
	@mkdir -p $(DVDDATA)/rels
	@$(LZX) -ewb $< $@

$(OUTPUT)/$(ARCHIVE).arc: $(DVD_FILES)
	@echo Build: $(ARCHIVE).arc
	@python $(TOOLS)/../python/wuj5/wuj5.py encode $(BUILD)/$(ARCHIVE).arc.d --root= --outputs=$@

$(DVDDATA)/wiimj2d.SMAP: $(BUILD)/$(TARGET)_ungc.elf
	@echo Make: wiimj2d.SMAP
	@python $(TOOLS)/../python/generate_symbol_map.py $(BUILD)/$(TARGET)_ungc.elf $(DVDDATA)/wiimj2d.SMAP

$(BUILD)/$(LOADER).elf: $(LOADER_OFILES)
	@echo Link: $(LOADER).elf
	@$(LD) -Tloader/Loader.ld --gc-sections -n -o $@ $<

$(OUTPUT)/$(LOADER).img: $(BUILD)/$(LOADER).elf
	@echo Output: $(LOADER).img
	@$(OBJCOPY) $< $@ -O binary



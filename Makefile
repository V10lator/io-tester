TARGET_EXEC=test.bin

IDIR = include
SDIR = src

CC	= gcc
CFLAGS	= -O0 -ggdb3 -fno-stack-protector -I$(IDIR)

ODIR=obj

LIBS=-lm

SRCS := $(shell find $(SDIR) -name *.cpp -or -name *.c)
INCS := $(shell find $(IDIR) -name *.h)

BUILD_DIR ?= ./build
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

LDFLAGS := $(CFLAGS) -lpthread

$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

# c source
$(BUILD_DIR)/%.c.o: %.c
	$(MKDIR_P) $(dir $@)
	$(CC) $(LDFLAGS) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

# c++ source
$(BUILD_DIR)/%.cpp.o: %.cpp
	$(MKDIR_P) $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

.PHONY: clean

clean:
	$(RM) -r $(BUILD_DIR)

-include $(DEPS)

MKDIR_P ?= mkdir -p
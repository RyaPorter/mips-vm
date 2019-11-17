BUILD_DIR = build
SRC_DIRS = src

src = $(shell find $(SRC_DIRS) -name *.cc)

obj = $(src:.cc=.o)

CXXFLAGS =

debug: CXXFLAGS += -g
debug: build

build: $(obj)
	$(CXX) $(obj) -o $(BUILD_DIR)/main

.PHONY: clean

clean:
	rm -f $(obj)
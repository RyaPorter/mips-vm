BUILD_DIR = build
SRC_DIRS = src

src = $(shell find $(SRC_DIRS) -name *.cc)

obj = $(src:.cc=.o)

CXXFLAGS = -std=c++11

debug: CXXFLAGS += -g
debug: build

build: $(obj)
	$(CXX) $(obj) -o $(BUILD_DIR)/main
	make clean

.PHONY: clean

clean:
	rm -f $(obj)
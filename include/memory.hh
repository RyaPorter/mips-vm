#pragma once
#include <stdint.h>

namespace hardware {

class memory {
  private:
    uint32_t *mem;

  public:
    memory(/* args */);
    ~memory();

    uint32_t read(uint32_t addr);
    void write(uint32_t addr, uint32_t val);
};
}; // namespace hardware

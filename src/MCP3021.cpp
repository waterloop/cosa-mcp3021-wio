// Copyright (c) 2019 Waterloop. All rights reserved.

#include <mcp3021/MCP3021.h>

using wlp::MCP3021;

static constexpr uint16_t resolution = 1023;

MCP3021::MCP3021(uint8_t addr) : Driver(mcp3021BaseAddr | addr) {}

uint16_t MCP3021::read() {
  twi.acquire(this);

  uint8_t dataRead[2];
  twi.read(dataRead, sizeof(dataRead));
  twi.release();

  return dataRead[0] << 6 | dataRead[1] >> 2;
}

uint16_t MCP3021::voltage(uint16_t data, uint32_t vref) {
  return (vref * data / resolution);
}

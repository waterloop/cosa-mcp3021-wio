// Copyright (c) 2019 Waterloop. All rights reserved.

#ifndef COSA_MCP3021_WIO_MCP3021_H
#define COSA_MCP3021_WIO_MCP3021_H

#include <Cosa/TWI.hh>

namespace wlp {
class MCP3021 : TWI::Driver {
 public:
  /**
   * Initializes the I2C driver
   * Most MCP3021 ship with the address 0b101 or 5). There are no configurable address
   * pins, but it is possible to get other addresses from the factory. If you have
   * an alternate address you can specify that as the optional second parameter to
   * the constructor.
   * @param addr address for the chip
   */
  MCP3021(uint8_t addr = 0x05);

  /**
   * Read the given channel and return the result.
   * @return sample
   */
  uint16_t read();

  /**
   * Convert sampled data (result) into voltage
   * @param data sampled data (result)
   * @param vref voltage reference
   * @return voltage for sampled data
   */
  static uint16_t voltage(uint16_t data, uint32_t vref);

 private:
  static constexpr uint8_t mcp3021BaseAddr = 0x4D;
};
}

#endif //COSA_MCP3021_WIO_MCP3021_H

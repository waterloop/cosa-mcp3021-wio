// Copyright (c) 2019 Waterloop. All rights reserved.

#include <Cosa/UART.hh>
#include <Cosa/Trace.hh>
#include <mcp3021/MCP3021.h>

using wlp::MCP3021;

constexpr uint8_t address = 0x05;
constexpr uint16_t ref_voltage = 5000;  // in mV

// address from 0 to 7
MCP3021 mcp3021{address};

void setup() {
  uart.begin(9600);
  trace.begin(&uart, PSTR("MCP3021 Example started"));
}

void loop() {
  auto data = mcp3021.sample();
  auto voltage = MCP3021::voltage(data, ref_voltage);

  trace << "Sampled Data[ADC: " << data << ", mV: " << voltage << "]" << endl;
}

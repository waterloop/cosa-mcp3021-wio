// Copyright (c) 2019 Waterloop. All rights reserved.

#include <Cosa/UART.hh>
#include <Cosa/Trace.hh>
#include <mcp3021/MCP3021.h>

using wlp::MCP3021;

constexpr uint16_t ref_voltage = 5000;  // in mV

MCP3021 mcp3021;

void setup() {
  uart.begin(9600);
  trace.begin(&uart, PSTR("MCP3021 Example started"));
}

void loop() {
  auto data = mcp3021.read();
  auto voltage = MCP3021::voltage(data, ref_voltage);

  trace << "[ADC: " << data << ", mV: " << voltage << "]" << endl;
  delay(500);
}

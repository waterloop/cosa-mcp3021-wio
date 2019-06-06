# Cosa MCP3021 Wio

This is a Cosa package for working with MCP3021 ADC.
Sample usage looks like this:

```cpp
#include <Cosa/UART.hh>
#include <Cosa/Trace.hh>
#include <mcp3021/MCP3021.h>

using wlp::MCP3021;

constexpr uint16_t ref_voltage = 5000;  // in mV

// use the default address binary: 101
MCP3021 mcp3021;

void setup() {
  uart.begin(9600);
  trace.begin(&uart, PSTR("MCP3021 Example started"));
}

void loop() {
  auto data = mcp3021.read();
  auto voltage = MCP3021::voltage(data, ref_voltage);

  trace << "Sampled Data[ADC: " << data << ", mV: " << voltage << "]" << endl;
  delay(500);
}

```

## Installing this package
```bash
wio install cosa-mcp3021-wio@1.0.0 --url github.com/waterloop/cosa-mcp3021-wio
```

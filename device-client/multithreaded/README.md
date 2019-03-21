# Multithreaded

**We recommend this to new users and tinkerers.** The Multi-Threaded version of our sdk (no \_ll\_ in file names) is the highest level API of our SDK. 

It is useful if you don't want to think about having multiple threads running tasks and also telling the SDK to communicate with IoTHub. With it, we have implemented an API abstraction layer that handles calling `DoWork` (which is needed for the SDK to... do work), so it's more straightforward for you to just call commands and have them execute.

## List of Samples 

- **amqp-shared-methods** -
AMQP Shared Methods

- **device-twin-and-methods** - 
Device Twin and Methods 

- **iot-edge-downstream-device-sample** - 
IoT Edge Downstream Device

- **module-filter** - 
Module Filter

- **module-method-invoke** -
Module Method Invoke

- **module-sender** - 
Module Sender

- **mqtt-dm** -
MQTT Direct Message (DM)

- **telemetry** -
Telemetry

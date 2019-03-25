# IoT Hub Device SDK Samples

## Multi-Threaded
**We recommend this to new users and tinkerers.** The Multi-Threaded version of our sdk (no \_ll\_ in file names) is the highest level API of our SDK. 

It is useful if you don't want to think about having multiple threads running tasks and also telling the SDK to communicate with IoTHub. With it, we have implemented an API abstraction layer that handles calling `DoWork` (which is needed for the SDK to... do work), so it's more straightforward for you to just call commands and have them execute.


## Single-Threaded
**We recommend this if you want more control.** As an experienced user, Single-Threaded exposes `DoWork` to be explicitly called each time you want the SDK to process the commands queued for it. 

Our SDK is built in layers, and the threading is an extra layer we implement for those that don't want to explicitly call `DoWork`. Using this lower-level layer (denoted by \_ll\_ in file names) will create less abstraction as to how the SDK sends messages, responds to method or twin callbacks, so on and so forth. 
# Singlethreaded

**We recommend this if you want more control.** As an experienced user, Single-Threaded exposes `DoWork` to be explicitly called each time you want the SDK to process the commands queued for it. 

Our SDK is built in layers, and the threading is an extra layer we implement for those that don't want to explicitly call `DoWork`. Using this lower-level layer (denoted by \_ll\_ in file names) will create less abstraction as to how the SDK sends messages, responds to method or twin callbacks, so on and so forth.
 

## List of Samples

- **amqp-multiplexing** -
AMQP Shared Methods

- **service-client-to-device** - 
Service Client to Device

- **telemetry** - 
Telemetry

- **upload-to-blob** - 
Upload to Blob

- **upload-to-blob-multiple-blocks** - 
Upload to Blob Multiple Blocks

- **x509-authentication** - 
X509 Authentication
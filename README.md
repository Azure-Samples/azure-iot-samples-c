### PARDON OUR DUST: THIS REPO IS STILL GETTING BUILT
# Azure IoT C Client Library Samples

A repository of samples for use with the [Azure IoT C Client Library](https://github.com/Azure/azure-iot-sdk-c).

# Samples 

TBD


# [Wiki](https://github.com/Azure-Samples/azure-iot-samples-c/wiki)

While simple README.md files are provided embedded within the codebase itself, more in depth documentation can be found in the Github Wiki, including sample walkthroughs.

# Community Guidelines

If you have an issue running a sample and you believe the error is a result of the sample code, submit a Github Issue to this repo. If you believe the error is from the C Client Library, please submit a Github issue to the [C Client Library](https://github.com/Azure/azure-iot-sdk-c/issues/new/choose).

If you want to contribute to this repository, consider submitting a PR.

This project has adopted the Microsoft [Open Source Code of Conduct](https://opensource.microsoft.com/codeofconduct). For more information see the Code of Conduct FAQ or contact opencode@microsoft.com with any additional questions or comments.

Microsoft collects performance and usage information which may be used to provide and improve Microsoft products and services and enhance your experience. To learn more, review the privacy statement.

# File Tree [This tree will be removed. Only for construction Purposes]
```bash
.
├── CHANGELOG.md
├── CONTRIBUTING.md
├── device-client
│   ├── CMakeLists.txt
│   ├── multithreaded
│   │   ├── amqp-shared-methods
│   │   │   ├── CMakeLists.txt
│   │   │   ├── iothub_client_sample_amqp_shared_methods.c
│   │   │   ├── linux
│   │   │   │   ├── CMakeLists.txt
│   │   │   │   └── README.md
│   │   │   └── README.md
│   │   ├── CMakeLists.txt
│   │   ├── device-twin-and-methods
│   │   │   ├── CMakeLists.txt
│   │   │   ├── iothub_device_twin_and_methods_sample.c
│   │   │   ├── linux
│   │   │   │   ├── CMakeLists.txt
│   │   │   │   └── README.md
│   │   │   └── README.md
│   │   ├── iot-edge-downstream-device-sample
│   │   │   ├── CMakeLists.txt
│   │   │   ├── iotedge_downstream_device_sample.c
│   │   │   ├── linux
│   │   │   │   ├── CMakeLists.txt
│   │   │   │   └── README.md
│   │   │   └── README.md
│   │   ├── module-filter
│   │   │   ├── CMakeLists.txt
│   │   │   ├── iothub_client_module_filter_sample.c
│   │   │   ├── iothub_client_module_filter_sample.h
│   │   │   ├── linux
│   │   │   │   ├── CMakeLists.txt
│   │   │   │   └── README.md
│   │   │   └── README.md
│   │   ├── module-method-invoke
│   │   │   ├── CMakeLists.txt
│   │   │   ├── iothub_client_sample_module_method_invoke.c
│   │   │   ├── iothub_client_sample_module_method_invoke.h
│   │   │   ├── linux
│   │   │   │   ├── CMakeLists.txt
│   │   │   │   └── README.md
│   │   │   └── README.md
│   │   ├── module-sender
│   │   │   ├── CMakeLists.txt
│   │   │   ├── iothub_client_sample_module_sender.c
│   │   │   ├── iothub_client_sample_module_sender.h
│   │   │   ├── linux
│   │   │   │   ├── CMakeLists.txt
│   │   │   │   └── README.md
│   │   │   └── README.md
│   │   ├── mqtt-dm
│   │   │   ├── CMakeLists.txt
│   │   │   ├── iothub_client_sample_mqtt_dm.c
│   │   │   ├── iothub_client_sample_mqtt_dm.h
│   │   │   ├── linux
│   │   │   │   ├── CMakeLists.txt
│   │   │   │   └── README.md
│   │   │   ├── pi_device
│   │   │   │   ├── iothub_client_sample_firmware_update.service
│   │   │   │   ├── packaging
│   │   │   │   │   ├── debian
│   │   │   │   │   │   ├── changelog
│   │   │   │   │   │   ├── compat
│   │   │   │   │   │   ├── control
│   │   │   │   │   │   ├── copyright
│   │   │   │   │   │   ├── docs
│   │   │   │   │   │   ├── files
│   │   │   │   │   │   ├── iothub-client-sample-firmware-update.substvars
│   │   │   │   │   │   ├── postinst.ex
│   │   │   │   │   │   ├── README.md
│   │   │   │   │   │   ├── rules
│   │   │   │   │   │   └── source
│   │   │   │   │   │       ├── format
│   │   │   │   │   │       └── README.md
│   │   │   │   │   └── README.md
│   │   │   │   ├── pi.c
│   │   │   │   ├── readme.md
│   │   │   │   └── README.md
│   │   │   ├── README.md
│   │   │   └── Template
│   │   │       ├── CMakeLists.txt
│   │   │       ├── README.md
│   │   │       └── template.cpp
│   │   ├── README.md
│   │   └── telemetry
│   │       ├── CMakeLists.txt
│   │       ├── iothub_telemetry_sample.c
│   │       ├── linux
│   │       │   ├── CMakeLists.txt
│   │       │   └── README.md
│   │       └── README.md
│   ├── README.md
│   └── singlethreaded
│       ├── amqp-multiplexing
│       │   ├── CMakeLists.txt
│       │   ├── iothub_ll_client_shared_sample.c
│       │   ├── linux
│       │   │   ├── CMakeLists.txt
│       │   │   └── README.md
│       │   └── README.md
│       ├── CMakeLists.txt
│       ├── README.md
│       ├── service-client-to-device
│       │   ├── CMakeLists.txt
│       │   ├── iothub_ll_c2d_sample.c
│       │   ├── linux
│       │   │   ├── CMakeLists.txt
│       │   │   └── README.md
│       │   └── README.md
│       ├── telemetry
│       │   ├── CMakeLists.txt
│       │   ├── iothub_ll_telemetry_sample.c
│       │   ├── linux
│       │   │   ├── CMakeLists.txt
│       │   │   └── README.md
│       │   └── README.md
│       ├── upload-to-blob
│       │   ├── CMakeLists.txt
│       │   ├── iothub_client_sample_upload_to_blob.c
│       │   ├── linux
│       │   │   ├── CMakeLists.txt
│       │   │   └── README.md
│       │   ├── mbed
│       │   │   ├── CMakeLists.txt
│       │   │   ├── iothub_client_sample_http_filelist.txt
│       │   │   ├── main.cpp
│       │   │   ├── readme.md
│       │   │   └── README.md
│       │   └── README.md
│       ├── upload-to-blob-multiple-blocks
│       │   ├── CMakeLists.txt
│       │   ├── iothub_client_sample_upload_to_blob_mb.c
│       │   ├── linux
│       │   │   ├── CMakeLists.txt
│       │   │   └── README.md
│       │   ├── mbed
│       │   │   ├── CMakeLists.txt
│       │   │   ├── iothub_client_sample_upload_to_blob_multi_block_filelist.txt
│       │   │   ├── main.cpp
│       │   │   ├── readme.md
│       │   │   └── README.md
│       │   └── README.md
│       └── x509-authentication
│           ├── CMakeLists.txt
│           ├── iothub_ll_client_x509_sample.c
│           ├── linux
│           │   ├── CMakeLists.txt
│           │   └── README.md
│           └── README.md
├── LICENSE.txt
├── README.md
└── tools
    ├── c_sdk_aptget.sh
    ├── generate_readmes.sh
    └── parson
        ├── LICENSE
        ├── Makefile
        ├── package.json
        ├── parson.c
        ├── parson.h
        ├── README.md
        ├── tests
        │   ├── test_1_1.txt
        │   ├── test_1_2.txt
        │   ├── test_1_3.txt
        │   ├── test_2_comments.txt
        │   ├── test_2_pretty.txt
        │   ├── test_2.txt
        │   └── test_5.txt
        └── tests.c

```

// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

// CAVEAT: This sample is to demonstrate azure IoT client concepts only and is not a guide design principles or style
// Checking of return codes and error values shall be omitted for brevity.  Please practice sound engineering practices
// when writing production code.


#include <stdio.h>
#include <stdlib.h>

/* This sample uses the _LL APIs of iothub_client for example purposes.
That does not mean that HTTP only works with the _LL APIs.
Simply changing the using the convenience layer (functions not having _LL)
and removing calls to _DoWork will yield the same results. */

#include "azure_c_shared_utility/shared_util_options.h"
#include "iothub.h"
#include "iothub_device_client.h"
#include "iothub_message.h"
#include "iothubtransporthttp.h"

#ifdef SET_TRUSTED_CERT_IN_SAMPLES
#include "certs.h"
#endif // SET_TRUSTED_CERT_IN_SAMPLES

// To upload multiple blocks of data using UploadToBlob, uncomment the following line.
// #define MULTIPLE_BLOCKS

/*String containing Hostname, Device Id & Device Key in the format:                         */
/*  "HostName=<host_name>;DeviceId=<device_id>;SharedAccessKey=<device_key>"                */
/*  "HostName=<host_name>;DeviceId=<device_id>;SharedAccessSignature=<device_sas_token>"    */
static const char* connectionString = "[device connection string]";

/*Optional string with http proxy host and integer for http proxy port (Linux only)         */
static const char* proxyHost = NULL;
static int proxyPort = 0;

#define HELLO_WORLD "Hello World from IoTHubClient_LL_UploadToBlob"

#ifdef MULTIPLE_BLOCKS
static int block_count = 0

static IOTHUB_CLIENT_FILE_UPLOAD_GET_DATA_RESULT getDataCallback(IOTHUB_CLIENT_FILE_UPLOAD_RESULT result, unsigned char const ** data, size_t* size, void* context)
{
    (void)context;
    if (result == FILE_UPLOAD_OK)
    {
        if (data != NULL && size != NULL)
        {
            // "block_count" is used to simulate reading chunks from a larger data content, like a large file.
            if (block_count < 100)
            {
                *data = (const unsigned char*)HELLO_WORLD;
                *size = strlen(HELLO_WORLD);
                block_count++;
            }
            else
            {
                // This simulates reaching the end of the file. At this point all the data content has been uploaded to blob.
                // Setting data to NULL and/or passing size as zero indicates the upload is completed.
                *data = NULL;
                *size = 0;
                (void)printf("Indicating upload is complete (%d blocks uploaded)\r\n", block_count);
            }
        }
        else
        {
            // The last call to this callback is to indicate the result of uploading the previous data block provided.
            // Note: In this last call, data and size pointers are NULL.
            (void)printf("Last call to getDataCallback (result for %dth block uploaded: %s)\r\n", block_count, ENUM_TO_STRING(IOTHUB_CLIENT_FILE_UPLOAD_RESULT, result));
        }
    }
    else
    {
        (void)printf("Received unexpected result %s\r\n", ENUM_TO_STRING(IOTHUB_CLIENT_FILE_UPLOAD_RESULT, result));
    }
    // This callback returns IOTHUB_CLIENT_FILE_UPLOAD_GET_DATA_OK to indicate that the upload shall continue.
    // To abort the upload, it should return IOTHUB_CLIENT_FILE_UPLOAD_GET_DATA_ABORT
    return IOTHUB_CLIENT_FILE_UPLOAD_GET_DATA_OK;
}
#endif // MULTIPLE_BLOCKS



int main(void)
{
    IOTHUB_DEVICE_CLIENT_LL_HANDLE device_ll_handle;

    // Used to initialize IoTHub SDK subsystem
    (void)IoTHub_Init();
    (void)printf("Starting the IoTHub client sample upload to blob...\r\n");
#ifdef MULTIPLE_BLOCKS
    (void)printf("MULTIPLE_BLOCKS defined, so uploading multiple blocks to blob.\r\n");
#endif // MULTIPLE_BLOCKS

    device_ll_handle = IoTHubDeviceClient_LL_CreateFromConnectionString(connectionString, HTTP_Protocol);
    if (device_ll_handle == NULL)
    {
        (void)printf("Failure createing Iothub device.  Hint: Check you connection string.\r\n");
    }
    else
    {
#ifndef WIN32
        size_t log = 1;
        (void)IoTHubDeviceClient_LL_SetOption(device_ll_handle, OPTION_CURL_VERBOSE, &log);
#endif // !WIN32

#ifdef SET_TRUSTED_CERT_IN_SAMPLES
        // Setting the Trusted Certificate.  This is only necessary on system with without
        // built in certificate stores.
        IoTHubDeviceClient_LL_SetOption(device_ll_handle, OPTION_TRUSTED_CERT, certificates);
#endif // SET_TRUSTED_CERT_IN_SAMPLES

        HTTP_PROXY_OPTIONS http_proxy_options = { 0 };
        http_proxy_options.host_address = proxyHost;
        http_proxy_options.port = proxyPort;

        if (proxyHost != NULL && IoTHubDeviceClient_LL_SetOption(device_ll_handle, OPTION_HTTP_PROXY, &http_proxy_options) != IOTHUB_CLIENT_OK)
        {
            (void)printf("failure to set proxy\n");
        }
        else
        {
#ifdef MULTIPLE_BLOCKS
            if (IoTHubDeviceClient_LL_UploadMultipleBlocksToBlob(device_ll_handle, "subdir/hello_world_mb.txt", getDataCallback, NULL) != IOTHUB_CLIENT_OK)
 
#else
            if (IoTHubDeviceClient_LL_UploadToBlob(device_ll_handle, "subdir/hello_world.txt", (const unsigned char*)HELLO_WORLD, sizeof(HELLO_WORLD) - 1) != IOTHUB_CLIENT_OK)
#endif

            {
                (void)printf("hello world failed to upload\n");
            }
            else
            {
                (void)printf("hello world has been created\n");
            }
        }
        // Clean up the iothub sdk handle
        IoTHubDeviceClient_LL_Destroy(device_ll_handle);
    }
    // Free all the sdk subsystem
    IoTHub_Deinit();

    printf("Press any key to continue");
    (void)getchar();

    return 0;
}

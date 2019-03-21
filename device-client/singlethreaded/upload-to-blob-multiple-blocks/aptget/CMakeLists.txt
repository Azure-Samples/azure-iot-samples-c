#Copyright (c) Microsoft. All rights reserved.
#Licensed under the MIT license. See LICENSE file in the project root for full license information.

cmake_minimum_required(VERSION 3.10)
project(iothub_client_sample_upload_to_blob_mb_linux)

set(AZUREIOT_INC_FOLDER "/usr/include/azureiot" "/usr/include/azureiot/inc")

set(sample_application_c_files
    ${PROJECT_SOURCE_DIR}/../iothub_client_sample_upload_to_blob_mb.c
    ${PROJECT_SOURCE_DIR}/../../../../tools/.certs/certs.c
)

set(sample_application_h_files
)

add_executable(${PROJECT_NAME} 
    ${sample_application_c_files} 
    ${sample_application_h_files}
)

add_definitions(-DSET_TRUSTED_CERT_IN_SAMPLES)

target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${AZUREIOT_INC_FOLDER}
        ${PROJECT_SOURCE_DIR}/../../../../tools/.certs
)

target_link_libraries(${PROJECT_NAME}
    iothub_client
    iothub_client_http_transport
    prov_auth_client
    hsm_security_client
    uhttp
    aziotsharedutil
    uuid
    parson
    pthread
    curl
    ssl
    crypto
    m
)
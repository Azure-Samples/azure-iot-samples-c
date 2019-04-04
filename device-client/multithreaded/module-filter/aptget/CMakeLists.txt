#Copyright (c) Microsoft. All rights reserved.
#Licensed under the MIT license. See LICENSE file in the project root for full license information.

cmake_minimum_required(VERSION 3.10)
project(iothub_client_sample_module_filter_linux)

if (NOT "${use_mqtt}")
    message("CMAKE WARNING: No protocol has been set. 
    Automatically linking mqtt.")
    set(use_mqtt ON)
endif()

set(AZUREIOT_INC_FOLDER ".." "/usr/include/azureiot" "/usr/include/azureiot/inc")

set(sample_application_c_files
    ${PROJECT_SOURCE_DIR}/../iothub_client_module_filter_sample.c
    ${PROJECT_SOURCE_DIR}/../../../../tools/.certs/certs.c
)

set(sample_application_h_files
    ${PROJECT_SOURCE_DIR}/../iothub_client_module_filter_sample.h
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

if("${use_mqtt}")
    message("target_link_libraries: use_mqtt")
    target_link_libraries(${PROJECT_NAME} iothub_client_mqtt_transport iothub_client_mqtt_ws_transport umqtt)
endif()

target_link_libraries(${PROJECT_NAME}
    iothub_client
    aziotsharedutil
    prov_auth_client
    hsm_security_client
    uhttp
    parson
    uuid
    pthread
    curl
    ssl
    crypto
    m
)






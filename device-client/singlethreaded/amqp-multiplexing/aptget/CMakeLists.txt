#Copyright (c) Microsoft. All rights reserved.
#Licensed under the MIT license. See LICENSE file in the project root for full license information.

cmake_minimum_required(VERSION 3.10)
project(iothub_ll_client_shared_sample_linux)

if (NOT "${use_amqp}" AND NOT "${use_http}")
    message(ERROR "No protocol has been set. 
    iothub_ll_client_shared_sample being generated without uamqp or http support.
    Defaulting to link amqp http.
    To only link a specific protocol, add the cmake option '-D use_<protocol>=ON'")
    set(use_amqp ON)
    set(use_http ON)
endif()

set(AZUREIOT_INC_FOLDER ".." "/usr/include/azureiot" "/usr/include/azureiot/inc")

set(sample_application_c_files
    ${PROJECT_SOURCE_DIR}/../iothub_ll_client_shared_sample.c
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

if("${use_mqtt}")
    message(FATAL_ERROR "this sample does not support mqtt")
endif()
if ("${use_amqp}")
    message("target_link_libraries: use_amqp")
    target_link_libraries(${PROJECT_NAME} iothub_client_amqp_transport iothub_client_amqp_ws_transport uamqp)
endif()
if ("${use_http}")
    message("target_link_libraries: use_http")
    target_link_libraries(${PROJECT_NAME} iothub_client_http_transport)
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




#Copyright (c) Microsoft. All rights reserved.
#Licensed under the MIT license. See LICENSE file in the project root for full license information.

cmake_minimum_required (VERSION 3.10)
project (iothub_device_twin_and_methods_sample_linux)

if (NOT "${use_amqp}" AND NOT "${use_mqtt}" AND NOT "${use_http}")
    message("CMAKE WARNING: No protocol has been set. 
    Defaulting to link mqtt, amqp, and http.
    To only link a specific protocol, add the cmake option '-D use_<protocol>=ON'")
    set(use_mqtt ON)
    set(use_amqp ON)
    set(use_http ON)
endif()

set(AZUREIOT_INC_FOLDER "/usr/include/azureiot" "/usr/include/azureiot/inc")

set(sample_application_c_files
    ${PROJECT_SOURCE_DIR}/../iothub_device_twin_and_methods_sample.c
    ${PROJECT_SOURCE_DIR}/../../../../tools/.certs/certs.c
)

set(sample_application_h_files
)

add_executable(${PROJECT_NAME} ${sample_application_c_files} ${sample_application_h_files})

target_include_directories(${PROJECT_NAME} 
    PRIVATE 
        ${AZUREIOT_INC_FOLDER}
        ${PROJECT_SOURCE_DIR}/../../../../tools/.certs
        ${PROJECT_SOURCE_DIR}/../../../../tools/parson
)

if("${use_mqtt}")
    message("target_link_libraries: use_mqtt")
    target_link_libraries(${PROJECT_NAME} iothub_client_mqtt_transport iothub_client_mqtt_ws_transport umqtt)
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
    prov_auth_client
    hsm_security_client
    uhttp
    aziotsharedutil
    parson
    uuid
    pthread
    curl
    ssl
    crypto
    m
)

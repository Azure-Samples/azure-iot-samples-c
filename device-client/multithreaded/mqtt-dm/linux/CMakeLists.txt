#Copyright (c) Microsoft. All rights reserved.
#Licensed under the MIT license. See LICENSE file in the project root for full license information.

cmake_minimum_required(VERSION 3.10)
project(iothub_client_sample_mqtt_dm_linux)

set(AZUREIOT_INC_FOLDER "pi_device" "../../../serializer/inc" "." "/usr/include/azureiot" "/usr/include/azureiot/inc")

set(sample_application_c_files
    ${PROJECT_SOURCE_DIR}/../iothub_client_sample_mqtt_dm.c
    ${PROJECT_SOURCE_DIR}/../../../../tools/.certs/certs.c
    pi_device/pi.c
)

set(sample_application_h_files
    ${PROJECT_SOURCE_DIR}/../iothub_client_sample_mqtt_dm.h
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
    iothub_client_mqtt_transport
    iothub_client_mqtt_ws_transport
    serializer
    aziotsharedutil
    umqtt
    pthread
    curl
    m
)
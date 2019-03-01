#!/usr/bin/env bash
# Copyright (c) Microsoft. All rights reserved.
# Licensed under the MIT license. See LICENSE file in the project root for full license information.

# Install the proper dependencies for azure-iot-sdk-c
echo "/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/"
echo "Installing cmake..."
echo "/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/"
if ! sudo apt-get install cmake; then 
    echo "Could not install cmake! Aborting." 1>&2
    exit 1
fi
echo "/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/"
echo "Installing build-essential..."
echo "/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/"
if ! sudo apt-get install build-essential; then 
    echo "Could not install build-essential! Aborting." 1>&2
    exit 1
fi
echo "/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/"
echo "Installing software-properties-common..."
echo "/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/"
if ! sudo apt-get install -y software-properties-common; then
    echo "Could not install software-properties-common! Aborting." 1>&2
    exit 1
fi
echo "/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/"
echo "Adding apt repository aziotsdklinux/ppa-azureiot..."
echo "/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/"
if ! sudo add-apt-repository ppa:aziotsdklinux/ppa-azureiot; then
    echo "Could not add apt respository aziotsdklinux/ppa-azureiot! Aborting." 1>&2
    exit 1
fi
echo "/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/"
echo "Updating apt-get..."
echo "/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/"
if ! sudo apt-get update; then
    echo "Could not update apt-get! Aborting." 1>&2
    exit 1
fi

# Install azure-iot-sdk-c
echo "/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/"
echo "Installing azure-iot-sdk-c-dev..."
echo "/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/"
if ! sudo apt-get install -y azure-iot-sdk-c-dev; then 
    echo "Could not install azure-iot-sdk-c-dev! Aborting." 1>&2
    exit 1
fi

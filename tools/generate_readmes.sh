#!/bin/bash

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"

pushd "${DIR}/../device-client"

add_readmes() {
    for element in $(find . -maxdepth 1 -type d -not -name .); do
        pushd $element
        local cmakeheader=$element
        echo "Subdirectory: $element"
        if [[ -e "README.md" ]]; then
            echo "README.md exists."
        else
            echo "No CMakeLists in /$element/CMakeLists.txt"
            echo "Adding README.md..."
            echo "##$cmakeheader" >> README.md
            echo "**Description: $cmakeheader is run by...**" >> README.md
            echo "**To Use:**" >> README.md
        fi
        add_readmes
        popd
    done
}

add_readmes
popd


#!/usr/bin/bash

path=$1

if [ -z "$path" ]; then
    echo "empty param!"
    exit 1
fi

# Check file has an extension (unquoted regex for =~ to work)
if [[ ! "$path" =~ \.[a-zA-Z0-9]+$ ]]; then
    echo "please enter a legal file"
    exit 1
fi

# If not already a .ppm file, convert with ffmpeg
if [[ ! "$path" =~ \.ppm$ ]]; then
    new_path="${path%.*}.ppm"
    ffmpeg -i "$path" "$new_path" &>/dev/null
    path=$new_path
fi

cd ./build
if [ ! -f iv ];then
    cmake ..
    make
fi
./iv $new_path
cd ..
rm $new_path



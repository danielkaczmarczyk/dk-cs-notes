#!/bin/zsh

filename="args.sh"

echo `ls`

if [ -e "$filename" ]; then
  echo "$filename exists as a file"
fi

dirname="srcipts"

if [ -d "$dirname" ]; then
  echo "$dirname exists as a directory"
else
  echo "$dirname does not exist as a directory"
fi

if [ -r "$filename" ]; then
  echo "you are allowed to read contents of $filename"
else
  echo "you are not allowed to read contents of $filename"
fi

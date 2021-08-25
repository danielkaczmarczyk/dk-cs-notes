#!/bin/zsh

# you cannot use ctrl+c in this shell

boo() {
  echo "not today"
}

trap boo SIGINT SIGTERM
echo "it's going to run until you hit Ctrl+Z"
echo "hit Ctrl+C to be blown away!"

while true
do
  sleep 60
done

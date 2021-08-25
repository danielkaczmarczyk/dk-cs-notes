#!/bin/bash

# $n is positional
echo $3
# $# is n args
echo $#

# TODO: look up why brackets preserve type
args=("$@")
echo "\$@: $@"

echo "${args[0]}"

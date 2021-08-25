#!/bin/bash

my_array=(apple banana "Fruit basket" orange)

# array members need not be consecutive or contingous
# some may be left uninitialized
new_array[2]=apricot

#      v  what is this? 
echo ${#my_array[@]}

echo ${my_array[3]}

my_array[4]="carrot"


# gives count of the whole array
echo ${#my_array[@]}

# gives the whole array
echo ${my_array[@]}

# --- 

NAMES=( John Eric Jessica )
NUMBERS=(1 2 3)
STRINGS=(hello world)
NumberOfNames=${#NAMES[@]}
second_name=${NAMES[1]}

echo "----------------------"
echo $NumberOfNames
echo $second_name

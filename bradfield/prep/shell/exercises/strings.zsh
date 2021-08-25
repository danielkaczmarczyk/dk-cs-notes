# len
STRING="this is a string"
#echo ${#STRING}
SUBSTRING="hat"

#echo ${STRING:3:5}

STRING="to be or not to be"

# replace one
echo ${STRING[@]/be/eat}
# replace all
echo ${STRING[@]//be/eat}
# delete all occurences
echo ${STRING[@]// not}
# replace if at the beginning
echo ${STRING[@]/#to be/eat now}
# as above, but end
echo ${STRING[@]/%be/eat}
# replace with a cmd output
echo ${STRING[@]/%be/be on $(date +%Y-%m-%d)}


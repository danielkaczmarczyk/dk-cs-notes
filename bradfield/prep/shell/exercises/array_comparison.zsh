a=(3 5 8 10 6)
b=(6 5 4 12)
c=(4 7 5 7 6)

# compare a and b
for x in "${a[@]}"; do
  in=false
  for y in "${b[@]}"; do
    if [ $x = $y ]; then
      # assign to a new array z
      z[${#z[@]}]=$x
    fi
  done
done

for i in "${c[@]}"; do
  in=false
  for k in "${z[@]}"; do
    if [ $i = $k ]; then
      # assigning the matching results to new array j
      j[${#j[@]}]=$i
    fi
  done
done

echo ${j[@]}

#!/bin/zsh

NAMES=(Joe Jenny Sara Tony)
for NAME in ${NAMES[@]}; do
  echo "My name is $NAME"
done

echo "----------"

for f in $(ls .); do
  echo "File is: $f"
done

COUNT=4

while [ $COUNT -gt 0 ]; do
  echo "COUNT: $COUNT"
  if [ $COUNT -eq 3 ]; then
    echo "see ya"
    break
  fi
  COUNT=$((COUNT - 1))
done

until [ $COUNT -gt 10 ]; do
  if [ $COUNT -eq 5 ]; then
    echo "fivey mate"
    COUNT=$((COUNT + 1))
    continue
  fi
  echo "COUNT: $COUNT"
  COUNT=$((COUNT + 1))
done



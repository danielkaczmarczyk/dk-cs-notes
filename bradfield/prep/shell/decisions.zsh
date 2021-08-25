NAME="John"
NAME="Bill"
NAME="George"
NAME="Daniel"
if [ "$NAME" = "John" ]; then
  echo "True - my name is indeed John"
elif [ "$NAME" = "George" ]; then
  echo "George Harrison"
else
  echo "False"
  echo "You mistaken me for $NAME"
fi

VAR_A=-10
VAR_B=ree
VAR_T=tee

if [[ $VAR_A -lt 1 && ($VAR_B = "bee" || $VAR_T = "tee") ]]; then
  echo "uh oh"
fi

variable=3
condition=1
condition_2=3

case "$variable" in
  "$condition" )
    echo "1 is satisfied"
    ;;
  "$condition_2" )
    echo "2 is satisfied"
    ;;
esac


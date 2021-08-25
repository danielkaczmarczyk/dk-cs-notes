#!/bin/bash

NUM_APPLES=5
APPLE_PRICE=10
echo "There are $NUM_APPLES in my pocket."
echo "With the price being \$${APPLE_PRICE}, that is a lot of money!"
echo "Sadly, bash isn't great with arithmetic ;("

GREETING="hello,            world!"

echo $GREETING
# encapsulating a variable with quotes preservers spacing
echo "$GREETING"

# substitution can be done using backticks or $()
files=`ls -alf`

echo "files: ${files}"

FILENAME_WITH_TIMESAMP=/bin/bash_$(/bin/date +%Y-%m-%d).txt

echo $FILENAME_WITH_TIMESAMP



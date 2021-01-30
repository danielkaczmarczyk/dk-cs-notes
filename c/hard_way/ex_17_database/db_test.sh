#!/bin/zsh

TEST_DB_FILE="./db.dat"

echo "Database test in progress... \n\n"

# if the test db file exists, delete it
if test -f "$TEST_DB_FILE"; then
  rm $TEST_DB_FILE
  echo '_>_> removed `./db.dat`'
fi

# populate the db
# view data
# alter data
# view data
# remove data
# view data
# cleanup


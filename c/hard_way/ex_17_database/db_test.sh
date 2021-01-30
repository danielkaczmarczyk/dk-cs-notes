#!/bin/zsh

TEST_DB_FILE="./db.dat"
DB=./ex17

echo "Database test in progress..."

# if the test db file exists, delete it
if test -f "$TEST_DB_FILE"; then
  echo "Old database file found. Removing"
  rm $TEST_DB_FILE
  echo "Removed $TEST_DB_FILE"
fi


# create the database
echo "Creating the database"
$DB $TEST_DB_FILE c
echo "Created database in $TEST_DB_FILE"

# populate the db
echo "Creating users"
$DB $TEST_DB_FILE s 1 daniel_kaczmarczyk daniel@dan.dan
$DB $TEST_DB_FILE s 2 bertram_g dinesh_sucks@pied.piper
$DB $TEST_DB_FILE s 3 dinesh_c dinesh@pied.piper
echo "Users created"

# view data
echo "Calling view data:"
$DB $TEST_DB_FILE l
# alter data
# view data
# remove data
# view data
# cleanup


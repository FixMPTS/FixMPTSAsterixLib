#! /bin/sh
export LD_LIBRARY_PATH="$PWD/../build/lib"
echo "Running Asterix test cases ... "

./testAsterix

if [ $? -eq 0 ]
then
  echo "Asterix Lib Unit Test run succeeded"
  exit 0
else
  echo "Asterix Lib Unit Test run failed"
  exit 1
fi
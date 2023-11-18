#!/bin/sh

red='\033[0;31m'
green='\033[32m'
no='\033[0m'

./megaphone "shhhhh... I think the students are asleep..." > actual
echo "SHHHHH... I THINK THE STUDENTS ARE ASLEEP..." > expected

./megaphone Damnit " ! " "Sorry students, I thought this thing was off." >> actual
echo "DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF." >> expected

./megaphone >> actual
echo "* LOUD AND UNBEARABLE FEEDBACK NOISE *" >> expected

diff actual expected
a=`echo $?`
if [ $a -eq 0 ]
then
  echo ${green}OK${no}
else
  echo ${red}KO!${no}
fi
rm -rf actual expected
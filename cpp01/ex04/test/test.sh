#!/bin/bash

RED='\033[0;31m'
GREEN='\033[32m'
STOP='\033[0m'

#create new file
python3 -c 'print(("a" * 100 + "b" * 100) * 100 + "AB" * 10
+ "CDEFGHIJKLMNOPQRSTUVWXWZ" + "cdefghijklmnopqrstuvwxyz")' > test.txt

./replace test.txt "a" "b" && cat test.txt.replace > actual
sed -e "s/a/b/g" test.txt > expected

diff actual expected
result=`echo $?`
if [ $result -eq 0 ]
then
  echo -e ${GREEN}pefect!!!!!!${STOP}
else
  echo -e ${RED}not pefect....${STOP}
fi

rm -f actual expected test.txt

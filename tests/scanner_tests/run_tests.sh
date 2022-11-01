#!/bin/sh

bminor=./bminor
path=./tests/scanner_tests

for testfile in $path/good*.bminor
do
	if $bminor -scan $testfile > $testfile.out
	then
		echo "$testfile success (as expected)"
	else
		echo "$testfile failure (INCORRECT)"
	fi
done

for testfile in $path/bad*.bminor
do
	if $bminor -scan $testfile > $testfile.out
	then
		echo "$testfile success (INCORRECT)"
	else
		echo "$testfile failure (as expected)"
	fi
done

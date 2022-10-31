#!/bin/sh

bminor=./bminor
path=./tests/printer_tests/sample

for testfile in $path/good*.bminor
do
    if $bminor -print $testfile > $testfile.out.1; then
        if $bminor -print $testfile.out.1 > testfile.out.2; then
            if cmp -s $testfile.out.1 testfile.out.2; then
                echo "$testfile success (as expected)"
            fi
        else
            echo "$testfile failure (INCORRECT)"
        fi
    else
        echo "$testfile failure (INCORRECT)"
    fi
done

for testfile in $path/bad*.bminor
do
    if $bminor -print $testfile > $testfile.out.1; then
        if $bminor -print $testfile.out.1 > testfile.out.2; then
            if cmp -s $testfile.out.1 testfile.out.2; then
                echo "$testfile failure (INCORRECT)"
            fi
        else
            echo "$testfile success (as expected)"
        fi
    else
        echo "$testfile success (as expected)"
    fi
done

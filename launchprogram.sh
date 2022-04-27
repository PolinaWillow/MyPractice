#!/bin/bash
make test
echo ""
echo "N = 10"
for i in {1..7}
do
    ./program BinarySearch 0Data.txt 0Find.txt 0Result 10
done
wait
echo ""
echo "N = 100"
for i in {1..7}
do
    ./program BinarySearch 1Data.txt 1Find.txt 1Result 100
done
wait
echo ""
echo "N = 1000"
for i in {1..7}
do
    ./program BinarySearch 2Data.txt 2Find.txt 2Result 1000
done
wait
echo ""
echo "N = 10000"
for i in {1..7}
do
    ./program BinarySearch 3Data.txt 3Find.txt 3Result 10000
done
wait
echo ""
echo "N = 100000"
for i in {1..7}
do
    ./program BinarySearch 4Data.txt 4Find.txt 4Result 100000
done
wait
echo ""
echo "N = 1000000"
for i in {1..7}
do
    ./program BinarySearch 5Data.txt 5Find.txt 5Result 1000000
done
wait
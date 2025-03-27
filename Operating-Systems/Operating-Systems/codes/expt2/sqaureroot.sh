echo "Enter the number"
read n
root=$(echo "scale=2; sqrt($n)" | bc)
echo "Square Root of $n is $root"

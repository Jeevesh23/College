echo "Enter the principal amount"
read p
echo "Enter the Rate"
read r
echo "Enter the Time period"
read t

si=$((($p*$r*$t)/100))

echo "The Simple interest is $si"

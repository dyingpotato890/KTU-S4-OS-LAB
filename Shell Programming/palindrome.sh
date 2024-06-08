echo "Enter The Word: "
read word

length=${#word}
rev=""

for((i=length-1;i>=0;i--)); do
    rev="$rev${word:$i:1}"
done

if [ "$word" == "$rev" ]; then
    echo "The Given Word Is A Palindrome"
else
    echo "The Given Word Is Not A Palindrome"
fi
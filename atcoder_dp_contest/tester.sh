

for((i = 1; i <= 1000; ++i)); do
    echo $i
    ./gen.exe > in1.txt
    # cat in1.txt
    ./n.exe < in1.txt > out1.txt
    ./ans.exe < in1.txt > out2.txt
    diff -w out1.txt out2.txt || break
done

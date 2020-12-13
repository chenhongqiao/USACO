for f in $(ls bin)
do
	mkdir $f
	mv bin/$f $f/
done

for f in $(ls)
do
	mv src/"$f.cpp" $f/
done

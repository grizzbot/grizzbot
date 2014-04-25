#1 /bin/bash
cd $(dirname $0)
for d in $(ls) ; do
    echo "----------------------------"
    echo "---- $d"
    echo "----------------------------"

    cd $d

    make clean
    make all
done


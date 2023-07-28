if [ ! -z $CAT_SOURCE_PATH ]; then
    echo "Syncing cat source code..."
    rm src/main/c/cat/*.c 
    rm src/main/c/cat/*.h
    cp $CAT_SOURCE_PATH/*.c src/main/c/cat
    cp $CAT_SOURCE_PATH/*.h src/main/c/cat
fi

if [ ! -z $HEXDUMP_SOURCE_PATH ]; then
    echo "Syncing hexdump source code..."
    rm src/main/c/hexdump/*.c 
    rm src/main/c/hexdump/*.h
    cp $HEXDUMP_SOURCE_PATH/*.c src/main/c/hexdump
    cp $HEXDUMP_SOURCE_PATH/*.h src/main/c/hexdump
fi

if [ ! -z $LS_SOURCE_PATH ]; then
    echo "Syncinc ls source code..."
    rm src/main/c/ls/*.c 
    rm src/main/c/ls/*.h
    cp $LS_SOURCE_PATH/*.c src/main/c/ls
    cp $LS_SOURCE_PATH/*.h src/main/c/ls
fi
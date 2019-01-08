#!/usr/bin/env bash


CLASS_PATH=""

for v_jar in $(find lib -name "*.jar" -print)
do
    CLASS_PATH=${CLASS_PATH}:${v_jar}
done

java -cp ${CLASS_PATH} com.saligia.study.Main
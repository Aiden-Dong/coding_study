#!/usr/bin/env bash


CLASS_PATH=""


for v_jar in $(find lib -name "*.jar" -print)
do
    CLASS_PATH=${v_jar}:${CLASS_PATH}
done

CLASS_PATH=${CLASS_PATH}:webapp

java -cp ${CLASS_PATH} com.saligia.spring.mvc.start.Main
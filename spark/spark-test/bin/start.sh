#!/usr/bin/env bash

spark-submit --class SparkSqlTest \
--deploy-mode cluster \
--driver-memory 1g \
--executor-memory 2g \
--executor-cores 1 \
--num-executors 1 \
target/spark-test-1.0.jar "Hello world" "agin" "123" "32464" "djsfak"

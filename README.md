# non-root-docker
Testing scenarios with non root docker-in-docker users

The host mounts a named volume into a docker container named sidecar. The sidecar creates input/output/log directories into those volumes and mounts them again into another docker conatiner named car. The car the reads/writes into those directories. This should all work as non-root users

## sidecar
Simple python script that creates and runs a docker container via the docker python API. 

## car
Simple c++ program that reads and writes to file.

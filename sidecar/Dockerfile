FROM python:3.6-alpine as base

LABEL maintainer=mguidon

ARG DOCKER_GID_ARG=1042

# create user `scu` and `docker` group (with same id as in host)
RUN adduser -D -u 8004 scu &&\
    addgroup -g $DOCKER_GID_ARG docker

RUN addgroup scu docker

RUN pip install docker

RUN mkdir /home/scu/input
RUN mkdir /home/scu/output
RUN mkdir /home/scu/log

RUN chown -R scu:scu /home/scu/input
RUN chown -R scu:scu /home/scu/output
RUN chown -R scu:scu /home/scu/log


USER scu

COPY --chown=scu:scu ./test_sidecar.py /home/scu/test_sidecar.py

WORKDIR /home/scu

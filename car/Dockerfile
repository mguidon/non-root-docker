FROM alpine:3.7

MAINTAINER  Manuel guidon <guidon@itis.ethz.ch>

ARG DOCKER_GID_ARG=1042

RUN apk add --no-cache g++ bash make

RUN adduser -D -u 8004 scu &&\
    addgroup -g $DOCKER_GID_ARG docker

RUN addgroup scu docker
RUN mkdir /home/scu/input
RUN mkdir /home/scu/output
RUN mkdir /home/scu/log

RUN chown -R scu:scu /home/scu/input
RUN chown -R scu:scu /home/scu/output
RUN chown -R scu:scu /home/scu/log

USER scu

COPY --chown=scu:scu ./src /home/scu/src
COPY --chown=scu:scu ./Makefile /home/scu/Makefile
COPY --chown=scu:scu ./simcore.cli /home/scu/simcore.cli
RUN chmod +x /home/scu/simcore.cli/*
ENV PATH="/home/scu/simcore.cli:${PATH}"


WORKDIR /home/scu

RUN make build-solver

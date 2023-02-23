FROM ubuntu:20.04
ENV TZ=America/Mexico_City
ENV DEBIAN_FRONTEND=noninteractive 
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone
RUN apt-get update && apt-get -y update
RUN apt install -y curl 
RUN apt install -y sl 
RUN apt install -y zip unzip
RUN apt install -y nano
RUN apt install -y wget

RUN mkdir -p /root/workspace
WORKDIR /root

RUN apt-get update && apt-get install -y --no-install-recommends locales
RUN apt update
RUN apt install make
RUN apt install -y build-essential
RUN apt install gcc
RUN apt -y install gdb
RUN apt install valgrind
RUN apt install g++
RUN apt -y install default-jdk
WORKDIR /root/workspace

ENV LANG=en_US.UTF-8 
RUN echo $LANG UTF-8 > /etc/locale.gen 
RUN locale-gen 
RUN update-locale LANG=$LANG
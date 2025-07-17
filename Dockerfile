FROM ubuntu:22.04

RUN apt-get update && apt-get install -y \
		sudo \
		vim \
		git \
		make \
		g++ \
		curl && apt-get clean && rm -rf /var/lib/apt/lists/*

WORKDIR /app


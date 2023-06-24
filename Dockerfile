FROM ubuntu:18.04

LABEL author="Lilekov 221-3210"

ENV TZ=Europe/Moscow
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

RUN apt-get update
RUN apt-get install build-essential -y
RUN apt-get install cmake -y

WORKDIR /MyProj_221-3210_lilekov
COPY *.cpp .
COPY *.h .
COPY *.txt .

WORKDIR /MyProj_221-3210_lilekov/build
RUN cmake ..
RUN make

WORKDIR /MyProj_221-3210_lilekov
ENTRYPOINT ["./my_Program"]

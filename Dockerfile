FROM ubuntu:bionic

MAINTAINER caiopoliveira@gmail.com

WORKDIR /home

RUN apt-get update

RUN apt-get install -y \
        bc \
        bin86 \
        build-essential \
        gdb \
        gcc-multilib \
        g++-multilib \
        make \
        python3 \
        python3-pip \
        qemu \
        qemu-kvm \
        qemu-system-arm \
        tar \
        tcsh \
        wget
    # sudo apt-get clean && \
    # rm -rf /var/lib/apt/lists/* && \

# RUN pip3 install pyserial

RUN wget https://github.com/Yelp/dumb-init/releases/download/v1.2.2/dumb-init_1.2.2_amd64.deb && \
    dpkg -i dumb-init_*.deb && \
    rm dumb-init_*.deb

RUN wget -q -O arm.tar.gz https://epos.lisha.ufsc.br/dl468 && \
    wget -q -O ia32.tar.gz https://epos.lisha.ufsc.br/dl469


RUN tar -zxvf ia32.tar.gz && \
    mkdir -p /usr/local/ia32/ && \
    mv gcc-7.2.0 /usr/local/ia32/ && \
    rm -r ia32.tar.gz

RUN tar -zxvf arm.tar.gz && \
    mkdir -p /usr/local/arm/ && \
    mv gcc-7.2.0 /usr/local/arm/ && \
    rm -r arm.tar.gz

RUN apt-get install -y xterm

ENTRYPOINT ["/usr/bin/dumb-init", "--"]

VOLUME /code

WORKDIR /code

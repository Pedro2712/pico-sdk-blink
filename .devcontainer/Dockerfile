# See here for image contents: https://github.com/microsoft/vscode-dev-containers/tree/v0.177.0/containers/cpp/.devcontainer/base.Dockerfile

# [Choice] Debian / Ubuntu version: debian-10, debian-9, ubuntu-20.04, ubuntu-18.04
ARG VARIANT="ubuntu-22.04"

FROM mcr.microsoft.com/vscode/devcontainers/cpp:0-$VARIANT

ENV TOOLCHAINURL="https://developer.arm.com/-/media/Files/downloads/gnu/11.3.rel1/binrel"
ENV TOOLCHAINARCHIVE="arm-gnu-toolchain-11.3.rel1-x86_64-arm-none-eabi.tar.xz"
ENV TOOLCHAINDIR="arm-gnu-toolchain-11.3.rel1-x86_64-arm-none-eabi"

# [Optional] Uncomment this section to install additional packages.
RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
    && apt-get -y install --no-install-recommends cmake build-essential wget ca-certificates \
    gdb-multiarch automake autoconf libtool libftdi-dev libusb-1.0-0-dev pkg-config clang-format libhidapi-dev
WORKDIR /apps

RUN echo "$TOOLCHAINURL/$TOOLCHAINARCHIVE"

RUN wget $TOOLCHAINURL/$TOOLCHAINARCHIVE 
RUN tar xf $TOOLCHAINARCHIVE

RUN mv $TOOLCHAINDIR gcc-arm-none && \
    rm $TOOLCHAINARCHIVE
ENV PATH=$PATH:/apps/gcc-arm-none/bin

RUN git clone -b master https://github.com/raspberrypi/pico-sdk.git --depth=1 && git -C pico-sdk submodule update --init
ENV PICO_SDK_PATH=/apps/pico-sdk

RUN git clone https://github.com/openocd-org/openocd.git --depth=1 --recurse-submodules \
# RUN git clone https://github.com/raspberrypi/openocd.git --depth=1 --recurse-submodules \
    && cd openocd && ./bootstrap && ./configure --enable-ftdi --enable-sysfsgpio --enable-picoprobe --enable-cmsis-dap && make -j 8 install 

RUN cd /apps && git clone https://github.com/raspberrypi/picotool.git --depth=1 \
    && cd picotool && mkdir build && cd build && cmake ../ && make -j 8 && cp picotool /usr/local/bin

RUN cd /apps && git clone https://github.com/wtarreau/bootterm.git --depth=1 \
    && cd bootterm && make -j 8 install 

RUN usermod -aG plugdev vscode


# Compile Custom Chips
RUN apt-get -y install clang lld git make llvm

RUN git clone https://github.com/CraneStation/wasi-libc.git && \
    cd wasi-libc && \
    make install INSTALL_DIR=/opt/wasi-libc && \
    cd ../ && \
    rm -rf wasi-libc

RUN mkdir -p /usr/lib/llvm16/lib/clang/16/lib/wasi && \
    wget -O /usr/lib/llvm16/lib/clang/16/lib/wasi/libclang_rt.builtins-wasm32.a https://github.com/jedisct1/libclang_rt.builtins-wasm32.a/blob/master/precompiled/llvm-15-to-16/libclang_rt.builtins-wasm32.a?raw=true

RUN curl -L https://wokwi.com/ci/install.sh | sh

#!/bin/bash

if [ $# -ne 2 -a $# -ne 3 ]
then
    echo "Usage: $0 <custom.json> <ipaddr> [<netmask>]"
    exit 1
fi

CONFIG_FILE=${1}
IP_ADDRESS=${2}
if [ $# -eq 3 ]
then
    NETMASK=${3}
else
    NETMASK="255.255.255.0"
fi

# generate proxy
bash create_proxy.bash ${CONFIG_FILE}


# copy sources on mros2-posix
if [ ! -d mros2-posix/workspace/hako_pdu_proxy ]
then
    mkdir mros2-posix/workspace/hako_pdu_proxy
fi
if [ ! -d mros2-posix/workspace/hako_pdu_proxy/gen ]
then
    mkdir mros2-posix/workspace/hako_pdu_proxy/gen
fi

cp workspace/src/hako_pdu_proxy/src/*.* mros2-posix/workspace/hako_pdu_proxy/
cp workspace/src/hako_pdu_proxy/src/gen/app.cpp mros2-posix/workspace/hako_pdu_proxy/
cp workspace/src/hako_pdu_proxy/src/gen/hako_*.cpp mros2-posix/workspace/hako_pdu_proxy/gen/

# mros2 config settings
sed -e "s/NETIF_IPADDR \"[0-9\.]*\"/NETIF_IPADDR \"$IP_ADDRESS\"/g" \
    -e "s/NETIF_NETMASK \"[0-9\.]*\"/NETIF_NETMASK \"$NETMASK\"/g" mros2-posix/include/netif.h > tmp.txt
mv tmp.txt mros2-posix/include/netif.h
rm -f tmp.txł

FORMATTED_IP=$(echo $IP_ADDRESS | sed 's/\./, /g')
sed -E "/Needs to be set in lwipcfg.h too./s/[0-9, ]+}/    $FORMATTED_IP }/" mros2-posix/include/rtps/config.h > tmp.txt
mv tmp.txt mros2-posix/include/rtps/config.h
rm -f tmp.txł


# mros2-posix patch
cp template/mros2-patch/CMakeLists.txt mros2-posix/CMakeLists.txt
cp template/mros2-patch/stats.c mros2-posix/lwip-posix/lwip/src/core/stats.c
cp template/mros2-patch/lwip.c mros2-posix/lwip-posix/src/core/lwip.c

# build mros2-posix for hako_pdu_proxy

cd mros2-posix

bash build.bash clean
bash build.bash all hako_pdu_proxy


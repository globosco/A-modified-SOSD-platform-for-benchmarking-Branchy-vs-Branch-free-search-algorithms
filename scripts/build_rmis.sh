#! /usr/bin/env bash
# git submodule update --init --recursive

mkdir -p rmi_data


function build_rmi_set() {
    DATA_NAME=$1
    HEADER_PATH=competitors/rmi/${DATA_NAME}_0.h
    JSON_PATH=scripts/rmi_specs/${DATA_NAME}.json

    shift 1
    if [ ! -f $HEADER_PATH ]; then
        echo "Building RMI set for $DATA_NAME"
        RMI/target/release/rmi data/$DATA_NAME --param-grid ${JSON_PATH} -d rmi_data/ --threads 8 --zero-build-time
        mv ${DATA_NAME}_* competitors/rmi/
    fi
}


cd RMI && cargo build --release && cd ..

#build_rmi_set L1_books_200M_uint32
TIMEFORMAT=%2U
utime="$( TIMEFORMAT='%U';time ( build_rmi_set L1_books_200M_uint32 ) 2>&1 1>/dev/null )"
echo "L1_books_200M_uint32 RMI Build Time: "$utime"s" >> scripts/logs/L1_books_200M_uint32.log

#build_rmi_set L1_books_200M_uint64
TIMEFORMAT=%2U
utime="$( TIMEFORMAT='%U';time ( build_rmi_set L1_books_200M_uint64 ) 2>&1 1>/dev/null )"
echo "L1_books_200M_uint64 RMI Build Time: "$utime"s" >> scripts/logs/L1_books_200M_uint64.log

#build_rmi_set L1_fb_200M_uint64
TIMEFORMAT=%2U
utime="$( TIMEFORMAT='%U';time ( build_rmi_set L1_fb_200M_uint64 ) 2>&1 1>/dev/null )"
echo "L1_fb_200M_uint64 RMI Build Time: "$utime"s" >> scripts/logs/L1_fb_200M_uint64.log

#build_rmi_set L1_logistic_uint64
TIMEFORMAT=%2U
utime="$( TIMEFORMAT='%U';time ( build_rmi_set L1_logistic_uint64 ) 2>&1 1>/dev/null )"
echo "L1_logistic_uint64 RMI Build Time: "$utime"s" >> scripts/logs/L1_logistic_uint64.log

#build_rmi_set L1_lognormal_uint64
TIMEFORMAT=%2U
utime="$( TIMEFORMAT='%U';time ( build_rmi_set L1_lognormal_uint64 ) 2>&1 1>/dev/null )"
echo "L1_lognormal_uint64 RMI Build Time: "$utime"s" >> scripts/logs/L1_lognormal_uint64.log

#build_rmi_set L1_osm_cellids_200M_uint64
TIMEFORMAT=%2U
utime="$( TIMEFORMAT='%U';time ( build_rmi_set L1_osm_cellids_200M_uint64 ) 2>&1 1>/dev/null )"
echo "L1_osm_cellids_200M_uint64 RMI Build Time: "$utime"s" >> scripts/logs/L1_osm_cellids_200M_uint64.log

#build_rmi_set L1_uniform_uint64
TIMEFORMAT=%2U
utime="$( TIMEFORMAT='%U';time ( build_rmi_set L1_uniform_uint64 ) 2>&1 1>/dev/null )"
echo "L1_uniform_uint64 RMI Build Time: "$utime"s" >> scripts/logs/L1_uniform_uint64.log

#build_rmi_set L1_wiki_ts_200M_uint64
TIMEFORMAT=%2U
utime="$( TIMEFORMAT='%U';time ( build_rmi_set L1_wiki_ts_200M_uint64 ) 2>&1 1>/dev/null )"
echo "L1_wiki_ts_200M_uint64 RMI Build Time: "$utime"s" >> scripts/logs/L1_wiki_ts_200M_uint64.log

#build_rmi_set L2_books_200M_uint32
TIMEFORMAT=%2U
utime="$( TIMEFORMAT='%U';time ( build_rmi_set L2_books_200M_uint32 ) 2>&1 1>/dev/null )"
echo "L2_books_200M_uint32 RMI Build Time: "$utime"s" >> scripts/logs/L2_books_200M_uint32.log

#build_rmi_set L2_books_200M_uint64
TIMEFORMAT=%2U
utime="$( TIMEFORMAT='%U';time ( build_rmi_set L2_books_200M_uint64 ) 2>&1 1>/dev/null )"
echo "L2_books_200M_uint64 RMI Build Time: "$utime"s" >> scripts/logs/L2_books_200M_uint64.log

#build_rmi_set L2_fb_200M_uint64
TIMEFORMAT=%2U
utime="$( TIMEFORMAT='%U';time ( build_rmi_set L2_fb_200M_uint64 ) 2>&1 1>/dev/null )"
echo "L2_fb_200M_uint64 RMI Build Time: "$utime"s" >> scripts/logs/L2_fb_200M_uint64.log

#build_rmi_set L2_logistic_uint64
TIMEFORMAT=%2U
utime="$( TIMEFORMAT='%U';time ( build_rmi_set L2_logistic_uint64 ) 2>&1 1>/dev/null )"
echo "L2_logistic_uint64 RMI Build Time: "$utime"s" >> scripts/logs/L2_logistic_uint64.log

#build_rmi_set L2_lognormal_uint64
TIMEFORMAT=%2U
utime="$( TIMEFORMAT='%U';time ( build_rmi_set L2_lognormal_uint64 ) 2>&1 1>/dev/null )"
echo "L2_lognormal_uint64 RMI Build Time: "$utime"s" >> scripts/logs/L2_lognormal_uint64.log

#build_rmi_set L2_osm_cellids_200M_uint64
TIMEFORMAT=%2U
utime="$( TIMEFORMAT='%U';time ( build_rmi_set L2_osm_cellids_200M_uint64 ) 2>&1 1>/dev/null )"
echo "L2_osm_cellids_200M_uint64 RMI Build Time: "$utime"s" >> scripts/logs/L2_osm_cellids_200M_uint64.log

#build_rmi_set L2_uniform_uint64
TIMEFORMAT=%2U
utime="$( TIMEFORMAT='%U';time ( build_rmi_set L2_uniform_uint64 ) 2>&1 1>/dev/null )"
echo "L2_uniform_uint64 RMI Build Time: "$utime"s" >> scripts/logs/L2_uniform_uint64.log

#build_rmi_set L2_wiki_ts_200M_uint64
TIMEFORMAT=%2U
utime="$( TIMEFORMAT='%U';time ( build_rmi_set L2_wiki_ts_200M_uint64 ) 2>&1 1>/dev/null )"
echo "L2_wiki_ts_200M_uint64 RMI Build Time: "$utime"s" >> scripts/logs/L2_wiki_ts_200M_uint64.log

#build_rmi_set L3_books_200M_uint32
TIMEFORMAT=%2U
utime="$( TIMEFORMAT='%U';time ( build_rmi_set L3_books_200M_uint32 ) 2>&1 1>/dev/null )"
echo "L3_books_200M_uint32 RMI Build Time: "$utime"s" >> scripts/logs/L3_books_200M_uint32.log

#build_rmi_set L3_books_200M_uint64
TIMEFORMAT=%2U
utime="$( TIMEFORMAT='%U';time ( build_rmi_set L3_books_200M_uint64 ) 2>&1 1>/dev/null )"
echo "L3_books_200M_uint64 RMI Build Time: "$utime"s" >> scripts/logs/L3_books_200M_uint64.log

#build_rmi_set L3_fb_200M_uint64
TIMEFORMAT=%2U
utime="$( TIMEFORMAT='%U';time ( build_rmi_set L3_fb_200M_uint64 ) 2>&1 1>/dev/null )"
echo "L3_fb_200M_uint64 RMI Build Time: "$utime"s" >> scripts/logs/L3_fb_200M_uint64.log

#build_rmi_set L3_logistic_uint64
TIMEFORMAT=%2U
utime="$( TIMEFORMAT='%U';time ( build_rmi_set L3_logistic_uint64 ) 2>&1 1>/dev/null )"
echo "L3_logistic_uint64 RMI Build Time: "$utime"s" >> scripts/logs/L3_logistic_uint64.log

#build_rmi_set L3_lognormal_uint64
TIMEFORMAT=%2U
utime="$( TIMEFORMAT='%U';time ( build_rmi_set L3_lognormal_uint64 ) 2>&1 1>/dev/null )"
echo "L3_lognormal_uint64 RMI Build Time: "$utime"s" >> scripts/logs/L3_lognormal_uint64.log

#build_rmi_set L3_osm_cellids_200M_uint64
TIMEFORMAT=%2U
utime="$( TIMEFORMAT='%U';time ( build_rmi_set L3_osm_cellids_200M_uint64 ) 2>&1 1>/dev/null )"
echo "L3_osm_cellids_200M_uint64 RMI Build Time: "$utime"s" >> scripts/logs/L3_osm_cellids_200M_uint64.log

#build_rmi_set L3_uniform_uint64
TIMEFORMAT=%2U
utime="$( TIMEFORMAT='%U';time ( build_rmi_set L3_uniform_uint64 ) 2>&1 1>/dev/null )"
echo "L3_uniform_uint64 RMI Build Time: "$utime"s" >> scripts/logs/L3_uniform_uint64.log

#build_rmi_set L3_wiki_ts_200M_uint64
TIMEFORMAT=%2U
utime="$( TIMEFORMAT='%U';time ( build_rmi_set L3_wiki_ts_200M_uint64 ) 2>&1 1>/dev/null )"
echo "L3_wiki_ts_200M_uint64 RMI Build Time: "$utime"s" >> scripts/logs/L3_wiki_ts_200M_uint64.log

#build_rmi_set L4_books_200M_uint32
TIMEFORMAT=%2U
utime="$( TIMEFORMAT='%U';time ( build_rmi_set L4_books_200M_uint32 ) 2>&1 1>/dev/null )"
echo "L4_books_200M_uint32 RMI Build Time: "$utime"s" >> scripts/logs/L4_books_200M_uint32.log

#build_rmi_set L4_books_200M_uint64
TIMEFORMAT=%2U
utime="$( TIMEFORMAT='%U';time ( build_rmi_set L4_books_200M_uint64 ) 2>&1 1>/dev/null )"
echo "L4_books_200M_uint64 RMI Build Time: "$utime"s" >> scripts/logs/L4_books_200M_uint64.log

#build_rmi_set L4_fb_200M_uint64
TIMEFORMAT=%2U
utime="$( TIMEFORMAT='%U';time ( build_rmi_set L4_fb_200M_uint64 ) 2>&1 1>/dev/null )"
echo "L4_fb_200M_uint64 RMI Build Time: "$utime"s" >> scripts/logs/L4_fb_200M_uint64.log

#build_rmi_set L4_fb_200M_no_outlayers_uint64
TIMEFORMAT=%2U
utime="$( TIMEFORMAT='%U';time ( build_rmi_set L4_fb_200M_no_outlayers_uint64 ) 2>&1 1>/dev/null )"
echo "L4_fb_200M_no_outlayers_uint64 RMI Build Time: "$utime"s" >> scripts/logs/L4_fb_200M_no_outlayers_uint64.log


#build_rmi_set L4_logistic_uint64
TIMEFORMAT=%2U
utime="$( TIMEFORMAT='%U';time ( build_rmi_set L4_logistic_uint64 ) 2>&1 1>/dev/null )"
echo "L4_logistic_uint64 RMI Build Time: "$utime"s" >> scripts/logs/L4_logistic_uint64.log

#build_rmi_set L4_lognormal_uint64
TIMEFORMAT=%2U
utime="$( TIMEFORMAT='%U';time ( build_rmi_set L4_lognormal_uint64 ) 2>&1 1>/dev/null )"
echo "L4_lognormal_uint64 RMI Build Time: "$utime"s" >> scripts/logs/L4_lognormal_uint64.log

#build_rmi_set L4_osm_cellids_200M_uint64
TIMEFORMAT=%2U
utime="$( TIMEFORMAT='%U';time ( build_rmi_set L4_osm_cellids_200M_uint64 ) 2>&1 1>/dev/null )"
echo "L4_osm_cellids_200M_uint64 RMI Build Time: "$utime"s" >> scripts/logs/L4_osm_cellids_200M_uint64.log

#build_rmi_set L4_uniform_uint64
TIMEFORMAT=%2U
utime="$( TIMEFORMAT='%U';time ( build_rmi_set L4_uniform_uint64 ) 2>&1 1>/dev/null )"
echo "L4_uniform_uint64 RMI Build Time: "$utime"s" >> scripts/logs/L4_uniform_uint64.log

#build_rmi_set L4_wiki_ts_200M_uint64
TIMEFORMAT=%2U
utime="$( TIMEFORMAT='%U';time ( build_rmi_set L4_wiki_ts_200M_uint64 ) 2>&1 1>/dev/null )"
echo "L4_wiki_ts_200M_uint64 RMI Build Time: "$utime"s" >> scripts/logs/L4_wiki_ts_200M_uint64.log

scripts/rmi_specs/gen.sh

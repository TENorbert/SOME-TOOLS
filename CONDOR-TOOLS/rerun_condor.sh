#!/bin/sh

rundir=data/${1}
#/data/whybee1a/user/klapoetke/${1}
#'bad_alloc exception was thrown'
#'Cannot allocate memory'
#'segmentation violation'
for log in `ls ${rundir}/log/*.err.gz`; do
    tester=`zcat $log | grep 'bad_alloc'`
        if [ -n "$tester" ]; then
	cfg1=${log#${rundir}/log/}    
	cfg2=${cfg1%.err.gz}
	cfg3=${cfg2}_cfg.py     
	cfg=${rundir}/cfg/${cfg3}
	listocfg="${listocfg}${cfg} "
#	condor_rerun.perl $cfg
#	sleep 1
    fi
done
for log in `ls ${rundir}/log/*.err.gz`; do
    tester=`zcat $log | grep 'Cannot allocate memory'`
    if [ -n "$tester" ]; then
	cfg1=${log#${rundir}/log/}    
	cfg2=${cfg1%.err.gz}
	cfg3=${cfg2}_cfg.py     
	cfg=${rundir}/cfg/${cfg3}
	listocfg="${listocfg}${cfg} "
#	condor_rerun.perl $cfg
#	sleep 1
    fi
done
for log in `ls ${rundir}/log/*.err.gz`; do
    tester=`zcat $log | grep 'segmentation violation'`
    if [ -n "$tester" ]; then
	cfg1=${log#${rundir}/log/}    
	cfg2=${cfg1%.err.gz}
	cfg3=${cfg2}_cfg.py     
	cfg=${rundir}/cfg/${cfg3}
	listocfg="${listocfg}${cfg} "
#	condor_rerun.perl $cfg
#	sleep 1
    fi
    
done
for log in `ls ${rundir}/log/*.err.gz`; do
    tester=`zcat $log | grep 'FileOpenError'`
        if [ -n "$tester" ]; then
	cfg1=${log#${rundir}/log/}    
	cfg2=${cfg1%.err.gz}
	cfg3=${cfg2}_cfg.py     
	cfg=${rundir}/cfg/${cfg3}
	listocfg="${listocfg}${cfg} "
#	condor_rerun.perl $cfg
#	sleep 1
    fi
done
for log in `ls ${rundir}/log/*.err.gz`; do
    tester=`zcat $log | grep 'FileReadError'`
        if [ -n "$tester" ]; then
	cfg1=${log#${rundir}/log/}    
	cfg2=${cfg1%.err.gz}
	cfg3=${cfg2}_cfg.py     
	cfg=${rundir}/cfg/${cfg3}
	listocfg="${listocfg}${cfg} "
#	condor_rerun.perl $cfg
#	sleep 1
    fi
done
#echo $listocfg
condor_rerun.perl $listocfg
#condor_rerun.perl
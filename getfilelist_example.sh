#!/bin/bash

rm -rf AuAu27_2018.list 

# in range use
get_file_list.pl -keys 'path,filename' -cond 'storage!=hpss,filetype=daq_reco_picoDst,filename~st_physics,production=P19ib,library=SL19b,trgsetupname=27GeV_production_2018' -limit 0 -distinct -delim '/' >& AuAu27_2018.list

## outside range use
#get_file_list.pl -keys 'path,filename' -cond 'storage=hpss,filetype=daq_reco_MuDst,filename~st_mtd,production=P15ie,trgsetupname=AuAu_200_production_high_2014,runnumber][15166023-15166028,tpx=1,sanity=1' -limit 0 -distinct -delim '/' >& micro.list

## or logic 
#get_file_list.pl -keys 'path,filename' -cond 'storage=hpss,filetype=daq_reco_MuDst,filename~st_mtd,production=P15ie,trgsetupname=AuAu_200_production_high_2014||AuAu_200_production_mid_2014||AuAu_200_production_low_2014,runnumber[]15166001-15166060,tpx=1,sanity=1' -limit 0 -distinct -delim '/' >& micro.list

##day select
#get_file_list.pl -keys 'path,filename' -cond 'storage=local,filetype=daq_reco_MuDst,filename~st_physics,trgsetupname=production_pp201long3_2015||production_pp200long2_2015||production_pp200long_2015||production_pp200trans_2015,daynumber~41,tpx=1,sanity=1' -limit 0 -distinct -delim '/' >& micro.list

##output daynumber
#get_file_list.pl -keys 'daynumber' -cond 'storage=local,filetype=daq_reco_MuDst,filename~st_physics,trgsetupname=production_pp201long3_2015||production_pp200long2_2015||production_pp200long_2015||production_pp200trans_2015,tpx=1,sanity=1' -limit 0 -distinct -delim '/' >& micro.list

## day select 
#get_file_list.pl -keys 'path,filename' -cond 'storage=hpss,filetype=daq_reco_MuDst,filename~st_mtd,production=P15ie,trgsetupname=AuAu_200_production_high_2014||AuAu_200_production_mid_2014||AuAu_200_production_low_2014,daynumber~151' -limit 0 -distinct -delim '/' >& micro.list

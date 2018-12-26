# The Rhythm Laser file specifications

## Table of Contents

1. [Introduction](#Introduction)
2. [The Song Index format](#The-Song-Index-format-info) 
   1. [Values](#Values) 
   2. [General Structure](#General-structure)  

## Introduction

Rhythm Laser (throughout this document RL) uses/will use a lot of different custom file types. In order to cut down file sizes, they are of a binary nature. This means that they can't be processed with simple ASCII I/O, but rather need to be interpreted via a binary decoding system. Furthermore, because RL is in a very early stage, song charts need to be written manually. This means that the writer has to have knowledge of the .sc format, which this document aims to provide.

Please note that any minor changes to any of the specifications will not be announced, this mostly includes small additions. Major changes, of course, will be announced.

## The Song Index format (.info)

The Song Index format encodes general information about the song charts, such as the number of song charts, the file paths and the menu background image. It does not store a lot of information, it merely points to other places a decoder needs to look at to gain more information. This however enables variable file names and avoids a tail-gating file structure or even a monolithic one.

### Values

|Name|Value|Meaning|
|-|-|-|
|SI_DIST|0x72 6c 69|File type distinguisher|
|CHART\_N|uint8\_t n|Number of song charts|
|CHART\_N\_SEP|0xa0|CHART\_N separator|
|nCHARTPATH\_LEN|uint8\_t n|Length of nth chart path name|
|nCHARTPATH\_LEN\_SEP|0xa1|nCHARTPATH\_LEN separator|
|nCHARTPATH|string|Path to the nth chart|
|nCHARTPATH\_SEP|0xa2|nCHARTPATH separator|
|CHART\_SEP|0xa3|CHARTPATH section separator|
|MENUBG\_LEN|uint8\_t n|Length of menu background path|
|MENUBG\_LEN\_SEP|0xa4|MENUBG\_LEN separator|
|MENUBG|string|Path to the menu background|
|MENUBG\_SEP|0xa5|MENUBG separator|
|EOF|0xef|End of .info file|

### General structure

```
/SI_DIST/
/CHART_N/CHART_N_SEP/
/1CHARTPATH_LEN/1CHARTPATH_LEN_SEP/1CHARTPATH/1CHARTPATH_SEP/
/2CHARTPATH_LEN/2CHARTPATH_LEN_SEP/2CHARTPATH/2CHARTPATH_SEP/
/nCHARTPATH_LEN/nCHARTPATH_LEN_SEP/nCHARTPATH/nCHARTPATH_SEP/
/CHART_SEP/
/MENUBG_LEN/MENUBG_LEN_SEP/MENUBG/MENUBG_SEP/
/EOF/
```

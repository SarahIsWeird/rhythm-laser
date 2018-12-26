# The Rhythm Laser file specifications

## Table of Contents

1. [Introduction](#Introduction)
2. [The Song Index format](#The_Song_Index_format)

## Introduction

Rhythm Laser (throughout this document RL) uses/will use a lot of different custom file types. In order to cut down file sizes, they are of a binary nature. This means that they can't be processed with simple ASCII I/O, but rather need to be interpreted via a binary decoding system. Furthermore, because RL is in a very early stage, song charts need to be written manually. This means that the writer has to have knowledge of the .sc format, which this document aims to provide.

Please note that any minor changes to any of the specifications will not be announced, this mostly includes small additions. Major changes, of course, will be announced.

## The Song Index format (.info)

|Name|Hex Value|Meaning|
|-|-|-|
|DIST|0x72 6c 69|File type distinguisher|
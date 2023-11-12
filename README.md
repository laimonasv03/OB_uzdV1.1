**In release v1.0** 
CMake 

testing different strategys on different containers

CPU - AMD Ryzen 5 5600H with Radeon Graphics, 3301 Mhz, 6 Core(s), 12 Logical Processor(s)
GPU - NVIDIA GeForce RTX 3050 Laptop GPU
RAM - 16GB

| Container | File Size | Strategy 1 | Strategy 2 | Strategy 3 |
|-----------|-----------|------------|------------|------------|
| List      | 1000      | 0.013      | 0.002      | 0.002      |
| List      | 10000     | 0.128      | 0.03       | 0.03       |
| List      | 100000    | 1.149      | 0.334      | 0.351      |
| List      | 1000000   | N/A        | 3.85       | 4.019      |
| Vector    | 1000      | 0.019      | 0.247      | 0.009      |
| Vector    | 10000     | 0.208      | 27.963     | 0.107      |
| Vector    | 100000    | 1.515      | N/A        | 0.635      |
| Vector    | 1000000   | 16.76      | N/A        | 7.089      |

﻿


# G3LOG_TEST

## Introduction
&nbsp;&nbsp; A simple example for g3log-1.3.4. It is proven to run well on ubuntu20.04 .

## How to build
&nbsp;&nbsp;(1).Create a folder in the G3LOG_TEST directory named "build".  

&nbsp;&nbsp;(2).Enter "build" folder and Execute the ```cmake ../``` command.  
  
&nbsp;&nbsp;(3).if (2) is success, Execute the ```make``` command.  

&nbsp;&nbsp;(4).if (3) is success, you will get the executable g3log_test in the build folder.

## Running
&nbsp;&nbsp;Execute the ``./``` command, you will get custom_log.*.log like this :  
  
```
g3log created log at: Thu Apr 18 16:44:56 2024
                LOG format: [YYYY/MM/DD hh:mm:ss uuu* LEVEL FILE->FUNCTION:LINE] message

                (uuu*: microseconds fractions of the seconds value)

2024/04/18 16:44:56 446569      INFO [main.cpp->main:23]        This is a custom log message
2024/04/18 16:44:56 446572      E [main.cpp->main:24]   This is a Error message
2024/04/18 16:44:56 446696      FATAL [main.cpp->main:25]
        *******  EXIT trigger caused by LOG(FATAL) entry:
        "This is a Fatal message
******* STACKDUMP *******

        stack dump [1]  ./g3log_test : LogCapture::LogCapture(char const*, int, char const*, LEVELS const&, char const*, int, char const*)+0x2f3 [0x5d2fe05b7be3]
        stack dump [2]  ./g3log_testmain+0x37f [0x5d2fe05af928]
        stack dump [3]  /lib/x86_64-linux-gnu/libc.so.6+0x29d90 [0x718bcc629d90]
        stack dump [4]  /lib/x86_64-linux-gnu/libc.so.6__libc_start_main+0x80 [0x718bcc629e40]
        stack dump [5]  ./g3log_test_start+0x25 [0x5d2fe05af4e5]

Exiting after fatal event  (FATAL). Fatal type:  SIGABRT
Log content flushed successfully to sink

"g3log g3FileSink shutdown at: 16:44:56 446764
```


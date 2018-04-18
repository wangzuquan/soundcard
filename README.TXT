#----------------------------  SOUND SENSOR PROJECT -------------------------

This project is meant to collect sound level at a proximity of a Raspbrerry Pi
device. The RPi is equipped with a USB sound card (C-Media Electronics, Inc.
Audio Adapter) and a microphone. The sound is record at 16000Hz samole rate
and every second will produce 80 pleces of RMS value as a bar-diagram...

Table of contant
1. Configuration instructions:
                 a. Raspberry Pi 3 device.
                 b. 16GB SD Card element 14 pre-installed with NOOBS.
                 c. USB cable (type A to type B).
                 d. Sound card.
                 e. Micro phone.
                 f. Internet and the server.

2. Installtion instructions:
                First insert the SD card to Raspbrrey Pi and connet with the power cable
                Then connet to the internet with RJ45 and get the IP address form your email
                Put on the sound card and installate the micro phone.

3. Operation instructions:
                Connet to the internet and get the IP address form your emaill
                Open putty and put on the IP address
                Use comment "make" and run "./sound.a"

4. Manifest:
                main.c      "The root file." 
                sound.c     "sound.c contains code for extracting information form the WAV file and processes it, then display the result."
                sound.h     "sound.h is the header file for sound.c"
                screen.c    "screen.c contains code for display the rms result on the screen."
                screen.h    "screen.h is the header file for screen.c."
                comm.c      "comm.c contains code for Raspberry pi communicating with online server."
                comm.h      "comm.h is the header file for comm.c."
                README.TXT 
   
5. License
                This project is made by Zuquan Wang and the teacher Mr.Gao chao.
                       
6. Contact information:
                 name: Zuquan Wang , e1701377
                 Dept. of Information technology
                 Vaasa University of Applied Sciences
                 Vastervikintie 271, 65280 Vaasa
                 Page: www.cc.puv.fi/~e1701377
                 email: wzq1669524085@gmail.com
                 
                  

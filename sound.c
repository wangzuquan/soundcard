#include <stdio.h>
#include "sound.h"
#include <math.h>
#include "comm.h"
//function difinition of displayBar()
//this function open the "test.wav" file and read the 2nd part (data) of the file and the sample should be in S16_LE format, and there are 1600 of them
//the function processes every 200 samples and calculate their RMS value
void displayBar(char filename[]){
        int i, j;
        FILE *fp;
        short int samples[SAMPLERATE];
        double sum_200, rms_80[80], dB;
        WAVHeader myhdr;
        fp = fopen(filename, "r");
        if(fp == NULL){
                printf("Error opening the file!\n");
                return;
}
        fread(&myhdr, sizeof(WAVHeader), 1, fp);
        fread(&samples, sizeof(short), SAMPLERATE, fp);
        fclose(fp);
        clearScreen();
        for(i=0; i<80; i++){
        for(j=0,sum_200=0.0; j<200; j++){
                sum_200 += samples[j+i*200]*samples[j+i*200];
                }
        rms_80[i] = sqrt(sum_200/200);
        dB = 20*log10(rms_80[i]);
#ifdef DEBUG
        printf("RMS[%d] = %10.4f = %10.4fdB\n", i, rms_80[i], dB);
#else
        bar(dB, i);
#endif
        }
gotoxy(0,0);
    printf("%c[1;%dm",ESC, 37);
    fflush(stdout);
    printf("%s ", filename);
    printf("%c[1;%dm",ESC, 32);
    fflush(stdout);
    printf("ch = %d ", myhdr.numChannels);
    printf("%c[1;%dm",ESC, 36);
    fflush(stdout);
    printf("SR = %d ", myhdr.sampleRate);
    printf("%c[1;%dm",ESC, 35);
    fflush(stdout);
    printf("dur = %ds\n", myhdr.subchunk2Size/(myhdr.sampleRate*myhdr.bitsPerSample/8));
    printf("%c[1;%dm",ESC, 37);
    fflush(stdout);
#ifdef COMM
	sendToserver(rms_80);
#endif
}
//function definition of displayWAVheader
void displayWAVheader(char filename[]){
        WAVHeader myhdr;
        FILE *fp;
        fp = fopen(filename, "r");
        if(fp == NULL){
                printf("ERROR of opening file!\n");
                return;
        }
        fread(&myhdr, sizeof(WAVHeader), 1, fp);
        fclose(fp);
        printID(myhdr.chunkID);
        printf("Chunk size: %d\n", myhdr.chukSize);
        printID(myhdr.format);
        printID(myhdr.subchunk1ID);
        printf("subchunk 1 size: %d\n", myhdr.subchunk1Size);
        printf("audio format: %d\n", myhdr.audioFormat);
        printf("number of channels: %d\n", myhdr.numChannels);
        printf("sample rate: %d\n", myhdr.sampleRate);
        printf("byte rare: %d\n", myhdr.byteRate);
        printf("block align: %d\n", myhdr.blockAlign);
        printf("bits per sample: %d\n", myhdr.bitsPerSample);
        printID(myhdr.subchunk2ID);
        printf("Sub chunk 2 size: %d\n", myhdr.subchunk2Size);

// there are more fields to be displayed

}
void printID(char id[]){
       int i;
       for(i=0; i<4; i++){
       printf("%c", id[i]);
       }
             printf("\n");
       }








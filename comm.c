#include "comm.h"
#include <math.h>
#include <stdio.h>        //sprintf{}
#include <curl/curl.h>    //libcurl

//This function takes in RMS values of 1 secound.each is calculated by 16000/80-200
// sampless, but the function will re-calculates 8-piecas of RMS values, each
// corresponding to 2000 samples or 125ms of sound

void sendToserver(double r80[]){
    double r8[8], sum;
    int i, j;    // loop counters
    CURL * curl;
    CURLcode res;
    char post[1000];

    for(i=0; i<8; i++){     //to calculate 8-piaces of fast values
        sum = 0;            //initialize the sum
        for(j=0; j<10; j++){
            sum += r80[j+i*10]*r80[j+i*10]*200;
        }
        r8[i] = sqrt(sum/2000);  // calculate a new RMS
   }
   // prepare post data
   sprintf(post, "data-%.2f;%.2f;%.2f;%.2f;%.2f;%.2f;%.2f;%.2f;",
               r8[0], r8[1], r8[2], r8[3], r8[4], r8[5], r8[6], r8[7]);
   // send data
   curl_global_init(CURL_GLOBAL_ALL);
   curl = curl_easy_init();
   if(curl){
       curl_easy_setopt(curl,CURLOPT_URL, URL);
       curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post);
       res = curl_easy_perform(curl);
       if(res != CURLE_OK)
          fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
	curl_easy_cleanup(curl);
   }   //end of if
   curl_global_cleanup();
}

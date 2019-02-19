#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{

  
  
    char cmd[1024];
    char index[64];
    char pfad[64];
    char image[64];
    
    char temp[] = "IMAGE=\"%s\"\nMOUNT=$(basename ${IMAGE} .squashfs)\nINDEX=\"%s\"\nDOCROOT=\"%s\"\nif [ -e ${IMAGE} ]; then\n   if ! [ -d ${DOCROOT} ]; then\n      echo false\n      exit 1\n   fi\n   if ! [ -d ${DOCROOT}/${MOUNT} ]; then\n      if ! mkdir ${DOCROOT}/${MOUNT} 2>&1 >/dev/null; then\n         echo false\n         exit 1\n      fi\n   fi\n   if ! mount|grep -q ${IMAGE}; then\n      if ! mount -o loop ${IMAGE} ${DOCROOT}/${MOUNT} 2>&1 >/dev/null; then\n         echo false\n         exit 1\n      fi\n   fi\n   if ! [ -e ${DOCROOT}/${MOUNT}/${INDEX} ]; then\n      echo false\n      exit 1\n   else\n      echo true\n      exit 0\n   fi\nelse\n   echo false\n   exit 1\nfi\n";

    /*

IMAGE=\"%s\"
MOUNT=$(basename ${IMAGE} .squashfs)
INDEX=\"%s\"
DOCROOT=\"%s\"
if [ -e ${IMAGE} ]; then
   if ! [ -d ${DOCROOT} ]; then
      echo false
      exit 1
   fi
   if ! [ -d ${DOCROOT}/${MOUNT} ]; then
      if ! mkdir ${DOCROOT}/${MOUNT} 2>&1 >/dev/null; then
         echo false
         exit 1
      fi
   fi
   if ! mount|grep -q ${IMAGE}; then
      if ! mount -o loop ${IMAGE} ${DOCROOT}/${MOUNT} 2>&1 >/dev/null; then
         echo false
         exit 1
      fi
   fi
   if ! [ -e ${DOCROOT}/${MOUNT}/${INDEX} ]; then
      echo false
      exit 1
   else
      echo true
      exit 0
   fi
else
   echo false
   exit 1
fi


  */
    
    if(argc<2||argc>4){
      printf("usage: mountloop </abs/pfad/zum/image>.squashfs [<index.html> [</abs/pfad/zum/webroot]>]\n");
      return 1;
    }else{
      strcpy(image, argv[1]);
    }
   
    if(argc>2){
      strcpy(index, argv[2]);
    }else{
      strcpy(index, "index.html");
    }
 
    if(argc>3){
      strcpy(pfad, argv[3]);
    }else{
      // must be the docroot of webfsd
      strcpy(pfad,"/usr/share/prop");
    }

    //and doit...
    sprintf(cmd, temp, image, index, pfad);
    setuid(0);
    system(cmd);
   
    //printf(cmd);
}

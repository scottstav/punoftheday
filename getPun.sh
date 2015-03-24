#!/bin/bash



curl -s http://feeds.feedburner.com/PunOfTheDay > PunOfTheDay #put the ugly text in a file
./getpun #this takes the ugly text and makes it pretty with C!
cat outputtest.txt #display the cleaned up file
printf "\n"
rm outputtest.txt #reset everything for next run
rm PunOfTheDay #"


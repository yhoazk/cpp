#!/bin/bash
date +"%s:%N" >> /tmp/kk/start
echo $$ >> /tmp/kk/start
sleep 2
date +"%s:%N" >> /tmp/kk/start
exit 5
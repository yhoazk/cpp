#!/bin/bash
date +"%s:%N" >> /tmp/kk/start
echo $$ >> /tmp/kk/start
sleep 5
date +"%s:%N" >> /tmp/kk/start
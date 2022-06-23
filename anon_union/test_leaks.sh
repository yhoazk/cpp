#!/usr/bin/env bash

valgrind --leak-check=summary  $1
:w

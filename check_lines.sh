#!/usr/bin/env bash

LINES=$1

shuf -i 0-9999 -n "$LINES" > arg.txt ; ./push_swap $(cat arg.txt) | wc -l
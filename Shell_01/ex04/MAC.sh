#!/bin/sh
ifconfig -a | grep "ether" | cut -b 8- | sed -e 's/ //g' 

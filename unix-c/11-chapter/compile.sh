#!/bin/bash
BASE=$(cd $(dirname $0); pwd)

function compile(){
	if [ $# != 1 ]; then
		echo "usage : $0 pathfile"
	else
		name=$(echo $1 | sed 's#\.c##g')
		gcc -g -Wall -pthread $1 -o $name
	fi
}

compile $*

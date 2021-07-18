#!/bin/sh

inputdir=../data/input
outputdir=../data/output

for path in $inputdir/*

do
    # python demo.py --video-path $path --output-path $outputdir/$video
    # echo $path
    # video=`basename $path`
    # videoName="${video%.*}"
    # videoExtension="${video##*.}"
    # echo $video
    # echo $videoName
    # echo $videoExtension
    

    video=`basename $path`
    python demo.py --video-path $inputdir/$video --output-path $outputdir/$video
done

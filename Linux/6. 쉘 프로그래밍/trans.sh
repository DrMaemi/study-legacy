#!/bin/sh

dir=.

for path in $dir/*

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
    videoName="${video%.*}"
    echo "${videoName}_mp4.mp4"
    transed_video="${videoName}_mp4.mp4"
    # echo $transed_video

    ffmpeg -i $video $transed_video
done

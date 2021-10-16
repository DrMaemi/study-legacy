import logging
import os
import json

class EmotionLogger():
    def __init__(self, path):
        self.logger = logging.getLogger('EmotionLogger')
        
        self.logger.setLevel(logging.DEBUG)

        formatter = logging.Formatter(fmt='%(message)s')

        # stream(console) handler 객체 생성
        stream_handler = logging.StreamHandler()
        stream_handler.setLevel(logging.WARNING)
        stream_handler.setFormatter(formatter)
        self.logger.addHandler(stream_handler)

        # file handler 객체 생성
        os.makedirs(path, exist_ok=True)
        file_handler = logging.FileHandler(filename=path+'/emotion.log')
        file_handler.setLevel(logging.INFO)
        file_handler.setFormatter(formatter)
        self.logger.addHandler(file_handler)

    def log(self, face_boxes_and_emotions_by_timestamp):
        self.logger.info(json.dumps(face_boxes_and_emotions_by_timestamp))

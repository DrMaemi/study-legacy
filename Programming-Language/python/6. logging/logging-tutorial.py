import logging, os

def MyLogger(path, save_file):
    logger = logging.getLogger('MyLogger')
    logger.setLevel(logging.DEBUG)

    formatter = logging.Formatter(fmt="%(asctime)s - %(name)s - %(levelname)s - %(message)s")

    # stream(console) handler 객체 생성
    stream_handler = logging.StreamHandler()
    stream_handler.setLevel(logging.DEBUG)
    stream_handler.setFormatter(formatter)
    logger.addHandler(stream_handler)

    if save_file:
        # file handler 객체 생성
        os.makedirs(path, exist_ok=True)
        file_handler = logging.FileHandler(filename=path+'/my.log')
        file_handler.setLevel(logging.INFO)
        file_handler.setFormatter(formatter)
        logger.addHandler(file_handler)

    return logger

if __name__ == '__main__':
    mylogger = MyLogger('./logs', True)
    mylogger.debug("\nlogging-tutorial.py - main()")

    mylogger.debug('DEBUG message')
    mylogger.info('INFO message')
    mylogger.warning('WARNING message')
    mylogger.error('ERROR message')

    mylogger.debug("Done.")

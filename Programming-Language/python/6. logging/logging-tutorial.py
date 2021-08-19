import logging

# logger 생성
logger = logging.getLogger("name")
logger.setLevel(logging.INFO)

logger.info("Message")

logging.Formatter(
    fmt = None, # 메세지 출력 형태. None일 경우 raw 메세지 출력
    datefmt = None, # 날짜 출력 형태. None일 경우 '%Y-%m-%d %H:%M:%S'
    style = '%' # '%', '{', '$' 중 하나. 'fmt'의 style 결정
)

stream_handler = logging.StreamHandler()
file_handler = logging.FileHandler(filename='example.log')

# formatter 객체 생성
formatter = logging.Formatter(fmt="%(asctime)s - %(name)s - %(levelname)s - %(message)s")

# handler에 level 설정
stream_handler.setLevel(logging.INFO)
file_handler.setLevel(logging.DEBUG)

# handler에 format 설정
stream_handler.setFormatter(formatter)
file_handler.setFormatter(formatter)

logger.addHandler(stream_handler)
logger.addHandler(file_handler)


logger.debug('This message should go to the log file')
logger.info('So should this')
logger.warning('And this, too')
logger.error('And non-ASCII stuff, too, like Øresund and Malmö')

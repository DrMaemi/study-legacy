import boto3

# AWS Rekognition
class AWSClient:
    def __init__(self):
        self.S3_ACCESS_KEY_ID = '...'
        self.S3_SECRET_ACCESS_KEY = '...'
        self.BUCKET_NAME = 'test.i-mind101.com'
        self.PREFIX = 'public/test/'
        self.FILE_NAME = '2021-10-05-test.mp4'
        self.FILE_KEY = self.PREFIX+self.FILE_NAME

        print('Creating AWS S3, Rekognition')
        self.s3 = boto3.resource(
            's3',
            aws_access_key_id=self.S3_ACCESS_KEY_ID,
            aws_secret_access_key=self.S3_SECRET_ACCESS_KEY
        )
        self.bucket = self.s3.Bucket(name=self.BUCKET_NAME)
        self.rekog = boto3.client(
            'rekognition',
            aws_access_key_id=self.S3_ACCESS_KEY_ID,
            aws_secret_access_key=self.S3_SECRET_ACCESS_KEY
        )

        self.start_face_detection_response = None
        self.get_face_detection_response = None

    def download_file(self, file_key, file_name):
        """
        Request Syntax:
        boto3.resource.meta.client.download_file(
            Bucket,
            Key,
            Filename,
            ExtraArgs=None,
            Callback=None,
            Config=None
        )
        boto3.resource.Bucket.download_file(Key, ...)

        ex)
        self.s3.meta.client.download_file(
            self.BUCKET_NAME,
            self.FILE_KEY,
            file_name
        )
        -> download as file_name
        """
        self.s3.meta.client.download_file(
            self.BUCKET_NAME,
            file_key,
            file_name
        )

    def upload_file(self, file_name, file_key):
        """
        Request Syntax:
        boto3.resource.meta.client.upload_file(
            Filename,
            Bucket,
            Key
        )

        ex)
        self.s3.meta.client.upload_file(
            self.FILE_NAME,
            'test.i-mind101.com',
            self.FILE_KEY
        )
        -> upload to FILE_KEY(remote path)
        """
        self.s3.meta.client.upload_file(
            file_name,
            'test.i-mind101.com',
            file_key
        )

    def start_face_detection(self):
        self.start_face_detection_response = self.rekog.start_face_detection(
            Video={
                'S3Object': {
                    'Bucket': self.BUCKET_NAME,
                    'Name': self.FILE_KEY
                }
            },
            ClientRequestToken='2',
            FaceAttributes = 'ALL'
        )

    def get_face_detection(self):
        self.get_face_detection_response = self.rekog.get_face_detection(
            JobId=self.start_face_detection_response['JobId'],
            MaxResults=123
        )

    def get_next(self):
        if 'NextToken' in self.get_face_detection_response:
            self.get_face_detection_response = self.rekog.get_face_detection(
                JobId=self.start_face_detection_response['JobId'],
                MaxResults=123,
                NextToken=self.get_face_detection_response['NextToken']
            )

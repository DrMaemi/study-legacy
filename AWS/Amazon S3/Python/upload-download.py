import boto3

S3_ACCESS_KEY_ID = '...'
S3_SECRET_ACCESS_KEY = '...'
bucket_name = 'test.i-mind101.com'
prefix = 'public/test/'
file_name = 'processed.mp4'
obj_key = prefix+file_name

print("Creating Amazon S3 bucket client obj and uploading video.")
s3 = boto3.resource(
    's3',
    aws_access_key_id=S3_ACCESS_KEY_ID,
    aws_secret_access_key=S3_SECRET_ACCESS_KEY
)
bucket = s3.Bucket(name=bucket_name)

print('Upload file')
# Request syntax:
# boto3.resource.upload_file(Filename, Bucket, Key, Extra_args=None, callback=None, Config=None)
# boto3.resource.Bucket.upload_file(Filename, Key, ...)
s3.meta.client.upload_file(
    file_name,
    bucket_name,
    obj_key
)

print('list all objects in bucket:')
for bucket_obj in bucket.objects.all():
    print(bucket_obj)

print('list prefix objects in bucket:')
for bucket_obj in bucket.objects.filter(Prefix=prefix):
    print(bucket_obj)

print('get specific object in bucket:')
obj = bucket.Object(key=obj_key)
obj2 = s3.Object(bucket_name=bucket_name, key=obj_key)
print(f'type(obj): {type(obj)}')
print(f'obj: {obj}')
print(f'type(obj2): {type(obj2)}')
print(f'obj2: {obj2}')

print('download file in s3')
# Request Syntax:
# boto3.resource.download_file(Bucket, Key, Filename, ExtraArgs=None, Callback=None, Config=None)
# boto3.resource.Bucket.download_file(Key, ...)
s3.meta.client.download_file(
    bucket_name,
    obj_key,
    './s3_downloaded.mp4'
)
bucket.download_file(obj_key, './bucket_downloaded.mp4')

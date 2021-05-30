from django.http import HttpResponse
from django.views.decorators.csrf import csrf_exempt

# json 라이브러리를 이용해서 데이터를 json 형태로 응답한다.
import json
from MyApplication.MongoDbManager import MongoDbManager


# 특정 유저를 위한 specific_user 메소드.
# GET과 POST 메소드로 접근한 경우만 허용.
# request에는 클라이언트의 요청 정보가 담긴다.
# username에는 URL의 username에 대한 정보가 담긴다.
# 최종적으로 HttpResponse를 통해 상태 코드와 DB에서 조회한 데이터를 json 형태로 담아 응답한다.
# 클라이언트의 요청 정보 중, POST 메소드에서 Body 내용은 request.POST를 통해 확인 가능
@csrf_exempt
def specific_user(request, username):
    def get():
        dbUserData = MongoDbManager().get_users_from_collection({'name': username})
        responseData = dbUserData[0]
        del responseData['_id']

        return HttpResponse(json.dumps(responseData), status=200)

    def post():
        try:
            age, job = request.POST['age'], request.POST['job']
        except:
            return HttpResponse(status=400)

        userData = {
            'name': username,
            'age': age,
            'job': job
        }

        result = MongoDbManager().add_user_on_collection(userData)
        return HttpResponse(status=201) if result else HttpResponse(status=500)

    if request.method == 'GET':
        return get()
    elif request.method == 'POST':
        return post()
    else:
        return HttpResponse(status=405)


# 모든 유저를 위한 all_users 메소드.
# GET 메소드로 접근한 경우만 허용.
def all_users(request):
    def get():
        dbUserData = MongoDbManager().get_users_from_collection({})
        responseData = []
        for user in dbUserData:
            del user['_id']
            responseData.append(user)

        return HttpResponse(json.dumps(responseData), status=200)

    if request.method == 'GET':
        return get()
    else:
        return HttpResponse(status=405)

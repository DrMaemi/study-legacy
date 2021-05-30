from django.urls import path
from MyApplication.Api import HtmlTest, JsonTest

# "~/api/json": 모든 유저의 정보를 json 형태로 요청
# "~/api/json/shin": shin이라는 유저의 정보를 json 형태로 요청
# "~/api/html": 모든 유저의 정보를 html 웹 문서로 요청
# "~/api/html/shin": shin이라는 유저의 정보를 html 웹 문서로 요청
urlpatterns = [
    path('json/', JsonTest.all_users, name='JsonAllUser'),
    path('json/<username>', JsonTest.specific_user, name='JsonSpecificUser'),
    path('html/', HtmlTest.all_users, name='HtmlAllUser'),
    path('html/<username>', HtmlTest.specific_user, name='HtmlSpecificUser')
]
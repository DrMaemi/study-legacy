from flask import Flask
from app import views

app = Flask(__name__)

# url
app.add_url_rule('/base','base',views.base)
app.add_url_rule('/','index',views.index)
app.add_url_rule('/foodapp','foodapp',views.foodapp)
app.add_url_rule('/foodapp/classification','classification',views.classification,methods=['GET','POST'])
 
if __name__ == "__main__":
    app.run(debug=True)
from flask import render_template, request
from flask import redirect, url_for
import os
import tensorflow as tf
from app.common_function import pred_and_plot

my_model = tf.keras.models.load_model("model/my_model")

UPLOAD_FLODER = 'static/uploads'
def base():
    return render_template('base.html')


def index():
    return render_template('index.html')


def foodapp():
    return render_template('foodapp.html')

def classification():

    if request.method == "POST":
        f = request.files['image']
        filename=  f.filename
        print(filename)
        path = os.path.join(UPLOAD_FLODER,filename)
        f.save(path)

        pred_and_plot(
            model=my_model,
            filename=path
        )

        return render_template('classification.html',fileupload=True,img_name=filename)


    return render_template('classification.html',fileupload=False,img_name="freeai.png")
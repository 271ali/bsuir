from flask import Flask, render_template, url_for, redirect
from model.AuthenticationService import AuthenticationService
from model.AuthenticationRepository import AuthenticationRepository
from model.RestaurantRepository import RestaurantRepository
from model.ResaturantService import RestaurantService
from model.ReservationService import ReservationService
from model.ReservationRepository import ReservationRepository
app=Flask(__name__)

@app.route('/registration')
def registration():

    return render_template("registration.html")
@app.route('/')
@app.route('/home')
def index():
    return render_template("index.html")

@app.route('/authorization')
def authorization():

    return render_template("authorization.html")

@app.route('/client_account')
def open_client_account():
    return render_template("client_account.html")

@app.route('/book_history')
def open_book_history():
    return render_template("book_history.html")

@app.route('/booking')
def open_booking():
    return render_template("booking.html")

@app.route('/restaurant')
def open_restaurant():
    return render_template("restaurant.html")

@app.route('/booking_form')
def open_booking_form():
    return render_template("booking_form.html")

@app.route('/review')
def open_review():
    return render_template("review.html")

@app.route('/admin')
def open_admin():
    return render_template("admin.html")

@app.route('/client_info')
def open_client_info():
    return render_template("client_info.html")

@app.route('/booking_request')
def open_booking_request():
    return render_template("booking_request.html")

@app.route('/analys')
def open_analys():
    return render_template("analys.html")

@app.route('/reviews_list')
def open_reviews_list():
    return render_template("reviews_list.html")

if __name__=='__main__':
    app.run(debug=True)
import os
import datetime
from Flask import Flask, request, jsonify
import jwt
from Flask import make_response

app= Flask(--appname--)
# secret key
app.config['SECRET_KEY'] = 'secret'

@app.route('/login', methods=['POST'])

# dummmy database for news articles, headlines and consumers 
# endpoint to login to recieve token

def login():
    auth = request.authorization
    if auth and auth.password == 'secret':
        token = jwt.encode({'user': auth.username, 'exp': datetime.datetime.utcnow() + datetime.timedelta(minutes=30)}, app.config['SECRET_KEY'])
        return jsonify({'token': token.decode('UTF-8')})
    return make_response('Could not verify', 401, {'WWW-Authenticate': 'Basic realm="Login Required"'})


@app.route('/news', methods=['GET'])

# endpoint to get news articles

def get_news():
    token = request.args.get('token')
    if not token:
        return jsonify({'message': 'Token is missing'})
    try:
        data = jwt.decode(token, app.config['SECRET_KEY'])
    except:
        return jsonify({'message': 'Token is invalid'})
    return jsonify({'news': 'news articles'})

@app.route('/headlines', methods=['GET'])

# endpoint to get news headlines

def get_headlines():
    token = request.args.get('token')
    if not token:
        return jsonify({'message': 'Token is missing'})
    try:
        data = jwt.decode(token, app.config['SECRET_KEY'])
    except:
        return jsonify({'message': 'Token is invalid'})
    return jsonify({'headlines': 'news headlines'})

@app.route('/consumers', methods=['GET'])

# endpoint to get news consumers

def get_consumers():
    token = request.args.get('token')
    if not token:
        return jsonify({'message': 'Token is missing'})
    try:
        data = jwt.decode(token, app.config['SECRET_KEY'])
    except:
        return jsonify({'message': 'Token is invalid'})
    return jsonify({'consumers': 'news consumers'})
# endpoint to search news articles by date 

@app.route('/search', methods=['GET'])

def search():
    token = request.args.get('token')
    if not token:
        return jsonify({'message': 'Token is missing'})
    try:
        data = jwt.decode(token, app.config['SECRET_KEY'])
    except:
        return jsonify({'message': 'Token is invalid'})
    return jsonify({'search': 'search results'})

@app.route('/subscribe', methods=['POST'])

# endpoint to subscribe to news articles

def subscribe():
    token = request.args.get('token')
    if not token:
        return jsonify({'message': 'Token is missing'})
    try:
        data = jwt.decode(token, app.config['SECRET_KEY'])
    except:
        return jsonify({'message': 'Token is invalid'})
    return jsonify({'subscribe': 'news subscribers'})   

@app.route('/unsubscribe', methods=['POST'])

# endpoint to unsubscribe to news articles

def unsubscribe():
    token = request.args.get('token')
    if not token:
        return jsonify({'message': 'Token is missing'})
    try:
        data = jwt.decode(token, app.config['SECRET_KEY'])
    except:
        return jsonify({'message': 'Token is invalid'})
    return jsonify({'unsubscribe': 'news subscribers'})

@app.route('/comment', methods=['POST'])

# endpoint to comment on news articles

def comment():
    token = request.args.get('token')
    if not token:
        return jsonify({'message': 'Token is missing'})
    try:
        data = jwt.decode(token, app.config['SECRET_KEY'])
    except:
        return jsonify({'message': 'Token is invalid'})
    return jsonify({'comment': 'news comments'})

@app.route('/like', methods=['POST'])

# endpoint to like on news articles

def like():
    token = request.args.get('token')
    if not token:
        return jsonify({'message': 'Token is missing'})
    try:
        data = jwt.decode(token, app.config['SECRET_KEY'])
    except:
        return jsonify({'message': 'Token is invalid'})
    return jsonify({'like': 'news likes'})

@app.route('/dislike', methods=['POST'])

# endpoint to dislike on news articles

def dislike():
    token = request.args.get('token')
    if not token:
        return jsonify({'message': 'Token is missing'})
    try:
        data = jwt.decode(token, app.config['SECRET_KEY'])
    except:
        return jsonify({'message': 'Token is invalid'})
    return jsonify({'dislike': 'news dislikes'})

@app.route('/share', methods=['POST'])

# endpoint to share on news articles

def share():
    token = request.args.get('token')
    if not token:
        return jsonify({'message': 'Token is missing'})
    try:
        data = jwt.decode(token, app.config['SECRET_KEY'])
    except:
        return jsonify({'message': 'Token is invalid'})
    return jsonify({'share': 'news shares'})

@app.route('/report', methods=['POST'])

# endpoint to report on news articles

def report():
    token = request.args.get('token')
    if not token:
        return jsonify({'message': 'Token is missing'})
    try:
        data = jwt.decode(token, app.config['SECRET_KEY'])
    except:
        return jsonify({'message': 'Token is invalid'})
    return jsonify({'report': 'news reports'})

@app.route('/flag', methods=['POST'])

# endpoint to flag on news articles

def flag():
    token = request.args.get('token')
    if not token:
        return jsonify({'message': 'Token is missing'})
    try:
        data = jwt.decode(token, app.config['SECRET_KEY'])
    except:
        return jsonify({'message': 'Token is invalid'})
    return jsonify({'flag': 'news flags'})

@app.route('/flag', methods=['POST'])

# endpoint to flag on news articles

def flag():
    token = request.args.get('token')
    if not token:
        return jsonify({'message': 'Token is missing'})
    try:
        data = jwt.decode(token, app.config['SECRET_KEY'])
    except:
        return jsonify({'message': 'Token is invalid'})
    return jsonify({'flag': 'news flags'})


if __name__ == '__main__':  
    app.run(debug = True)


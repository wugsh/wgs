from flask import Flask, redirect, url_for, request, render_template
# Flask类的一个对象是我们的WSGI应用程序。
# lask构造函数使用当前模块（__name __）的名称作为参数
app = Flask(__name__)

# Flask类的route()函数是一个装饰器，它告诉应用程序哪个URL应该调用相关的函数
@app.route('/hello_world')
def hello_world():
    return 'Hello World!'


@app.route('/hello')
def hello_world1():
    return "AAAAA"

# route()装饰器的规则参数包含附加到URL '/hello'的<name>。
# 因此，如果在浏览器中输入http://localhost:5000/hello/w3cschool作为URL，则'w3cschool'将作为参数提供给hello()函数
@app.route('/hello/<name>')
def hello_name(name):
    return 'Hello %s!' % name


@app.route('/blog/<int:postID>')
def show_blog(postID):
    return 'Blog Number %d' % postID


@app.route('/rev/<float:revNo>')
def revision(revNo):
    return 'Revision Number %f' % revNo

# 这两个规则看起来类似，但在第二个规则中，使用斜杠（/）。因此，它成为一个规范的URL。
# 因此，使用 /python 或 /python/返回相同的输出。但是，如果是第一个规则，/flask/ URL会产生“404 Not Found”页面。
@app.route('/flask')
def hello_flask():
    return 'Hello Flask'


@app.route('/python/')
def hello_python():
    return 'Hello Python'

# url_for()函数对于动态构建特定函数的URL非常有用。
# 该函数接受函数的名称作为第一个参数，以及一个或多个关键字参数，每个参数对应于URL的变量部分。
@app.route('/admin')
def hello_admin():
    return 'Hello Admin'
@app.route('/guest/<guest>')
def hello_guest(guest):
    return 'Hello %s as Guest' %guest
@app.route('/user/<name>')
def hello_user(name):
    if name == 'admin':
        return redirect(url_for('hello_admin'))
    else:
        return redirect(url_for('hello_guest', guest = name))

#使用POST方法将表单数据发送到URL。
@app.route('/success/<name>')
def success(name):
    return 'welcome %s' %name
@app.route('/login', methods = ['POST', 'GET'])
def login():
    if request.method == 'POST':
        user = request.form['nm']
        return redirect(url_for('success', name = user))
    else:
        user = request.args.get('nm')
        return redirect(url_for('success', name = user))

#Flask 模板:可以以HTML的形式返回绑定到某个URL的函数的输出,可以通过render_template()函数呈现HTML文件。
@app.route('/index/<int:user>')
def index(user):
   return render_template('hello.html', marks = user)

# Flask类的run()方法在本地开发服务器上运行应用程序。
if __name__ == '__main__':
    app.run(host='0.0.0.0', port='5000', debug=True)

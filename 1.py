from flask import Flask,request,render_template,send_file
from flask_cors import CORS
app=Flask(__name__)
CORS(app)
a=""
c=""
d=""
e=""
@app.route("/")
def A():
    return render_template("1.html")
@app.route("/send",methods=["POST"])
def B():
    global a
    a=request.form.get("a") or "你还没有新消息"
    return "信息已发送"
@app.route("/catch/message")
def C():
    global a
    return render_template("2.html",a=a)
@app.route("/send/file",methods=["POST"])
def D():
    global c
    b=request.files.get("b")
    c=request.form.get("c")
    b.save("\\static\\"+c)
    return "信息已发送"
@app.route("/catch/message/file")
def E():
    global c
    return send_file("\\static\\"+c)
@app.route("/send/2")
def F():
    global d,e
    d=request.args.get("d")
    e=request.args.get("e")
    return """<script>window.close();</script>"""
@app.route("/catch/message/2")
def G():
    global d,e
    if request.args.get("d")==d:
        return e
    return "还没有"
@app.route("/catch/<ooo>")
def H(ooo):
    return send_file("\\static\\"+ooo)
app.run(host="0.0.0.0",port=2200)

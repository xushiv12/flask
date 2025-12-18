from flask import Flask,request,render_template,send_file
app=Flask(__name__)
a=""
c=""
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
    b.save("static\\"+c)
    return "信息已发送"
@app.route("/catch/message/file")
def E():
    global c
    return send_file("static\\"+c)
app.run(host="0.0.0.0",port=2200)
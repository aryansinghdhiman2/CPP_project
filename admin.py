from tkinter import *
from tkinter import messagebox


def admin_window(login_win):
    admin_win=Toplevel(login_win)
    admin_win.title("Login")
    admin_win.geometry("925x500+300+200")
    admin_win.configure(bg="#fff")
    admin_win.resizable(False,False)


def login(root):
    login_win=Toplevel(root)
    login_win.title("Login")
    login_win.geometry("925x500+300+200")
    login_win.configure(bg="#fff")
    login_win.resizable(False,False) 

    def signin():
        username=user.get()
        password=code.get()
        if username=="admin" and password=="root":
            admin_window(login_win)
            login_win.withdraw()

    img= PhotoImage(file="login.png")
    Label(login_win,image=img,bg="white").place(x=50,y=50 )
    frame=Frame(login_win,width=350,height=350,bg="white")
    frame.place(x=480,y=70)
    heading= Label(frame,text="Sign In",fg="#57a1f8",bg="white",font=("Microsoft YaHei UI Light",23,'bold'))
    heading.place(x=100,y=5)

    user= Entry(frame,width=25,fg="black",border=0,bg="white",font=("Microsoft YaHei UI Light",11))
    user.place(x=30,y=80)
    user.insert(0,"Username")
    
    Frame(frame,width=295,height=2,bg="black").place(x=25,y=107)

    code= Entry(frame,width=25,fg="black",border=0,bg="white",font=("Microsoft YaHei UI Light",11))
    code.place(x=30,y=150)
    code.insert(0,"Password")
    Frame(frame,width=295,height=2,bg="black").place(x=25,y=177)


    Button(frame,width=29,pady=7,text="Sign in",bg="#57a1f8",fg="white",border=0,font=("Microsoft YaHei UI Light",12,"bold"),command=signin).place(x=28,y=204)
    exit=Button(frame,width=6,text="Exit",border=0,bg="#57a1f8",cursor="hand2",fg="white",font=("Microsoft YaHei UI Light",12,"bold"))
    exit.place(x=25,y=270)
    login_win.mainloop()   
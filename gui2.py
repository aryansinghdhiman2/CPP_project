from tkinter import *
from tkinter.font import Font
def on_enter(e):
   e.widget['background'] = '#e5e5e5'
def on_leave(e):
   e.widget['background'] = '#fca311'
root= Tk()
myFont= Font(family="Calibri",size=30,weight="bold")
myFont1= Font(family="Calibri",size=18,weight="bold")
myFont2= Font(family="Calibri",size=15,weight="bold")
root.geometry("1280x720")
root.title("Clubs and Event Management System")
# screen_width = root.winfo_screenwidth()
# screen_height = root.winfo_screenheight()
root.resizable(False,False)
header= Label(root,font=myFont,bg='#14213d',text="Clubs and Event Management System",fg="white")
header.place(x=0,y=0,relwidth=1,height=60)
main_menu= Label(root,font=myFont,bg="#fca311",text="Main Menu",fg="white")
main_menu.place(x=0,y=60,relwidth=1,height=45)
f1=Label(root,bg="#e5e5e5")
f1.place(x=0,y=100,relwidth=1,height=350)
f2=Label(root,bg="#cad2c5")
f2.place(x=0,y=659,relwidth=1,height=27)
c1= Frame(root,height=250,width=225,bg="#023047",relief=SUNKEN)
c1.place(x=50,y=250)
c1.pack_propagate(0)
c2= Frame(root,height=250,width=225,bg="#023047")
c2.place(x=370,y=250)
c2.pack_propagate(0)
c3= Frame(root,height=250,width=225,bg="#023047")
c3.place(x=695,y=250)
c3.pack_propagate(0)
c4= Frame(root,height=250,width=225,bg="#023047")
c4.place(x=1000,y=250)
c4.pack_propagate(0)
clubs_btn= Button(c1,text="Clubs",font=myFont1,relief=SOLID,borderwidth=1,height=1,width=12,activebackground='#e5e5e5',bg='#fca311')
clubs_btn.pack(pady=15)
Events_btn= Button(c2,text="Events",font=myFont1,relief=SOLID,borderwidth=1,height=1,width=12,activebackground='#e5e5e5',bg='#fca311')
Events_btn.pack(pady=15)
admin_btn= Button(c3,text= "Admin",font=myFont1,relief=SOLID,borderwidth=1,height=1,width=12,activebackground='#e5e5e5',bg='#fca311')
admin_btn.pack(pady=15)
exit_btn= Button(c4,text= "Exit",font=myFont1,relief=SOLID,borderwidth=1,height=1,width=12,activebackground='#e5e5e5',bg='#fca311',command=root.destroy)
exit_btn.pack(pady=15)
clubs_btn.bind('<Enter>', on_enter)
clubs_btn.bind('<Leave>', on_leave)
Events_btn.bind('<Enter>', on_enter)
Events_btn.bind('<Leave>', on_leave)
admin_btn.bind('<Enter>', on_enter)
admin_btn.bind('<Leave>', on_leave)
exit_btn.bind('<Enter>', on_enter)
exit_btn.bind('<Leave>', on_leave)

l1=Label(c1,text="Get info about the club",font=myFont2,bg="#023047",fg="white")
l1.pack(pady=3,anchor="w",ipadx=7)
l2=Label(c1,text="Upcoming meetings",font=myFont2,bg="#023047",fg="white")
l2.pack(pady=3,anchor="w",ipadx=7)
l3=Label(c1,text="Recruitments",font=myFont2,bg="#023047",fg="white")
l3.pack(pady=3,anchor="w",ipadx=7)
l4=Label(c2,text="Get info about the",font=myFont2,bg="#023047",fg="white")
l4.pack(pady=3,anchor="w",ipadx=7)
l5=Label(c2,text="current & upcoming",font=myFont2,bg="#023047",fg="white")
l5.pack(pady=3,anchor="w",ipadx=7)
l6=Label(c2,text="events in UIET",font=myFont2,bg="#023047",fg="white")
l6.pack(pady=3,anchor="w",ipadx=7)
l7=Label(c3,text="Admins can access and",font=myFont2,bg="#023047",fg="white")
l7.pack(pady=3,anchor="w",ipadx=7)
l8=Label(c3,text="edit info about their",font=myFont2,bg="#023047",fg="white")
l8.pack(pady=3,anchor="w",ipadx=7)
l8=Label(c3,text="clubs",font=myFont2,bg="#023047",fg="white")
l8.pack(pady=3,anchor="w",ipadx=7)
l9=Label(c4,text="Exit the main menu",font=myFont2,bg="#023047",fg="white")
l9.pack(pady=3,anchor="w",ipadx=7)
root.mainloop()
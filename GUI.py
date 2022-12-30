from tkinter import *
from tkinter.font import Font

root= Tk()
myFont= Font(family="Calibri",size=30)
myFont1= Font(family="Calibri",size=20)
bg1=PhotoImage(file="newbg.png")
def club_window():
   club_win= Toplevel(root)
   root.withdraw()
   l1=Label(club_win,image=bg1)
   l1.place(x=0,y=0,relheight=1,relwidth=1)
   club_win.geometry("1000x663")
   club_win.resizable(False,False)
   club_win.title("Clubs")
   def func():
      club_win.destroy()
      root.deiconify()
   main_frame= Frame(club_win,bg="pale turquoise",height=300,width=700,borderwidth=1,relief=RIDGE)
   main_frame.pack(pady=130)
   main_frame.pack_propagate(0)
   heading= Label(main_frame,text="Club Menu",font=myFont, padx=15,pady=25,bg="pale turquoise").
   heading.pack()
   btn_frame= Frame(main_frame,bg="pale turquoise")
   btn_frame.pack(pady=20)
   info_btn= Button(btn_frame,text="Information",font=myFont1,relief=SOLID,borderwidth=1,height=1,width=12,activebackground='light sea green',bg='pale turquoise')
   info_btn.grid(row=0, column=0,padx=4,pady=4)
   recr_btn= Button(btn_frame,text="Recruitment",font=myFont1,relief=SOLID,borderwidth=1,height=1,width=12,activebackground='light sea green',bg='pale turquoise')
   recr_btn.grid(row=0, column=1)
   meet_btn= Button(btn_frame,text= "Meeting",font=myFont1,relief=SOLID,borderwidth=1,height=1,width=12,activebackground='light sea green',bg='pale turquoise')
   meet_btn.grid(row=1, column=0,padx=4)
   return_btn= Button(btn_frame,text= "Return",font=myFont1,relief=SOLID,borderwidth=1,height=1,width=12,activebackground='light sea green',bg='pale turquoise',command=func)
   return_btn.grid(row=1, column=1)
   info_btn.bind('<Enter>', on_enter)
   info_btn.bind('<Leave>', on_leave)
   recr_btn.bind('<Enter>', on_enter)
   recr_btn.bind('<Leave>', on_leave)
   meet_btn.bind('<Enter>', on_enter)
   meet_btn.bind('<Leave>', on_leave)
   return_btn.bind('<Enter>', on_enter)
   return_btn.bind('<Leave>', on_leave)

def on_enter(e):
   e.widget['background'] = 'sky blue'
def on_leave(e):
   e.widget['background'] = 'pale turquoise'


mybg= PhotoImage(file="newbg.png")
l=Label(root,image=mybg)
screen_width = root.winfo_screenwidth()
screen_height = root.winfo_screenheight()
# root.geometry(f"{screen_width} x {screen_height}")
root.geometry("1000x663")
root.resizable(False,False)
l.place(x=0,y=0,relheight=1,relwidth=1)
root.title("Clubs and Event Management System")
main_frame= Frame(bg="pale turquoise",height=300,width=700,borderwidth=1,relief=RIDGE)
main_frame.pack(pady=150)
main_frame.pack_propagate(0)
heading= Label(main_frame,text="Clubs and Event Management System",font=myFont, padx=15,pady=50,bg="pale turquoise")
heading.pack()
btn_frame= Frame(main_frame,bg="pale turquoise")
btn_frame.pack()
clubs_btn= Button(btn_frame,text="Clubs",font=myFont1,relief=SOLID,borderwidth=1,height=1,width=12,activebackground='light sea green',bg='pale turquoise',command=club_window)
clubs_btn.grid(row=0, column=0,padx=4,pady=4)
Events_btn= Button(btn_frame,text="Events",font=myFont1,relief=SOLID,borderwidth=1,height=1,width=12,activebackground='light sea green',bg='pale turquoise')
Events_btn.grid(row=0, column=1)
admin_btn= Button(btn_frame,text= "Admin",font=myFont1,relief=SOLID,borderwidth=1,height=1,width=12,activebackground='light sea green',bg='pale turquoise')
admin_btn.grid(row=1, column=0,padx=4)
exit_btn= Button(btn_frame,text= "Exit",font=myFont1,relief=SOLID,borderwidth=1,height=1,width=12,activebackground='light sea green',bg='pale turquoise',command=root.destroy)
exit_btn.grid(row=1, column=1)


clubs_btn.bind('<Enter>', on_enter)
clubs_btn.bind('<Leave>', on_leave)
Events_btn.bind('<Enter>', on_enter)
Events_btn.bind('<Leave>', on_leave)
admin_btn.bind('<Enter>', on_enter)
admin_btn.bind('<Leave>', on_leave)
exit_btn.bind('<Enter>', on_enter)
exit_btn.bind('<Leave>', on_leave)
root.mainloop()


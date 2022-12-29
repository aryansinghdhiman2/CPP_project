from tkinter import *
root= Tk()

def club_window():
   club_win= Toplevel(root)
   club_win.geometry("750x500")
   club_win.title("Clubs")
   main_frame= Frame(club_win,bg="#ffffff",height=300,width=700,borderwidth=1,relief=RIDGE)
   main_frame.pack(pady=100)
   main_frame.pack_propagate(0)
   # heading= Label(main_frame,text="Clubs and Event Management System",font="timesnewroman 30 ", padx=15,pady=50,bg="#ffffff")
   # heading.pack()
   btn_frame= Frame(main_frame,bg="#ffffff")
   btn_frame.pack(pady=70)
   info_btn= Button(btn_frame,text="Information",font="timesnewroman 20",relief=SOLID,borderwidth=1,height=1,width=12,activebackground='#666666',bg='#ffffff')
   info_btn.grid(row=0, column=0,padx=4,pady=4)
   recr_btn= Button(btn_frame,text="Recruitment",font="timesnewroman 20",relief=SOLID,borderwidth=1,height=1,width=12,activebackground='#666666',bg='#ffffff')
   recr_btn.grid(row=0, column=1)
   meet_btn= Button(btn_frame,text= "Meeting",font="timesnewroman 20",relief=SOLID,borderwidth=1,height=1,width=12,activebackground='#666666',bg='#ffffff')
   meet_btn.grid(row=1, column=0,padx=4)
   return_btn= Button(btn_frame,text= "Return",font="timesnewroman 20",relief=SOLID,borderwidth=1,height=1,width=12,activebackground='#666666',bg='#ffffff',command=club_win.destroy)
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
   e.widget['background'] = '#999999'
def on_leave(e):
   e.widget['background'] = '#ffffff'



screen_width = root.winfo_screenwidth()
screen_height = root.winfo_screenheight()
# root.geometry(f"{screen_width} x {screen_height}")
root.geometry("750x500")
root.title("Clubs and Event Management System")
main_frame= Frame(bg="#ffffff",height=300,width=700,borderwidth=1,relief=RIDGE)
main_frame.pack(pady=100)
main_frame.pack_propagate(0)
heading= Label(main_frame,text="Clubs and Event Management System",font="timesnewroman 30 ", padx=15,pady=50,bg="#ffffff")
heading.pack()
btn_frame= Frame(main_frame,bg="#ffffff")
btn_frame.pack()
clubs_btn= Button(btn_frame,text="Clubs",font="timesnewroman 20",relief=SOLID,borderwidth=1,height=1,width=12,activebackground='#666666',bg='#ffffff',command=club_window)
clubs_btn.grid(row=0, column=0,padx=4,pady=4)
Events_btn= Button(btn_frame,text="Events",font="timesnewroman 20",relief=SOLID,borderwidth=1,height=1,width=12,activebackground='#666666',bg='#ffffff')
Events_btn.grid(row=0, column=1)
admin_btn= Button(btn_frame,text= "Admin",font="timesnewroman 20",relief=SOLID,borderwidth=1,height=1,width=12,activebackground='#666666',bg='#ffffff')
admin_btn.grid(row=1, column=0,padx=4)
exit_btn= Button(btn_frame,text= "Exit",font="timesnewroman 20",relief=SOLID,borderwidth=1,height=1,width=12,activebackground='#666666',bg='#ffffff',command=root.destroy)
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

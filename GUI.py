from tkinter import *
root= Tk()
screen_width = root.winfo_screenwidth()
screen_height = root.winfo_screenheight()
# root.geometry(f"{screen_width} x {screen_height}")
root.geometry("750x500")
root.title("Clubs and Event Management System")
heading= Label(root,text="Clubs and Event Management System",font="timesnewroman 30 ", padx=15,pady=50)
heading.pack()
btn_frame= Frame(root)
btn_frame.pack()
clubs_btn= Button(btn_frame,text="Clubs",font="timesnewroman 20",relief=SOLID,borderwidth=1,height=1,width=12,activebackground='#999999')
clubs_btn.grid(row=0, column=0,padx=4,pady=4)
Events_btn= Button(btn_frame,text="Events",font="timesnewroman 20",relief=SOLID,borderwidth=1,height=1,width=12,activebackground='#999999')
Events_btn.grid(row=0, column=1)
admin_btn= Button(btn_frame,text= "Admin",font="timesnewroman 20",relief=SOLID,borderwidth=1,height=1,width=12,activebackground='#999999')
admin_btn.grid(row=1, column=0,padx=4)
exit_btn= Button(btn_frame,text= "Exit",font="timesnewroman 20",relief=SOLID,borderwidth=1,height=1,width=12,activebackground='#999999',command=root.destroy)
exit_btn.grid(row=1, column=1)
def on_enter(e):
   e.widget['background'] = '#666666'
def on_leave(e):
   e.widget['background'] = '#ffffff'

clubs_btn.bind('<Enter>', on_enter)
clubs_btn.bind('<Leave>', on_leave)
Events_btn.bind('<Enter>', on_enter)
Events_btn.bind('<Leave>', on_leave)
admin_btn.bind('<Enter>', on_enter)
admin_btn.bind('<Leave>', on_leave)
exit_btn.bind('<Enter>', on_enter)
exit_btn.bind('<Leave>', on_leave)
root.mainloop()
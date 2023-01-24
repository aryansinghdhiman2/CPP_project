import oracledb
from env import user,password,dsn
from dbms_func import *
from tkinter import *
from tkinter.font import Font
from tkinter import ttk
from event import event_window
from admin import login
def on_enter(e):
   e.widget['background'] = '#e5e5e5'
def on_leave(e):
   e.widget['background'] = '#fca311'

connection=create_connection(user,password,dsn)

root= Tk()
myFont= Font(family="Calibri",size=30,weight="bold")
myFont1= Font(family="Calibri",size=18,weight="bold")
myFont2= Font(family="Calibri",size=15,weight="bold")
myFont3= Font(family="Calibri",size=13)
myFont4= Font(family="Century Gothic",size=16,weight="bold")
myFont5= Font(family="Century Gothic",size=15,weight="bold")
root.geometry("1280x720")
root.title("Clubs and Event Management System")
# screen_width = root.winfo_screenwidth()
# screen_height = root.winfo_screenheight()
root.resizable(False,False)

def club_window():
    club_win= Toplevel(root)
    #root.withdraw()
    club_win.geometry("1280x720")
    main_menu= Label(club_win,font=myFont,bg="#023047",text="Club Menu",fg="white")
    main_menu.place(x=0,y=0,relwidth=1,height=45)
    def club_info():
        display_frame= Frame(club_win,bd=4,bg="#8ecae6",relief=RIDGE)
        display_frame.place(x=25,y=115,height=540,width=1215)

        
        srch_frame= Frame(display_frame,bd=2,bg="#219ebc",relief=FLAT)
        srch_frame.place(x=290,y=10)
        search_lbl= Label(srch_frame,text="Search by",bg="#219ebc",font=myFont4,fg="white")
        search_lbl.grid(row=0,column=0,sticky="w",pady=5,padx=10)

        srch_var=StringVar()
        srch_entry_var=StringVar()
        # style= ttk.Style()
        # style.theme_use("default")
        combo_search= ttk.Combobox(srch_frame,width=10,font=myFont2,state="readonly",textvariable=srch_var)
        combo_search['values']=("Club name","social media")
        combo_search.grid(row=0,column=1,pady=10,padx=10)
        srch_entry=Entry(srch_frame,font=myFont3,width=20,relief=SUNKEN,bd=3,textvariable=srch_entry_var)
        srch_entry.grid(row=0,column=2)
        
        display2_frame= Frame(display_frame,bd=4,bg="#8ecae6",relief=RIDGE)
        display2_frame.place(x=10,y=70,height=450,width=1185)
        clb_info_tb= ttk.Treeview(display2_frame,columns=("Club_Name","Convener","Social Media","Description"))
        # clb_info_tb.tag_configure("evenrow",background="lightblue")
        clb_info_tb.heading("Club_Name",text="Club Name")
        clb_info_tb.heading("Convener",text="Convener")
        clb_info_tb.heading("Social Media",text="Social Media")
        clb_info_tb.heading("Description",text="Description")
        clb_info_tb['show']="headings"
        clb_info_tb.column("Club_Name",width=150)
        clb_info_tb.column("Convener",width=150)
        clb_info_tb.column("Social Media",width=150)
        clb_info_tb.column("Description",width=300)
        clb_info_tb.pack(fill=BOTH,expand=1)
        srch_btn=Button(srch_frame,text="Search",font=myFont5,bd=3,bg="#219ebc",fg="white",relief=RAISED,command=lambda:search_club(connection,clb_info_tb,srch_var,srch_entry_var)).grid(row=0,column=3,padx=10)
        
        showall= Button(srch_frame,text="Show All",font=myFont5,bd=3,bg="#219ebc",fg="white",relief=RAISED,command=lambda:fetch_club_info(connection,clb_info_tb)).grid(row=0,column=4,padx=10)

    def club_meeting():
        
        display_frame= Frame(club_win,bd=4,bg="#8ecae6",relief=RIDGE)
        display_frame.place(x=25,y=115,height=540,width=1215)

        srch_var=StringVar()
        srch_entry_var=StringVar()

        srch_frame= Frame(display_frame,bd=2,bg="#219ebc",relief=FLAT)
        srch_frame.place(x=290,y=10)
        search_lbl= Label(srch_frame,text="Search by",bg="#219ebc",font=myFont4,fg="white")
        search_lbl.grid(row=0,column=0,sticky="w",pady=10,padx=10)
        combo_search= ttk.Combobox(srch_frame,width=10,font=myFont2,state="readonly",textvariable=srch_var)
        combo_search['values']=("Club name","Meeting date")
        combo_search.grid(row=0,column=1,pady=10,padx=10)
        srch_entry=Entry(srch_frame,font=myFont3,width=20,relief=SUNKEN,bd=3,textvariable=srch_entry_var)
        srch_entry.grid(row=0,column=2)

        
    
        display2_frame= Frame(display_frame,bd=4,bg="#8ecae6",relief=RIDGE)
        display2_frame.place(x=10,y=70,height=450,width=1185)
        clb_meet_tb= ttk.Treeview(display2_frame,columns=("c_name","m_date","venue","desc"))
        clb_meet_tb.heading("c_name",text="Club Name")
        clb_meet_tb.heading("m_date",text="Meeting Date")
        clb_meet_tb.heading("venue",text="Venue")
        clb_meet_tb.heading("desc",text="Description")
        clb_meet_tb['show']="headings"
        clb_meet_tb.column("c_name",width=150)
        clb_meet_tb.column("m_date",width=150)
        clb_meet_tb.column("venue",width=150)
        clb_meet_tb.column("desc",width=300)
        clb_meet_tb.pack(fill=BOTH,expand=1)
        srch_btn=Button(srch_frame,text="Search",font=myFont5,bd=3,bg="#219ebc",fg="white",relief=RAISED,command=lambda:search_meeting(connection,clb_meet_tb,srch_var,srch_entry_var)).grid(row=0,column=3,padx=10)
        showall= Button(srch_frame,text="Show All",font=myFont5,bd=3,bg="#219ebc",fg="white",relief=RAISED,command=lambda:fetch_club_meeting(connection,clb_meet_tb)).grid(row=0,column=4,padx=10)
    def club_recr():
        # manage_frame= Frame(club_win,bd=4,bg="#8ecae6",relief=RIDGE)
        # manage_frame.place(x=0,y=100,width=480,height=540)
        display_frame= Frame(club_win,bd=4,bg="#8ecae6",relief=RIDGE)
        display_frame.place(x=25,y=115,height=540,width=1215)

        srch_var=StringVar()
        srch_entry_var=StringVar()

        # l1=Label(manage_frame,text="Club name",font=myFont1,bg="#8ecae6")
        # l1.grid(row=0,column=0,pady=30,padx=20)

        # name_entry=Entry(manage_frame,font=myFont3,width=20,relief=SUNKEN,bd=3)
        # name_entry.grid(row=0,column=1)

        # l2=Label(manage_frame,text="Recruitment Date",font=myFont1,bg="#8ecae6")
        # l2.grid(row=1,column=0,pady=30,padx=20)

        # con_entry=Entry(manage_frame,font=myFont3,width=20,relief=SUNKEN,bd=3)
        # con_entry.grid(row=1,column=1)

        # l3=Label(manage_frame,text="Venue",font=myFont1,bg="#8ecae6")
        # l3.grid(row=2,column=0,pady=30,padx=20)

        # con_entry=Entry(manage_frame,font=myFont3,width=20,relief=SUNKEN,bd=3)
        # con_entry.grid(row=2,column=1)
        srch_frame= Frame(display_frame,bd=2,bg="#219ebc",relief=FLAT)
        srch_frame.place(x=290,y=10)
        search_lbl= Label(srch_frame,text="Search by",bg="#219ebc",font=myFont4,fg="white")
        search_lbl.grid(row=0,column=0,sticky="w",pady=10,padx=10)
        combo_search= ttk.Combobox(srch_frame,width=10,font=myFont2,state="readonly",textvariable=srch_var)
        combo_search['values']=("Club Name","Recruitment Date")
        combo_search.grid(row=0,column=1,pady=10,padx=10)
        srch_entry=Entry(srch_frame,font=myFont3,width=20,relief=SUNKEN,bd=3,textvariable=srch_entry_var)
        srch_entry.grid(row=0,column=2)
        
        
        display2_frame= Frame(display_frame,bd=4,bg="#8ecae6",relief=RIDGE)
        display2_frame.place(x=10,y=70,height=450,width=1185)
        clb_rec_tb= ttk.Treeview(display2_frame,columns=("c_name","r_date","venue"))
        clb_rec_tb.heading("c_name",text="Club Name")
        clb_rec_tb.heading("r_date",text="Recruitment Date")
        clb_rec_tb.heading("venue",text="Venue")
        clb_rec_tb['show']="headings"
        clb_rec_tb.column("c_name",width=150)
        clb_rec_tb.column("r_date",width=150)
        clb_rec_tb.column("venue",width=150)
        clb_rec_tb.pack(fill=BOTH,expand=1)
        srch_btn=Button(srch_frame,text="Search",font=myFont5,bd=3,fg="white",bg="#219ebc",relief=RAISED,command=lambda:search_recruitment(connection,clb_rec_tb,srch_var,srch_entry_var)).grid(row=0,column=3,padx=10)
        showall= Button(srch_frame,text="Show All",font=myFont5,bd=3,fg="white",bg="#219ebc",relief=RAISED,command=lambda:fetch_club_recruitment(connection,clb_rec_tb)).grid(row=0,column=4,padx=10)



    btn_frame=Frame(club_win,bg="#219ebc")
    btn_frame.place(x=0,y=45,height=50,relwidth=1)
    info= Button(btn_frame,text="Club Information",font=myFont2,width=25,height=1,relief=RIDGE,bg="#219ebc",bd=4,command=club_info)
    info.grid(row=0,column=0,padx=20,pady=3)
    meeting=Button(btn_frame,text="Club Meeting",font=myFont2,width=25,relief=RIDGE,bg="#219ebc",bd=4,command=club_meeting)
    meeting.grid(row=0,column=1,padx=20,pady=3)
    recr=Button(btn_frame,text="Club Recruitment",font=myFont2,width=25,relief=RIDGE,bg="#219ebc",bd=4,command=club_recr)
    recr.grid(row=0,column=2,padx=20,pady=3)
    exit=Button(btn_frame,text="Exit",font=myFont2,width=25,relief=RIDGE,bg="#219ebc",bd=4,command=club_win.destroy)
    exit.grid(row=0,column=3,padx=20,pady=3)
    

header= Label(root,font=myFont,bg='#14213d',text="Clubs and Event Management System",fg="white")
header.place(x=0,y=0,relwidth=1,height=60)
main_menu= Label(root,font=myFont,bg="#ffb703",text="Main Menu",fg="white")
main_menu.place(x=0,y=60,relwidth=1,height=45)
f1=Label(root,bg="#cad2c5")
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
clubs_btn= Button(c1,text="Clubs",font=myFont1,relief=SOLID,borderwidth=1,height=1,width=12,activebackground='#e5e5e5',bg='#ffb703',command=club_window)
clubs_btn.pack(pady=15)
Events_btn= Button(c2,text="Events",font=myFont1,relief=SOLID,borderwidth=1,height=1,width=12,activebackground='#e5e5e5',bg='#ffb703',command=lambda:event_window(root,connection))
Events_btn.pack(pady=15)
admin_btn= Button(c3,text= "Admin",font=myFont1,relief=SOLID,borderwidth=1,height=1,width=12,activebackground='#e5e5e5',bg='#ffb703',command=lambda:login(root,connection))
admin_btn.pack(pady=15)
exit_btn= Button(c4,text= "Exit",font=myFont1,relief=SOLID,borderwidth=1,height=1,width=12,activebackground='#e5e5e5',bg='#ffb703',command=root.destroy)
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
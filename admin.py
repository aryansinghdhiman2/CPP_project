from tkinter import *
from tkinter import messagebox
from tkinter.font import Font
from tkinter import ttk
from dbms_func import *

def admin_window(login_win,connection):
    admin_win=Toplevel(login_win)
    login_win.withdraw()
    admin_win.geometry("1280x720")
    admin_win.resizable(False,False)
    admin_win.title("Admin")

    #root.withdraw()
    myFont= Font(family="Calibri",size=30,weight="bold")
    myFont1= Font(family="Calibri",size=18,weight="bold")
    myFont2= Font(family="Calibri",size=15,weight="bold")
    myFont3= Font(family="Calibri",size=13)
    myFont5= Font(family="Century Gothic",size=13,weight="bold")
    main_menu= Label(admin_win,font=myFont,bg="#023047",text="Admin Menu",fg="white")
    main_menu.place(x=0,y=0,relwidth=1,height=45)

    # manage_frame= Frame(club_win,bd=4,bg="yellow",relief=RIDGE)
    # manage_frame.place(x=20,y=100,width=450,height=460)
    def club_info():
        manage_frame= Frame(admin_win,bd=4,bg="#8ecae6",relief=RIDGE)
        manage_frame.place(x=10,y=100,width=480,height=570)
        display_frame= Frame(admin_win,bd=4,bg="#8ecae6",relief=RIDGE)
        display_frame.place(x=500,y=100,height=570,width=760)
    
        name_var= StringVar()
        conv_var= StringVar()
        scl_var=StringVar()
        top_frame=Frame(manage_frame,bg="#8ecae6")
        top_frame.grid(row=0,column=0)
        slct_lbl= Label(top_frame,text="Select",bg="#8ecae6",font=myFont1,fg="black")
        slct_lbl.grid(row=0,column=0,padx=20,pady=8)
        global combo_search
        combo_search= ttk.Combobox(top_frame,width=10,font=myFont3,state="readonly")
        combo_search['values']=("Club details","Co convener details")
        combo_search.grid(row=0,column=1,pady=8)
        combo_search.current(0)
        combo_search.bind("<<ComboboxSelected>>",co_convener)



        l1=Label(manage_frame,text="Club name",font=myFont1,bg="#8ecae6")
        l1.grid(row=1,column=0,pady=25,padx=20,sticky="w")

        name_entry=Entry(manage_frame,font=myFont3,width=20,relief=SUNKEN,bd=3,textvariable=name_var)
        name_entry.grid(row=1,column=1)

        l2=Label(manage_frame,text="Convener",font=myFont1,bg="#8ecae6")
        l2.grid(row=2,column=0,pady=25,padx=20,sticky="w")

        con_entry=Entry(manage_frame,font=myFont3,width=20,relief=SUNKEN,bd=3,textvariable=conv_var)
        con_entry.grid(row=2,column=1)

        l3=Label(manage_frame,text="Social Media",font=myFont1,bg="#8ecae6")
        l3.grid(row=3,column=0,pady=25,padx=20,sticky="w")

        sc_entry=Entry(manage_frame,font=myFont3,width=20,relief=SUNKEN,bd=3,textvariable=scl_var)
        sc_entry.grid(row=3,column=1)

        l4=Label(manage_frame,text="Description",font=myFont1,bg="#8ecae6")
        l4.grid(row=4,column=0,pady=35,padx=20,sticky="w")

        des_entry=Text(manage_frame,font=myFont3,width=20,height=4,relief=SUNKEN,bd=3)
        des_entry.grid(row=4,column=1)

        btn_frame2=Frame(manage_frame,bd=4,relief=GROOVE,bg="#219ebc")
        btn_frame2.place(x=5,y=480,width=460)

        data= {"Name":name_var,"Convener":conv_var,"S_media":scl_var,"Description":des_entry}


        add_btn= Button(btn_frame2,text="Add",font=myFont5,bg="#219ebc",width=7,fg="white",relief=RAISED,command=lambda:add_club(connection,data)).grid(row=0,column=0,padx=17,pady=2)
        update_btn= Button(btn_frame2,text="Update",font=myFont5,bg="#219ebc",fg="white",width=7,relief=RAISED,command=lambda:update_club(connection,data)).grid(row=0,column=1,padx=17,pady=2)
        del_btn= Button(btn_frame2,text="Delete",font=myFont5,bg="#219ebc",fg="white",width=7,relief=RAISED,command=lambda:delete_club(connection,data)).grid(row=0,column=2,padx=17,pady=2)
        #clr_btn= Button(btn_frame2,text="Clear",font=myFont3,bg="#ffffff",width=7).grid(row=0,column=3,padx=20,pady=10)
        # search_lbl= Label(display_frame,text="Search by",bg="#8ecae6",font=myFont1)
        # search_lbl.grid(row=0,column=0,sticky="w",pady=10,padx=20)
        # combo_search= ttk.Combobox(display_frame,width=10,font=myFont2,state="readonly")
        # combo_search['values']=("Club name","social media")
        # combo_search.grid(row=0,column=1,pady=10,padx=10)
        # srch_entry=Entry(display_frame,font=myFont3,width=20,relief=SUNKEN,bd=3)
        # srch_entry.grid(row=0,column=2)
        # srch_btn=Button(display_frame,text="Search",font=myFont3,bd=3,relief=GROOVE).grid(row=0,column=3,padx=10)
        display2_frame= Frame(display_frame,bd=4,bg="#8ecae6",relief=RIDGE)
        display2_frame.place(x=10,y=10,height=533,width=735)
        clb_info_tb= ttk.Treeview(display2_frame,columns=("Club_Name","Convener","Social Media","Description"))
        #showall= Button(display_frame,text="Show All",font=myFont3,bd=3,relief=GROOVE,command=lambda:fetch_club_info(connection,clb_info_tb)).grid(row=0,column=0,padx=20,pady=10)

        # display2_frame= Frame(display_frame,bd=4,bg="#8ecae6",relief=RIDGE)
        # display2_frame.place(x=10,y=65,height=450,width=735)
        #clb_info_tb= ttk.Treeview(display2_frame,columns=("Club_Name","Convener","Social Media","Description"))
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
        showall= Button(btn_frame2,text="Show All",font=myFont5,bd=3,relief=RAISED,fg="white",bg="#219ebc",command=lambda:fetch_club_info(connection,clb_info_tb)).grid(row=0,column=3,padx=17,pady=5)


    def co_convener(event):
        if combo_search.get()=="Co convener details":
            manage_frame= Frame(admin_win,bd=4,bg="#8ecae6",relief=RIDGE)
            manage_frame.place(x=0,y=100,width=480,height=540)
            con1_var=StringVar()
            con2_var=StringVar()
            name_var=StringVar()
            #combo_search.grid(row=0,column=0,pady=10,padx=10)
            l1=Label(manage_frame,text="Club Name",font=myFont1,bg="#8ecae6")
            l1.grid(row=1,column=0,pady=30,padx=20,sticky="w")

            name1_entry=Entry(manage_frame,font=myFont3,width=20,relief=SUNKEN,bd=3,textvariable=name_var)
            name1_entry.grid(row=1,column=1)

            l2=Label(manage_frame,text="Convener 1",font=myFont1,bg="#8ecae6")
            l2.grid(row=2,column=0,pady=30,padx=20,sticky="w")

            name2_entry=Entry(manage_frame,font=myFont3,width=20,relief=SUNKEN,bd=3,textvariable=con1_var)
            name2_entry.grid(row=2,column=1)

            l2=Label(manage_frame,text="Convener 2",font=myFont1,bg="#8ecae6")
            l2.grid(row=3,column=0,pady=30,padx=20,sticky="w")

            name2_entry=Entry(manage_frame,font=myFont3,width=20,relief=SUNKEN,bd=3,textvariable=con2_var)
            name2_entry.grid(row=3,column=1)

            btn_frame2=Frame(manage_frame,bd=4,relief=RIDGE,bg="#8ecae6")
            btn_frame2.place(x=5,y=450,width=460)
            data1= {"Conv_name":con1_var,"Club_name":name_var}
            data2= {"Conv_name":con2_var,"Club_name":name_var}
            add_btn= Button(btn_frame2,text="Add",font=myFont3,bg="#ffffff",width=7,command=lambda:add_co_convener2(connection,data1,data2)).grid(row=0,column=0,padx=25,pady=10)
            #update_btn= Button(btn_frame2,text="Update",font=myFont3,bg="#ffffff",width=7).grid(row=0,column=1,padx=25,pady=10)
            del_btn= Button(btn_frame2,text="Delete",font=myFont3,bg="#ffffff",width=7,command=lambda:delete_co_convener(connection,data1)).grid(row=0,column=2,padx=25,pady=10)

    def club_meeting():
        manage_frame= Frame(admin_win,bd=4,bg="#8ecae6",relief=RIDGE)
        manage_frame.place(x=0,y=100,width=480,height=540)
        display_frame= Frame(admin_win,bd=4,bg="#8ecae6",relief=RIDGE)
        display_frame.place(x=500,y=100,height=540,width=760)
        name_var= StringVar()
        date_var= StringVar()
        ven_var=StringVar()
        l1=Label(manage_frame,text="Club Name",font=myFont1,bg="#8ecae6")
        l1.grid(row=0,column=0,pady=30,padx=20,sticky="w")

        name_entry=Entry(manage_frame,font=myFont3,width=20,relief=SUNKEN,bd=3,textvariable=name_var)
        name_entry.grid(row=0,column=1)

        l2=Label(manage_frame,text="Meeting Date",font=myFont1,bg="#8ecae6")
        l2.grid(row=1,column=0,pady=30,padx=20,sticky="w")

        con_entry=Entry(manage_frame,font=myFont3,width=20,relief=SUNKEN,bd=3,textvariable=date_var)
        con_entry.grid(row=1,column=1)

        l3=Label(manage_frame,text="Venue",font=myFont1,bg="#8ecae6")
        l3.grid(row=2,column=0,pady=30,padx=20,sticky="w")

        sc_entry=Entry(manage_frame,font=myFont3,width=20,relief=SUNKEN,bd=3,textvariable=ven_var)
        sc_entry.grid(row=2,column=1)

        l4=Label(manage_frame,text="Description",font=myFont1,bg="#8ecae6")
        l4.grid(row=3,column=0,pady=40,padx=20,sticky="w")

        des_entry=Text(manage_frame,font=myFont3,width=20,height=4,relief=SUNKEN,bd=3)
        des_entry.grid(row=3,column=1)
        btn_frame2=Frame(manage_frame,bd=4,relief=RIDGE,bg="#8ecae6")
        btn_frame2.place(x=5,y=450,width=460)

        data= {"Name":name_var,"Date":date_var,"Venue":ven_var,"Description":des_entry}

        add_btn= Button(btn_frame2,text="Add",font=myFont3,bg="#ffffff",width=7,command=lambda:add_meeting(connection,data)).grid(row=0,column=0,padx=20,pady=10)
        update_btn= Button(btn_frame2,text="Update",font=myFont3,bg="#ffffff",width=7,command=lambda:update_meeting(connection,data)).grid(row=0,column=1,padx=20,pady=10)
        del_btn= Button(btn_frame2,text="Delete",font=myFont3,bg="#ffffff",width=7,command=lambda:delete_meeting(connection,data)).grid(row=0,column=2,padx=20,pady=10)
        clr_btn= Button(btn_frame2,text="Clear",font=myFont3,bg="#ffffff",width=7).grid(row=0,column=3,padx=20,pady=10)
        # search_lbl= Label(display_frame,text="Search by",bg="#8ecae6",font=myFont1)
        # search_lbl.grid(row=0,column=0,sticky="w",pady=10,padx=20)
        # combo_search= ttk.Combobox(display_frame,width=10,font=myFont2,state="readonly")
        # combo_search['values']=("Club name","Meeting date")
        # combo_search.grid(row=0,column=1,pady=10,padx=10)
        # srch_entry=Entry(display_frame,font=myFont3,width=20,relief=SUNKEN,bd=3)
        # srch_entry.grid(row=0,column=2)
        # srch_btn=Button(display_frame,text="Search",font=myFont3,bd=3,relief=GROOVE).grid(row=0,column=3,padx=10)
        #showall= Button(display_frame,text="Show All",font=myFont3,bd=3,relief=GROOVE).grid(row=0,column=4,padx=20,pady=10)

        display2_frame= Frame(display_frame,bd=4,bg="#8ecae6",relief=RIDGE)
        display2_frame.place(x=10,y=65,height=450,width=735)
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
        showall= Button(display_frame,text="Show All",font=myFont3,bd=3,relief=GROOVE,command=lambda:fetch_club_meeting(connection,clb_meet_tb)).grid(row=0,column=4,padx=20,pady=10)

    def club_recr():
        manage_frame= Frame(admin_win,bd=4,bg="#8ecae6",relief=RIDGE)
        manage_frame.place(x=0,y=100,width=480,height=540)
        display_frame= Frame(admin_win,bd=4,bg="#8ecae6",relief=RIDGE)
        display_frame.place(x=500,y=100,height=540,width=760)
        name_var= StringVar()
        date_var= StringVar()
        ven_var=StringVar()
        l1=Label(manage_frame,text="Club name",font=myFont1,bg="#8ecae6")
        l1.grid(row=0,column=0,pady=30,padx=20,sticky="w")

        name_entry=Entry(manage_frame,font=myFont3,width=20,relief=SUNKEN,bd=3,textvariable=name_var)
        name_entry.grid(row=0,column=1)

        l2=Label(manage_frame,text="Recruitment Date",font=myFont1,bg="#8ecae6")
        l2.grid(row=1,column=0,pady=30,padx=20,sticky="w")

        con_entry=Entry(manage_frame,font=myFont3,width=20,relief=SUNKEN,bd=3,textvariable=date_var)
        con_entry.grid(row=1,column=1)

        l3=Label(manage_frame,text="Venue",font=myFont1,bg="#8ecae6")
        l3.grid(row=2,column=0,pady=30,padx=20,sticky="w")

        con_entry=Entry(manage_frame,font=myFont3,width=20,relief=SUNKEN,bd=3,textvariable=ven_var)
        con_entry.grid(row=2,column=1)
        btn_frame2=Frame(manage_frame,bd=4,relief=RIDGE,bg="#8ecae6")
        btn_frame2.place(x=5,y=450,width=460)
        data= {"Name":name_var,"Date":date_var,"Venue":ven_var}

        add_btn= Button(btn_frame2,text="Add",font=myFont3,bg="#ffffff",width=7,command=lambda:add_recruitment(connection,data)).grid(row=0,column=0,padx=20,pady=10)
        update_btn= Button(btn_frame2,text="Update",font=myFont3,bg="#ffffff",width=7,command=lambda:update_recruitment(connection,data)).grid(row=0,column=1,padx=20,pady=10)
        del_btn= Button(btn_frame2,text="Delete",font=myFont3,bg="#ffffff",width=7,command=lambda:delete_recruitment(connection,data)).grid(row=0,column=2,padx=20,pady=10)
        clr_btn= Button(btn_frame2,text="Clear",font=myFont3,bg="#ffffff",width=7).grid(row=0,column=3,padx=20,pady=10)
        # search_lbl= Label(display_frame,text="Search by",bg="#8ecae6",font=myFont1)
        # search_lbl.grid(row=0,column=0,sticky="w",pady=10,padx=20)
        # combo_search= ttk.Combobox(display_frame,width=10,font=myFont2,state="readonly")
        # combo_search['values']=("Club Name","Recruitment Date")
        # combo_search.grid(row=0,column=1,pady=10,padx=10)
        # srch_entry=Entry(display_frame,font=myFont3,width=20,relief=SUNKEN,bd=3)
        # srch_entry.grid(row=0,column=2)
        # srch_btn=Button(display_frame,text="Search",font=myFont3,bd=3,relief=GROOVE).grid(row=0,column=3,padx=10)
        #showall= Button(display_frame,text="Show All",font=myFont3,bd=3,relief=GROOVE).grid(row=0,column=4,padx=20,pady=10)

        display2_frame= Frame(display_frame,bd=4,bg="#8ecae6",relief=RIDGE)
        display2_frame.place(x=10,y=65,height=450,width=735)
        clb_rec_tb= ttk.Treeview(display2_frame,columns=("c_name","r_date","venue"))
        clb_rec_tb.heading("c_name",text="Club Name")
        clb_rec_tb.heading("r_date",text="Recruitment Date")
        clb_rec_tb.heading("venue",text="Venue")
        clb_rec_tb['show']="headings"
        clb_rec_tb.column("c_name",width=150)
        clb_rec_tb.column("r_date",width=150)
        clb_rec_tb.column("venue",width=150)
        clb_rec_tb.pack(fill=BOTH,expand=1)
        showall= Button(display_frame,text="Show All",font=myFont3,bd=3,relief=GROOVE,command=lambda:fetch_club_recruitment(connection,clb_rec_tb)).grid(row=0,column=4,padx=20,pady=10)



    
    
    btn_frame=Frame(admin_win,bg="#219ebc")
    btn_frame.place(x=0,y=45,height=50,relwidth=1)
    info= Button(btn_frame,text="Club Information",font=myFont2,width=25,height=1,relief=RIDGE,bg="#219ebc",bd=4,command=club_info)
    info.grid(row=0,column=0,padx=20,pady=3)
    meeting=Button(btn_frame,text="Club Meeting",font=myFont2,width=25,relief=RIDGE,bg="#219ebc",bd=4,command=club_meeting)
    meeting.grid(row=0,column=1,padx=20,pady=3)
    recr=Button(btn_frame,text="Club Recruitment",font=myFont2,width=25,relief=RIDGE,bg="#219ebc",bd=4,command=club_recr)
    recr.grid(row=0,column=2,padx=20,pady=3)
    exit=Button(btn_frame,text="Exit",font=myFont2,width=25,relief=RIDGE,bg="#219ebc",bd=4,command=admin_win.destroy)
    exit.grid(row=0,column=3,padx=20,pady=3)


    admin_win.mainloop()


def login(root,connection):
    login_win=Toplevel(root)
    login_win.title("Login")
    login_win.geometry("925x500+300+200")
    login_win.configure(bg="#fff")
    login_win.resizable(False,False) 

    def signin():
        username=user.get()
        password=code.get()
        if username=="admin" and password=="root":
            admin_window(login_win,connection)

    img= PhotoImage(file="login.png")
    Label(login_win,image=img,bg="white").place(x=50,y=50 )
    frame=Frame(login_win,width=350,height=350,bg="white")
    frame.place(x=480,y=70)
    heading= Label(frame,text="Sign In",fg="#57a1f8",bg="white",font=("Microsoft YaHei UI Light",23,'bold'))
    heading.place(x=100,y=5)

    user= Entry(frame,width=25,fg="black",border=0,bg="white",font=("Microsoft YaHei UI Light",11))
    user.place(x=30,y=80)
    user.insert(0,"admin")
    
    Frame(frame,width=295,height=2,bg="black").place(x=25,y=107)

    code= Entry(frame,width=25,fg="black",border=0,bg="white",font=("Microsoft YaHei UI Light",11))
    code.place(x=30,y=150)
    code.insert(0,"root")
    Frame(frame,width=295,height=2,bg="black").place(x=25,y=177)


    Button(frame,width=29,pady=7,text="Sign in",bg="#57a1f8",fg="white",border=0,font=("Microsoft YaHei UI Light",12,"bold"),command=signin).place(x=28,y=204)
    exit=Button(frame,width=6,text="Exit",border=0,bg="#57a1f8",cursor="hand2",fg="white",font=("Microsoft YaHei UI Light",12,"bold"),command=login_win.destroy)
    exit.place(x=25,y=270)
    login_win.mainloop()   



  

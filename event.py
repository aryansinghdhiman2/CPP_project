from tkinter import *
from tkinter.font import Font
from tkinter import ttk
from dbms_func import *
def event_window(root,connection):
    event_win=Toplevel(root)
    event_win.geometry("1280x720")
    myfont= Font(family="Calibri",size=30,weight="bold")
    myfont1= Font(family="Calibri",size=18,weight="bold")
    myfont2= Font(family="Calibri",size=15,weight="bold")
    myfont3= Font(family="Calibri",size=13)
    myFont5= Font(family="Century Gothic",size=13,weight="bold")
    main_menu= Label(event_win,font=myfont,bg="#023047",text="Event Menu",fg="white")
    main_menu.place(x=0,y=0,relwidth=1,height=56)
    # manage_frame= Frame(event_win,bd=4,bg="yellow",relief=RIDGE)
    # manage_frame.place(x=20,y=100,width=450,height=460)
    
    manage_frame= Frame(event_win,bd=4,bg="#8ecae6",relief=RIDGE)
    manage_frame.place(x=10,y=60,width=480,height=615)
    display_frame= Frame(event_win,bd=4,bg="#8ecae6",relief=RIDGE)
    display_frame.place(x=500,y=60,height=615,width=760)

    id_var=StringVar()
    name_var=StringVar()
    date_var=StringVar()
    ven_var=StringVar()
    clb_var=StringVar()

    srch_var=StringVar()
    srch_entry_var=StringVar()
    l1=Label(manage_frame,text="Event ID",font=myfont1,bg="#8ecae6")
    l1.grid(row=0,column=0,pady=20,padx=20,sticky="w")

    name_entry=Entry(manage_frame,font=myfont3,width=20,relief=SUNKEN,bd=3,textvariable=id_var)
    name_entry.grid(row=0,column=1)

    l2=Label(manage_frame,text="Event Name",font=myfont1,bg="#8ecae6")
    l2.grid(row=1,column=0,pady=20,padx=20,sticky="w")

    con_entry=Entry(manage_frame,font=myfont3,width=20,relief=SUNKEN,bd=3,textvariable=name_var)
    con_entry.grid(row=1,column=1)

    l3=Label(manage_frame,text="Date",font=myfont1,bg="#8ecae6")
    l3.grid(row=2,column=0,pady=20,padx=20,sticky="w")

    sc_entry=Entry(manage_frame,font=myfont3,width=20,relief=SUNKEN,bd=3,textvariable=date_var)
    sc_entry.grid(row=2,column=1)

    l4=Label(manage_frame,text="Venue",font=myfont1,bg="#8ecae6")
    l4.grid(row=3,column=0,pady=20,padx=20,sticky="w")

    des_entry=Entry(manage_frame,font=myfont3,width=20,relief=SUNKEN,bd=3,textvariable=ven_var)
    des_entry.grid(row=3,column=1)

    l4=Label(manage_frame,text="Description",font=myfont1,bg="#8ecae6")
    l4.grid(row=4,column=0,pady=25,padx=20,sticky="w")

    des_entry=Text(manage_frame,font=myfont3,width=20,height=4,relief=SUNKEN,bd=3)
    des_entry.grid(row=4,column=1,pady=13)

    l4=Label(manage_frame,text="Club",font=myfont1,bg="#8ecae6")
    l4.grid(row=5,column=0,pady=20,padx=20,sticky="w")
    clb_entry=Entry(manage_frame,font=myfont3,width=20,relief=SUNKEN,bd=3,textvariable=clb_var)
    clb_entry.grid(row=5,column=1)
    
    data= {"Name":name_var,"Date":date_var,"Venue":ven_var,"Description":des_entry,"Club":clb_var}
    data2= {"ID":id_var,"Name":name_var,"Date":date_var,"Venue":ven_var,"Description":des_entry,"Club":clb_var}

    btn_frame2=Frame(manage_frame,bd=2,relief=GROOVE,bg="#219ebc")
    btn_frame2.place(x=5,y=520,width=460)

    add_btn= Button(btn_frame2,text="Add",relief=RAISED,font=myFont5,fg="white",bg="#219ebc",bd=3,width=7,command=lambda:add_event(connection,data)).grid(row=0,column=0,padx=15,pady=10)
    update_btn= Button(btn_frame2,text="Update",relief=RAISED,font=myFont5,fg="white",bg="#219ebc",bd=3,width=7,command=lambda:update_event(connection,data2)).grid(row=0,column=1,padx=17,pady=10)
    del_btn= Button(btn_frame2,text="Delete",relief=RAISED,font=myFont5,fg="white",bg="#219ebc",width=7,bd=3,command=lambda:delete_event(connection,data2)).grid(row=0,column=2,padx=17,pady=10)
    clr_btn= Button(btn_frame2,text="Clear",relief=RAISED,font=myFont5,fg="white",bg="#219ebc",width=7,bd=3).grid(row=0,column=3,padx=20,pady=10)



    search_lbl= Label(display_frame,text="Search by",bg="#8ecae6",font=myfont1)
    search_lbl.grid(row=0,column=0,sticky="w",pady=10,padx=20)
    combo_search= ttk.Combobox(display_frame,width=10,font=myfont2,state="readonly",textvariable=srch_var)
    combo_search['values']=("Event ID","Date","Club Name")
    combo_search.grid(row=0,column=1,pady=10,padx=10)
    srch_entry=Entry(display_frame,font=myfont3,width=20,relief=SUNKEN,bd=3,textvariable=srch_entry_var)
    srch_entry.grid(row=0,column=2)
    
    #showall= Button(display_frame,text="Show All",font=myfont3,bd=3,relief=GROOVE,command=lamdba:fetch_events(connection,)).grid(row=0,column=4,padx=10)

    display2_frame= Frame(display_frame,bd=4,bg="#8ecae6",relief=RIDGE)
    display2_frame.place(x=10,y=65,height=525,width=735)
    event_tb= ttk.Treeview(display2_frame,columns=("e_id","e_name","e_date","venue","desc","club"))
    event_tb.heading("e_id",text="Event ID")
    event_tb.heading("e_name",text="Event Name")
    event_tb.heading("e_date",text="Date")
    event_tb.heading("venue",text="Venue")
    event_tb.heading("desc",text="Description")
    event_tb.heading("club",text="Club")
    event_tb['show']="headings"
    event_tb.column("e_id",width=75)
    event_tb.column("e_name",width=125)
    event_tb.column("e_date",width=85)
    event_tb.column("venue",width=125)
    event_tb.column("desc",width=190)
    event_tb.column("club",width=100)
    event_tb.pack(fill=BOTH,expand=1)
    srch_btn=Button(display_frame,text="Search",font=myfont3,bd=3,relief=GROOVE,command=lambda:search_event(connection,event_tb,srch_var,srch_entry_var)).grid(row=0,column=3,padx=10)
    showall= Button(display_frame,text="Show All",font=myfont3,bd=3,relief=GROOVE,command=lambda:fetch_events(connection,event_tb)).grid(row=0,column=4,padx=10)

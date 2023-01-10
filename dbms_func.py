import oracledb
from env import user,password,dsn
def create_connection(user,password,dsn):
    global connection
    connection = oracledb.connect(
        user=user,
        password=password,
        dsn=dsn)
    return connection

# create_connection(user,password,dsn)

def fetch_club_info(connection,table):
    for item in table.get_children():
        table.delete(item)
    cursor = connection.cursor()
    for row in cursor.execute("SELECT * FROM CLUB"):
        table.insert('','end',values=row)
def fetch_club_meeting(connection,table):
    for item in table.get_children():
        table.delete(item)
    cursor = connection.cursor()
    for row in cursor.execute("SELECT * FROM MEETING"):
        table.insert('','end',values=row)
def fetch_club_recruitment(connection,table):
    for item in table.get_children():
        table.delete(item)
    cursor = connection.cursor()
    for row in cursor.execute("SELECT * FROM RECRUITMENT"):
        table.insert('','end',values=row) 
def fetch_events(connection,table):
    for item in table.get_children():
        table.delete(item)
    cursor = connection.cursor()
    for row in cursor.execute("SELECT * FROM MEETING"):
        table.insert('','end',values=row)

def search_club(connection,table,SEARCH_STRING,TO_SEARCH):
    for item in table.get_children():
        table.delete(item)
    cursor = connection.cursor()
    if(SEARCH_STRING == 'Club name'):
        string = 'CLUB_NAME'
    else:
        string = 'S_MEDIA'
    for row in cursor.execute(f'SELECT * FROM CLUB WHERE {string} = {TO_SEARCH}'):
        table.insert('','end',values=row)
def search_meeting(connection,table,SEARCH_STRING,TO_SEARCH):
    for item in table.get_children():
        table.delete(item)
    cursor = connection.cursor()
    if(SEARCH_STRING == 'Club name'):
        string = 'C_NAME'
    else:
        string = 'M_DATE'
    for row in cursor.execute(f'SELECT * FROM MEETING WHERE {string} = {TO_SEARCH}'):
        table.insert('','end',values=row)
def search_recruitment(connection,table,SEARCH_STRING,TO_SEARCH):
    for item in table.get_children():
        table.delete(item)
    cursor = connection.cursor()
    if(SEARCH_STRING == 'Club name'):
        string = 'C_NAME'
    else:
        string = 'R_DATE'
    for row in cursor.execute(f'SELECT * FROM RECRUITMENT WHERE {string} = {TO_SEARCH}'):
        table.insert('','end',values=row)
def search_event(connection,table,SEARCH_STRING,TO_SEARCH):
    for item in table.get_children():
        table.delete(item)
    cursor = connection.cursor()
    if(SEARCH_STRING == 'Club name'):
        string = 'C_NAME'
    elif(SEARCH_STRING == 'Date'):
        string = 'S_MEDIA'
    else: 
        string = 'E_ID'
    for row in cursor.execute(f'SELECT * FROM CLUB WHERE {string} = {TO_SEARCH}'):
        table.insert('','end',values=row)    

def add_club(connection,data:dict):
    with connection.cursor() as cursor:
        cursor.execute(f"BEGIN CLUB_PACK.INSERT_CLUB('{data['Name'].get()}','{data['Convener'].get()}','{data['S_media'].get()}','{data['Description'].get('1.0','end-1c')}'); END;")
    connection.commit()
def add_recruitment(connection,data:dict):
    with connection.cursor() as cursor:
        cursor.execute(f"BEGIN CLUB_PACK.INSERT_RECRUITMENT('{data['Name'].get()}','{data['Date'].get()}','{data['Venue'].get()}'); END;")
    connection.commit()
def add_meeting(connection,data:dict):
    with connection.cursor() as cursor:
        cursor.execute(f"BEGIN CLUB_PACK.INSERT_MEETING('{data['Name'].get()}','{data['Date'].get()}','{data['Venue'].get()}','{data['Description'].get('1.0','end-1c')}'); END;")
    connection.commit()
def add_event(connection,data:dict):
    with connection.cursor() as cursor:
        cursor.execute(f"BEGIN CLUB_PACK.INSERT_EVENT('{data['Name'].get()}','{data['Date'].get()}','{data['Venue'].get()}','{data['Description'].get('1.0','end-1c')}','{data['Club'].get()}'); END;")
    connection.commit()


def update_club(connection,data:dict):
    with connection.cursor() as cursor:
        cursor.execute(f"BEGIN CLUB_PACK.UPDATE_CLUB('{data['Name'].get()}','{data['Convener'].get()}','{data['S_media'].get()}','{data['Description'].get('1.0','end-1c')}'); END;")
    connection.commit()
def update_recruitment(connection,data:dict):
    with connection.cursor() as cursor:
        cursor.execute(f"BEGIN CLUB_PACK.UPDATE_RECRUITMENT('{data['Name'].get()}','{data['Date'].get()}','{data['Venue'].get()}'); END;")
    connection.commit()
def update_meeting(connection,data:dict):
    with connection.cursor() as cursor:
        cursor.execute(f"BEGIN CLUB_PACK.UPDATE_MEETING('{data['Name'].get()}','{data['Date'].get()}','{data['Venue'].get()}','{data['Description'].get('1.0','end-1c')}'); END;")
    connection.commit()
def update_event(connection,data:dict):
    with connection.cursor() as cursor:
        cursor.execute(f"BEGIN CLUB_PACK.UPDATE_EVENT({data['ID'].get()},'{data['Name'].get()}','{data['Date'].get()}','{data['Venue'].get()}','{data['Description'].get('1.0','end-1c')}','{data['Club'].get()}'); END;")
    connection.commit()

def delete_club(connection,data:dict):
    with connection.cursor() as cursor:
        cursor.execute(f"BEGIN CLUB_PACK.DELETE_CLUB('{data['Name'].get()}'); END;")
    connection.commit()
def delete_recruitment(connection,data:dict):
    with connection.cursor() as cursor:
        cursor.execute(f"BEGIN CLUB_PACK.DELETE_RECRUITMENT({data['Name'].get()},{data['Date'].get()}); END;")
    connection.commit()
def delete_meeting(connection,data:dict):
    with connection.cursor() as cursor:
        cursor.execute(f"BEGIN CLUB_PACK.DELETE_MEETING('{data['Name'].get()}','{data['Date'].get()}'); END;")
    connection.commit()
def delete_event(connection,data:dict):
    with connection.cursor() as cursor:
        cursor.execute(f"BEGIN CLUB_PACK.DELETE_EVENT('{data['ID'].get()}','{data['Date'].get()}'); END;")
    connection.commit()
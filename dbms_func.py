import oracledb
from env import user,password,dsn
def create_connection(user,password,dsn):
    global connection
    connection = oracledb.connect(
        user=user,
        password=password,
        dsn=dsn)
    return connection

create_connection(user,password,dsn)

def fetch_club_info(connection,table):
    table.delete(table.get_children())
    cursor = connection.cursor()
    for row in cursor.execute("SELECT * FROM CLUB;"):
        table.insert('','end',values=row)
def fetch_club_meeting(connection,table):
    table.delete(table.get_children())
    cursor = connection.cursor()
    for row in cursor.execute("SELECT * FROM MEETING;"):
        table.insert('','end',values=row)
def fetch_club_recruitment(connection,table):
    table.delete(table.get_children())
    cursor = connection.cursor()
    for row in cursor.execute("SELECT * FROM RECRUITMENT;"):
        table.insert('','end',values=row) 
def fetch_events(connection,table):
    table.delete(table.get_children())
    cursor = connection.cursor()
    for row in cursor.execute("SELECT * FROM MEETING;"):
        table.insert('','end',values=row)

def search_club(connection,table,SEARCH_STRING,TO_SEARCH):
    table.delete(table.get_children())
    cursor = connection.cursor()
    if(SEARCH_STRING == 'Club name'):
        string = 'CLUB_NAME'
    else:
        string = 'S_MEDIA'
    for row in cursor.execute(f'SELECT * FROM CLUB WHERE {string} = {TO_SEARCH}'):
        table.insert('','end',values=row)
def search_meeting(connection,table,SEARCH_STRING,TO_SEARCH):
    table.delete(table.get_children())
    cursor = connection.cursor()
    if(SEARCH_STRING == 'Club name'):
        string = 'C_NAME'
    else:
        string = 'M_DATE'
    for row in cursor.execute(f'SELECT * FROM MEETING WHERE {string} = {TO_SEARCH}'):
        table.insert('','end',values=row)
def search_recruitment(connection,table,SEARCH_STRING,TO_SEARCH):
    table.delete(table.get_children())
    cursor = connection.cursor()
    if(SEARCH_STRING == 'Club name'):
        string = 'C_NAME'
    else:
        string = 'R_DATE'
    for row in cursor.execute(f'SELECT * FROM RECRUITMENT WHERE {string} = {TO_SEARCH}'):
        table.insert('','end',values=row)
def search_event(connection,table,SEARCH_STRING,TO_SEARCH):
    table.delete(table.get_children())
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
        cursor.execute(f"CLUB_PACK.INSERT_CLUB({data['Name']},{data['Convener']},{data['S_media']},{data['Description']});")
    connection.commit()
def add_recruitment(connection,data:dict):
    with connection.cursor() as cursor:
        cursor.execute(f"CLUB_PACK.INSERT_RECRUITMENT({data['Name']},{data['Date'],data['Venue']})")
    connection.commit()
def add_meeting(connection,data:dict):
    with connection.cursor() as cursor:
        cursor.execute(f"CLUB_PACK.INSERT_MEETING({data['Name']},{data['Date']},{data['Venue']},{data['Description']});")
    connection.commit()
def add_event(connection,data:dict):
    with connection.cursor() as cursor:
        cursor.execute(f"CLUB_PACK.INSERT_EVENT({data['Name']},{data['Date']},{data['Venue']},{data['Description']},{data['Club']}")
    connection.commit()


def update_club(connection,data:dict):
    with connection.cursor() as cursor:
        cursor.execute(f"CLUB_PACK.UPDATE_CLUB({data['Name']},{data['Convener']},{data['S_media']},{data['Description']});")
    connection.commit()
def update_recruitment(connection,data:dict):
    with connection.cursor() as cursor:
        cursor.execute(f"CLUB_PACK.UPDATE_RECRUITMENT({data['Name']},{data['Date'],data['Venue']})")
    connection.commit()
def update_meeting(connection,data:dict):
    with connection.cursor() as cursor:
        cursor.execute(f"CLUB_PACK.UPDATE_MEETING({data['Name']},{data['Date']},{data['Venue']},{data['Description']});")
    connection.commit()
def update_event(connection,data:dict):
    with connection.cursor() as cursor:
        cursor.execute(f"CLUB_PACK.UPDATE_EVENT({data['ID']},{data['Name']},{data['Date']},{data['Venue']},{data['Description']},{data['Club']}")
    connection.commit()

def delete_club(connection,data:dict):
    with connection.cursor() as cursor:
        cursor.execute(f"CLUB_PACK.DELETE_CLUB({data['Name']})")
    connection.commit()
def delete_recruitment(connection,data:dict):
    with connection.cursor() as cursor:
        cursor.execute(f"CLUB_PACK.DELETE_RECRUITMENT({data['Name']},{data['Date']})")
    connection.commit()
def delete_meeting(connection,data:dict):
    with connection.cursor() as cursor:
        cursor.execute(f"CLUB_PACK.DELETE_MEETING({data['Name']},{data['Date']}")
    connection.commit()
def delete_event(connection,data:dict):
    with connection.cursor() as cursor:
        cursor.execute(f"CLUB_PACK.DELETE_EVENT({data['ID']},{data['Date']}")
    connection.commit()
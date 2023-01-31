
from env import user,password,dsn

import oracledb
def create_connection(user,password,dsn):
    connection = oracledb.connect(
        user=user,
        password=password,
        dsn=dsn)
    return connection


# oracledb.init_oracle_client()
# oracledb.NUMBER
# args = ['Club']
# conn = create_connection(user,password,dsn)
# with conn.cursor() as curs:
#     type_var = conn.gettype("CLUB_PACK.CLUB_VIEW_ARRAY")
#     result = curs.callfunc('CLUB_PACK.GET_CLUBS',return_type=type_var,parameters=None)
#     test = result.aslist()
#     # print(test[0].CO_NAME)
# conn.commit()
# conn.close()

def fetch_full_club_info(connection:oracledb.Connection,table):
    for item in table.get_children():
        table.delete(item)
    with connection.cursor() as curs:
        type_var = connection.gettype("CLUB_PACK.CLUB_VIEW_ARRAY")
        result = curs.callfunc('CLUB_PACK.GET_CLUBS',return_type=type_var,parameters=None)
    for row in result.aslist():
        row_val = (row.CLUB_NAME,
                   row.CONVENER,
                   row.CO_NAME,
                   row.S_MEDIA,
                   row.CLUB_DESCRIPTION
                )
        table.insert('','end',values=row_val)
    connection.commit()


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
    for row in cursor.execute("SELECT * FROM MEETING ORDER BY M_DATE DESC"):
        table.insert('','end',values=row)
def fetch_club_recruitment(connection,table):
    for item in table.get_children():
        table.delete(item)
    cursor = connection.cursor()
    for row in cursor.execute("SELECT * FROM RECRUITMENT ORDER BY R_DATE DESC"):
        table.insert('','end',values=row) 
def fetch_events(connection,table):
    for item in table.get_children():
        table.delete(item)
    cursor = connection.cursor()
    for row in cursor.execute("SELECT * FROM EVENT ORDER BY E_DATE DESC"):
        table.insert('','end',values=row)

def search_club(connection,table,SEARCH_STRING,TO_SEARCH):
    for item in table.get_children():
        table.delete(item)
    with connection.cursor() as curs:
        type_var = connection.gettype("CLUB_PACK.CLUB_VIEW_ARRAY")
        result = curs.callfunc('CLUB_PACK.GET_CLUBS',return_type=type_var,parameters=None)
    for row in result.aslist():
        row_val = (row.CLUB_NAME,
                   row.CONVENER,
                   row.CO_NAME,
                   row.S_MEDIA,
                   row.CLUB_DESCRIPTION
                  )
        if(SEARCH_STRING.get() == 'Club name'):
            if(row_val[0]==TO_SEARCH.get()):
                table.insert('','end',values=row_val)
        else:
            if(row_val[3]==TO_SEARCH.get()):
                table.insert('','end',values=row_val)
def search_meeting(connection,table,SEARCH_STRING,TO_SEARCH):
    for item in table.get_children():
        table.delete(item)
    cursor = connection.cursor()
    if(SEARCH_STRING.get() == 'Club name'):
        string = 'C_NAME'
    else:
        string = 'M_DATE'
    for row in cursor.execute(f"SELECT * FROM MEETING WHERE {string} = '{TO_SEARCH.get()}'"):
        table.insert('','end',values=row)
def search_recruitment(connection,table,SEARCH_STRING,TO_SEARCH):
    for item in table.get_children():
        table.delete(item)
    cursor = connection.cursor()
    if(SEARCH_STRING.get() == 'Club Name'):
        string = 'C_NAME'
    else:
        string = 'R_DATE'
    for row in cursor.execute(f"SELECT * FROM RECRUITMENT WHERE {string} = '{TO_SEARCH.get()}'"):
        table.insert('','end',values=row)
def search_event(connection,table,SEARCH_STRING,TO_SEARCH):
    for item in table.get_children():
        table.delete(item)
    cursor = connection.cursor()
    if(SEARCH_STRING.get() == 'Club name'):
        string = 'C_NAME'
    elif(SEARCH_STRING.get() == 'Date'):
        string = 'S_MEDIA'
    else: 
        string = 'E_ID'
    for row in cursor.execute(f"SELECT * FROM EVENT WHERE {string} = '{TO_SEARCH.get()}'"):
        table.insert('','end',values=row)    
    connection.commit()

def add_club(connection,data:dict):
    with connection.cursor() as cursor:
        cursor.execute(f"BEGIN CLUB_PACK.INSERT_CLUB('{data['Name'].get()}','{data['Convener'].get()}','{data['S_media'].get()}','{data['Description'].get('1.0','end-1c')}'); END;")
    connection.commit()
def add_co_convener(connection:oracledb.Connection,data:dict):
    with connection.cursor() as cursor:
        cursor.callproc('CLUB_PACK.INSERT_CO_CONVENER',parameters=[data['Conv_name'].get(),data['Club_name'].get()])
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
def add_co_convener2(connection,data1,data2):
    add_co_convener(connection,data1)
    add_co_convener(connection,data2)

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
def update_co_convener(connection:oracledb.Connection,data:dict):
    with connection.cursor() as cursor:
        cursor.callproc('CLUB_PACK.UPDATE_CO_CONVENER',parameters=[data['Conv_name'].get(),data['Club_name'].get()])
    connection.commit()
def delete_club(connection:oracledb.Connection,data:dict):
    with connection.cursor() as cursor:
        # cursor.execute(f"DELETE FROM CO_CONVENER WHERE C_NAME = '{data['Name'].get()}'")
        cursor.execute(f"BEGIN CLUB_PACK.DELETE_CLUB('{data['Name'].get()}'); END;")
    connection.commit()
def delete_recruitment(connection,data:dict):
    with connection.cursor() as cursor:
        cursor.execute(f"BEGIN CLUB_PACK.DELETE_RECRUITMENT('{data['Name'].get()}','{data['Date'].get()}'); END;")
    connection.commit()
def delete_meeting(connection,data:dict):
    with connection.cursor() as cursor:
        cursor.execute(f"BEGIN CLUB_PACK.DELETE_MEETING('{data['Name'].get()}','{data['Date'].get()}'); END;")
    connection.commit()
def delete_event(connection,data:dict):
    with connection.cursor() as cursor:
        cursor.execute(f"BEGIN CLUB_PACK.DELETE_EVENT('{data['ID'].get()}','{data['Date'].get()}'); END;")
    connection.commit()
def delete_co_convener(connection:oracledb.Connection,data:dict):
    with connection.cursor() as cursor:
        cursor.callproc("CLUB_PACK.DELETE_CO_CONVENER",parameters=[data['Conv_name'].get(),data['Club_name'].get()])
    connection.commit()
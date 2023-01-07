import oracledb
from env import user,password,dsn
def create_cursor(user,password,dsn):
    connection = oracledb.connect(
        user=user,
        password=password,
        dsn=dsn)

    return connection

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
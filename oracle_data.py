import oracledb

def create_cursor():
    connection = oracledb.connect(
        user="ARYAN",
        password="2003",
        dsn="localhost:1521/XEPDB1")

    cursor = connection.cursor()
    return cursor

# for row in cursor.execute(""" select * from EMPLOYEE_20 """):
#     print(f"{row[0]},{row[1]},{row[2]}")


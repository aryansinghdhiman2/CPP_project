import pymysql.cursors

# Connect to the database
connection = pymysql.connect(host='localhost',
                             user='root',
                             password='2003',
                             database = 'cems',
                             cursorclass=pymysql.cursors.DictCursor)

cur = connection.cursor()

# cur.execute(""" CREATE TABLE CLUB (CLUB_NAME VARCHAR(20) NOT NULL,
#                     CONVENER VARCHAR(20) NOT NULL,
#                     S_MEDIA VARCHAR(20),
#                     CLUB_DESCRIPTION VARCHAR(50) NOT NULL,
#                     CONSTRAINT CLUB_NAME_PK PRIMARY KEY(CLUB_NAME)
#                     );""")
# cur.execute(""" CREATE TABLE CO_CONVENER(CO_NAME VARCHAR(20),
#                             C_NAME VARCHAR(20),
#                             CONSTRAINT CO_CONVENER_NAME_FK FOREIGN KEY(C_NAME) REFERENCES CLUB(CLUB_NAME),
#                             CONSTRAINT CO_CONV_CO_NAME_PK PRIMARY KEY(CO_NAME,C_NAME)
#                             );""")
# cur.execute(""" CREATE TABLE RECRUITMENT(C_NAME VARCHAR(20),
#                         R_DATE TIMESTAMP,
#                         VENUE VARCHAR(30) NOT NULL,
#                         CONSTRAINT RECRUITMENT_PK PRIMARY KEY(C_NAME,R_DATE),
#                         CONSTRAINT RECRUITMENT_CNAME_FK FOREIGN KEY(C_NAME) REFERENCES CLUB(CLUB_NAME)
#                         ); """)
# cur.execute(""" CREATE TABLE MEETING(C_NAME VARCHAR(20),
#                     M_DATE TIMESTAMP,
#                     VENUE VARCHAR(30) NOT NULL,
#                     DESCRIPTION VARCHAR(50) NOT NULL,
#                     CONSTRAINT MEETING_PK PRIMARY KEY(C_NAME,M_DATE),
#                     CONSTRAINT MEETING_CNAME_FK FOREIGN KEY(C_NAME) REFERENCES CLUB(CLUB_NAME)
#                     );""")
# cur.execute(""" CREATE TABLE EVENT(E_ID INTEGER AUTO_INCREMENT,
#                     E_NAME VARCHAR(20) NOT NULL,
#                     E_DATE TIMESTAMP,
#                     VENUE VARCHAR(30) NOT NULL,
#                     DESCRIPTION VARCHAR(50) NOT NULL,
#                     C_NAME VARCHAR(20),
#                     CONSTRAINT EVENT_PK PRIMARY KEY(E_ID,E_DATE),
#                     CONSTRAINT EVENT_C_NAME_FK FOREIGN KEY(C_NAME) REFERENCES CLUB(CLUB_NAME)
#                     );""")
cur.execute(""" CREATE INDEX RECRUITMENT_IDX ON RECRUITMENT(R_DATE);""")
cur.execute("CREATE INDEX MEETING_IDX ON MEETING(M_DATE);")
cur.execute("CREATE INDEX EVENT_IDX ON EVENT(E_DATE);")
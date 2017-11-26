import pyodbc

# Authentication
server = 'SOMEONE\SQLEXPRESS'
database = 'autopark'
cnxn = pyodbc.connect('DRIVER={ODBC Driver 13 for SQL Server};SERVER='+server+
                      ';DATABASE='+database+';trusted_connection=yes')
cursor = cnxn.cursor()


def execute_and_show(query):
    cursor.execute(query)
    row = cursor.fetchone()
    print([column[0] for column in cursor.description])  # description
    while row:
        print(row)
        row = cursor.fetchone()


def process_input(*args):
    res_arg = []
    for arg in args:
        res_arg.append('N\'' + str(arg) + '\'')

    return len(res_arg) > 1 and res_arg or res_arg[0]


def drivers_routes():
    query =\
'''SELECT D.fullName [Full Name], D.dateBirth [Date of Birth], D.placeOfLive [Place of Live], D.class [Class], D.experience [Experience], D.salary [Salary], D.ready [Ready], WR.startTime [Time of route start], WR.finishTime [Time of route finish] FROM Driver D
JOIN DriverWayRoute DWR ON D.id = DWR.DriverId
JOIN WayRoute WR ON DWR.WayRouteNumber = WR.number'''

    execute_and_show(query)


def get_buses_on_route(number):
    number = process_input(number)
    query =\
f'''SELECT B.plateNumber [Plate Number], B.capacity [Capacity], B.vehicleType [Type], B.ready [Ready] FROM Bus B
JOIN DriverBus DB ON DB.BusPlateNumber = B.plateNumber
JOIN Driver D ON DB.DriverId = D.id
JOIN DriverWayRoute DWR ON DWR.DriverId = D.id
JOIN WayRoute WR ON DWR.WayRouteNumber = WR.number
WHERE WR.number = {number}'''

    execute_and_show(query)


def get_route_by_points(start_point: str, finish_point: str):
    start_point, finish_point = process_input(start_point, finish_point)
    query =\
f'''SELECT WR.number [Number], WR.startPoint [Start Point], WR.finishPoint [Finish Point], WR.startTime [Time of route start], WR.finishTime [Time of route finish], WR.interval [Interval], WR.extent [Extent] FROM WayRoute WR
WHERE WR.startPoint = {start_point} OR WR.finishPoint = {finish_point}'''

    execute_and_show(query)


def routes_time():
    query =\
'''SELECT WR.number [Number], WR.startTime [Time of route start], WR.finishTime [Time of route finish] FROM WayRoute WR'''

    execute_and_show(query)


def route_extent(number):
    number = process_input(number)
    query =\
f'''SELECT WR.number [Number], WR.extent [Extent] FROM WayRoute WR
WHERE WR.number = {number}'''

    execute_and_show(query)


def total_extent():
    query = 'SELECT SUM(WR.extent) [Total Extent] FROM WayRoute WR'

    execute_and_show(query)


def get_buses_no_work():
    query =\
'''SELECT B.plateNumber [Plate Number], B.capacity [Capacity], B.vehicleType [Type], B.ready [Reason] FROM Bus B
LEFT JOIN DriverBus DB ON DB.BusPlateNumber = B.plateNumber
WHERE B.ready <> N'yes' OR DB.BusPlateNumber IS NULL'''

    execute_and_show(query)


def drivers_each_class_qty():
    query =\
'''SELECT D.class [Class], COUNT(D.fullName) [Drivers] FROM Driver D
GROUP BY D.class'''

    execute_and_show(query)


def get_max_exp_driver():
    query =\
'''SELECT D.fullName [Full Name], D.dateBirth [Date of Birth], D.placeOfLive [Place of Live], D.class [Class], D.experience [Experience], D.salary [Salary], D.ready [Ready] FROM Driver D
WHERE D.experience = (
	SELECT MAX(D.experience) FROM Driver D
)'''

    execute_and_show(query)


def route_info(number):
    number = process_input(number)
    query =\
f'''SELECT WR.number [Number], WR.extent [Extent], WR.interval [Interval], WR.startPoint [Start Point], WR.finishPoint [Finish Point],
( 
	SELECT D.fullName + ', ' FROM Driver D
	JOIN DriverWayRoute DWR ON DWR.WayRouteNumber = WR.number
	WHERE DWR.DriverId = D.id
	ORDER BY D.fullName
	FOR XML PATH('') 
) AS Serve
FROM WayRoute WR
WHERE number = {number}'''

    execute_and_show(query)


def bus_types_and_routes():
    query =\
'''SELECT DISTINCT B.vehicleType [Bus Type],
( 
	SELECT DISTINCT WR.number + ', ' FROM Bus B2
	JOIN DriverBus DB ON DB.BusPlateNumber = B2.plateNumber
	JOIN Driver D ON D.id = DB.DriverId
	JOIN DriverWayRoute DWR ON DWR.DriverId = D.id
	JOIN WayRoute WR ON WR.number = DWR.WayRouteNumber
	WHERE B.vehicleType = B2.vehicleType
	FOR XML PATH('')
) [Routes]
FROM Bus B'''

    execute_and_show(query)


def routes_info():
    query =\
'''SELECT DISTINCT WR.number [Route Number], WR.startPoint [Start Point], WR.finishPoint [Finish Point], WR.startTime [Time of route start], WR.finishTime [Time of route finish], WR.interval [Interval], WR.extent [Extent],
( 
	SELECT DISTINCT B.plateNumber + ', ' FROM WayRoute WR2
	JOIN DriverWayRoute DWR ON DWR.WayRouteNumber = WR2.number
	JOIN Driver D ON D.id = DWR.DriverId
	JOIN DriverBus DB ON DB.DriverId = D.id
	JOIN Bus B ON B.plateNumber = DB.BusPlateNumber
	WHERE WR.number = WR2.number
	FOR XML PATH('')
) [Buses],
( 
	SELECT D.fullName + ', ' FROM WayRoute WR3
	JOIN DriverWayRoute DWR ON DWR.WayRouteNumber = WR3.number
	JOIN Driver D ON D.id = DWR.DriverId
	WHERE WR.number = WR3.number
	FOR XML PATH('')
) [Drivers]
FROM WayRoute WR'''

    execute_and_show(query)


def routes_extent_sum():
    query = 'SELECT SUM(WR.extent) [Extend Sum] FROM WayRoute WR'

    execute_and_show(query)


def get_qty_of_buses_by_types():
    query =\
'''SELECT B.vehicleType [Bus Type], COUNT(B.plateNumber) [Buses Quantity] FROM Bus B
GROUP BY B.vehicleType'''

    execute_and_show(query)


def drivers_qty_avg_age_and_exp():
    query =\
'''SELECT COUNT(D.id) [Drivers Quantity], 
	   AVG(DATEDIFF(hour,D.dateBirth,GETDATE())/8766) [Drivers Avarage Age],
	   AVG(D.experience) [Drivers Avarage Experience]
	   FROM Driver D'''

    execute_and_show(query)


if __name__ == '__main__':
    drivers_routes()
    get_buses_on_route(62)
    get_route_by_points('Odessa, Ukraine', 'Odessa, Ukraine')
    routes_time()
    route_extent(62)
    total_extent()
    get_buses_no_work()
    drivers_each_class_qty()
    get_max_exp_driver()
    route_info(20)
    bus_types_and_routes()
    routes_info()
    routes_extent_sum()
    get_qty_of_buses_by_types()
    drivers_qty_avg_age_and_exp()


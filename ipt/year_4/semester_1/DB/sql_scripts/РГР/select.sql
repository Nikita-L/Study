USE autopark
GO

-- Список водителей, работающих на определенном маршруте с указанием графика их работы?
SELECT D.fullName [Full Name], D.dateBirth [Date of Birth], D.placeOfLive [Place of Live], D.class [Class], D.experience [Experience], D.salary [Salary], D.ready [Ready], WR.startTime [Time of route start], WR.finishTime [Time of route finish] FROM Driver D
JOIN DriverWayRoute DWR ON D.id = DWR.DriverId
JOIN WayRoute WR ON DWR.WayRouteNumber = WR.number

-- Какие автобусы обслуживают данный маршрут?
SELECT B.plateNumber [Plate Number], B.capacity [Capacity], B.vehicleType [Type], B.ready [Ready] FROM Bus B
JOIN DriverBus DB ON DB.BusPlateNumber = B.plateNumber
JOIN Driver D ON DB.DriverId = D.id
JOIN DriverWayRoute DWR ON DWR.DriverId = D.id
JOIN WayRoute WR ON DWR.WayRouteNumber = WR.number
WHERE WR.number = N'62'

-- Какие маршруты начинаются или заканчиваются в пункте с заданным названием?
SELECT WR.number [Number], WR.startPoint [Start Point], WR.finishPoint [Finish Point], WR.startTime [Time of route start], WR.finishTime [Time of route finish], WR.interval [Interval], WR.extent [Extent] FROM WayRoute WR
WHERE WR.startPoint = N'Odessa, Ukraine' OR WR.finishPoint = N'Odessa, Ukraine'

-- Когда начинается и заканчивается движение автобусов на каждом маршруте?
SELECT WR.number [Number], WR.startTime [Time of route start], WR.finishTime [Time of route finish] FROM WayRoute WR

-- Какова протяженность определенного маршрута?
SELECT WR.number [Number], WR.extent [Extent] FROM WayRoute WR
WHERE WR.number = N'62'

-- Какова общая протяженность маршрутов, обслуживаемых автопарком?
SELECT SUM(WR.extent) [Total Extent] FROM WayRoute WR

-- Какие автобусы не вышли на линию, и по какой причине (неисправность, отсутствие водителя)?
SELECT B.plateNumber [Plate Number], B.capacity [Capacity], B.vehicleType [Type], B.ready [Reason] FROM Bus B
LEFT JOIN DriverBus DB ON DB.BusPlateNumber = B.plateNumber
WHERE B.ready <> N'yes' OR DB.BusPlateNumber IS NULL
--WHERE B.ready <> N'yes' OR NOT EXISTS(SELECT 1 FROM DriverBus DB WHERE DB.BusPlateNumber = B.plateNumber)

-- Сколько водителей каждого класса работает в автопарке?
SELECT D.class [Class], COUNT(D.fullName) [Drivers] FROM Driver D
GROUP BY D.class

-- Водитель с самым большим стажем работы?
SELECT D.fullName [Full Name], D.dateBirth [Date of Birth], D.placeOfLive [Place of Live], D.class [Class], D.experience [Experience], D.salary [Salary], D.ready [Ready] FROM Driver D
WHERE D.experience = (
	SELECT MAX(D.experience) FROM Driver D
)

-- Справки о маршруте (протяженность, время и интервал движения, конечные пункты, кто обслуживает)
SELECT WR.number [Number], WR.extent [Extent], WR.interval [Interval], WR.startPoint [Start Point], WR.finishPoint [Finish Point],
( 
	SELECT D.fullName + ', ' FROM Driver D
	JOIN DriverWayRoute DWR ON DWR.WayRouteNumber = WR.number
	WHERE DWR.DriverId = D.id
	ORDER BY D.fullName
	FOR XML PATH('') 
) AS Serve
FROM WayRoute WR
WHERE number = N'20'

-- Отчет по автопарку, сгруппированный по типам автобусов, с указанием маршрутов, обслуживаемых автобусами каждого типа
SELECT DISTINCT B.vehicleType [Bus Type],
( 
	SELECT DISTINCT WR.number + ', ' FROM Bus B2
	JOIN DriverBus DB ON DB.BusPlateNumber = B2.plateNumber
	JOIN Driver D ON D.id = DB.DriverId
	JOIN DriverWayRoute DWR ON DWR.DriverId = D.id
	JOIN WayRoute WR ON WR.number = DWR.WayRouteNumber
	WHERE B.vehicleType = B2.vehicleType
	FOR XML PATH('')
) [Routes]
FROM Bus B

-- Для маршрутов должны быть указаны все характеристики, включая списки автобусов и водителей, обслуживающих каждый маршрут
SELECT DISTINCT WR.number [Route Number], WR.startPoint [Start Point], WR.finishPoint [Finish Point], WR.startTime [Time of route start], WR.finishTime [Time of route finish], WR.interval [Interval], WR.extent [Extent],
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
FROM WayRoute WR

-- Cуммарная протяженность обслуживаемых маршрутов
SELECT SUM(WR.extent) [Extend Sum] FROM WayRoute WR

-- Количество имеющихся в автопарке автобусов каждого типа
SELECT B.vehicleType [Bus Type], COUNT(B.plateNumber) [Buses Quantity] FROM Bus B
GROUP BY B.vehicleType

-- Kоличествo водителей, их средний возраст и стаж
SELECT COUNT(D.id) [Drivers Quantity], 
	   AVG(DATEDIFF(hour,D.dateBirth,GETDATE())/8766) [Drivers Avarage Age],
	   AVG(D.experience) [Drivers Avarage Experience]
	   FROM Driver D
USE master;
GO
CREATE DATABASE autopark
GO
USE autopark
GO


CREATE TABLE Driver (
	id int IDENTITY PRIMARY KEY,
    fullName nvarchar(50) NOT NULL,
	dateBirth smalldatetime NOT NULL,
	placeOfLive nvarchar(100) NOT NULL,
	class nvarchar(25),
	experience tinyint,
	salary decimal(6, 2),

	CONSTRAINT DriverCheck 
		CHECK (fullName LIKE ('_%[ ]_%[ ]_%')),
		CHECK (DATEDIFF(day, dateBirth, GetDate()) >= 18 * 365),
		CHECK (Len(RTrim(placeOfLive)) > 5),
		CHECK (ISNULL(experience, 0) >= 0),
		CHECK (ISNULL(salary, 0) >= 0),
);

CREATE TABLE Bus (
	plateNumber nvarchar(25) PRIMARY KEY,
	vehicleType nvarchar(25) NOT NULL,
	capacity tinyint,

	CONSTRAINT BusCheck
		CHECK (ISNULL(capacity, 0) >= 0),
);

CREATE TABLE WayRoute (
	number nvarchar(10) PRIMARY KEY,
	startPoint nvarchar(100) NOT NULL,
	finishPoint nvarchar(100) NOT NULL,
	startTime time NOT NULL,
	finishTime time NOT NULL,
	interval tinyint,
	extent tinyint,

	CONSTRAINT WayRouteCheck 
		CHECK (ISNULL(interval, 0) >= 0),
		CHECK (ISNULL(extent, 0) >= 0),
);

CREATE TABLE DriverBus (
	DriverId int,
	BusPlateNumber nvarchar(25),
	primary key (DriverId, BusPlateNumber),

	CONSTRAINT DriverBusFK 
		FOREIGN KEY (DriverId)
		REFERENCES Driver(id)
		ON UPDATE CASCADE
		ON DELETE CASCADE,
		FOREIGN KEY (BusPlateNumber)
		REFERENCES Bus(plateNumber)
		ON UPDATE CASCADE
		ON DELETE CASCADE,
);

CREATE TABLE DriverWayRoute (
	DriverId int,
	WayRouteNumber nvarchar(10),
	primary key (DriverId, WayRouteNumber),

	CONSTRAINT DriverWayRouteFK 
		FOREIGN KEY (DriverId)
		REFERENCES Driver(id)
		ON UPDATE CASCADE
		ON DELETE CASCADE,
		FOREIGN KEY (WayRouteNumber)
		REFERENCES WayRoute(number)
		ON UPDATE CASCADE
		ON DELETE CASCADE,
);

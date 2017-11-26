USE master;
GO
CREATE DATABASE autopark
GO
USE autopark
GO


CREATE TABLE Driver (
	id int IDENTITY PRIMARY KEY,
	fullName nvarchar(50) NOT NULL,
	dateBirth date NOT NULL,
	placeOfLive nvarchar(100) NOT NULL,
	class nvarchar(2),
	experience tinyint,
	salary decimal(8, 2),
	ready nvarchar(50) NOT NULL,

	CONSTRAINT DriverCheck 
		CHECK (fullName LIKE ('_%[ ]_%[ ]_%')),
		CHECK (DATEDIFF(day, dateBirth, GetDate()) >= 18 * 365),
		CHECK (Len(RTrim(placeOfLive)) > 5),
		CHECK (ISNULL(experience, 0) >= 0),
		CHECK (ISNULL(salary, 0) >= 0),
);

CREATE TABLE Bus (
	plateNumber nvarchar(25) PRIMARY KEY,
	capacity tinyint NOT NULL,
	ready nvarchar(50) NOT NULL,
	vehicleType nvarchar(1),

	CONSTRAINT BusCheck
		CHECK (ISNULL(capacity, 0) >= 0),
);
GO

IF OBJECT_ID ('BusInsert', 'P') IS NOT NULL  
    DROP PROC BusInsert;  
GO

CREATE PROCEDURE BusInsert
	@plateNumber nvarchar(25),
	@capacity tinyint,
	@ready nvarchar(50)
AS
DECLARE @vehicleType nvarchar(25)
IF @capacity < 22 (
	SELECT @vehicleType = N'B'
);
ELSE (
	SELECT @vehicleType = N'A'
);
INSERT INTO Bus VALUES (@plateNumber,
						@capacity,
						@ready,
						@vehicleType);
GO

CREATE TABLE WayRoute (
	number nvarchar(10) PRIMARY KEY,
	startPoint nvarchar(100) NOT NULL,
	finishPoint nvarchar(100) NOT NULL,
	startTime time(0) NOT NULL,
	finishTime time(0) NOT NULL,
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

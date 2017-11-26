CREATE LOGIN newUser WITH PASSWORD='12345';
USE bookkeeping
GO

CREATE USER newUser FOR LOGIN newUser;
CREATE ROLE Auditors;
GO

EXEC sp_addrolemember "Auditors", "newUser";
GO
CREATE PROC temp
	@text VARCHAR(20) OUTPUT
AS  
INSERT INTO SubdivisionTypes
VALUES(@text)
GO

EXEC temp 'some text'
GRANT EXEC ON temp TO newUser;
GO

CREATE LOGIN NewUser2 WITH PASSWORD='12345';

USE bookkeeping;
GO

CREATE USER NewUser2 FOR LOGIN NewUser2;

EXEC sp_addrolemember db_securityadmin, "NewUser2";

GRANT EXEC ON temp TO NewUser2;
GO

REVOKE EXECUTE ON temp TO NewUser2;


USE master;
GO
SELECT *
FROM sys.symmetric_keys
WHERE name = '##MS_ServiceMasterKey##';
GO

USE bookkeeping;
GO
CREATE MASTER KEY ENCRYPTION BY PASSWORD = 'Password123';
GO

USE bookkeeping;
GO
CREATE CERTIFICATE Certificate1
WITH SUBJECT = 'Protect Data';
GO

USE bookkeeping;
GO
CREATE SYMMETRIC KEY SymmetricKey1 
	WITH ALGORITHM = AES_128 
	ENCRYPTION BY CERTIFICATE Certificate1;
GO

USE bookkeeping;
GO
ALTER TABLE Equipment 
ADD nameEncrypt varbinary(MAX) NULL
GO

USE bookkeeping;
GO
-- Opens the symmetric key for use
OPEN SYMMETRIC KEY SymmetricKey1
DECRYPTION BY CERTIFICATE Certificate1;
GO
UPDATE Equipment
SET nameEncrypt = EncryptByKey (Key_GUID('SymmetricKey1'), name)
FROM dbo.Equipment;
GO
-- Closes the symmetric key
CLOSE SYMMETRIC KEY SymmetricKey1;
GO

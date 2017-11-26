USE bookkeeping
GO

ALTER TABLE Equipment
NOCHECK CONSTRAINT FK__Equipment__mater__267ABA7A, CK__Equipment__name__25869641;
GO


DELETE FROM MaterialResponsiblePeople WHERE fullName = N'Trigger test person'

DELETE FROM Equipment WHERE name = N'Trigger test equipment'
GO
DELETE FROM MaterialResponsiblePeople WHERE fullName = N'Trigger test person'
GO
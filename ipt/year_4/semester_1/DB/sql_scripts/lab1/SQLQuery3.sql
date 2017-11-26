--USE master
--GO
 
--SELECT class
--    ,major_id
--    ,grantee_principal_id
--    ,permission_name
--    ,state_desc
--FROM sys.server_permissions
--WHERE state_desc = 'DENY'
--GO
 
--USE bookkeeping -- permission in database
--GO
 
--SELECT class
--    ,major_id
--    ,grantee_principal_id
--    ,permission_name
--    ,state_desc
--FROM sys.database_permissions
--WHERE state_desc = 'DENY'
--GO

USE master
DENY VIEW any database TO "SOMEONE\Lyovkin"
USE bookkeeping
DENY VIEW DEFINITION on Equipment to "SOMEONE\Lyovkin"